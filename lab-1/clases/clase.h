#ifndef CLASE_H
#define CLASE_H

#include <iostream>
using namespace std;

#include "../dataStructures/turno.cpp"

class Clase{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        Clase(int, string, Turno);
        int getId();
        virtual int cupo() = 0;
        virtual ~Clase();
};

#endif