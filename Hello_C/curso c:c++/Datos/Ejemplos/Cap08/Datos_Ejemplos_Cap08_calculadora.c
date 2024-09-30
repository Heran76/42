// calculadora.c
//
#include <stdio.h>
#include <stdlib.h>

// Declaración de funciones
double sumar(double dato1, double dato2);
double restar(double dato1, double dato2);
double multiplicar(double dato1, double dato2);
double dividir(double dato1, double dato2);
int menu(void);
double ejecutar(double (*pfn)(), double a, double b);

int main(void)
{
  double dato1 = 0, dato2 = 0, resultado = 0;
  int op = 0;
  // Definir e iniciar la matriz de punteros
  double (*operacion[])(double, double) =
             {sumar, restar, multiplicar, dividir};

  while (1)
  {
    op = menu();

    if (op != 5)
    {
      // Leer datos
      printf("Dato 1: "); scanf("%lf", &dato1);
      printf("Dato 2: "); scanf("%lf", &dato2);
      // Limpiar el buffer del flujo de entrada
      while (getchar() != '\n');

      // Realizar la operación
      resultado = operacion[op-1](dato1, dato2);

      // Escribir el resultado
      printf("Resultado = %g\n", resultado);
      // Hacer una pausa
      printf("Pulse <Entrar> para continuar ");
      getchar();
    }
    else
      break;
  }
}

int menu()
{
  int op;
  do
  {
    system("cls");
    printf("\t1. sumar\n");
    printf("\t2. restar\n");
    printf("\t3. multiplicar\n");
    printf("\t4. dividir\n");
    printf("\t5. salir\n");
    printf("\nSeleccione la operación deseada: ");
    scanf("%d", &op);
  }
  while (op < 1 || op > 5);
  return op;
}

double sumar(double a, double b)
{
  return a + b;
}

double restar(double a, double b)
{
  return a - b;
}

double multiplicar(double a, double b)
{
  return a * b;
}

double dividir(double a, double b)
{
  return a / b;
}
