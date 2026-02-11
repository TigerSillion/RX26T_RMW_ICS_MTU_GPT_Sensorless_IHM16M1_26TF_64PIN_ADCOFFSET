#include "rmw_debug_proto_frame.h"

typedef enum e_rmw_debug_parse_state
{
    RMW_PARSE_WAIT_SOF0 = 0,
    RMW_PARSE_WAIT_SOF1,
    RMW_PARSE_WAIT_VER,
    RMW_PARSE_WAIT_SEQ,
    RMW_PARSE_WAIT_CMD,
    RMW_PARSE_WAIT_ERR,
    RMW_PARSE_WAIT_LEN_L,
    RMW_PARSE_WAIT_LEN_H,
    RMW_PARSE_WAIT_PAYLOAD,
    RMW_PARSE_WAIT_CRC_L,
    RMW_PARSE_WAIT_CRC_H
} rmw_debug_parse_state_t;

static rmw_debug_proto_frame_handler_t s_pfn_frame_handler;
static rmw_debug_parse_state_t s_e_state;
static rmw_debug_proto_frame_t s_st_rx_frame;
static uint16_t s_u2_payload_index;
static uint16_t s_u2_rx_crc;

void rmw_debug_proto_frame_init(rmw_debug_proto_frame_handler_t pfn_handler)
{
    s_pfn_frame_handler = pfn_handler;
    rmw_debug_proto_frame_reset();
}

void rmw_debug_proto_frame_reset(void)
{
    s_e_state = RMW_PARSE_WAIT_SOF0;
    s_u2_payload_index = 0u;
    s_u2_rx_crc = 0u;
}

uint16_t rmw_debug_proto_frame_crc16(const uint8_t *p_u1_data, uint16_t u2_size)
{
    uint16_t u2_crc = 0xFFFFu;
    uint16_t i;
    uint8_t j;

    for (i = 0u; i < u2_size; i++)
    {
        u2_crc ^= p_u1_data[i];
        for (j = 0u; j < 8u; j++)
        {
            if (0u != (u2_crc & 1u))
            {
                u2_crc = (uint16_t)((u2_crc >> 1u) ^ 0xA001u);
            }
            else
            {
                u2_crc >>= 1u;
            }
        }
    }

    return u2_crc;
}

static uint16_t rmw_debug_proto_frame_build_crc_buffer(const rmw_debug_proto_frame_t *p_st_frame, uint8_t *p_u1_buffer)
{
    uint16_t u2_len = 0u;
    uint16_t i;

    p_u1_buffer[u2_len++] = p_st_frame->u1_version;
    p_u1_buffer[u2_len++] = p_st_frame->u1_seq;
    p_u1_buffer[u2_len++] = p_st_frame->u1_cmd;
    p_u1_buffer[u2_len++] = p_st_frame->u1_err;
    p_u1_buffer[u2_len++] = (uint8_t)(p_st_frame->u2_payload_length & 0xFFu);
    p_u1_buffer[u2_len++] = (uint8_t)((p_st_frame->u2_payload_length >> 8u) & 0xFFu);

    for (i = 0u; i < p_st_frame->u2_payload_length; i++)
    {
        p_u1_buffer[u2_len++] = p_st_frame->au1_payload[i];
    }

    return u2_len;
}

uint16_t rmw_debug_proto_frame_encode(const rmw_debug_proto_frame_t *p_st_frame, uint8_t *p_u1_buffer, uint16_t u2_buffer_size)
{
    uint16_t u2_payload_size = p_st_frame->u2_payload_length;
    uint16_t u2_total_size = (uint16_t)(2u + 1u + 1u + 1u + 1u + 2u + u2_payload_size + 2u);
    uint16_t u2_crc;
    uint16_t u2_idx;

    if ((u2_payload_size > RMW_DEBUG_PROTO_MAX_PAYLOAD) || (u2_total_size > u2_buffer_size))
    {
        return 0u;
    }

    p_u1_buffer[0] = RMW_DEBUG_PROTO_SOF0;
    p_u1_buffer[1] = RMW_DEBUG_PROTO_SOF1;
    u2_idx = 2u;
    u2_idx += rmw_debug_proto_frame_build_crc_buffer(p_st_frame, &p_u1_buffer[u2_idx]);
    u2_crc = rmw_debug_proto_frame_crc16(&p_u1_buffer[2], (uint16_t)(u2_idx - 2u));
    p_u1_buffer[u2_idx++] = (uint8_t)(u2_crc & 0xFFu);
    p_u1_buffer[u2_idx++] = (uint8_t)((u2_crc >> 8u) & 0xFFu);

    return u2_idx;
}

