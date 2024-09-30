// Trabajar con una base de datos
// basededatos.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Definición del tipo registro
typedef struct
{
  char referencia[20];
  double precio;
} registro;

// Definición del tipo baseDeDatos.
typedef struct
{
  char nomArchivo[20]; // nombre del archivo
  FILE *fes;           // flujo hacia/desde el archivo
  int nregs;           // número de registros
  int tamreg;          // tamaño del registro en bytes
  int regsEliminados;  // 1 cuando se haya borrado algún registro
} baseDeDatos;

void fflushstdin(void);
char *leerCadena(char *, int);

/////////////////////////////////////////////////////////////////
// Definición de las funciones para manipular la base de datos:
//   1. iniciar un registro
//   2. ¿existe el archivo sobre el que se desea trabajar?
//   3. escribir un registro
//   4. añadir un registro al final
//   5. leer un registro i
//   6. buscar un registro específico
//   7. eliminar un registro
//   8. iniciar base de datos
//   9. cerrar base de datos
//  10. actualizar la base de datos
//
void IniciarRegistro(registro *reg)
{
  *(reg->referencia) = 0;
  reg->precio = 0.0;
}

bool Existe(char *nombreArchivo)
{
  FILE *pf = NULL;
  int exis = false; // no existe

  // ¿Existe el archivo?
  if ((pf = fopen(nombreArchivo, "r")) != NULL)
  {
    exis = true;   // existe
    fclose(pf);
  }
  return exis;
}

int EscribirRegistro( int i, registro reg, baseDeDatos bd )
{
  if (i >= 0 && i <= bd.nregs)
  {
    // Situar el puntero de L/E en el registro i
    fseek(bd.fes, i * bd.tamreg, SEEK_SET);
    // Sobrescribir el registro con la nueva información
    fwrite(&reg, bd.tamreg, 1, bd.fes);
    if (!ferror(bd.fes)) return 1;
    printf("Error al escribir en el archivo\n");
  }
  else
    printf("Número de registro fuera de límites\n");
  return 0;
}

void AnyadirRegistro( registro reg, baseDeDatos *bd )
{
  // Añadir un registro al final del archivo e incrementar
  // el número de registros
  if (EscribirRegistro( bd->nregs, reg, *bd )) bd->nregs++;
}

registro LeerRegistro( int i, baseDeDatos bd )
{
  registro reg;
  IniciarRegistro(&reg);

  if (i >= 0 && i < bd.nregs)
  {
    // Situar el puntero de L/E en el registro i
    fseek(bd.fes, i * bd.tamreg, SEEK_SET);
    // Leer la información correspondiente al registro i
    fread(&reg, bd.tamreg, 1, bd.fes);
  }
  else
    printf("Número de registro fuera de límites\n");

  // Devolver el registro correspondiente.
  return reg;
}

int BuscarRegistro( char *str, int nreg, baseDeDatos bd )
{
  // Buscar un registro por una subcadena de la referencia
  // a partir de un registro determinado. Si se encuentra,
  // se devuelve el número de registro, o -1 en otro caso
  registro reg;

  if (str == NULL) return -1;
  if (nreg < 0) nreg = 0;
  for ( int reg_i = nreg; reg_i < bd.nregs; reg_i++ )
  {
    // Obtener el registro reg_i
    reg = LeerRegistro(reg_i, bd);
    // ¿str está contenida en referencia?
    if (strstr(reg.referencia, str))
      return reg_i; // devolver el número de registro
  }
  return -1; // la búsqueda falló
}

int EliminarRegistro( char *ref, baseDeDatos *bd)
{
  registro reg;
  // Buscar la referencia y marcar el registro correspondiente
  // para poder eliminarlo cuando se requiera
  for ( int reg_i = 0; reg_i < bd->nregs; reg_i++ )
  {
    // Obtener el registro reg_i
    reg = LeerRegistro(reg_i, *bd);
    // ¿Tiene la referencia ref?
    if (strcmp(ref, reg.referencia) == 0)
    {
      // Marcar el registro con la referencia "borrar"
      strcpy(reg.referencia, "borrar");
      // Grabarlo
      EscribirRegistro( reg_i, reg, *bd );

      bd->regsEliminados = 1;
      return 1;
    }
  }
  return 0;
}

