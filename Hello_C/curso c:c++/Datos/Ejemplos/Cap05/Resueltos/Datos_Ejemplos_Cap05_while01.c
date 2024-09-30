#include <stdio.h>

int main(void)
{
  char car = '\0';

  printf("Desea continuar s/n (sí o no) "); 
  car = getchar();
  while (car != 's' && car != 'n')
  { 
    while (getchar() != '\n'); // limpiar buffer de stdin
    printf("Desea continuar s/n (sí o no) ");
    car = getchar();
  }
}
