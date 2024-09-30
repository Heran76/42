/************************** BIBLIOTECA ************************/
/* estr_variables.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define N 100 // máximo número de elementos de la matriz

enum clase // tipo enumerado
{
  libro, revista
};

typedef struct // estructura variable
{
  unsigned numref;
  char titulo[30];
  char autor[20];
  char editorial[25];
  enum clase libro_revista;
  union
  {
    struct
    {
      unsigned edicion;
      unsigned anyo;
    } libros;
    char nomrev[30];
  } lr;
} tficha;

// Prototipos de las funciones
void escribir(tficha[], int);
int leer(tficha[], int);
void fflushstdin(void);
char *leerCadena(char *, int);

int main(void) // función principal
{
  setlocale(0, ""); // configuración regional predeterminada
  static tficha biblioteca[N]; // matriz de estructuras
  int n = 0; // número actual de elementos de la matriz

  system("cls");
  printf("Introducir datos.\n");
  n = leer(biblioteca, N);
  system("cls");
  printf("Listado de libros y revistas\n");
  escribir(biblioteca, n); // listar todos los libros y revistas
}

/***************************************************************
      Función para leer los datos de los libros y revistas
***************************************************************/
int leer(tficha bibli[], int NMAX)
{
  int clase;
  char resp = 's';
  int k = 0; // número de elementos introducidos

  while( tolower(resp) == 's' && k < NMAX )
  {
    system("cls");
    printf("Número de refer. ");
    scanf("%u",&bibli[k].numref); fflushstdin();
    printf("Título           ");
    leerCadena(bibli[k].titulo, sizeof(bibli[k].titulo));
    printf("Autor            ");
    leerCadena(bibli[k].autor, sizeof(bibli[k].autor));
    printf("Editorial        ");
    leerCadena(bibli[k].editorial, sizeof(bibli[k].editorial));
    do
    {
      printf("Libro o revista (0 = libro, 1 = revista) ");
      scanf("%d", &clase); fflushstdin();
    }
    while (clase != 0 && clase != 1);
    if (clase == libro)
    {
      bibli[k].libro_revista = libro;
      printf("Edición          ");
      scanf("%u", &bibli[k].lr.libros.edicion);
      printf("Año de public.   ");
      scanf("%u", &bibli[k].lr.libros.anyo); fflushstdin();
    }
    else
    {
      bibli[k].libro_revista = revista;
      printf("Nombre revista   ");
      leerCadena(bibli[k].lr.nomrev, sizeof(bibli[k].lr.nomrev));
    }

    k++;

    do
    {
      printf("\n¿Más datos a introducir? s/n ");
      resp = getchar();
      fflushstdin();
    }
    while( tolower(resp) != 's' && tolower(resp) != 'n' );
  }
  return k;
}

/***************************************************************
      Función para listar todos los elementos de la matriz
***************************************************************/
void escribir(tficha bibli[], int n)
{
  int k = 0;
  for (k = 0; k < n; k++)
  {
    printf("%d  %s\n", bibli[k].numref, bibli[k].titulo);
    printf("%s - Ed. %s\n", bibli[k].autor,  bibli[k].editorial);

    switch (bibli[k].libro_revista)
    {
      case libro :
        printf("Edición %u - año %u\n",
        bibli[k].lr.libros.edicion,
        bibli[k].lr.libros.anyo);
        break;
      case revista :
        printf("%s\n", bibli[k].lr.nomrev);
    }
    printf("\nPulse <Entrar> para continuar");
    getchar();
    system("cls");
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
