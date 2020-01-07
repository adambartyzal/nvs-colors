.thumb

.include "init/adresses.s"
.global _start                          @ Make start function global so the linker can see it later
.include "init/vectortable.s"

.thumb_func				                      @ Because of Thumb mode
_start:                                 @ Start Request Handler

.include "init/hardware.s"

@ Main Loop

loop:

  @ enable dma
  ldr		r0, = DMA_CCR4
  ldr		r1, [r0]
  ldr		r2, = 1
  orr		r1, r1, r2
  str		r1, [r0]

  bl    wait

b loop

@ Strings

.include "data/strings.s"

@ Functions

.ltorg @ Directive to move literal pool here
.include "functions/wait.s"

@ Interrupt Request Handlers

.include "irqhandlers/default.s"
.include "irqhandlers/hardfault.s"
.include "irqhandlers/systick.s"
.include "irqhandlers/usart2.s"
.include "irqhandlers/tim6.s"
