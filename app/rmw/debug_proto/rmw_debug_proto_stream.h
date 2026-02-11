#ifndef RMW_DEBUG_PROTO_STREAM_H
#define RMW_DEBUG_PROTO_STREAM_H

#include <stdint.h>
#include "rmw_debug_proto_frame.h"

#define RMW_DEBUG_STREAM_MAX_CHANNELS   (8u)

typedef struct st_rmw_debug_stream_cfg
{
    uint8_t  u1_enable;
    uint8_t  u1_interval;
    uint8_t  u1_channel_num;
    uint16_t au2_var_id[RMW_DEBUG_STREAM_MAX_CHANNELS];
} rmw_debug_stream_cfg_t;

void rmw_debug_proto_stream_init(void);
uint8_t rmw_debug_proto_stream_configure(const uint8_t *p_u1_payload, uint16_t u2_length);
void rmw_debug_proto_stream_build_ack(rmw_debug_proto_frame_t *p_st_rsp);
uint8_t rmw_debug_proto_stream_poll(rmw_debug_proto_frame_t *p_st_sample_frame);

#endif
