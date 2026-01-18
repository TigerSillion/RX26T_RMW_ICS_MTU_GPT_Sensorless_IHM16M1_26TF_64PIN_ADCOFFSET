/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_s12ad.h
* Version          : 1.0.100
* Device(s)        : R5F526TFCxFM
* Description      : General header file for S12AD peripheral.
***********************************************************************************************************************/

#ifndef S12AD_H
#define S12AD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    A/D Control Register (ADCSR)
*/
/* Double Trigger Channel Select (DBLANS) */
#define _0000_AD_DBCHANNEL_ANx00             (0x0000U) /* ANx00 is used for double trigger mode */
#define _0001_AD_DBCHANNEL_ANx01             (0x0001U) /* ANx01 is used for double trigger mode */
#define _0002_AD_DBCHANNEL_ANx02             (0x0002U) /* ANx02 is used for double trigger mode */
#define _0003_AD_DBCHANNEL_ANx03             (0x0003U) /* ANx03 is used for double trigger mode */
#define _0004_AD_DBCHANNEL_ANx04             (0x0004U) /* ANx04 is used for double trigger mode */
#define _0005_AD_DBCHANNEL_ANx05             (0x0005U) /* ANx05 is used for double trigger mode */
#define _0006_AD_DBCHANNEL_ANx06             (0x0006U) /* ANx06 is used for double trigger mode */
#define _0007_AD_DBCHANNEL_ANx07             (0x0007U) /* ANx07 is used for double trigger mode */
#define _0008_AD_DBCHANNEL_ANx08             (0x0008U) /* ANx08 is used for double trigger mode */
#define _0009_AD_DBCHANNEL_ANx09             (0x0009U) /* ANx09 is used for double trigger mode */
#define _000A_AD_DBCHANNEL_ANx10             (0x000AU) /* ANx10 is used for double trigger mode */
#define _000B_AD_DBCHANNEL_ANx11             (0x000BU) /* ANx11 is used for double trigger mode */
#define _0010_AD_DBCHANNEL_ANx16             (0x0010U) /* ANx16 is used for double trigger mode */
#define _0011_AD_DBCHANNEL_ANx17             (0x0011U) /* ANx17 is used for double trigger mode */
/* Group B Scan End Interrupt Enable (GBADIE) */
#define _0000_AD_GBADI_DISABLE               (0x0000U) /* Disable S12GBADI interrupt generation upon group B scan
                                                          completion */
#define _0040_AD_GBADI_ENABLE                (0x0040U) /* Enable S12GBADI interrupt generation upon group B scan
                                                          completion */
/* Double Trigger Mode Select (DBLE) */
#define _0000_AD_DBLTRIGGER_DISABLE          (0x0000U) /* Disable double trigger mode */
#define _0080_AD_DBLTRIGGER_ENABLE           (0x0080U) /* Enable double trigger mode */
/* Trigger Select (EXTRG) */
#define _0000_AD_SYNC_TRIGGER                (0x0000U) /* A/D conversion started by synchronous trigger */
#define _0100_AD_ASYNC_TRIGGER               (0x0100U) /* A/D conversion started by asynchronous trigger */
/* Trigger Start Enable (TRGE) */
#define _0000_AD_SYNCASYNCTRG_DISABLE        (0x0000U) /* A/D conversion synchronous or asynchronous trigger disable */
#define _0200_AD_SYNCASYNCTRG_ENABLE         (0x0200U) /* A/D conversion synchronous or asynchronous trigger enable */
/* Scan End Interrupt Enable (ADIE) */
#define _0000_AD_SCAN_END_INTERRUPT_DISABLE  (0x0000U) /* Disable S12ADI interrupt generation upon scan completion */
#define _1000_AD_SCAN_END_INTERRUPT_ENABLE   (0x1000U) /* Enable S12ADI interrupt generation upon scan completion */
/* Scan Mode Select (ADCS) */
#define _0000_AD_SINGLE_SCAN_MODE            (0x0000U) /* Single scan mode */
#define _2000_AD_GROUP_SCAN_MODE             (0x2000U) /* Group scan mode */
#define _4000_AD_CONTINUOUS_SCAN_MODE        (0x4000U) /* Continuous scan mode */
/* A/D Conversion Start (ADST) */
#define _0000_AD_CONVERSION_STOP             (0x0000U) /* Stop A/D conversion */
#define _8000_AD_CONVERSION_START            (0x8000U) /* Start A/D conversion */

/*
    A/D Channel Select Register A0 (ADANSA0)
*/
#define _0001_AD_ANx00_USED                  (0x0001U) /* ANx00 is subjected to conversion */
#define _0001_AD_ANx00_GROUPA_USED           (0x0001U) /* ANx00 is subjected to group A conversion */
#define _0002_AD_ANx01_USED                  (0x0002U) /* ANx01 is subjected to conversion */
#define _0002_AD_ANx01_GROUPA_USED           (0x0002U) /* ANx01 is subjected to group A conversion */
#define _0004_AD_ANx02_USED                  (0x0004U) /* ANx02 is subjected to conversion */
#define _0004_AD_ANx02_GROUPA_USED           (0x0004U) /* ANx02 is subjected to group A conversion */
#define _0008_AD_ANx03_USED                  (0x0008U) /* ANx03 is subjected to conversion */
#define _0008_AD_ANx03_GROUPA_USED           (0x0008U) /* ANx03 is subjected to group A conversion */
#define _0010_AD_ANx04_USED                  (0x0010U) /* ANx04 is subjected to conversion */
#define _0010_AD_ANx04_GROUPA_USED           (0x0010U) /* ANx04 is subjected to group A conversion */
#define _0020_AD_ANx05_USED                  (0x0020U) /* ANx05 is subjected to conversion */
#define _0020_AD_ANx05_GROUPA_USED           (0x0020U) /* ANx05 is subjected to group A conversion */
#define _0040_AD_ANx06_USED                  (0x0040U) /* ANx06 is subjected to conversion */
#define _0040_AD_ANx06_GROUPA_USED           (0x0040U) /* ANx06 is subjected to group A conversion */
#define _0080_AD_ANx07_USED                  (0x0080U) /* ANx07 is subjected to conversion */
#define _0080_AD_ANx07_GROUPA_USED           (0x0080U) /* ANx07 is subjected to group A conversion */
#define _0100_AD_ANx08_USED                  (0x0100U) /* ANx08 is subjected to conversion */
#define _0100_AD_ANx08_GROUPA_USED           (0x0100U) /* ANx08 is subjected to group A conversion */
#define _0200_AD_ANx09_USED                  (0x0200U) /* ANx09 is subjected to conversion */
#define _0200_AD_ANx09_GROUPA_USED           (0x0200U) /* ANx09 is subjected to group A conversion */
#define _0400_AD_ANx10_USED                  (0x0400U) /* ANx10 is subjected to conversion */
#define _0400_AD_ANx10_GROUPA_USED           (0x0400U) /* ANx10 is subjected to group A conversion */
#define _0800_AD_ANx11_USED                  (0x0800U) /* ANx11 is subjected to conversion */
#define _0800_AD_ANx11_GROUPA_USED           (0x0800U) /* ANx11 is subjected to group A conversion */

/*
    A/D Channel Select Register A1 (ADANSA1)
*/
#define _0001_AD_ANx16_USED                  (0x0001U) /* ANx16 is subjected to conversion */
#define _0001_AD_ANx16_GROUPA_USED           (0x0001U) /* ANx16 is subjected to group A conversion */
#define _0002_AD_ANx17_USED                  (0x0002U) /* ANx17 is subjected to conversion */
#define _0002_AD_ANx17_GROUPA_USED           (0x0002U) /* ANx17 is subjected to group A conversion */

