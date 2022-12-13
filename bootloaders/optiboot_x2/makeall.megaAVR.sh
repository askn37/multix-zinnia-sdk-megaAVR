#!/bin/sh -x

###
### Generic tinyAVR-0/1 8pin Standard Default USART using USERT0.PA6 LED.PA3
###

### tinyAVR-0/1 8pin LED.PA3 UART0.PA6/PA1
# make -f Makefile.megaAVR attiny412 TIMEOUT=1 BOOTNAME=bigboot_attiny_UART0 UARTTX=A6 LED=A3 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1 BIGBOOT=1
make -f Makefile.megaAVR attiny412 TIMEOUT=1 BOOTNAME=boot_attiny_UART0 UARTTX=A6 LED=A3 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR attiny412 TIMEOUT=1 BOOTNAME=boot_attiny_UART0 UARTTX=A1 LED=A3 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

###
### Generic tinyAVR-0/1/2 14/20/24pin Standard Default USART using USERT0.PB2 LED.PA7
###

### tinyAVR-0/1/2 14/20/24pin LED.PA7 UART0.PB2/PA1
# make -f Makefile.megaAVR attiny824 TIMEOUT=1 BOOTNAME=bigboot_attiny_UART0 UARTTX=B2 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1 BIGBOOT=1
make -f Makefile.megaAVR attiny824 TIMEOUT=1 BOOTNAME=boot_attiny_UART0 UARTTX=B2 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR attiny824 TIMEOUT=1 BOOTNAME=boot_attiny_UART0 UARTTX=A1 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

### alt tinyAVR-2 20/24pin LED.PA7 UART1.PC2
make -f Makefile.megaAVR attiny824 TIMEOUT=1 BOOTNAME=boot_attiny_UART1 UARTTX=C2 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

###
### Generic megaAVR-0 28/32/40/48pin Standard Default USART using USERT0.PA0 LED.PA7
###

### megaAVR-0 28/32/40/48pin LED.PA7 UART0.PA0/PA4 UART1.PC0 UART2.F0
# make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=bigboot_atmega_UART0 UARTTX=A0 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1 BIGBOOT=1
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART0 UARTTX=A0 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART0 UARTTX=A4 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART1 UARTTX=C0 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART2 UARTTX=F0 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

### alt megaAVR-0 32/48pin LED.PA7 UART2.PF4
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART2 UARTTX=F4 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

### alt megaAVR-0 40/48pin LED.PA7 UART1.PC4
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART1 UARTTX=C4 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

### alt megaAVR-0 48pin LED.PA7 UART3.PB0/PB4
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART3 UARTTX=B0 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1
make -f Makefile.megaAVR atmega4809 TIMEOUT=1 BOOTNAME=boot_atmega_UART3 UARTTX=B4 LED=A7 BAUD_RATE=115200 SKIP_BOOTLOADER_ON_POR=1

###
### Cleanup
###

make -f Makefile.megaAVR clean

# end of code
