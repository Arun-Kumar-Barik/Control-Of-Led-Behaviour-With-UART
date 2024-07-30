#include "stm32f446xx.h"

void UART_Init(void) {
    // Enable clocks for GPIOA and USART2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // Configure PA2 and PA3 for USART2
    GPIOA->MODER |= (2 << (2 * 2)) | (2 << (3 * 2)); // Alternate function mode
    GPIOA->AFR[0] |= (7 << (2 * 4)) | (7 << (3 * 4)); // AF7 for USART2

    // Configure USART2
    USART2->BRR = 0x0683; // 9600 baud rate @ 16 MHz
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; // Enable TX, RX, and USART
}


void UART_SendChar(char c) {
    while (!(USART2->SR & USART_SR_TXE));
    USART2->DR = c;
}

char UART_ReceiveChar(void) {
    while (!(USART2->SR & USART_SR_RXNE));
    return USART2->DR;
}