/*
    A/D Channel Select Register B0 (ADANSB0)
*/
#define _0001_AD_ANx00_GROUPB_USED           (0x0001U) /* ANx00 is subjected to group B conversion */
#define _0002_AD_ANx01_GROUPB_USED           (0x0002U) /* ANx01 is subjected to group B conversion */
#define _0004_AD_ANx02_GROUPB_USED           (0x0004U) /* ANx02 is subjected to group B conversion */
#define _0008_AD_ANx03_GROUPB_USED           (0x0008U) /* ANx03 is subjected to group B conversion */
#define _0010_AD_ANx04_GROUPB_USED           (0x0010U) /* ANx04 is subjected to group B conversion */
#define _0020_AD_ANx05_GROUPB_USED           (0x0020U) /* ANx05 is subjected to group B conversion */
#define _0040_AD_ANx06_GROUPB_USED           (0x0040U) /* ANx06 is subjected to group B conversion */
#define _0080_AD_ANx07_GROUPB_USED           (0x0080U) /* ANx07 is subjected to group B conversion */
#define _0100_AD_ANx08_GROUPB_USED           (0x0100U) /* ANx08 is subjected to group B conversion */
#define _0200_AD_ANx09_GROUPB_USED           (0x0200U) /* ANx09 is subjected to group B conversion */
#define _0400_AD_ANx10_GROUPB_USED           (0x0400U) /* ANx10 is subjected to group B conversion */
#define _0800_AD_ANx11_GROUPB_USED           (0x0800U) /* ANx11 is subjected to group B conversion */

/*
    A/D Channel Select Register B1 (ADANSB1)
*/
#define _0001_AD_ANx16_GROUPB_USED           (0x0001U) /* ANx16 is subjected to group B conversion */
#define _0002_AD_ANx17_GROUPB_USED           (0x0002U) /* ANx17 is subjected to group B conversion */

/*
    A/D Channel Select Register C0 (ADANSC0)
*/
#define _0001_AD_ANx00_GROUPC_USED           (0x0001U) /* ANx00 is subjected to group C conversion */
#define _0002_AD_ANx01_GROUPC_USED           (0x0002U) /* ANx01 is subjected to group C conversion */
#define _0004_AD_ANx02_GROUPC_USED           (0x0004U) /* ANx02 is subjected to group C conversion */
#define _0008_AD_ANx03_GROUPC_USED           (0x0008U) /* ANx03 is subjected to group C conversion */
#define _0010_AD_ANx04_GROUPC_USED           (0x0010U) /* ANx04 is subjected to group C conversion */
#define _0020_AD_ANx05_GROUPC_USED           (0x0020U) /* ANx05 is subjected to group C conversion */
#define _0040_AD_ANx06_GROUPC_USED           (0x0040U) /* ANx06 is subjected to group C conversion */
#define _0080_AD_ANx07_GROUPC_USED           (0x0080U) /* ANx07 is subjected to group C conversion */
#define _0100_AD_ANx08_GROUPC_USED           (0x0100U) /* ANx08 is subjected to group C conversion */
#define _0200_AD_ANx09_GROUPC_USED           (0x0200U) /* ANx09 is subjected to group C conversion */
#define _0400_AD_ANx10_GROUPC_USED           (0x0400U) /* ANx10 is subjected to group C conversion */
#define _0800_AD_ANx11_GROUPC_USED           (0x0800U) /* ANx11 is subjected to group C conversion */

/*
    A/D Channel Select Register C1 (ADANSC1)
*/
#define _0001_AD_ANx16_GROUPC_USED           (0x0001U) /* ANx16 is subjected to group C conversion */
#define _0002_AD_ANx17_GROUPC_USED           (0x0002U) /* ANx17 is subjected to group C conversion */

/*
    A/D-Converted Value Addition/Average Function Channel Select Register 0 (ADADS0)
*/
#define _0001_AD_ANx00_ADD_USED              (0x0001U) /* ANx00 is selected to addition/average mode */
#define _0002_AD_ANx01_ADD_USED              (0x0002U) /* ANx01 is selected to addition/average mode */
#define _0004_AD_ANx02_ADD_USED              (0x0004U) /* ANx02 is selected to addition/average mode */
#define _0008_AD_ANx03_ADD_USED              (0x0008U) /* ANx03 is selected to addition/average mode */
#define _0010_AD_ANx04_ADD_USED              (0x0010U) /* ANx04 is selected to addition/average mode */
#define _0020_AD_ANx05_ADD_USED              (0x0020U) /* ANx05 is selected to addition/average mode */
#define _0040_AD_ANx06_ADD_USED              (0x0040U) /* ANx06 is selected to addition/average mode */
#define _0080_AD_ANx07_ADD_USED              (0x0080U) /* ANx07 is selected to addition/average mode */
#define _0100_AD_ANx08_ADD_USED              (0x0100U) /* ANx08 is selected to addition/average mode */
#define _0200_AD_ANx09_ADD_USED              (0x0200U) /* ANx09 is selected to addition/average mode */
#define _0400_AD_ANx10_ADD_USED              (0x0400U) /* ANx10 is selected to addition/average mode */
#define _0800_AD_ANx11_ADD_USED              (0x0800U) /* ANx11 is selected to addition/average mode */

/*
    A/D-Converted Value Addition/Average Function Select Register 1 (ADADS1)
*/
#define _0001_AD_ANx16_ADD_USED              (0x0001U) /* ANx16 is selected to addition/average mode */
#define _0002_AD_ANx17_ADD_USED              (0x0002U) /* ANx17 is selected to addition/average mode */

/*
    A/D-Converted Value Addition/Average Count Select Register (ADADC)
*/
/* Addition Count Select (ADC) */
#define _00_AD_1_TIME_CONVERSION             (0x00U)   /* 1-time conversion */
#define _01_AD_2_TIME_CONVERSION             (0x01U)   /* 2-time conversion */
#define _02_AD_3_TIME_CONVERSION             (0x02U)   /* 3-time conversion */
#define _03_AD_4_TIME_CONVERSION             (0x03U)   /* 4-time conversion */
#define _05_AD_16_TIME_CONVERSION            (0x05U)   /* 16-time conversion */
/* Average Mode Enable (AVEE) */
#define _00_AD_ADDITION_MODE                 (0x00U)   /* Addition mode */
#define _80_AD_AVERAGE_MODE                  (0x80U)   /* Average mode */

/*
    A/D Control Extended Register (ADCER)
*/
/* A/D Data Register Automatic Clearing Enable (ACE) */
#define _0000_AD_AUTO_CLEARING_DISABLE       (0x0000U) /* Disable auto clearing */
#define _0020_AD_AUTO_CLEARING_ENABLE        (0x0020U) /* Enable auto clearing */
/* A/D Data Register Automatic Setting Enable (ASE) */
#define _0000_AD_AUTO_SETTING_DISABLE        (0x0000U) /* Disable auto setting */
#define _0040_AD_AUTO_SETTING_ENABLE         (0x0040U) /* Enable auto setting */
/* Self-Diagnosis Conversion Voltage Select (DIAGVAL) */
#define _0100_AD_SELFTDIAGST_0V              (0x0100U) /* Self-diagnosis using a voltage of 0V */
#define _0200_AD_SELFTDIAGST_AVCC_HALF       (0x0200U) /* Self-diagnosis using a voltage of AVCC_1/2 */
#define _0300_AD_SELFTDIAGST_AVCC            (0x0300U) /* Self-diagnosis using a voltage of AVCC_1 */
/* Self-Diagnosis Mode Select (DIAGLD) */
#define _0000_AD_SELFTDIAGST_ROTATION        (0x0000U) /* Rotation mode for self-diagnosis voltage */
#define _0400_AD_SELFTDIAGST_FIX             (0x0400U) /* Fixed mode for self-diagnosis voltage */
/* Self-Diagnosis Enable (DIAGM) */
#define _0000_AD_SELFTDIAGST_DISABLE         (0x0000U) /* 12-bit A/D converter self-diagnosis disable */
#define _0800_AD_SELFTDIAGST_ENABLE          (0x0800U) /* 12-bit A/D converter self-diagnosis enable */
/* A/D Data Register Format Select (ADRFMT) */
#define _0000_AD_RIGHT_ALIGNMENT             (0x0000U) /* Right-alignment for data register format */
#define _8000_AD_LEFT_ALIGNMENT              (0x8000U) /* Left-alignment for data register format */

/*
    A/D Conversion Start Trigger Select Register (ADSTRGR)
*/
/* A/D Conversion Start Trigger Select for Group B (TRSB) */
#define _0001_AD_TRSB_TRGA0N                 (0x0001U) /* Compare match/input capture in MTU0.TGRA */
#define _0002_AD_TRSB_TRGA1N                 (0x0002U) /* Compare match/input capture in MTU1.TGRA */
#define _0003_AD_TRSB_TRGA2N                 (0x0003U) /* Compare match/input capture in MTU2.TGRA */
#define _0004_AD_TRSB_TRGA3N                 (0x0004U) /* Compare match/input capture in MTU3.TGRA */
#define _0005_AD_TRSB_TRGA4N                 (0x0005U) /* Compare match/input capture in MTU4.TGRA or
                                                          underflow (trough) of MTU4.TCNT in complementary PWM mode */
