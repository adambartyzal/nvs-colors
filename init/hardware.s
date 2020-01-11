@ Hardware Inicialization:

@ RCC

ldr   r2, = (1 << 19) | (1 << 17) | (1 << 0) @ 19 = GPIOC, 18 = GPIOB, 17 = GPIOA, 0 = DMA
ldr   r0, = RCC_AHBENR
ldr	  r1, [r0]
bic		r1, r2 
orr		r1, r2
str   r1, [r0]

ldr   r0, = RCC_CFGR
ldr   r1, = 10 << 18 | 1 << 1 @ PLL Mutliptication (4MHz) * 12 = 48 MHz
str   r1, [r0]

ldr		r2, = 1 << 24 @ PLLON
ldr   r0, = RCC_BASE
ldr	  r1, [r0]
bic		r1, r2
orr		r1, r2
str   r1, [r0]

nop
nop
nop
nop
nop

ldr   r0, = RCC_APB2ENR @ SPI1 En
ldr   r1, = 1 << 12 
str   r1, [r0]

@ GPIOA (not to use PA9 and PA10 .. SWDIO .. it will break debug)

ldr		r2, = 3 << (2*7)
ldr		r0, = GPIOA_MODER @ 0 = IN, 1 = OUT, 2 = Alternative, 3 =Analog
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 2 << (2*7)
orr		r1, r1, r2
str		r1, [r0]

ldr		r2, = 3 << (2*7)	
ldr		r0, = GPIOA_OSPEEDR @ x0 = low speed, 01 = medium speed, 10 = high speed
ldr		r1, [r0]
bic		r1, r1, r2
ldr		r2, = 2 << (2*7) 
orr		r1, r1, r2
str		r1, [r0]

@ DMA

ldr		r0, = DMA_CPAR3
ldr		r1, = SPI1_DR
str		r1, [r0]

ldr		r0, = DMA_CMAR3
ldr		r1, = begin
str		r1, [r0]

ldr		r0, = DMA_CNDTR3
ldr		r1, = 4 + 8 * 24 + 64 @ incremetation count
str		r1, [r0]

@ [13, 12] = Priority, [11,10] = mem size, [9,8] = Periph size, 7 = memory increment, 5 = circular, 4 = read from memory, 0 = enable ch.
ldr		r0, = DMA_CCR3
ldr		r1, = 1 << 13 | 1 << 12 | 1 << 7 | 1 << 4 | 1 << 0 @ byte
str		r1, [r0]

@ SPI

ldr   r0, = SPI1_CR2 @ [11:8] = size of data, 1 Tx DMA channel enable
ldr   r1, = 7 << 8 | 1 << 1 @ 12 bits
str   r1, [r0]

@ 9 = Software slave, 8 = slave set to 1 (prevents mode err), 7 = LSB first  [5:3] = PLL DIV
ldr   r0, = SPI1_CR1
ldr   r1, = 1 << 9 | 1 << 8 | 1 << 6 | 2 << 3 | 1 << 2 | 1 << 0 @ MSB first, fclk / 8 = 6
str   r1, [r0]

