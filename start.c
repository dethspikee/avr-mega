#include "usart/usart.h"

#define BAUD_RATE 9600


int main(void) {
    USART_Init_TX(BAUD_RATE);
    return 0;
}