#define _0006_AD_TRSB_TRGA6N                 (0x0006U) /* Compare match/input capture in MTU6.TGRA */
#define _0007_AD_TRSB_TRGA7N                 (0x0007U) /* Compare match/input capture in MTU7.TGRA or
                                                          underflow (trough) of MTU7.TCNT in complementary PWM mode */
#define _0008_AD_TRSB_TRG0N                  (0x0008U) /* Compare match in MTU0.TGRE */
#define _0009_AD_TRSB_TRG4AN                 (0x0009U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _000A_AD_TRSB_TRG4BN                 (0x000AU) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _000B_AD_TRSB_TRG4AN_TRG4BN          (0x000BU) /* Compare match between MTU4.TADCORA and MTU4.TCNT, or compare
                                                          match between MTU4.TADCORB and MTU4.TCNT */
#define _000C_AD_TRSB_TRG4ABN                (0x000CU) /* Compare match between MTU4.TADCORA and MTU4.TCNT, and compare
                                                          match between MTU4.TADCORB and MTU4.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _000D_AD_TRSB_TRG7AN                 (0x000DU) /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _000E_AD_TRSB_TRG7BN                 (0x000EU) /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _000F_AD_TRSB_TRG7AN_TRG7BN          (0x000FU) /* Compare match between MTU7.TADCORA and MTU7.TCNT, or compare
                                                          match between MTU7.TADCORB and MTU7.TCNT */
#define _0010_AD_TRSB_TRG7ABN                (0x0010U) /* Compare match between MTU7.TADCORA and MTU7.TCNT, and compare
                                                          match between MTU7.TADCORB and MTU7.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _0013_AD_TRSB_TRGA9N                 (0x0013U) /* Compare match/input capture in MTU9.TGRA */
#define _0014_AD_TRSB_TRG9N                  (0x0014U) /* Compare match in MTU9.TGRE */
#define _0019_AD_TRSB_TRGA0N_TRG0N           (0x0019U) /* Compare match/input capture in MTU0.TGRA, or compare match in
                                                          MTU0.TGRE */
#define _001A_AD_TRSB_TRGA9N_TRG9N           (0x001AU) /* Compare match/input capture in MTU9.TGRA, or compare match in
                                                          MTU9.TGRE */
#define _001B_AD_TRSB_TRGA0N_TRGA9N          (0x001BU) /* Compare match/input capture in MTU0.TGRA, or compare
                                                          match/input capture in MTU9.TGRA */
#define _001C_AD_TRSB_TRG0N_TRG9N            (0x001CU) /* Compare match in MTU0.TGRE, or compare match in MTU9.TGRE */
#define _0021_AD_TRSB_TRG9AEN                (0x0021U) /* Compare match/input capture in MTU9.TGRA, and compare match
                                                          in MTU9.TGRE */
#define _0022_AD_TRSB_TRG0AEN                (0x0022U) /* Compare match/input capture in MTU0.TGRA, and compare match
                                                          in MTU0.TGRE */
#define _0023_AD_TRSB_TRGA09N                (0x0023U) /* Compare match/input capture in MTU0.TGRA, and
                                                          compare match/input capture in MTU9.TGRA */
#define _0024_AD_TRSB_TRG09N                 (0x0024U) /* Compare match in MTU0.TGRE, and compare match in MTU9.TGRE */
#define _0040_AD_TRSB_GTADTRA0N              (0x0040U) /* Compare match in GPTW0.GTADTRA */
#define _0041_AD_TRSB_GTADTRB0N              (0x0041U) /* Compare match in GPTW0.GTADTRB */
#define _0042_AD_TRSB_GTADTRA1N              (0x0042U) /* Compare match in GPTW1.GTADTRA */
#define _0043_AD_TRSB_GTADTRB1N              (0x0043U) /* Compare match in GPTW1.GTADTRB */
#define _0044_AD_TRSB_GTADTRA2N              (0x0044U) /* Compare match in GPTW2.GTADTRA */
#define _0045_AD_TRSB_GTADTRB2N              (0x0045U) /* Compare match in GPTW2.GTADTRB */
#define _0046_AD_TRSB_GTADTRA3N              (0x0046U) /* Compare match in GPTW3.GTADTRA */
#define _0047_AD_TRSB_GTADTRB3N              (0x0047U) /* Compare match in GPTW3.GTADTRB */
#define _0048_AD_TRSB_GTADTRA0N_GTADTRB0N    (0x0048U) /* Compare match in GPTW0.GTADTRA, or compare match in
                                                          GPTW0.GTADTRB */
#define _0049_AD_TRSB_GTADTRA1N_GTADTRB1N    (0x0049U) /* Compare match in GPTW1.GTADTRA, or compare match in
                                                          GPTW1.GTADTRB */
#define _004A_AD_TRSB_GTADTRA2N_GTADTRB2N    (0x004AU) /* Compare match in GPTW2.GTADTRA, or compare match in
                                                          GPTW2.GTADTRB */
#define _004B_AD_TRSB_GTADTRA3N_GTADTRB3N    (0x004BU) /* Compare match in GPTW3.GTADTRA, or compare match in
                                                          GPTW3.GTADTRB */
#define _004C_AD_TRSB_GTADTRA4N              (0x004CU) /* Compare match in GPTW4.GTADTRA */
#define _004D_AD_TRSB_GTADTRB4N              (0x004DU) /* Compare match in GPTW4.GTADTRB */
#define _004E_AD_TRSB_GTADTRA5N              (0x004EU) /* Compare match in GPTW5.GTADTRA */
#define _004F_AD_TRSB_GTADTRB5N              (0x004FU) /* Compare match in GPTW5.GTADTRB */
#define _0050_AD_TRSB_GTADTRA6N              (0x0050U) /* Compare match in GPTW6.GTADTRA */
#define _0051_AD_TRSB_GTADTRB6N              (0x0051U) /* Compare match in GPTW6.GTADTRB */
#define _0052_AD_TRSB_GTADTRA7N              (0x0052U) /* Compare match in GPTW7.GTADTRA */
#define _0053_AD_TRSB_GTADTRB7N              (0x0053U) /* Compare match in GPTW7.GTADTRB */
#define _0054_AD_TRSB_GTADTRA4N_GTADTRB4N    (0x0054U) /* Compare match in GPTW4.GTADTRA, or compare match in
                                                          GPTW4.GTADTRB */
#define _0055_AD_TRSB_GTADTRA5N_GTADTRB5N    (0x0055U) /* Compare match in GPTW5.GTADTRA, or compare match in
                                                          GPTW5.GTADTRB */
#define _0056_AD_TRSB_GTADTRA6N_GTADTRB6N    (0x0056U) /* Compare match in GPTW6.GTADTRA, or compare match in
                                                          GPTW6.GTADTRB */
#define _0057_AD_TRSB_GTADTRA7N_GTADTRB7N    (0x0057U) /* Compare match in GPTW7.GTADTRA, or compare match in
                                                          GPTW7.GTADTRB */
#define _001D_AD_TRSB_TMTRG0AN_0             (0x001DU) /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _001E_AD_TRSB_TMTRG0AN_1             (0x001EU) /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _001F_AD_TRSB_TMTRG0AN_2             (0x001FU) /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _0020_AD_TRSB_TMTRG0AN_3             (0x0020U) /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _0032_AD_TRSB_ELCTRGX0N              (0x0032U) /* A/D Startup source 0 from ELC */
#define _0033_AD_TRSB_ELCTRGX1N              (0x0033U) /* A/D Startup source 1 from ELC */
#define _003A_AD_TRSB_ELCTRGX01N             (0x003AU) /* A/D Startup source 0 from ELC, or A/D Startup source 1 from
                                                          ELC */
