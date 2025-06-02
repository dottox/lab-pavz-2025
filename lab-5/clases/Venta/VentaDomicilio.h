#pragma once

#include <iostream>
#include "Venta.h"
#include "../../datatypes/Cliente/DtCliente.h"

using namespace std;

class VentaDomicilio : public Venta
{
private:
    DtCliente datosCliente;

public:
    VentaDomicilio(int, float, int, Producto **, int, DtCliente);
    ~VentaDomicilio();
};