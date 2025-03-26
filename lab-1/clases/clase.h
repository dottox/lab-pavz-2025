
#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "./inscripcion.h"
#define MAX_INSCRIPCIONES 3

/**
 * @class Clase
 * @brief Represents a class with an ID, name, schedule (turno), and a list of inscriptions.
 * 
 * This is an abstract base class that provides a common interface for different types of classes.
 * It includes methods to manage inscriptions and retrieve class details.
 */
class Clase{
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
        void agregarInscripcion(Inscripcion*);
        int getCantInscripciones();
        Inscripcion** getInscripciones();
};