/**
 * @file variant_io.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

/* C Language Only */
#if !defined (__ASSEMBLER__)

#endif /* !defined (__ASSEMBLER__) */

/* FUSE - Fuses */
#define FUSE_CODESIZE  _SFR_MEM8(0x1287) /* FUSE_APPEND */
#define FUSE_BOOTSIZE  _SFR_MEM8(0x1288) /* FUSE_BOOTEND */

/* GPR - General Purpose Registers */
#define GPR_GPR0  _SFR_MEM8(0x001C)
#define GPR_GPR1  _SFR_MEM8(0x001D)
#define GPR_GPR2  _SFR_MEM8(0x001E)
#define GPR_GPR3  _SFR_MEM8(0x001F)

#define CLKSEL_OSCHF_gc  CLKCTRL_CLKSEL_OSC20M_gc
#define CLKSEL_OSC32K_gc CLKCTRL_CLKSEL_OSCULP32K_gc
#define SLEEP_MODE_ADC   SLEEP_MODE_STANDBY

#define EVSYS_CHANNEL_OFF_gc              EVSYS_CHANNEL0_OFF_gc
#define EVSYS_CHANNEL_UPDI_gc             EVSYS_CHANNEL0_UPDI_gc
#define EVSYS_CHANNEL_RTC_OVF_gc          EVSYS_CHANNEL0_RTC_OVF_gc
#define EVSYS_CHANNEL_RTC_CMP_gc          EVSYS_CHANNEL0_RTC_CMP_gc
#define EVSYS_CHANNEL_CCL_LUT0_gc         EVSYS_CHANNEL0_CCL_LUT0_gc
#define EVSYS_CHANNEL_CCL_LUT1_gc         EVSYS_CHANNEL0_CCL_LUT1_gc
#define EVSYS_CHANNEL_CCL_LUT2_gc         EVSYS_CHANNEL0_CCL_LUT2_gc
#define EVSYS_CHANNEL_CCL_LUT3_gc         EVSYS_CHANNEL0_CCL_LUT3_gc
#define EVSYS_CHANNEL_AC0_OUT_gc          EVSYS_CHANNEL0_AC0_OUT_gc
#define EVSYS_CHANNEL_ADC0_RES_gc         EVSYS_CHANNEL0_ADC0_RES_gc
#define EVSYS_CHANNEL_ADC0_SAMP_gc        EVSYS_CHANNEL0_ADC0_SAMP_gc
#define EVSYS_CHANNEL_ADC0_WCMP_gc        EVSYS_CHANNEL0_ADC0_WCMP_gc
#define EVSYS_CHANNEL_USART0_XCK_gc       EVSYS_CHANNEL0_USART0_XCK_gc
#define EVSYS_CHANNEL_USART1_XCK_gc       EVSYS_CHANNEL0_USART1_XCK_gc
#define EVSYS_CHANNEL_SPI0_SCK_gc         EVSYS_CHANNEL0_SPI0_SCK_gc
#define EVSYS_CHANNEL_TCA0_OVF_LUNF_gc    EVSYS_CHANNEL0_TCA0_OVF_LUNF_gc
#define EVSYS_CHANNEL_TCA0_HUNF_gc        EVSYS_CHANNEL0_TCA0_HUNF_gc
#define EVSYS_CHANNEL_TCA0_CMP0_LCMP0_gc  EVSYS_CHANNEL0_TCA0_CMP0_LCMP0_gc
#define EVSYS_CHANNEL_TCA0_CMP1_LCMP1_gc  EVSYS_CHANNEL0_TCA0_CMP1_LCMP1_gc
#define EVSYS_CHANNEL_TCA0_CMP2_LCMP2_gc  EVSYS_CHANNEL0_TCA0_CMP2_LCMP2_gc
#define EVSYS_CHANNEL_TCA1_OVF_LUNF_gc    EVSYS_CHANNEL0_TCA1_OVF_LUNF_gc
#define EVSYS_CHANNEL_TCA1_HUNF_gc        EVSYS_CHANNEL0_TCA1_HUNF_gc
#define EVSYS_CHANNEL_TCA1_CMP0_LCMP0_gc  EVSYS_CHANNEL0_TCA1_CMP0_LCMP0_gc
#define EVSYS_CHANNEL_TCA1_CMP1_LCMP1_gc  EVSYS_CHANNEL0_TCA1_CMP1_LCMP1_gc
#define EVSYS_CHANNEL_TCA1_CMP2_LCMP2_gc  EVSYS_CHANNEL0_TCA1_CMP2_LCMP2_gc
#define EVSYS_CHANNEL_TCB0_CAPT_gc        EVSYS_CHANNEL0_TCB0_CAPT_gc
#define EVSYS_CHANNEL_TCB0_OVF_gc         EVSYS_CHANNEL0_TCB0_OVF_gc
#define EVSYS_CHANNEL_TCB1_CAPT_gc        EVSYS_CHANNEL0_TCB1_CAPT_gc
#define EVSYS_CHANNEL_TCB1_OVF_gc         EVSYS_CHANNEL0_TCB1_OVF_gc

// end of code
