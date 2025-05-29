#pragma once

#include <iostream>
#include "Venta.h"

using namespace std;

class VentaLocal : public Venta
{
public:
    VentaLocal(int, float, int, Producto **, int);
    ~VentaLocal();
};