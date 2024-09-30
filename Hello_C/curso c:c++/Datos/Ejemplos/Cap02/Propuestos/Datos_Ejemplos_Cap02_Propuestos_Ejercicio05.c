/*************************** Tipos primitivos ***********************/
// Cap2\ejercicio05.c

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  printf("Enteros:\n char = %2zd bytes\n short = %2zd bytes\n int = %2zd bytes\n long = %2zd bytes\n long long = %2zd bytes\n bool = %2zd bytes\n",
	sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long), sizeof(bool));
  printf(" (Los tipos signed, ocupan igual que sus respectivos unsigned)\n");
  printf("Reales:\n float = %2zd bytes\n double = %2zd bytes\n long double = %2zd bytes\n",
	sizeof(float), sizeof(double), sizeof(long double));
}
