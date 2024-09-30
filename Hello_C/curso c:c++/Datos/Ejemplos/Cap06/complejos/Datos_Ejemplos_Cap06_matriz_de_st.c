/********** Calcular el % de aprobados y suspendidos **********/
/* matriz_de_st.c
 */
#include <stdio.h>
#include <string.h>
#define NA 100      // número máximo de alumnos
char *leerCadena(char *, int);

typedef struct
{
  char nombre[60];
  float nota;
} tficha;

int main(void)
{
  static tficha alumno[NA]; // matriz de estructuras o registros
  int n = 0; // número de alumnos introducidos
  char *fin = NULL; // para almacenar el valor devuelto por fgets
  int aprobados = 0, suspendidos = 0;

  // Entrada de datos
  printf("Introducir datos. ");
  printf("Para finalizar teclear la marca de fin de archivo\n\n");

  printf("Nombre: ");
  fin = leerCadena(alumno[n].nombre, sizeof(alumno[n].nombre));
  while (fin != NULL)
  {
    printf("Nota:   ");
    scanf("%f", &alumno[n++].nota);
    while (getchar() != '\n'); // eliminar el carácter \n
    if (n == NA) break;
    // Siguiente alumno
    printf("Nombre: ");
    fin = leerCadena(alumno[n].nombre, sizeof(alumno[n].nombre));
  }

  // Contar los aprobados y suspendidos
  for (int i = 0; i < n; i++)
    if (alumno[i].nota >= 5)
      aprobados++;
    else
      suspendidos++;

  // Escribir resultados
  printf("Aprobados:   %.4g %%\n", (float)aprobados/n*100);
  printf("Suspendidos: %.4g %%\n", (float)suspendidos/n*100);
}

char *leerCadena(char *str, int n)
{
  char *fin, *c = 0;
  fin = fgets(str, n, stdin);
  if (c = strchr(str, '\n'))
    *c = 0; // reemplazar '\n'
  else if (!feof(stdin))
    while (getchar() != '\n'); // limpiar buffer stdin
  return fin;
}
