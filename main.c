
#include "constants.h"
#include "data.h"
#include "clock.h"
#include "irqHandlers.h"
#include "w2812b.h"
#include "hardware.h"
int32_t main(void);

#include "vectortable.h"
#include "globals.h"

uint32_t counter;
uint32_t position;
uint8_t data[320];

// Main code
int32_t main(void) {
	
	counter = 10;
	position = 0;
	//uint8_t shift = 0;
	prepareValues(data, 7);
	// Copy LMA to VMA for data section
	copy_data();
	clockTo48MHz();
	tim6Init();
	tim14Init();
	nvicInit();
	initGPIOs();
	initDMA();
	initUsart2();
	initSPI();
	initExti ();
	while (1) {

	}

	return 0;
}
