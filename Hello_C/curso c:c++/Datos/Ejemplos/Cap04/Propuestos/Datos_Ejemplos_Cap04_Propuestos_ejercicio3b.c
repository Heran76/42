/* Calcula la edad en el 2030
 *
 * Cap4 - ejercicio3b.c
 */

#include <stdio.h>
#include <time.h>
                 
/* Este programa usa un m�todo mejor para calcular los a�os, basado en las funciones 
   del ap�ndice A. (Cons�ltense para m�s referencias)*/                
int main(void)
{
  char nombre[30];
  int edad = 0, inc = 1;
  char cumple = 'n';
  struct tm *tiempo;
  
  time_t segundos;
  time(&segundos);
  tiempo = localtime(&segundos);
  printf("Introduzca su nombre: ");
  scanf("%[^\n]", nombre); // 'nombre' es una cadena de caracteres
  printf("Introduzca su edad: ");
  scanf("%d", &edad); while (getchar() != '\n') continue;
  printf("�Ya pas� su cumplea�os? (s/n): ");
  scanf("%c", &cumple);
  if (cumple == 'n')
    inc = 1;
  else if (cumple == 's')
    inc = 0;
  printf("Hola %s, en el a�o 2030 cumplir�s %d a�os\n", nombre,
          edad + (2030 - (tiempo->tm_year + 1900) + inc) );
  // Ahora, calcula su edad estemos en el a�o en que estemos     
}
