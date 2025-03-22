#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include <iostream>
#include "clase.h"
using namespace std;

class Entrenamiento : Clase{
    private: 
        bool enRambla;
    public:
        int cupo();
        void setRambla(bool);
        bool getRambla();
};
#endif