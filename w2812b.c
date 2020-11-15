#include "w2812b.h"


void prepareValues(uint8_t data[], int shift) {
  int ptr = 0;

  int colors[8] = {G,R,B,Y,C,M,K,W};
  for (int i = 0; i < 64; i++) {
    data[ptr] = 0;
    ptr++;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 23; j >= 0; j--) {
      data[ptr] = colors[(i + shift) % 8] >> j & 1 ? 0xFC : 0xC0;
      ptr++;
    }
  }

  for (int i = 0; i < 64; i++) {
    data[ptr] = 0;
    ptr++;
  }
}

void triColor(uint8_t data[], int choose) {
  int ptr = 0;
  static int alphabet[5*8][8] = { {R,R,R,R,R,R,K,K},
                                  {K,K,R,K,K,R,R,K},
                                  {K,K,R,K,K,K,R,R},
                                  {K,K,R,K,K,K,R,R},
                                  {K,K,R,K,K,R,R,K},
                                  {R,R,R,R,R,R,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},

                                  {M,M,M,M,M,M,M,M},
                                  {M,K,K,K,K,K,K,M},
                                  {M,K,K,K,K,K,K,M},
                                  {M,K,K,K,K,K,K,M},
                                  {M,M,K,K,K,K,M,M},
                                  {K,K,M,M,M,M,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  
                                  {G,G,G,G,G,G,K,K},
                                  {K,K,G,K,K,G,G,K},
                                  {K,K,G,K,K,K,G,G},
                                  {K,K,G,K,K,K,G,G},
                                  {K,K,G,K,K,G,G,K},
                                  {G,G,G,G,G,G,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                
                                  {Y,Y,Y,Y,Y,Y,Y,Y},
                                  {K,K,K,K,K,K,Y,Y},
                                  {K,K,K,K,Y,Y,K,K},
                                  {K,K,K,K,Y,Y,K,K},
                                  {K,K,K,K,K,K,Y,Y},
                                  {Y,Y,Y,Y,Y,Y,Y,Y},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  {K,K,K,K,K,K,K,K},
                                  };

  for (int i = 0; i < 64; i++) {
    data[ptr] = 0;
    ptr++;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 23; j >= 0; j--) {
      data[ptr] = alphabet[choose][i] >> j & 1 ? 0xFC : 0xC0;
      ptr++;
    }
  }

  for (int i = 0; i < 64; i++) {
    data[ptr] = 0;
    ptr++;
  }
}
