//Ahoj
#include <stdio.h>

// GRB not RGB
const int green = 0x110000;
const int red = 0x001100;
const int blue = 0x000011;
const int yellow = 0x111100;
const int cyan = 0x110011;
const int magenta = 0x001111;
const int black = 0x000000;
const int white = 0x111111;


int main()
{
  int diodesCnt = 8;
  int p;
  char zero = 0xC0, one = 0xFC;

  int colors[8] = {green,red,blue,yellow,cyan,magenta,black,white};
  char colorNames[8][20] = {"green","red","blue","yellow","cyan","magenta","black","white"};

  printf("@ Strigns in literal space:\n@ put after main loop\n\n.align 4\n");

  printf("begin: .byte ");
  for (int i = 0; i < 64; i++) {
    printf("0x%x",0);
    if (i != 63) printf(", ");
  }
  putchar('\n');

  for (int i = 0; i < diodesCnt; i++) {
    printf("%s: .byte ",colorNames[i]);
    for (int j = 23; j >= 0; j--) {
      p = colors[i] >> j & 1 ? one : zero;
      p &= 0xFF;
      printf("0x%x",p);
      if (j) printf(", ");
    }
    putchar('\n');
  }

  printf("end: .byte ");
  for (int i = 0; i < 64; i++) {
    printf("0x%x",0);
    if (i != 63) printf(", ");
  }
  printf("\n.align 4\n");
  return(0);
}
