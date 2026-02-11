#include "rmw_debug_proto_dispatch.h"
#include "rmw_debug_proto_vars.h"
#include "rmw_debug_proto_stream.h"
#include "r_app_rmw.h"

#define RMW_CMD_GET_PROTOCOL_INFO      (0x01u)
#define RMW_CMD_READ_VAR               (0x10u)
#define RMW_CMD_WRITE_VAR              (0x11u)
#define RMW_CMD_READ_VAR_BATCH         (0x12u)
#define RMW_CMD_WRITE_VAR_BATCH        (0x13u)
#define RMW_CMD_STREAM_CONFIG          (0x20u)
#define RMW_CMD_STREAM_SAMPLE          (0x21u)

#define RMW_TX_QUEUE_SIZE              (512u)

static uint8_t s_au1_tx_queue[RMW_TX_QUEUE_SIZE];
static uint16_t s_u2_tx_wr;
static uint16_t s_u2_tx_rd;
static uint8_t s_u1_stream_seq;

static void rmw_debug_proto_queue_frame(const rmw_debug_proto_frame_t *p_st_rsp)
{
    uint8_t au1_encoded[2u + 6u + RMW_DEBUG_PROTO_MAX_PAYLOAD + 2u];
    uint16_t u2_len;
    uint16_t u2_idx;
    uint16_t u2_next_wr;

    u2_len = rmw_debug_proto_frame_encode(p_st_rsp, au1_encoded, (uint16_t)sizeof(au1_encoded));
    for (u2_idx = 0u; u2_idx < u2_len; u2_idx++)
    {
        u2_next_wr = (uint16_t)((s_u2_tx_wr + 1u) % RMW_TX_QUEUE_SIZE);
        if (u2_next_wr == s_u2_tx_rd)
        {
            break;
        }

        s_au1_tx_queue[s_u2_tx_wr] = au1_encoded[u2_idx];
        s_u2_tx_wr = u2_next_wr;
    }
}

void rmw_debug_proto_dispatch_init(void)
{
    s_u2_tx_wr = 0u;
    s_u2_tx_rd = 0u;
    s_u1_stream_seq = 0u;
    rmw_debug_proto_stream_init();
}

uint8_t rmw_debug_proto_dispatch_pop_tx(uint8_t *p_u1_byte)
{
    if (s_u2_tx_rd == s_u2_tx_wr)
    {
        return 0u;
    }

    *p_u1_byte = s_au1_tx_queue[s_u2_tx_rd];
    s_u2_tx_rd = (uint16_t)((s_u2_tx_rd + 1u) % RMW_TX_QUEUE_SIZE);
    return 1u;
}

static void rmw_debug_proto_response_header(rmw_debug_proto_frame_t *p_st_rsp, const rmw_debug_proto_frame_t *p_st_req)
{
    p_st_rsp->u1_version = RMW_DEBUG_PROTO_VERSION_V1;
    p_st_rsp->u1_seq = p_st_req->u1_seq;
    p_st_rsp->u1_cmd = p_st_req->u1_cmd;
    p_st_rsp->u1_err = RMW_DEBUG_PROTO_ERR_OK;
    p_st_rsp->u2_payload_length = 0u;
}

