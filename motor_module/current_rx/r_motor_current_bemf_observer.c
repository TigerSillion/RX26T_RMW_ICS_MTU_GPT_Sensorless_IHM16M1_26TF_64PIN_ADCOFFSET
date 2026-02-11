/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
***********************************************************************************************************************/

#include "r_motor_current_bemf_observer.h"

#include <math.h>

#define BEMF_OBS_EPSILON (1.0e-6f)

static void motor_current_bemf_observer_axis_start(st_bemf_obs_axis_t * p_st_axis,
                                                    float f4_dt,
                                                    float f4_r,
                                                    float f4_v_ref,
                                                    float f4_i)
{
    float f4_i_err;
    float f4_i_est;
    float f4_d_est;

    f4_i_err = f4_i - p_st_axis->f4_i_est_pre;

    f4_i_est = p_st_axis->f4_i_est_pre + (f4_dt * ((f4_v_ref - (f4_r * f4_i))
            + p_st_axis->f4_d_est_pre + (p_st_axis->f4_k_e_obs_1 * f4_i_err)));

    f4_d_est = p_st_axis->f4_d_est_pre + (f4_dt * (p_st_axis->f4_k_e_obs_2 * f4_i_err));

    if (f4_d_est > p_st_axis->f4_d_est_limit)
    {
        f4_d_est = p_st_axis->f4_d_est_limit;
    }
    else if (f4_d_est < (-p_st_axis->f4_d_est_limit))
    {
        f4_d_est = -p_st_axis->f4_d_est_limit;
    }

    p_st_axis->f4_i_pre = f4_i;
    p_st_axis->f4_i_est_pre = f4_i_est;
    p_st_axis->f4_d_est = f4_d_est;
    p_st_axis->f4_d_est_pre = f4_d_est;
}

void motor_current_bemf_observer_start(st_bemf_observer_t * p_st_bemf_observer,
                                       float f4_vd_ref,
                                       float f4_vq_ref,
                                       float f4_id,
                                       float f4_iq)
{
    float f4_r;

    f4_r = p_st_bemf_observer->p_st_motor->f4_mtr_r;

    motor_current_bemf_observer_axis_start(&p_st_bemf_observer->st_d_axis,
                                           p_st_bemf_observer->f4_dt,
                                           f4_r,
                                           f4_vd_ref,
                                           f4_id);

    motor_current_bemf_observer_axis_start(&p_st_bemf_observer->st_q_axis,
                                           p_st_bemf_observer->f4_dt,
                                           f4_r,
                                           f4_vq_ref,
                                           f4_iq);
}

float motor_current_bemf_observer_d_calc(st_bemf_observer_t * p_st_bemf_observer, float f4_speed_rad, float f4_iq)
{
    return p_st_bemf_observer->st_d_axis.f4_d_est
            - (f4_speed_rad * p_st_bemf_observer->p_st_motor->f4_mtr_lq * f4_iq);
}

float motor_current_bemf_observer_q_calc(st_bemf_observer_t * p_st_bemf_observer, float f4_speed_rad, float f4_id)
{
    return p_st_bemf_observer->st_q_axis.f4_d_est
            + (f4_speed_rad * ((p_st_bemf_observer->p_st_motor->f4_mtr_ld * f4_id)
            + p_st_bemf_observer->p_st_motor->f4_mtr_m));
}

float motor_current_bemf_observer_amp_calc(float f4_ed, float f4_eq)
{
    return sqrtf((f4_ed * f4_ed) + (f4_eq * f4_eq));
}

void motor_current_bemf_observer_init(st_bemf_observer_t * p_st_bemf_observer, st_motor_parameter_t * p_st_motor)
{
    p_st_bemf_observer->p_st_motor = p_st_motor;
    p_st_bemf_observer->f4_dt = 0.0f;

    p_st_bemf_observer->st_d_axis.f4_k_e_obs_1 = 0.0f;
    p_st_bemf_observer->st_d_axis.f4_k_e_obs_2 = 0.0f;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_1 = 0.0f;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_2 = 0.0f;

    p_st_bemf_observer->st_d_axis.f4_d_est_limit = 1.0e6f;
    p_st_bemf_observer->st_q_axis.f4_d_est_limit = 1.0e6f;

    motor_current_bemf_observer_reset(p_st_bemf_observer);
}