void IniciarBaseDeDatos(baseDeDatos *bd)
{
  *(bd->nomArchivo) = 0;
  bd->fes = NULL;
  bd->nregs = 0;
  bd->tamreg = sizeof(registro);
  bd->regsEliminados = 0;
}

int ActualizarBaseDeDatos( baseDeDatos *bd );
void CerrarBaseDeDatos( baseDeDatos *bd )
{
  if (bd->regsEliminados)
  {
    bd->regsEliminados = 0;
    ActualizarBaseDeDatos(bd);
  }
  if (bd->fes) fclose(bd->fes); // cerrar el archivo actual
  bd->fes = NULL;
  bd->nregs = 0;      // poner a cero el n.º de registros
}

int ActualizarBaseDeDatos( baseDeDatos *bd )
{
  registro reg;
  baseDeDatos bdtemp;
  IniciarBaseDeDatos(&bdtemp);

  // Crear una bd temporal.
  bdtemp.fes = tmpfile();
  if (bdtemp.fes == NULL)
  {
    printf("Error: No se puede crear un archivo temporal\n");
    return 0;
  }

  // Copiar en el archivo temporal todos los registros del
  // archivo actual que no estén marcados para "borrar"
  for ( int reg_i = 0; reg_i < bd->nregs; reg_i++ )
  {
    reg = LeerRegistro(reg_i, *bd);
    if (strcmp(reg.referencia, "borrar") == 0) continue;
    AnyadirRegistro(reg, &bdtemp);
  }
  // Copiar en el archivo actual todos los registros del temporal.
  // Para ello, creamos de nuevo el actual.
  CerrarBaseDeDatos(bd);
  if ((bd->fes = fopen(bd->nomArchivo, "w+b")) == NULL)
  {
    printf("Error: No se puede crear el archivo\n");
    return 0;
  }
  rewind(bdtemp.fes); // volver al principio del archivo temporal
  for ( int reg_i = 0; reg_i < bdtemp.nregs; reg_i++ )
  {
    reg = LeerRegistro(reg_i, bdtemp);
    AnyadirRegistro(reg, bd);
  }

  return 1;
}
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// Funciones que responderán a cada una de las opciones del menú
//
int menuAbrirBaseDeDatos(baseDeDatos *bd)
{
  char resp = 'n';
  char *modo;

  if (bd->fes)
  {
    printf("Ya hay un archivo abierto.\n");
    return 0;
  }

  printf("Nombre del archivo: ");
  leerCadena(bd->nomArchivo, sizeof(bd->nomArchivo)); // nombre archivo
  modo = "w+b";
  if (Existe(bd->nomArchivo))
  {
    do
    {
      printf("Este archivo existe ¿Desea sobrescribirlo? (s/n) ");
      resp = tolower(getchar());
      fflushstdin();
    }
    while (resp != 's' && resp != 'n');
    if (resp == 'n')
      modo = "r+b";
  }

  if ((bd->fes = fopen(bd->nomArchivo, modo)) == NULL)
  {
    printf("Error: No se puede crear el archivo\n");
    bd->fes = 0; // archivo no abierto
    return 0;
  }
  // Establecer los datos longitud del registro y n.º de registros
  bd->tamreg = sizeof(registro);
  fseek(bd->fes, 0, SEEK_END);
  bd->nregs = ftell(bd->fes)/sizeof(registro);
  rewind(bd->fes);
  printf("Archivo %s abierto\n", bd->nomArchivo);
  return 1;
}

void menuAnyadirReg(baseDeDatos *bd)
{
  registro reg;

  printf("Referencia:    ");
  leerCadena(reg.referencia, sizeof(reg.referencia));
  printf("Precio:        ");
  scanf("%lf", &reg.precio); fflushstdin();
  AnyadirRegistro( reg, bd );
}

