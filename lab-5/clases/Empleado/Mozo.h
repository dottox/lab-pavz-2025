#pragma once

#include <iostream>
#include "../Empleado/Empleado.h"
#include "../Mesa/Mesa.h"

using namespace std;

class Mesa;

class Mozo : public Empleado{
protected:
    Mesa ** mesasAsignadas;
    int cantidadMesasAsignadas;

public:
    Mozo(string);
    int getCantidadMesasAsignadas() const;
    friend ostream & operator<<(ostream&, const Mozo&);
    ~Mozo();
};