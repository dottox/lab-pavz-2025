#include "Mozo.h"

Mozo::Mozo(string nombre) : Empleado(nombre){
    mesasAsignadas = NULL;
    cantidadMesasAsignadas = 0;
}

Mozo::~Mozo(){
    // Destructor implementation
}