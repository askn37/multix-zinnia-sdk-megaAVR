/**
 * @file peripheral.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <api/HarfUART.h>
#include <api/TWIM.h>

#ifdef __cplusplus
extern "C" {
#endif

/* configuration to "api/Portmux.cpp" */

/* USARTn in HarfUART.h */
#define Serial0 Serial0A
extern HarfUART_Class Serial0A;   /* upload.port=UART0_B2 */
extern HarfUART_Class Serial0B;   /* upload.port=UART0_A1 */

/* Serial1x not implemented */
/* Serial2x not implemented */
/* Serial3x not implemented */

/* struct UART_portmux_t in Portmux.h */
#define _PORTMUX_USART0A {&PORTMUX_CTRLA, 1, 0, &PORTA, PIN6_bm, PIN7_bm, &PORTA_PIN7CTRL}
#define _PORTMUX_USART0B {&PORTMUX_CTRLA, 1, 1, &PORTA, PIN1_bm, PIN2_bm, &PORTA_PIN2CTRL}

/* TWIn in TWIM.h */
#define Wire0 Wire0A
extern TWIM_Class Wire0A;

/* struct TWI_portmux_t in Portmux.h */
#define _PORTMUX_TWI0A {nullptr, 0, 0, &PORTA, PIN1_bm, PIN2_bm, &PORTA_PIN1CTRL, &PORTA_PIN2CTRL}

#ifdef __cplusplus
} // extern "C"
#endif

// end of code
