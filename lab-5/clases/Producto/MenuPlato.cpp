#include "MenuPlato.h"

MenuPlato::MenuPlato(Plato *plato, Menu *menu, int cantidad)
{
    this->plato = plato;
    this->menu = menu;
    this->cantidad = cantidad;
}

Plato *MenuPlato::getPlato()
{
    return this->plato;
}

Menu *MenuPlato::getMenu()
{
    return this->menu;
}

int MenuPlato::getCantidad()
{
    return this->cantidad;
}

void MenuPlato::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

MenuPlato::~MenuPlato()
{
    // No need to delete plato and menu, as they are managed by their respective classes
    // If they were dynamically allocated, we would need to delete them here
    // delete plato;
    // delete menu;
}