#pragma once
#include <string>
#include "../../clases/Venta/Venta.h"

class DtMesa{
private:
    int numero;
    Venta *ventaActual;
    bool ventaEnCurso;
public:
    DtMesa(Venta*, bool);
    DtMesa(int, Venta*, bool);
    int getNumero();
    Venta *getVentaActual();
    bool getVentaEnCurso();
    ~DtMesa();
    
};
