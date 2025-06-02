#pragma once

#include <iostream>
#include "DtProducto.h"

using namespace std;

class DtPlato : public DtProducto
{
private:
    float precio;
    

public:
    DtPlato();
    DtPlato(string, string,float);
    float getPrecio();
    string getDescripcion();
    string getCodigo();
    ~DtPlato();
    
};
