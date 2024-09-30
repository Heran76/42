/* localtime.c
 */
#include <stdio.h>
#include <time.h> 
 
int main(void)
{ 
  struct tm *fh;
  time_t segundos; 
  time(&segundos); 
  fh = localtime(&segundos); 
  printf("%d horas, %d minutos\n", fh->tm_hour, fh->tm_min); 
}