/* A/D Conversion Start Trigger Select (TRSA) */
#define _0000_AD_TRSA_ADTRG                  (0x0000U) /* A/D conversion start trigger pin */
#define _0100_AD_TRSA_TRGA0N                 (0x0100U) /* Compare match/input capture in MTU0.TGRA */
#define _0200_AD_TRSA_TRGA1N                 (0x0200U) /* Compare match/input capture in MTU1.TGRA */
#define _0300_AD_TRSA_TRGA2N                 (0x0300U) /* Compare match/input capture in MTU2.TGRA */
#define _0400_AD_TRSA_TRGA3N                 (0x0400U) /* Compare match/input capture in MTU3.TGRA */
#define _0500_AD_TRSA_TRGA4N                 (0x0500U) /* Compare match/input capture in MTU4.TGRA or
                                                          underflow (trough) of MTU4.TCNT in complementary PWM mode */
#define _0600_AD_TRSA_TRGA6N                 (0x0600U) /* Compare match/input capture in MTU6.TGRA */
#define _0700_AD_TRSA_TRGA7N                 (0x0700U) /* Compare match/input capture in MTU7.TGRA or
                                                          underflow (trough) of MTU7.TCNT in complementary PWM mode */
#define _0800_AD_TRSA_TRG0N                  (0x0800U) /* Compare match in MTU0.TGRE */
#define _0900_AD_TRSA_TRG4AN                 (0x0900U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0A00_AD_TRSA_TRG4BN                 (0x0A00U) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0B00_AD_TRSA_TRG4AN_TRG4BN          (0x0B00U) /* Compare match between MTU4.TADCORA and MTU4.TCNT, or compare
                                                          match between MTU4.TADCORB and MTU4.TCNT */
#define _0C00_AD_TRSA_TRG4ABN                (0x0C00U) /* Compare match between MTU4.TADCORA and MTU4.TCNT, and compare
                                                          match between MTU4.TADCORB and MTU4.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _0D00_AD_TRSA_TRG7AN                 (0x0D00U) /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _0E00_AD_TRSA_TRG7BN                 (0x0E00U) /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _0F00_AD_TRSA_TRG7AN_TRG7BN          (0x0F00U) /* Compare match between MTU7.TADCORA and MTU7.TCNT, or compare
                                                          match between MTU7.TADCORB and MTU7.TCNT */
#define _1000_AD_TRSA_TRG7ABN                (0x1000U) /* Compare match between MTU7.TADCORA and MTU7.TCNT, and compare
                                                          match between MTU7.TADCORB and MTU7.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _1300_AD_TRSA_TRGA9N                 (0x1300U) /* Compare match/input capture in MTU9.TGRA */
#define _1400_AD_TRSA_TRG9N                  (0x1400U) /* Compare match in MTU9.TGRE */
#define _1900_AD_TRSA_TRGA0N_TRG0N           (0x1900U) /* Compare match/input capture in MTU0.TGRA, or compare match in
                                                          MTU0.TGRE */
#define _1A00_AD_TRSA_TRGA9N_TRG9N           (0x1A00U) /* Compare match/input capture in MTU9.TGRA, or compare match in
                                                          MTU9.TGRE */
#define _1B00_AD_TRSA_TRGA0N_TRGA9N          (0x1B00U) /* Compare match/input capture in MTU0.TGRA, or compare
                                                          match/input capture in MTU9.TGRA */
#define _1C00_AD_TRSA_TRG0N_TRG9N            (0x1C00U) /* Compare match in MTU0.TGRE, or compare match in MTU9.TGRE */
#define _2100_AD_TRSA_TRG9AEN                (0x2100U) /* Compare match/input capture in MTU9.TGRA, and compare match
                                                          in MTU9.TGRE */
#define _2200_AD_TRSA_TRG0AEN                (0x2200U) /* Compare match/input capture in MTU0.TGRA, and compare match
                                                          in MTU0.TGRE */
#define _2300_AD_TRSA_TRGA09N                (0x2300U) /* Compare match/input capture in MTU0.TGRA, and
                                                          compare match/input capture in MTU9.TGRA */
#define _2400_AD_TRSA_TRG09N                 (0x2400U) /* Compare match in MTU0.TGRE, and compare match in MTU9.TGRE */
#define _4000_AD_TRSA_GTADTRA0N              (0x4000U) /* Compare match in GPTW0.GTADTRA */
#define _4100_AD_TRSA_GTADTRB0N              (0x4100U) /* Compare match in GPTW0.GTADTRB */
#define _4200_AD_TRSA_GTADTRA1N              (0x4200U) /* Compare match in GPTW1.GTADTRA */
#define _4300_AD_TRSA_GTADTRB1N              (0x4300U) /* Compare match in GPTW1.GTADTRB */
#define _4400_AD_TRSA_GTADTRA2N              (0x4400U) /* Compare match in GPTW2.GTADTRA */
#define _4500_AD_TRSA_GTADTRB2N              (0x4500U) /* Compare match in GPTW2.GTADTRB */
#define _4600_AD_TRSA_GTADTRA3N              (0x4600U) /* Compare match in GPTW3.GTADTRA */
#define _4700_AD_TRSA_GTADTRB3N              (0x4700U) /* Compare match in GPTW3.GTADTRB */
#define _4800_AD_TRSA_GTADTRA0N_GTADTRB0N    (0x4800U) /* Compare match in GPTW0.GTADTRA, or compare match in
                                                          GPTW0.GTADTRB */
#define _4900_AD_TRSA_GTADTRA1N_GTADTRB1N    (0x4900U) /* Compare match in GPTW1.GTADTRA, or compare match in
                                                          GPTW1.GTADTRB */
#define _4A00_AD_TRSA_GTADTRA2N_GTADTRB2N    (0x4A00U) /* Compare match in GPTW2.GTADTRA, or compare match in
                                                          GPTW2.GTADTRB */
#define _4B00_AD_TRSA_GTADTRA3N_GTADTRB3N    (0x4B00U) /* Compare match in GPTW3.GTADTRA, or compare match in
                                                          GPTW3.GTADTRB */
#define _4C00_AD_TRSA_GTADTRA4N              (0x4C00U) /* Compare match in GPTW4.GTADTRA */
#define _4D00_AD_TRSA_GTADTRB4N              (0x4D00U) /* Compare match in GPTW4.GTADTRB */
#define _4E00_AD_TRSA_GTADTRA5N              (0x4E00U) /* Compare match in GPTW5.GTADTRA */
#define _4F00_AD_TRSA_GTADTRB5N              (0x4F00U) /* Compare match in GPTW5.GTADTRB */
#define _5000_AD_TRSA_GTADTRA6N              (0x5000U) /* Compare match in GPTW6.GTADTRA */
#define _5100_AD_TRSA_GTADTRB6N              (0x5100U) /* Compare match in GPTW6.GTADTRB */
#define _5200_AD_TRSA_GTADTRA7N              (0x5200U) /* Compare match in GPTW7.GTADTRA */
#define _5300_AD_TRSA_GTADTRB7N              (0x5300U) /* Compare match in GPTW7.GTADTRB */
#define _5400_AD_TRSA_GTADTRA4N_GTADTRB4N    (0x5400U) /* Compare match in GPTW4.GTADTRA, or compare match in
                                                          GPTW4.GTADTRB */
#define _5500_AD_TRSA_GTADTRA5N_GTADTRB5N    (0x5500U) /* Compare match in GPTW5.GTADTRA, or compare match in
                                                          GPTW5.GTADTRB */
#define _5600_AD_TRSA_GTADTRA6N_GTADTRB6N    (0x5600U) /* Compare match in GPTW6.GTADTRA, or compare match in
                                                          GPTW6.GTADTRB */
#define _5700_AD_TRSA_GTADTRA7N_GTADTRB7N    (0x5700U) /* Compare match in GPTW7.GTADTRA, or compare match in
                                                          GPTW7.GTADTRB */
#define _1D00_AD_TRSA_TMTRG0AN_0             (0x1D00U) /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _1E00_AD_TRSA_TMTRG0AN_1             (0x1E00U) /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _1F00_AD_TRSA_TMTRG0AN_2             (0x1F00U) /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _2000_AD_TRSA_TMTRG0AN_3             (0x2000U) /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _3200_AD_TRSA_ELCTRGX0N              (0x3200U) /* A/D Startup source 0 from ELC */
#define _3300_AD_TRSA_ELCTRGX1N              (0x3300U) /* A/D Startup source 1 from ELC */
#define _3A00_AD_TRSA_ELCTRGX01N             (0x3A00U) /* A/D Startup source 0 from ELC, or A/D Startup source 1 from
                                                          ELC */
