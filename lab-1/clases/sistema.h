#pragma once

#include <iostream>

#include "socio.h"
#include "inscripcion.h"
#include "clase.h"
#include "entrenamiento.h"
#include "spinning.h"
#include "../globals/constants.h"

using namespace std;

/*
  * @class Sistema
  * @brief Represents the system that manages socios and classes.
  * 
  * The Sistema class encapsulates the functionality of managing socios and classes,
  * including adding, listing, and retrieving information about them.
*/
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
    void listarClases();
    void listarSocios();
    int getCantSocios();
    int getCantClases();
  
    // Funciones de los requerimientos
    void agregarSocio(string, string);
    void agregarInscripcion(string, int, DtFecha);
    void agregarClase(DtSpinning);
    void agregarClase(DtEntrenamiento);
    void borrarInscripcion(string, int);

    Socio* getSocio(string);
    Clase* getClase(int);
  
    DtSocio ** obtenerInfoSociosPorClase(int, int &);
    DtClase obtenerClase(int);
    
    ~Sistema();


};