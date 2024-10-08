/********** Conversiones implícitas **********/
// conver_impl.c
#include <stdio.h>

int main(void)
{
  unsigned char uc = 0;
  char c = 0;

  int i = 1985; // 0x000007C1
  printf("%d %08X\n", i, i); // 1985 000007C1

  uc = i;       // unsigned char <-- int
  printf("%u %c\n", uc, uc); // 193 ┴

  c = i;        // char <-- int
  printf("%d %c\n", c, c); // -63 ┴
}
