#include "stm32f446xx.h"

void Menu(void) {
    char command;

    while (1) {
        UART_SendChar('M');
        UART_SendChar('e');
        UART_SendChar('n');
        UART_SendChar('u');
        UART_SendChar(':');
        UART_SendChar('\n');
        UART_SendChar('1');
        UART_SendChar('.');
        UART_SendChar(' ');
        UART_SendChar('L');
        UART_SendChar('E');
        UART_SendChar('D');
        UART_SendChar(' ');
        UART_SendChar('B');
        UART_SendChar('l');
        UART_SendChar('i');
        UART_SendChar('n');
        UART_SendChar('k');
        UART_SendChar('i');
        UART_SendChar('n');
        UART_SendChar('g');
        UART_SendChar('\n');
        UART_SendChar('2');
        UART_SendChar('.');
        UART_SendChar(' ');
        UART_SendChar('L');
        UART_SendChar('E');
        UART_SendChar('D');
        UART_SendChar(' ');
        UART_SendChar('P');
        UART_SendChar('W');
        UART_SendChar('M');
        UART_SendChar(' ');
        UART_SendChar('C');
        UART_SendChar('o');
        UART_SendChar('n');
        UART_SendChar('t');
        UART_SendChar('r');
        UART_SendChar('o');
        UART_SendChar('l');
        UART_SendChar('\n');
        UART_SendChar('3');
        UART_SendChar('.');
        UART_SendChar(' ');
        UART_SendChar('E');
        UART_SendChar('x');
        UART_SendChar('i');
        UART_SendChar('t');
        UART_SendChar('\n');
        UART_SendChar('E');
        UART_SendChar('n');
        UART_SendChar('t');
        UART_SendChar('e');
        UART_SendChar('r');
        UART_SendChar(' ');
        UART_SendChar('y');
        UART_SendChar('o');
        UART_SendChar('u');
        UART_SendChar('r');
        UART_SendChar(' ');
        UART_SendChar('c');
        UART_SendChar('h');
        UART_SendChar('o');
        UART_SendChar('i');
        UART_SendChar('c');
        UART_SendChar('e');
        UART_SendChar(':');
        UART_SendChar(' ');

        command = UART_ReceiveChar();
        UART_SendChar(command); // Echo the received character for debugging

        switch (command) {
            case '1':
                LED_Blinking();
                break;
            case '2':
                LED_PWM_Control();
                break;
            case '3':
                UART_SendChar('E');
                UART_SendChar('x');
                UART_SendChar('i');
                UART_SendChar('t');
                UART_SendChar('i');
                UART_SendChar('n');
                UART_SendChar('g');
                UART_SendChar('.');
                UART_SendChar('.');
                UART_SendChar('.');
                UART_SendChar('\n');
                return;
            default:
                UART_SendChar('I');
                UART_SendChar('n');
                UART_SendChar('v');
                UART_SendChar('a');
                UART_SendChar('l');
                UART_SendChar('i');
                UART_SendChar('d');
                UART_SendChar(' ');
                UART_SendChar('c');
                UART_SendChar('h');
                UART_SendChar('o');
                UART_SendChar('i');
                UART_SendChar('c');
                UART_SendChar('e');
                UART_SendChar('.');
                UART_SendChar(' ');
                UART_SendChar('T');
                UART_SendChar('r');
                UART_SendChar('y');
                UART_SendChar(' ');
                UART_SendChar('a');
                UART_SendChar('g');
                UART_SendChar('a');
                UART_SendChar('i');
                UART_SendChar('n');
                UART_SendChar('.');
                UART_SendChar('\n');
                break;
        }
    }
}
