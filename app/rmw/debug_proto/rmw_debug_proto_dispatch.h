#ifndef RMW_DEBUG_PROTO_DISPATCH_H
#define RMW_DEBUG_PROTO_DISPATCH_H

#include <stdint.h>
#include "rmw_debug_proto_frame.h"

void rmw_debug_proto_dispatch_init(void);
void rmw_debug_proto_dispatch_on_frame(const rmw_debug_proto_frame_t *p_st_frame);
void rmw_debug_proto_dispatch_periodic(void);
uint8_t rmw_debug_proto_dispatch_pop_tx(uint8_t *p_u1_byte);

#endif
