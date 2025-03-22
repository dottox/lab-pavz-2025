#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>

#include "clase.h"
#include "../dataStructures/turno.cpp"

using namespace std;

class Spinning : public Clase {
    private:
        int cantBicicletas;
    public:
        Spinning(int, string, Turno, int);
        int cupo();
        void setCantBicicletas(int);
        int getCantBicicletas();
        ~Spinning();
};
#endif