/*
    A/D Conversion Extended Input Control Register (ADEXICR)
*/
/* Temperature Sensor Output A/D Converted Value Addition/Averaging Mode Select (TSSAD) */
#define _0000_AD_TEMP_ADD_UNUSED             (0x0000U) /* Temperature sensor output A/D converted value addition/average
                                                          mode disabled */
#define _0001_AD_TEMP_ADD_USED               (0x0001U) /* Temperature sensor output A/D converted value addition/average
                                                          mode enabled */
/* Internal Reference Voltage A/D Converted Value Addition/Average Mode Select (OCSAD) */
#define _0000_AD_IREF_ADD_UNUSED             (0x0000U) /* Internal ref. voltage A/D converted value addition/average
                                                          mode disabled */
#define _0002_AD_IREF_ADD_USED               (0x0002U) /* Internal ref. voltage A/D converted value addition/average
                                                          mode enabled */
/* Temperature Sensor Output A/D Conversion Select (TSSA) */
#define _0000_AD_TEMP_UNUSED                 (0x0000U) /* A/D conversion of temperature sensor output is disabled */
#define _0100_AD_TEMP_USED                   (0x0100U) /* A/D conversion of temperature sensor output is enabled */
#define _0100_AD_TEMP_GROUPA_USED            (0x0100U) /* A/D conversion of temperature sensor output is enabled in
                                                          group A */
/* Internal Reference Voltage A/D Conversion Select (OCSA) */
#define _0000_AD_IREF_UNUSED                 (0x0000U) /* A/D conversion of internal reference voltage is disabled */
#define _0200_AD_IREF_USED                   (0x0200U) /* A/D conversion of internal reference voltage is enabled */
#define _0200_AD_IREF_GROUPA_USED            (0x0200U) /* A/D conversion of internal reference voltage is enabled in
                                                          group A */
/* Group B Temperature Sensor Output A/D Conversion Select (TSSB) */
#define _0000_AD_TEMP_GROUPB_UNUSED          (0x0000U) /* A/D conversion of temperature sensor output is disabled in
                                                          group B */
#define _0400_AD_TEMP_GROUPB_USED            (0x0400U) /* A/D conversion of temperature sensor output is enabled in
                                                          group B */
/* Group B Internal Reference Voltage A/D Conversion Select (OCSB) */
#define _0000_AD_IREF_GROUPB_UNUSED          (0x0000U) /* A/D conversion of internal reference voltage is disabled in
                                                          group B */
#define _0800_AD_IREF_GROUPB_USED            (0x0800U) /* A/D conversion of internal reference voltage is enabled in
                                                          group B */

/*
    A/D Group C Extended Input Control Register (ADGCEXCR)
*/
/* Group C Temperature Sensor Output A/D Conversion Select (TSSC) */
#define _00_AD_TEMP_GROUPC_UNUSED            (0x00U)   /* A/D conversion of temperature sensor output is disabled in
                                                          group C */
#define _01_AD_TEMP_GROUPC_USED              (0x01U)   /* A/D conversion of temperature sensor output is enabled in
                                                          group C */
/* Group C Internal Reference Voltage A/D Conversion Select (OCSC) */
#define _00_AD_IREF_GROUPC_UNUSED            (0x00U)   /* A/D conversion of internal reference voltage is disabled in
                                                          group C */
#define _02_AD_IREF_GROUPC_USED              (0x02U)   /* A/D conversion of internal reference voltage is enabled in
                                                          group C */

/*
    A/D Group C Trigger Select Register (ADGCTRGR)
*/
/* Group C A/D Conversion Start Trigger Select (TRSC) */
#define _01_AD_TRSC_TRGA0N                   (0x01U)   /* Compare match/input capture in MTU0.TGRA */
#define _02_AD_TRSC_TRGA1N                   (0x02U)   /* Compare match/input capture in MTU1.TGRA */
#define _03_AD_TRSC_TRGA2N                   (0x03U)   /* Compare match/input capture in MTU2.TGRA */
#define _04_AD_TRSC_TRGA3N                   (0x04U)   /* Compare match/input capture in MTU3.TGRA */
#define _05_AD_TRSC_TRGA4N                   (0x05U)   /* Compare match/input capture in MTU4.TGRA or
                                                          underflow (trough) of MTU4.TCNT in complementary PWM mode */
#define _06_AD_TRSC_TRGA6N                   (0x06U)   /* Compare match/input capture in MTU6.TGRA */
#define _07_AD_TRSC_TRGA7N                   (0x07U)   /* Compare match/input capture in MTU7.TGRA or
                                                          underflow (trough) of MTU7.TCNT in complementary PWM mode */
#define _08_AD_TRSC_TRG0N                    (0x08U)   /* Compare match in MTU0.TGRE */
#define _09_AD_TRSC_TRG4AN                   (0x09U)   /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0A_AD_TRSC_TRG4BN                   (0x0AU)   /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0B_AD_TRSC_TRG4AN_TRG4BN            (0x0BU)   /* Compare match between MTU4.TADCORA and MTU4.TCNT, or compare
                                                          match between MTU4.TADCORB and MTU4.TCNT */
#define _0C_AD_TRSC_TRG4ABN                  (0x0CU)   /* Compare match between MTU4.TADCORA and MTU4.TCNT, and compare
                                                          match between MTU4.TADCORB and MTU4.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _0D_AD_TRSC_TRG7AN                   (0x0DU)   /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _0E_AD_TRSC_TRG7BN                   (0x0EU)   /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _0F_AD_TRSC_TRG7AN_TRG7BN            (0x0FU)   /* Compare match between MTU7.TADCORA and MTU7.TCNT, or compare
                                                          match between MTU7.TADCORB and MTU7.TCNT */
#define _10_AD_TRSC_TRG7ABN                  (0x10U)   /* Compare match between MTU7.TADCORA and MTU7.TCNT, and compare
                                                          match between MTU7.TADCORB and MTU7.TCNT (when interrupt
                                                          skipping function 2 is used) */
#define _13_AD_TRSC_TRGA9N                   (0x13U)   /* Compare match/input capture in MTU9.TGRA */
#define _14_AD_TRSC_TRG9N                    (0x14U)   /* Compare match in MTU9.TGRE */
#define _19_AD_TRSC_TRGA0N_TRG0N             (0x19U)   /* Compare match/input capture in MTU0.TGRA, or compare match in
                                                          MTU0.TGRE */
#define _1A_AD_TRSC_TRGA9N_TRG9N             (0x1AU)   /* Compare match/input capture in MTU9.TGRA, or compare match in
                                                          MTU9.TGRE */
#define _1B_AD_TRSC_TRGA0N_TRGA9N            (0x1BU)   /* Compare match/input capture in MTU0.TGRA, or compare
                                                          match/input capture in MTU9.TGRA */
#define _1C_AD_TRSC_TRG0N_TRG9N              (0x1CU)   /* Compare match in MTU0.TGRE, or compare match in MTU9.TGRE */
#define _21_AD_TRSC_TRG9AEN                  (0x21U)   /* Compare match/input capture in MTU9.TGRA, and compare match
                                                          in MTU9.TGRE */
#define _22_AD_TRSC_TRG0AEN                  (0x22U)   /* Compare match/input capture in MTU0.TGRA, and compare match
                                                          in MTU0.TGRE */
#define _23_AD_TRSC_TRGA09N                  (0x23U)   /* Compare match/input capture in MTU0.TGRA, and
                                                          compare match/input capture in MTU9.TGRA */
#define _24_AD_TRSC_TRG09N                   (0x24U)   /* Compare match in MTU0.TGRE, and compare match in MTU9.TGRE */
#define _00_AD_TRSC_GTADTRA0N                (0x00U)   /* Compare match in GPTW0.GTADTRA */
#define _01_AD_TRSC_GTADTRB0N                (0x01U)   /* Compare match in GPTW0.GTADTRB */
#define _02_AD_TRSC_GTADTRA1N                (0x02U)   /* Compare match in GPTW1.GTADTRA */
#define _03_AD_TRSC_GTADTRB1N                (0x03U)   /* Compare match in GPTW1.GTADTRB */
#define _04_AD_TRSC_GTADTRA2N                (0x04U)   /* Compare match in GPTW2.GTADTRA */
#define _05_AD_TRSC_GTADTRB2N                (0x05U)   /* Compare match in GPTW2.GTADTRB */
#define _06_AD_TRSC_GTADTRA3N                (0x06U)   /* Compare match in GPTW3.GTADTRA */
#define _07_AD_TRSC_GTADTRB3N                (0x07U)   /* Compare match in GPTW3.GTADTRB */
#define _08_AD_TRSC_GTADTRA0N_GTADTRB0N      (0x08U)   /* Compare match in GPTW0.GTADTRA, or compare match in
                                                          GPTW0.GTADTRB */
