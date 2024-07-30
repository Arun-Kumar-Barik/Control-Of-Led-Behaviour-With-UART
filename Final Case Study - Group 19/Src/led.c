#include "stm32f446xx.h"

#define LED_PIN 5
#define BUTTON_PIN 13

void LED_Init(void) {
    // Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA5 as output
    GPIOA->MODER |= (1 << (LED_PIN * 2));
}

void Button_Init(void) {
    // Enable clock for GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Configure PC13 as input
    GPIOC->MODER &= ~(3 << (BUTTON_PIN * 2));
}

int Button_Pressed(void) {
    return !(GPIOC->IDR & (1 << BUTTON_PIN));
}

void LED_Blinking(void) {
    static uint32_t delay = 200;  // Initial delay in milliseconds
    static uint8_t press_count = 0;

    while (1) {
        if (Button_Pressed()) {
            UART_SendChar('B'); // To Verify whether button is actually pressed
            press_count++;
            if (press_count >= 4) {
                press_count = 0;
                delay = 200;  // Reset to initial delay
            } else {
                delay += 200;  // Increase delay
            }
            while (Button_Pressed()); // Wait for button release
        }
        GPIOA->ODR ^= (1 << LED_PIN);
        for (volatile uint32_t i = 0; i < delay * 1000; i++); // Simple delay
    }
}

