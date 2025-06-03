#include "Plato.h"

Plato::Plato(DtPlato plato) : Producto(plato.getProducto()){
    
}

DtPlato* Plato::getInfo() {
    return new DtPlato(this->getCodigo(), this->getDescripcion(), this->getTipo());
}

ostream& operator<<(ostream& os, const Plato& plato) {
    os << static_cast<const Producto&>(plato);
    return os;
}

Plato::~Plato() {};