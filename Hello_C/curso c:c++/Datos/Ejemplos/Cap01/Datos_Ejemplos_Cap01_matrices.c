/* Matrices */
#include <stdio.h>
#include <locale.h>
#define N 10

int main(void)
{
  setlocale(0, ""); // configuración regional predeterminada
  char car = 'A';
  int ent = 0, r = 0;
  double real = 0.0;
  char cadena[80] = "hola";
  float m[N]; // los elementos son m[0], m[1], m[2],..., m[9]

  printf("%c", car); printf("\n");  // printf("%c\n", car);
  printf("%d\n", ent);
  printf("%lf\n", real);
  printf("%s\n", cadena);

  printf("Hola, ¿qué tal estás? ");
  printf("\n");
  printf("Cadena de caracteres: ");  scanf("%s", cadena);
  printf("La variable \"cadena\" contiene: %s\n", cadena);

  printf("Introduce datos para la matriz:\n");
  for (int i = 0; i < N; ++i)
  {
    printf("m[%d] = ", i);
    scanf("%f", &m[i]);
  }
  printf("Valores introducidos en la matriz m:\n");
  for (int i = 0; i < N; ++i)
    printf("%g ", m[i]);
  printf("\n");
}
