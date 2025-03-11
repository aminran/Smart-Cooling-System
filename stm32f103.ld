/* Linker script for STM32F103 */
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text : {
        *(.vectors)       /* Interrupt Vector Table */
        *(.text*)         /* Program Code */
        *(.rodata*)       /* Read-Only Data */
    } > FLASH

    .data : {
        *(.data*)         /* Initialized Data */
    } > RAM AT> FLASH

    .bss : {
        *(.bss*)          /* Uninitialized Data */
    } > RAM
}
