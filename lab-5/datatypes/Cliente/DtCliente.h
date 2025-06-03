#pragma once

#include <iostream>
#include "../Direccion/DtDireccion.h"

using namespace std;

class DtCliente
{
private:
    string nombre;
    string telefono;
    DtDireccion direccion;

public:
    DtCliente();
    DtCliente(string, string, DtDireccion);
    string getNombre();
    DtDireccion getDireccion();
    string getTelefono();
    friend ostream& operator<<(ostream&, const DtCliente&);
    ~DtCliente();
};