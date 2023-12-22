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
#define AVR_MODERNAVR_LIKE_MEGAAVR

/* C Language Only */
#if !defined (__ASSEMBLER__)

/* Clock select */
typedef enum CLKCTRL_CLKSEL_ALT_enum
{
    CLKCTRL_CLKSEL_OSCHF_gc = (0x00<<0),  /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSC32K_gc = (0x01<<0),  /* Internal 32.768 kHz oscillator */
 // CLKCTRL_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32.768 kHz crystal oscillator */
 // CLKCTRL_CLKSEL_EXTCLK_gc = (0x03<<0)  /* External clock */
} CLKCTRL_CLKSEL_ALT_t;

/* Channel 0 generator select */
typedef enum EVSYS_CHANNEL0_enum
{
    EVSYS_CHANNEL0_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL0_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL0_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL0_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL0_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL0_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL0_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL0_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL0_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL0_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL0_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL0_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL0_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL0_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL0_PORTA_PIN0_gc = (0x40<<0),  /* Port A Pin 0 */
    EVSYS_CHANNEL0_PORTA_PIN1_gc = (0x41<<0),  /* Port A Pin 1 */
    EVSYS_CHANNEL0_PORTA_PIN2_gc = (0x42<<0),  /* Port A Pin 2 */
    EVSYS_CHANNEL0_PORTA_PIN3_gc = (0x43<<0),  /* Port A Pin 3 */
    EVSYS_CHANNEL0_PORTA_PIN4_gc = (0x44<<0),  /* Port A Pin 4 */
    EVSYS_CHANNEL0_PORTA_PIN5_gc = (0x45<<0),  /* Port A Pin 5 */
    EVSYS_CHANNEL0_PORTA_PIN6_gc = (0x46<<0),  /* Port A Pin 6 */
    EVSYS_CHANNEL0_PORTA_PIN7_gc = (0x47<<0),  /* Port A Pin 7 */
    EVSYS_CHANNEL0_PORTB_PIN0_gc = (0x48<<0),  /* Port B Pin 0 */
    EVSYS_CHANNEL0_PORTB_PIN1_gc = (0x49<<0),  /* Port B Pin 1 */
    EVSYS_CHANNEL0_PORTB_PIN2_gc = (0x4A<<0),  /* Port B Pin 2 */
    EVSYS_CHANNEL0_PORTB_PIN3_gc = (0x4B<<0),  /* Port B Pin 3 */
    EVSYS_CHANNEL0_PORTB_PIN4_gc = (0x4C<<0),  /* Port B Pin 4 */
    EVSYS_CHANNEL0_PORTB_PIN5_gc = (0x4D<<0),  /* Port B Pin 5 */
    EVSYS_CHANNEL0_PORTB_PIN6_gc = (0x4E<<0),  /* Port B Pin 6 */
    EVSYS_CHANNEL0_PORTB_PIN7_gc = (0x4F<<0),  /* Port B Pin 7 */
    EVSYS_CHANNEL0_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL0_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL0_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL0_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL0_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL0_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL0_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL0_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL0_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL0_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL0_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL0_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL0_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL0_t;

/* Channel 1 generator select */
typedef enum EVSYS_CHANNEL1_enum
{
    EVSYS_CHANNEL1_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL1_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL1_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL1_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL1_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL1_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL1_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL1_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL1_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL1_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL1_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL1_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL1_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL1_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL1_PORTA_PIN0_gc = (0x40<<0),  /* Port A Pin 0 */
    EVSYS_CHANNEL1_PORTA_PIN1_gc = (0x41<<0),  /* Port A Pin 1 */
    EVSYS_CHANNEL1_PORTA_PIN2_gc = (0x42<<0),  /* Port A Pin 2 */
    EVSYS_CHANNEL1_PORTA_PIN3_gc = (0x43<<0),  /* Port A Pin 3 */
    EVSYS_CHANNEL1_PORTA_PIN4_gc = (0x44<<0),  /* Port A Pin 4 */
    EVSYS_CHANNEL1_PORTA_PIN5_gc = (0x45<<0),  /* Port A Pin 5 */
    EVSYS_CHANNEL1_PORTA_PIN6_gc = (0x46<<0),  /* Port A Pin 6 */
    EVSYS_CHANNEL1_PORTA_PIN7_gc = (0x47<<0),  /* Port A Pin 7 */
    EVSYS_CHANNEL1_PORTB_PIN0_gc = (0x48<<0),  /* Port B Pin 0 */
    EVSYS_CHANNEL1_PORTB_PIN1_gc = (0x49<<0),  /* Port B Pin 1 */
    EVSYS_CHANNEL1_PORTB_PIN2_gc = (0x4A<<0),  /* Port B Pin 2 */
    EVSYS_CHANNEL1_PORTB_PIN3_gc = (0x4B<<0),  /* Port B Pin 3 */
    EVSYS_CHANNEL1_PORTB_PIN4_gc = (0x4C<<0),  /* Port B Pin 4 */
    EVSYS_CHANNEL1_PORTB_PIN5_gc = (0x4D<<0),  /* Port B Pin 5 */
    EVSYS_CHANNEL1_PORTB_PIN6_gc = (0x4E<<0),  /* Port B Pin 6 */
    EVSYS_CHANNEL1_PORTB_PIN7_gc = (0x4F<<0),  /* Port B Pin 7 */
    EVSYS_CHANNEL1_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL1_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL1_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL1_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL1_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL1_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL1_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL1_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL1_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL1_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL1_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL1_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL1_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL1_t;

/* Channel 2 generator select */
typedef enum EVSYS_CHANNEL2_enum
{
    EVSYS_CHANNEL2_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL2_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL2_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL2_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL2_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL2_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL2_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL2_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL2_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL2_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL2_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL2_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL2_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL2_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL2_PORTC_PIN0_gc = (0x40<<0),  /* Port C Pin 0 */
    EVSYS_CHANNEL2_PORTC_PIN1_gc = (0x41<<0),  /* Port C Pin 1 */
    EVSYS_CHANNEL2_PORTC_PIN2_gc = (0x42<<0),  /* Port C Pin 2 */
    EVSYS_CHANNEL2_PORTC_PIN3_gc = (0x43<<0),  /* Port C Pin 3 */
    EVSYS_CHANNEL2_PORTC_PIN4_gc = (0x44<<0),  /* Port C Pin 4 */
    EVSYS_CHANNEL2_PORTC_PIN5_gc = (0x45<<0),  /* Port C Pin 5 */
    EVSYS_CHANNEL2_PORTC_PIN6_gc = (0x46<<0),  /* Port C Pin 6 */
    EVSYS_CHANNEL2_PORTC_PIN7_gc = (0x47<<0),  /* Port C Pin 7 */
    EVSYS_CHANNEL2_PORTD_PIN0_gc = (0x48<<0),  /* Port D Pin 0 */
    EVSYS_CHANNEL2_PORTD_PIN1_gc = (0x49<<0),  /* Port D Pin 1 */
    EVSYS_CHANNEL2_PORTD_PIN2_gc = (0x4A<<0),  /* Port D Pin 2 */
    EVSYS_CHANNEL2_PORTD_PIN3_gc = (0x4B<<0),  /* Port D Pin 3 */
    EVSYS_CHANNEL2_PORTD_PIN4_gc = (0x4C<<0),  /* Port D Pin 4 */
    EVSYS_CHANNEL2_PORTD_PIN5_gc = (0x4D<<0),  /* Port D Pin 5 */
    EVSYS_CHANNEL2_PORTD_PIN6_gc = (0x4E<<0),  /* Port D Pin 6 */
    EVSYS_CHANNEL2_PORTD_PIN7_gc = (0x4F<<0),  /* Port D Pin 7 */
    EVSYS_CHANNEL2_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL2_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL2_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL2_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL2_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL2_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL2_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL2_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL2_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL2_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL2_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL2_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL2_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL2_t;

/* Channel 3 generator select */
typedef enum EVSYS_CHANNEL3_enum
{
    EVSYS_CHANNEL3_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL3_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL3_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL3_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL3_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL3_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL3_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL3_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL3_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL3_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL3_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL3_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL3_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL3_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL3_PORTC_PIN0_gc = (0x40<<0),  /* Port C Pin 0 */
    EVSYS_CHANNEL3_PORTC_PIN1_gc = (0x41<<0),  /* Port C Pin 1 */
    EVSYS_CHANNEL3_PORTC_PIN2_gc = (0x42<<0),  /* Port C Pin 2 */
    EVSYS_CHANNEL3_PORTC_PIN3_gc = (0x43<<0),  /* Port C Pin 3 */
    EVSYS_CHANNEL3_PORTC_PIN4_gc = (0x44<<0),  /* Port C Pin 4 */
    EVSYS_CHANNEL3_PORTC_PIN5_gc = (0x45<<0),  /* Port C Pin 5 */
    EVSYS_CHANNEL3_PORTC_PIN6_gc = (0x46<<0),  /* Port C Pin 6 */
    EVSYS_CHANNEL3_PORTC_PIN7_gc = (0x47<<0),  /* Port C Pin 7 */
    EVSYS_CHANNEL3_PORTD_PIN0_gc = (0x48<<0),  /* Port D Pin 0 */
    EVSYS_CHANNEL3_PORTD_PIN1_gc = (0x49<<0),  /* Port D Pin 1 */
    EVSYS_CHANNEL3_PORTD_PIN2_gc = (0x4A<<0),  /* Port D Pin 2 */
    EVSYS_CHANNEL3_PORTD_PIN3_gc = (0x4B<<0),  /* Port D Pin 3 */
    EVSYS_CHANNEL3_PORTD_PIN4_gc = (0x4C<<0),  /* Port D Pin 4 */
    EVSYS_CHANNEL3_PORTD_PIN5_gc = (0x4D<<0),  /* Port D Pin 5 */
    EVSYS_CHANNEL3_PORTD_PIN6_gc = (0x4E<<0),  /* Port D Pin 6 */
    EVSYS_CHANNEL3_PORTD_PIN7_gc = (0x4F<<0),  /* Port D Pin 7 */
    EVSYS_CHANNEL3_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL3_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL3_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL3_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL3_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL3_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL3_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL3_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL3_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL3_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL3_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL3_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL3_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL3_t;

/* Channel 4 generator select */
typedef enum EVSYS_CHANNEL4_enum
{
    EVSYS_CHANNEL4_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL4_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL4_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL4_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL4_RTC_PIT_DIV8192_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL4_RTC_PIT_DIV4096_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL4_RTC_PIT_DIV2048_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL4_RTC_PIT_DIV1024_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL4_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL4_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL4_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL4_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL4_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL4_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL4_PORTE_PIN0_gc = (0x40<<0),  /* Port E Pin 0 */
    EVSYS_CHANNEL4_PORTE_PIN1_gc = (0x41<<0),  /* Port E Pin 1 */
    EVSYS_CHANNEL4_PORTE_PIN2_gc = (0x42<<0),  /* Port E Pin 2 */
    EVSYS_CHANNEL4_PORTE_PIN3_gc = (0x43<<0),  /* Port E Pin 3 */
    EVSYS_CHANNEL4_PORTF_PIN0_gc = (0x48<<0),  /* Port F Pin 0 */
    EVSYS_CHANNEL4_PORTF_PIN1_gc = (0x49<<0),  /* Port F Pin 1 */
    EVSYS_CHANNEL4_PORTF_PIN2_gc = (0x4A<<0),  /* Port F Pin 2 */
    EVSYS_CHANNEL4_PORTF_PIN3_gc = (0x4B<<0),  /* Port F Pin 3 */
    EVSYS_CHANNEL4_PORTF_PIN4_gc = (0x4C<<0),  /* Port F Pin 4 */
    EVSYS_CHANNEL4_PORTF_PIN5_gc = (0x4D<<0),  /* Port F Pin 5 */
    EVSYS_CHANNEL4_PORTF_PIN6_gc = (0x4E<<0),  /* Port F Pin 6 */
    EVSYS_CHANNEL4_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL4_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL4_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL4_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL4_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL4_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL4_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL4_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL4_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL4_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL4_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL4_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL4_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL4_t;

/* Channel 5 generator select */
typedef enum EVSYS_CHANNEL5_enum
{
    EVSYS_CHANNEL5_OFF_gc = (0x00<<0),  /* Off */
    EVSYS_CHANNEL5_UPDI_SYNCH_gc = (0x01<<0),  /* UPDI SYNCH character */
    EVSYS_CHANNEL5_RTC_OVF_gc = (0x06<<0),  /* Real Time Counter overflow */
    EVSYS_CHANNEL5_RTC_CMP_gc = (0x07<<0),  /* Real Time Counter compare */
    EVSYS_CHANNEL5_RTC_PIT_DIV512_gc = (0x08<<0),  /* Periodic Interrupt Timer output 0 */
    EVSYS_CHANNEL5_RTC_PIT_DIV256_gc = (0x09<<0),  /* Periodic Interrupt Timer output 1 */
    EVSYS_CHANNEL5_RTC_PIT_DIV128_gc = (0x0A<<0),  /* Periodic Interrupt Timer output 2 */
    EVSYS_CHANNEL5_RTC_PIT_DIV64_gc = (0x0B<<0),  /* Periodic Interrupt Timer output 3 */
    EVSYS_CHANNEL5_CCL_LUT0_gc = (0x10<<0),  /* Configurable Custom Logic LUT0 */
    EVSYS_CHANNEL5_CCL_LUT1_gc = (0x11<<0),  /* Configurable Custom Logic LUT1 */
    EVSYS_CHANNEL5_CCL_LUT2_gc = (0x12<<0),  /* Configurable Custom Logic LUT2 */
    EVSYS_CHANNEL5_CCL_LUT3_gc = (0x13<<0),  /* Configurable Custom Logic LUT3 */
    EVSYS_CHANNEL5_AC0_OUT_gc = (0x20<<0),  /* Analog Comparator 0 out */
    EVSYS_CHANNEL5_ADC0_RESRDY_gc = (0x24<<0),  /* ADC 0 Result Ready */
    EVSYS_CHANNEL5_PORTE_PIN0_gc = (0x40<<0),  /* Port E Pin 0 */
    EVSYS_CHANNEL5_PORTE_PIN1_gc = (0x41<<0),  /* Port E Pin 1 */
    EVSYS_CHANNEL5_PORTE_PIN2_gc = (0x42<<0),  /* Port E Pin 2 */
    EVSYS_CHANNEL5_PORTE_PIN3_gc = (0x43<<0),  /* Port E Pin 3 */
    EVSYS_CHANNEL5_PORTF_PIN0_gc = (0x48<<0),  /* Port F Pin 0 */
    EVSYS_CHANNEL5_PORTF_PIN1_gc = (0x49<<0),  /* Port F Pin 1 */
    EVSYS_CHANNEL5_PORTF_PIN2_gc = (0x4A<<0),  /* Port F Pin 2 */
    EVSYS_CHANNEL5_PORTF_PIN3_gc = (0x4B<<0),  /* Port F Pin 3 */
    EVSYS_CHANNEL5_PORTF_PIN4_gc = (0x4C<<0),  /* Port F Pin 4 */
    EVSYS_CHANNEL5_PORTF_PIN5_gc = (0x4D<<0),  /* Port F Pin 5 */
    EVSYS_CHANNEL5_PORTF_PIN6_gc = (0x4E<<0),  /* Port F Pin 6 */
    EVSYS_CHANNEL5_USART0_XCK_gc = (0x60<<0),  /* USART 0 XCK */
    EVSYS_CHANNEL5_USART1_XCK_gc = (0x61<<0),  /* USART 1 XCK */
    EVSYS_CHANNEL5_USART2_XCK_gc = (0x62<<0),  /* USART 2 XCK */
    EVSYS_CHANNEL5_SPI0_SCK_gc = (0x68<<0),  /* SPI 0 SCK */
    EVSYS_CHANNEL5_TCA0_OVF_LUNF_gc = (0x80<<0),  /* Timer/Counter A0 overflow / low byte timer underflow */
    EVSYS_CHANNEL5_TCA0_HUNF_gc = (0x81<<0),  /* Timer/Counter A0 high byte timer underflow */
    EVSYS_CHANNEL5_TCA0_CMP0_LCMP0_gc = (0x84<<0),  /* Timer/Counter A0 compare 0 / low byte timer compare 0 */
    EVSYS_CHANNEL5_TCA0_CMP1_LCMP1_gc = (0x85<<0),  /* Timer/Counter A0 compare 1 / low byte timer compare 1 */
    EVSYS_CHANNEL5_TCA0_CMP2_LCMP2_gc = (0x86<<0),  /* Timer/Counter A0 compare 2 / low byte timer compare 2 */
    EVSYS_CHANNEL5_TCB0_CAPT_gc = (0xA0<<0),  /* Timer/Counter B0 capture */
    EVSYS_CHANNEL5_TCB1_CAPT_gc = (0xA2<<0),  /* Timer/Counter B1 capture */
    EVSYS_CHANNEL5_TCB2_CAPT_gc = (0xA4<<0),  /* Timer/Counter B2 capture */
    EVSYS_CHANNEL5_TCB3_CAPT_gc = (0xA6<<0)   /* Timer/Counter B3 capture */
} EVSYS_CHANNEL5_t;

#define EVSYS_CHANNEL_OFF_gc              EVSYS_GENERATOR_OFF_gc
#define EVSYS_CHANNEL_UPDI_gc             EVSYS_GENERATOR_UPDI_gc
#define EVSYS_CHANNEL_RTC_OVF_gc          EVSYS_GENERATOR_RTC_OVF_gc
#define EVSYS_CHANNEL_RTC_CMP_gc          EVSYS_GENERATOR_RTC_CMP_gc
#define EVSYS_CHANNEL_CCL_LUT0_gc         EVSYS_GENERATOR_CCL_LUT0_gc
#define EVSYS_CHANNEL_CCL_LUT1_gc         EVSYS_GENERATOR_CCL_LUT1_gc
#define EVSYS_CHANNEL_CCL_LUT2_gc         EVSYS_GENERATOR_CCL_LUT2_gc
#define EVSYS_CHANNEL_CCL_LUT3_gc         EVSYS_GENERATOR_CCL_LUT3_gc
#define EVSYS_CHANNEL_AC0_OUT_gc          EVSYS_GENERATOR_AC0_OUT_gc
#define EVSYS_CHANNEL_ADC0_RESRDY_gc      EVSYS_GENERATOR_ADC0_RESRDY_gc
#define EVSYS_CHANNEL_USART0_XCK_gc       EVSYS_GENERATOR_USART0_XCK_gc
#define EVSYS_CHANNEL_USART1_XCK_gc       EVSYS_GENERATOR_USART1_XCK_gc
#define EVSYS_CHANNEL_USART2_XCK_gc       EVSYS_GENERATOR_USART2_XCK_gc
#define EVSYS_CHANNEL_USART3_XCK_gc       EVSYS_GENERATOR_USART3_XCK_gc
#define EVSYS_CHANNEL_SPI0_SCK_gc         EVSYS_GENERATOR_SPI0_SCK_gc
#define EVSYS_CHANNEL_TCA0_OVF_LUNF_gc    EVSYS_GENERATOR_TCA0_OVF_LUNF_gc
#define EVSYS_CHANNEL_TCA0_HUNF_gc        EVSYS_GENERATOR_TCA0_HUNF_gc
#define EVSYS_CHANNEL_TCA0_CMP0_LCMP0_gc  EVSYS_GENERATOR_TCA0_CMP0_gc
#define EVSYS_CHANNEL_TCA0_CMP1_LCMP1_gc  EVSYS_GENERATOR_TCA0_CMP1_gc
#define EVSYS_CHANNEL_TCA0_CMP2_LCMP2_gc  EVSYS_GENERATOR_TCA0_CMP2_gc
#define EVSYS_CHANNEL_TCB0_CAPT_gc        EVSYS_GENERATOR_TCB0_CAPT_gc
#define EVSYS_CHANNEL_TCB1_CAPT_gc        EVSYS_GENERATOR_TCB1_CAPT_gc
#define EVSYS_CHANNEL_TCB2_CAPT_gc        EVSYS_GENERATOR_TCB2_CAPT_gc
#define EVSYS_CHANNEL_TCB3_CAPT_gc        EVSYS_GENERATOR_TCB3_CAPT_gc

/* Software event on channel select */
typedef enum EVSYS_SWEVENTA_enum
{
    EVSYS_SWEVENTA_CH0_gc = (0x01<<0),  /* Software event on channel 0 */
    EVSYS_SWEVENTA_CH1_gc = (0x02<<0),  /* Software event on channel 1 */
    EVSYS_SWEVENTA_CH2_gc = (0x04<<0),  /* Software event on channel 2 */
    EVSYS_SWEVENTA_CH3_gc = (0x08<<0),  /* Software event on channel 3 */
    EVSYS_SWEVENTA_CH4_gc = (0x10<<0),  /* Software event on channel 4 */
    EVSYS_SWEVENTA_CH5_gc = (0x20<<0),  /* Software event on channel 5 */
    EVSYS_SWEVENTA_CH6_gc = (0x40<<0),  /* Software event on channel 6 */
    EVSYS_SWEVENTA_CH7_gc = (0x80<<0)   /* Software event on channel 7 */
} EVSYS_SWEVENTA_t;

/* User channel select */
typedef enum EVSYS_USER_enum
{
    EVSYS_USER_OFF_gc = (0x00<<0),       /* Off, No Eventsys Channel connected */
    EVSYS_USER_CHANNEL0_gc = (0x01<<0),  /* Connect user to event channel 0 */
    EVSYS_USER_CHANNEL1_gc = (0x02<<0),  /* Connect user to event channel 1 */
    EVSYS_USER_CHANNEL2_gc = (0x03<<0),  /* Connect user to event channel 2 */
    EVSYS_USER_CHANNEL3_gc = (0x04<<0),  /* Connect user to event channel 3 */
    EVSYS_USER_CHANNEL4_gc = (0x05<<0),  /* Connect user to event channel 4 */
    EVSYS_USER_CHANNEL5_gc = (0x06<<0),  /* Connect user to event channel 5 */
    EVSYS_USER_CHANNEL6_gc = (0x07<<0),  /* Connect user to event channel 6 */
    EVSYS_USER_CHANNEL7_gc = (0x08<<0)   /* Connect user to event channel 7 */
} EVSYS_USER_t;

/* CCL Look-Up Table 0 Signals select */
typedef enum PORTMUX_LUT0_enum
{
    PORTMUX_LUT0_DEFAULT_gc = (0x00<<0), /* Out: PA3 In: PA0, PA1, PA2 */
    PORTMUX_LUT0_ALT1_gc = (0x01<<0)     /* Out: PA6 In: PA0, PA1, PA2 */
} PORTMUX_LUT0_t;

/* CCL Look-Up Table 1 Signals select */
typedef enum PORTMUX_LUT1_enum
{
    PORTMUX_LUT1_DEFAULT_gc = (0x00<<1), /* Out: PC3 In: PC0, PC1, PC2 */
    PORTMUX_LUT1_ALT1_gc = (0x01<<1),    /* Out: PC6 In: PC0, PC1, PC2 */
} PORTMUX_LUT1_t;

/* CCL Look-Up Table 2 Signals select */
typedef enum PORTMUX_LUT2_enum
{
    PORTMUX_LUT2_DEFAULT_gc = (0x00<<2), /* Out: PD3 In: PD0, PD1, PD2 */
    PORTMUX_LUT2_ALT1_gc = (0x01<<2)     /* Out: PD6 In: PD0, PD1, PD2 */
} PORTMUX_LUT2_t;

/* Clock Select */
typedef enum RTC_CLKSEL_ALT_enum
{
    RTC_CLKSEL_OSC32K_gc = (0x00<<0),   /* 32.768 kHz from OSC32K */
    RTC_CLKSEL_OSC1K_gc = (0x01<<0),    /* 1.024 kHz from OSC32K */
    RTC_CLKSEL_XOSC32K_gc = (0x02<<0)   /* 32.768 kHz from XOSC32K */
} RTC_CLKSEL_ALT_t;

/* Event Action A select */
typedef enum TCA_SINGLE_EVACTA_enum
{
    TCA_SINGLE_EVACTA_CNT_POSEDGE_gc = (0x00<<1),  /* Count on positive edge event */
    TCA_SINGLE_EVACTA_CNT_ANYEDGE_gc = (0x01<<1),  /* Count on any edge event */
    TCA_SINGLE_EVACTA_CNT_HIGHLVL_gc = (0x02<<1),  /* Count on prescaled clock while event line is 1. */
    TCA_SINGLE_EVACTA_UPDOWN_gc = (0x03<<1)  /* Count on prescaled clock. Event controls count direction. Up-count when event line is 0, down-count when event line is 1. */
} TCA_SINGLE_EVACTA_t;

/* Clock Select */
typedef enum TCB_CLKSEL_ALT_enum
{
    TCB_CLKSEL_DIV1_gc = (0x00<<1),      /* CLK_PER */
    TCB_CLKSEL_DIV2_gc = (0x01<<1),      /* CLK_PER/2 */
    TCB_CLKSEL_TCA0_gc = (0x02<<1)       /* Use CLK_TCA from TCA0 */
} TCB_CLKSEL_ALT_t;

/* RS485 Mode internal transmitter select */
typedef enum USART_RS485_ALT_enum
{
    USART_RS485_DISABLE_gc = (0x00<<0), /* RS485 Mode disabled */
    USART_RS485_ENABLE_gc = (0x01<<0)   /* RS485 Mode enabled */
} USART_RS485_ALT_t;

#endif /* !defined (__ASSEMBLER__) */

/* EVSYS - Event System */
#define EVSYS_SWEVENTA          _SFR_MEM8(0x0180) /* EVSYS_STROBE   */
#define EVSYS_USERADC0START     _SFR_MEM8(0x01A8) /* EVSYS_USERADC0 */
#define EVSYS_USEREVSYSEVOUTA   _SFR_MEM8(0x01A9) /* EVSYS_USEREVOUTA */
#define EVSYS_USEREVSYSEVOUTB   _SFR_MEM8(0x01AA) /* EVSYS_USEREVOUTB */
#define EVSYS_USEREVSYSEVOUTC   _SFR_MEM8(0x01AB) /* EVSYS_USEREVOUTC */
#define EVSYS_USEREVSYSEVOUTD   _SFR_MEM8(0x01AC) /* EVSYS_USEREVOUTD */
#define EVSYS_USEREVSYSEVOUTE   _SFR_MEM8(0x01AD) /* EVSYS_USEREVOUTE */
#define EVSYS_USEREVSYSEVOUTF   _SFR_MEM8(0x01AE) /* EVSYS_USEREVOUTF */
#define EVSYS_USERUSART0IRDA    _SFR_MEM8(0x01AF) /* EVSYS_USERUSART0 */
#define EVSYS_USERUSART1IRDA    _SFR_MEM8(0x01B0) /* EVSYS_USERUSART1 */
#define EVSYS_USERUSART2IRDA    _SFR_MEM8(0x01B1) /* EVSYS_USERUSART2 */
#define EVSYS_USERUSART3IRDA    _SFR_MEM8(0x01B2) /* EVSYS_USERUSART3 */
#define EVSYS_USERTCA0CNTA      _SFR_MEM8(0x01B3) /* EVSYS_USERTCA0 */
#define EVSYS_USERTCB0CAPT      _SFR_MEM8(0x01B4) /* EVSYS_USERTCB0 */
#define EVSYS_USERTCB1CAPT      _SFR_MEM8(0x01B5) /* EVSYS_USERTCB1 */
#define EVSYS_USERTCB2CAPT      _SFR_MEM8(0x01B6) /* EVSYS_USERTCB2 */
#define EVSYS_USERTCB3CAPT      _SFR_MEM8(0x01B7) /* EVSYS_USERTCB3 */

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


/* EVSYS.SWEVENTA  bit masks and bit positions */
#define EVSYS_SWEVENTA_gm       0xFF    /* Software event on channel select group mask. */
#define EVSYS_SWEVENTA_gp       0       /* Software event on channel select group position. */
#define EVSYS_SWEVENTA_0_bm     (1<<0)  /* Software event on channel select bit 0 mask. */
#define EVSYS_SWEVENTA_0_bp     0       /* Software event on channel select bit 0 position. */
#define EVSYS_SWEVENTA_1_bm     (1<<1)  /* Software event on channel select bit 1 mask. */
#define EVSYS_SWEVENTA_1_bp     1       /* Software event on channel select bit 1 position. */
#define EVSYS_SWEVENTA_2_bm     (1<<2)  /* Software event on channel select bit 2 mask. */
#define EVSYS_SWEVENTA_2_bp     2       /* Software event on channel select bit 2 position. */
#define EVSYS_SWEVENTA_3_bm     (1<<3)  /* Software event on channel select bit 3 mask. */
#define EVSYS_SWEVENTA_3_bp     3       /* Software event on channel select bit 3 position. */
#define EVSYS_SWEVENTA_4_bm     (1<<4)  /* Software event on channel select bit 4 mask. */
#define EVSYS_SWEVENTA_4_bp     4       /* Software event on channel select bit 4 position. */
#define EVSYS_SWEVENTA_5_bm     (1<<5)  /* Software event on channel select bit 5 mask. */
#define EVSYS_SWEVENTA_5_bp     5       /* Software event on channel select bit 5 position. */
#define EVSYS_SWEVENTA_6_bm     (1<<6)  /* Software event on channel select bit 6 mask. */
#define EVSYS_SWEVENTA_6_bp     6       /* Software event on channel select bit 6 position. */
#define EVSYS_SWEVENTA_7_bm     (1<<7)  /* Software event on channel select bit 7 mask. */
#define EVSYS_SWEVENTA_7_bp     7       /* Software event on channel select bit 7 position. */


/* Other Alias and Dummy */
#define TCA_SINGLE_RUNSTDBY_bm  0       /* Run in Standby bit mask. (dummy) */
#define TCA_SINGLE_RUNSTDBY_bp  7       /* Run in Standby bit position. */
#define TCA_SPLIT_RUNSTDBY_bm   0       /* Run in Standby bit mask. (dummy) */
#define TCA_SPLIT_RUNSTDBY_bp   7       /* Run in Standby bit position. */
#define TCB_CASCADE_bm          0       /* Cascade two timers bit mask. (dummy) */
#define TCB_CASCADE_bp          5       /* Cascade two timers bit position. */

#define TCA_SINGLE_CNTAEI_bm    (1<<0)  /* Count on Event Input A bit mask. */
#define TCA_SINGLE_CNTAEI_bp    0       /* Count on Event Input A bit position. */

#ifndef SLEEP_MODE_ADC
#define SLEEP_MODE_ADC          SLEEP_MODE_IDLE
#endif

#define SWEVENTA        STROBE
#define USERADC0START   USERADC0
#define USEREVSYSEVOUTA USEREVOUTA
#define USEREVSYSEVOUTB USEREVOUTB
#define USEREVSYSEVOUTC USEREVOUTC
#define USEREVSYSEVOUTD USEREVOUTD
#define USEREVSYSEVOUTE USEREVOUTE
#define USEREVSYSEVOUTF USEREVOUTF
#define USERUSART0IRDA  USERUSART0
#define USERUSART1IRDA  USERUSART1
#define USERUSART2IRDA  USERUSART2
#define USERUSART3IRDA  USERUSART3
#define USERTCA0CNTA    USERTCA0
#define USERTCB0CAPT    USERTCB0
#define USERTCB1CAPT    USERTCB1
#define USERTCB2CAPT    USERTCB2
#define USERTCB3CAPT    USERTCB3


// end of code
