#pragma once

#include <iostream>
using namespace std;

#include "../dataStructures/turno.h"
#include "../dataStructures/dtClase.h"
#include "inscripcion.h"
#include "../globals/constants.h"


/*
  * @class Clase
  * @brief Represents a class with its details and inscriptions.
  * 
  * The Clase class encapsulates the details of a class, including its
  * ID, name, turn, and the list of inscriptions. It provides methods to manage
  * the class, including adding and removing inscriptions.
*/
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

    int cupo();
    void agregarInscripcion(Inscripcion *);
    Inscripcion* getInscripcion(string);
    Inscripcion** getInscripciones();
    void borrarInscripcion(string);

    virtual ~Clase();
};
