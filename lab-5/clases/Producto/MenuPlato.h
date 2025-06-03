#pragma once

#include <iostream>

#include "../Producto/Plato.h"

using namespace std;

class MenuPlato : public ICollectible
{
private:
    Plato* plato;
    int cantidad;

public:
    MenuPlato(Plato*, int);
    Plato *getPlato();
    int getCantidad();
    void setCantidad(int);
    ~MenuPlato();
};