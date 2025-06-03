#pragma once

#include <iostream>
#include "../Empleado/Empleado.h"
#include "../../enums/Transporte.h"

using namespace std;

class Repartidor : public Empleado{
protected:
    Transporte transporte;

public:
    Repartidor(string, Transporte);
    Transporte getTransporte() const;
    friend ostream & operator<<(ostream &, const Repartidor&);
    ~Repartidor();
};