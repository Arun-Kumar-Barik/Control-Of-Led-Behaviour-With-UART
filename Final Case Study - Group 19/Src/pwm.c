#include "stm32f446xx.h"

void PWM_Init(void) {
    // Enable clock for GPIOA and TIM2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Configure PA0 as alternate function (TIM2_CH1)
    GPIOA->MODER |= (2 << (0 * 2));
    GPIOA->AFR[0] |= (1 << (0 * 4)); // AF1 for TIM2

    // Configure TIM2 for PWM
    TIM2->PSC = 15; // Prescaler
    TIM2->ARR = 999; // Auto-reload register
    TIM2->CCMR1 |= (6 << 4); // PWM mode 1
    TIM2->CCER |= TIM_CCER_CC1E; // Enable channel 1
    TIM2->CR1 |= TIM_CR1_CEN; // Enable TIM2
}

void PWM_SetDutyCycle(uint8_t duty_cycle) {
    TIM2->CCR1 = duty_cycle * 10; // Set duty cycle (0-100)
}
void LED_PWM_Control(void) {
    static uint8_t intensity = 0;
    static uint8_t press_count = 0;

    while (1) {
        if (Button_Pressed()) {
            UART_SendChar('B'); // Debugging message for button press
            press_count++;
            if (press_count >= 4) {
                press_count = 0;
                intensity = 0;  // Reset to initial intensity
            } else {
                intensity += 64;  // Increase intensity (4 steps: 0, 64, 128, 192, 255)
            }
            PWM_SetDutyCycle(intensity);
            while (Button_Pressed()); // Wait for button release
        }
        for (volatile uint32_t i = 0; i < 1000000; i++); // Noticeable delay
    }
}