void rmw_debug_proto_dispatch_on_frame(const rmw_debug_proto_frame_t *p_st_frame)
{
    rmw_debug_proto_frame_t st_rsp;
    uint16_t u2_idx;
    uint16_t u2_var_id;
    uint8_t u1_size;
    uint8_t u1_count;

    rmw_debug_proto_response_header(&st_rsp, p_st_frame);

    switch (p_st_frame->u1_cmd)
    {
        case RMW_CMD_GET_PROTOCOL_INFO:
            st_rsp.au1_payload[0] = RMW_DEBUG_PROTO_VERSION_V1;
            st_rsp.au1_payload[1] = 0x01u;
            st_rsp.au1_payload[2] = 0x00u;
            st_rsp.u2_payload_length = 3u;
            break;

        case RMW_CMD_READ_VAR:
            if (p_st_frame->u2_payload_length != 2u)
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            u2_var_id = (uint16_t)p_st_frame->au1_payload[0] | ((uint16_t)p_st_frame->au1_payload[1] << 8u);
            st_rsp.au1_payload[0] = p_st_frame->au1_payload[0];
            st_rsp.au1_payload[1] = p_st_frame->au1_payload[1];
            if (0u == rmw_debug_proto_var_read(u2_var_id, &st_rsp.au1_payload[3], &u1_size))
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_VAR;
                st_rsp.u2_payload_length = 2u;
            }
            else
            {
                st_rsp.au1_payload[2] = u1_size;
                st_rsp.u2_payload_length = (uint16_t)(3u + u1_size);
            }
            break;

        case RMW_CMD_WRITE_VAR:
            if (p_st_frame->u2_payload_length < 3u)
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            u2_var_id = (uint16_t)p_st_frame->au1_payload[0] | ((uint16_t)p_st_frame->au1_payload[1] << 8u);
            u1_size = p_st_frame->au1_payload[2];
            if ((uint16_t)(3u + u1_size) != p_st_frame->u2_payload_length)
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            if (0u == rmw_debug_proto_var_write(u2_var_id, &p_st_frame->au1_payload[3], u1_size))
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_VAR;
            }
            else
            {
                r_app_rmw_copy_com_to_buffer();
            }
            break;

        case RMW_CMD_READ_VAR_BATCH:
            if (p_st_frame->u2_payload_length < 1u)
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            u1_count = p_st_frame->au1_payload[0];
            if (p_st_frame->u2_payload_length != (uint16_t)(1u + (2u * u1_count)))
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            st_rsp.au1_payload[0] = u1_count;
            st_rsp.u2_payload_length = 1u;
            for (u2_idx = 0u; u2_idx < u1_count; u2_idx++)
            {
                u2_var_id = (uint16_t)p_st_frame->au1_payload[1u + (2u * u2_idx)] |
                            ((uint16_t)p_st_frame->au1_payload[2u + (2u * u2_idx)] << 8u);
                st_rsp.au1_payload[st_rsp.u2_payload_length++] = (uint8_t)(u2_var_id & 0xFFu);
                st_rsp.au1_payload[st_rsp.u2_payload_length++] = (uint8_t)((u2_var_id >> 8u) & 0xFFu);
                if (0u == rmw_debug_proto_var_read(u2_var_id, &st_rsp.au1_payload[st_rsp.u2_payload_length + 1u], &u1_size))
                {
                    st_rsp.au1_payload[st_rsp.u2_payload_length++] = 0u;
                }
                else
                {
                    st_rsp.au1_payload[st_rsp.u2_payload_length++] = u1_size;
                    st_rsp.u2_payload_length = (uint16_t)(st_rsp.u2_payload_length + u1_size);
                }
            }
            break;

        case RMW_CMD_WRITE_VAR_BATCH:
            if (p_st_frame->u2_payload_length < 1u)
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                break;
            }
            u1_count = p_st_frame->au1_payload[0];
            u2_idx = 1u;
            while ((u1_count > 0u) && (u2_idx < p_st_frame->u2_payload_length))
            {
                if ((u2_idx + 3u) > p_st_frame->u2_payload_length)
                {
                    st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                    break;
                }
                u2_var_id = (uint16_t)p_st_frame->au1_payload[u2_idx] |
                            ((uint16_t)p_st_frame->au1_payload[u2_idx + 1u] << 8u);
                u1_size = p_st_frame->au1_payload[u2_idx + 2u];
                u2_idx = (uint16_t)(u2_idx + 3u);
                if ((u2_idx + u1_size) > p_st_frame->u2_payload_length)
                {
                    st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
                    break;
                }
                if (0u == rmw_debug_proto_var_write(u2_var_id, &p_st_frame->au1_payload[u2_idx], u1_size))
                {
                    st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_VAR;
                    break;
                }
                u2_idx = (uint16_t)(u2_idx + u1_size);
                u1_count--;
            }
            if (RMW_DEBUG_PROTO_ERR_OK == st_rsp.u1_err)
            {
                r_app_rmw_copy_com_to_buffer();
            }
            break;

        case RMW_CMD_STREAM_CONFIG:
            if (0u == rmw_debug_proto_stream_configure(p_st_frame->au1_payload, p_st_frame->u2_payload_length))
            {
                st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_LENGTH;
            }
            rmw_debug_proto_stream_build_ack(&st_rsp);
            break;

        default:
            st_rsp.u1_err = RMW_DEBUG_PROTO_ERR_BAD_CMD;
            break;
    }

    rmw_debug_proto_queue_frame(&st_rsp);
}

void rmw_debug_proto_dispatch_periodic(void)
{
    rmw_debug_proto_frame_t st_sample;

    st_sample.u1_version = RMW_DEBUG_PROTO_VERSION_V1;
    st_sample.u1_seq = s_u1_stream_seq++;
    st_sample.u1_cmd = RMW_CMD_STREAM_SAMPLE;
    st_sample.u1_err = RMW_DEBUG_PROTO_ERR_OK;
    st_sample.u2_payload_length = 0u;

    if (0u != rmw_debug_proto_stream_poll(&st_sample))
    {
        rmw_debug_proto_queue_frame(&st_sample);
    }
}
