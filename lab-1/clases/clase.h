#ifndef CLASE_H
#define CLASE_H

#include <iostream>
using namespace std;

#include "../dataStructures/turno.cpp"
#include "../dataStructures/dtClase.cpp"

class Clase{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        Clase(DtClase*);
        int getId();
        string getNombre();
        Turno getTurno();
        virtual int cupo() = 0;
        virtual ~Clase();
};

#endif