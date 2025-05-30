#pragma once

#include <iostream>
#include "Venta.h"
#include "../../datatypes/Cliente/dtCliente.h"

using namespace std;

class VentaDomicilio : public Venta
{
private:
    dtCliente datosCliente;

public:
    VentaDomicilio(int, float, int, Producto **, int, dtCliente);
    ~VentaDomicilio();
};