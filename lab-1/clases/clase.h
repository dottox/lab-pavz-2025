#ifndef CLASE_H
#define CLASE_H

#include <iostream>
using namespace std;

#include "../dataStructures/turno.cpp"

class Clase{
    public:
        int id;
        string nombre;
        Turno turno;
    private:
        Clase(int, string, Turno);
        virtual int cupo() = 0;
        ~Clase();
};

#endif