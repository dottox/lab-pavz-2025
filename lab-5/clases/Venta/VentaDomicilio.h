#pragma once

#include <iostream>
#include "Venta.h"
#include "../../datatypes/Cliente/DtCliente.h"

#include "../../ICollection/interfaces/ICollection.h"

using namespace std;

class VentaDomicilio : public Venta
{
private:
    DtCliente datosCliente;

public:
    VentaDomicilio(DtCliente);
    DtCliente getDatosCliente();
    friend ostream& operator<<(ostream&, const VentaDomicilio&);
    ~VentaDomicilio();
};