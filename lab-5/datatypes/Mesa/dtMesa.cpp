#include "DtMesa.h"

DtMesa::DtMesa(Venta* ventaActual, bool ventaEnCurso) {
    this->numero = -1; // Default value 
    this->ventaActual = ventaActual;
    this->ventaEnCurso = ventaEnCurso;
}

DtMesa::DtMesa(int numero, Venta* ventaActual, bool ventaEnCurso) {
    this->numero = numero;
    this->ventaActual = ventaActual;
    this->ventaEnCurso = ventaEnCurso;
}

int DtMesa::getNumero() {
    return this->numero;
}
Venta* DtMesa::getVentaActual() {
    return this->ventaActual;
}
bool DtMesa::getVentaEnCurso() {
    return this->ventaEnCurso;
}
DtMesa::~DtMesa() {

}