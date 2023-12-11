/**
 * @file boot_ax.c
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 3.7
 * @date 2023-11-30
 *
 * @copyright Copyright (c) 2023 askn37 at github.com
 *
 */

/***

+++ OVERVIEW +++

This bootstrap loader firmware for moderAVR is based on the ATMEL STK500
version 1 protocol and is fully compatible with Arduino bootloaders.

When the firmware boots, the RESET information flag is checked and, in the
case of a WDT or software reset, the application code (starting at 0x200)
starts executing immediately. Otherwise, if a valid STK500 version 1
command is received within the timeout period, the UART will open and he
will start NVM operations.

Builds are possible with AVR-GCC and AVR-LIBC, but other compilers are not
considered. Binary code fits within 512 bytes.

Previously, the source code was a clone of "Optiboot", but this is no longer
the case. They, as a rule, only support older generation devices. For these
reasons, the source code published here has been rewritten.

Licensing and redistribution are subject to the MIT License.

***/

#include <avr/io.h>
#include "boot_ax.h"

#ifndef UART_BASE
  #warning UART is ignored for this chip (use UART=<TxD-PortPin> instead)
#endif

#ifndef USART
/*** For an asynchronous UART, perform the following settings. ***/

/***
  The main clock control of AVR_EA/EB series is similar to tinyAVR/megaAVR.
  Select 16Mhz or 20MHz with FUSE, but the default division ratio is 6.
***/
  #define BAUD_SETTING_16 ((16000000L / FDIV * 64) / (16L * BAUD_RATE))
  #define BAUD_SETTING_20 ((20000000L / FDIV * 64) / (16L * BAUD_RATE))

  #if (BAUD_SETTING_16 < 64)
    #error Unachievable baud rate (too fast) BAUD_RATE
    #include "BUILD_STOP"
  #elif (BAUD_SETTING_16 > 65535)
    #error Unachievable baud rate (too slow) BAUD_RATE
    #include "BUILD_STOP"
  #elif (BAUD_SETTING_20 < 64)
    #error Unachievable baud rate (too fast) BAUD_RATE
    #include "BUILD_STOP"
  #elif (BAUD_SETTING_20 > 65535)
    #error Unachievable baud rate (too slow) BAUD_RATE
    #include "BUILD_STOP"
  #endif
#endif /* not USART */

/*
  This section provides an auxiliary capability
  for self-modifying the flash area.

  $0000 : Started Bootloader (POR)
  $0002 : nvm_spm function : magicnumber $9201
  $0004 : ret              :             $9508
  $0006 : nvm_cmd function : magicnumber $E99D, $BF94
  $0200 : appcode
 */

__attribute__((naked))
__attribute__((noreturn))
__attribute__((section (".init0")))
void vector_table (void) {
  __asm__ __volatile__ (
  R"#ASM#(
    RJMP  main
    ST    Z+, R0
    RET
  )#ASM#"
  );
  /* next is nvm_cmd */
}

/* This version has two snippets.
   One is to write 1 byte to the specified address using the ST command.
   Another is to simply write her CMD to her NVMCTRL and check the STATUS.
   (This family has LPM instructions but no SPM+ instructions) */

__attribute__((used))
__attribute__((noinline))
__attribute__((section (".init1")))
void nvm_cmd (uint8_t _nvm_cmd) {
  /* This function occupies 18 bytes of space. */
  _PROTECTED_WRITE_SPM(NVMCTRL_CTRLA, _nvm_cmd);
  while (NVMCTRL.STATUS & 3);
}

__attribute__((noinline))
void putch (uint8_t ch) {
  /* Put-Character will not send the character unless the buffer is empty. */
  loop_until_bit_is_set(UART_BASE.STATUS, USART_DREIF_bp);
  UART_BASE.TXDATAL = ch;
}

__attribute__((noinline))
uint8_t pullch (void) {
  /* Pull-Character blocks if buffer is empty.
     If nothing is received, WDT will eventually work. */
  uint8_t ch, er;
  loop_until_bit_is_set(UART_BASE.STATUS, USART_RXCIF_bp);
  er = UART_BASE.RXDATAH;
  ch = UART_BASE.RXDATAL;
  /* If there are no frame errors, pet the dog. */
  if ((er & USART_FERR_bm) == 0) wdt_reset();
#ifdef LED_PORT
  LED_PORT.IN |= _BV(LED_PIN);
#endif
  return ch;
}

__attribute__((noinline))
void end_of_packet (void) {
  if (pullch() != CRC_EOP) {
    /* If the End of Packet marks do not match, the system will be reset. */
    __asm__ __volatile__ ( "RJMP vector_table" );
  }
  putch(STK_INSYNC);
}

