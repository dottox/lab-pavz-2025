#include <iostream>

int generarNumeroEmpleado() {
    static int contadorEmpleado = 0; // Variable estática para mantener el estado entre llamadas
    contadorEmpleado++;
    return contadorEmpleado;
}

int generarNumeroFactura() {
    static int contadorFactura = 0; // Variable estática para mantener el estado entre llamadas
    contadorFactura++;
    return contadorFactura;
}

int generarNumeroProducto() {
    static int contadorProducto = 0; // Variable estática para mantener el estado entre llamadas
    contadorProducto++;
    return contadorProducto;
}

int generarNumeroMesa() {
    static int contadorMesa = 0; // Variable estática para mantener el estado entre llamadas
    contadorMesa++;
    return contadorMesa;
}