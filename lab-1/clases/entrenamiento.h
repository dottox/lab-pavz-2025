#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include <iostream>

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