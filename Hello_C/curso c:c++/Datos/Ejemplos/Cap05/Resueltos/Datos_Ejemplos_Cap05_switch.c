/******* Días correspondientes a un mes de un año dado *******/
/* switch.c
 */
#include <stdio.h>

enum meses {ninguno, enero, febrero, marzo, abril, mayo, junio,
            julio, agosto, septiembre, octubre, noviembre, diciembre};

int main(void)
{
  int dd = 0, mm = 0, aa = 0;

  printf("Introducir mes (##) y año (####): ");
  scanf("%d %d", &mm, &aa);
  switch (mm)
  {
    case enero:
    case marzo:
    case mayo:
    case julio:
    case agosto:
    case octubre:
    case diciembre:
      dd = 31;
      break;
    case abril:
    case junio:
    case septiembre:
    case noviembre:
      dd = 30;
      break;
    case febrero:
      // ¿Es el año bisiesto?
      if ((aa % 4 == 0) && (aa % 100 != 0) || (aa % 400 == 0))
        dd = 29;
      else
        dd = 28;
        break;
    default:
      printf("\nEl mes no es válido\n");
      break;
  }
  if (mm >= enero && mm <= diciembre)
    printf("\nEl mes %d del año %d tiene %d días\n",mm,aa,dd);
}
