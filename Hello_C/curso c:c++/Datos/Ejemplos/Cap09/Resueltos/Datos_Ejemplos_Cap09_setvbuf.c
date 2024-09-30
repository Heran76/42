/********** Control del buffer asociado a un archivo **********/
/* setvbuf.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIBUFFER 2048

int cuenta_lineas(FILE *pf, int lecturas);
FILE *abrir(char *);
// BUFSIZ es una constante definida en stdio.h
char buf1[BUFSIZ], buf2[MIBUFFER];  // buffers para el archivo

int main(int argc, char *argv[])
{
  time_t t_inicial;
  FILE *pf;
  int  c, lecturas;

  if (argc != 2)  // verificar el número de argumentos
  {
    printf("Sintaxis: nombre_programa nombre_archivo.\n");
    exit(1);
  }
  printf("¿Cuántas veces consecutivas desea leer el archivo %s? ", argv[1]);
  scanf("%d", &lecturas);
  if (lecturas < 1) lecturas = 1;

  /**************************************************************
  Utilizando el buffer buf1, de tamaño BUFSIZ
  **************************************************************/
  pf = abrir(argv[1]);
  setvbuf(pf, buf1, _IOFBF, BUFSIZ);
  t_inicial = clock();
  c = cuenta_lineas(pf, lecturas);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\n",
    ((float)clock() - t_inicial) / CLOCKS_PER_SEC, BUFSIZ);

  /**************************************************************
  Utilizando el buffer buf2, de tamaño MIBUFFER
  **************************************************************/
  pf = abrir(argv[1]);
  setvbuf(pf, buf2, _IOFBF, sizeof(buf2));
  t_inicial = clock();
  c = cuenta_lineas(pf, lecturas);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\t  mi buffer\n",
    ((float)clock() - t_inicial) / CLOCKS_PER_SEC, MIBUFFER);

  /**************************************************************
  Sin utilizar un buffer
  **************************************************************/
  pf = abrir(argv[1]);
  setvbuf(pf, NULL, _IONBF, 0);
  t_inicial = clock();
  c = cuenta_lineas(pf, lecturas);
  printf("Tiempo: %5.1f\tTamaño del Buffer: %4d\n",
    ((float)clock() - t_inicial) / CLOCKS_PER_SEC, 0);

  printf("\nSe han procesado %d líneas\n", c);

  return 0;
}

/****************************************************************
Contar líneas en un archivo de texto
****************************************************************/
int cuenta_lineas(FILE *pf, int lecturas)
{
  #define N 81
  char linea_buf[N];
  int c = 0;
  for (int i = 0; i < lecturas; ++i)
  {
    while (!ferror(pf) && !feof(pf))
    {
      fgets(linea_buf, N, pf);     // lee una línea
      c++;                         // contar líneas
      (c % 2) ? printf("\\\r") : printf("/\r");
    }
    rewind(pf);
  }
  if (ferror(pf))
  {
    printf("Ha ocurrido un error de lectura.");
    fclose(pf);
    exit(3);
  }
  putchar('\n');
  fclose(pf);
  return c;
}

/****************************************************************
Abrir el archivo indicado por argv[1]
****************************************************************/
FILE *abrir(char *archivo)
{
  FILE *pf;
  if ((pf = fopen(archivo, "r")) == NULL)
  {
    printf("El archivo %s no puede abrirse.\n", archivo);
    exit(2);
  }
  return pf;
}
