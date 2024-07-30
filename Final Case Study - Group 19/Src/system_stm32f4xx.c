#include "stm32f446xx.h"

void SystemInit(void) {
    // Set system clock to 16 MHz (HSI)
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY));
    RCC->CFGR = RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}
