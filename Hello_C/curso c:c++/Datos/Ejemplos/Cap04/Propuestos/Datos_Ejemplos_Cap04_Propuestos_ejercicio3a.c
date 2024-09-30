/* Calcula la edad en el 2030
 *
 * Cap4 - ejercicio3a.c
 */

#include <stdio.h>

int main(void)
{                                                                            
  char nombre[30]; // Se reservan 30 caracteres para el nombre
  int edad = 0, anyo = 2002, inc = 1;
  char cumple = 'n';

  printf("Introduzca su nombre: ");
  scanf("%[^\n]", nombre); // 'nombre' es una cadena de caracteres
  printf("Introduzca su edad: ");
  scanf("%d", &edad);
  printf("Introduzca el año actual ####: ");
  scanf("%d", &anyo); while (getchar() != '\n') continue;
  printf("¿Ya pasó su cumpleaños? (s/n): ");
  scanf("%c", &cumple);
  if (cumple == 'n')
    inc = 1;
  else if (cumple == 's')
    inc = 0;
  printf("Hola %s, en el año 2030 cumplirás %d años\n", nombre, edad + (2030 - anyo) + inc);
}
