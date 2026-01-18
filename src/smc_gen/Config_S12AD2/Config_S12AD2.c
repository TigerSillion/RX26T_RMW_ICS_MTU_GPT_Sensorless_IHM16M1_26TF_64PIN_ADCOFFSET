/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_S12AD2.c
* Component Version: 2.5.0
* Device(s)        : R5F526TFCxFM
* Description      : This file implements device driver for Config_S12AD2.
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
#include "Config_S12AD2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Create
* Description  : This function initializes the S12AD2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Create(void)
{
    /* Cancel S12AD2 module stop state */
    MSTP(S12AD2) = 0U;

    /* Disable and clear interrupt flags of S12AD2 module */
    S12AD2.ADCSR.BIT.ADIE = 0U;
    S12AD2.ADCMPCR.BIT.CMPAIE = 0U;
    S12AD2.ADCMPCR.BIT.CMPBIE = 0U;

    /* Set S12AD2 control registers */
    S12AD2.ADCSR.WORD = _0000_AD_DBLTRIGGER_DISABLE | _0000_AD_SYNC_TRIGGER | _0200_AD_SYNCASYNCTRG_ENABLE | 
                        _0000_AD_SINGLE_SCAN_MODE;

    /* Set AD conversion start trigger sources */
    S12AD2.ADSTRGR.WORD = _0900_AD_TRSA_TRG4AN;
    S12AD2.ADADC.BYTE = _00_AD_1_TIME_CONVERSION | _00_AD_ADDITION_MODE;
    S12AD2.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;

    /* Set channels and sampling time */
    S12AD2.ADSSTR0 = _1B_AD2_SAMPLING_STATE_0;
    S12AD2.ADANSA0.WORD = _0001_AD_ANx00_USED;
    S12AD2.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_AUTO_SETTING_DISABLE | 
                        _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD2.ADELCCR.BYTE = _02_ALL_SCAN_COMPLETION;
    S12AD2.ADCSR.WORD |= _0000_AD_SCAN_END_INTERRUPT_DISABLE;

    /* Set compare control register */
    S12AD2.ADCMPCR.WORD = _0000_AD_WINDOWB_DISABLE | _0000_AD_WINDOWA_DISABLE | _0000_AD_WINDOWFUNCTION_DISABLE;

    /* Set AN200 pin */
    PORT5.PMR.BYTE &= 0xFBU;
    PORT5.PDR.BYTE &= 0xFBU;
    MPC.P52PFS.BYTE = 0x80U;

    R_Config_S12AD2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Start
* Description  : This function starts the AD2 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Start(void)
{
    S12AD2.ADCSR.BIT.TRGE = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Stop
* Description  : This function stops the AD2 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Stop(void)
{
    S12AD2.ADCSR.BIT.TRGE = 0U;
    S12AD2.ADCSR.BIT.ADST = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Get_ValueResult
* Description  : This function gets result from the AD2 converter
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (uint16_t)(S12AD2.ADRD.WORD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (uint16_t)(S12AD2.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (uint16_t)(S12AD2.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (uint16_t)(S12AD2.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (uint16_t)(S12AD2.ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            *buffer = (uint16_t)(S12AD2.ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            *buffer = (uint16_t)(S12AD2.ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            *buffer = (uint16_t)(S12AD2.ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            *buffer = (uint16_t)(S12AD2.ADDR7);
            break;
        }
        case ADCHANNEL8:
        {
            *buffer = (uint16_t)(S12AD2.ADDR8);
            break;
        }
        case ADCHANNEL9:
        {
            *buffer = (uint16_t)(S12AD2.ADDR9);
            break;
        }
        case ADCHANNEL10:
        {
            *buffer = (uint16_t)(S12AD2.ADDR10);
            break;
        }
        case ADCHANNEL11:
        {
            *buffer = (uint16_t)(S12AD2.ADDR11);
            break;
        }
        case ADCHANNEL16:
        {
            *buffer = (uint16_t)(S12AD2.ADDR16);
            break;
        }
        case ADCHANNEL17:
        {
            *buffer = (uint16_t)(S12AD2.ADDR17);
            break;
        }
        case ADTEMPSENSOR:
        {
            *buffer = (uint16_t)(S12AD2.ADTSDR);
            break;
        }
        case ADINTERREFVOLT:
        {
            *buffer = (uint16_t)(S12AD2.ADOCDR);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDRB);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDR);
            break;
        }
        default:
        {
            break;
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

