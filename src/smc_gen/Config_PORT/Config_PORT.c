/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_PORT.c
* Component Version: 2.4.1
* Device(s)        : R5F526TFCxFM
* Description      : This file implements device driver for Config_PORT.
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_motor_common.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT2 registers */
    PORT2.PODR.BYTE = _00_Pm0_OUTPUT_0 | _00_Pm1_OUTPUT_0 | _00_Pm2_OUTPUT_0;
    PORT2.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT;
    PORT2.DSCR.BYTE = _00_Pm0_HIDRV_OFF | _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF;
    PORT2.PMR.BYTE &= (_FE_Pm0_PIN_GPIO & _FD_Pm1_PIN_GPIO & _FB_Pm2_PIN_GPIO);
    PORT2.PDR.BYTE = _01_Pm0_MODE_OUTPUT | _02_Pm1_MODE_OUTPUT | _04_Pm2_MODE_OUTPUT | _98_PDR2_DEFAULT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
uint8_t R_Config_PORT_GetSW1(void)
{
 //   return(PORT2.PIDR.BIT.B3);
} /* End of function R_Config_PORT_GetSW1 */

/******************************************************************************
* Function Name : R_Config_PORT_GetSW2
* Description   : Get state of SW2
* Arguments     : none
* Return Value  : state of SW2
******************************************************************************/
uint8_t R_Config_PORT_GetSW2(void)
{
 //   return (PORT2.PIDR.BIT.B2);
} /* End of function R_Config_PORT_GetSW2 */

/******************************************************************************
* Function Name : R_Config_PORT_Led1_on
* Description   : Turn on LED1
* Arguments     : none
* Return Value  : none
******************************************************************************/
void R_Config_PORT_Led1_on(void)
{
    PORT2.PODR.BIT.B1 = MTR_LED_ON;
} /* End of function R_Config_PORT_Led1_on */

/******************************************************************************
* Function Name : R_Config_PORT_Led2_on
* Description   : Turn on LED2
* Arguments     : none
* Return Value  : none
******************************************************************************/
void R_Config_PORT_Led2_on(void)
{
    PORT2.PODR.BIT.B0 = MTR_LED_ON;
} /* End of function R_Config_PORT_Led2_on */

/******************************************************************************
* Function Name : R_Config_PORT_Led1_off
* Description   : Turn off LED1
* Arguments     : none
* Return Value  : none
******************************************************************************/
void R_Config_PORT_Led1_off(void)
{
    PORT2.PODR.BIT.B1 = MTR_LED_OFF;
} /* End of function R_Config_PORT_Led1_off */

/******************************************************************************
* Function Name : R_Config_PORT_Led2_off
* Description   : Turn off LED2
* Arguments     : none
* Return Value  : none
******************************************************************************/
void R_Config_PORT_Led2_off(void)
{
    PORT2.PODR.BIT.B0 = MTR_LED_OFF;
} /* End of function R_Config_PORT_Led2_off */
/* End user code. Do not edit comment generated here */
