#ifndef CLASE_H
#define CLASE_H

#include <iostream>
using namespace std;

#include "../dataStructures/turno.cpp"

class Clase{
    public:
        int id;
        string nombre;
        turno turno;
    private:
        Clase(int, string, turno);
        virtual int cupo() = 0;
        ~Clase();
};

#endif