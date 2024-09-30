// errno.c
//
#include <stdio.h>
#include <stdlib.h>
 
//extern int errno; // número de error
//extern char *sys_errlist[]; // mensajes de error
//extern int sys_nerr; // elementos del array sys_errlist

int main(void) 
{
  for (int i = 0; i < sys_nerr; i++)
  {
    printf("Error: %d, %s\n", i, sys_errlist[i]);
    getchar();
  }
}
