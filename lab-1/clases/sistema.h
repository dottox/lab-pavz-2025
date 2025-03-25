#include <iostream>
#include "socio.h"
#include "inscripcion.h"
#include "clase.h"
#include "entrenamiento.h"
#include "spinning.h"
#define MAX_SOCIOS 3
#define MAX_CLASES 3

using namespace std;

class Sistema {
  private:
    int cantSocios;
    Socio** socios;
    
    int cantClases;
    Clase** clases;

  public:
    Sistema();
    void agregarSocio(string, string);
    Socio* getSocio(string);
    Clase* getClase(int);
    void agregarInscripcion(string, int, DtFecha);
    void agregarClase(DtSpinning);
    void agregarClase(DtEntrenamiento);
    void listarClases();
    void listarSocios();
    bool buscarClase(int);
    ~Sistema();
};