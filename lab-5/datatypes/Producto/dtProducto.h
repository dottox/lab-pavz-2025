#pragma once

#include <iostream>

using namespace std;

class dtProducto
{
private:
    int id;
    string codigo;
    string descripcion;

public:
    dtProducto();
    dtProducto(int, string, string);
    int getId();
    string getDescripcion();
    string getCodigo();
    dtProducto getProducto();
    virtual ~dtProducto();
};
