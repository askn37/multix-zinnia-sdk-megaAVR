/**
 * @file variant.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <util/atomic.h>
#include <variant_io.h>
#include <api/CLKCTRL_megaAVR.h>

#define AVR_MEGAAVR
#define AVR_TINYAVR
#define AVR_TINYAVR0
#define AVR_TINYAVR_14

//// Pin name to PORT configuration
////   bit[765] PORTA-G index position
////   bit[4]   1 (+16) (A=16,B=48,C=80,D=112,E=144,F=176,G=208)
////   bit[3]   0
////   bit[210] PIN0-7 bit position (0-7)

/* GPIO x12 (other VDD,GND) */

#define PIN_PA0 16
#define PIN_PA1 17
#define PIN_PA2 18
#define PIN_PA3 19
#define PIN_PA4 20
#define PIN_PA5 21
#define PIN_PA6 22
#define PIN_PA7 23

#define PIN_PB0 48
#define PIN_PB1 49
#define PIN_PB2 50
#define PIN_PB3 51
/*      PIN_PB4 not implemented */
/*      PIN_PB5 not implemented */
/*      PIN_PB6 not implemented */
/*      PIN_PB7 not implemented */

/* PORTC not implemented */
/* PORTD not implemented */
/* PORTE not implemented */
/* PORTF not implemented */
/* PORTG not implemented */

#define NOT_A_PIN    255
#define PIN_UPDI     PIN_PA0
#define PIN_RESET    PIN_PA0
#define PIN_VREFA    PIN_PA5

#ifndef LED_BUILTIN
#define LED_BUILTIN  PIN_PA7
#endif
#define LED_BUILTIN_INVERT  /* implementation dependent */

/* Timer Waveout signal */

#define PIN_WO0           PIN_PB0
#define PIN_WO1           PIN_PB1
#define PIN_WO2           PIN_PB2
#define PIN_WO3           PIN_PA3
#define PIN_WO4           PIN_PA4
#define PIN_WO5           PIN_PA5
#define PIN_WO0_ALT1      PIN_PB3
// #define PIN_WO1_ALT1      PIN_PB4
// #define PIN_WO2_ALT1      PIN_PB5
// #define PIN_WO3_ALT1      PIN_PC3
#define PIN_TCA0_WO0      PIN_PB0
#define PIN_TCA0_WO1      PIN_PB1
#define PIN_TCA0_WO2      PIN_PB2
#define PIN_TCA0_WO3      PIN_PA3
#define PIN_TCA0_WO4      PIN_PA4
#define PIN_TCA0_WO5      PIN_PA5
#define PIN_TCA0_WO0_ALT1 PIN_PB3
// #define PIN_TCA0_WO1_ALT1 PIN_PB4
// #define PIN_TCA0_WO2_ALT1 PIN_PB5
// #define PIN_TCA0_WO3_ALT1 PIN_PC3
// #define PIN_TCA0_WO4_ALT1 PIN_PC4
// #define PIN_TCA0_WO5_ALT1 PIN_PC5
#define PIN_TCB0_WO       PIN_PA5
// #define PIN_TCB0_WO_ALT1  PIN_PC0

/* peripheral ports */

#define PIN_AC0_OUT       PIN_PA5
#define PIN_AC0_AINN0     PIN_PA6
#define PIN_AC0_AINP0     PIN_PA7
// #define PIN_AC0_AINN1     PIN_PB4
// #define PIN_AC0_AINP1     PIN_PB5
#define PIN_ADC0_AIN0     PIN_PA0
#define PIN_ADC0_AIN1     PIN_PA1
#define PIN_ADC0_AIN2     PIN_PA2
#define PIN_ADC0_AIN3     PIN_PA3
#define PIN_ADC0_AIN4     PIN_PA4
#define PIN_ADC0_AIN5     PIN_PA5
#define PIN_ADC0_AIN6     PIN_PA6
#define PIN_ADC0_AIN7     PIN_PA7
// #define PIN_ADC0_AIN8     PIN_PB5
// #define PIN_ADC0_AIN9     PIN_PB4
#define PIN_ADC0_AIN10    PIN_PB1
#define PIN_ADC0_AIN11    PIN_PB0
#define PIN_EVOUT0        PIN_PA2
#define PIN_EVOUT1        PIN_PB2
// #define PIN_EVOUT2        PIN_PC2
#define PIN_LUT0_IN0      PIN_PA0
#define PIN_LUT0_IN1      PIN_PA1
#define PIN_LUT0_IN2      PIN_PA2
#define PIN_LUT0_OUT      PIN_PA4
#define PIN_LUT0_OUT_ALT1 PIN_PB4
// #define PIN_LUT1_IN0      PIN_PC3
// #define PIN_LUT1_IN1      PIN_PC4
// #define PIN_LUT1_IN2      PIN_PC5
#define PIN_LUT1_OUT      PIN_PA7
// #define PIN_LUT1_OUT_ALT1 PIN_PC1

