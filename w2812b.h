#ifndef W2812B_H
#define W2812B_H

#include <stdlib.h>

#include "types.h"
#include "constants.h"

// Prepares colorful rainbow in data arr for DMA push to SPI MOSI connected to W2812B diode strip
void prepareValues(uint8_t data[], int shift);

// Prepares one color to all diodeson W2812B diode strip
void triColor(uint8_t data[], int choose);

#endif