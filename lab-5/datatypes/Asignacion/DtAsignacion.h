#pragma once

#include <iostream>
using namespace std;

class DtAsignacion
{
private:
    int numeroMozo;
    int numeroMesa;

public:
    DtAsignacion();
    DtAsignacion(int, int);
    int getNumeroMozo();
    int getNumeroMesa();
    ~DtAsignacion();
};