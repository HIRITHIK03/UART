#include "UART0_Transmitter.h"
#include "GPIO_A_Init.h"
#include "UART0_Init.h"
#include "Delay.h"

int main(void) {

    /* GPIO Port A initialization */
    GPIO_A_Init();

    /* UART0 initialization */
    UART0_Init();

    Delay(1000000); // Delay

    // Infinite Loop
    while(1)
    {
        char *name="HIRITHIK ROSHAN ";
        while(*name!='\0') {
            UART0_Transmitter(*name++); // Transmit characters of the name
        }
        UART0_Transmitter(' '); // Transmit a space
        Delay(1000000); // Delay
    }
}