void motor_current_bemf_observer_gain_calc(st_bemf_observer_t * p_st_bemf_observer,
                                           st_motor_parameter_t * p_st_motor,
                                           float f4_e_obs_omega_hz,
                                           float f4_e_obs_zeta,
                                           float f4_ctrl_period)
{
    float f4_omega;
    float f4_k1;
    float f4_k2;
    float f4_limit;

    f4_omega = MTR_TWOPI * f4_e_obs_omega_hz;
    f4_k1 = 2.0f * f4_e_obs_zeta * f4_omega;
    f4_k2 = f4_omega * f4_omega;

    p_st_bemf_observer->p_st_motor = p_st_motor;
    p_st_bemf_observer->f4_dt = f4_ctrl_period;

    p_st_bemf_observer->st_d_axis.f4_k_e_obs_1 = f4_k1;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_1 = f4_k1;
    p_st_bemf_observer->st_d_axis.f4_k_e_obs_2 = f4_k2 * p_st_motor->f4_mtr_ld;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_2 = f4_k2 * p_st_motor->f4_mtr_lq;

    f4_limit = (p_st_motor->f4_nominal_current_rms * MTR_SQRT_2 * p_st_motor->f4_mtr_r) + fabsf(p_st_motor->f4_mtr_m * f4_omega);
    if (f4_limit < BEMF_OBS_EPSILON)
    {
        f4_limit = 1.0e6f;
    }

    p_st_bemf_observer->st_d_axis.f4_d_est_limit = f4_limit;
    p_st_bemf_observer->st_q_axis.f4_d_est_limit = f4_limit;
}

void motor_current_bemf_observer_gain_set(st_bemf_observer_t * p_st_bemf_observer,
                                          float f4_dt,
                                          float f4_k1_d,
                                          float f4_k2_d,
                                          float f4_k1_q,
                                          float f4_k2_q)
{
    p_st_bemf_observer->f4_dt = f4_dt;
    p_st_bemf_observer->st_d_axis.f4_k_e_obs_1 = f4_k1_d;
    p_st_bemf_observer->st_d_axis.f4_k_e_obs_2 = f4_k2_d;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_1 = f4_k1_q;
    p_st_bemf_observer->st_q_axis.f4_k_e_obs_2 = f4_k2_q;
}

void motor_current_bemf_observer_reset(st_bemf_observer_t * p_st_bemf_observer)
{
    p_st_bemf_observer->st_d_axis.f4_i_pre = 0.0f;
    p_st_bemf_observer->st_d_axis.f4_i_est_pre = 0.0f;
    p_st_bemf_observer->st_d_axis.f4_d_est = 0.0f;
    p_st_bemf_observer->st_d_axis.f4_d_est_pre = 0.0f;

    p_st_bemf_observer->st_q_axis.f4_i_pre = 0.0f;
    p_st_bemf_observer->st_q_axis.f4_i_est_pre = 0.0f;
    p_st_bemf_observer->st_q_axis.f4_d_est = 0.0f;
    p_st_bemf_observer->st_q_axis.f4_d_est_pre = 0.0f;
}

void motor_current_angle_speed_pll(st_pll_est_t * p_st_pll_est, float f4_phase_err, float * f4_speed)
{
    p_st_pll_est->f4_i_est_speed += (p_st_pll_est->f4_ki_est_speed * f4_phase_err);
    *f4_speed = p_st_pll_est->f4_i_est_speed + (p_st_pll_est->f4_kp_est_speed * f4_phase_err);
}

void motor_current_angle_speed_init(st_pll_est_t * p_st_pll_est)
{
    p_st_pll_est->f4_kp_est_speed = 0.0f;
    p_st_pll_est->f4_ki_est_speed = 0.0f;
    p_st_pll_est->f4_i_est_speed = 0.0f;
}

void motor_current_angle_speed_gain_calc(st_pll_est_t * p_st_pll_est,
                                         float f4_pll_est_omega_hz,
                                         float f4_pll_est_zeta,
                                         float f4_ctrl_period)
{
    float f4_omega;

    f4_omega = MTR_TWOPI * f4_pll_est_omega_hz;
    p_st_pll_est->f4_kp_est_speed = 2.0f * f4_pll_est_zeta * f4_omega;
    p_st_pll_est->f4_ki_est_speed = (f4_omega * f4_omega) * f4_ctrl_period;
}

void motor_current_angle_speed_gain_set(st_pll_est_t * p_st_pll_est, float f4_kp, float f4_ki)
{
    p_st_pll_est->f4_kp_est_speed = f4_kp;
    p_st_pll_est->f4_ki_est_speed = f4_ki;
}

void motor_current_angle_speed_reset(st_pll_est_t * p_st_pll_est)
{
    p_st_pll_est->f4_i_est_speed = 0.0f;
}
