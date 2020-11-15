  #include "irqHandlers.h"

void defaultIRQHandler(void) {
  
}

void hardfaultIRQHandler(void) {
  
}

void systickIRQHandler(void) {
  
}

void tim6IRQHandler(void) {
  //Clear Flags
  TIM6->SR &= 0;
	//Do Stuff

  ((GPIOA->ODR >> 5) & 1) ? ledOff() : ledOn();
  triColor(data, position);
	pushDMA(data, 320);
  position++;
  if (position >=5*8) position = 0;
}

void tim14IRQHandler(void) {
  //Clear Flags
  TIM14->SR &= 0;
	//Do Stuff
  TIM6->ARR = counter/128;
  TIM6->CNT = TIM6->ARR;
}

void usart2IRQHandler(void) {
  
}

void dma1ch1IRQHandler(void) {

}

void dma1ch23IRQHandler(void) {
  // Disable channel to configure it again
  DMA1->CCR3 &= ~1; 
  //Clear Flags
  int b = DMA1->ISR;
  DMA1->IFCR |= b;
}

void dma1ch45IRQHandler(void) { // USART
  //Clear Flags
  DMA1->CCR4 &= ~1;
  USART2->ICR |= 1 << 6 | 1 << 1;
  int b = DMA1->ISR;
  DMA1->IFCR |= b;
	//Do Stuff

}

void exti01IRQHandler(void) {
  //Clear Flags
  EXTI->PR |= 1 << 0  ;
	//Do Stuff
  counter = TIM14->CNT;
  TIM14->CNT = TIM14->ARR;
  TIM6->CNT = TIM6->ARR;
  position = 0;
}

void exti23IRQHandler(void) {

}