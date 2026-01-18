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
* File Name        : Config_MOTOR.c
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
#include "r_cg_userdefine.h"
#include "Config_MOTOR.h"
#include "r_smc_entry.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_Create
* Description  : This function initializes the MTU for motor
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_Create(void)
{
    #if 0
    /* Release MTU channel 3 from stop state */
    MSTP(MTU3) = 0U;
    /* Enable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 1U;
    /* Stop MTU3, MTU4 counter */
    MTU.TSTRA.BYTE = MTU.TSTRA.BYTE & 0x3FU;

    /* Configure MTU3 and MTU4 as complementary PWM mode timer */
    MTU3.TIER.BYTE = 0x00U;
    MTU4.TIER.BYTE = 0x00U;
    MTU.TITCR1A.BIT.T3AEN = 0U;
    MTU.TITCR1A.BIT.T4VEN = 0U;
    MTU3.TCR.BYTE = _00_MTR_MTU_PCLK_1 | _00_MTR_MTU_CKEG_RISE;
    MTU4.TCR.BYTE = _00_MTR_MTU_PCLK_1 | _00_MTR_MTU_CKEG_RISE;
    MTU3.TCR2.BYTE = _00_MTR_MTU_PCLK_1;
    MTU4.TCR2.BYTE = _00_MTR_MTU_PCLK_1;
    MTU3.TCNT = _00F0_3TCNT_VALUE;
    MTU4.TCNT = 0x0000U;
    MTU.TSYRA.BIT.SYNC3 = 0U;
    MTU.TSYRA.BIT.SYNC4 = 0U;
    MTU3.TGRB = _0654_3TGRB_VALUE;
    MTU3.TGRD = _0654_3TGRB_VALUE;
    MTU4.TGRA = _0654_4TGRA_VALUE;
    MTU4.TGRC = _0654_4TGRA_VALUE;
    MTU4.TGRB = _0654_4TGRB_VALUE;
    MTU4.TGRD = _0654_4TGRB_VALUE;
    MTU.TDERA.BIT.TDER = 1U;
    MTU.TDDRA = _00F0_TDDRA_VALUE;
    MTU.TCDRA = _0BB8_TCDRA_VALUE;
    MTU.TCBRA = _0BB8_TCDRA_VALUE;
    MTU3.TGRA = _0CA8_SUM_VALUE;
    MTU3.TGRC = _0CA8_SUM_VALUE;
    MTU.TOCR1A.BYTE = _00_MTR_MTU_PSYE_DISABLE | _08_MTR_MTU_TOCL_DISABLE | _04_MTR_MTU_TOCS_TOCR2;
    MTU.TOCR2A.BYTE = _20_MTR_MTU_OLS3N_LH | _10_MTR_MTU_OLS3P_LH | _08_MTR_MTU_OLS2N_LH | _04_MTR_MTU_OLS2P_LH | 
                      _02_MTR_MTU_OLS1N_LH | _01_MTR_MTU_OLS1P_LH;
    MTU.TOLBRA.BYTE = MTU.TOCR2A.BYTE & 0x3FU;
    MTU4.TADCORA = _0002_MTR_MTU_TADCORA_VALUE;
    MTU4.TADCOBRA = _0002_MTR_MTU_TADCORA_VALUE;
    MTU4.TADCR.WORD = _0000_MTR_MTU_ADSYNCH_DISABLE | _0080_MTR_MTU_UTAE_ENABLE;
    MTU.TITMRA.BIT.TITM = 0U;
    MTU.TITCR1A.BYTE = _00_MTR_MTU_INT_SKIP_DISABLE << 4U | _00_MTR_MTU_INT_SKIP_DISABLE;
    MTU3.TMDR1.BYTE = _0E_MTR_MTU_CMT2 | _10_MTR_MTU_BFA_BUFFER | _20_MTR_MTU_BFB_BUFFER;
    MTU.TOERA.BYTE = 0xC0U;
    MTU3.TIORH.BYTE = 0x00U;
    MTU3.TIORL.BYTE = 0x00U;
    MTU4.TIORH.BYTE = 0x00U;
    MTU4.TIORL.BYTE = 0x00U;
    /* Disable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 0U;

    //Init Wp (MTIOC3B)
    PORT7.PODR.BIT.B1 = 0U; //Active High
    PORT7.PDR.BIT.B1 = 1U;
    PORT7.PMR.BIT.B1 = 0U;
    MPC.P71PFS.BIT.PSEL = 0x01U;
    //Init Wn (MTIOC3D)
    PORT7.PODR.BIT.B4 = 0U; //Active High
    PORT7.PDR.BIT.B4 = 1U;
    PORT7.PMR.BIT.B4 = 0U;
    MPC.P74PFS.BIT.PSEL = 0x01U;
    //Init Vp (MTIOC4A)
    PORT7.PODR.BIT.B2 = 0U; //Active High
    PORT7.PDR.BIT.B2 = 1U;
    PORT7.PMR.BIT.B2 = 0U;
    MPC.P72PFS.BIT.PSEL = 0x01U;
    //Init Up (MTIOC4B)
    PORT7.PODR.BIT.B3 = 0U; //Active High
    PORT7.PDR.BIT.B3 = 1U;
    PORT7.PMR.BIT.B3 = 0U;
    MPC.P73PFS.BIT.PSEL = 0x01U;
    //Init Vn (MTIOC4C)
    PORT7.PODR.BIT.B5 = 0U; //Active High
    PORT7.PDR.BIT.B5 = 1U;
    PORT7.PMR.BIT.B5 = 0U;
    MPC.P75PFS.BIT.PSEL = 0x01U;
    //Init Un (MTIOC4D)
    PORT7.PODR.BIT.B6 = 0U; //Active High
    PORT7.PDR.BIT.B6 = 1U;
    PORT7.PMR.BIT.B6 = 0U;
    MPC.P76PFS.BIT.PSEL = 0x01U;

    /* Cancel S12AD module stop state */
    MSTP(S12AD) = 0U;
    /* Disable and clear interrupt flags of S12AD module */
    S12AD.ADCSR.BIT.ADIE = 0U;
    IEN(S12AD, S12ADI) = 0U;

    /* Configure S12AD as single scan mode AD converter */
    S12AD.ADCSR.WORD = _0000_MTR_AD_SINGLE_SCAN_MODE;
    S12AD.ADSTRGR.WORD = _0900_MTR_AD_TRSA_TRG4AN;
    S12AD.ADANSA0.WORD = _0001_MTR_AD_AN000_USED | _0004_MTR_AD_AN002_USED | _0008_MTR_AD_AN003_USED;
    S12AD.ADSHCR.BIT.SHANS = _01_MTR_AD_DSH_AN000_SELECT | _04_MTR_AD_DSH_AN002_SELECT;
    S12AD.ADPGACR.BIT.P000CR = 1U;
    S12AD.ADPGACR.BIT.P002CR = 1U;
    S12AD.ADCSR.WORD |= _1000_MTR_AD_SCAN_END_INTERRUPT_ENABLE;
    IPR(S12AD, S12ADI) = _0C_MTR_PRIORITY_LEVEL12;
    //Init AN000
    PORT4.PDR.BIT.B0 = 0U;
    MPC.P40PFS.BIT.ASEL = 1U;
    //Init AN002
    PORT4.PDR.BIT.B2 = 0U;
    MPC.P42PFS.BIT.ASEL = 1U;
    //Init AN003
    PORT4.PDR.BIT.B3 = 0U;
    MPC.P43PFS.BIT.ASEL = 1U;

    R_Config_MOTOR_Create_UserInit();
    #endif
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StarttTimerCount
* Description  : This function starts the MTU3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StartTimerCount(void)
{
    #if 0
    /* Start MTU3, MTU4 counter */
    MTU.TCSYSTR.BYTE = (_10_MTR_MTU_SCH3_START | _08_MTR_MTU_SCH4_START);
    #endif
    R_Config_MTU3_MTU4_Start();
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StopTimerCount
* Description  : This function stops the MTU3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StopTimerCount(void)
{
#if 0
    /* Stop MTU3, MTU4 channel counter */
    MTU.TSTRA.BYTE = MTU.TSTRA.BYTE & 0x3FU;
#endif
    R_Config_MTU3_MTU4_Stop();
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StartTimerOutput
* Description  : This function starts the MTU output
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StartTimerCtrl(void)
{
    /* Enable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 1U;

    //Control Wp (MTIOC3B)
    PORT7.PODR.BIT.B1 = 0U; //Active High
    PORT7.PMR.BIT.B1 = 1U;
    //Control Wn (MTIOC3D)
    PORT7.PODR.BIT.B4 = 0U; //Active High
    PORT7.PMR.BIT.B4 = 1U;
    //Control Vp (MTIOC4A)
    PORT7.PODR.BIT.B2 = 0U; //Active High
    PORT7.PMR.BIT.B2 = 1U;
    //Control Up (MTIOC4B)
    PORT7.PODR.BIT.B3 = 0U; //Active High
    PORT7.PMR.BIT.B3 = 1U;
    //Control Vn (MTIOC4C)
    PORT7.PODR.BIT.B5 = 0U; //Active High
    PORT7.PMR.BIT.B5 = 1U;
    //Control Un (MTIOC4D)
    PORT7.PODR.BIT.B6 = 0U; //Active High
    PORT7.PMR.BIT.B6 = 1U;
    //Enable MTU3,MTU4 PWM output
    MTU.TOERA.BYTE = _C1_MTR_MTU_OE3B_ENABLE | _C8_MTR_MTU_OE3D_ENABLE | _C2_MTR_MTU_OE4A_ENABLE | 
                     _D0_MTR_MTU_OE4C_ENABLE | _C4_MTR_MTU_OE4B_ENABLE | _E0_MTR_MTU_OE4D_ENABLE;

    /* Disable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StopTimerOutput
* Description  : This function stops the MTU output
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StopTimerCtrl(void)
{
    /* Enable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 1U;

    //Disable MTU3,MTU4 PWM output
    MTU.TOERA.BYTE = 0xC0U;
    //Control Wp (MTIOC3B)
    PORT7.PODR.BIT.B1 = 0U; //Active High
    PORT7.PMR.BIT.B1 = 0U;
    //Control Wn (MTIOC3D)
    PORT7.PODR.BIT.B4 = 0U; //Active High
    PORT7.PMR.BIT.B4 = 0U;
    //Control Vp (MTIOC4A)
    PORT7.PODR.BIT.B2 = 0U; //Active High
    PORT7.PMR.BIT.B2 = 0U;
    //Control Up (MTIOC4B)
    PORT7.PODR.BIT.B3 = 0U; //Active High
    PORT7.PMR.BIT.B3 = 0U;
    //Control Vn (MTIOC4C)
    PORT7.PODR.BIT.B5 = 0U; //Active High
    PORT7.PMR.BIT.B5 = 0U;
    //Control Un (MTIOC4D)
    PORT7.PODR.BIT.B6 = 0U; //Active High
    PORT7.PMR.BIT.B6 = 0U;

    /* Disable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_UpdDuty
* Description  : This function updates duty cycle
* Arguments    : duty_u -
*                    U phase duty register value
*                duty_v -
*                    V phase duty register value
*                duty_w -
*                    W phase duty register value
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_UpdDuty(uint16_t duty_u, uint16_t duty_v, uint16_t duty_w)
{
    MTU4.TGRC = duty_v;
    MTU3.TGRD = duty_w;
    MTU4.TGRD = duty_u;
   // MTU3.TGRD =duty_u;
   // MTU4.TGRD =duty_w;


}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StartAD
* Description  : This function starts the AD conversiont
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StartAD(void)
{
    IR(S12AD, S12ADI) = 0U;
    IEN(S12AD, S12ADI) = 1U;
    S12AD.ADCSR.BIT.TRGE = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_StopAD
* Description  : This function stops the AD conversion
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_StopAD(void)
{
    S12AD.ADCSR.BIT.TRGE = 0U;
    S12AD.ADCSR.BIT.ADST = 0U;
    IEN(S12AD, S12ADI) = 0U;
    IR(S12AD, S12ADI) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_MOTOR_AdcGetConvVal
* Description  : This function gets conversion result
* Arguments    : mtr_ad_data -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_MOTOR_AdcGetConvVal( r_mtr_adc_tb *mtr_ad_data )
{
    mtr_ad_data->u2_iu_ad  = (uint16_t)(S12AD.ADDR0);
    mtr_ad_data->u2_iv_ad  =  0xFFFFU;
    mtr_ad_data->u2_iw_ad  = (uint16_t)(S12AD.ADDR2);
    mtr_ad_data->u2_vdc_ad  = (uint16_t)(S12AD.ADDR3);
    mtr_ad_data->u2_vphase_u_ad  =  0xFFFFU;
    mtr_ad_data->u2_vphase_v_ad  =  0xFFFFU;
    mtr_ad_data->u2_vphase_w_ad  =  0xFFFFU;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
