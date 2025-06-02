#pragma once

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class Empleado : ICollectible {
    protected:
        int numero;
        string nombre;
    public:
        Empleado(string);
        int getNumero();
        string getNombre();
        virtual ~Empleado();
};