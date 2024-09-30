/* complejo.h */
#if !defined _INC_COMPLEJO
#define _INC_COMPLEJO

typedef struct
{
  float r; // parte real de un n�mero complejo
  float i; // parte imaginaria de un n�mero complejo
} tcomplejo;

void fflushstdin(void);
tcomplejo leerComplejo();
void mostrarComplejo(tcomplejo c);
tcomplejo multiplicarComplejos(tcomplejo a, tcomplejo b);
tcomplejo sumarComplejos(tcomplejo a, tcomplejo b);
// Otras operaciones...

#endif
