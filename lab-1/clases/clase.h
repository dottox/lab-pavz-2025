#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "./inscripcion.h"
#define MAX_INSCRIPCIONES 100

class Clase
{
private:
    int id;
    string nombre;
    Turno turno;
    Inscripcion** inscripciones;
    int cantInscripciones;

public:
    Clase(DtClase);
    int getId();
    string getNombre();
    Turno getTurno();
    virtual int cupo() = 0;
    virtual ~Clase();
    void agregarInscripcion(Inscripcion *);
    int getCantInscripciones();
    Inscripcion **getInscripciones();
};