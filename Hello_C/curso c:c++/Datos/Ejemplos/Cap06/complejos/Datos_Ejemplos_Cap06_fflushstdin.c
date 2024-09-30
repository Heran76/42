/************* Limpiar el buffer asociado con stdin ************/
/* fflushstdin.c
 */
#include <stdio.h>

int main(void)
{
  int entero;
  double real;
  char respuesta = 's', cadena[81];

  // Introducir números
  printf("Introducir un nº entero y un nº real:\n");
  scanf("%d %lf", &entero, &real);
  printf("%d + %f = %f\n\n", entero, real, entero + real);

  fgets(cadena, sizeof(cadena), stdin); // limpiar el buffer de entrada
  // Leer una cadena con fgets
  printf("Introducir cadenas para fgets.\n");
  while (respuesta == 's' && fgets(cadena, sizeof(cadena), stdin) != NULL)
  {
    printf("%s\n", cadena);
    do
    {
      printf("¿Desea continuar? (s/n) ");
      respuesta = getchar();
      while (getchar() != '\n'); // limpiar el buffer de entrada
    }
    while ((respuesta != 's') && (respuesta != 'n'));
  }
}
