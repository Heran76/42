/* complejo.h */
#pragma once

typedef struct
{
  float r; // parte real de un número complejo
  float i; // parte imaginaria de un número complejo
} tcomplejo;

void fflushstdin(void);
tcomplejo leerComplejo();
void mostrarComplejo(tcomplejo c);
tcomplejo multiplicarComplejos(tcomplejo a, tcomplejo b);
tcomplejo sumarComplejos(tcomplejo a, tcomplejo b);
// Otras operaciones...
