#include <stdio.h>

int main(void)
{
  char car = '\0'; 

  printf("Desea continuar s/n (s� o no) "); 
  while ((car = getchar()) != 's' && car != 'n')
  { 
    while (getchar() != '\n');
    printf("Desea continuar s/n (s� o no) ");
  }
}
