#include "Repartidor.h"

Repartidor::Repartidor(string nombre, Transporte transporte) : Empleado(nombre){
    this->transporte = transporte;
};

Repartidor::~Repartidor(){
    delete this; // Destructor implementation
}