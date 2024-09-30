/* sscanf.c
 */
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(0, "");
    int i1, i2;
    float f1, f2;
    char str1[10], str2[4];

    char datos[] = "13 25,07e-1 d�gitos 23456 7890 34";
    int r = sscanf(datos, "%d%f%9s%2d%f%*d %3[0-9]",
                          &i1, &f1, str1, &i2, &f2, str2);
    /*
       los datos se leen as�:
       %d: un entero
       %f: un valor con decimales
       %9s: una cadena de como mucho 9 caracteres
            que no sean espacios en blanco
       %2d: un entero de dos d�gitos (d�gitos 2 y 3)
       %f:  un valor con decimales (d�gitos 4, 5, 6)
       %*d: un entero que no se almacena (*)
       ' ': todos los espacios en blanco consecutivos
       %3[0-9]: una cadena de como mucho 3 d�gitos (3 y 4)
    */

    printf("%d datos le�dos:\ni = %d\nx = %f\nstr1 = %s\n"
           "j = %d\ny = %f\nstr2 = %s\n",
           r, i1, f1, str1, i2, f2, str2);
}
