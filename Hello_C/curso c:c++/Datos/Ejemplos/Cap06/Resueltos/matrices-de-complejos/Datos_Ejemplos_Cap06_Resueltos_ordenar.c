/*********** Leer una lista de nombres y ordenarlos ***********/
/* ordenar.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILAS_MAX 100
#define COLS_MAX 80

void fflushstdin(void);
char *leerCadena(char *, int);
void ordenar(char [][COLS_MAX], int);

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
    fflushstdin(); // limpiar '\n'
  }
  while (nFilas < 1 || nFilas > FILAS_MAX || r == 0);

  printf("Escriba los nombres que desea introducir.\n");
  printf("Puede finalizar introduciendo la marca EOF.\n");
  for (fila = 0; fila < nFilas; fila++)
  {
    printf("Nombre[%d]: ", fila);
    fin = leerCadena(nombre[fila], COLS_MAX);
    // Si se pulsó [Ctrl][Z], salir del bucle
    if (fin == NULL) break;
  }

  nFilas = fila; // número de filas leídas

  ordenar(nombre, nFilas);

  do
  {
    printf("¿Desea visualizar el contenido de la matriz? (s/n): ");
    respuesta = tolower(getchar());
    fflushstdin();
  }
  while (respuesta != 's' && respuesta != 'n');

  if ( respuesta == 's' )
  {
    // Visualizar la lista de nombres
    printf("\n");
    for (fila = 0; fila < nFilas; fila++)
      printf("%s\n", nombre[fila]);
  }
}

void fflushstdin(void)
{
  if (!feof(stdin) && !ferror(stdin))
    while ((getchar()) != '\n'); 
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

/***************************************************************
		                   Función ordenar
***************************************************************/
// Ordenar cadenas de caracteres por orden alfabético
void ordenar(char cad[][COLS_MAX], int nc)
{
  char aux[COLS_MAX];
  int i, s = 1;

  while ((s == 1) && (--nc > 0))
  {
    s = 0;  // no permutación
    for (i = 1; i <= nc; i++)
      if (strcmp(cad[i-1], cad[i]) > 0)
      {
        strcpy(aux, cad[i-1]);
        strcpy(cad[i-1], cad[i]);
        strcpy(cad[i], aux);
        s = 1;  // permutación
      }
  }
}
