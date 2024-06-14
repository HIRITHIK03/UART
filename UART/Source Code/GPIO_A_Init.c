#include <stdint.h>

#define SYSCTL_RCGCGPIO (*((volatile unsigned long *)0x400FE608)) // System Control Register for enabling GPIO clock
#define GPIO_PORTA_BASE 0x40058000 // Base address of PORTA GPIO module

#define GPIO_PORTA_DEN  (*((volatile unsigned long *)(GPIO_PORTA_BASE + 0x51C))) // GPIO Port A Digital Enable
#define GPIO_PORTA_AFSEL (*((volatile unsigned long *)(GPIO_PORTA_BASE + 0x420))) // GPIO Port A Alternate Function Select
#define GPIO_PORTA_AMSEL (*((volatile unsigned long *)(GPIO_PORTA_BASE + 0x528))) // GPIO Port A Analog Mode Select
#define GPIO_PORTA_PCTL (*((volatile unsigned long *)(GPIO_PORTA_BASE + 0x52C))) // GPIO Port A Control

// Function for GPIO Port A Initialization
void GPIO_A_Init()
{
    SYSCTL_RCGCGPIO |= 0x01;    // Enable clock to PORTA for PA0/Rx and PA1/Tx

    /* UART0 TX and RX use PA0 and PA1. Configure them digital and enable alternate function */
    GPIO_PORTA_DEN |= 0x03;     // Set PA0 and PA1 as digital
    GPIO_PORTA_AFSEL |= 0x03;   // Use PA0, PA1 alternate function
    GPIO_PORTA_AMSEL &= ~0x03;  // Turn off analog function

    /* Configure PA0 and PA1 for UART */
    GPIO_PORTA_PCTL |= (1<<0) | (1<<4); // Enable UART pins on PA0 and PA1
}
