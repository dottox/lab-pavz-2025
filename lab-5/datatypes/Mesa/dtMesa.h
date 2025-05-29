#ifndef MESA_H
#define MESA_H
#include <string>
#include "../clases/Venta/Venta.h"
class dtMesa{
private:
    int numero;
    Venta *ventaActual;
    bool ventaEnCurso;
public:
    dtMesa(int , Venta*, bool);
    int getNumero();
    Venta *getVentaActual();
    bool getVentaEnCurso();
    ~dtMesa();
    
};

#endif