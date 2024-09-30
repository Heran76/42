#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h> // offsetof

struct flexArrayStruct
{
  int num;
  int m[]; // matriz flexible
};

void mostrar(struct flexArrayStruct *mflex)
{
  for (int i = 0; i < mflex->num; i++)
    printf("%d ", mflex->m[i]);
  printf("\n");
}

int comparar_ints(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

struct flexArrayStruct *generarValoresAleatorios(int n, int limInf, int limSup)
{
  srand((unsigned)time(NULL));
  // Asignar espacio para la estructura
  struct flexArrayStruct *ps = (struct flexArrayStruct*)
    malloc(offsetof(struct flexArrayStruct, m) + n * sizeof(int));
  if (ps == NULL)
  {
    // Manipular el error
  }
  ps->num = n;

  for (int i = 0; i < n; i++)
  {
    // Obtener un número aleatorio
    ps->m[i] = (int)(rand() % (limSup - limInf + 1) + limInf);
    // Verificar si ya existe el último número obtenido
    for (int k = 0; k < i; k++)
      if (ps->m[k] == ps->m[i]) // ya existe
      {
        i--; // i será incrementada por el for externo
        break; // salir de este for
      }
  }
  qsort(ps->m, n, sizeof(*ps->m), comparar_ints);
  return ps;
}

int main(void)
{
  struct flexArrayStruct *mflex = generarValoresAleatorios(6, 1, 49);
  mostrar(mflex);
  free(mflex);
  return 0;
}
