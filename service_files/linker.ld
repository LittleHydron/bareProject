ENTRY(_vectors)  /* Set entry point */

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .vectors : {
        . = ALIGN(4);
        KEEP(*(.vectors))
    } > FLASH

    .text : {
        . = ALIGN(4);
        *(.text)
        *(.rodata)
        . = ALIGN(4);
    } > FLASH

    .data : {
        . = ALIGN(4);
        *(.data)
    } > RAM AT > FLASH

    .bss : {
        . = ALIGN(4);
        *(.bss)
    } > RAM
}

