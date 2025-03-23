#ifndef CLASE_H
#define CLASE_H

#include <iostream>
using namespace std;

#include "../dataStructures/turno.cpp"
#include "../dataStructures/dtClase.cpp"
#include "../clases/Inscripcion.cpp"

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

#endif