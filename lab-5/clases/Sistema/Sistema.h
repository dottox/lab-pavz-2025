#pragma once

#include <iostream>
#include "ISistema.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../Empleado/Mozo.h"
#include "../Venta/Venta.h"
#include "../Mesa/Mesa.h"
#include "../Producto/Producto.h"

using namespace std;

class Sistema : public ISistema {
    private:
        Sistema();
        static Sistema * instance;
        IDictionary * empleados;
        IDictionary * ventas;
        IDictionary * mezas;
        IDictionary * productos;
    public:
        ~Sistema();
        static Sistema * getInstance();
        void saludar();
};