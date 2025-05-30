#pragma once

#include <iostream>

using namespace std;

class dtConsumido
{
private:
    string descripcion;
    int cantidad;
    float precio;

public:
    dtConsumido();
    dtConsumido(string, int, float);
    string getDescripcion();
    int getCantidad();
    float getPrecio();
    ~dtConsumido();
};