#define _09_AD_TRSC_GTADTRA1N_GTADTRB1N      (0x09U)   /* Compare match in GPTW1.GTADTRA, or compare match in
                                                          GPTW1.GTADTRB */
#define _0A_AD_TRSC_GTADTRA2N_GTADTRB2N      (0x0AU)   /* Compare match in GPTW2.GTADTRA, or compare match in
                                                          GPTW2.GTADTRB */
#define _0B_AD_TRSC_GTADTRA3N_GTADTRB3N      (0x0BU)   /* Compare match in GPTW3.GTADTRA, or compare match in
                                                          GPTW3.GTADTRB */
#define _0C_AD_TRSC_GTADTRA4N                (0x0CU)   /* Compare match in GPTW4.GTADTRA */
#define _0D_AD_TRSC_GTADTRB4N                (0x0DU)   /* Compare match in GPTW4.GTADTRB */
#define _0E_AD_TRSC_GTADTRA5N                (0x0EU)   /* Compare match in GPTW5.GTADTRA */
#define _0F_AD_TRSC_GTADTRB5N                (0x0FU)   /* Compare match in GPTW5.GTADTRB */
#define _10_AD_TRSC_GTADTRA6N                (0x10U)   /* Compare match in GPTW6.GTADTRA */
#define _11_AD_TRSC_GTADTRB6N                (0x11U)   /* Compare match in GPTW6.GTADTRB */
#define _12_AD_TRSC_GTADTRA7N                (0x12U)   /* Compare match in GPTW7.GTADTRA */
#define _13_AD_TRSC_GTADTRB7N                (0x13U)   /* Compare match in GPTW7.GTADTRB */
#define _14_AD_TRSC_GTADTRA4N_GTADTRB4N      (0x14U)   /* Compare match in GPTW4.GTADTRA, or compare match in
                                                          GPTW4.GTADTRB */
#define _15_AD_TRSC_GTADTRA5N_GTADTRB5N      (0x15U)   /* Compare match in GPTW5.GTADTRA, or compare match in
                                                          GPTW5.GTADTRB */
#define _16_AD_TRSC_GTADTRA6N_GTADTRB6N      (0x16U)   /* Compare match in GPTW6.GTADTRA, or compare match in
                                                          GPTW6.GTADTRB */
#define _17_AD_TRSC_GTADTRA7N_GTADTRB7N      (0x17U)   /* Compare match in GPTW7.GTADTRA, or compare match in
                                                          GPTW7.GTADTRB */
#define _1D_AD_TRSC_TMTRG0AN_0               (0x1DU)   /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _1E_AD_TRSC_TMTRG0AN_1               (0x1EU)   /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _1F_AD_TRSC_TMTRG0AN_2               (0x1FU)   /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _20_AD_TRSC_TMTRG0AN_3               (0x20U)   /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _32_AD_TRSC_ELCTRGX0N                (0x32U)   /* A/D Startup source 0 from ELC */
#define _33_AD_TRSC_ELCTRGX1N                (0x33U)   /* A/D Startup source 1 from ELC */
#define _3A_AD_TRSC_ELCTRGX01N               (0x3AU)   /* A/D Startup source 0 from ELC, or A/D Startup source 1 from
                                                            ELC */
/* Group C Scan End Interrupt Enable (GCADIE) */
#define _00_AD_GCADI_DISABLE                 (0x00U)   /* Group C scan end interrupt is disabled */
#define _40_AD_GCADI_ENABLE                  (0x40U)   /* Group C scan end interrupt is enabled */
/* Group C A/D Conversion Operation Enable (GRCE) */
#define _00_AD_GROUPC_DISABLE                (0x00U)   /* A/D conversion operation for group C is disabled */
#define _80_AD_GROUPC_ENABLE                 (0x80U)   /* A/D conversion operation for group C is enabled */

/*
    A/D Group C Trigger Select Register 2 (ADGCTRGR2)
*/
/* Group C A/D Conversion Start Trigger Select (TRSC6) */
#define _00_AD_TRSC6_DISABLE                 (0x00U)   /* Combination with the ADGCTRGR register to select the A/D
                                                          conversion start trigger for group C */
#define _01_AD_TRSC6_ENABLE                  (0x01U)   /* Combination with the ADGCTRGR register to select the A/D
                                                          conversion start trigger for group C */

/*
    A/D Sample-and-Hold Circuit Control Register (ADSHCR)
*/
/*  Channel-Dedicated Sample-and-Hold Circuit Bypass Select (SHANS) */
#define _0100_AD_DSH_ANx00_SELECT            (0x0100U) /* ANx00 use the channel-dedicated sample-and-hold circuits */
#define _0200_AD_DSH_ANx01_SELECT            (0x0200U) /* ANx01 use the channel-dedicated sample-and-hold circuits */
#define _0400_AD_DSH_ANx02_SELECT            (0x0400U) /* ANx02 use the channel-dedicated sample-and-hold circuits */

/*
    A/D Sample-and-Hold Operating Mode Select Register (ADSHMSR)
*/
/*  Channel-Dedicated Sample-and-Hold Circuit Operating Mode Setting (SHMD) */
#define _00_AD_DSH_CONST_SAMPL_DISABLE       (0x00U)   /* Constant sampling of the channel-dedicated sample-and-hold
                                                          circuits is disabled */
#define _01_AD_DSH_CONST_SAMPL_ENABLE        (0x01U)   /* Constant sampling of the channel-dedicated sample-andhold
                                                          circuits is enabled */

/*
    A/D Disconnection Detection Control Register (ADDISCR)
*/
#define _00_AD_DISCONECT_UNUSED              (0x00U)   /* Detection detection control unused */
#define _00_AD_DISCONECT_DISCHARGE           (0x00U)   /* Detection detection control discharge */
#define _10_AD_DISCONECT_PRECHARGE           (0x10U)   /* Detection detection control precharge */
#define _03_AD_DISCONECT_3ADCLK              (0x03U)   /* 3 ADCLK of detection detection control precharge/discharge */
#define _06_AD_DISCONECT_6ADCLK              (0x06U)   /* 6 ADCLK of detection detection control precharge/discharge */
#define _09_AD_DISCONECT_9ADCLK              (0x09U)   /* 9 ADCLK of detection detection control precharge/discharge */
#define _0C_AD_DISCONECT_12ADCLK             (0x0CU)   /* 12 ADCLK of detection detection control precharge/discharge */
#define _0F_AD_DISCONECT_15ADCLK             (0x0FU)   /* 15 ADCLK of detection detection control precharge/discharge */

/*
    A/D Event Link Control Register (ADELCCR)
*/
#define _00_GROUPA_SCAN_COMPLETION           (0x00U)   /* An event signal is generated when scanning for group A is
                                                          completed */
#define _01_GROUPB_SCAN_COMPLETION           (0x01U)   /* An event signal is generated when scanning for group B is 
                                                          completed */
#define _02_ALL_SCAN_COMPLETION              (0x02U)   /* An event signal is generated when scanning for group A,
                                                          group B, or group C is completed */
#define _04_GROUPC_SCAN_COMPLETION           (0x04U)   /* An event signal is generated when scanning for group C is
                                                          completed */

/*
    A/D Group Scan Priority Control Register (ADGSPCR)
*/
/* Group Priority Control Setting (PGS) */
#define _0000_AD_GPPRIORITY_DISABLE          (0x0000U) /* Operation is without group priority control */
#define _0001_AD_GPPRIORITY_ENABLE           (0x0001U) /* Operation is with group priority control */
/* Low-Priority Group Restart Setting (GBRSCN) */
#define _0000_AD_GPRESTART_DISABLE           (0x0000U) /* Scanning for the group is not restarted after having been
                                                          interrupted due to group priority control */
