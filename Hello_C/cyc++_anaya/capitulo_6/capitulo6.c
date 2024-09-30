#include <stdio.h>

#define SECRETO 3
const int PREMIO = 6;

int main(void)
{
	int numero;
	
	printf("Introduce un numero: ");
	scanf("%d",&numero);
	fflush(stdin);

	if(numero == SECRETO)
		printf("Enhorabuna has ganado %d Puntos", PREMIO);
	else
		printf("los siento no has acertado el numero era el %d", SECRETO);
	return(0);

}
