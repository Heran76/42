/********************* Diccionario inverso *********************/
/* dicinver.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char *leerCadena(char *str, int n);
int leerPalabras(char **palabra, int nFilas);
int comparar(char *cad1, char *cad2);
void ordenarPalabras(char **palabra, int filas);
void visualizarPalabras(char **palabra, int filas);

int main(void)
{
  setlocale(0, ""); // configuración regional predeterminada
  char **palabra = NULL;
  int nFilas = 0;
  int correcto = 0, filas = 0;

  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%u", &nFilas);
    while (getchar() != '\n') continue;
  }
  while ( !correcto || nFilas < 1 );

  // Asignar memoria para la matriz de punteros
  if ((palabra = (char **)malloc(nFilas * sizeof(char *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Operaciones
  filas = leerPalabras(palabra, nFilas);
  ordenarPalabras(palabra, filas);
  visualizarPalabras(palabra, filas);

  // Liberar la memoria asignada a cada una de las filas
  for ( int f = 0; f < filas; f++ )
    free(palabra[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(palabra);
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

int leerPalabras(char **palabra, int nFilas)
{
  int f = 0, longitud = 0;
  char pal[81];

  printf("Introducir palabras.\n");
  printf("Para finalizar introduzca una palabra nula.\n");
  printf("Esto es, pulse solo <Entrar>.\n");

  while (f < nFilas && (longitud = strlen(leerCadena(pal, 81))) > 0)
  {
    // Asignar espacio para una palabra
    if ((palabra[f] = (char *)malloc(longitud + 1)) == NULL)
    {
      printf("Insuficiente espacio de memoria disponible\n");
      return -1;	// terminar el proceso
    }
    // Copiar la palabra en el espacio de memoria asignado
    strcpy(palabra[f], pal);
    f++;
  }
  return f;
}

int comparar(char *cad1, char *cad2)
{
  int i, j;
  i = strlen(cad1) - 1;
  j = strlen(cad2) - 1;
  // Comparar las palabras de atrás hacia delante
  while( i > 0 && j > 0 )
  {
    if ( cad1[i] != cad2[j] )
      return (cad1[i] - cad2[j]);
    i--;
    j--;
  }
  return (cad1[i] == cad2[j]) ? i - j : cad1[i] - cad2[j];
  // (i – j) para parejas como "centrar" y "entrar"
}

void ordenarPalabras(char **palabra, int filas)
{
  char *aux;  // puntero auxiliar
  int i = 0, k = 0;
  // Método de inserción
  for ( i = 1; i < filas; i++ )
  {
    aux = palabra[i];
    k = i - 1;
    while ( (k >= 0) && (comparar(aux, palabra[k]) < 0) )
    {
      palabra[k+1] = palabra[k];
      k--;
    }
    palabra[k+1] = aux;
  }
}

void visualizarPalabras(char **palabra, int filas)
{
  for ( int f = 0; f < filas; f++ )
    printf("%s\n", palabra[f]);
}
