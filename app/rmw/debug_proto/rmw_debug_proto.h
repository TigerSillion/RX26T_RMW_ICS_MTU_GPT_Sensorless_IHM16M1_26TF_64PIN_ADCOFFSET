#ifndef RMW_DEBUG_PROTO_H
#define RMW_DEBUG_PROTO_H

#include <stdint.h>

void r_app_rmw_debug_proto_init(void);
void r_app_rmw_debug_proto_on_rxi(void);
void r_app_rmw_debug_proto_on_eri(void);
void r_app_rmw_debug_proto_feed_byte(uint8_t u1_byte);
void r_app_rmw_debug_proto_periodic(void);

#endif
