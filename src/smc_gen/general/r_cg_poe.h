/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_poe.h
* Version          : 1.0.100
* Device(s)        : R5F526TFCxFM
* Description      : General header file for POE peripheral.
***********************************************************************************************************************/

#ifndef POE_H
#define POE_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Input Level Control/Status Register 1 (ICSR1)
*/
/* POE0 Mode Select (POE0M) */
#define _0000_POE_POE0M_SEL_DEFAULT         (0x0000U) /* Accepts request on the falling or rising edge of POE0# input */
#define _0001_POE_POE0M_SEL_8               (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected */
#define _0002_POE_POE0M_SEL_16              (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE0M_SEL_128             (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE0M_SEL_0               (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE0M_SEL_2               (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE0M_SEL_4               (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE0 Sampling Count Select (POE0M2) */
#define _0000_POE_POE0M2_16TIMES            (0x0000U) /* 16 times */
#define _0010_POE_POE0M2_4TIMES             (0x0010U) /* 4 times */
#define _0020_POE_POE0M2_8TIMES             (0x0020U) /* 8 times */
#define _0030_POE_POE0M2_9TIMES             (0x0030U) /* 9 times */
#define _0040_POE_POE0M2_10TIMES            (0x0040U) /* 10 times */
#define _0050_POE_POE0M2_11TIMES            (0x0050U) /* 11 times */
#define _0060_POE_POE0M2_12TIMES            (0x0060U) /* 12 times */
#define _0070_POE_POE0M2_13TIMES            (0x0070U) /* 13 times */
#define _0080_POE_POE0M2_14TIMES            (0x0080U) /* 14 times */
#define _0090_POE_POE0M2_15TIMES            (0x0090U) /* 15 times */
/* Port Interrupt Enable 1 (PIE1) */
#define _0000_POE_PIE1_DISABLE              (0x0000U) /* OEI1 interrupt requests by input level detection disabled */
#define _0100_POE_PIE1_ENABLE               (0x0100U) /* OEI1 interrupt requests by input level detection enabled */
/* POE0# Pin Input Invert (INV) */
#define _0000_POE_POE0_INV_DISABLE          (0x0000U) /* Does not invert the input signal from POE0# pin  */
#define _8000_POE_POE0_INV_ENABLE           (0x8000U) /* Inverts the input signal from POE0# pin  */

/*
    Input Level Control/Status Register 2 (ICSR2)
*/
/* POE4 Mode Select (POE4M) */
#define _0000_POE_POE4M_SEL_DEFAULT         (0x0000U) /* Accepts request on the falling or rising edge of POE4# input */
#define _0001_POE_POE4M_SEL_8               (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE4M_SEL_16              (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE4M_SEL_128             (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE4M_SEL_0               (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE4M_SEL_2               (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE4M_SEL_4               (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE4 Sampling Count Select (POE4M2) */
#define _0000_POE_POE4M2_16TIMES            (0x0000U) /* 16 times */
#define _0010_POE_POE4M2_4TIMES             (0x0010U) /* 4 times */
#define _0020_POE_POE4M2_8TIMES             (0x0020U) /* 8 times */
#define _0030_POE_POE4M2_9TIMES             (0x0030U) /* 9 times */
#define _0040_POE_POE4M2_10TIMES            (0x0040U) /* 10 times */
#define _0050_POE_POE4M2_11TIMES            (0x0050U) /* 11 times */
#define _0060_POE_POE4M2_12TIMES            (0x0060U) /* 12 times */
#define _0070_POE_POE4M2_13TIMES            (0x0070U) /* 13 times */
#define _0080_POE_POE4M2_14TIMES            (0x0080U) /* 14 times */
#define _0090_POE_POE4M2_15TIMES            (0x0090U) /* 15 times */
/* Port Interrupt Enable 2 (PIE2) */
#define _0000_POE_PIE2_DISABLE              (0x0000U) /* OEI2 interrupt requests by input level detection disabled */
#define _0100_POE_PIE2_ENABLE               (0x0100U) /* OEI2 interrupt requests by input level detection enabled */
/* POE4# Pin Input Invert (INV) */
#define _0000_POE_POE4_INV_DISABLE          (0x0000U) /* Does not invert the input signal from POE4# pin  */
#define _8000_POE_POE4_INV_ENABLE           (0x8000U) /* Inverts the input signal from POE4# pin  */

/*
    Input Level Control/Status Register 3 (ICSR3)
*/
/* POE8 Mode Select (POE8M) */
#define _0000_POE_POE8M_SEL_DEFAULT         (0x0000U) /* Accepts request on the falling or rising edge of POE8# input */
#define _0001_POE_POE8M_SEL_8               (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE8M_SEL_16              (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE8M_SEL_128             (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE8M_SEL_0               (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE8M_SEL_2               (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE8M_SEL_4               (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE8 Sampling Count Select (POE8M2) */
#define _0000_POE_POE8M2_16TIMES            (0x0000U) /* 16 times */
#define _0010_POE_POE8M2_4TIMES             (0x0010U) /* 4 times */
#define _0020_POE_POE8M2_8TIMES             (0x0020U) /* 8 times */
#define _0030_POE_POE8M2_9TIMES             (0x0030U) /* 9 times */
#define _0040_POE_POE8M2_10TIMES            (0x0040U) /* 10 times */
#define _0050_POE_POE8M2_11TIMES            (0x0050U) /* 11 times */
#define _0060_POE_POE8M2_12TIMES            (0x0060U) /* 12 times */
#define _0070_POE_POE8M2_13TIMES            (0x0070U) /* 13 times */
#define _0080_POE_POE8M2_14TIMES            (0x0080U) /* 14 times */
#define _0090_POE_POE8M2_15TIMES            (0x0090U) /* 15 times */
/* Port Interrupt Enable 3 (PIE3) */
#define _0000_POE_PIE3_DISABLE              (0x0000U) /* OEI3 interrupt requests by input level detection disabled */
#define _0100_POE_PIE3_ENABLE               (0x0100U) /* OEI3 interrupt requests by input level detection enabled */
/* POE8 High-Impedance Enable (POE8E) */
#define _0000_POE_POE8E_DISABLE             (0x0000U) /* Not places the POE8 pin in high-impedance state */
#define _0200_POE_POE8E_ENABLE              (0x0200U) /* Places the POE8 pin in high-impedance state */
/* POE8# Pin Input Invert (INV) */
#define _0000_POE_POE8_INV_DISABLE          (0x0000U) /* Does not invert the input signal from POE8# pin */
#define _8000_POE_POE8_INV_ENABLE           (0x8000U) /* Inverts the input signal from POE8# pin  */

/*
    Input Level Control/Status Register 4 (ICSR4)
*/
/* POE10 Mode Select (POE10M) */
#define _0000_POE_POE10M_SEL_DEFAULT        (0x0000U) /* Accepts request on the falling
                                                         or rising edge of POE10# input */
#define _0001_POE_POE10M_SEL_8              (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE10M_SEL_16             (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE10M_SEL_128            (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE10M_SEL_0              (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE10M_SEL_2              (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE10M_SEL_4              (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE10 Sampling Count Select (POE10M2) */
#define _0000_POE_POE10M2_16TIMES           (0x0000U) /* 16 times */
#define _0010_POE_POE10M2_4TIMES            (0x0010U) /* 4 times */
#define _0020_POE_POE10M2_8TIMES            (0x0020U) /* 8 times */
#define _0030_POE_POE10M2_9TIMES            (0x0030U) /* 9 times */
#define _0040_POE_POE10M2_10TIMES           (0x0040U) /* 10 times */
#define _0050_POE_POE10M2_11TIMES           (0x0050U) /* 11 times */
#define _0060_POE_POE10M2_12TIMES           (0x0060U) /* 12 times */
#define _0070_POE_POE10M2_13TIMES           (0x0070U) /* 13 times */
#define _0080_POE_POE10M2_14TIMES           (0x0080U) /* 14 times */
#define _0090_POE_POE10M2_15TIMES           (0x0090U) /* 15 times */
/* Port Interrupt Enable 4 (PIE4) */
#define _0000_POE_PIE4_DISABLE              (0x0000U) /* OEI4 interrupt requests by input level detection disabled */
#define _0100_POE_PIE4_ENABLE               (0x0100U) /* OEI4 interrupt requests by input level detection enabled */
/* POE10 High-Impedance Enable (POE10E) */
#define _0000_POE_POE10E_DISABLE            (0x0000U) /* Not places the POE10 pin in high-impedance state */
#define _0200_POE_POE10E_ENABLE             (0x0200U) /* Places the POE10 pin in high-impedance state */
/* POE10# Pin Input Invert (INV) */
#define _0000_POE_POE10_INV_DISABLE         (0x0000U) /* Does not invert the input signal from POE10# pin */
#define _8000_POE_POE10_INV_ENABLE          (0x8000U) /* Inverts the input signal from POE10# pin  */

/*
    Input Level Control/Status Register 5 (ICSR5)
*/
/* POE11 Mode Select (POE11M) */
#define _0000_POE_POE11M_SEL_DEFAULT        (0x0000U) /* Accepts request on the falling
                                                         or rising edge of POE11# input */
#define _0001_POE_POE11M_SEL_8              (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE11M_SEL_16             (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE11M_SEL_128            (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE11M_SEL_0              (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE11M_SEL_2              (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE11M_SEL_4              (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE11 Sampling Count Select (POE11M2) */
#define _0000_POE_POE11M2_16TIMES           (0x0000U) /* 16 times */
#define _0010_POE_POE11M2_4TIMES            (0x0010U) /* 4 times */
#define _0020_POE_POE11M2_8TIMES            (0x0020U) /* 8 times */
#define _0030_POE_POE11M2_9TIMES            (0x0030U) /* 9 times */
#define _0040_POE_POE11M2_10TIMES           (0x0040U) /* 10 times */
#define _0050_POE_POE11M2_11TIMES           (0x0050U) /* 11 times */
#define _0060_POE_POE11M2_12TIMES           (0x0060U) /* 12 times */
#define _0070_POE_POE11M2_13TIMES           (0x0070U) /* 13 times */
#define _0080_POE_POE11M2_14TIMES           (0x0080U) /* 14 times */
#define _0090_POE_POE11M2_15TIMES           (0x0090U) /* 15 times */
/* Port Interrupt Enable 5 (PIE5) */
#define _0000_POE_PIE5_DISABLE              (0x0000U) /* OEI5 interrupt requests by input level detection disabled */
#define _0100_POE_PIE5_ENABLE               (0x0100U) /* OEI5 interrupt requests by input level detection enabled */
/* POE11 High-Impedance Enable (POE11E) */
#define _0000_POE_POE11E_DISABLE            (0x0000U) /* Not places the POE11 pin in high-impedance state */
#define _0200_POE_POE11E_ENABLE             (0x0200U) /* Places the POE11 pin in high-impedance state */
/* POE11# Pin Input Invert (INV) */
#define _0000_POE_POE11_INV_DISABLE         (0x0000U) /* Does not invert the input signal from POE11# pin */
#define _8000_POE_POE11_INV_ENABLE          (0x8000U) /* Inverts the input signal from POE11# pin  */

