
#include "utils.h"
#include <iostream>

int utils::generarNumeroEmpleado() {
    static int contadorEmpleado = 0; // Variable estática para mantener el estado entre llamadas
    contadorEmpleado++;
    return contadorEmpleado;
}

int utils::generarNumeroFactura() {
    static int contadorFactura = 0; // Variable estática para mantener el estado entre llamadas
    contadorFactura++;
    return contadorFactura;
}

int utils::generarNumeroProducto() {
    static int contadorProducto = 0; // Variable estática para mantener el estado entre llamadas
    contadorProducto++;
    return contadorProducto;
}

int utils::generarNumeroMesa() {
    static int contadorMesa = 0; // Variable estática para mantener el estado entre llamadas
    contadorMesa++;
    return contadorMesa;
}