#define _0002_AD_GPRESTART_ENABLE            (0x0002U) /* Scanning for the group is restarted after having been
                                                          interrupted due to group priority control */
/* Restart Channel Select (LGRRS) */
#define _0000_AD_RESTART_START_CHAN          (0x0000U) /* Scanning is restarted from the scan start channel */
#define _4000_AD_RESTART_INCOMPLETE          (0x4000U) /* Scanning is restarted from the channel on which A/D
                                                          conversion is not completed. */
/* Single Scan Continuous Start (GBRP) */
#define _0000_AD_SINGLE_START_NOT_CONT       (0x0000U) /* Single cycle scan for group B not continuously activated */
#define _8000_AD_SINGLE_START_CONT           (0x8000U) /* Single cycle scan for group B is continuously activated */

/*
    A/D Comparison Function Control Register (ADCMPCR)
*/
/* Window A/B Complex Conditions Setting (CMPAB) */
#define _0000_AD_COMPLEX_CONDITION_OR        (0x0000U) /* Window A comparison condition matched OR window B
                                                          comparison condition matched */
#define _0001_AD_COMPLEX_CONDITION_EXOR      (0x0001U) /* Window A comparison condition matched EXOR window B
                                                          comparison condition matched */
#define _0002_AD_COMPLEX_CONDITION_AND       (0x0002U) /* Window A comparison condition matched AND window B
                                                          comparison condition matched */
/* Comparison Window B Enable (CMPBE) */
#define _0000_AD_WINDOWB_DISABLE             (0x0000U) /* Comparison window B disabled */
#define _0200_AD_WINDOWB_ENABLE              (0x0200U) /* Comparison window B enabled */
/* Comparison Window A Enable (CMPAE) */
#define _0000_AD_WINDOWA_DISABLE             (0x0000U) /* Comparison window A disabled */
#define _0800_AD_WINDOWA_ENABLE              (0x0800U) /* Comparison window A enabled */
/* Comparison B Interrupt Enable (CMPBIE) */
#define _0000_AD_COMPAREB_INTERRUPT_DISABLE  (0x0000U) /* Comparison interrupt by a match with the comparison condition
                                                          (window B) is disabled */
#define _2000_AD_COMPAREB_INTERRUPT_ENABLE   (0x2000U) /* Comparison interrupt by a match with the comparison condition
                                                          (window B) is enable */
/* Window Function Setting (WCMPE) */
#define _0000_AD_WINDOWFUNCTION_DISABLE      (0x0000U) /* Window function disabled */
#define _4000_AD_WINDOWFUNCTION_ENABLE       (0x4000U) /* Window function enabled */
/* Comparison A Interrupt Enable (CMPAIE) */
#define _0000_AD_COMPAREA_INTERRUPT_DISABLE  (0x0000U) /* Comparison interrupt by a match with the comparison condition
                                                          (window A) is disabled */
#define _8000_AD_COMPAREA_INTERRUPT_ENABLE   (0x8000U) /* Comparison interrupt by a match with the comparison condition
                                                          (window A) is enable */

/*
    A/D Comparison Function Window A Extended Input Select Register (ADCMPANSER)
*/
/* Temperature Sensor Output Comparison Select (CMPSTS) */
#define _00_AD_TEMP_CMPA_UNUSED              (0x00U)   /* Temperature sensor output is not a target for comparison */
#define _01_AD_TEMP_CMPA_USED                (0x01U)   /* Temperature sensor output is a target for comparison */
/* Internal Reference Voltage Compare Select (CMPSOC) */
#define _00_AD_IREF_CMPA_UNUSED              (0x00U)   /* Internal reference voltage is not a target for comparison */
#define _02_AD_IREF_CMPA_USED                (0x02U)   /* Internal reference voltage is a target for comparison */

/*
    A/D Comparison Function Window A Channel Select Register 0 (ADCMPANSR0)
*/
#define _0001_AD_ANx00_CMPA_USED             (0x0001U) /* ANx00 is target for comparison */
#define _0002_AD_ANx01_CMPA_USED             (0x0002U) /* ANx01 is target for comparison */
#define _0004_AD_ANx02_CMPA_USED             (0x0004U) /* ANx02 is target for comparison */
#define _0008_AD_ANx03_CMPA_USED             (0x0008U) /* ANx03 is target for comparison */
#define _0010_AD_ANx04_CMPA_USED             (0x0010U) /* ANx04 is target for comparison */
#define _0020_AD_ANx05_CMPA_USED             (0x0020U) /* ANx05 is target for comparison */
#define _0040_AD_ANx06_CMPA_USED             (0x0040U) /* ANx06 is target for comparison */
#define _0080_AD_ANx07_CMPA_USED             (0x0080U) /* ANx07 is target for comparison */
#define _0100_AD_ANx08_CMPA_USED             (0x0100U) /* ANx08 is target for comparison */
#define _0200_AD_ANx09_CMPA_USED             (0x0200U) /* ANx09 is target for comparison */
#define _0400_AD_ANx10_CMPA_USED             (0x0400U) /* ANx10 is target for comparison */
#define _0800_AD_ANx11_CMPA_USED             (0x0800U) /* ANx11 is target for comparison */

/*
    A/D Comparison Function Window A Channel Select Register 1 (ADCMPANSR1)
*/
#define _0001_AD_ANx16_CMPA_USED             (0x0001U) /* ANx16 is target for comparison */
#define _0002_AD_ANx17_CMPA_USED             (0x0002U) /* ANx17 is target for comparison */

/*
    A/D Comparison Function Window A Comparison Condition Setting Register 0 (ADCMPLR0)
*/
#define _0000_AD_ANx00_CMPA_LEVEL0           (0x0000U) /* ANx00 converted value < ADCMPDR0 register value or ANx00
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx01_CMPA_LEVEL0           (0x0000U) /* ANx01 converted value < ADCMPDR0 register value or ANx01
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx02_CMPA_LEVEL0           (0x0000U) /* ANx02 converted value < ADCMPDR0 register value or ANx02
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx03_CMPA_LEVEL0           (0x0000U) /* ANx03 converted value < ADCMPDR0 register value or ANx03
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx04_CMPA_LEVEL0           (0x0000U) /* ANx04 converted value < ADCMPDR0 register value or ANx04
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx05_CMPA_LEVEL0           (0x0000U) /* ANx05 converted value < ADCMPDR0 register value or ANx05
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx06_CMPA_LEVEL0           (0x0000U) /* ANx06 converted value < ADCMPDR0 register value or ANx06
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx07_CMPA_LEVEL0           (0x0000U) /* ANx07 converted value < ADCMPDR0 register value or ANx07
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx08_CMPA_LEVEL0           (0x0000U) /* ANx08 converted value < ADCMPDR0 register value or ANx08
                                                         converted value > ADCMPDR1 register value */
#define _0000_AD_ANx09_CMPA_LEVEL0           (0x0000U) /* ANx09 converted value < ADCMPDR0 register value or ANx09
                                                         converted value > ADCMPDR1 register value */
#define _0000_AD_ANx10_CMPA_LEVEL0           (0x0000U) /* ANx10 converted value < ADCMPDR0 register value or ANx10
                                                         converted value > ADCMPDR1 register value */
#define _0000_AD_ANx11_CMPA_LEVEL0           (0x0000U) /* ANx11 converted value < ADCMPDR0 register value or ANx11
                                                          converted value > ADCMPDR1 register value */
#define _0001_AD_ANx00_CMPA_LEVEL1           (0x0001U) /* ADCMPDR0 register value < ANx00 converted value < ADCMPDR1
                                                          register value */
#define _0002_AD_ANx01_CMPA_LEVEL1           (0x0002U) /* ADCMPDR0 register value < ANx01 converted value < ADCMPDR1
                                                          register value */
#define _0004_AD_ANx02_CMPA_LEVEL1           (0x0004U) /* ADCMPDR0 register value < ANx02 converted value < ADCMPDR1
                                                          register value */
#define _0008_AD_ANx03_CMPA_LEVEL1           (0x0008U) /* ADCMPDR0 register value < ANx03 converted value < ADCMPDR1
                                                          register value */
#define _0010_AD_ANx04_CMPA_LEVEL1           (0x0010U) /* ADCMPDR0 register value < ANx04 converted value < ADCMPDR1
                                                          register value */
