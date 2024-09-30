/* Calcula la edad en el 2030
 *
 * Cap4 - ejercicio3b.c
 */

#include <stdio.h>
#include <time.h>
                 
/* Este programa usa un método mejor para calcular los años, basado en las funciones 
   del apéndice A. (Consúltense para más referencias)*/                
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
  printf("¿Ya pasó su cumpleaños? (s/n): ");
  scanf("%c", &cumple);
  if (cumple == 'n')
    inc = 1;
  else if (cumple == 's')
    inc = 0;
  printf("Hola %s, en el año 2030 cumplirás %d años\n", nombre,
          edad + (2030 - (tiempo->tm_year + 1900) + inc) );
  // Ahora, calcula su edad estemos en el año en que estemos     
}
