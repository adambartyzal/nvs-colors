#ifndef IRQHANDLERS_H
#define IRQHANDLERS_H
#include "adresses.h"
#include "hardware.h"
#include "w2812b.h"
#include "globals.h"

//General Interrupt Request Handler (does nothing)
void defaultIRQHandler(void);

//Hard Fault Interrupt Request Handler 
void hardfaultIRQHandler(void);

//Systick timer Interrupt Request Handler
void systickIRQHandler(void);

//Timer 6 Interrupt Request Handler
void tim6IRQHandler(void);

//Timer 14 Interrupt Request Handler
void tim14IRQHandler(void);

//USART 2 Interrupt Request Handler
void usart2IRQHandler(void);

//Direct Memory Access Interrupt Request Handler for Channels 0 & 1
void dma1ch1IRQHandler(void);

//Direct Memory Access Interrupt Request Handler for Channels 2 & 3
void dma1ch23IRQHandler(void);

//Direct Memory Access Interrupt Request Handler for Channels 4 & 5
void dma1ch45IRQHandler(void);

//External Interrupt Request Handler for Channels 0 & 1
void exti01IRQHandler(void);

//External Interrupt Request Handler for Channels 2 & 3
void exti23IRQHandler(void);

#endif