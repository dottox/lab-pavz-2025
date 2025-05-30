#include "Mesa.h"
#include "../../utils/funciones.cpp" 

Mesa::Mesa(Mozo* mozo){
    this->numero = generarNumeroMesa();
    this->mozo = mozo;
    this->ventaEnCurso = NULL;
}

int Mesa::getNumero(){
    return this->numero;
}

Mozo *Mesa::getMozo(){
    return this->mozo;
}

VentaLocal *Mesa::getVentaEnCurso(){
    return this->ventaEnCurso;
}

void Mesa::setNumero(int numero){
    this->numero = numero;
}
void Mesa::setMozo(Mozo* mozo){
    this->mozo = mozo;
}
void Mesa::setVentaEnCurso(VentaLocal* venta){
    this->ventaEnCurso = venta; 
}

Mesa::~Mesa(){
    // Destructor logic if needed, currently does nothing
}