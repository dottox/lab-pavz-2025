#pragma once

#include <iostream>
#include "Producto.h"
#include "Plato.h"
#include "../../datatypes/Producto/dtMenu.h"

using namespace std;

class Menu : public Producto
{
private:
    Plato **platos;

public:
    Menu(dtMenu, Plato **);
    Plato **getPlatos();
    ~Menu();
};