#include "usart.h"

#define IO_DATA_REG                     (* (volatile char *) (0xC6))
#define BAUD_RATE_REG_HIGH              (* (volatile char *) (0xC5))
#define BAUD_RATE_REG_LOW               (* (volatile char *) (0xC4))
#define CTL_AND_STATUS_REG_C            (* (volatile char *) (0xC2))
#define CTL_AND_STATUS_REG_B            (* (volatile char *) (0xC1))
#define CTL_AND_STATUS_REG_A            (* (volatile char *) (0xC0))
#define INPUT_BAUD                      9600L
#define F_OSC                           1000000L
#define OUTPUT_BAUD                     (((F_OSC) / (8L * INPUT_BAUD)) - 1)


void InitUsart(void) {
    /* Set baud rate */
    BAUD_RATE_REG_HIGH = (unsigned char) (OUTPUT_BAUD >> 8);
    BAUD_RATE_REG_LOW = (unsigned char) OUTPUT_BAUD;

    // Enable receiver and transmitter
    CTL_AND_STATUS_REG_B |= 0x18;

    // Set double transmission speed
    CTL_AND_STATUS_REG_A |= 0x02;

    // Set frame format; 8 bit data + 2 stop bits
    // they work by default

}

void USART_Transmit(unsigned char data){
  IO_DATA_REG = data;                                            /* send data */
}
