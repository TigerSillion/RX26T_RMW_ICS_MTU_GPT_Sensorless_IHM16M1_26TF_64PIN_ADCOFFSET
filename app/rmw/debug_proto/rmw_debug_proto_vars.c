#include "rmw_debug_proto_vars.h"
#include "r_app_rmw.h"

extern uint8_t g_u1_ics_decimation;

enum
{
    RMW_VAR_ID_SYSTEM_MODE = 0x0001,
    RMW_VAR_ID_ENABLE_WRITE = 0x0002,
    RMW_VAR_ID_REF_SPEED_RPM = 0x0101,
    RMW_VAR_ID_CTRL_LOOP_MODE = 0x0102,
    RMW_VAR_ID_CURRENT_OMEGA = 0x0103,
    RMW_VAR_ID_SPEED_OMEGA = 0x0104,
    RMW_VAR_ID_ICS_DECIMATION = 0x0200
};

static rmw_debug_var_desc_t s_ast_var_map[] =
{
    {RMW_VAR_ID_SYSTEM_MODE,     RMW_DEBUG_VAR_U8,  0u, &com_u1_system_mode},
    {RMW_VAR_ID_ENABLE_WRITE,    RMW_DEBUG_VAR_U8,  0u, &com_u1_enable_write},
    {RMW_VAR_ID_REF_SPEED_RPM,   RMW_DEBUG_VAR_F32, 0u, &com_f4_ref_speed_rpm},
    {RMW_VAR_ID_CTRL_LOOP_MODE,  RMW_DEBUG_VAR_U8,  0u, &com_u1_ctrl_loop_mode},
    {RMW_VAR_ID_CURRENT_OMEGA,   RMW_DEBUG_VAR_F32, 0u, &com_f4_current_omega_hz},
    {RMW_VAR_ID_SPEED_OMEGA,     RMW_DEBUG_VAR_F32, 0u, &com_f4_speed_omega_hz},
    {RMW_VAR_ID_ICS_DECIMATION,  RMW_DEBUG_VAR_U8,  0u, &g_u1_ics_decimation}
};

static uint8_t rmw_debug_proto_var_size(rmw_debug_var_type_t e_type)
{
    uint8_t u1_size = 0u;

    switch (e_type)
    {
        case RMW_DEBUG_VAR_U8:
            u1_size = 1u;
            break;
        case RMW_DEBUG_VAR_U16:
        case RMW_DEBUG_VAR_S16:
            u1_size = 2u;
            break;
        case RMW_DEBUG_VAR_F32:
            u1_size = 4u;
            break;
        default:
            break;
    }

    return u1_size;
}

static rmw_debug_var_desc_t *rmw_debug_proto_find_var(uint16_t u2_var_id)
{
    uint16_t u2_idx;
    uint16_t u2_count = (uint16_t)(sizeof(s_ast_var_map) / sizeof(s_ast_var_map[0]));

    for (u2_idx = 0u; u2_idx < u2_count; u2_idx++)
    {
        if (s_ast_var_map[u2_idx].u2_var_id == u2_var_id)
        {
            return &s_ast_var_map[u2_idx];
        }
    }

    return (rmw_debug_var_desc_t*)0;
}

uint8_t rmw_debug_proto_var_read(uint16_t u2_var_id, uint8_t *p_u1_dst, uint8_t *p_u1_size)
{
    rmw_debug_var_desc_t *p_st_desc = rmw_debug_proto_find_var(u2_var_id);
    uint8_t u1_size;
    uint8_t u1_idx;
    uint8_t *p_u1_src;

    if (0 == p_st_desc)
    {
        return 0u;
    }

    u1_size = rmw_debug_proto_var_size(p_st_desc->e_type);
    p_u1_src = (uint8_t*)p_st_desc->p_var;

    for (u1_idx = 0u; u1_idx < u1_size; u1_idx++)
    {
        p_u1_dst[u1_idx] = p_u1_src[u1_idx];
    }

    *p_u1_size = u1_size;
    return 1u;
}

uint8_t rmw_debug_proto_var_write(uint16_t u2_var_id, const uint8_t *p_u1_src, uint8_t u1_size)
{
    rmw_debug_var_desc_t *p_st_desc = rmw_debug_proto_find_var(u2_var_id);
    uint8_t u1_expect_size;
    uint8_t u1_idx;
    uint8_t *p_u1_dst;

    if ((0 == p_st_desc) || (0u != p_st_desc->u1_read_only))
    {
        return 0u;
    }

    u1_expect_size = rmw_debug_proto_var_size(p_st_desc->e_type);
    if (u1_expect_size != u1_size)
    {
        return 0u;
    }

    p_u1_dst = (uint8_t*)p_st_desc->p_var;
    for (u1_idx = 0u; u1_idx < u1_expect_size; u1_idx++)
    {
        p_u1_dst[u1_idx] = p_u1_src[u1_idx];
    }

    return 1u;
}
