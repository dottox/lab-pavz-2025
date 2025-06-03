#include "Repartidor.h"

Repartidor::Repartidor(string nombre, Transporte transporte) : Empleado(nombre){
    this->transporte = transporte;
};

Transporte Repartidor::getTransporte() const {
    return this->transporte;
}

ostream & operator<<(ostream &os, const Repartidor &repartidor) {
    os << "Repartidor: " << static_cast<const Empleado&>(repartidor); // Call base class operator<<
    os << ", Transporte: " << repartidor.getTransporte();
    return os;
}

Repartidor::~Repartidor(){
}