#define PIN_SPI0_MOSI        PIN_PA1
#define PIN_SPI0_MISO        PIN_PA2
#define PIN_SPI0_SCK         PIN_PA3
#define PIN_SPI0_SS          PIN_PA4
#define PIN_TWI0_SCL         PIN_PB0
#define PIN_TWI0_SDA         PIN_PB1
#define PIN_TWI0_SDA_ALT1    PIN_PA1
#define PIN_TWI0_SCL_ALT1    PIN_PA2
#define PIN_USART0_TXD       PIN_PB2
#define PIN_USART0_RXD       PIN_PB3
#define PIN_USART0_XCK       PIN_PB1
#define PIN_USART0_XDIR      PIN_PB0
#define PIN_USART0_TXD_ALT1  PIN_PA1
#define PIN_USART0_RXD_ALT1  PIN_PA2
#define PIN_USART0_XCK_ALT1  PIN_PA3
#define PIN_USART0_XDIR_ALT1 PIN_PA4

#define PIN_PTC_XY0   PIN_PA4
#define PIN_PTC_XY1   PIN_PA5
#define PIN_PTC_XY2   PIN_PA6
#define PIN_PTC_XY3   PIN_PA7
#define PIN_PTC_XY4   PIN_PB1
#define PIN_PTC_XY5   PIN_PB0

/* peripheral symbols */

#define HAVE_AC0           AC0_AC_vect_num
#define HAVE_ADC0     ADC0_RESRDY_vect_num
#define HAVE_BOD          BOD_VLM_vect_num
#define HAVE_CCL          CCL_CCL_vect_num
#define HAVE_NMI      CRCSCAN_NMI_vect_num
#define HAVE_NVMCTRL   NVMCTRL_EE_vect_num
#define HAVE_PIT          RTC_PIT_vect_num
#define HAVE_PORTA     PORTA_PORT_vect_num
#define HAVE_PORTB     PORTB_PORT_vect_num
#define HAVE_RTC          RTC_CNT_vect_num
#define HAVE_SPI0        SPI0_INT_vect_num
#define HAVE_TCA0        TCA0_OVF_vect_num
#define HAVE_TCB0        TCB0_INT_vect_num
#define HAVE_TWI0       TWI0_TWIS_vect_num
#define HAVE_USART0    USART0_RXC_vect_num

/* build.console_select */

#ifndef ICSP_Serial
#define ICSP_Serial Serial0
#endif

/* build.console_select */

#ifndef Serial
#define Serial Serial0
#endif

#ifndef Wire
#define Wire Wire0
#endif

#ifdef __cplusplus
extern "C" {
#endif

inline void initVariant (void) {

  // /* I want to write this, but the result is not good : 66 bytes */
  // register8_t *ports[] = {&PORTA_PIN0CTRL, &PORTB_PIN0CTRL};
  // for (auto port : ports) {
  //   for (uint8_t i = 0; i <= 7; i++) {
  //     port[i] = PORT_ISC_INPUT_DISABLE_gc;
  //   }
  // }

  /* 2x8 PINnCTRL initialize : 22 bytes */
  __asm__ volatile (
    "   LDI  R24, 2  \n" /* PORTA to PORTB */
    "2: LDI  R25, 8  \n"
    "1: ST   Z+, %1  \n"
    "   DEC  R25     \n"
    "   BRNE 1b      \n" /* 8 loop PIN0CTRL to PIN7CTRL */
    "   ADIW Z, 0x18 \n" /* offset +0x18 : next PIN0CTRL */
    "   DEC  R24     \n"
    "   BRNE 2b        " /* 2 loop PORTA to PORTB */
    : : "z" ((register8_t*)&PORTA_PIN0CTRL),
        "r" ((uint8_t)PORT_ISC_INPUT_DISABLE_gc)
      : "r24", "r25"
  );

  _CLKCTRL_SETUP();
}

#ifdef __cplusplus
} // extern "C"
#endif

// end of code
