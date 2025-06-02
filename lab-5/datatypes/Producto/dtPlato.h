#pragma once

#include <iostream>
#include "dtProducto.h"

using namespace std;

class dtPlato : public dtProducto
{
private:
    float precio;
    

public:
    dtPlato();
    dtPlato(string, string,float);
    float getPrecio();
    string getDescripcion();
    string getCodigo();
    ~dtPlato();
    
};
