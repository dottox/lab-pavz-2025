#pragma once

#include <iostream>

using namespace std;

class dtProducto
{
private:
    string codigo;
    string descripcion;

public:
    dtProducto();
    dtProducto(string, string);
    string getDescripcion();
    string getCodigo();
    dtProducto getProducto();
    virtual ~dtProducto();
};