/*
    Input Level Control/Status Register 6 (ICSR6)
*/
/* OSTST High-Impedance Enable (OSTSTE) */
#define _0000_POE_OSTSTE_DISABLE            (0x0000U) /* MTU0 / MTU9 and complementary PWM output pins
                                                         or GPT pins high impedance are disabled */
#define _0200_POE_OSTSTE_ENABLE             (0x0200U) /* MTU0 / MTU9 and complementary PWM output pins
                                                         or GPT pins high impedance are enabled */

/*
    Input Level Control/Status Register 7 (ICSR7)
*/
/* POE12 Mode Select (POE12M) */
#define _0000_POE_POE12M_SEL_DEFAULT        (0x0000U) /* Accepts request on the falling
                                                         or rising edge of POE12# input */
#define _0001_POE_POE12M_SEL_8              (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE12M_SEL_16             (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE12M_SEL_128            (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE12M_SEL_0              (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE12M_SEL_2              (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE12M_SEL_4              (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE12 Sampling Count Select (POE12M2) */
#define _0000_POE_POE12M2_16TIMES           (0x0000U) /* 16 times */
#define _0010_POE_POE12M2_4TIMES            (0x0010U) /* 4 times */
#define _0020_POE_POE12M2_8TIMES            (0x0020U) /* 8 times */
#define _0030_POE_POE12M2_9TIMES            (0x0030U) /* 9 times */
#define _0040_POE_POE12M2_10TIMES           (0x0040U) /* 10 times */
#define _0050_POE_POE12M2_11TIMES           (0x0050U) /* 11 times */
#define _0060_POE_POE12M2_12TIMES           (0x0060U) /* 12 times */
#define _0070_POE_POE12M2_13TIMES           (0x0070U) /* 13 times */
#define _0080_POE_POE12M2_14TIMES           (0x0080U) /* 14 times */
#define _0090_POE_POE12M2_15TIMES           (0x0090U) /* 15 times */
/* Port Interrupt Enable 7 (PIE7) */
#define _0000_POE_PIE7_DISABLE              (0x0000U) /* OEI7 interrupt requests by input level detection disabled */
#define _0100_POE_PIE7_ENABLE               (0x0100U) /* OEI7 interrupt requests by input level detection enabled */
/* POE12 High-Impedance Enable (POE12E) */
#define _0000_POE_POE12E_DISABLE            (0x0000U) /* Not places the POE12 pin in high-impedance state */
#define _0200_POE_POE12E_ENABLE             (0x0200U) /* Places the POE12 pin in high-impedance state */
/* POE12# Pin Input Invert (INV) */
#define _0000_POE_POE12_INV_DISABLE         (0x0000U) /* Does not invert the input signal from POE12# pin */
#define _8000_POE_POE12_INV_ENABLE          (0x8000U) /* Inverts the input signal from POE12# pin  */

/*
    Input Level Control/Status Register 8 (ICSR8)
*/
/* POE9 Mode Select (POE9M) */
#define _0000_POE_POE9M_SEL_DEFAULT         (0x0000U) /* Accepts request on the falling or rising edge of POE9# input */
#define _0001_POE_POE9M_SEL_8               (0x0001U) /* Accepts request when sampled at PCLK/8
                                                         and low or high level is detected*/
#define _0002_POE_POE9M_SEL_16              (0x0002U) /* Accepts request when sampled at PCLK/16
                                                         and low or high level is detected */
#define _0003_POE_POE9M_SEL_128             (0x0003U) /* Accepts request when sampled at PCLK/128
                                                         and low or high level is detected */
#define _0004_POE_POE9M_SEL_0               (0x0004U) /* Accepts request when sampled at PCLK
                                                         and low or high level is detected */
#define _0005_POE_POE9M_SEL_2               (0x0005U) /* Accepts request when sampled at PCLK/2
                                                         and low or high level is detected */
#define _0006_POE_POE9M_SEL_4               (0x0006U) /* Accepts request when sampled at PCLK/4
                                                         and low or high level is detected */
/* POE9 Sampling Count Select (POE9M2) */
#define _0000_POE_POE9M2_16TIMES            (0x0000U) /* 16 times */
#define _0010_POE_POE9M2_4TIMES             (0x0010U) /* 4 times */
#define _0020_POE_POE9M2_8TIMES             (0x0020U) /* 8 times */
#define _0030_POE_POE9M2_9TIMES             (0x0030U) /* 9 times */
#define _0040_POE_POE9M2_10TIMES            (0x0040U) /* 10 times */
#define _0050_POE_POE9M2_11TIMES            (0x0050U) /* 11 times */
#define _0060_POE_POE9M2_12TIMES            (0x0060U) /* 12 times */
#define _0070_POE_POE9M2_13TIMES            (0x0070U) /* 13 times */
#define _0080_POE_POE9M2_14TIMES            (0x0080U) /* 14 times */
#define _0090_POE_POE9M2_15TIMES            (0x0090U) /* 15 times */
/* Port Interrupt Enable 8 (PIE8) */
#define _0000_POE_PIE8_DISABLE              (0x0000U) /* OEI8 interrupt requests by input level detection disabled */
#define _0100_POE_PIE8_ENABLE               (0x0100U) /* OEI8 interrupt requests by input level detection enabled */
/* POE9 High-Impedance Enable (POE9E) */
#define _0000_POE_POE9E_DISABLE             (0x0000U) /* Not places the POE9 pin in high-impedance state */
#define _0200_POE_POE9E_ENABLE              (0x0200U) /* Places the POE9 pin in high-impedance state */
/* POE9# Pin Input Invert (INV) */
#define _0000_POE_POE9_INV_DISABLE          (0x0000U) /* Does not invert the input signal from POE9# pin */
#define _8000_POE_POE9_INV_ENABLE           (0x8000U) /* Inverts the input signal from POE9# pin */

/*
    Output Level Control/Status Register 1 (OCSR1)
*/
/* Output Short Interrupt Enable 1 (OIE1) */
#define _0000_POE_OIE1_DISABLE              (0x0000U) /* OEI1 interrupt requests by output level comparison disabled */
#define _0100_POE_OIE1_ENABLE               (0x0100U) /* OEI1 interrupt requests by output level comparison enabled */
/* Output Short High-Impedance Enable 1 (OCE1) */
#define _0000_POE_OCE1_DISABLE              (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_OCE1_ENABLE               (0x0200U) /* Places the pins in high-impedance */

/*
    Output Level Control/Status Register 2 (OCSR2)
*/
/* Output Short Interrupt Enable 2 (OIE2) */
#define _0000_POE_OIE2_DISABLE              (0x0000U) /* OEI2 interrupt requests by output level comparison disabled */
#define _0100_POE_OIE2_ENABLE               (0x0100U) /* OEI2 interrupt requests by output level comparison enabled */
/* Output Short High-Impedance Enable 2 (OCE2) */
#define _0000_POE_OCE2_DISABLE              (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_OCE2_ENABLE               (0x0200U) /* Places the pins in high-impedance */

/*
    Output Level Control/Status Register 3 (OCSR3)
*/
/* Output Short Interrupt Enable 3 (OIE3) */
#define _0000_POE_OIE3_DISABLE              (0x0000U) /* OEI3 interrupt requests by output level comparison disabled */
#define _0100_POE_OIE3_ENABLE               (0x0100U) /* OEI3 interrupt requests by output level comparison enabled */
/* Output Short High-Impedance Enable 3 (OCE3) */
#define _0000_POE_OCE3_DISABLE              (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_OCE3_ENABLE               (0x0200U) /* Places the pins in high-impedance */

/*
    Output Level Control/Status Register 4 (OCSR4)
*/
/* Output Short Interrupt Enable 4 (OIE4) */
#define _0000_POE_OIE4_DISABLE              (0x0000U) /* OEI4 interrupt requests by output level comparison disabled */
#define _0100_POE_OIE4_ENABLE               (0x0100U) /* OEI4 interrupt requests by output level comparison enabled */
/* Output Short High-Impedance Enable 4 (OCE4) */
#define _0000_POE_OCE4_DISABLE              (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_OCE4_ENABLE               (0x0200U) /* Places the pins in high-impedance */

/*
    Output Level Control/Status Register 5 (OCSR5)
*/
/* Output Short Interrupt Enable 5 (OIE5) */
#define _0000_POE_OIE5_DISABLE              (0x0000U) /* OEI5 interrupt requests by output level comparison disabled */
#define _0100_POE_OIE5_ENABLE               (0x0100U) /* OEI5 interrupt requests by output level comparison enabled */
/* Output Short High-Impedance Enable 5 (OCE5) */
#define _0000_POE_OCE5_DISABLE              (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_OCE5_ENABLE               (0x0200U) /* Places the pins in high-impedance */

/*
    Active Level Setting Register 1 (ALR1)
*/
/* MTIOC3B Active Level Setting (OLSG0A) */
#define _0000_POE_MTIOC3B_LOW               (0x0000U) /* MTIOC3B active level low */
#define _0001_POE_MTIOC3B_HIGH              (0x0001U) /* MTIOC3B active level high */
/* MTIOC3D Active Level Setting (OLSG0B) */
#define _0000_POE_MTIOC3D_LOW               (0x0000U) /* MTIOC3D active level low */
#define _0002_POE_MTIOC3D_HIGH              (0x0002U) /* MTIOC3D active level high */
/* MTIOC4A Active Level Setting (OLSG1A) */
#define _0000_POE_MTIOC4A_LOW               (0x0000U) /* MTIOC4A active level low */
#define _0004_POE_MTIOC4A_HIGH              (0x0004U) /* MTIOC4A active level high */
/* MTIOC4C Active Level Setting (OLSG1B) */
#define _0000_POE_MTIOC4C_LOW               (0x0000U) /* MTIOC4C active level low */
#define _0008_POE_MTIOC4C_HIGH              (0x0008U) /* MTIOC4C active level high */
/* MTIOC4B Active Level Setting (OLSG2A) */
#define _0000_POE_MTIOC4B_LOW               (0x0000U) /* MTIOC4B active level low */
#define _0010_POE_MTIOC4B_HIGH              (0x0010U) /* MTIOC4B active level high */
/* MTIOC4D Active Level Setting (OLSG2B) */
#define _0000_POE_MTIOC4D_LOW               (0x0000U) /* MTIOC4D active level low */
#define _0020_POE_MTIOC4D_HIGH              (0x0020U) /* MTIOC4D active level high */
/* Active Level Setting Enable (OLSEN) */
#define _0000_POE_MTU34_ACTLEL_DISABLE      (0x0000U) /* Active level disable */
#define _0080_POE_MTU34_ACTLEL_ENABLE       (0x0080U) /* Active level enable */

