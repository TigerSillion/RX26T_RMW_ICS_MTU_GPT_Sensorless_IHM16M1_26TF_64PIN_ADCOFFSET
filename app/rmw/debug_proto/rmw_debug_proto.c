#include "rmw_debug_proto.h"

#include "rmw_debug_proto_frame.h"
#include "rmw_debug_proto_dispatch.h"
#include "r_app_rmw.h"

static uint8_t rmw_debug_proto_read_rdr(uint8_t *p_u1_byte)
{
#if (APP_CFG_SCI_CH_SELECT == ICS_SCI6_PB2_PB1)
    *p_u1_byte = SCI6.RDR;
    return 1u;
#elif (APP_CFG_SCI_CH_SELECT == ICS_SCI6_P81_P80)
    *p_u1_byte = SCI6.RDR;
    return 1u;
#elif (APP_CFG_SCI_CH_SELECT == ICS_SCI1_PD3_PD5)
    *p_u1_byte = SCI1.RDR;
    return 1u;
#elif (APP_CFG_SCI_CH_SELECT == ICS_SCI5_PB5_PB6)
    *p_u1_byte = SCI5.RDR;
    return 1u;
#else
    (void)p_u1_byte;
    return 0u;
#endif
}

void r_app_rmw_debug_proto_init(void)
{
    rmw_debug_proto_dispatch_init();
    rmw_debug_proto_frame_init(rmw_debug_proto_dispatch_on_frame);
}

void r_app_rmw_debug_proto_feed_byte(uint8_t u1_byte)
{
    rmw_debug_proto_frame_feed_byte(u1_byte);
}

void r_app_rmw_debug_proto_on_rxi(void)
{
    uint8_t u1_byte;

    if (0u != rmw_debug_proto_read_rdr(&u1_byte))
    {
        r_app_rmw_debug_proto_feed_byte(u1_byte);
    }
}

void r_app_rmw_debug_proto_on_eri(void)
{
#if !defined(BSP_MCU_RX13T)
    ics_int_sci_eri();
#endif
    rmw_debug_proto_frame_reset();
}

void r_app_rmw_debug_proto_periodic(void)
{
    rmw_debug_proto_dispatch_periodic();
}
