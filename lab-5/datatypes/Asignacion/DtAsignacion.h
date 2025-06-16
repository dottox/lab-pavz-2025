#pragma once

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class DtAsignacion : public ICollectible
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