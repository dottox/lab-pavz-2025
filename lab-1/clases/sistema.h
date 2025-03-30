#pragma once

#include <iostream>
#include "socio.h"
#include "inscripcion.h"
#include "clase.h"
#include "entrenamiento.h"
#include "spinning.h"
#include "../globals/constants.h"

//Fin Errores de clases
using namespace std;

class Sistema {
  private:
    int cantSocios;
    Socio** socios;
    
    int cantClases;
    Clase** clases;
    
    Socio* getSocio(string);
    Clase* getClase(int);

  public:
    Sistema();

    // Funciones de los requerimientos
    void agregarSocio(string, string);
    void agregarInscripcion(string, int, DtFecha);
    void agregarClase(DtSpinning);
    void agregarClase(DtEntrenamiento);
    void listarClases();
    void listarSocios();
    DtSocio ** obtenerInfoSociosPorClase (int,int &);
    ~Sistema();


};