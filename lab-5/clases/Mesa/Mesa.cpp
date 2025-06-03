#include "Mesa.h"
#include "../../utils/utils.h" 

Mesa::Mesa(Mozo* mozo){
    this->numero = utils::generarNumeroMesa();
    this->mozo = mozo;
    this->ventaEnCurso = NULL;
}

int Mesa::getNumero(){
    return this->numero;
}

Mozo *Mesa::getMozo(){
    return this->mozo;
}

VentaLocal *Mesa::getVentaEnCurso() const {
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

ostream & operator<<(ostream &os, const Mesa &mesa) {
    os << "Mesa Numero: " << mesa.numero << endl
       << "    " << "Mozo: " << *(mesa.mozo);
    if (mesa.getVentaEnCurso() != NULL) {
        os << ", Hay venta en curso";
    } else {
        os << ", No hay venta en curso";
    }
    return os;
}

Mesa::~Mesa(){
    // Destructor logic if needed, currently does nothing
}