#include <stdio.h>
#include <stdlib.h>
#define N 81

int main(void)
{
  FILE *pf = NULL;
  char buffer[N], nomfi[13];

  printf("Nombre del archivo: ");
  scanf("%s", nomfi);

  // Abrir el archivo nomfi para escribir y leer
  if ((pf = fopen(nomfi, "w+")) == NULL)
  {
    printf("El archivo %s no puede abrirse.", nomfi);
    exit(1);
  }

  printf("Archivo %s abierto\n", nomfi);
  printf("Introducir datos. Finalizar cada línea con <Entrar>\n");
  printf("Para terminar introduzca la marca eof\n\n");
  while (fgets(buffer, sizeof(buffer), stdin) != NULL)
  {
    // Escribir la cadena en el archivo seguida de \n
    fputs(buffer, pf);
    if (ferror(pf))
    {
      perror("Error al escribir");
      exit(2);
    }
  }

  // Visualizar el contenido del archivo
  rewind(pf);  // situarse al principio del archivo

  // leer hasta un '\n' o hasta N-1 caracteres
  while (fgets(buffer, N, pf) != NULL)
    printf("%s", buffer);

//  fgets(buffer, sizeof(buffer), pf);
//  while (!ferror(pf) && !feof(pf))
//  {
//    printf("%s", buffer);
//    fgets(buffer, sizeof(buffer), pf);
//  }

  if (ferror(pf))
    perror("Error durante la lectura");

  fclose(pf);
}
