#pragma once

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class Empleado : public ICollectible {
    protected:
        int numero;
        string nombre;
    public:
        Empleado(string);
        int getNumero();
        string getNombre();
        friend ostream & operator<<(ostream &, const Empleado&);
        virtual ~Empleado();
};