void menuModificarReg(baseDeDatos bd)
{
  registro reg;
  int op = 3, nreg = 0;

  if (bd.nregs == 0)
  {
    printf("archivo vacío\n");
    return;
  }

  // Solicitar el número de registro a modificar
  printf("Número de registro entre 0 y %d: ", bd.nregs - 1);
  scanf("%d", &nreg); fflushstdin();

  // Leer el registro
  reg = LeerRegistro(nreg, bd);
  if (strcmp(reg.referencia, "") == 0 && reg.precio == 0.0) return;
  // Visualizarlo
  printf("%s\n", reg.referencia);
  printf("%g\n", reg.precio);

  // Modificar el registro
  do
  {
    printf("\n\n");
    printf("Modificar el dato:\n");
    printf("1. Referencia\n");
    printf("2. Precio\n");
    printf("3. Salir y salvar los cambios\n");
    printf("4. Salir sin salvar los cambios\n\n");
    printf("   Opción: ");
    scanf("%d", &op); fflushstdin();

    switch( op )
    {
      case 1: // modificar referencia
        printf("Referencia:    ");
        leerCadena(reg.referencia, sizeof(reg.referencia));
        break;
      case 2: // modificar precio
        printf("Precio:        ");
        scanf("%lf", &reg.precio); fflushstdin();
        break;
      case 3: // guardar los cambios
        break;
      case 4: // salir sin guardar los cambios
        break;
    }
  }
  while( op != 3 && op != 4);

  if (op == 3) EscribirRegistro(nreg, reg, bd);
}

int menuEliminarReg(baseDeDatos *bd)
{
  char referencia[20];
  int eliminado = 0;

  if (bd->nregs == 0)
  {
    printf("archivo vacío\n");
    return 0;
  }

  printf("Referencia: ");
  leerCadena(referencia, sizeof(referencia));
  eliminado = EliminarRegistro( referencia, bd);
  if (eliminado)
    printf("registro eliminado\n");
  else
    if (bd->nregs != 0)
      printf("referencia no encontrada\n");
    else
      printf("lista vacía\n");
  return eliminado;
}

void menuVisualizarRegs(baseDeDatos bd)
{
  registro reg;
  char str[20];
  int nreg = -1;

  IniciarRegistro(&reg);

  if (bd.nregs == 0)
  {
    printf("archivo vacío\n");
    return;
  }

  printf("conjunto de caracteres a buscar: ");
  leerCadena(str, sizeof(str));
  // str igual a * visualiza todos
  do
  {
    if ( *str != '*' )
      nreg = BuscarRegistro(str, nreg+1, bd);
    else
      if (++nreg == bd.nregs) break;
    if (nreg > -1)
    {
      reg = LeerRegistro(nreg, bd);
      printf("Registro: %d\n", nreg);
      printf("%s\n", reg.referencia);
      printf("%g\n\n", reg.precio);
    }
  }
  while (nreg != -1);

  if (strcmp(reg.referencia, "") == 0 && reg.precio == 0.0)
    printf("no se encontró ningún registro\n");
}

int menu(baseDeDatos bd)
{
  int op;
  printf("\n\n");
  printf("1. Abrir archivo\n");
  printf("2. Añadir registro\n");
  printf("3. Modificar registro\n");
  printf("4. Eliminar registro\n");
  printf("5. Visualizar registros\n");
  printf("6. Salir\n\n");
  printf("   Opción: ");
  do
  {
    scanf("%d", &op); fflushstdin();
    if (op < 1 || op > 6)
      printf("Opción no válida. Elija otra: ");
  }
  while (op < 1 || op > 6);

  if (op > 1 && op < 6 && !bd.fes)
  {
    printf("No hay un archivo abierto.\n");
    return 0;
  }
  return op;
}

int main(void)
{
  int opcion = 0;
  baseDeDatos articulos;
  IniciarBaseDeDatos(&articulos);

  do
  {
    opcion = menu(articulos);
    switch (opcion)
    {
      case 1: // abrir archivo
        menuAbrirBaseDeDatos(&articulos);
        break;
      case 2: // añadir registro al final del archivo
        menuAnyadirReg(&articulos);
        break;
      case 3: // modificar registro
        menuModificarReg(articulos);
        break;
      case 4: // eliminar registro
        menuEliminarReg(&articulos);
        break;
      case 5: // visualizar registros
        menuVisualizarRegs(articulos);
        break;
      case 6: // salir
        CerrarBaseDeDatos(&articulos);
    }
  }
  while(opcion != 6);
}

void fflushstdin(void)
{
  if (!feof(stdin) && !ferror(stdin))
    while ((getchar()) != '\n');
}

char *leerCadena(char *str, int n)
{
  char *fin, *c = 0;
  fin = fgets(str, n, stdin);
  if (c = strchr(str, '\n'))
    *c = 0; // reemplazar '\n'
  else if (!feof(stdin))
    while (getchar() != '\n'); // limpiar buffer stdin
  return fin;
}
