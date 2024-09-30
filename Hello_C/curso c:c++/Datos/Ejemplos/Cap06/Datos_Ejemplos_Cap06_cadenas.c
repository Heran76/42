/****************** Leer una lista de nombres ******************/
/* cadenas.c
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FILAS_MAX 100
#define COLS_MAX 40

char *leerCadena(char *, int);

int main(void)
{
  // Matriz de cadenas de caracteres
  char nombre[FILAS_MAX][COLS_MAX];
  int nFilas = 0;
  int fila = 0, r = 0;
  char *fin, respuesta;

  do
  {
    printf("Número de filas de la matriz:  ");
    r = scanf("%d", &nFilas);
    while (getchar() != '\n'); // limpiar '\n'
  }
  while (nFilas < 1 || nFilas > FILAS_MAX || r == 0);
  printf("Escriba los nombres que desea introducir.\n");
  printf("Puede finalizar introduciendo la marca EOF.\n");
  for (fila = 0; fila < nFilas; fila++)
  {
    printf("Nombre[%d]: ", fila);
    fin = leerCadena(nombre[fila], COLS_MAX);
    // Si se pulsó [Ctrl][z], salir del bucle
    if (fin == NULL) break;
  }

  nFilas = fila; // número de filas leídas
  do
  {
    printf("¿Desea visualizar el contenido de la matriz? (s/n): ");
    respuesta = tolower(getchar());
    while (getchar() != '\n');
  }
  while (respuesta != 's' && respuesta != 'n');

  if (respuesta == 's')
  {
    // Visualizar la lista de nombres
    printf("\n");
    for (fila = 0; fila < nFilas; fila++)
      printf("%s\n", nombre[fila]);
  }
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
