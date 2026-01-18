/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name   : r_motor_inverter_cfg.h
* Description : Definitions of inverter board parameters
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version
*         : 05.08.2022 1.00
***********************************************************************************************************************/

/* Guard against multiple inclusion */
#ifndef R_MOTOR_INVERTER_CFG_H
#define R_MOTOR_INVERTER_CFG_H

#include "r_smc_entry.h"

/***********************************************************************************************************************
* Includes <System Includes> , "Project Includes"
***********************************************************************************************************************/
/*
 * Hardware system configurations
 */
//#define MOTOR_COMMON_CFG_BOARD_MCILV1          /* Renesas Flexible Motor Control Kit(RTK0EM0000B12020BJ) */
#define MOTOR_COMMON_CFG_BOARD_IHM16M1

/***********************************************************************************************************************
* Target Inverter Define
***********************************************************************************************************************/
/* Target Inverter definitions */
#ifdef MOTOR_COMMON_CFG_BOARD_MCILV1

#define     INVERTER_CFG_SHUNT_RESIST           (0.010f)                      /* Resistance of shunt resistor [ohm] */
#define     INVERTER_CFG_DEADTIME               (CG_CONFIG_MOTOR_DEADTIME)    /* Deadtime [us] */
#define     INVERTER_CFG_VOLTAGE_GAIN           (22.2766f)                    /* Voltage measurement gain */
#define     INVERTER_CFG_CURRENT_AMP_GAIN       (20.0f)                       /* Current amplifier gain */
#define     INVERTER_CFG_CURRENT_LIMIT          (21.4f)                       /* Current limit[A] for the inverter board */
#define     INVERTER_CFG_OVERVOLTAGE_LIMIT      (60.0f)                       /* Over voltage limit [V] */
#define     INVERTER_CFG_UNDERVOLTAGE_LIMIT     (8.0f)                        /* Under voltage limit [V] */
#define     INVERTER_CFG_INPUT_V                (24.0f)                       /* Nominal Vdc [V] */
#define     INVERTER_CFG_ADC_REF_VOLTAGE        (5.0f)

#endif /* MOTOR_COMMON_CFG_BOARD_MCILV1 */

#ifdef MOTOR_COMMON_CFG_BOARD_IHM16M1


#define INVERTER_CFG_SHUNT_RESIST (0.33f) /* Resistance of shunt resistor [ohm] */
#define INVERTER_CFG_DEADTIME (CG_CONFIG_MOTOR_DEADTIME) /* Deadtime [us] */
#define INVERTER_CFG_VOLTAGE_GAIN (16) /* Voltage measurement gain */
#define INVERTER_CFG_CURRENT_AMP_GAIN (1.53f) /* Current amplifier gain */
#define INVERTER_CFG_CURRENT_LIMIT (2.5f) /* Current limit[A] for the inverter board */
#define INVERTER_CFG_OVERVOLTAGE_LIMIT (45.0f) /* Over voltage limit [V] */
#define INVERTER_CFG_UNDERVOLTAGE_LIMIT (7.0f) /* Under voltage limit [V] */
#define INVERTER_CFG_INPUT_V (24.0f) /* Nominal Vdc [V] */
#define INVERTER_CFG_ADC_REF_VOLTAGE (3.3f)




#endif

/* Voltage error compensation User set value. */
#define     INVERTER_CFG_COMP_V0                (0.564f)
#define     INVERTER_CFG_COMP_V1                (0.782f)
#define     INVERTER_CFG_COMP_V2                (0.937f)
#define     INVERTER_CFG_COMP_V3                (1.027f)
#define     INVERTER_CFG_COMP_V4                (1.058f)

#define     INVERTER_CFG_COMP_I0                (0.022f)
#define     INVERTER_CFG_COMP_I1                (0.038f)
#define     INVERTER_CFG_COMP_I2                (0.088f)
#define     INVERTER_CFG_COMP_I3                (0.248f)
#define     INVERTER_CFG_COMP_I4                (0.865f)

#endif /* R_MOTOR_INVERTER_CFG_H */
