#include "Mozo.h"

Mozo::Mozo(string nombre) : Empleado(nombre){
    mesasAsignadas = NULL;
    cantidadMesasAsignadas = 0;
}

int Mozo::getCantidadMesasAsignadas() const {
    return this->cantidadMesasAsignadas;
}


ostream & operator<<(ostream &os, const Mozo &mozo) {
    os << "Mozo: " << static_cast<const Empleado&>(mozo); // Call base class operator<<
    os << ", Cantidad de Mesas Asignadas: " << mozo.getCantidadMesasAsignadas();
    return os;
}

Mozo::~Mozo(){
    // Destructor implementation
}