#include "MenuPlato.h"

MenuPlato::MenuPlato(Plato *plato, int cantidad){
    this->plato = plato;
    this->cantidad = cantidad;
}

Plato* MenuPlato::getPlato(){
    return this->plato;
}


int MenuPlato::getCantidad(){
    return this->cantidad;
}

void MenuPlato::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

MenuPlato::~MenuPlato(){
    cout << "Destruyendo MenuPlato con Plato '" << this->getPlato()->getCodigo() << "' (x" << this->getCantidad() <<")" << endl;
}