/**
 * @file peripheral.h
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
#include <api/HarfUART.h>
#include <api/TWIM.h>

#ifdef __cplusplus
extern "C" {
#endif

/* configuration to "api/Portmux.cpp" */

/* USARTn in HarfUART.h */
#define Serial0 Serial0A
extern HarfUART_Class Serial0A;   /* upload.port=UART0_A0 */
extern HarfUART_Class Serial0B;   /* upload.port=UART0_A4 */

#define Serial1 Serial1A
extern HarfUART_Class Serial1A;   /* upload.port=UART1_C0 */
extern HarfUART_Class Serial1B;   /* upload.port=UART1_C4 */

#define Serial2 Serial2B
extern HarfUART_Class Serial2A;   /* upload.port=UART2_F0 */
extern HarfUART_Class Serial2B;   /* upload.port=UART2_F4 */

#define Serial3 Serial3A
extern HarfUART_Class Serial3A;   /* upload.port=UART3_B0 */
extern HarfUART_Class Serial3B;   /* upload.port=UART3_B4 */

/* struct UART_portmux_t in Portmux.h */
#define _PORTMUX_USART0A {&PORTMUX_USARTROUTEA, PORTMUX_USART0_gm, PORTMUX_USART0_DEFAULT_gc, &PORTA, PIN0_bm, PIN1_bm, &PORTA_PIN1CTRL}
#define _PORTMUX_USART0B {&PORTMUX_USARTROUTEA, PORTMUX_USART0_gm, PORTMUX_USART0_ALT1_gc   , &PORTA, PIN4_bm, PIN5_bm, &PORTA_PIN5CTRL}
#define _PORTMUX_USART1A {&PORTMUX_USARTROUTEA, PORTMUX_USART1_gm, PORTMUX_USART1_DEFAULT_gc, &PORTC, PIN0_bm, PIN1_bm, &PORTC_PIN1CTRL}
#define _PORTMUX_USART1B {&PORTMUX_USARTROUTEA, PORTMUX_USART1_gm, PORTMUX_USART1_ALT1_gc   , &PORTC, PIN4_bm, PIN5_bm, &PORTC_PIN5CTRL}
#define _PORTMUX_USART2A {&PORTMUX_USARTROUTEA, PORTMUX_USART2_gm, PORTMUX_USART2_DEFAULT_gc, &PORTF, PIN0_bm, PIN1_bm, &PORTF_PIN1CTRL}
#define _PORTMUX_USART2B {&PORTMUX_USARTROUTEA, PORTMUX_USART2_gm, PORTMUX_USART2_ALT1_gc   , &PORTF, PIN4_bm, PIN5_bm, &PORTF_PIN5CTRL}
#define _PORTMUX_USART3A {&PORTMUX_USARTROUTEA, PORTMUX_USART3_gm, PORTMUX_USART3_DEFAULT_gc, &PORTB, PIN0_bm, PIN1_bm, &PORTB_PIN1CTRL}
#define _PORTMUX_USART3B {&PORTMUX_USARTROUTEA, PORTMUX_USART3_gm, PORTMUX_USART3_ALT1_gc   , &PORTB, PIN4_bm, PIN5_bm, &PORTB_PIN5CTRL}

/* TWIn in TWIM.h */
#define Wire0 Wire0A
extern TWIM_Class Wire0A;
extern TWIM_Class Wire0B;
extern TWIM_Class Wire0C;

/* struct TWI_portmux_t in Portmux.h */
#define _PORTMUX_TWI0A {&PORTMUX_TWISPIROUTEA, PORTMUX_TWI0_gm, PORTMUX_TWI0_DEFAULT_gc, &PORTA, PIN2_bm, PIN3_bm, &PORTA_PIN2CTRL, &PORTA_PIN3CTRL}
#define _PORTMUX_TWI0B {&PORTMUX_TWISPIROUTEA, PORTMUX_TWI0_gm, PORTMUX_TWI0_ALT1_gc   , &PORTA, PIN2_bm, PIN3_bm, &PORTA_PIN2CTRL, &PORTA_PIN3CTRL}
#define _PORTMUX_TWI0C {&PORTMUX_TWISPIROUTEA, PORTMUX_TWI0_gm, PORTMUX_TWI0_ALT2_gc   , &PORTC, PIN2_bm, PIN3_bm, &PORTC_PIN2CTRL, &PORTC_PIN3CTRL}

/* struct SPI_portmux_t in Portmux.h */
#define _PORTMUX_SPI0A {PORTMUX_TWISPIROUTEA, PORTMUX_SPI0_gm, PORTMUX_SPI0_DEFAULT_gc, &PORTA, PIN4_bm, PIN5_bm, PIN6_bm, PIN7_bm, &PORTA_PIN4CTRL. &PORTA_PIN5CTRL. &PORTA_PIN6CTRL. &PORTA_PIN7CTRL}
#define _PORTMUX_SPI0B {PORTMUX_TWISPIROUTEA, PORTMUX_SPI0_gm, PORTMUX_SPI0_ALT1_gc   , &PORTC, PIN0_bm, PIN1_bm, PIN2_bm, PIN3_bm, &PORTC_PIN0CTRL. &PORTC_PIN1CTRL. &PORTC_PIN2CTRL. &PORTC_PIN3CTRL}
#define _PORTMUX_SPI0C {PORTMUX_TWISPIROUTEA, PORTMUX_SPI0_gm, PORTMUX_SPI0_ALT2_gc   , &PORTE, PIN0_bm, PIN1_bm, PIN2_bm, PIN3_bm, &PORTE_PIN0CTRL. &PORTE_PIN1CTRL. &PORTE_PIN2CTRL. &PORTE_PIN3CTRL}

#ifdef __cplusplus
} // extern "C"
#endif

// end of code
