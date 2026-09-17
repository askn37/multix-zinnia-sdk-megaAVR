/**
 * @file variant_io.h
 * @author askn (K.Sato) multix.jp
 * @brief Macro/Micro API variant io header
 * @version 0.2
 * @date 2026-09-16
 * @copyright Copyright (c) 2026 askn37 at github.com
 * @link Product Potal : https://askn37.github.io/
 *         MIT License : https://askn37.github.io/LICENSE.html
 */

#pragma once
#if defined(ENABLE_MACRO_API) && !defined(DISABLE_MACRO_API) && (__AVR_ARCH__ >= 102)
#include <avr/io.h>
#define AVR_MEGAAVR_LIKE_MODERNAVR
#define AVR_MODERNAVR_LIKE_MEGAAVR

#define __MSS_USART_RS485_INT__
#define __MSS_CLKCTRL_CLKSEL_OSCX__
#define __MSS_CLKCTRL_PDIV_DIVN__
#define __MSS_EVSYS_CH__
#define __MSS_AVRNOX_FUSES__

/* C Language Only */
#if !defined (__ASSEMBLER__)

/* Clock Select bit group configurations*/
typedef enum RTC_CLKSEL_ALT_enum
{
    RTC_CLKSEL_OSC32K_gc    = (RTC_CLKSEL_INT32K_gv   << RTC_CLKSEL_gp),  /* Internal 32kHz OSC */
    RTC_CLKSEL_OSC1K_gc     = (RTC_CLKSEL_INT1K_gv    << RTC_CLKSEL_gp),  /* Internal 1kHz OSC */
    RTC_CLKSEL_XOSC32K_gc   = (RTC_CLKSEL_TOSC32K_gv  << RTC_CLKSEL_gp),  /* 32KHz Crystal OSC */
//  RTC_CLKSEL_EXTCLK_gc    = (RTC_CLKSEL_EXTCLK_gv   << RTC_CLKSEL_gp)   /* External Clock */
} RTC_CLKSEL_ALT_t;

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
#define EVSYS_CHANNEL_TCB0_CAPT_gc        EVSYS_CHANNEL0_TCB0_CAPT_gc
#define EVSYS_CHANNEL_TCB0_OVF_gc         EVSYS_CHANNEL0_TCB0_OVF_gc
#define EVSYS_CHANNEL_TCB1_CAPT_gc        EVSYS_CHANNEL0_TCB1_CAPT_gc
#define EVSYS_CHANNEL_TCB1_OVF_gc         EVSYS_CHANNEL0_TCB1_OVF_gc

#endif

#include <api/macro_sugar.h>
#endif

// end of code
