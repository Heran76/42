#include <stdio.h>

#define INF 1
#define ERR 2
#define STD_OUT stdout
#define STD_ERR stderr

#define LOG_MSJ(prioridad, flujo, msj, ...)\
          {\
            char *str;\
            if (prioridad == INF)\
              str = "INF";\
            else if (prioridad == ERR)\
              str = "ERR";\
            fprintf(flujo, "[%s] : %s : %d : "msj"\n", \
              str, __FILE__, __LINE__, ##__VA_ARGS__);\
          } 

int main(void)
{
  char *s = "funcion01";
  int a = 1, b = 2;

  // Mostrar un mensaje de error
  LOG_MSJ(ERR, STD_ERR, "El archivo no se puede abrir");

  // Información como argumento adicional
  LOG_MSJ(INF, STD_OUT, "Se ejecutó satisfactoriamente %s", s);

  // Información como argumentos adicionales
  LOG_MSJ(INF, STD_OUT, "%d + %d = %d", a, b, (a + b));

  return 0;
}
