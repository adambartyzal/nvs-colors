#ifndef HARDWARE_H
#define HARDWARE_H
#include "adresses.h"

// Initialization of IO/s
void initGPIOs ();

// Init DMA to send data to SPI
void initDMA ();

// put data to DMA
void pushDMA (uint8_t data[], int sizeOfData);

// Initialization of SPI to drive the LEDs
void initSPI ();

// Initialize a system timer
void systickInit ();

// Initialize a timer
void tim6Init ();

// Initialize a timer
void tim14Init ();

// Config of Nested Vector Interrupt Controller
void nvicInit ();

// Config of USART 2
void initUsart2 ();

// Config of EXTI1
void initExti ();

// Turns on green LED on Nucleo Board
void ledOn ();

// Turns off green LED on Nucleo Board
void ledOff ();

#endif