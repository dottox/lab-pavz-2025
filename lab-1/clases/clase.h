#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "./inscripcion.h"

class Clase{

private:
    int id;
    string nombre;
    Turno turno;
    Inscripcion** inscripciones;
    int cantInscripciones;
    int cantCupo = 0; //Esto no se si está bien

public:
    Clase(DtClase);
    int getId();
    string getNombre();
    Turno getTurno();
    
    virtual int cupo() = 0; // Funcion polimorfica
    void agregarInscripcion(Inscripcion *);
    int getCantInscripciones();
    Inscripcion** getInscripciones();
    Inscripcion* getInscripcion(string, DtFecha);
    
    virtual ~Clase();
};