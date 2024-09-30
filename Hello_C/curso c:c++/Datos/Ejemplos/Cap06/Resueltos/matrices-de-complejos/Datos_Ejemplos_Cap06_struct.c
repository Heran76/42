#include <stdio.h>

typedef struct ficha
{
  char nombre[40];
  char direccion[40];
  long telefono;
} tficha;

int ficha = 1;

int main(void)
{
  tficha var1;
  char nombre[40] = "Javier";

  printf("Nombre: ");
  fgets(var1.nombre, sizeof(var1.nombre), stdin);
  printf("%s\n", var1.nombre);
  printf("%s\n", nombre);
  printf("%d\n", ficha);
}

