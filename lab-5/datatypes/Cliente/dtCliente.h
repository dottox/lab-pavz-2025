#pragma once

#include <iostream>
#include "../Direccion/dtDireccion.h"

using namespace std;

class dtCliente
{
private:
    string nombre;
    string telefono;
    dtDireccion direccion;

public:
    dtCliente(string, string, dtDireccion);
    string getNombre();
    dtDireccion getDireccion();
    string getTelefono();
    ~dtCliente();
};