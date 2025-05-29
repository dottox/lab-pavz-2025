#include "./Empleado.h"
#include "../utils/funciones.cpp"

Empleado::Empleado(string nom){
    this->numero = generarNumeroEmpleado();
    this->nombre = nom;
}

int Empleado::getNumero(){
    return this->numero;
}

string Empleado::getNombre(){
    return this->nombre;
}

Empleado::~Empleado(){
    // Destructor vacio
    // No es necesario liberar memoria ya que no se usan punteros
    // y los atributos son de tipo primitivo o string.
}