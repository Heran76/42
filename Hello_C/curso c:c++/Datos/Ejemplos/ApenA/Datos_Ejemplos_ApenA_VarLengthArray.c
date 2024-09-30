void mostrar(int m[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", m[i]);
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

void generarValoresAleatorios(int n, int limInf, int limSup)
{
  srand((unsigned)time(NULL));
  int m[n];
  for (int i = 0; i < n; i++)
  {
    // Obtener un número aleatorio
    m[i] = (int)(rand() % (limSup - limInf + 1) + limInf);
    // Verificar si ya existe el último número obtenido
    for (int k = 0; k < i; k++)
      if (m[k] == m[i]) // ya existe
      {
        i--; // i será incrementada por el for externo
        break; // salir de este for
      }
  }
  qsort(m, sizeof(m)/sizeof(*m), sizeof(*m), comparar_ints);
  mostrar(m, n);
}

int main(void)
{
  generarValoresAleatorios(6, 1, 49);
}
