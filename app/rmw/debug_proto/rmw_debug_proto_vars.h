#ifndef RMW_DEBUG_PROTO_VARS_H
#define RMW_DEBUG_PROTO_VARS_H

#include <stdint.h>
#include <stddef.h>

typedef enum e_rmw_debug_var_type
{
    RMW_DEBUG_VAR_U8 = 0,
    RMW_DEBUG_VAR_U16,
    RMW_DEBUG_VAR_S16,
    RMW_DEBUG_VAR_F32
} rmw_debug_var_type_t;

typedef struct st_rmw_debug_var_desc
{
    uint16_t u2_var_id;
    rmw_debug_var_type_t e_type;
    uint8_t u1_read_only;
    void * p_var;
} rmw_debug_var_desc_t;

uint8_t rmw_debug_proto_var_read(uint16_t u2_var_id, uint8_t *p_u1_dst, uint8_t *p_u1_size);
uint8_t rmw_debug_proto_var_write(uint16_t u2_var_id, const uint8_t *p_u1_src, uint8_t u1_size);

#endif
