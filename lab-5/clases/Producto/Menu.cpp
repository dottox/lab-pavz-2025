#include "Menu.h"

Menu::Menu(DtMenu menu, Plato **platos) : Producto(menu.getProducto())
{
    this->platos = platos;
}

Plato **Menu::getPlatos()
{
    return this->platos;
}

Menu::~Menu()
{
    if (this->platos != NULL)
    {
        delete[] this->platos;
    }
}