/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
***********************************************************************************************************************/

#include "r_motor_current_volt_err_comp.h"

#include <math.h>

static float motor_current_volt_err_comp_interp(st_volt_comp_t * p_st_volt_comp, float f4_i_abs)
{
    uint8_t u1_idx;

    if (f4_i_abs <= p_st_volt_comp->f4_comp_i[0])
    {
        return (p_st_volt_comp->f4_slope[0] * f4_i_abs) + p_st_volt_comp->f4_intcept[0];
    }

    for (u1_idx = 0; u1_idx < (VERR_COMP_ARY_SIZE - 1); u1_idx++)
    {
        if (f4_i_abs <= p_st_volt_comp->f4_comp_i[u1_idx + 1])
        {
            return (p_st_volt_comp->f4_slope[u1_idx + 1] * f4_i_abs) + p_st_volt_comp->f4_intcept[u1_idx + 1];
        }
    }

    return (p_st_volt_comp->f4_slope[VERR_COMP_ARY_SIZE] * f4_i_abs)
            + p_st_volt_comp->f4_intcept[VERR_COMP_ARY_SIZE];
}

void motor_current_volt_err_comp_init(st_volt_comp_t *p_st_volt_comp, uint8_t u1_volt_comp_use_motor_type)
{
    static const float s_f4_default_comp_v[VERR_COMP_ARY_SIZE] = {
        VERR_COMP_TBL_COMP_V0,
        VERR_COMP_TBL_COMP_V1,
        VERR_COMP_TBL_COMP_V2,
        VERR_COMP_TBL_COMP_V3,
        VERR_COMP_TBL_COMP_V4
    };
    static const float s_f4_default_comp_i[VERR_COMP_ARY_SIZE] = {
        VERR_COMP_TBL_COMP_I0,
        VERR_COMP_TBL_COMP_I1,
        VERR_COMP_TBL_COMP_I2,
        VERR_COMP_TBL_COMP_I3,
        VERR_COMP_TBL_COMP_I4
    };

    p_st_volt_comp->u1_volt_comp_use_motor_type = u1_volt_comp_use_motor_type;
    p_st_volt_comp->u1_volt_err_comp_enable = (VERROR_COMP_USE_OFF == u1_volt_comp_use_motor_type)
            ? VERR_COMP_DISABLE : VERR_COMP_ENABLE;

    motor_current_volt_err_comp_table_set(p_st_volt_comp,
                                          s_f4_default_comp_i,
                                          s_f4_default_comp_v,
                                          VERR_COMP_REF_VOLTAGE);
    motor_current_volt_err_vlimit_set(p_st_volt_comp, 1.0f);
    motor_current_volt_err_comp_reset(p_st_volt_comp);
}

void motor_current_volt_err_comp_reset(st_volt_comp_t *p_st_volt_comp)
{
    p_st_volt_comp->f4_volt_comp_array[0] = 0.0f;
    p_st_volt_comp->f4_volt_comp_array[1] = 0.0f;
    p_st_volt_comp->f4_volt_comp_array[2] = 0.0f;
}

void motor_current_volt_err_comp_main(st_volt_comp_t *p_st_volt_comp,
                                      float *p_f4_v_array,
                                      float *p_f4_i_array,
                                      float f4_vdc)
{
    uint8_t u1_phase_num;
    uint8_t u1_idx;
    float f4_limit;

    if (VERR_COMP_ENABLE != p_st_volt_comp->u1_volt_err_comp_enable)
    {
        return;
    }

    p_st_volt_comp->f4_vdc = f4_vdc;
    f4_limit = p_st_volt_comp->f4_volt_comp_limit_ratio * f4_vdc;
    p_st_volt_comp->f4_volt_comp_limit = f4_limit;

    u1_phase_num = (VERROR_COMP_USE_AB == p_st_volt_comp->u1_volt_comp_use_motor_type) ? 2U : 3U;

    for (u1_idx = 0; u1_idx < u1_phase_num; u1_idx++)
    {
        float f4_i;
        float f4_comp_abs;
        float f4_comp;

        f4_i = p_f4_i_array[u1_idx];
        f4_comp_abs = motor_current_volt_err_comp_interp(p_st_volt_comp, fabsf(f4_i));
        f4_comp = (f4_i >= 0.0f) ? f4_comp_abs : -f4_comp_abs;

        if (f4_comp > f4_limit)
        {
            f4_comp = f4_limit;
        }
        else if (f4_comp < -f4_limit)
        {
            f4_comp = -f4_limit;
        }

        p_st_volt_comp->f4_volt_comp_array[u1_idx] = f4_comp;
        p_f4_v_array[u1_idx] += f4_comp;
    }
}

void motor_current_volt_err_comp_table_set(st_volt_comp_t *p_st_volt_comp,
                                       const float *f4_current_table,
                                       const float *f4_volterr_table,
                                       float f4_ref_vdc)
{
    uint8_t u1_idx;

    p_st_volt_comp->f4_vdc = f4_ref_vdc;

    for (u1_idx = 0; u1_idx < VERR_COMP_ARY_SIZE; u1_idx++)
    {
        p_st_volt_comp->f4_comp_i[u1_idx] = f4_current_table[u1_idx];
        p_st_volt_comp->f4_comp_v[u1_idx] = f4_volterr_table[u1_idx];
    }

    if (p_st_volt_comp->f4_comp_i[0] != 0.0f)
    {
        p_st_volt_comp->f4_slope[0] = p_st_volt_comp->f4_comp_v[0] / p_st_volt_comp->f4_comp_i[0];
    }
    else
    {
        p_st_volt_comp->f4_slope[0] = 0.0f;
    }
    p_st_volt_comp->f4_intcept[0] = 0.0f;

    for (u1_idx = 0; u1_idx < (VERR_COMP_ARY_SIZE - 1); u1_idx++)
    {
        float f4_dx;

        f4_dx = p_st_volt_comp->f4_comp_i[u1_idx + 1] - p_st_volt_comp->f4_comp_i[u1_idx];
        if (fabsf(f4_dx) < 1.0e-6f)
        {
            p_st_volt_comp->f4_slope[u1_idx + 1] = 0.0f;
        }
        else
        {
            p_st_volt_comp->f4_slope[u1_idx + 1] = (p_st_volt_comp->f4_comp_v[u1_idx + 1]
                    - p_st_volt_comp->f4_comp_v[u1_idx]) / f4_dx;
        }

        p_st_volt_comp->f4_intcept[u1_idx + 1] = p_st_volt_comp->f4_comp_v[u1_idx]
                - (p_st_volt_comp->f4_slope[u1_idx + 1] * p_st_volt_comp->f4_comp_i[u1_idx]);
    }

    p_st_volt_comp->f4_slope[VERR_COMP_ARY_SIZE] = p_st_volt_comp->f4_slope[VERR_COMP_ARY_SIZE - 1];
    p_st_volt_comp->f4_intcept[VERR_COMP_ARY_SIZE] = p_st_volt_comp->f4_comp_v[VERR_COMP_ARY_SIZE - 1]
            - (p_st_volt_comp->f4_slope[VERR_COMP_ARY_SIZE] * p_st_volt_comp->f4_comp_i[VERR_COMP_ARY_SIZE - 1]);
}

void motor_current_volt_err_vlimit_set(st_volt_comp_t *p_st_volt_comp, float f4_vlimit_ratio)
{
    p_st_volt_comp->f4_volt_comp_limit_ratio = f4_vlimit_ratio;
}
