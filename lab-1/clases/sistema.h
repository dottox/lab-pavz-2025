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
    int MAXSOCIOS;
    int cantSocios;
    Socio** socios;
    
    int MAXCLASES;
    int cantClases;
    Clase** clases;
    
    
    public:
    Sistema();
    Sistema(int,int);
    
    // Funciones de los requerimientos
    void agregarSocio(string, string);
    void agregarInscripcion(string, int, DtFecha);
    void agregarClase(DtSpinning);
    void agregarClase(DtEntrenamiento);
    void listarClases();
    void listarSocios();
    int getCantSocios();
    int getCantClases();
    Socio* getSocio(string);
    Clase* getClase(int);
    DtSocio ** obtenerInfoSociosPorClase(int, int &);
    DtClase obtenerClase(int);
    ~Sistema();


};