/*
    Active Level Setting Register 2 (ALR2)
*/
/* MTIOC6B Active Level Setting (OLSG4A) */
#define _0000_POE_MTIOC6B_LOW               (0x0000U) /* MTIOC6B active level low */
#define _0001_POE_MTIOC6B_HIGH              (0x0001U) /* MTIOC6B active level high */
/* MTIOC6D Active Level Setting (OLSG4B) */
#define _0000_POE_MTIOC6D_LOW               (0x0000U) /* MTIOC6D active level low */
#define _0002_POE_MTIOC6D_HIGH              (0x0002U) /* MTIOC6D active level high */
/* MTIOC7A Active Level Setting (OLSG5A) */ 
#define _0000_POE_MTIOC7A_LOW               (0x0000U) /* MTIOC7A active level low */
#define _0004_POE_MTIOC7A_HIGH              (0x0004U) /* MTIOC7A active level high */
/* MTIOC7C Active Level Setting (OLSG5B) */
#define _0000_POE_MTIOC7C_LOW               (0x0000U) /* MTIOC7C active level low */
#define _0008_POE_MTIOC7C_HIGH              (0x0008U) /* MTIOC7C active level high */
/* MTIOC7B Active Level Setting (OLSG6A) */
#define _0000_POE_MTIOC7B_LOW               (0x0000U) /* MTIOC7B active level low */
#define _0010_POE_MTIOC7B_HIGH              (0x0010U) /* MTIOC7B active level high */
/* MTIOC7D Active Level Setting (OLSG6B) */
#define _0000_POE_MTIOC7D_LOW               (0x0000U) /* MTIOC7D active level low */
#define _0020_POE_MTIOC7D_HIGH              (0x0020U) /* MTIOC7D active level high */
/* Active Level Setting Enable (OLSEN) */
#define _0000_POE_MTU67_ACTLEL_DISABLE      (0x0000U) /* Active level disable */
#define _0080_POE_MTU67_ACTLEL_ENABLE       (0x0080U) /* Active level enable */

/*
    Active Level Setting Register 3 (ALR3)
*/
/* GTIOC0A Active Level Setting (OLSG0A) */
#define _0000_POE_GTIOC0A_LOW               (0x0000U) /* GTIOC0A active level low */
#define _0001_POE_GTIOC0A_HIGH              (0x0001U) /* GTIOC0A active level high */
/* GTIOC0B Active Level Setting (OLSG0B) */
#define _0000_POE_GTIOC0B_LOW               (0x0000U) /* GTIOC0B active level low */
#define _0002_POE_GTIOC0B_HIGH              (0x0002U) /* GTIOC0B active level high */
/* GTIOC1A Active Level Setting (OLSG1A) */
#define _0000_POE_GTIOC1A_LOW               (0x0000U) /* GTIOC1A active level low */
#define _0004_POE_GTIOC1A_HIGH              (0x0004U) /* GTIOC1A active level high */
/* GTIOC1B Active Level Setting (OLSG1B) */
#define _0000_POE_GTIOC1B_LOW               (0x0000U) /* GTIOC1B active level low */
#define _0008_POE_GTIOC1B_HIGH              (0x0008U) /* GTIOC1B active level high */
/* GTIOC2A Active Level Setting (OLSG2A) */
#define _0000_POE_GTIOC2A_LOW               (0x0000U) /* GTIOC2A active level low */
#define _0010_POE_GTIOC2A_HIGH              (0x0010U) /* GTIOC2A active level high */
/* GTIOC2B Active Level Setting (OLSG2B) */
#define _0000_POE_GTIOC2B_LOW               (0x0000U) /* GTIOC2B active level low */
#define _0020_POE_GTIOC2B_HIGH              (0x0020U) /* GTIOC2B active level high */
/* Active Level Setting Enable (OLSEN) */
#define _0000_POE_GPT012_ACTLEL_DISABLE     (0x0000U) /* Active level disable */
#define _0080_POE_GPT012_ACTLEL_ENABLE      (0x0080U) /* Active level enable */

/*
    Active Level Setting Register 4 (ALR4)
*/
/* GTIOC4A Active Level Setting (OLSG0A) */
#define _0000_POE_GTIOC4A_LOW               (0x0000U) /* GTIOC4A active level low */
#define _0001_POE_GTIOC4A_HIGH              (0x0001U) /* GTIOC4A active level high */
/* GTIOC4B Active Level Setting (OLSG0B) */
#define _0000_POE_GTIOC4B_LOW               (0x0000U) /* GTIOC4B active level low */
#define _0002_POE_GTIOC4B_HIGH              (0x0002U) /* GTIOC4B active level high */
/* GTIOC5A Active Level Setting (OLSG1A) */
#define _0000_POE_GTIOC5A_LOW               (0x0000U) /* GTIOC5A active level low */
#define _0004_POE_GTIOC5A_HIGH              (0x0004U) /* GTIOC5A active level high */
/* GTIOC5B Active Level Setting (OLSG1B) */
#define _0000_POE_GTIOC5B_LOW               (0x0000U) /* GTIOC5B active level low */
#define _0008_POE_GTIOC5B_HIGH              (0x0008U) /* GTIOC5B active level high */
/* GTIOC6A Active Level Setting (OLSG2A) */
#define _0000_POE_GTIOC6A_LOW               (0x0000U) /* GTIOC6A active level low */
#define _0010_POE_GTIOC6A_HIGH              (0x0010U) /* GTIOC6A active level high */
/* GTIOC6B Active Level Setting (OLSG2B) */
#define _0000_POE_GTIOC6B_LOW               (0x0000U) /* GTIOC6B active level low */
#define _0020_POE_GTIOC6B_HIGH              (0x0020U) /* GTIOC6B active level high */
/* Active Level Setting Enable (OLSEN) */
#define _0000_POE_GPT456_ACTLEL_DISABLE     (0x0000U) /* Active level disable */
#define _0080_POE_GPT456_ACTLEL_ENABLE      (0x0080U) /* Active level enable */

/*
    Active Level Setting Register 5 (ALR5)
*/
/* GTIOC7A Active Level Setting (OLSG0A) */
#define _0000_POE_GTIOC7A_LOW               (0x0000U) /* GTIOC7A active level low */
#define _0001_POE_GTIOC7A_HIGH              (0x0001U) /* GTIOC7A active level high */
/* GTIOC7B Active Level Setting (OLSG0B) */
#define _0000_POE_GTIOC7B_LOW               (0x0000U) /* GTIOC7B active level low */
#define _0002_POE_GTIOC7B_HIGH              (0x0002U) /* GTIOC7B active level high */
/* Active Level Setting Enable (OLSEN) */
#define _0000_POE_GPT789_ACTLEL_DISABLE     (0x0000U) /* Active level disable */
#define _0080_POE_GPT789_ACTLEL_ENABLE      (0x0080U) /* Active level enable */

/*
    Software Port Output Enable Register (SPOER)
*/
/* MTU3 and MTU4 Output High-Impedance Enable (MTUCH34HIZ) */
#define _0000_POE_MTU34HIZ_DISABLE          (0x0000U) /* Does not place the pins in high-impedance */
#define _0001_POE_MTU34HIZ_ENABLE           (0x0001U) /* Places the pins in high-impedance */
/* MTU6 and MTU7 Output High-Impedance Enable (MTUCH67HIZ) */
#define _0000_POE_MTU67HIZ_DISABLE          (0x0000U) /* Does not place the pins in high-impedance */
#define _0002_POE_MTU67HIZ_ENABLE           (0x0002U) /* Places the pins in high-impedance */
/* MTU0 Output High-Impedance Enable (MTUCH0HIZ) */
#define _0000_POE_MTU0HIZ_DISABLE           (0x0000U) /* Does not place the pins in high-impedance */
#define _0004_POE_MTU0HIZ_ENABLE            (0x0004U) /* Places the pins in high-impedance */
/* GPT0 and GPT1 Output High-Impedance Enable (GPT01HIZ) */
#define _0000_POE_GPT01HIZ_DISABLE          (0x0000U) /* Does not place the pins in high-impedance */
#define _0008_POE_GPT01HIZ_ENABLE           (0x0008U) /* Places the pins in high-impedance */
/* GPT2 and GPT3 Output High-Impedance Enable (GPT23HIZ) */
#define _0000_POE_GPT23HIZ_DISABLE          (0x0000U) /* Does not place the pins in high-impedance */
#define _0010_POE_GPT23HIZ_ENABLE           (0x0010U) /* Places the pins in high-impedance */
/* MTU9 Output High-Impedance Enable (MTUCH9HIZ) */
#define _0000_POE_MTU9HIZ_DISABLE           (0x0000U) /* Does not place the pins in high-impedance */
#define _0040_POE_MTU9HIZ_ENABLE            (0x0040U) /* Places the pins in high-impedance */
/* GPT0 to GPT2 Output High-Impedance Enable (GPT02HIZ) */
#define _0000_POE_GPT012HIZ_DISABLE         (0x0000U) /* Does not place the pins in high-impedance */
#define _0100_POE_GPT012HIZ_ENABLE          (0x0100U) /* Places the pins in high-impedance */
/* GPT4 to GPT6 Output High-Impedance Enable (GPT46HIZ) */
#define _0000_POE_GPT456HIZ_DISABLE         (0x0000U) /* Does not place the pins in high-impedance */
#define _0200_POE_GPT456HIZ_ENABLE          (0x0200U) /* Places the pins in high-impedance */
/* GPT7 Output High-Impedance Enable (GPT79HIZ) */
#define _0000_POE_GPT789HIZ_DISABLE         (0x0000U) /* Does not place the pins in high-impedance */
#define _0400_POE_GPT789HIZ_ENABLE          (0x0400U) /* Places the pins in high-impedance */

