#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>
using namespace std;
class Spinning : Clase{
    private:
        int cantBicicletas;
    public:
        int cupo();
        void setCantBicicletas(int);
        int getCantBicicletas();
};
#endif