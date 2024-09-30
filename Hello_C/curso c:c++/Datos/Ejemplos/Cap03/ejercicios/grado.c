#include <stdio.h>

#define INF -30
#define SUP 100

float convertir(int c);

int main(void)
{
	int nGradosCentigrados = 0;
	int incremento = 6;
	float GradosFahrenheit = 0;

	nGradosCentigrados = INF;
	while(nGradosCentigrados <= SUP)
	{
		GradosFahrenheit = convertir(nGradosCentigrados);
		printf("%10d C %10.2F F\n", nGradosCentigrados, GradosFahrenheit);
		nGradosCentigrados += incremento; 
	}

}

float convertir(int gcent)
{
	float gfahr;
	gfahr = (float)9 / (float)5 * gcent + 32;
	return (gfahr);
}

