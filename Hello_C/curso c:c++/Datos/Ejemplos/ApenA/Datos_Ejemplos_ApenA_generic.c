#include <stdio.h>

#define MENOR(X, Y) _Generic((X), int:     imenor, \
                                  char*:   smenor, \
                                  default: menor)(X, Y)
int imenor(int a, int b);
char* smenor(char* a, char* b);
double menor(double a, double b);

int main(void)
{
  printf("%d\n", MENOR(5, 4));
  printf("%s\n", MENOR("hola", "adiós"));
  printf("%g\n", MENOR(9.0, 8.0));
}

int imenor(int a, int b)
{
  return a < b ? a : b;
}

char* smenor(char* a, char* b)
{
  return strcmp(a, b) < 0 ? a : b;
}

double menor(double a, double b)
{
  return a < b ? a : b;
}