/*
    Port Output Enable Control Register 1 (POECR1)
*/
/* MTIOC0A High-Impedance Enable (MTU0AZE) */
#define _00_POE_MTU0AZE_DISABLE             (0x00U) /* Does not place the pin in high-impedance */
#define _01_POE_MTU0AZE_ENABLE              (0x01U) /* Places the pin in high-impedance */
/* MTIOC0B High-Impedance Enable (MTU0BZE) */
#define _00_POE_MTU0BZE_DISABLE             (0x00U) /* Does not place the pin in high-impedance */
#define _02_POE_MTU0BZE_ENABLE              (0x02U) /* Places the pin in high-impedance */
/* MTIOC0C High-Impedance Enable (MTU0CZE) */
#define _00_POE_MTU0CZE_DISABLE             (0x00U) /* Does not place the pin in high-impedance */
#define _04_POE_MTU0CZE_ENABLE              (0x04U) /* Places the pin in high-impedance */
/* MTIOC0D High-Impedance Enable (MTU0DZE) */
#define _00_POE_MTU0DZE_DISABLE             (0x00U) /* Does not place the pin in high-impedance */
#define _08_POE_MTU0DZE_ENABLE              (0x08U) /* Places the pin in high-impedance */

/*
    Port Output Enable Control Register 2 (POECR2)
*/
/* MTIOC7B/7D High-Impedance Enable (MTU7BDZE) */
#define _0000_POE_MTU7BDZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0001_POE_MTU7BDZE_ENABLE           (0x0001U) /* Places the pin in high-impedance */
/* MTIOC7A/7C High-Impedance Enable (MTU7ACZE) */
#define _0000_POE_MTU7ACZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0002_POE_MTU7ACZE_ENABLE           (0x0002U) /* Places the pin in high-impedance */
/* MTIOC6B/6D High-Impedance Enable (MTU6BDZE) */
#define _0000_POE_MTU6BDZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0004_POE_MTU6BDZE_ENABLE           (0x0004U) /* Places the pin in high-impedance */
/* MTIOC4B/4D High-Impedance Enable (MTU4BDZE) */
#define _0000_POE_MTU4BDZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0100_POE_MTU4BDZE_ENABLE           (0x0100U) /* Places the pin in high-impedance */
/* MTIOC4A/4C High-Impedance Enable (MTU4ACZE) */
#define _0000_POE_MTU4ACZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0200_POE_MTU4ACZE_ENABLE           (0x0200U) /* Places the pin in high-impedance */
/* MTIOC3B/3D High-Impedance Enable (MTU3BDZE) */
#define _0000_POE_MTU3BDZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0400_POE_MTU3BDZE_ENABLE           (0x0400U) /* Places the pin in high-impedance */
#define _0000_POE_POECR2_CLEAR              (0x0000U) /* POECR2 clear default value */

/*
    Port Output Enable Control Register 3 (POECR3)
*/
/* GTIOC0A/0B High-Impedance Enable (GPT0ABZE) */
#define _0000_POE_GPT0ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0001_POE_GPT0ABZE_ENABLE           (0x0001U) /* Places the pin in high-impedance */
/* GTIOC1A/1B High-Impedance Enable (GPT1ABZE) */
#define _0000_POE_GPT1ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0002_POE_GPT1ABZE_ENABLE           (0x0002U) /* Places the pin in high-impedance */
/* GTIOC2A/2B High-Impedance Enable (GPT2ABZE) */
#define _0000_POE_GPT2ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0004_POE_GPT2ABZE_ENABLE           (0x0004U) /* Places the pin in high-impedance */
/* GTIOC3A/3B High-Impedance Enable (GPT3ABZE) */
#define _0000_POE_GPT3ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0008_POE_GPT3ABZE_ENABLE           (0x0008U) /* Places the pin in high-impedance */
/* GTIOC4A/4B High-Impedance Enable (GPT4ABZE) */
#define _0000_POE_GPT4ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0010_POE_GPT4ABZE_ENABLE           (0x0010U) /* Places the pin in high-impedance */
/* GTIOC5A/5B High-Impedance Enable (GPT5ABZE) */
#define _0000_POE_GPT5ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0020_POE_GPT5ABZE_ENABLE           (0x0020U) /* Places the pin in high-impedance */
/* GTIOC6A/6B High-Impedance Enable (GPT6ABZE) */
#define _0000_POE_GPT6ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0040_POE_GPT6ABZE_ENABLE           (0x0040U) /* Places the pin in high-impedance */
/* GTIOC7A/7B High-Impedance Enable (GPT7ABZE) */
#define _0000_POE_GPT7ABZE_DISABLE          (0x0000U) /* Does not place the pin in high-impedance */
#define _0080_POE_GPT7ABZE_ENABLE           (0x0080U) /* Places the pin in high-impedance */

/*
    Port Output Enable Control Register 4 (POECR4)
*/
/* MTU3 and MTU4 Output Disabling Condition CFLAG Add (CMADDMT34ZE) */
#define _0000_POE_CMADDMT34ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDMT34ZE_ENABLE        (0x0001U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE0F Add (IC1ADDMT34ZE) */
#define _0000_POE_IC1ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDMT34ZE_ENABLE       (0x0002U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE4F Add (IC2ADDMT34ZE) */
#define _0000_POE_IC2ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDMT34ZE_ENABLE       (0x0004U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE8F Add (IC3ADDMT34ZE) */
#define _0000_POE_IC3ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDMT34ZE_ENABLE       (0x0008U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE10F Add (IC4ADDMT34ZE) */
#define _0000_POE_IC4ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDMT34ZE_ENABLE       (0x0010U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE11F Add (IC5ADDMT34ZE) */
#define _0000_POE_IC5ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDMT34ZE_ENABLE       (0x0020U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE12F Add (IC6ADDMT34ZE) */
#define _0000_POE_IC6ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDMT34ZE_ENABLE       (0x0040U) /* Add the pins to high-impedance control conditions */
/* MTU3 and MTU4 High-Impedance POE9F Add (IC8ADDMT34ZE) */
#define _0000_POE_IC8ADDMT34ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDMT34ZE_ENABLE       (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 4B (POECR4B)
*/
/* MTU6 and MTU7 Output Disabling Condition CFLAG Add (CMADDMT67ZE) */
#define _0000_POE_CMADDMT67ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDMT67ZE_ENABLE        (0x0001U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE0F Add (IC1ADDMT67ZE) */
#define _0000_POE_IC1ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDMT67ZE_ENABLE       (0x0002U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE4F Add (IC2ADDMT67ZE) */
#define _0000_POE_IC2ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDMT67ZE_ENABLE       (0x0004U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE8F Add (IC3ADDMT67ZE) */
#define _0000_POE_IC3ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDMT67ZE_ENABLE       (0x0008U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE10F Add (IC4ADDMT67ZE) */
#define _0000_POE_IC4ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDMT67ZE_ENABLE       (0x0010U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE11F Add (IC5ADDMT67ZE) */
#define _0000_POE_IC5ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDMT67ZE_ENABLE       (0x0020U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE12F Add (IC6ADDMT67ZE) */
#define _0000_POE_IC6ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDMT67ZE_ENABLE       (0x0040U) /* Add the pins to high-impedance control conditions */
/* MTU6 and MTU7 High-Impedance POE9F Add (IC8ADDMT67ZE) */
#define _0000_POE_IC8ADDMT67ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDMT67ZE_ENABLE       (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 5 (POECR5)
*/
/* MTU0 Output Disabling Condition CFLAG Add (CMADDMT0ZE) */
#define _0000_POE_CMADDMT0ZE_DISABLE        (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDMT0ZE_ENABLE         (0x0001U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE0F Add (IC1ADDMT0ZE) */
#define _0000_POE_IC1ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDMT0ZE_ENABLE        (0x0002U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE4F Add (IC2ADDMT0ZE) */
#define _0000_POE_IC2ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDMT0ZE_ENABLE        (0x0004U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE8F Add (IC3ADDMT0ZE) */
#define _0000_POE_IC3ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDMT0ZE_ENABLE        (0x0008U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE10F Add (IC4ADDMT0ZE) */
#define _0000_POE_IC4ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDMT0ZE_ENABLE        (0x0010U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE11F Add (IC5ADDMT0ZE) */
#define _0000_POE_IC5ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDMT0ZE_ENABLE        (0x0020U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE12F Add (IC6ADDMT0ZE) */
#define _0000_POE_IC6ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDMT0ZE_ENABLE        (0x0040U) /* Add the pins to high-impedance control conditions */
/* MTU0 High-Impedance POE9F Add (IC8ADDMT0ZE) */
#define _0000_POE_IC8ADDMT0ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDMT0ZE_ENABLE        (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 6 (POECR6)
*/
/* GPT0 and GPT1 Output Disabling Condition CFLAG Add (CMADDGPT01ZE) */
#define _0000_POE_CMADDGPT01ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDGPT01ZE_ENABLE       (0x0001U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE0F Add (IC1ADDGPT01ZE) */
#define _0000_POE_IC1ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDGPT01ZE_ENABLE      (0x0002U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE4F Add (IC2ADDGPT01ZE) */
#define _0000_POE_IC2ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDGPT01ZE_ENABLE      (0x0004U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE8F Add (IC3ADDGPT01ZE) */
#define _0000_POE_IC3ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDGPT01ZE_ENABLE      (0x0008U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE10F Add (IC4ADDGPT01ZE) */
#define _0000_POE_IC4ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDGPT01ZE_ENABLE      (0x0010U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE11F Add (IC5ADDGPT01ZE) */
#define _0000_POE_IC5ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDGPT01ZE_ENABLE      (0x0020U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE12F Add (IC6ADDGPT01ZE) */
#define _0000_POE_IC6ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDGPT01ZE_ENABLE      (0x0040U) /* Add the pins to high-impedance control conditions */
/* GPT0 and GPT1 High-Impedance POE9F Add (IC8ADDGPT01ZE) */
#define _0000_POE_IC8ADDGPT01ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDGPT01ZE_ENABLE      (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 6B (POECR6B)
*/
/* GPT2 and GPT3 Output Disabling Condition CFLAG Add (CMADDGPT23ZE) */
#define _0000_POE_CMADDGPT23ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDGPT23ZE_ENABLE       (0x0001U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE0F Add (IC1ADDGPT23ZE) */
#define _0000_POE_IC1ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDGPT23ZE_ENABLE      (0x0002U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE4F Add (IC2ADDGPT23ZE) */
#define _0000_POE_IC2ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDGPT23ZE_ENABLE      (0x0004U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE8F Add (IC3ADDGPT23ZE) */
#define _0000_POE_IC3ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDGPT23ZE_ENABLE      (0x0008U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE10F Add (IC4ADDGPT23ZE) */
#define _0000_POE_IC4ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDGPT23ZE_ENABLE      (0x0010U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE11F Add (IC5ADDGPT23ZE) */
#define _0000_POE_IC5ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDGPT23ZE_ENABLE      (0x0020U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE12F Add (IC6ADDGPT23ZE) */
#define _0000_POE_IC6ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDGPT23ZE_ENABLE      (0x0040U) /* Add the pins to high-impedance control conditions */
/* GPT2 and GPT3 High-Impedance POE9F Add (IC8ADDGPT23ZE) */
#define _0000_POE_IC8ADDGPT23ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDGPT23ZE_ENABLE      (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 7 (POECR7)
*/
/* MTIOC9A Pin High-Impedance Enable (MTU9AZE) */
#define _0000_POE_MTU9AZE_DISABLE           (0x0000U) /* Does not switch the pin to high-impedance state */
#define _0001_POE_MTU9AZE_ENABLE            (0x0001U) /* Switch the pin to high-impedance state */
/* MTIOC9B Pin High-Impedance Enable (MTU9BZE) */
#define _0000_POE_MTU9BZE_DISABLE           (0x0000U) /* Does not switch the pin to high-impedance state */
#define _0002_POE_MTU9BZE_ENABLE            (0x0002U) /* Switch the pin to high-impedance state */
/* MTIOC9C Pin High-Impedance Enable (MTU9CZE) */
#define _0000_POE_MTU9CZE_DISABLE           (0x0000U) /* Does not switch the pin to high-impedance state */
#define _0004_POE_MTU9CZE_ENABLE            (0x0004U) /* Switch the pin to high-impedance state */
/* MTIOC9D Pin High-Impedance Enable (MTU9DZE) */
#define _0000_POE_MTU9DZE_DISABLE           (0x0000U) /* Does not switch the pin to high-impedance state */
#define _0008_POE_MTU9DZE_ENABLE            (0x0008U) /* Switch the pin to high-impedance state */

