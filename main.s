.thumb

.include "init/adresses.s"
.global _start                          @ Make start function global so the linker can see it later
.include "init/vectortable.s"

.thumb_func				                      @ Because of Thumb mode
_start:                                 @ Start Request Handler

.include "init/hardware.s"

@ Main Loop

loop:

  ldr		r0, = SPI1_DR

  @ldr		r0, = SPI1_DR
  @ldr		r1, = 0b010000011  
  @str		r1, [r0]

  @bl    wait

b loop

@ Strings

.include "data/strings.s"

@ Functions

.ltorg @ Directive to move literal pool here
.include "functions/wait.s"
.include "functions/putchar.s"

@ Interrupt Request Handlers

.include "irqhandlers/default.s"
.include "irqhandlers/hardfault.s"
.include "irqhandlers/systick.s"
.include "irqhandlers/usart2.s"
.include "irqhandlers/tim6.s"
