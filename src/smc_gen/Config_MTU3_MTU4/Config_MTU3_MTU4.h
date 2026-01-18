/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU3_MTU4.h
* Component Version: 1.11.0
* Device(s)        : R5F526TFCxFM
* Description      : This file implements device driver for Config_MTU3_MTU4.
***********************************************************************************************************************/

#ifndef CFG_Config_MTU3_MTU4_H
#define CFG_Config_MTU3_MTU4_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu3.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define MTU3_PCLK_COUNTER_DIVISION      (1)
#define _00F0_3TCNT_VALUE               (0x00F0U) /* MTU3.TCNT value */
#define _00F0_TDDRA_VALUE               (0x00F0U) /* MTU.TDDRA value */
#define _0BB8_TCDRA_VALUE               (0x0BB8U) /* MTU.TCDRA value */
#define _0654_3TGRB_VALUE               (0x0654U) /* MTU3.TGRB value */
#define _0654_4TGRA_VALUE               (0x0654U) /* MTU4.TGRA value */
#define _0654_4TGRB_VALUE               (0x0654U) /* MTU4.TGRB value */
/* Timer A/D Converter Start Request Cycle Set Registers A value */
#define _0002_TADCORA_VALUE             (0x0002U) /* MTU4.TADCORA value */
/* Timer A/D Converter Start Request Cycle Set Buffer Registers A value */
#define _0002_TADCOBRA_VALUE            (0x0002U) /* MTU4.TADCOBRA value */
#define _0CA8_SUM_VALUE                 (0x0CA8U) /* Timer General Register (TGR) value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU3_MTU4_Create(void);
void R_Config_MTU3_MTU4_Create_UserInit(void);
void R_Config_MTU3_MTU4_Start(void);
void R_Config_MTU3_MTU4_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
