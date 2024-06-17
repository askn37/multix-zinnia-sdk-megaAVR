/**
 * @file variant_io.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once

/* C Language Only */
#if !defined (__ASSEMBLER__)

/* Clock Select */
typedef enum TCB_CLKSEL_ALT_enum
{
    TCB_CLKSEL_DIV1_gc = (0x00<<1),  /* CLK_PER */
    TCB_CLKSEL_DIV2_gc = (0x01<<1),  /* CLK_PER/2 */
    TCB_CLKSEL_TCA0_gc = (0x02<<1),  /* Use CLK_TCA from TCA0 */
} TCB_CLKSEL_ALT_t;

typedef enum RTC_CLKSEL_ALT_enum
{
    RTC_CLKSEL_OSC32K_gc = (0x00<<0),   /* 32.768 kHz from OSC32K */
    RTC_CLKSEL_OSC1K_gc = (0x01<<0),    /* 1.024 kHz from OSC32K */
    RTC_CLKSEL_XOSC32K_gc = (0x02<<0)   /* 32.768 kHz from XOSC32K */
} RTC_CLKSEL_ALT_t;

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
#define SLEEP_MODE_ADC   SLEEP_MODE_IDLE

// end of code