__attribute__((noinline))
void drop_packet (uint8_t count) {
  /* Closes the received packet by discarding
     the indicated number of characters. */
  do pullch(); while (--count);
  end_of_packet();
}

#if defined(LED_BLINK) && defined(LED_PORT)
inline static
void blink (void) {
  /* Makes the LED blink at a different rate than normal.
     This code uses about 10 bytes of extra space. */
  uint8_t count = LED_BLINK;
  do {
    LED_PORT.IN |= _BV(LED_PIN);
    /* delay assuming 3Mhz */
    uint16_t delay = 3000000U / 200;
    do {
      if (bit_is_set(UART_BASE.STATUS, USART_RXCIF_bp)) return;
    } while (--delay);
  }
  while (--count);
}
#endif

/* main program starts here */
__attribute__((OS_main))
int main (void) {
  /* It is preferable that these variables be allocated directly to registers. */
  register addr16_t address;
  register addr16_t length;
  register uint8_t ch;

  /* This is the first code that is executed.
     According to modernAVR specifications,
     interrupts are disabled and SP points to RAMEND. */

  /* Known-zero required by avr-libc. */
  __asm__ __volatile__ ( "CLR __zero_reg__" );

  /* Get the reset reason. The value is also copied to GPR0. */
  ch = RSTCTRL_RSTFR; /* get reset cause */
  RSTCTRL_RSTFR = ch; /* clear flags */
  GPIO_GPIOR0 = ch;      /* Backup so user code can be referenced */

  /* If the register is zero, consider it a user call and perform a software
     reset. This is just in case, so it consumes extra code space. */
  if (ch == 0) _PROTECTED_WRITE(RSTCTRL_SWRR, 1);

  /* WDT or soft reset executes user code */
  if (bit_is_set(GPIO_GPIOR0, RSTCTRL_WDRF_bp) || ch < 4) {
    __asm__ __volatile__ ( "RJMP appcode" );
  }

  /* Set LED pin as output */
#ifdef LED_PORT
  LED_PORT.DIR |= _BV(LED_PIN);
#endif

#ifdef FREQSEL
  /* Change the main clock division ratio if necessary */
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, FREQSEL);
#endif

#ifdef UART_PMUX_VAL
  /* PORTMUX setting.
     Should be omitted if no alternate is set. */
  UART_PMUX_REG = UART_PMUX_VAL;
#endif

#ifndef USART
/*** For an asynchronous UART, perform the following settings. ***/

/* Different settings are required depending on FUSE */
/* BAUDH is zero, so if you don't need it, just write BAUDL */
if (bit_is_set(FUSE_OSCCFG, FUSE_FREQSEL_0_bp)) {
  #if (BAUD_SETTING_16 < 256)
    UART_BASE.BAUDL = BAUD_SETTING_16;
  #else
    UART_BASE.BAUD = BAUD_SETTING_16;
  #endif
}
else {
  #if (BAUD_SETTING_20 < 256)
    UART_BASE.BAUDL = BAUD_SETTING_20;
  #else
    UART_BASE.BAUD = BAUD_SETTING_20;
  #endif
}

#endif /* not USART */

#ifdef RS485
  /*** For RS485 mode ***/
  #ifdef UART_XDIRPIN_BP
    #ifdef RS485_INVERT
  UART_XDIRCFG = PORT_INVEN_bm;
    #endif
    #ifdef RS485_SINGLE
  UART_BASE.CTRLA = USART_RS485_ENABLE_gc|_BV(1)|USART_LBME_bm;
    #else
  UART_BASE.CTRLA = USART_RS485_ENABLE_gc|_BV(1);
    #endif
  #else
    #error RS485 XDIR pin not USART exists
    #include "BUILD_STOP"
  #endif
#endif

#ifdef USART
  /*** For synchronous USART ***/
  #ifdef UART_XCKCFG
    #ifdef USART_INVERT
  UART_XCKCFG = PORT_INVEN_bm;
    #endif
  #else
    #error USART XCK pin not USART exists
    #include "BUILD_STOP"
  #endif
#endif

#if defined(RS485) && defined(UART_XDIRPIN)
  UART_TXPORT.DIR |= UART_XDIRPIN;
#elif defined(RS485) && defined(RS485_SINGLE)
  UART_TXPORT.DIR |= UART_TXPIN;
  UART_TXCFG = PORT_PULLUPEN_bm;
#elif defined(PULLUP_RX)
  /* RX pin pullup (RX is TX next GPIO).
     Normally, the TxD side is push-pull, so it is not required. */
  UART_RXCFG = PORT_PULLUPEN_bm;
#endif

#ifdef USART
  /* For synchronous USART */
  UART_BASE.CTRLC = USART_CHSIZE_8BIT_gc|USART_CMODE_SYNCHRONOUS_gc;
