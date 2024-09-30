/******************** Nota media del curso ********************/
/* notas-EOF.c
*/
#include <stdio.h>

#define N_ALUMNOS 100  // número máximo de alumnos

int main(void)
{
  float notas[N_ALUMNOS]; // matriz notas
  int i = 0, r = 0;       // índice y valor devuelto por scanf
  int nalumnos = 0;       // número real de alumnos
  float suma = 0;         // suma total de todas las notas medias

  // Entrada de datos
  printf("Puede finalizar la entrada de datos introduciendo la marca EOF.\n");
  while (i < N_ALUMNOS && r != EOF)
  {
    printf("Alumno número %3d, nota media: ", i + 1);
    r = scanf("%f", &notas[i]);
    if (r != EOF) ++i;
  }
  nalumnos = i;

  // Sumar las notas
  for (i = 0; i < nalumnos; i++)
    suma += notas[i];

  // Escribir resultados
  if (nalumnos > 0)
    printf("\n\nNota media del curso: %5.2f\n", suma / nalumnos);
}
