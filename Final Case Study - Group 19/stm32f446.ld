/* Linker script for STM32F446 */
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .text : {
        *(.isr_vector)
        *(.text*)
        *(.rodata*)
    } > FLASH

    .data : {
        *(.data*)
    } > RAM AT > FLASH

    .bss : {
        *(.bss*)
    } > RAM

    ._user_heap_stack : {
        . = ALIGN(8);
        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + 0x2000;
        . = ALIGN(8);
        PROVIDE ( _estack = . );
    } > RAM
}
