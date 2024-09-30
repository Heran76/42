#include <stdio.h>
#include "threads.h"

int th_func(void * arg) // hilo secundario
{
  puts("Se ejecuta el hilo secundario...");
  puts("Los hilos principal y secundario se ejecutan en paralelo...");
  ++*(int*)arg;
  return 0;
}

int main(void) // hilo principal
{
  thrd_t th; int n = 1;
  if (thrd_create(&th, th_func, &n) != thrd_success)
  {
    fprintf(stderr, "Error al crear el hilo.\n"); return -1;
  }
  puts("Hilo principal en ejecución...");
  thrd_join(th, NULL);
  printf("El valor final de n es %d\n", n); // n == 2
  return 0;
}
