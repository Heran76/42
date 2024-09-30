/********************** Programa alumnos **********************/
/* alumnos.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100  // n�mero m�ximo de alumnos

typedef struct
{
  char matricula[10];
  char apellidos[30];
  char nombre[20];
  char direccion[30];
} ficha;

void leer(ficha *, int *, const int);
void buscar(ficha *, char *, int, int);
int menu(void);
char *leerCadena(char *str, int n);

int main(void)
{
  static ficha lista[N];
  char dato[30];  // dato a buscar
  int opcion;     // opci�n elegida en el men�
  int n = 0;      // n�mero de alumnos le�dos

  while (1)       // bucle infinito. Se sale con break
  {
    opcion = menu();
    if (opcion != 4)
    {
      switch (opcion)
      {
        case 1:    // entrada de los datos de los alumnos
          leer(lista, &n, N);
          break;
        case 2:    // b�squeda por el n�mero de matr�cula
          system("cls");
          printf("N�mero de matr�cula ");
          leerCadena(dato, sizeof(dato));
          buscar(lista, dato, n, opcion);
          break;
        case 3:    // B�squeda por los apellidos
          system("cls");
          printf("Apellidos.......... ");
          leerCadena(dato, sizeof(dato));
          buscar(lista, dato, n, opcion);
          break;
      }
    }
    else
      break;
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

/****************************************************************
               Funci�n para visualizar el men�
****************************************************************/
int menu(void)
{
  int op;

  do
  {
    system("cls");
    printf("\t1. Entrada de datos de alumnos\n");
    printf("\t2. B�squeda por nro. de matr�cula\n");
    printf("\t3. B�squeda por apellidos\n");
    printf("\t4. Fin\n");
    printf("\nTeclee la opci�n deseada  ");
    scanf("%d", &op);
    while (getchar() != '\n');
  }
  while (op < 1 || op > 4);

  return (op);
}

/****************************************************************
           Funci�n para leer los datos de los alumnos
****************************************************************/
void leer(ficha *lista, int *n, const int NMAX)
{
  int i = *n;
  char resp = 's';
  while (tolower(resp) == 's' && i < NMAX)
  {
    do
    {
      system("cls");
      printf("Alumno n�mero %d\n\n", i+1);
      printf("N�mero de matr�cula ");
      leerCadena(lista[i].matricula, sizeof(lista[i].matricula));
      printf("Apellidos.......... ");
      leerCadena(lista[i].apellidos, sizeof(lista[i].apellidos));
      printf("Nombre............. ");
      leerCadena(lista[i].nombre, sizeof(lista[i].nombre));
      printf("Direcci�n.......... ");
      leerCadena(lista[i].direccion, sizeof(lista[i].direccion));
      printf("\n\n� Datos correctos ? s/n ");
      resp = getchar();
      while (getchar() != '\n');
    }
    while (tolower(resp) != 's');
    i++;

    printf("\n� M�s datos a introducir ? s/n ");
    resp = getchar();
    while (getchar() != '\n');
  }
  *n = i; // actualizar n
}

/****************************************************************
       Funci�n para buscar si existe o no un dato
****************************************************************/
void buscar(ficha *lista, char *x, int alumnos, int opcion)
{
  int i = 0;
  bool existe = false;

  switch (opcion)
  {
    case 2: // b�squeda por n�mero de matr�cula
      while (!existe && i < alumnos)
        if (strcmp(lista[i++].matricula, x) == 0)
          existe = true;
      break;
    case 3: // b�squeda por apellidos
      while (!existe && i < alumnos)
        if (strcmp(lista[i++].apellidos, x) == 0)
          existe = true;
      break;
  }
  if (existe)
    printf("\n%s\n%s %s\n%s\n", lista[i-1].matricula,
                                lista[i-1].apellidos,
                                lista[i-1].nombre,
                                lista[i-1].direccion);
  else
    printf("\n%s no existe", x);

  printf("\n\nPulse <Entrar> para continuar ");
  while (getchar() != '\n');
}
