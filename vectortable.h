#ifndef VECTORTABLE_H
#define VECTORTABLE_H
#include "types.h"

// Vector table
uint32_t (* const vector_table[])
__attribute__ ((section(".vectors"))) = {
  (uint32_t *) STACKINIT,  		          // 0x0000 - Stack pointer init value (0x20000000 is RAM address and 0x1000 is 4kB size, stack grows "downwards")
  (uint32_t *) main,                    // 0x0004 - Reset vector - where the code begins
  (uint32_t *) defaultIRQHandler,       // 0x0008 - NMI
  (uint32_t *) hardfaultIRQHandler,     // 0x000C - HardFault
  0,                                    // 0x0010 - Reserved
  0,                                    // 0x0014 - Reserved
  0,                                    // 0x0018 - Reserved
  0,                                    // 0x001C - Reserved
  0,                                    // 0x0020 - Reserved
  0,                                    // 0x0024 - Reserved
  0,                                    // 0x0028 - Reserved
  (uint32_t *) defaultIRQHandler,       // 0x002C - SVCall
  0,                                    // 0x0030 - Reserved
  0,                                    // 0x0034 - Reserved
  (uint32_t *) defaultIRQHandler,       // 0x0038 - PendSV 
  (uint32_t *) systickIRQHandler,       // 0x003C - SysTick
  (uint32_t *) defaultIRQHandler,       // 0x0040 - WWDG
  0,                                    // 0x0044 - Reserved
  (uint32_t *) defaultIRQHandler,       // 0x0048 - RTC
  (uint32_t *) defaultIRQHandler,       // 0x004C - FLASH  
  (uint32_t *) defaultIRQHandler,       // 0x0050 - RCC
  (uint32_t *) exti01IRQHandler,        // 0x0054 - EXTI Line 0,and 1
  (uint32_t *) exti23IRQHandler,        // 0x0058 - EXTI Line 2 and 3
  (uint32_t *) defaultIRQHandler,       // 0x005C - EXTI Line 4 to 15
  0,                                    // 0x0060 - Reserved
  (uint32_t *) dma1ch1IRQHandler,       // 0x0064 - DMA1 Channel 1       
  (uint32_t *) dma1ch23IRQHandler,      // 0x0068 - DMA1 Channel 2 and Channel 3
  (uint32_t *) dma1ch45IRQHandler,      // 0x006C - DMA1 Channel 4 and Channel 5
  (uint32_t *) defaultIRQHandler,       // 0x0070 - ADC1    
  (uint32_t *) defaultIRQHandler,       // 0x0074 - TIM1 Break, Update, Trigger and Commutation
  (uint32_t *) defaultIRQHandler,       // 0x0078 - TIM1 Capture Compare 
  0,                                    // 0x007C - Reserved
  (uint32_t *) defaultIRQHandler,       // 0x0080 - TIM3    
  (uint32_t *) tim6IRQHandler,          // 0x0084 - TIM6    
  0,                                    // 0x0088 - Reserved
  (uint32_t *) tim14IRQHandler,         // 0x008C - TIM14   
  (uint32_t *) defaultIRQHandler,       // 0x0090 - TIM15   
  (uint32_t *) defaultIRQHandler,       // 0x0094 - TIM16   
  (uint32_t *) defaultIRQHandler,       // 0x0098 - TIM17   
  (uint32_t *) defaultIRQHandler,       // 0x009C - I2C1    
  (uint32_t *) defaultIRQHandler,       // 0x00A0 - I2C2    
  (uint32_t *) defaultIRQHandler,       // 0x00A4 - SPI1    
  (uint32_t *) defaultIRQHandler,       // 0x00A8 - SPI2    
  (uint32_t *) defaultIRQHandler,       // 0x00AC - USART1  
  (uint32_t *) usart2IRQHandler,        // 0x00B0 - USART2  
  0,                                    // 0x00B4 - Reserved
  0,                                    // 0x00B8 - Reserved
  0,                                    // 0x00BC - Reserved
};
#endif
