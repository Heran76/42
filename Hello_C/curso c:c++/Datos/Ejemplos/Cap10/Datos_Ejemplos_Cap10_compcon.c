/****** Compilación condicional ******/
/* compcon.c
 */
#include <stdio.h>

#define USA 1   // Estados Unidos
#define ESP 2   // España
#define JPN 3   // Japón

#define PAIS_ACTIVO ESP

int main(void) 
{ 
  #if PAIS_ACTIVO == USA 
     char moneda[] = "dólar"; 
  #elif PAIS_ACTIVO == ESP 
     char moneda[] = "euro "; 
  #elif PAIS_ACTIVO == JPN 
     char moneda[] = "yen  "; 
  #endif 
 
  printf("%s", moneda); 
} 
