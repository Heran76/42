/**************** Ordenar cadenas de caracteres ****************/
/* ordcads.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CADS  25    // n�mero m�ximo de cadenas
#define TCAD  81    // n�mero m�ximo de caracteres por cadena

char *leerCadena(char *str, int n);
int  leerCadenas(char cad[][TCAD], char *pcad[], int nmc);
void ordenarCadenas(char *pcad[], int nc);
void visualizarCadenas(char *pcad[], int nc);

int main(void)
{
  setlocale(0, ""); // configuraci�n regional predeterminada
  char cad[CADS][TCAD];  // matriz de cadenas
  char *pcad[CADS];      // matriz de punteros a las cadenas
  int  ncads = 0;        // n�mero de cadenas le�das

  printf("Ordenaci�n de cadenas de caracteres.\n");
  printf("Introduzca las cadenas a ordenar.\n");
  printf("Pulse <Entrar> para salir.\n");
  if ((ncads = leerCadenas(cad, pcad, CADS)) > 0)
  {
    printf("Cadenas le�das %d\n\n", ncads);
    printf("Proceso de ordenaci�n.\n\n");
    ordenarCadenas(pcad, ncads);
    visualizarCadenas(pcad, ncads);
  }
  else
    printf("Matriz vac�a\n");
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
                   Funci�n leer cadenas
***************************************************************/
int leerCadenas(char cad[][TCAD], char *pcad[], int nmc)
{
  // nmc = n�mero m�ximo de cadenas que se pueden leer
  int ncads = 0;
  if (nmc < 1) return -1; // error
  while (strlen(leerCadena(cad[ncads], TCAD)) > 0)
  {
    // guardar la direcci�n de comienzo de la cadena le�da en
    // el siguiente elemento de la matriz de punteros
    pcad[ncads] = cad[ncads]; ncads++;
    if (ncads == nmc) break; // matriz llena
  }
  return (ncads);  // n�mero de cadenas le�das
}

/***************************************************************
                   Funci�n ordenar cadenas
***************************************************************/
void ordenarCadenas(char *pcad[], int nc)
{
  char *aux = NULL;  // puntero auxiliar
  int i = 0, s = 1;
  while ((s == 1) && (--nc > 0))
  {
    s = 0;  // no permutaci�n
    for (i = 1; i <= nc; i++)
      if (strcmp(pcad[i-1], pcad[i]) > 0)
      {
        aux = pcad[i-1];
        pcad[i-1] = pcad[i];
        pcad[i] = aux;
        s = 1;  // permutaci�n
      }
  }
}

/***************************************************************
                   Funci�n visualizar cadenas
***************************************************************/
void visualizarCadenas(char *pcad[], int nc)
{
  // nc = n�mero de cadenas a visualizar
  while (--nc >= 0)
    printf("%s\n", *pcad++);
}
