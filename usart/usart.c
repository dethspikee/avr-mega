#include "usart.h"

#define UBRRnH                          (* (volatile char *) (0xC5))
#define UBRRnL                          (* (volatile char *) (0xC4))
#define UCSRnB                          (* (volatile char *) (0xC1))
#define UCSRnC                          (* (volatile char *) (0xC2))
#define ENABLE_TRANSMITTER_ONLY         (0x08)


void USART_Init_TX(unsigned int baud) {
    /* Set baud rate */
    UBRRnH = (unsigned char) (baud >> 8);
    UBRRnL = (unsigned char) baud;
    /* Enable transmitter only */
    UCSRnB |= (unsigned char) ENABLE_TRANSMITTER_ONLY;
    /* Set frame format: 8 data bits and 2 stop bits */
    UCSRnC |= (unsigned char) 0x0D; 
}
