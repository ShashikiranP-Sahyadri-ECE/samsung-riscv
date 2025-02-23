// VSDSquadron Mini UART Communication (Send "Start" Command)
#include <ch32v00x.h>
#include <debug.h>

void UART_Init() {
    // Enable UART clock
    RCC->APB2PCENR |= RCC_APB2Periph_USART1;

    // Configure PD5 (TX) as alternate function push-pull
    GPIOD->CFGLR &= ~(0xF << 20);  // Clear PD5 settings
    GPIOD->CFGLR |= (0x9 << 20);  // Set PD5 as AF push-pull

    // Configure PD6 (RX) as input floating
    GPIOD->CFGLR &= ~(0xF << 24); // Clear PD6 settings
    GPIOD->CFGLR |= (0x4 << 24);  // Set PD6 as input floating

    // Set baud rate to 9600 (for 48 MHz clock)
    USART1->BRR = 0x1A1;

    // Enable TX, RX and UART
    USART1->CTLR1 |= USART_CTLR1_TE | USART_CTLR1_RE | USART_CTLR1_UE;
}

void UART_SendChar(char c) {
    while (!(USART1->STATR & USART_STATR_TXE)); // Wait until TX buffer is empty
    USART1->DATAR = c;
}

void UART_SendString(const char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
}

char UART_ReceiveChar() {
    while (!(USART1->STATR & USART_STATR_RXNE)); // Wait for data
    return (char)USART1->DATAR;
}

int main() {
    UART_Init();

    while (1) {
        UART_SendString("Start\n"); // Send "Start" command every 5 seconds
        Delay_Ms(5000);

        if (USART1->STATR & USART_STATR_RXNE) { // If data is received
            char received = UART_ReceiveChar();
            UART_SendString("Received: ");
            UART_SendChar(received);
            UART_SendString("\n");
        }
    }
}