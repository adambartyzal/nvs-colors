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

@@ SysTick
@
@ldr		r2, = 1 << 1 | 1 << 0
@ldr   r0, = (STK_CSR)
@ldr   r1, [r0]
@bic   r1, r2
@orr   r1, r2
@str   r1, [r0]
@
@ldr   r0, = STK_CALIB
@ldr   r1, [r0]
@ldr   r0, = STK_RVR
@str   r1, [r0]
@
@ldr   r0, = STK_CVR
@ldr   r1, [r0]
@ldr   r2, = 0xFFFFFF
@bic   r1, r2
@ldr   r2, =1
@orr   r1, r2
@str   r1, [r0]

@ GPIOA (not to use PA9 and PA10 .. SWDIO .. it will break debug)

ldr		r2, = 3 << (2*5) | 3 << (2*4) | 3 << (2*3) | 3 << (2*2) | 3 << (2*1) | 3 << (2*0)	
ldr		r0, = GPIOA_MODER @ 0 = IN, 1 = OUT, 2 = Alternative, 3 =Analog
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << (2*5) | 1 << (2*4) | 2 << (2*3) | 2 << (2*2) | 1 << (2*1) | 1 << (2*0)
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0		
ldr		r0, = GPIOA_OTYPER  @0 = Push pull, 1 = Open Drain
ldr		r1, [r0]
bic		r1, r1, r2
str		r1, [r0]

ldr		r2, = 3 << (2*5) | 3 << (2*4) | 3 << (2*3) | 3 << (2*2) | 3 << (2*1) | 3 << (2*0)		
ldr		r0, = GPIOA_OSPEEDR @ x0 = low speed, 01 = medium speed, 10 = high speed
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << (2*5) | 1 << (2*4) | 2 << (2*3) | 2 << (2*2) | 1 << (2*1) | 1 << (2*0) 
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0	
ldr		r0, = GPIOA_PUPDR @ 00 = No, 01 = Pull up, 10 = Pull down, 11 = reserved 
ldr		r1, [r0]
bic		r1, r1, r2
str		r1, [r0]

ldr		r2, = 15 << (4*2) | 15 << (4*3) @ A2 - TX, A3 - RX
ldr		r0, = GPIOA_AFRL  @ AFRL AF1 = USART, AF0 = TIM15
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2,= 1 << (2*4) | 1 << (3*4)	
orr		r1, r1, r2
str		r1, [r0]

@ GPIOC

@ldr		r2, = 3 << (2*7) | 3 << (2*6) | 3 << (2*5) | 3 << (2*4) | 3 << (2*3) | 3 << (2*2) | 3 << (2*1) | 3 << (2*0)
@ldr		r0, = GPIOC_MODER @ 0 = IN, 1 = OUT, 2 = Alternative, 3 =Analog
@ldr		r1, [r0]
@bic		r1, r1, r2
@ldr		r2, =1 << (2*7) | 1 << (2*6) | 1 << (2*5) | 1 << (2*4) | 1 << (2*3) | 1 << (2*2) | 1 << (2*1) | 1 << (2*0)
@orr		r1, r1, r2
@str		r1, [r0]
@
@ldr		r2, = 1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0
@ldr		r0, = GPIOC_OTYPER  @ 0 = Push pull, 1 = Open Drain
@ldr		r1, [r0]
@bic		r1, r1, r2
@str		r1, [r0]
@
@ldr		r2, = 1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0	
@ldr		r0, = GPIOC_OSPEEDR @ x0 = low speed, 01 = medium speed, 10 = high speed
@ldr		r1, [r0]
@bic		r1, r1, r2
@ldr		r2, = 1 << 7 | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0	
@orr		r1, r1, r2
@str		r1, [r0]
@
@ldr		r2, = 3 << (2*7) | 3 << (2*6) | 3 << (2*5) | 3 << (2*4) | 3 << (2*3) | 3 << (2*2) | 3 << (2*1) | 3 << (2*0)
@ldr		r0, = GPIOC_PUPDR @ 00 = No, 01 = Pull up, 10 = Pull down, 11 = reserved
@ldr		r1, [r0]
@bic		r1, r1, r2
@str		r1, [r0]

@ USART 2

ldr		r2, = 0xFFFF
ldr		r0, = USART2_BRR
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 3 @ one pulse is 0,375 us long, 3 are 1,125 desired are 1,125 which should be fine
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 1 << 17 @ TX INV
ldr		r0, = USART2_CR2
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << 17
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 1 << 28 | 1 << 2 | 1 << 0 @ 28 = 7bits, 5 = Rx interrupt, 3 = TX En, 2 = RX En, 0 = USART En
ldr		r0, = USART2_CR1
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 1 << 28 | 1 << 2 | 1 << 0
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

@ TIM6

@ldr		r0, = TIM6_CR1
@ldr		r2, = 0 @ Turn off before setup
@str		r2, [r0]
@
@ldr		r0, = TIM6_DIER
@ldr		r2, = 1  @ Interrupt Enable
@str		r2, [r0]
@
@ldr		r0, = TIM6_PSC
@ldr		r2, = 0xFFFF  @ Max Divide
@str		r2, [r0]
@
@ldr		r0, = TIM6_ARR
@ldr		r2, = 0x7a  @ One Second
@str		r2, [r0]
@
@ldr		r0, = TIM6_CNT 
@ldr		r2, = 0x7a  @ Same as ARR
@str		r2, [r0]

@ldr		r0, = TIM6_CR1
@ldr		r2, = 1 @ Start timer count
@str		r2, [r0]

@ NVIC
   
ldr		r0, = NVIC_ISER
ldr		r2, = 1 << 17 @ 7 = EXTI4_15, 17 = TIM6, 28 = USART2
str		r2, [r0]

