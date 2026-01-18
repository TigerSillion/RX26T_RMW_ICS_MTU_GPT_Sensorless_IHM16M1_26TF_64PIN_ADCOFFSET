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
* File Name   : r_app_control_cfg.h
* Description : Compile-time configurations
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version
*         : 05.08.2022 1.00
***********************************************************************************************************************/

/* Guard against multiple inclusion */
#ifndef R_APP_CONTROL_CFG_H
#define R_APP_CONTROL_CFG_H

/***********************************************************************************************************************
* Includes <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "r_app_main.h"

/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
/* Defines the UI used as default UI (MAIN_UI_BOARD/MAIN_UI_RMW)*/
#define  APP_CFG_USE_UI  (MAIN_UI_RMW)

/* design parameter */
#define     APP_CFG_FREQ_BAND_LIMIT     (3.0f)                       /* Motor control natural frequency limit */
#define     APP_CFG_MAX_CURRENT_OMEGA   (1000.0f)                    /* Max natural frequency of current loop [Hz] */
#define     APP_CFG_MIN_OMEGA           (1.0f)                       /* Min natural frequency of control loop [Hz] */

/* Select SCI port
 * 0x10 - SCI1  PD3/TXD1  PD5/RXD1
 * 0x50 - SCI5  PD7/TXD5  PE0/RXD5
 * 0x51 - SCI5  PB5/TXD5  PB6/RXD5
 * 0x60 - SCI6  P81/TXD6  P80/RXD6
 * 0x61 - SCI6  PB2/TXD6  PB1/RXD6
 * 0xC0 - SCI12 PD4/TXD12 PD6/RXD12
 * 0xC1 - SCI12 P01/TXD12 P00/RXD12
 * 0xC2 - SCI12 P81/TXD12 P80/RXD12
 * 0xC3 - SCI12 P23/TXD12 P22/RXD12
 * 0xC4 - SCI12 PB5/TXD12 PB6/RXD12
 */
#define APP_CFG_SCI_CH_SELECT     (0x61)

#endif /* R_APP_CONTROL_CFG_H */
