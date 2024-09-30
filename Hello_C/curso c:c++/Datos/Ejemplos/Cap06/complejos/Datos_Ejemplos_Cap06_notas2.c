/******************** Nota media del curso ********************/
/* notas2.c
 */
#include <stdio.h>

int main(void)
{
  // Definición de la matriz
  int nalumnos = 0;       // número real de alumnos
  do
  {
    printf("Número de alumnos: ");
    scanf("%d", &nalumnos);
  }
  while (nalumnos < 1);
  float notas[nalumnos]; // matriz notas

  // Entrada de datos
  for (int i = 0; i < nalumnos; i++)
  {
    printf("Alumno número %3d, nota media: ", i+1);
    scanf("%f", &notas[i]);
  }

  // Sumar las notas
  float suma = 0;         // suma total de todas las notas medias
  for (int i = 0; i < nalumnos; i++)
    suma += notas[i];

  // Escribir resultados
  printf("\n\nNota media del curso: %5.2f\n", suma / nalumnos);
}
