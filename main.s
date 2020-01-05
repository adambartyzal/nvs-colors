.thumb

.include "init/adresses.s"
.global _start                          @ Make start function global so the linker can see it later
.include "init/vectortable.s"

.thumb_func				                      @ Because of Thumb mode
_start:                                 @ Start Request Handler

.include "init/hardware.s"

@ Main Loop

loop:

b loop

@ Functions

.ltorg @ Directive to move literal pool here
.include "functions/setpins.s"

@ Interrupt Request Handlers

.include "irqhandlers/default.s"
.include "irqhandlers/hardfault.s"
.include "irqhandlers/systick.s"
.include "irqhandlers/usart2.s"
.include "irqhandlers/tim6.s"
