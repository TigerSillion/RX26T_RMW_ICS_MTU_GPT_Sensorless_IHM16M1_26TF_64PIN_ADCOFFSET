#include "rmw_debug_proto_stream.h"
#include "rmw_debug_proto_vars.h"

static rmw_debug_stream_cfg_t s_st_stream_cfg;
static uint8_t s_u1_tick;

void rmw_debug_proto_stream_init(void)
{
    uint8_t u1_idx;

    s_st_stream_cfg.u1_enable = 0u;
    s_st_stream_cfg.u1_interval = 1u;
    s_st_stream_cfg.u1_channel_num = 0u;
    s_u1_tick = 0u;

    for (u1_idx = 0u; u1_idx < RMW_DEBUG_STREAM_MAX_CHANNELS; u1_idx++)
    {
        s_st_stream_cfg.au2_var_id[u1_idx] = 0u;
    }
}

uint8_t rmw_debug_proto_stream_configure(const uint8_t *p_u1_payload, uint16_t u2_length)
{
    uint8_t u1_idx;

    if (u2_length < 3u)
    {
        return 0u;
    }

    s_st_stream_cfg.u1_enable = p_u1_payload[0];
    s_st_stream_cfg.u1_interval = p_u1_payload[1];
    s_st_stream_cfg.u1_channel_num = p_u1_payload[2];

    if ((0u == s_st_stream_cfg.u1_interval) || (s_st_stream_cfg.u1_channel_num > RMW_DEBUG_STREAM_MAX_CHANNELS))
    {
        return 0u;
    }

    if (u2_length != (uint16_t)(3u + ((uint16_t)s_st_stream_cfg.u1_channel_num * 2u)))
    {
        return 0u;
    }

    for (u1_idx = 0u; u1_idx < s_st_stream_cfg.u1_channel_num; u1_idx++)
    {
        s_st_stream_cfg.au2_var_id[u1_idx] = (uint16_t)p_u1_payload[3u + (2u * u1_idx)] |
                                             (uint16_t)((uint16_t)p_u1_payload[4u + (2u * u1_idx)] << 8u);
    }

    return 1u;
}

void rmw_debug_proto_stream_build_ack(rmw_debug_proto_frame_t *p_st_rsp)
{
    uint8_t u1_idx;
    uint16_t u2_len = 0u;

    p_st_rsp->au1_payload[u2_len++] = s_st_stream_cfg.u1_enable;
    p_st_rsp->au1_payload[u2_len++] = s_st_stream_cfg.u1_interval;
    p_st_rsp->au1_payload[u2_len++] = s_st_stream_cfg.u1_channel_num;

    for (u1_idx = 0u; u1_idx < s_st_stream_cfg.u1_channel_num; u1_idx++)
    {
        p_st_rsp->au1_payload[u2_len++] = (uint8_t)(s_st_stream_cfg.au2_var_id[u1_idx] & 0xFFu);
        p_st_rsp->au1_payload[u2_len++] = (uint8_t)((s_st_stream_cfg.au2_var_id[u1_idx] >> 8u) & 0xFFu);
    }

    p_st_rsp->u2_payload_length = u2_len;
}

uint8_t rmw_debug_proto_stream_poll(rmw_debug_proto_frame_t *p_st_sample_frame)
{
    uint8_t u1_idx;
    uint8_t u1_size;
    uint16_t u2_var_id;
    uint16_t u2_len = 0u;

    if ((0u == s_st_stream_cfg.u1_enable) || (0u == s_st_stream_cfg.u1_channel_num))
    {
        return 0u;
    }

    s_u1_tick++;
    if (s_u1_tick < s_st_stream_cfg.u1_interval)
    {
        return 0u;
    }
    s_u1_tick = 0u;

    for (u1_idx = 0u; u1_idx < s_st_stream_cfg.u1_channel_num; u1_idx++)
    {
        u2_var_id = s_st_stream_cfg.au2_var_id[u1_idx];
        if ((u2_len + 3u) >= RMW_DEBUG_PROTO_MAX_PAYLOAD)
        {
            break;
        }

        p_st_sample_frame->au1_payload[u2_len++] = (uint8_t)(u2_var_id & 0xFFu);
        p_st_sample_frame->au1_payload[u2_len++] = (uint8_t)((u2_var_id >> 8u) & 0xFFu);

        if (0u == rmw_debug_proto_var_read(u2_var_id,
                                           &p_st_sample_frame->au1_payload[u2_len + 1u],
                                           &u1_size))
        {
            p_st_sample_frame->au1_payload[u2_len++] = 0u;
        }
        else
        {
            p_st_sample_frame->au1_payload[u2_len++] = u1_size;
            u2_len = (uint16_t)(u2_len + u1_size);
        }
    }

    p_st_sample_frame->u2_payload_length = u2_len;
    return 1u;
}
