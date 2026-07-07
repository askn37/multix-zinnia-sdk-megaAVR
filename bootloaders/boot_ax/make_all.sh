#!/usr/bin/env bash -e -

###
### megaAVR Generic
###

### megaAVR-0 28/32/40/48pin using USART0.PA0 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART0 UART=A0 LED=A7 PULLUP_RX=1

### megaAVR-0 28/32/40/48pin using USART0.PA4 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART0 UART=A4 LED=A7 PULLUP_RX=1

### megaAVR-0 28/32/40/48pin using USART1.PC0 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART1 UART=C0 LED=A7 PULLUP_RX=1

### megaAVR-0 28/32/40/48pin using USART2.PF0 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART2 UART=F0 LED=A7 PULLUP_RX=1

### megaAVR-0 32/48pin using USART2.PF4 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART2 UART=F4 LED=A7 PULLUP_RX=1

### megaAVR-0 40/48pin using USART1.PC4 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART1 UART=C4 LED=A7 PULLUP_RX=1

### megaAVR-0 48pin using USART3.PB0 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART3 UART=B0 LED=A7 PULLUP_RX=1

### megaAVR-0 48pin using USART3.PB4 LED.PA7
make atmega4809 BOOTNAME=boot_atmega_UART3 UART=B4 LED=A7 PULLUP_RX=1

###
### megaAVR Alternate
###

### ATmega4809 48pin using USART1.PB0 LED.PB3 SW.PF6 for ATmega4809 Curiosity Nano
make atmega4809 BOOTNAME=boot_atmega_UART3 UART=B0 LED=F5 PULLUP_RX=1

###
### tinyAVR Generic
###

### tinyAVR-0/1 8pin using USART0.PA6 LED.PA3
make attiny402 BOOTNAME=boot_attiny_UART0 UART=A6 LED=A3 PULLUP_RX=1 PORSTRAP=1

### tinyAVR-0/1 8pin using USART0.PA1 LED.PA3
make attiny412 BOOTNAME=boot_attiny_UART0 UART=A1 LED=A3 PULLUP_RX=1 PORSTRAP=1

### tinyAVR-0/1/2 14/20/24pin using USART0.PB2 LED.PA7
make attiny804 BOOTNAME=boot_attiny_UART0 UART=B2 LED=A7 PULLUP_RX=1 PORSTRAP=1

### tinyAVR-0/1/2 14/20/24pin using USART0.PA1 LED.PA7
make attiny814 BOOTNAME=boot_attiny_UART0 UART=A1 LED=A7 PULLUP_RX=1 PORSTRAP=1

### tinyAVR-2 20/24pin using USART1.C2 LED.PA7
make attiny826 BOOTNAME=boot_attiny_UART1 UART=C2 LED=A7 PULLUP_RX=1 PORSTRAP=1

###
### tinyAVR Alternate
###

### ATtiny1607/1627 24pin using USART0.PB2 LED.PB7 SW.PC4 for ATtiny1607/1627 Curiosity Nano
make attiny1627 BOOTNAME=boot_attiny_UART0 UART=B2 LED=B7 PULLUP_RX=1 PORSTRAP=1

### ATtiny3217 24pin using USART0.PB2 LED.PA3 SW.PB7 for ATtiny3217 Curiosity Nano
make attiny3217 BOOTNAME=boot_attiny_UART0 UART=B2 LED=A3 PULLUP_RX=1 PORSTRAP=1

###
### Cleanup
###

make clean

# end of code
