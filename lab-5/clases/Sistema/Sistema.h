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

using namespace std;

class Sistema : public ISistema {
    private:
        Sistema();
        static Sistema* instance;

        IDictionary* empleados;
        IDictionary* ventas;
        IDictionary* mesas;
        IDictionary* productos;

        // ###### --------------- Baja producto ---------------  #######
        TipoProducto tipoProductoSeleccionado;
        Producto* productoCreado;

    public:

        // ###### --------------- Baja producto ---------------  #######
        /**
         * @brief El sistema guarda temporalmente el tipo de producto a crear.
         * @param tipoProducto --> TipoProducto (Plato o Menu).
         */
        void seleccionarTipoProducto(TipoProducto);

        /**
         * @brief Crea un menu y lo guarda temporalmente en una variable del sistema.
         * @param DtMenu --> Datos del menu a crear.
         */
        void crearMenu(DtMenu);

        /**
         * @brief Crea un plato y lo guarda temporalmente en una variable del sistema.
         * @param DtPlato --> Datos del plato a crear.
         */
        void crearPlato(DtPlato);

        /**
         * @brief Lista todos los platos del sistema
         * @return ICollection* --> Set<DtPlato>.
         */
        ICollection* listarPlatos();

        /**
         * @brief Añade un plato a un menu.
         * @param codigo --> Codigo del plato a añadir.
         * @param cantidad --> Cantidad de platos a añadir al menu.
         * @note El sistema ya guarda en una variable el menu al que se le añadirá el plato.
         */
        void añadirPlatoAMenu(char*, int);

        /**
         * @brief Crea el producto y lo guarda en el sistema.
         */
        void darAltaProducto();

        /**
         * @brief Cancela la creación del producto.
         */
        void cancelarAltaProducto();


        // ####### --------------- Baja producto --------------- #######
        /**
         * @brief Retorna todos los productos del sistema.
         * @return ICollection* --> Set<DtProducto>.
         */
        //ICollection* mostrarProductos();

        /**
         * @brief El sistema guarda temporalmente el producto seleccionado.
         * @param codigo --> El código del producto a seleccionar
         */
        //void seleccionarProducto(int);

        /**
         * @brief Elimina el producto seleccionado del sistema.
         * @note Solo borrará al producto si todas las ventas que lo contienen están facturadas.
         */
        //void quitarProducto();

        /**
         * @brief Cancela la baja del producto.
         */
        //void cancelarProducto();


        // ###### --------------- Utils ---------------  #######
        /**
         * @brief Pobla todo el sistema
         * @return Sistema* --> El objeto único de la clase Sistema.
         */
        void poblarSistema();

        /**
         * @brief Retorna el número de productos del sistema.
         * @return int --> Cantidad de productos.
         */
        int getCantidadProductos();

        void listarEmpleados();
        void listarVentas();
        void listarMesas();
        void listarProductos();


        static Sistema * getInstance();
        void saludar();
        ~Sistema();
};