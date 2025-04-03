#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "inscripcion.h"
#include "../globals/constants.h"


class Clase{

  protected:
    int id;
    string nombre;
    Turno turno;
    Inscripcion** inscripciones;
    int cantInscripciones;
    int cantCupo;

  public:
    Clase(DtClase);
    int getId();
    string getNombre();
    Turno getTurno();
    int getCantInscripciones();

    void setNombre(string);
    void setTurno(Turno);

    virtual int cupo() = 0; // Funcion polimorfica
    void agregarInscripcion(Inscripcion *);
    Inscripcion* getInscripcion(string);
    Inscripcion** getInscripciones();
    void borrarInscripcion(string);

    virtual ~Clase();
};
