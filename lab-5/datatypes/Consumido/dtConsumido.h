#pragma once

#include <iostream>

using namespace std;

class DtConsumido
{
private:
    string descripcion;
    int cantidad;
    float precio;

public:
    DtConsumido();
    DtConsumido(string, int, float);
    string getDescripcion();
    int getCantidad();
    float getPrecio();
    ~DtConsumido();
};