#else
  /* For asynchronous UART */
  UART_BASE.CTRLC = USART_CHSIZE_8BIT_gc;
#endif

  /* not interrupt, polling read-write UART started */
  #if defined(RS485) && defined(RS485_SINGLE)
  UART_BASE.CTRLB = USART_RXEN_bm|USART_TXEN_bm|USART_ODME_bm;
  #else
  UART_BASE.CTRLB = USART_RXEN_bm|USART_TXEN_bm;
  #endif

  /* At this stage, the UART only acts as a receiver.
     TxD pin is not configured as an output yet and remains Hi-Z */

#if defined(LED_BLINK) && defined(LED_PORT)
  /* LED flashing time is not included in WDT limit. */
  blink();
#elif defined(LED_PORT)
  /* Set noinit SRAM as a flag and make the LED blink
     alternately every time the WDT restarts. */
  if (++_SFR_MEM8(RAMEND - 256) & 1) LED_PORT.IN |= _BV(LED_PIN);
#endif

  /* This probably isn't necessary since WDT isn't started yet. */
  // loop_until_bit_is_clear(WDT_STATUS, WDT_SYNCBUSY_bp);

  /* Start WDT monitoring */
  _PROTECTED_WRITE(WDT_CTRLA, WDTPERIOD);

  /*** Forever loop: exits by causing WDT reset ***/
  for (;;) {
    /* get STK Command */
    ch = pullch();
    if (ch == STK_GET_PARAMETER) {
      ch = pullch();
      end_of_packet();
      if (ch == PAR_SW_MINOR)
        ch = BOOT_MINVER;
      else if (ch == PAR_SW_MAJOR)
        ch = BOOT_MAJVER;
      else
        ch = BOOT_HW_VER;
      putch(ch);
    }
    else if (ch == STK_SET_DEVICE) {
      /* SET_DEVICE is ignored */
      /* drop 20bytes */
      drop_packet(20);
    }
    else if (ch == STK_SET_DEVICE_EXT) {
      /* SET_DEVICE EXT is ignored */
      /* drop 5bytes */
      drop_packet(5);
    }
    else if (ch == STK_LOAD_ADDRESS) {
      /* LOAD_ADDRESS little endian */
      address.bytes[0] = pullch();
      address.bytes[1] = pullch();
      /* byte addressed mode */
      end_of_packet();
    }
    else if (ch == STK_PROG_PAGE) {
      /* Flash or EEPROM */
      /* Write memory block mode, length is big endian. */
      length.bytes[1] = pullch();
      length.bytes[0] = pullch();

      if (pullch() == 'F') {
        address.word += MAPPED_PROGMEM_START;
      }
      else {
        address.word += MAPPED_EEPROM_START;
      }

      /* Before complete wait. */
      nvm_cmd(NVMCTRL_CMD_NONE_gc);
      // while (NVMCTRL_STATUS & 3);

      /* Page buffer filling. */
      do *(address.bptr++) = pullch(); while (--length.word);

      /* Page Erase and Write. */
      nvm_cmd(NVMCTRL_CMD_PAGEERASEWRITE_gc);
      end_of_packet();
    }
    else if (ch == STK_READ_PAGE) {
      /* Read memory block mode, length is big endian. */
      length.bytes[1] = pullch();
      length.bytes[0] = pullch();
      if (pullch() == 'F') {
        address.word += MAPPED_PROGMEM_START;
      }
      else {
        address.word += MAPPED_EEPROM_START;
      }
      end_of_packet();
      do putch(*(address.bptr++)); while (--length.word);
    }
    else if (ch == STK_READ_SIGN) {
      /* READ SIGN - return actual device signature from SIGROW
         this enables the same binary to be ued on multiple chips. */
      end_of_packet();

      /* SIGROW_DEVICEID0 : This value is always fixed. */
      putch(0x1E);

      /* This value indicates the flash size and indicates
         whether or not there is a RAMPZ register. */
      putch(SIGROW_DEVICEID1);

      /* Inconsistent values to avoid duplicate SIGROW */
      putch(SIGROW_DEVICEID2);
    }
    else {
      #ifndef RS485_SINGLE
      /* The TxD pin is set to output only after passing here. */
      /* Normally STK_GET_SYNC executes this for the first time. */
      UART_TXPORT.DIR |= UART_TXPIN;
      #endif
      end_of_packet();
    }
    putch(STK_OK);
  } /* Forever loop */
}   /* End of main */

/*** This is a dummy application. It is not included in the output file. ***/

__attribute__((naked))
__attribute__((noreturn))
__attribute__((section( ".appcode")))
void appcode (void) {
  __asm__ __volatile__ ( "RJMP vector_table" );
}

/* end of code */