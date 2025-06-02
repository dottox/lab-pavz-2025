#pragma once

#include <iostream>
#include "../Direccion/DtDireccion.h"

using namespace std;

class DtCliente
{
private:
    string nombre;
    string telefono;
    dtDireccion direccion;

public:
    DtCliente(string, string, dtDireccion);
    string getNombre();
    dtDireccion getDireccion();
    string getTelefono();
    ~DtCliente();
};