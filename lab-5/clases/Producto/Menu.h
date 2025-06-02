#pragma once

#include <iostream>
#include "Producto.h"
#include "Plato.h"
#include "../../datatypes/Producto/DtMenu.h"

using namespace std;

class Menu : public Producto
{
private:
    Plato **platos;

public:
    Menu(DtMenu, Plato **);
    Plato **getPlatos();
    ~Menu();
};