/*
    Port Output Enable Control Register 8 (POECR8)
*/
/* MTU9 Output Disabling Condition CFLAG Add (CMADDMT9ZE) */
#define _0000_POE_CMADDMT9ZE_DISABLE        (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDMT9ZE_ENABLE         (0x0001U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE0F Add (IC1ADDMT9ZE) */
#define _0000_POE_IC1ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDMT9ZE_ENABLE        (0x0002U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE4F Add (IC2ADDMT9ZE) */
#define _0000_POE_IC2ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDMT9ZE_ENABLE        (0x0004U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE8F Add (IC3ADDMT9ZE) */
#define _0000_POE_IC3ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDMT9ZE_ENABLE        (0x0008U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE10F Add (IC4ADDMT9ZE) */
#define _0000_POE_IC4ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDMT9ZE_ENABLE        (0x0010U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE11F Add (IC5ADDMT9ZE) */
#define _0000_POE_IC5ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDMT9ZE_ENABLE        (0x0020U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE12F Add (IC6ADDMT9ZE) */
#define _0000_POE_IC6ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDMT9ZE_ENABLE        (0x0040U) /* Add the pins to high-impedance control conditions */
/* MTU9 High-Impedance POE9F Add (IC8ADDMT9ZE) */
#define _0000_POE_IC8ADDMT9ZE_DISABLE       (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDMT9ZE_ENABLE        (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 9 (POECR9)
*/
/* GPT0 to GPT2 Output Disabling Condition CFLAG Add (CMADDGPT02ZE) */
#define _0000_POE_CMADDGPT02ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDGPT02ZE_ENABLE       (0x0001U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE0F Add (IC1ADDGPT02ZE) */
#define _0000_POE_IC1ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDGPT02ZE_ENABLE      (0x0002U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE4F Add (IC2ADDGPT02ZE) */
#define _0000_POE_IC2ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDGPT02ZE_ENABLE      (0x0004U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE8F Add (IC3ADDGPT02ZE) */
#define _0000_POE_IC3ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDGPT02ZE_ENABLE      (0x0008U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE10F Add (IC4ADDGPT02ZE) */
#define _0000_POE_IC4ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDGPT02ZE_ENABLE      (0x0010U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE11F Add (IC5ADDGPT02ZE) */
#define _0000_POE_IC5ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDGPT02ZE_ENABLE      (0x0020U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE12F Add (IC6ADDGPT02ZE) */
#define _0000_POE_IC6ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDGPT02ZE_ENABLE      (0x0040U) /* Add the pins to high-impedance control conditions */
/* GPT0 to GPT2 High-Impedance POE9F Add (IC8ADDGPT02ZE) */
#define _0000_POE_IC8ADDGPT02ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDGPT02ZE_ENABLE      (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 10 (POECR10)
*/
/* GPT4 to GPT6 Output Disabling Condition CFLAG Add (CMADDGPT46ZE) */
#define _0000_POE_CMADDGPT46ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDGPT46ZE_ENABLE       (0x0001U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE0F Add (IC1ADDGPT46ZE) */
#define _0000_POE_IC1ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDGPT46ZE_ENABLE      (0x0002U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE4F Add (IC2ADDGPT46ZE) */
#define _0000_POE_IC2ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDGPT46ZE_ENABLE      (0x0004U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE8F Add (IC3ADDGPT46ZE) */
#define _0000_POE_IC3ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDGPT46ZE_ENABLE      (0x0008U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE10F Add (IC4ADDGPT46ZE) */
#define _0000_POE_IC4ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDGPT46ZE_ENABLE      (0x0010U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE11F Add (IC5ADDGPT46ZE) */
#define _0000_POE_IC5ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDGPT46ZE_ENABLE      (0x0020U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE12F Add (IC6ADDGPT46ZE) */
#define _0000_POE_IC6ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDGPT46ZE_ENABLE      (0x0040U) /* Add the pins to high-impedance control conditions */
/* GPT4 to GPT6 High-Impedance POE9F Add (IC8ADDGPT46ZE) */
#define _0000_POE_IC8ADDGPT46ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDGPT46ZE_ENABLE      (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Output Enable Control Register 11 (POECR11)
*/
/* GPT7 to GPT9 Output Disabling Condition CFLAG Add (CMADDGPT79ZE) */
#define _0000_POE_CMADDGPT79ZE_DISABLE      (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0001_POE_CMADDGPT79ZE_ENABLE       (0x0001U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE0F Add (IC1ADDGPT79ZE) */
#define _0000_POE_IC1ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0002_POE_IC1ADDGPT79ZE_ENABLE      (0x0002U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE4F Add (IC2ADDGPT79ZE) */
#define _0000_POE_IC2ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0004_POE_IC2ADDGPT79ZE_ENABLE      (0x0004U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE8F Add (IC3ADDGPT79ZE) */
#define _0000_POE_IC3ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0008_POE_IC3ADDGPT79ZE_ENABLE      (0x0008U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE10F Add (IC4ADDGPT79ZE) */
#define _0000_POE_IC4ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0010_POE_IC4ADDGPT79ZE_ENABLE      (0x0010U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE11F Add (IC5ADDGPT79ZE) */
#define _0000_POE_IC5ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0020_POE_IC5ADDGPT79ZE_ENABLE      (0x0020U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE12F Add (IC6ADDGPT79ZE) */
#define _0000_POE_IC6ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0040_POE_IC6ADDGPT79ZE_ENABLE      (0x0040U) /* Add the pins to high-impedance control conditions */
/* GPT7 to GPT9 High-Impedance POE9F Add (IC8ADDGPT79ZE) */
#define _0000_POE_IC8ADDGPT79ZE_DISABLE     (0x0000U) /* Does not add the pins to high-impedance control conditions */
#define _0100_POE_IC8ADDGPT79ZE_ENABLE      (0x0100U) /* Add the pins to high-impedance control conditions */

/*
    Port Mode Mask Control Register 0 (PMMCR0)
*/
/* MTIOC0A Pin Port Mode Mask Enable (MTU0AME) */
#define _0000_POE_MTU0AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0001_POE_MTU0AME_ENABLE            (0x0001U) /* Switching to the general I/O port pin is enabled */
/* MTIOC0B Pin Port Mode Mask Enable (MTU0BME) */
#define _0000_POE_MTU0BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0002_POE_MTU0BME_ENABLE            (0x0002U) /* Switching to the general I/O port pin is enabled */
/* MTIOC0C Pin Port Mode Mask Enable (MTU0CME) */
#define _0000_POE_MTU0CME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0004_POE_MTU0CME_ENABLE            (0x0004U) /* Switching to the general I/O port pin is enabled */
/* MTIOC0D Pin Port Mode Mask Enable (MTU0DME) */
#define _0000_POE_MTU0DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0008_POE_MTU0DME_ENABLE            (0x0008U) /* Switching to the general I/O port pin is enabled */
/* MTIOC9A Pin Port Mode Mask Enable (MTU9AME) */
#define _0000_POE_MTU9AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0100_POE_MTU9AME_ENABLE            (0x0100U) /* Switching to the general I/O port pin is enabled */
/* MTIOC9B Pin Port Mode Mask Enable (MTU9BME) */
#define _0000_POE_MTU9BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0200_POE_MTU9BME_ENABLE            (0x0200U) /* Switching to the general I/O port pin is enabled */
/* MTIOC9C Pin Port Mode Mask Enable (MTU9CME) */
#define _0000_POE_MTU9CME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0400_POE_MTU9CME_ENABLE            (0x0400U) /* Switching to the general I/O port pin is enabled */
/* MTIOC9D Pin Port Mode Mask Enable (MTU9DME) */
#define _0000_POE_MTU9DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0800_POE_MTU9DME_ENABLE            (0x0800U) /* Switching to the general I/O port pin is enabled */

