#pragma once


#include <iostream>
#include "ISistema.h"

#include "../Empleado/Mozo.h"
#include "../Empleado/Repartidor.h"
#include "../Mesa/Mesa.h"
#include "../Producto/Producto.h"
#include "../Producto/Menu.h"
#include "../Producto/Plato.h"

#include "../Venta/Venta.h"
#include "../Venta/VentaLocal.h"
#include "../Venta/VentaDomicilio.h"

#include "../../datatypes/Producto/DtPlato.h"
#include "../../datatypes/Producto/DtMenu.h"

#include "../../enums/TipoProducto.h"

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/ICollection.h"

#include <iostream>
using namespace std;

class ISistema {
    public:
        virtual void saludar() = 0;
        ~ISistema();


        // ###### --------------- Baja producto ---------------  #######
        /**
         * @brief El sistema guarda temporalmente el tipo de producto a crear.
         * @param tipoProducto --> TipoProducto (Plato o Menu).
         */
        virtual void seleccionarTipoProducto(TipoProducto) = 0;

        /**
         * @brief Crea un menu y lo guarda temporalmente en una variable del sistema.
         * @param DtMenu --> Datos del menu a crear.
         */
        virtual void crearMenu(DtMenu) = 0;

        /**
         * @brief Crea un plato y lo guarda temporalmente en una variable del sistema.
         * @param DtPlato --> Datos del plato a crear.
         */
        virtual void crearPlato(DtPlato) = 0;

        /**
         * @brief Lista todos los platos del sistema
         * @return ICollection* --> Set<DtPlato>.
         */
        virtual ICollection* obtenerPlatos() = 0;

        /**
         * @brief Añade un plato a un menu.
         * @param codigo --> Codigo del plato a añadir.
         * @param cantidad --> Cantidad de platos a añadir al menu.
         * @note El sistema ya guarda en una variable el menu al que se le añadirá el plato.
         */
        virtual void añadirPlatoAMenu(char*, int) = 0;

        /**
         * @brief Crea el producto y lo guarda en el sistema.
         */
        virtual void darAltaProducto() = 0;

        /**
         * @brief Cancela la creación del producto.
         */
        virtual void cancelarAltaProducto() = 0;


        // ####### --------------- Baja producto --------------- #######
        /**
         * @brief Retorna todos los productos del sistema.
         * @return ICollection* --> Set<DtProducto>.
         */
        // virtual ICollection* mostrarProductos() = 0;

        /**
         * @brief El sistema guarda temporalmente el producto seleccionado.
         * @param codigo --> El código del producto a seleccionar
         */
        // virtual void seleccionarProducto(int) = 0;

        /**
         * @brief Elimina el producto seleccionado del sistema.
         * @note Solo borrará al producto si todas las ventas que lo contienen están facturadas.
         */
        // virtual void quitarProducto() = 0;

        /**
         * @brief Cancela la baja del producto.
         */
        // virtual void cancelarProducto() = 0;

        // ####### --------------- Agregar producto a una venta --------------- #######
        virtual void seleccionarMozo(int) = 0;
        virtual void elegirMesa(int) = 0;
        // void listarProductos(); Ya hecho
        virtual void seleccionarProducto(char*) = 0;
        virtual void agregarProductoAVenta() = 0;
        virtual void cancelarAgregarProductoAVenta() = 0;


        // ###### --------------- Utils ---------------  #######
        /**
         * @brief Pobla todo el sistema
         * @return Sistema* --> El objeto único de la clase Sistema.
         */
        virtual void poblarSistema() = 0;

        /**
         * @brief Retorna el número de productos del sistema.
         * @return int --> Cantidad de productos.
         */
        virtual int getCantidadProductos() = 0; 

        virtual void listarEmpleados() = 0;
        virtual void listarVentas() = 0;
        virtual void listarMesas() = 0;
        virtual void listarProductos() = 0;
        virtual void listarProductoTemporal() = 0;
};