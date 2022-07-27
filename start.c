#include "usart/usart.h"

int main(void) {
    InitUsart();
    while (1) {
        USART_Transmit(120);
    }
    return 0;
}
