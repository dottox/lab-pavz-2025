#pragma once

#include <iostream>
using namespace std;

class dtAsignacion
{
private:
    int numeroMozo;
    int numeroMesa;

public:
    dtAsignacion();
    dtAsignacion(int, int);
    int getNumeroMozo();
    int getNumeroMesa();
    ~dtAsignacion();
};