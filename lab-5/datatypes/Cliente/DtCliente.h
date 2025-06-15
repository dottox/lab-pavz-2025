#pragma once

#include <iostream>
#include "../Direccion/DtDireccion.h"

using namespace std;

class DtCliente
{
private:
    string nombre;
    int telefono;
    DtDireccion direccion;

public:
    DtCliente();
    DtCliente(string, int, DtDireccion);
    string getNombre();
    DtDireccion getDireccion();
    int getTelefono();
    friend ostream& operator<<(ostream&, const DtCliente&);
    ~DtCliente();
};