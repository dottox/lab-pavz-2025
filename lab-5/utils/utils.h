#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include "../datatypes/Fecha/DtFecha.h"
#include "../datatypes/Hora/DtHora.h"

class utils
{
private:
    utils() = default; // Constructor privado para evitar instanciación

public:
    static int generarNumeroEmpleado();
    static int generarNumeroFactura();
    static int generarNumeroMesa();
    static int generarNumeroVenta();
    static DtFecha obtenerFechaActual();
    static DtHora obtenerHoraActual();
};