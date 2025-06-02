#include "dtMesa.h"

dtMesa::dtMesa(Venta* ventaActual, bool ventaEnCurso) {
    this->numero = -1; // Default value 
    this->ventaActual = ventaActual;
    this->ventaEnCurso = ventaEnCurso;
}

dtMesa::dtMesa(int numero, Venta* ventaActual, bool ventaEnCurso) {
    this->numero = numero;
    this->ventaActual = ventaActual;
    this->ventaEnCurso = ventaEnCurso;
}

int dtMesa::getNumero() {
    return this->numero;
}
Venta* dtMesa::getVentaActual() {
    return this->ventaActual;
}
bool dtMesa::getVentaEnCurso() {
    return this->ventaEnCurso;
}
dtMesa::~dtMesa() {

}