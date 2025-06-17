#pragma once

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtConsumido : public ICollectible
{
private:
    char* codigo;
    string descripcion;
    int cantidad;
    float precio;

public:
    DtConsumido();
    DtConsumido(char*, string, int, float);
    char* getCodigo();
    string getDescripcion();
    int getCantidad();
    float getPrecio();
    friend ostream &operator<<(ostream &, const DtConsumido &);
    ~DtConsumido();
};