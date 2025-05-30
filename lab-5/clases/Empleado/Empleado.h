#pragma once

#include <iostream>
using namespace std;

class Empleado {
    protected:
        int numero;
        string nombre;
    public:
        Empleado(string);
        int getNumero();
        string getNombre();
        virtual ~Empleado();
};