/*
    Port Mode Mask Control Register 1 (PMMCR1)
*/
/* MTIOC7B Pin Port Mode Mask Enable (MTU7BME) */
#define _0000_POE_MTU7BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0001_POE_MTU7BME_ENABLE            (0x0001U) /* Switching to the general I/O port pin is enabled */
/* MTIOC7A Pin Port Mode Mask Enable (MTU7AME) */
#define _0000_POE_MTU7AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0002_POE_MTU7AME_ENABLE            (0x0002U) /* Switching to the general I/O port pin is enabled */
/* MTIOC6B Pin Port Mode Mask Enable (MTU6BME) */
#define _0000_POE_MTU6BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0004_POE_MTU6BME_ENABLE            (0x0004U) /* Switching to the general I/O port pin is enabled */
/* MTIOC7D Pin Port Mode Mask Enable (MTU7DME) */
#define _0000_POE_MTU7DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0008_POE_MTU7DME_ENABLE            (0x0008U) /* Switching to the general I/O port pin is enabled */
/* MTIOC7C Pin Port Mode Mask Enable (MTU7CME) */
#define _0000_POE_MTU7CME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0010_POE_MTU7CME_ENABLE            (0x0010U) /* Switching to the general I/O port pin is enabled */
/* MTIOC6D Pin Port Mode Mask Enable (MTU6DME) */
#define _0000_POE_MTU6DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0020_POE_MTU6DME_ENABLE            (0x0020U) /* Switching to the general I/O port pin is enabled */
/* MTIOC4B Pin Port Mode Mask Enable (MTU4BME) */
#define _0000_POE_MTU4BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0100_POE_MTU4BME_ENABLE            (0x0100U) /* Switching to the general I/O port pin is enabled */
/* MTIOC4A Pin Port Mode Mask Enable (MTU4AME) */
#define _0000_POE_MTU4AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0200_POE_MTU4AME_ENABLE            (0x0200U) /* Switching to the general I/O port pin is enabled */
/* MTIOC4B Pin Port Mode Mask Enable (MTU3BME) */
#define _0000_POE_MTU3BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0400_POE_MTU3BME_ENABLE            (0x0400U) /* Switching to the general I/O port pin is enabled */
/* MTIOC4A Pin Port Mode Mask Enable (MTU4DME) */
#define _0000_POE_MTU4DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0800_POE_MTU4DME_ENABLE            (0x0800U) /* Switching to the general I/O port pin is enabled */
/* MTIOC7C Pin Port Mode Mask Enable (MTU4CME) */
#define _0000_POE_MTU4CME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _1000_POE_MTU4CME_ENABLE            (0x1000U) /* Switching to the general I/O port pin is enabled */
/* MTIOC6D Pin Port Mode Mask Enable (MTU3DME) */
#define _0000_POE_MTU3DME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _2000_POE_MTU3DME_ENABLE            (0x2000U) /* Switching to the general I/O port pin is enabled */

/*
    Port Mode Mask Control Register 2 (PMMCR2)
*/
/* GTIOC0A Pin Port Mode Mask Enable (GPT0AME) */
#define _0000_POE_GPT0AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0001_POE_GPT0AME_ENABLE            (0x0001U) /* Switching to the general I/O port pin is enabled */
/* GTIOC0B Pin Port Mode Mask Enable (GPT0BME) */
#define _0000_POE_GPT0BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0002_POE_GPT0BME_ENABLE            (0x0002U) /* Switching to the general I/O port pin is enabled */
/* GTIOC1A Pin Port Mode Mask Enable (GPT1AME) */
#define _0000_POE_GPT1AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0004_POE_GPT1AME_ENABLE            (0x0004U) /* Switching to the general I/O port pin is enabled */
/* GTIOC1B Pin Port Mode Mask Enable (GPT1BME) */
#define _0000_POE_GPT1BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0008_POE_GPT1BME_ENABLE            (0x0008U) /* Switching to the general I/O port pin is enabled */
/* GTIOC2A Pin Port Mode Mask Enable (GPT2AME) */
#define _0000_POE_GPT2AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0010_POE_GPT2AME_ENABLE            (0x0010U) /* Switching to the general I/O port pin is enabled */
/* GTIOC2B Pin Port Mode Mask Enable (GPT2BME) */
#define _0000_POE_GPT2BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0020_POE_GPT2BME_ENABLE            (0x0020U) /* Switching to the general I/O port pin is enabled */
/* GTIOC3A Pin Port Mode Mask Enable (GPT3AME) */
#define _0000_POE_GPT3AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0040_POE_GPT3AME_ENABLE            (0x0040U) /* Switching to the general I/O port pin is enabled */
/* GTIOC3B Pin Port Mode Mask Enable (GPT3BME) */
#define _0000_POE_GPT3BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0080_POE_GPT3BME_ENABLE            (0x0080U) /* Switching to the general I/O port pin is enabled */
/* GTIOC4A Pin Port Mode Mask Enable (GPT4AME) */
#define _0000_POE_GPT4AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0100_POE_GPT4AME_ENABLE            (0x0100U) /* Switching to the general I/O port pin is enabled */
/* GTIOC4B Pin Port Mode Mask Enable (GPT4BME) */
#define _0000_POE_GPT4BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0200_POE_GPT4BME_ENABLE            (0x0200U) /* Switching to the general I/O port pin is enabled */
/* GTIOC5A Pin Port Mode Mask Enable (GPT5AME) */
#define _0000_POE_GPT5AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0400_POE_GPT5AME_ENABLE            (0x0400U) /* Switching to the general I/O port pin is enabled */
/* GTIOC5B Pin Port Mode Mask Enable (GPT5BME) */
#define _0000_POE_GPT5BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _0800_POE_GPT5BME_ENABLE            (0x0800U) /* Switching to the general I/O port pin is enabled */
/* GTIOC3A Pin Port Mode Mask Enable (GPT6AME) */
#define _0000_POE_GPT6AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _1000_POE_GPT6AME_ENABLE            (0x1000U) /* Switching to the general I/O port pin is enabled */
/* GTIOC3B Pin Port Mode Mask Enable (GPT6BME) */
#define _0000_POE_GPT6BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _2000_POE_GPT6BME_ENABLE            (0x2000U) /* Switching to the general I/O port pin is enabled */
/* GTIOC4A Pin Port Mode Mask Enable (GPT7AME) */
#define _0000_POE_GPT7AME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _4000_POE_GPT7AME_ENABLE            (0x4000U) /* Switching to the general I/O port pin is enabled */
/* GTIOC4B Pin Port Mode Mask Enable (GPT7BME) */
#define _0000_POE_GPT7BME_DISABLE           (0x0000U) /* Switching to the general I/O port pin is disabled */
#define _8000_POE_GPT7BME_ENABLE            (0x8000U) /* Switching to the general I/O port pin is enabled */

/*   
    Port Output Enable Comparator Request Select Register (POECMPSEL)
*/
/* Comparator Channel 0 Output Disabling Request Enable (POEREQ0) */
#define _0000_POE_POEREQ0_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled */
#define _0001_POE_POEREQ0_ENABLE            (0x0001U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 1 Output Disabling Request Enable (POEREQ1) */
#define _0000_POE_POEREQ1_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled*/
#define _0002_POE_POEREQ1_ENABLE            (0x0002U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 2 Output Disabling Request Enable (POEREQ2) */
#define _0000_POE_POEREQ2_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled */
#define _0004_POE_POEREQ2_ENABLE            (0x0004U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 3 Output Disabling Request Enable (POEREQ3) */
#define _0000_POE_POEREQ3_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled */
#define _0008_POE_POEREQ3_ENABLE            (0x0008U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 4 Output Disabling Request Enable (POEREQ4) */
#define _0000_POE_POEREQ4_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled */
#define _0010_POE_POEREQ4_ENABLE            (0x0010U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 5 Output Disabling Request Enable (POEREQ5) */
#define _0000_POE_POEREQ5_DISABLE           (0x0000U) /* Disable output upon CMPC0 output detection is disabled */
#define _0020_POE_POEREQ5_ENABLE            (0x0020U) /* Disable output upon CMPC0 output detection is enabled */

/*
    Port Output Enable Comparator Request Extended Selection Register m(POECMPEXm) (m = 0 to 8)
*/
/* Comparator Channel 0 Output Disabling Request Enable (POEREQ0) */
#define _00_POE_CMPC0_DISABLE               (0x00U) /* Disable output upon CMPC0 output detection is disabled */
#define _01_POE_CMPC0_ENABLE                (0x01U) /* Disable output upon CMPC0 output detection is enabled */
/* Comparator Channel 1 Output Disabling Request Enable (POEREQ1) */
#define _00_POE_CMPC1_DISABLE               (0x00U) /* Disable output upon CMPC1 output detection is disabled */
#define _02_POE_CMPC1_ENABLE                (0x02U) /* Disable output upon CMPC1 output detection is enabled */
/* Comparator Channel 2 Output Disabling Request Enable (POEREQ2) */
#define _00_POE_CMPC2_DISABLE               (0x00U) /* Disable output upon CMPC2 output detection is disabled */
#define _04_POE_CMPC2_ENABLE                (0x04U) /* Disable output upon CMPC2 output detection is enabled */
/* Comparator Channel 3 Output Disabling Request Enable (POEREQ3) */
#define _00_POE_CMPC3_DISABLE               (0x00U) /* Disable output upon CMPC3 output detection is disabled */
#define _08_POE_CMPC3_ENABLE                (0x08U) /* Disable output upon CMPC3 output detection is enabled */
/* Comparator Channel 4 Output Disabling Request Enable (POEREQ4) */
#define _00_POE_CMPC4_DISABLE               (0x00U) /* Disable output upon CMPC4 output detection is disabled */
#define _10_POE_CMPC4_ENABLE                (0x10U) /* Disable output upon CMPC4 output detection is enabled */
/* Comparator Channel 5 Output Disabling Request Enable (POEREQ5) */
#define _00_POE_CMPC5_DISABLE               (0x00U) /* Disable output upon CMPC5 output detection is disabled */
#define _20_POE_CMPC5_ENABLE                (0x20U) /* Disable output upon CMPC5 output detection is enabled */

/*
    MTU0 Pin Select Register 1 (M0SELR1)
*/
/* MTU0-A (MTIOC0A) Pin Select (M0ASEL) */
#define _00_POE_MTU0APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC0A pin */
#define _01_POE_MTU0APIN_PB3                (0x01U) /* Controls high-impedance state of PB3 when used as MTIOC0A pin */
#define _02_POE_MTU0APIN_P31                (0x02U) /* Controls high-impedance state of P31 when used as MTIOC0A pin */
#define _03_POE_MTU0APIN_P70                (0x03U) /* Controls high-impedance state of P70 when used as MTIOC0A pin */
/* MTU0-B (MTIOC0B) Pin Select (M0BSEL) */
#define _00_POE_MTU0BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC0B pin */
#define _10_POE_MTU0BPIN_PB2                (0x10U) /* Controls high-impedance state of P87 when used as MTIOC0B pin */
#define _20_POE_MTU0BPIN_P30                (0x20U) /* Controls high-impedance state of P30 when used as MTIOC0B pin */

/*
    MTU0 Pin Select Register 2 (M0SELR2)
*/
/* MTU0-C (MTIOC0C) Pin Select (M0CSEL) */
#define _00_POE_MTU0CPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC0C pin */
#define _01_POE_MTU0CPIN_PB1                (0x01U) /* Controls high-impedance state of PB1 when used as MTIOC0C pin */
#define _02_POE_MTU0CPIN_P27                (0x02U) /* Controls high-impedance state of P27 when used as MTIOC0C pin */
/* MTU0-D (MTIOC0D) Pin Select (M0DSEL) */
#define _00_POE_MTU0DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC0D pin */
#define _10_POE_MTU0DPIN_PB0                (0x10U) /* Controls high-impedance state of PB0 when used as MTIOC0D pin */

