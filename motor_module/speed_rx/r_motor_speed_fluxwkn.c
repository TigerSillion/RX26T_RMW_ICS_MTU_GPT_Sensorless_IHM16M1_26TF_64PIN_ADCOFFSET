/***********************************************************************************************************************
* DISCLAIMER
***********************************************************************************************************************/

#include "r_motor_speed_fluxwkn.h"

#include <math.h>

static void motor_speed_flux_weakn_update_limits(st_fluxwkn_t * p_st_fluxwkn)
{
    if ((0 != p_st_fluxwkn->p_motor) && (p_st_fluxwkn->p_motor->f4_mtr_ld > 0.0f))
    {
        p_st_fluxwkn->f4_id_demag = -(p_st_fluxwkn->p_motor->f4_mtr_m / p_st_fluxwkn->p_motor->f4_mtr_ld);
    }
    else
    {
        p_st_fluxwkn->f4_id_demag = 0.0f;
    }

    p_st_fluxwkn->f4_id_min = (p_st_fluxwkn->f4_id_demag < -p_st_fluxwkn->f4_ia_max)
            ? p_st_fluxwkn->f4_id_demag : -p_st_fluxwkn->f4_ia_max;
    p_st_fluxwkn->f4_v_fw = p_st_fluxwkn->f4_va_max * p_st_fluxwkn->f4_vfw_ratio;
}

void motor_speed_flux_weakn_init(st_fluxwkn_t * p_st_fluxwkn,
                                 float f4_ia_max,
                                 float f4_va_max,
                                 float f4_vfw_ratio,
                                 const st_motor_parameter_t * p_st_motor)
{
    p_st_fluxwkn->p_motor = p_st_motor;
    p_st_fluxwkn->f4_ia_max = f4_ia_max;
    p_st_fluxwkn->f4_va_max = f4_va_max;
    p_st_fluxwkn->f4_vfw_ratio = f4_vfw_ratio;

    motor_speed_flux_weakn_update_limits(p_st_fluxwkn);
    p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_BYPASSED;
}

void motor_speed_flux_weakn_reset(st_fluxwkn_t * p_st_fluxwkn)
{
    p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_BYPASSED;
}

uint16_t motor_speed_flux_weakn_start(st_fluxwkn_t * p_st_fluxwkn,
                                      float f4_speed_rad,
                                      const float *p_f4_idq,
                                      float *p_f4_idq_ref)
{
    float f4_v_required;

    (void)p_f4_idq;

    if (motor_speed_flux_weakn_invalid_parameter_check(p_st_fluxwkn))
    {
        return p_st_fluxwkn->u2_fw_status;
    }

    f4_v_required = fabsf(f4_speed_rad) * (p_st_fluxwkn->p_motor->f4_mtr_m
            + (p_st_fluxwkn->p_motor->f4_mtr_ld * p_f4_idq_ref[0]));

    if (f4_v_required <= p_st_fluxwkn->f4_v_fw)
    {
        p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_BYPASSED;
        return p_st_fluxwkn->u2_fw_status;
    }

    if (fabsf(f4_speed_rad) > 0.0f)
    {
        float f4_id_target;

        f4_id_target = (p_st_fluxwkn->f4_v_fw / fabsf(f4_speed_rad)) - p_st_fluxwkn->p_motor->f4_mtr_m;
        f4_id_target /= p_st_fluxwkn->p_motor->f4_mtr_ld;

        if (f4_id_target < p_st_fluxwkn->f4_id_min)
        {
            p_f4_idq_ref[0] = p_st_fluxwkn->f4_id_min;
            p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_IDSAT;
        }
        else
        {
            p_f4_idq_ref[0] = f4_id_target;
            p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_FLUXWKN;
        }
    }

    return p_st_fluxwkn->u2_fw_status;
}

void motor_speed_flux_weakn_motor_set(st_fluxwkn_t * p_st_fluxwkn, const st_motor_parameter_t * p_st_motor)
{
    p_st_fluxwkn->p_motor = p_st_motor;
    motor_speed_flux_weakn_update_limits(p_st_fluxwkn);
}

void motor_speed_flux_weakn_iamax_set(st_fluxwkn_t * p_st_fluxwkn, float f4_ia_max)
{
    p_st_fluxwkn->f4_ia_max = f4_ia_max;
    motor_speed_flux_weakn_update_limits(p_st_fluxwkn);
}

void motor_speed_flux_weakn_vamax_set(st_fluxwkn_t * p_st_fluxwkn, float f4_va_max)
{
    p_st_fluxwkn->f4_va_max = f4_va_max;
    motor_speed_flux_weakn_update_limits(p_st_fluxwkn);
}

void motor_speed_flux_weakn_vfw_ratio_set(st_fluxwkn_t * p_st_fluxwkn, float f4_vfw_ratio)
{
    p_st_fluxwkn->f4_vfw_ratio = f4_vfw_ratio;
    motor_speed_flux_weakn_update_limits(p_st_fluxwkn);
}

float motor_speed_flux_weakn_iamax_get(st_fluxwkn_t * p_st_fluxwkn)
{
    return p_st_fluxwkn->f4_ia_max;
}

float motor_speed_flux_weakn_vamax_get(st_fluxwkn_t * p_st_fluxwkn)
{
    return p_st_fluxwkn->f4_va_max;
}

float motor_speed_flux_weakn_vfw_ratio_get(st_fluxwkn_t * p_st_fluxwkn)
{
    return p_st_fluxwkn->f4_vfw_ratio;
}

uint16_t motor_speed_flux_weakn_status_get(st_fluxwkn_t * p_st_fluxwkn)
{
    return p_st_fluxwkn->u2_fw_status;
}

uint8_t motor_speed_flux_weakn_error_check(st_fluxwkn_t * p_st_fluxwkn)
{
    return ((p_st_fluxwkn->u2_fw_status & FLUXWKN_STATE_ERROR) == FLUXWKN_STATE_ERROR) ? MTR_TRUE : MTR_FALSE;
}

uint8_t motor_speed_flux_weakn_invalid_parameter_check(st_fluxwkn_t * p_st_fluxwkn)
{
    if ((0 == p_st_fluxwkn->p_motor)
            || (p_st_fluxwkn->p_motor->f4_mtr_ld <= 0.0f)
            || (p_st_fluxwkn->p_motor->f4_mtr_lq <= 0.0f)
            || (p_st_fluxwkn->p_motor->f4_mtr_m <= 0.0f))
    {
        p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_INVALID_MOTOR;
    }
    else if (p_st_fluxwkn->f4_ia_max < 0.0f)
    {
        p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_INVALID_IAMAX;
    }
    else if (p_st_fluxwkn->f4_va_max < 0.0f)
    {
        p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_INVALID_VAMAX;
    }
    else if ((p_st_fluxwkn->f4_vfw_ratio < FLUXWKN_DEF_VFWRATIO_MIN)
            || (p_st_fluxwkn->f4_vfw_ratio > 1.0f))
    {
        p_st_fluxwkn->u2_fw_status = FLUXWKN_STATE_INVALID_VFWRATIO;
    }

    return motor_speed_flux_weakn_error_check(p_st_fluxwkn);
}

uint8_t motor_speed_flux_weakn_run_time_error_check(st_fluxwkn_t * p_st_fluxwkn)
{
    return ((p_st_fluxwkn->u2_fw_status & FLUXWKN_STATE_ERROR) == FLUXWKN_STATE_ERROR
            && ((p_st_fluxwkn->u2_fw_status & 0xF000U) != 0x9000U)) ? MTR_TRUE : MTR_FALSE;
}