#define _0020_AD_ANx05_CMPA_LEVEL1           (0x0020U) /* ADCMPDR0 register value < ANx05 converted value < ADCMPDR1
                                                          register value */
#define _0040_AD_ANx06_CMPA_LEVEL1           (0x0040U) /* ADCMPDR0 register value < ANx06 converted value < ADCMPDR1
                                                          register value */
#define _0080_AD_ANx07_CMPA_LEVEL1           (0x0080U) /* ADCMPDR0 register value < ANx07 converted value < ADCMPDR1
                                                          register value */
#define _0100_AD_ANx08_CMPA_LEVEL1           (0x0100U) /* ADCMPDR0 register value < ANx08 converted value < ADCMPDR1
                                                          register value */
#define _0200_AD_ANx09_CMPA_LEVEL1           (0x0200U) /* ADCMPDR0 register value < ANx09 converted value < ADCMPDR1
                                                          register value */
#define _0400_AD_ANx10_CMPA_LEVEL1           (0x0400U) /* ADCMPDR0 register value < ANx10 converted value < ADCMPDR1
                                                          register value */
#define _0800_AD_ANx11_CMPA_LEVEL1           (0x0800U) /* ADCMPDR0 register value < ANx11 converted value < ADCMPDR1
                                                          register value */

/*
    A/D Comparison Function Window A Comparison Condition Setting Register 1 (ADCMPLR1)
*/
#define _0000_AD_ANx16_CMPA_LEVEL0           (0x0000U) /* ANx16 converted value < ADCMPDR0 register value or ANx16
                                                          converted value > ADCMPDR1 register value */
#define _0000_AD_ANx17_CMPA_LEVEL0           (0x0000U) /* ANx17 converted value < ADCMPDR0 register value or ANx17
                                                          converted value > ADCMPDR1 register value */
#define _0001_AD_ANx16_CMPA_LEVEL1           (0x0001U) /* ADCMPDR0 register value < ANx016 converted value < ADCMPDR1
                                                          register value */
#define _0002_AD_ANx17_CMPA_LEVEL1           (0x0002U) /* ADCMPDR0 register value < ANx17 converted value < ADCMPDR1
                                                          register value */

/*
    A/D Comparison Function Window A Extended Input Comparison Condition Setting Register (ADCMPLER)
*/
/* Comparison Window A Temperature Sensor Output Comparison Condition Select (CMPLTS) */
#define _00_AD_TEMP_CMPA_LEVEL0              (0x00U)   /* Temperature converted value < ADCMPDR0 register value or
                                                          Temperature converted value > ADCMPDR1 register value */
#define _01_AD_TEMP_CMPA_LEVEL1              (0x01U)   /* ADCMPDR0 register value < Temperature converted value <
                                                          ADCMPDR1 register value */
/* Comparison Window A Internal Reference Voltage Comparison Condition Select (CMPLOC) */
#define _00_AD_IREF_CMPA_LEVEL0              (0x00U)   /* Internal converted value < ADCMPDR0 register value or
                                                          Internal converted value > ADCMPDR1 register value */
#define _02_AD_IREF_CMPA_LEVEL1              (0x02U)   /* ADCMPDR0 register value < Internal converted value < ADCMPDR1
                                                          register value */

/*
    A/D Comparison Function Window B Channel Select Register (ADCMPBNSR)
*/
/* Comparison Window B Channel Select (CMPLB) */
#define _00_AD_CMPB_LEVEL0                   (0x00U)   /* Comparison B converted value < ADCMPDR0 register value or
                                                          Comparison B converted value > ADCMPDR1 register value */
#define _80_AD_CMPB_LEVEL1                   (0x80U)   /* ADWINLLB register value < Comparison B converted value <
                                                          ADWINULB register value */

/*
    A/D Programmable Gain Amplifier Control Register (ADPGACR)
*/
/* Px Amplifier Control, x = 000 to 002, 100 to 102 */
#define _0000_AD_PATH_DISCONNECTED           (0x0000U) /* Analog input path: A/D: None | CMPCm0: None | CMPCm1: None */
#define _0001_AD_PATH_ANx_NONE_NONE          (0x0001U) /* Analog input path: A/D: ANx  | CMPCm0: None | CMPCm1: None */
#define _0008_AD_PATH_NONE_ANx_NONE          (0x0008U) /* Analog input path: A/D: None | CMPCm0: ANx  | CMPCm1: None */
#define _0009_AD_PATH_ANx_ANx_NONE           (0x0009U) /* Analog input path: A/D: ANx  | CMPCm0: ANx  | CMPCm1: None */
#define _000C_AD_PATH_NONE_ANx_Px            (0x000CU) /* Analog input path: A/D: None | CMPCm0: ANx  | CMPCm1: Px */
#define _000D_AD_PATH_ANx_ANx_Px             (0x000DU) /* Analog input path: A/D: ANx  | CMPCm0: ANx  | CMPCm1: Px */
#define _000E_AD_PATH_Px_ANx_Px              (0x000EU) /* Analog input path: A/D: Px   | CMPCm0: ANx  | CMPCm1: Px */

/*
    A/D Programmable Gain Amplifier Gain Setting Register 0 (ADPGAGS0)
*/
/* Px Amplifier Gain Setting (PxGAIN), x = 000 to 002, 100 to 102 */
#define _0000_AD_GAIN_2_000                  (0x0000U) /* x 2.000 */
#define _0001_AD_GAIN_2_500                  (0x0001U) /* x 2.500 */
#define _0003_AD_GAIN_3_077                  (0x0003U) /* x 3.077 */
#define _0005_AD_GAIN_3_636                  (0x0005U) /* x 3.636 */
#define _0006_AD_GAIN_4_000                  (0x0006U) /* x 4.000 */
#define _0007_AD_GAIN_4_444                  (0x0007U) /* x 4.444 */
#define _0008_AD_GAIN_5_000                  (0x0008U) /* x 5.000 */
#define _000A_AD_GAIN_6_667                  (0x000AU) /* x 6.667 */
#define _000B_AD_GAIN_8_000                  (0x000BU) /* x 8.000 */
#define _000C_AD_GAIN_10_000                 (0x000CU) /* x 10.000 */
#define _000D_AD_GAIN_13_333                 (0x000DU) /* x 13.333 */
#define _000E_AD_GAIN_20_000                 (0x000EU) /* x 20.000 */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _00_AD_PRIORITY_LEVEL0               (0x00U)   /* Level 0 (interrupt disabled) */
#define _01_AD_PRIORITY_LEVEL1               (0x01U)   /* Level 1 */
#define _02_AD_PRIORITY_LEVEL2               (0x02U)   /* Level 2 */
#define _03_AD_PRIORITY_LEVEL3               (0x03U)   /* Level 3 */
#define _04_AD_PRIORITY_LEVEL4               (0x04U)   /* Level 4 */
#define _05_AD_PRIORITY_LEVEL5               (0x05U)   /* Level 5 */
#define _06_AD_PRIORITY_LEVEL6               (0x06U)   /* Level 6 */
#define _07_AD_PRIORITY_LEVEL7               (0x07U)   /* Level 7 */
#define _08_AD_PRIORITY_LEVEL8               (0x08U)   /* Level 8 */
#define _09_AD_PRIORITY_LEVEL9               (0x09U)   /* Level 9 */
#define _0A_AD_PRIORITY_LEVEL10              (0x0AU)   /* Level 10 */
#define _0B_AD_PRIORITY_LEVEL11              (0x0BU)   /* Level 11 */
#define _0C_AD_PRIORITY_LEVEL12              (0x0CU)   /* Level 12 */
#define _0D_AD_PRIORITY_LEVEL13              (0x0DU)   /* Level 13 */
#define _0E_AD_PRIORITY_LEVEL14              (0x0EU)   /* Level 14 */
#define _0F_AD_PRIORITY_LEVEL15              (0x0FU)   /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5, ADCHANNEL6, ADCHANNEL7,
    ADCHANNEL8, ADCHANNEL9, ADCHANNEL10, ADCHANNEL11, ADCHANNEL16, ADCHANNEL17,
    ADSELFDIAGNOSIS, ADTEMPSENSOR, ADINTERREFVOLT, ADDATADUPLICATION, ADDATADUPLICATIONA, ADDATADUPLICATIONB
} ad_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
