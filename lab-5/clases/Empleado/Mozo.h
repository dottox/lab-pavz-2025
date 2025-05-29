#pragma once

#include <iostream>
#include "../Empleado/Empleado.h"
#include "../Mesa/Mesa.h"
using namespace std;

class Mozo : public Empleado{
private:
    Mesa ** mesasAsignadas;
    int cantidadMesasAsignadas;

public:
    Mozo(string);
    ~Mozo();
};