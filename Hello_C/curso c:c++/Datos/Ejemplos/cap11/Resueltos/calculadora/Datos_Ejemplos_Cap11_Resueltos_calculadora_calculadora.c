//////////////////////////////////////////////////////////////////
// Utilizar una pila para simular una calculadora capaz de
// realizar las operaciones +, -, * y /, utilizando la
// notación postfija.
//
// calculadora.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_pila_cola.h"

void liberarMemoria(tpila *pila)
{
  // Borrar todos los elementos de la pila
  double *pdouble = NULL;
  // borrar: borra siempre el primer elemento
  pdouble = borrar(pila);
  while (pdouble)
  {
    free(pdouble); // borrar el área de datos
    pdouble = borrar(pila); // borrar elemento
  }
}

void *nuevoDouble(double d)
{
  // Reservar memoria para un double
  double *p = (double *)malloc(sizeof(double));
  if (!p) return 0;
  *p = d;
  return p;
}

int obtenerOperandos(double operando[], tpila *pila)
{
  // Obtener los dos operandos de la cima de la pila
  double *pdouble = NULL;

  if (pila->numeroDeElementos < 2)
  {
    printf("Error: teclee %d operando(s) más\n",
           2 - pila->numeroDeElementos);
    return 0;
  }
  pdouble = (double *)sacarDePila(pila);
  if (!pdouble) return 0;
  operando[0] = *pdouble;
  free(pdouble);
  pdouble = (double *)sacarDePila(pila);
  operando[1] = *pdouble;
  free(pdouble);
  return 1;
}

void error1(tpila *pila)
{
  liberarMemoria(pila);
  error();
}

int main(void)
{
  int m = 0; // controlar errores
  double *p = 0;
  // oper almacena la entrada realizada desde el teclado
  char oper[20];
  // operando almacena los dos operandos
  double operando[2];

  // Pila vacía
  tpila pila;
  iniciarPila(&pila);

  printf("Operaciones: + - * /\n\n");
  printf("Forma de introducir los datos:\n");
  printf(">operando 0 [Entrar]\n");
  printf(">operando 1 [Entrar]\n");
  printf(">operador [Entrar]\n\n");
  printf("Para salir pulse q\n\n");

  do
  {
    printf("> ");
    scanf("%s", oper);       // leer un operando o un operador
    switch (oper[0])  // verificar el primer carácter
    {
      case '+':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] + operando[1]);
        if (p = nuevoDouble(operando[0] + operando[1]))
          m = meterEnPila(p, &pila);
        break;
      case '-':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] - operando[1]);
        if (p = nuevoDouble(operando[0] - operando[1]))
          m = meterEnPila(p, &pila);
        break;
      case '*':
        if (!obtenerOperandos(operando, &pila)) break;
        printf("%g\n", operando[0] * operando[1]);
        if (p = nuevoDouble(operando[0] * operando[1]))
          m = meterEnPila(p, &pila);
        break;
      case '/':
        if (!obtenerOperandos(operando, &pila)) break;
        if (operando[1] == 0)
        {
          printf("\nError: división por cero");
          break;
        }
        printf("%g\n", operando[0] / operando[1]);
        if (p = nuevoDouble(operando[0] / operando[1]))
          m = meterEnPila(p, &pila);
        break;
      case 'q':
        // salir
        break;
      default :  // es un operando
        if (p = nuevoDouble(atof(oper)))
          m = meterEnPila(p, &pila);
    }
    if (oper[0] != 'q' && (m == 0 || p == 0))
    {
      if (p) free(p);
      error1(&pila);
    }
  }
  while (oper[0] != 'q');

  // Borrar la pila
  liberarMemoria(&pila);
}
