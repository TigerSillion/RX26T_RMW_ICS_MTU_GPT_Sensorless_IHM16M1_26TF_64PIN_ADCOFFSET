/***********************************************************************************************************************
#include <Config_MOTOR/Config_MOTOR.h>
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_MOTOR_user.c
* Component Version: 1.1.0
* Device(s)        : R5F526TFCxFP
* Description      : This file implements device driver for Config_MOTOR.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_motor_sensorless_vector_api.h"
#include "r_app_rmw.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_Create_UserInit
* Description  : This function adds user code after initializing the MTU channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MOTOR_ad_interrupt
* Description  : This function is S12ADI interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if 0
#if FAST_INTERRUPT_VECTOR == VECT_S12AD_S12ADI
#pragma interrupt r_Config_MOTOR_ad_interrupt(vect=VECT(S12AD,S12ADI),fint)
#else
#pragma interrupt r_Config_MOTOR_ad_interrupt(vect=VECT(S12AD,S12ADI))
#endif
static void r_Config_MOTOR_ad_interrupt(void)
{
    /* Start user code for r_Config_MOTOR_ad_interrupt-1. Do not edit comment generated here */
    R_MOTOR_SENSORLESS_VECTOR_CurrentInterrupt(&g_st_sensorless_vector);
    r_app_rmw_interrupt_handler();
    /* End user code. Do not edit comment generated here */
    
    /* Start user code for r_Config_MOTOR_ad_interrupt-2. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
#endif
/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
