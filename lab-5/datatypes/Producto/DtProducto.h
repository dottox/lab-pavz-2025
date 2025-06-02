#pragma once

#include <iostream>

using namespace std;

class DtProducto
{
private:
    string codigo;
    string descripcion;

public:
    DtProducto();
    DtProducto(string, string);
    string getDescripcion();
    string getCodigo();
    DtProducto getProducto();
    virtual ~DtProducto();
};