/*
    MTU3 Pin Select Register (M3SELR)
*/
/* MTU3-B (MTIOC3B) Pin Select (M3BSEL) */
#define _00_POE_MTU3BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC3B pin */
#define _01_POE_MTU3BPIN_P71                (0x01U) /* Controls high-impedance state of P71 when used as MTIOC3B pin */
/* MTU3-D (MTIOC3D) Pin Select (M3DSEL) */
#define _00_POE_MTU3DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC3D pin */
#define _10_POE_MTU3DPIN_P74                (0x10U) /* Controls high-impedance state of P74 when used as MTIOC3D pin */

/*
    MTU4 Pin Select Register 1 (M4SELR1)
*/
/* MTU4-A (MTIOC4A) Pin Select (M4ASEL) */
#define _00_POE_MTU4APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC4A pin */
#define _01_POE_MTU4APIN_P72                (0x01U) /* Controls high-impedance state of P72 when used as MTIOC4A pin */
/* MTU4-C (MTIOC4C) Pin Select)(M4CSEL) */
#define _00_POE_MTU4CPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC4C pin */
#define _10_POE_MTU4CPIN_P75                (0x10U) /* Controls high-impedance state of P75 when used as MTIOC4C pin */

/*
    MTU4 Pin Select Register 2 (M4SELR2)
*/
/* MTU4-B (MTIOC4B) Pin Select (M4BSEL) */
#define _00_POE_MTU4BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC4B pin */
#define _01_POE_MTU4BPIN_P73                (0x01U) /* Controls high-impedance state of P73 when used as MTIOC4B pin */
/* MTU4-D (MTIOC4D) Pin Select (M4DSEL) */
#define _00_POE_MTU4DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC4D pin */
#define _10_POE_MTU4DPIN_P76                (0x10U) /* Controls high-impedance state of P76 when used as MTIOC4D pin */

/*
    MTU6 Pin Select Register (M6SELR)
*/
/* MTU6-B (MTIOC6B) Pin Select (M6BSEL) */
#define _00_POE_MTU6BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC6B pin */
#define _01_POE_MTU6BPIN_P95                (0x01U) /* Controls high-impedance state of P95 when used as MTIOC6B pin */
/* MTU6-D (MTIOC6D) Pin Select (M6DSEL) */
#define _00_POE_MTU6DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC6D pin */
#define _10_POE_MTU6DPIN_P92                (0x10U) /* Controls high-impedance state of P92 when used as MTIOC6D pin */

/*
    MTU7 Pin Select Register 1 (M7SELR1)
*/
/* MTU7-A (MTIOC7A) Pin Select (M7ASEL) */
#define _00_POE_MTU7APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC7A pin */
#define _01_POE_MTU7APIN_P94                (0x01U) /* Controls high-impedance state of P94 when used as MTIOC7A pin */
/* MTU7-C (MTIOC7C) Pin Select (M7CSEL) */   
#define _00_POE_MTU7CPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC7C pin */
#define _10_POE_MTU7CPIN_P91                (0x10U) /* Controls high-impedance state of P91 when used as MTIOC7C pin */

/*
    MTU7 Pin Select Register 2 (M7SELR2)
*/
/* MTU7-B (MTIOC7B) Pin Select (M7BSEL) */
#define _00_POE_MTU7BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC7B pin */
#define _01_POE_MTU7BPIN_P93                (0x01U) /* Controls high-impedance state of P93 when used as MTIOC7B pin */
/* MTU7-D (MTIOC7D) Pin Select (M7DSEL) */
#define _00_POE_MTU7DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC7D pin */
#define _10_POE_MTU7DPIN_P90                (0x10U) /* Controls high-impedance state of P90 when used as MTIOC7D pin */

/*
    MTU9 Pin Select Register 1 (M9SELR1)
*/
/* MTU9-A (MTIOC9A) Pin Select (M9ASEL) */
#define _00_POE_MTU9APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC9A pin */
#define _01_POE_MTU9APIN_PD7                (0x01U) /* Controls high-impedance state of PD7 when used as MTIOC9A pin */
#define _02_POE_MTU9APIN_P21                (0x02U) /* Controls high-impedance state of P21 when used as MTIOC9A pin */
#define _03_POE_MTU9APIN_P00                (0x03U) /* Controls high-impedance state of P00 when used as MTIOC9A pin */
/* MTU9-B (MTIOC9B) Pin Select (M9BSEL) */
#define _00_POE_MTU9BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC9B pin */
#define _10_POE_MTU9BPIN_PE0                (0x10U) /* Controls high-impedance state of PE0 when used as MTIOC9B pin */
#define _30_POE_MTU9BPIN_P10                (0x30U) /* Controls high-impedance state of P10 when used as MTIOC9B pin */
#define _40_POE_MTU9BPIN_P22                (0x40U) /* Controls high-impedance state of P22 when used as MTIOC9B pin */

/*
    MTU9 Pin Select Register 2 (M9SELR2)
*/
/* MTU9-C (MTIOC9C) Pin Select (M9CSEL) */
#define _00_POE_MTU9CPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC9C pin */
#define _01_POE_MTU9CPIN_PD6                (0x01U) /* Controls high-impedance state of PD6 when used as MTIOC9C pin */
#define _02_POE_MTU9CPIN_P20                (0x02U) /* Controls high-impedance state of P20 when used as MTIOC9C pin */
#define _03_POE_MTU9CPIN_P01                (0x03U) /* Controls high-impedance state of P01 when used as MTIOC9C pin */
/* MTU9-D (MTIOC9D) Pin Select (M9DSEL) */   
#define _00_POE_MTU9DPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for MTIOC9D pin */
#define _10_POE_MTU9DPIN_PE1                (0x10U) /* Controls high-impedance state of PE1 when used as MTIOC9D pin */
#define _20_POE_MTU9DPIN_PN7                (0x20U) /* Controls high-impedance state of PN7 when used as MTIOC9D pin */
#define _30_POE_MTU9DPIN_PE5                (0x30U) /* Controls high-impedance state of PE5 when used as MTIOC9D pin */
#define _40_POE_MTU9DPIN_P11                (0x40U) /* Controls high-impedance state of P11 when used as MTIOC9D pin */

/*
    GPT0 Pin Select Register (G0SELR)
*/
/* GPT0-A (GTIOC0A) Pin Select (G0ASEL) */
#define _00_POE_GPT0APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC0A pin */
#define _01_POE_GPT0APIN_P71                (0x01U) /* Controls high-impedance state of P71 when used as GTIOC0A pin */
#define _02_POE_GPT0APIN_PD7                (0x02U) /* Controls high-impedance state of PD7 when used as GTIOC0A pin */
#define _04_POE_GPT0APIN_PD2                (0x04U) /* Controls high-impedance state of PD2 when used as GTIOC0A pin */
/* GPT0-B (GTIOC0B) Pin Select (G0BSEL) */   
#define _00_POE_GPT0BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC0B pin */
#define _10_POE_GPT0BPIN_P74                (0x10U) /* Controls high-impedance state of P74 when used as GTIOC0B pin */
#define _20_POE_GPT0BPIN_PD6                (0x20U) /* Controls high-impedance state of PD6 when used as GTIOC0B pin */
#define _40_POE_GPT0BPIN_PD1                (0x40U) /* Controls high-impedance state of PD1 when used as GTIOC0B pin */

/*
    GPT1 Pin Select Register (G1SELR)
*/
/* GPT1-A (GTIOC1A) Pin Select (G1ASEL) */
#define _00_POE_GPT1APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC1A pin */
#define _01_POE_GPT1APIN_P72                (0x01U) /* Controls high-impedance state of P72 when used as GTIOC1A pin */
#define _02_POE_GPT1APIN_PD5                (0x02U) /* Controls high-impedance state of PD5 when used as GTIOC1A pin */
#define _04_POE_GPT1APIN_PD0                (0x04U) /* Controls high-impedance state of PD0 when used as GTIOC1A pin */
/* GPT1-B (GTIOC1B) Pin Select (G1BSEL) */   
#define _00_POE_GPT1BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC1B pin */
#define _10_POE_GPT1BPIN_P75                (0x10U) /* Controls high-impedance state of P75 when used as GTIOC1B pin */
#define _20_POE_GPT1BPIN_PD4                (0x20U) /* Controls high-impedance state of PD4 when used as GTIOC1B pin */
#define _40_POE_GPT1BPIN_PB7                (0x40U) /* Controls high-impedance state of PB7 when used as GTIOC1B pin */

/*
    GPT2 Pin Select Register (G2SELR)
*/
/* GPT2-A (GTIOC2A) Pin Select (G2ASEL) */
#define _00_POE_GPT2APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC2A  pin */
#define _01_POE_GPT2APIN_P73                (0x01U) /* Controls high-impedance state of P73 when used as GTIOC2A pin */
#define _02_POE_GPT2APIN_PD3                (0x02U) /* Controls high-impedance state of PD3 when used as GTIOC2A pin */
#define _04_POE_GPT2APIN_PB6                (0x04U) /* Controls high-impedance state of PB6 when used as GTIOC2A pin */
/* GPT2-B (GTIOC2B) Pin Select (G2BSEL) */
#define _00_POE_GPT2BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC2B pin */
#define _10_POE_GPT2BPIN_P76                (0x10U) /* Controls high-impedance state of P76 when used as GTIOC2B pin */
#define _20_POE_GPT2BPIN_PD2                (0x20U) /* Controls high-impedance state of PD2 when used as GTIOC2B pin */
#define _40_POE_GPT2BPIN_PB5                (0x40U) /* Controls high-impedance state of PB5 when used as GTIOC2B pin */