void rmw_debug_proto_frame_feed_byte(uint8_t u1_byte)
{
    uint8_t au1_crc_buffer[6u + RMW_DEBUG_PROTO_MAX_PAYLOAD];
    uint16_t u2_crc_len;
    uint16_t u2_calc_crc;

    switch (s_e_state)
    {
        case RMW_PARSE_WAIT_SOF0:
            if (RMW_DEBUG_PROTO_SOF0 == u1_byte)
            {
                s_e_state = RMW_PARSE_WAIT_SOF1;
            }
            break;

        case RMW_PARSE_WAIT_SOF1:
            if (RMW_DEBUG_PROTO_SOF1 == u1_byte)
            {
                s_e_state = RMW_PARSE_WAIT_VER;
            }
            else
            {
                s_e_state = RMW_PARSE_WAIT_SOF0;
            }
            break;

        case RMW_PARSE_WAIT_VER:
            s_st_rx_frame.u1_version = u1_byte;
            s_e_state = RMW_PARSE_WAIT_SEQ;
            break;

        case RMW_PARSE_WAIT_SEQ:
            s_st_rx_frame.u1_seq = u1_byte;
            s_e_state = RMW_PARSE_WAIT_CMD;
            break;

        case RMW_PARSE_WAIT_CMD:
            s_st_rx_frame.u1_cmd = u1_byte;
            s_e_state = RMW_PARSE_WAIT_ERR;
            break;

        case RMW_PARSE_WAIT_ERR:
            s_st_rx_frame.u1_err = u1_byte;
            s_e_state = RMW_PARSE_WAIT_LEN_L;
            break;

        case RMW_PARSE_WAIT_LEN_L:
            s_st_rx_frame.u2_payload_length = u1_byte;
            s_e_state = RMW_PARSE_WAIT_LEN_H;
            break;

        case RMW_PARSE_WAIT_LEN_H:
            s_st_rx_frame.u2_payload_length |= (uint16_t)((uint16_t)u1_byte << 8u);
            if (s_st_rx_frame.u2_payload_length > RMW_DEBUG_PROTO_MAX_PAYLOAD)
            {
                rmw_debug_proto_frame_reset();
            }
            else if (0u == s_st_rx_frame.u2_payload_length)
            {
                s_e_state = RMW_PARSE_WAIT_CRC_L;
            }
            else
            {
                s_u2_payload_index = 0u;
                s_e_state = RMW_PARSE_WAIT_PAYLOAD;
            }
            break;

        case RMW_PARSE_WAIT_PAYLOAD:
            s_st_rx_frame.au1_payload[s_u2_payload_index++] = u1_byte;
            if (s_u2_payload_index >= s_st_rx_frame.u2_payload_length)
            {
                s_e_state = RMW_PARSE_WAIT_CRC_L;
            }
            break;

        case RMW_PARSE_WAIT_CRC_L:
            s_u2_rx_crc = u1_byte;
            s_e_state = RMW_PARSE_WAIT_CRC_H;
            break;

        case RMW_PARSE_WAIT_CRC_H:
            s_u2_rx_crc |= (uint16_t)((uint16_t)u1_byte << 8u);
            u2_crc_len = rmw_debug_proto_frame_build_crc_buffer(&s_st_rx_frame, au1_crc_buffer);
            u2_calc_crc = rmw_debug_proto_frame_crc16(au1_crc_buffer, u2_crc_len);
            if ((u2_calc_crc == s_u2_rx_crc) && (RMW_DEBUG_PROTO_VERSION_V1 == s_st_rx_frame.u1_version) && (0 != s_pfn_frame_handler))
            {
                s_pfn_frame_handler(&s_st_rx_frame);
            }
            rmw_debug_proto_frame_reset();
            break;

        default:
            rmw_debug_proto_frame_reset();
            break;
    }
}
