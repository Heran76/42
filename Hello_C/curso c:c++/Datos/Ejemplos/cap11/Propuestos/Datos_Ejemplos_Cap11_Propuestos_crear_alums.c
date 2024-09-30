// crear_alums.c
//
#include <stdio.h>
#include <stdlib.h>
                                                       
typedef struct
{
  char nombre[60];
  unsigned long dni;
} alumno;

int main(void)
{                        
  FILE *pf = NULL;
  alumno a;

  // Abrir el fichero
  if ((pf = fopen("dni.dat", "wb")) == NULL)
  {
    printf("Error al crear el fichero\n");
    exit(-1);
  } 

  printf("nombre: ");
  while (scanf("%[^\n]", a.nombre) != EOF)
  {
    printf("dni:    ");
    scanf("%ld", &a.dni); while (getchar() != '\n');
    fwrite(&a, sizeof(alumno), 1, pf);
    printf("nombre: ");
  }
  fclose(pf);    
}
