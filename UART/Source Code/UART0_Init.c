#include <stdint.h>

#define SYSCTL_RCGCUART (*((volatile unsigned long *)0x400FE618)) // System Control Register for enabling UART clock
#define UART0_BASE      0x4000C000 // Base address of UART0 module

#define UART0_CTL       (*((volatile unsigned long *)(UART0_BASE + 0x030))) // UART Control Register
#define UART0_IBRD      (*((volatile unsigned long *)(UART0_BASE + 0x024))) // UART Integer Baud-Rate Divisor
#define UART0_FBRD      (*((volatile unsigned long *)(UART0_BASE + 0x028))) // UART Fractional Baud-Rate Divisor
#define UART0_CC        (*((volatile unsigned long *)(UART0_BASE + 0xFC8))) // UART Clock Control
#define UART0_LCRH      (*((volatile unsigned long *)(UART0_BASE + 0x02C))) // UART Line Control
#define UART0_FR        (*((volatile unsigned long *)(UART0_BASE + 0x018))) // UART Flag Register
#define UART0_DR        (*((volatile unsigned long *)(UART0_BASE + 0x000))) // UART Data Register

/* UART0 initialization */
void UART0_Init()
{
    SYSCTL_RCGCUART |= 0x01;    // Enable clock to UART0
    UART0_CTL = 0;               // UART0 module disable
    UART0_IBRD = 104;            // for 9600 baud rate, integer = 104
    UART0_FBRD = 11;             // for 9600 baud rate, fractional = 11
    UART0_LCRH = (0x3<<5);       // data length 8-bit, no parity bit, no FIFO
    UART0_CC = 0x5;              // select system clock
    UART0_CTL = 0x301;           // Enable UART0 module, Rx and Tx
}
