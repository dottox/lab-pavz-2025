#pragma once

#include <iostream>
#include "ISistema.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../Empleado/Mozo.h"
#include "../Venta/Venta.h"
#include "../Mesa/Mesa.h"
#include "../Producto/Producto.h"

#include "../../datatypes/Producto/DtPlato.h"
#include "../../datatypes/Producto/DtMenu.h"

#include "../../enums/TipoProducto.h"

using namespace std;

class Sistema : public ISistema {
    private:
        Sistema();
        static Sistema * instance;
        IDictionary * empleados;
        IDictionary * ventas;
        IDictionary * mesas;
        IDictionary * productos;
    public:

        void seleccionarTipoProducto(TipoProducto tipo);
        void crearMenu(DtMenu datosMenu);
        void crearPlato(DtPlato datosPlato);

        static Sistema * getInstance();
        void saludar();
        ~Sistema();
};