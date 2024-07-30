.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global _start
.global Default_Handler

.section .isr_vector, "a", %progbits
.type _start, %function
_start:
    .word _estack
    .word Reset_Handler
    .word NMI_Handler
    .word HardFault_Handler
    .word MemManage_Handler
    .word BusFault_Handler
    .word UsageFault_Handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word SVC_Handler
    .word DebugMon_Handler
    .word 0
    .word PendSV_Handler
    .word SysTick_Handler

.section .text.Reset_Handler
Reset_Handler:
    LDR R0, =_estack
    MOV SP, R0
    BL main
    B .

Default_Handler:
    B .
