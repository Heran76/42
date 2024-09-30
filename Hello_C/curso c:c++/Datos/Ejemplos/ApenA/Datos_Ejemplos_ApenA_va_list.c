#include <stdio.h>
#include <stdarg.h>

double media(int num,...)
{
  va_list valist;
  double sum = 0.0;
  int i;

  // Inicia valist con la dirección justo a continuación de 'num'
  va_start(valist, num);

  // Acceder a los argumentos de valist
  for (i = 0; i < num; i++)
  {
    sum += va_arg(valist, int);
  }

  // Liberar valist (valist ya no es válida)
  va_end(valist);

  return sum/num;
}

int main(void)
{
  printf("Media de 3, 4, 5, 6, 7 = %f\n", media(5, 3,4,5,6,7));
  printf("Media de 6, 12, 18, 24 = %f\n", media(4, 6,12,18,24));
}
