/***********************************************************************************************************************
* DISCLAIMER
***********************************************************************************************************************/

#include "r_motor_speed_opl2less.h"

#include <math.h>

float motor_speed_opl2less_iq_calc(float f4_ed,
                                   float f4_eq,
                                   float f4_id,
                                   float f4_torque_current,
                                   float f4_phase_err)
{
    float f4_iq_ref;

    (void)f4_ed;
    (void)f4_eq;
    (void)f4_id;

    f4_iq_ref = f4_torque_current * cosf(f4_phase_err);
    return f4_iq_ref;
}

float motor_speed_opl2less_torque_current_calc(const st_motor_parameter_t * p_st_motor,
                                               float f4_opl2less_sw_time,
                                               float f4_ol_id_ref,
                                               float f4_phase_err_rad_lpf)
{
    float f4_torque_current;
    float f4_gain;

    if ((0 == p_st_motor) || (f4_opl2less_sw_time <= 0.0f))
    {
        return 0.0f;
    }

    f4_gain = (p_st_motor->f4_mtr_j * f4_phase_err_rad_lpf)
            / (f4_opl2less_sw_time * (p_st_motor->f4_mtr_m + (p_st_motor->f4_mtr_ld * f4_ol_id_ref) + 1.0e-6f));

    f4_torque_current = f4_gain;
    return f4_torque_current;
}
