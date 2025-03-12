.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global _reset
.global _vectors
.global _estack

.section .vectors, "a", %progbits
_vectors:
    .word  _estack      // Initial stack pointer (from linker script)
    .word  _reset       // Reset handler
    .word  Default_Handler  // NMI
    .word  Default_Handler  // HardFault
    .word  Default_Handler  // MemManage
    .word  Default_Handler  // BusFault
    .word  Default_Handler  // UsageFault
    .word  0              // Reserved
    .word  0              // Reserved
    .word  0              // Reserved
    .word  0              // Reserved
    .word  Default_Handler  // SVC
    .word  Default_Handler  // Debug
    .word  0              // Reserved
    .word  Default_Handler  // PendSV
    .word  Default_Handler  // SysTick

.section .text
.thumb_func
_reset:
    ldr sp, =_estack     // Load stack pointer
    bl main             // Jump to main()
    b .                 // Infinite loop if main() exits

.thumb_func
Default_Handler:
    b Default_Handler    // Infinite loop

.section .bss
_estack = 0x20020000; // Adjust to your STM32 RAM size

