#include "stm32f446xx.h"

void UART_Init(void);
void UART_SendChar(char c);
char UART_ReceiveChar(void);
void LED_Init(void);
void Button_Init(void);
void LED_Blinking(void);
void PWM_Init(void);
void PWM_SetDutyCycle(uint8_t duty_cycle);
void LED_PWM_Control(void);
void Menu(void);

int main(void) {
    UART_Init();
    LED_Init();
    Button_Init();
    PWM_Init();

    Menu();

}