/*
    GPT3 Pin Select Register (G3SELR)
*/
/* GPT3-A (GTIOC3A) Pin Select (G3ASEL) */
#define _00_POE_GPT3APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC3A pin */
#define _01_POE_GPT3APIN_P32                (0x01U) /* Controls high-impedance state of P32 when used as GTIOC3A pin */
#define _02_POE_GPT3APIN_PD1                (0x02U) /* Controls high-impedance state of PD1 when used as GTIOC3A pin */
#define _03_POE_GPT3APIN_PE5                (0x03U) /* Controls high-impedance state of PE5 when used as GTIOC3A pin */
#define _04_POE_GPT3APIN_PD7                (0x04U) /* Controls high-impedance state of PD7 when used as GTIOC3A pin */
#define _05_POE_GPT3APIN_PB6                (0x05U) /* Controls high-impedance state of PB6 when used as GTIOC3A pin */
#define _06_POE_GPT3APIN_P10                (0x06U) /* Controls high-impedance state of P10 when used as GTIOC3A pin */
/* GPT3-B (GTIOC3B) Pin Select (G3BSEL) */
#define _00_POE_GPT3BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC3B pin */
#define _10_POE_GPT3BPIN_P33                (0x10U) /* Controls high-impedance state of P33 when used as GTIOC3B pin */
#define _20_POE_GPT3BPIN_PD0                (0x20U) /* Controls high-impedance state of PD0 when used as GTIOC3B pin */
#define _30_POE_GPT3BPIN_P11                (0x30U) /* Controls high-impedance state of P11 when used as GTIOC3B pin */
#define _40_POE_GPT3BPIN_PD6                (0x40U) /* Controls high-impedance state of PD6 when used as GTIOC3B pin */
#define _50_POE_GPT3BPIN_PB5                (0x50U) /* Controls high-impedance state of PB5 when used as GTIOC3B pin */

/*
    GPT4 Pin Select Register (G4SELR)
*/
/* GPT4-A (GTIOC4A) Pin Select (G4ASEL) */
#define _00_POE_GPT4APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC4A pin */
#define _01_POE_GPT4APIN_P95                (0x01U) /* Controls high-impedance state of P95 when used as GTIOC4A pin */
#define _02_POE_GPT4APIN_P71                (0x02U) /* Controls high-impedance state of P71 when used as GTIOC4A pin */
/* GPT4-B (GTIOC4B) Pin Select (G4BSEL) */
#define _00_POE_GPT4BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC4B pin */
#define _10_POE_GPT4BPIN_P92                (0x10U) /* Controls high-impedance state of P92 when used as GTIOC4B pin */
#define _20_POE_GPT4BPIN_P74                (0x20U) /* Controls high-impedance state of P74 when used as GTIOC4B pin */

/*
    GPT5 Pin Select Register (G5SELR)
*/
/* GPT5-A (GTIOC5A) Pin Select (G5ASEL) */
#define _00_POE_GPT5APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC5A pin */
#define _01_POE_GPT5APIN_P94                (0x01U) /* Controls high-impedance state of P94 when used as GTIOC5A pin */
#define _02_POE_GPT5APIN_P72                (0x02U) /* Controls high-impedance state of P72 when used as GTIOC5A pin */
/* GPT5-B (GTIOC5B) Pin Select (G5BSEL) */
#define _00_POE_GPT5BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC5B pin */
#define _10_POE_GPT5BPIN_P91                (0x10U) /* Controls high-impedance state of P91 when used as GTIOC5B pin */
#define _20_POE_GPT5BPIN_P75                (0x20U) /* Controls high-impedance state of P75 when used as GTIOC5B pin */

/*
    GPT6 Pin Select Register (G6SELR)
*/
/* GPT6-A (GTIOC6A) Pin Select (G6ASEL) */
#define _00_POE_GPT6APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC6A pin */
#define _01_POE_GPT6APIN_P93                (0x01U) /* Controls high-impedance state of P93 when used as GTIOC6A pin */
#define _02_POE_GPT6APIN_P73                (0x02U) /* Controls high-impedance state of P73 when used as GTIOC6A pin */
/* GPT6-B (GTIOC6B) Pin Select (G6BSEL) */
#define _00_POE_GPT6BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC6B pin */
#define _10_POE_GPT6BPIN_P90                (0x10U) /* Controls high-impedance state of P90 when used as GTIOC6B pin */
#define _20_POE_GPT6BPIN_P76                (0x20U) /* Controls high-impedance state of P76 when used as GTIOC6B pin */

/*
    GPT7 Pin Select Register (G7SELR)
*/
/* GPT7-A (GTIOC7A) Pin Select (G7ASEL) */
#define _00_POE_GPT7APIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC7A pin */
#define _01_POE_GPT7APIN_P95                (0x01U) /* Controls high-impedance state of P95 when used as GTIOC7A pin */
#define _02_POE_GPT7APIN_PB2                (0x02U) /* Controls high-impedance state of PB2 when used as GTIOC7A pin */
#define _03_POE_GPT7APIN_P32                (0x03U) /* Controls high-impedance state of P32 when used as GTIOC7A pin */
#define _04_POE_GPT7APIN_PD5                (0x04U) /* Controls high-impedance state of PD5 when used as GTIOC7A pin */
/* GPT7-B (GTIOC7B) Pin Select (G7BSEL) */   
#define _00_POE_GPT7BPIN_NOPIN_SET          (0x00U) /* Does not perform the output disabling control for GTIOC7B pin */
#define _10_POE_GPT7BPIN_P92                (0x10U) /* Controls high-impedance state of P92 when used as GTIOC7B pin */
#define _20_POE_GPT7BPIN_PB1                (0x20U) /* Controls high-impedance state of PB1 when used as GTIOC7B pin */
#define _30_POE_GPT7BPIN_P33                (0x30U) /* Controls high-impedance state of P33 when used as GTIOC7B pin */
#define _40_POE_GPT7BPIN_PD3                (0x40U) /* Controls high-impedance state of PD3 when used as GTIOC7B pin */

/*
    Below macro definitions are shared among the following registers:
    - Input Signal Mask Control Register x (IMCRx) (x = 0 - 6 , 9 - 14)
*/
/* POEy Mask Signal Select (POEyMS) (y = 0, 4, 8 - 12) */
/* COMPz Mask Signal Select (CMPzMS) (z = 0 - 5) */
#define _00_POE_NO_MASK                     (0x00U) /* Does not mask */
#define _01_POE_MASK_MTIOC0A                (0x01U) /* Mask with MTIOC0A signal */
#define _02_POE_MASK_MTIOC0B                (0x02U) /* Mask with MTIOC0B signal */
#define _03_POE_MASK_MTIOC0C                (0x03U) /* Mask with MTIOC0C signal */
#define _04_POE_MASK_MTIOC0D                (0x04U) /* Mask with MTIOC0D signal */
#define _05_POE_MASK_MTIOC1A                (0x05U) /* Mask with MTIOC1A signal */
#define _06_POE_MASK_MTIOC1B                (0x06U) /* Mask with MTIOC1B signal */
#define _07_POE_MASK_MTIOC2A                (0x07U) /* Mask with MTIOC2A signal */
#define _08_POE_MASK_MTIOC2B                (0x08U) /* Mask with MTIOC2B signal */
#define _09_POE_MASK_MTIOC3A                (0x09U) /* Mask with MTIOC3A signal */
#define _0A_POE_MASK_MTIOC3B                (0x0AU) /* Mask with MTIOC3B signal */
#define _0B_POE_MASK_MTIOC3C                (0x0BU) /* Mask with MTIOC3C signal */
#define _0C_POE_MASK_MTIOC3D                (0x0CU) /* Mask with MTIOC3D signal */
#define _0D_POE_MASK_MTIOC4A                (0x0DU) /* Mask with MTIOC4A signal */
#define _0E_POE_MASK_MTIOC4B                (0x0EU) /* Mask with MTIOC4B signal */
#define _0F_POE_MASK_MTIOC4C                (0x0FU) /* Mask with MTIOC4C signal */
#define _10_POE_MASK_MTIOC4D                (0x10U) /* Mask with MTIOC4D signal */
#define _11_POE_MASK_MTIOC6A                (0x11U) /* Mask with MTIOC6A signal */
#define _12_POE_MASK_MTIOC6B                (0x12U) /* Mask with MTIOC6B signal */
#define _13_POE_MASK_MTIOC6C                (0x13U) /* Mask with MTIOC6C signal */
#define _14_POE_MASK_MTIOC6D                (0x14U) /* Mask with MTIOC6D signal */
#define _15_POE_MASK_MTIOC7A                (0x15U) /* Mask with MTIOC7A signal */
#define _16_POE_MASK_MTIOC7B                (0x16U) /* Mask with MTIOC7B signal */
#define _17_POE_MASK_MTIOC7C                (0x17U) /* Mask with MTIOC7C signal */
#define _18_POE_MASK_MTIOC7D                (0x18U) /* Mask with MTIOC7D signal */
#define _19_POE_MASK_MTIOC9A                (0x19U) /* Mask with MTIOC9A signal */
#define _1A_POE_MASK_MTIOC9B                (0x1AU) /* Mask with MTIOC9B signal */
#define _1B_POE_MASK_MTIOC9C                (0x1BU) /* Mask with MTIOC9C signal */
#define _1C_POE_MASK_MTIOC9D                (0x1CU) /* Mask with MTIOC9D signal */
#define _1D_POE_MASK_GTIOC0A                (0x1DU) /* Mask with GTIOC0A signal */
#define _1E_POE_MASK_GTIOC0B                (0x1EU) /* Mask with GTIOC0B signal */
#define _1F_POE_MASK_GTIOC1A                (0x1FU) /* Mask with GTIOC1A signal */
#define _20_POE_MASK_GTIOC1B                (0x20U) /* Mask with GTIOC1B signal */
#define _21_POE_MASK_GTIOC2A                (0x21U) /* Mask with GTIOC2A signal */
#define _22_POE_MASK_GTIOC2B                (0x22U) /* Mask with GTIOC2B signal */
#define _23_POE_MASK_GTIOC3A                (0x23U) /* Mask with GTIOC3A signal */
#define _24_POE_MASK_GTIOC3B                (0x24U) /* Mask with GTIOC3B signal */
#define _25_POE_MASK_GTIOC4A                (0x25U) /* Mask with GTIOC4A signal */
#define _26_POE_MASK_GTIOC4B                (0x26U) /* Mask with GTIOC4B signal */
#define _27_POE_MASK_GTIOC5A                (0x27U) /* Mask with GTIOC5A signal */
#define _28_POE_MASK_GTIOC5B                (0x28U) /* Mask with GTIOC5B signal */
#define _29_POE_MASK_GTIOC6A                (0x29U) /* Mask with GTIOC6A signal */
#define _2A_POE_MASK_GTIOC6B                (0x2AU) /* Mask with GTIOC6B signal */
#define _2B_POE_MASK_GTIOC7A                (0x2BU) /* Mask with GTIOC7A signal */
#define _2C_POE_MASK_GTIOC7B                (0x2CU) /* Mask with GTIOC7B signal */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
