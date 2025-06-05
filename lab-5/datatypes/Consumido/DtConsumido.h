#pragma once

#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtConsumido : public ICollectible
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
    friend ostream &operator<<(ostream &, const DtConsumido &);
    ~DtConsumido();
};