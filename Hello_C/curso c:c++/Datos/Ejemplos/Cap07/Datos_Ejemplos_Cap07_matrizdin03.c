/*********** Matriz dinámica de cadenas de caracteres ***********/
/* matrizdin03.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char *leerCadena(char *str, int n);
int leerCadenas(char **nombre, int nFilas);
void ordenarCadenas(char **nombre, int filas);
void visualizarCadenas(char **nombre, int filas);
void liberarMemoria(char **nombre, int filas);

int main(void)
{
  setlocale(0, ""); // configuración regional predeterminada
  char **nombre = NULL;
  int nFilas = 0;
  int correcto = 0, filas = 0;
  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%d", &nFilas);
    while (getchar() != '\n'); // limpiar buffer
  }
  while (!correcto || nFilas < 1);
  // Asignar memoria para la matriz de punteros
  if ((nombre = (char **)malloc(nFilas * sizeof(char *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }
  // Operaciones
  filas = leerCadenas(nombre, nFilas);
  if (filas == -1) return -1;
  ordenarCadenas(nombre, filas);
  visualizarCadenas(nombre, filas);
  // Liberar la memoria asignada
  liberarMemoria(nombre, filas);

  return 0;
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

int leerCadenas(char **nombre, int nFilas)
{
  int f = 0, longitud = 0;
  char cadena[81];
  printf("Introducir cadenas de caracteres.\n");
  printf("Para finalizar introduzca una cadena nula.\n");
  printf("Esto es, pulse solo <Entrar>.\n\n");
  while (f < nFilas && (longitud = strlen(leerCadena(cadena, 81))) > 0)
  {
    // Asignar espacio para una cadena de caracteres
    if ((nombre[f] = (char *)malloc(longitud + 1)) == NULL)
    {
      printf("Insuficiente espacio de memoria disponible\n");
      // Liberar la memoria asignada
      liberarMemoria(nombre, f);
      return -1;	// terminar el proceso
    }
    // Copiar la cadena en el espacio de memoria asignado
    strcpy(nombre[f], cadena);
    f++;
  }
  return f;
}

void ordenarCadenas(char **nombre, int filas)
{
  char *aux;  // puntero auxiliar
  int i = 0, s = 1;
  while ((s == 1) && (--filas > 0))
  {
    s = 0;  // no permutación
    for (i = 1; i <= filas; i++)
    if (strcmp(nombre[i - 1], nombre[i]) > 0)
    {
      aux = nombre[i - 1];
      nombre[i - 1] = nombre[i];
      nombre[i] = aux;
      s = 1;  // permutación
    }
  }
}

void visualizarCadenas(char **nombre, int filas)
{
  for (int f = 0; f < filas; f++)
    printf("%s\n", nombre[f]);
}

void liberarMemoria(char **nombre, int filas)
{
  // Liberar la memoria asignada a cada una de las filas
  for (int f = 0; f < filas; f++)
    free(nombre[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(nombre);
}
