#include "ICS2_RX26T.h"

#include <stddef.h>

#define ICS2_IMPL_VERSION (0x00010000UL)

typedef struct
{
    void * p_dtc_table;
    uint8_t u1_port;
    uint8_t u1_level;
    uint8_t u1_speed;
    uint8_t u1_mode;
    volatile uint32_t u4_watchpoint_count;
    volatile uint32_t u4_eri_count;
    volatile uint32_t u4_rxi_count;
} st_ics2_state_t;

static st_ics2_state_t g_st_ics2_state;

void ics2_init(void * addr, uint8_t port, uint8_t level, uint8_t speed, uint8_t mode)
{
    g_st_ics2_state.p_dtc_table = addr;
    g_st_ics2_state.u1_port = port;
    g_st_ics2_state.u1_level = level;
    g_st_ics2_state.u1_speed = speed;
    g_st_ics2_state.u1_mode = mode;
    g_st_ics2_state.u4_watchpoint_count = 0UL;
    g_st_ics2_state.u4_eri_count = 0UL;
    g_st_ics2_state.u4_rxi_count = 0UL;
}

void ics2_watchpoint(void)
{
    g_st_ics2_state.u4_watchpoint_count++;
}

uint32_t ics2_version(void)
{
    return ICS2_IMPL_VERSION;
}

void ics_int_sci_eri(void)
{
    g_st_ics2_state.u4_eri_count++;
}

void ics_int_sci_rxi(void)
{
    g_st_ics2_state.u4_rxi_count++;
}
