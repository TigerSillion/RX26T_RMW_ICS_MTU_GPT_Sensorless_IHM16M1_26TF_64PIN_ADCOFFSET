/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_IWDT.c
* Component Version: 1.11.0
* Device(s)        : R5F526TFCxFM
* Description      : This file implements device driver for Config_IWDT.
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
#include "Config_IWDT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_IWDT_Create
* Description  : This function initializes the IWDT module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_IWDT_Create(void)
{
    /* Set control registers */
    IWDT.IWDTCR.WORD = _0003_IWDT_TIMEOUT_16384 | _00F0_IWDT_CLOCK_DIV128 | _0300_IWDT_WINDOW_END_0 | 
                       _3000_IWDT_WINDOW_START_100;
    IWDT.IWDTRCR.BYTE = _80_IWDT_RESET_OUTPUT;
    IWDT.IWDTCSTPR.BYTE = _80_IWDT_COUNT_STOP_ENABLE;
    
    R_Config_IWDT_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_IWDT_Restart
* Description  : This function restarts IWDT module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_IWDT_Restart(void)
{
    /* Refreshed by writing 00h and then writing FFh */
    IWDT.IWDTRR = 0x00U;
    IWDT.IWDTRR = 0xFFU;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
