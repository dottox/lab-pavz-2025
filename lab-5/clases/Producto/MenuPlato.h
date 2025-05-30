#pragma once

#include <iostream>

#include "../Producto/Plato.h"
#include "../Producto/Menu.h"

using namespace std;

class MenuPlato
{
private:
    Plato *plato;
    Menu *menu;
    int cantidad;

public:
    MenuPlato(Plato*, Menu*, int);
    Plato *getPlato();
    Menu *getMenu();
    int getCantidad();
    void setCantidad(int);
    ~MenuPlato();
};