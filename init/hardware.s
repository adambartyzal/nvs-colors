@ Hardware Inicialization:

@ RCC

ldr   r2, = (1 << 19) | (1 << 17) | (1 << 0) @ 19 = GPIOC, 18 = GPIOB, 17 = GPIOA, 0 = DMA
ldr   r0, = RCC_AHBENR
ldr	  r1, [r0]
bic		r1, r2 
orr		r1, r2
str   r1, [r0]

ldr		r2, = 1 << 17 @ | 1 << 4 @ 17 = USART 2, 4 = TIM6
ldr   r0, = RCC_APB1ENR
ldr	  r1, [r0]
bic		r1, r2
orr		r1, r2
str   r1, [r0]

@ GPIOA (not to use PA9 and PA10 .. SWDIO .. it will break debug)

ldr		r2, = 3 << (2*3) | 3 << (2*2)
ldr		r0, = GPIOA_MODER @ 0 = IN, 1 = OUT, 2 = Alternative, 3 =Analog
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 2 << (2*3) | 2 << (2*2)
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 3 << (2*3) | 3 << (2*2)	
ldr		r0, = GPIOA_OSPEEDR @ x0 = low speed, 01 = medium speed, 10 = high speed
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 2 << (2*3) | 2 << (2*2) 
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 15 << (4*2) | 15 << (4*3) @ A2 - TX, A3 - RX
ldr		r0, = GPIOA_AFRL  @ AFRL AF1 = USART, AF0 = TIM15
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2,= 1 << (2*4) | 1 << (3*4)	
orr		r1, r1, r2
str		r1, [r0]

@ USART 2

ldr		r2, = 0xFFFF
ldr		r0, = USART2_BRR
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 0x034D  @ if oversampling by 16 (0 << 15 OVER8 in CR1) USARTDIV = 8 000 000/9600 BRR = USARTDIV = 833d = 0341h
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 1 << 5 | 1 << 3 | 1 << 2 | 1 << 0 @ Enable Rx interrupt, TX, RX and USART
ldr		r0, = USART2_CR1
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << 3 | 1 << 2 | 1 << 0
orr		r1, r1, r2
str		r1, [r0]

@ DMA

ldr		r2, = 1 << 13 | 1 << 12 | 1 << 7 | 1 << 4 @ [13, 12] = Priority, [11,10] = mem size, [9,8] = Periph size, 7 = memory increment, 4 = read from memory, 0 = enable ch.
ldr		r0, = DMA_CCR4
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << 13 | 1 << 12 | 1 << 7 | 1 << 4
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 0xFFFFFFFF @ Clear all
ldr		r0, = DMA_CNDTR4
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 11 @ incremetation count
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 0xFFFFFFFF
ldr		r0, = DMA_CPAR4
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = USART2_TDR
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 0xFFFFFFFF
ldr		r0, = DMA_CMAR4
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = textReady
orr		r1, r1, r2
str		r1, [r0]
