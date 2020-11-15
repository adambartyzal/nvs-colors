#ifndef CLOCK_H
#define CLOCK_H
#include "types.h"
#include "adresses.h"


/*
 * By default 8 MHz internal clock is used (HSI)
 * Enables PLL with Multilication * 12
 */
void clockTo48MHz(void);

#endif
