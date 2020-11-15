 #include "hardware.h"

void initGPIOs () {
  RCC->AHBENR |= 1 << 17; // 19 = GPIOC, 18 = GPIOB, 17 = GPIOA,
  GPIOA->MODER |= 2 << (2 * 7) | 1 << (2 * 5) | 2 << (2 * 2); // PA7 = SPI MOSI, PA5 = LED, PA2 USART TX, PA0 = EXTI
  GPIOA->OSPEEDR |= 2 << (2 * 7) | 2 << (2 * 2) | 3 << (0 * 2);
  GPIOA->PUPDR |= 1 << 0;
  GPIOA->AFRL |= 1 << (2 * 4); // USART2 TX
}

void initDMA () {
  RCC->AHBENR |= 1 << 0; // Clock to DMA
  DMA1->CPAR3 |= (uint32_t) &SPI1->DR;
  DMA1->CCR3 |= 1 << 13 | 1 << 12 | 1 << 7 | 1 << 4 | 1 << 1;
}

void pushDMA (uint8_t data[], int sizeOfData) {
  DMA1->CMAR3 = (uint32_t) data;
  DMA1->CNDTR3 = sizeOfData;
  DMA1->CCR3 |= 1;
}

void initSPI () {
  RCC->APB2ENR |= 1 << 12;
  SPI1->CR2 &= 0;
  SPI1->CR2 |= 7 << 8 | 1 << 1;
  SPI1->CR1 |= 1 << 9 | 1 << 8 | 1 << 6 | 2 << 3 | 1 << 2 | 1 << 0;
}

void systickInit () {
  STK->RVR |= (uint32_t) & STK->CALIB;
  STK->CVR &= ~0;
  STK->CVR |= 1;
  STK->CSR |= 1 << 1 | 1 << 0;
}

void tim6Init () {
  RCC->APB1ENR |= 1 << 4;
  TIM6->CR1 &= 0;
  TIM6->DIER |= 1;
  TIM6->PSC |= 12000;
  TIM6->ARR &= 0;
  TIM6->ARR |= 0x7a;
  TIM6->CNT |= 0x7a;
  TIM6->CR1 |= 1;
}

void tim14Init () {
  RCC->APB1ENR |= 1 << 8;
  TIM14->CR1 &= 0;
  TIM14->DIER |= 1;
  TIM14->PSC |= 12000;
  TIM14->ARR &= 0;
  TIM14->ARR |= 0x5FF;
  TIM14->CNT |= 0x5FF;
  TIM14->CR1 |= 1;
}

void nvicInit () {
  NVIC->ISER |= 1 << 19 | 1 << 17 | 1 << 10 | 1 << 5; //19 = TIM14, 17 = TIM6, 11 = DMA CH 4-5, 10 = DMA CH 2-3, 6 = EXTI2_3, , 6 = EXTI0_1
}

void initUsart2 () {
  RCC->APB1ENR |= 1 << 17;
  USART2->BRR &= 0;
  USART2->BRR |= 48000000/9600;
  //USART2->CR3 |= 1 << 7; // ENABLE DMA
  USART2->CR1 |= 1 << 3 | 1 << 0; // TX EN, RX EN, USART EN (| 1 << 2 )
}

void initExti () {
  RCC->APB2ENR |= 1 << 0; // Enable SYSCFG
  SYSCFG->EXTICR1 &= ~ 15 << (4 * 0); // MUX PA0 (unnecessary at startup)
  EXTI->IMR |= 1 << 0;
  EXTI->FTSR |= 1 << 0;
}

void ledOn () {
  GPIOA->BSRR |= (1 << 5);
}

void ledOff () {
  GPIOA->BSRR |= (1 << 5) << 16;
}