/***********************************************************************************************************************
* DISCLAIMER
***********************************************************************************************************************/

#include "r_motor_speed_opl_damp_ctrl.h"

#include <math.h>

float motor_speed_opl_damp_ctrl(st_opl_damp_t * p_st_opl_damp, float f4_ed, float f4_speed_ref)
{
    float f4_ed_lpf;
    float f4_speed_fb;
    float f4_limit;

    f4_ed_lpf = motor_filter_first_order_lpff(&p_st_opl_damp->st_ed_lpf, f4_ed);
    f4_speed_fb = -(p_st_opl_damp->f4_damp_comp_gain * f4_ed_lpf);

    f4_limit = fabsf(f4_speed_ref) * p_st_opl_damp->f4_fb_speed_limit_rate;
    if (f4_speed_fb > f4_limit)
    {
        f4_speed_fb = f4_limit;
    }
    else if (f4_speed_fb < -f4_limit)
    {
        f4_speed_fb = -f4_limit;
    }

    return f4_speed_fb;
}

void motor_speed_opl_damp_init(st_opl_damp_t * p_st_opl_damp, float f4_fb_speed_limit_rate)
{
    motor_filter_first_order_lpff_init(&p_st_opl_damp->st_ed_lpf);
    p_st_opl_damp->f4_damp_comp_gain = 0.0f;
    p_st_opl_damp->f4_fb_speed_limit_rate = f4_fb_speed_limit_rate;
}

void motor_speed_opl_damp_reset(st_opl_damp_t * p_st_opl_damp)
{
    motor_filter_first_order_lpff_reset(&p_st_opl_damp->st_ed_lpf);
}

void motor_speed_opl_damp_gain_set(st_opl_damp_t * p_st_opl_damp,
                                   float f4_damp_gain,
                                   float f4_omega_t,
                                   float f4_gain_ka,
                                   float f4_gain_kb)
{
    p_st_opl_damp->f4_damp_comp_gain = f4_damp_gain;
    p_st_opl_damp->st_ed_lpf.f4_omega_t = f4_omega_t;
    p_st_opl_damp->st_ed_lpf.f4_gain_ka = f4_gain_ka;
    p_st_opl_damp->st_ed_lpf.f4_gain_kb = f4_gain_kb;
}

void motor_speed_opl_damp_r_gain_set(st_opl_damp_t * p_st_opl_damp,
                                     uint16_t u2_pp,
                                     float f4_ke,
                                     float f4_j,
                                     float f4_zeta,
                                     float f4_ed_hpf_fc,
                                     float f4_opl_current,
                                     float f4_id_down_speed,
                                     float f4_tc)
{
    float f4_damp_gain;

    (void)f4_opl_current;

    if ((f4_ke > 0.0f) && (f4_j > 0.0f))
    {
        f4_damp_gain = (2.0f * f4_zeta * f4_id_down_speed * f4_j)
                / (f4_ke * (float)u2_pp + 1.0e-6f);
    }
    else
    {
        f4_damp_gain = 0.0f;
    }

    motor_filter_first_order_lpff_gain_calc(&p_st_opl_damp->st_ed_lpf, f4_ed_hpf_fc, f4_tc);
    p_st_opl_damp->f4_damp_comp_gain = f4_damp_gain;
}

void motor_speed_opl_damp_limit_set(st_opl_damp_t * p_st_opl_damp, float f4_limit_rate)
{
    p_st_opl_damp->f4_fb_speed_limit_rate = f4_limit_rate;
}
