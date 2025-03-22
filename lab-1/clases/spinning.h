#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>
#include "clase.h"
using namespace std;

class Spinning : Clase {
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