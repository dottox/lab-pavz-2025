#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>
#include "clase.h"
using namespace std;
class Spinning : Clase{
    private:
        int cantBicicletas;
    public:
        Spinning();
        Spinning(int);
        int cupo();
        int cupo(int);
        void setCantBicicletas(int);
        int getCantBicicletas();
        ~Spinning();
};
#endif