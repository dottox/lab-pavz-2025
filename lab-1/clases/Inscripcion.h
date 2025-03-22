#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
using namespace std;

#include "../dataStructures/dtFecha.cpp"

class Inscripcion{
    private:
        DtFecha fecha;
    public:
        Inscripcion(DtFecha);
        DtFecha getFecha();
        ~Inscripcion();
};

#endif