#include "Plato.h"

Plato::Plato(DtPlato plato) : Producto(plato.clone()){
    
}

DtPlato* Plato::getInfo() {
    return new DtPlato(this->getCodigo(), this->getDescripcion(), this->getPrecio());
}

ostream& operator<<(ostream& os, const Plato& plato) {
    os << static_cast<const Producto&>(plato);
    return os;
}

Plato::~Plato() {};