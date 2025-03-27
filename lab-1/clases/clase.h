#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "./inscripcion.h"
<<<<<<< HEAD
#define MAX_INSCRIPCIONES 100
#define DEFAULT_INSCRIPCIONES 0

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
    
    virtual int cupo() = 0; // Funcion polimorfica
    void agregarInscripcion(Inscripcion *);
    int getCantInscripciones();
    Inscripcion **getInscripciones();
    
    virtual ~Clase();
=======
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
>>>>>>> dev
};