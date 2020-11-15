#include "clock.h"


void clockTo48MHz(void)
{
	RCC->CFGR |= 10 << 18 | 1 << 1; //PLL Mutliptication (4MHz) * 12 = 48 MHz
	RCC->CR |= (1 << 24); //PLL ON
}