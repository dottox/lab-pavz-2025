#pragma once

#include <iostream>

#include "../Empleado/Empleado.h"
#include "../Empleado/Repartidor.h"
#include "../Empleado/Mozo.h"

#include "../Mesa/Mesa.h"

#include "../Producto/Producto.h"
#include "../Producto/Menu.h"
#include "../Producto/Plato.h"
#include "../Venta/Venta.h"
#include "../Venta/VentaLocal.h"
#include "../Venta/VentaDomicilio.h"

#include "../../datatypes/Factura/DtFacturaLocal.h"
#include "../../datatypes/Producto/DtPlato.h"
#include "../../datatypes/Producto/DtMenu.h"
#include "../../datatypes/Informe/DtInforme.h"

#include "../../enums/TipoProducto.h"
#include "../../enums/ActorMenu.h"

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../ICollection/interfaces/IKey.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"

using namespace std;

class ISistema
{
public:
    ~ISistema();

    // ###### --------------- Alta producto ---------------  #######
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
    virtual ICollection *obtenerPlatos() = 0;

    /**
     * @brief Añade un plato a un menu.
     * @param codigo --> Codigo del plato a añadir.
     * @param cantidad --> Cantidad de platos a añadir al menu.
     * @note El sistema ya guarda en una variable el menu al que se le añadirá el plato.
     */
    virtual void anadirPlatoAMenu(char *, int) = 0;

    /**
     * @brief Crea el producto y lo guarda en el sistema.
     */
    virtual void darAltaProducto() = 0;

    /**
     * @brief Cancela la creación del producto.
     */
    virtual void cancelarAltaProducto() = 0;

    // ####### --------------- Alta producto --------------- #######

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

    // ###### --------------- Facturar venta ---------------  #######

    /**
     * @brief El sistema guarda temporalmente la mesa elegida.
     * @param int --> Codigo de mesa.
     */

    virtual void elegirMesa(int) = 0;

    /**
     * @brief El sistema agrega el descuento a la venta.
     * @param int --> Porcentaje de descuento a aplicar.
     */

    virtual void agregarPorcentaje(int) = 0;

    /**
     * @brief El sistema muestra la factura generada.
     * @return DtFacturaLocal --> Datos de la factura generada.
     */

    virtual DtFacturaLocal generarFactura() = 0;

    // ###### --------------- Facturar venta ---------------  #######

    // ####### --------------- Agregar producto a una venta --------------- #######

    virtual void seleccionarMozo(int) = 0;
    // virtual void elegirMesa(int) = 0; Ya hecho
    // void listarProductos(); Ya hecho
    virtual void seleccionarProducto(char *) = 0;
    virtual void agregarProductoAVenta() = 0;
    virtual void cancelarAgregarProductoAVenta() = 0;

    // ###### --------------- Alta Empleado ---------------  #######

    /**
     * @brief Agrega un empleado al sistema.
     * @param string --> Nombre del empleado.
     * @param string --> Tipo de empleado (Mozo o Repartidor).
     */
    virtual void agregarEmpleado(string, string) = 0;

    /**
     * @brief Selecciona el transporte del repartidor.
     * @param Transporte --> Tipo de transporte (aPie, Moto, Bicicleta, Auto).
     */
    virtual void seleccionarTransporte(Transporte) = 0;

    /**
     * @brief Crea un empleado y lo guarda en el sistema.
     * @return int --> Número del empleado creado.
     */
    virtual int darDeAltaEmpleado() = 0;

    /**
     * @brief Cancela la creación del empleado.
     */
    virtual void cancelarAltaEmpleado() = 0;

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

    /**
     * @brief Retorna las facturaciones del sistema en una fecha dada.
     * @param DtFecha --> Fecha a consultar.
     */
    virtual DtInforme consultarFacturacion(DtFecha) = 0;

    virtual void listarEmpleados() = 0;
    virtual void listarVentas() = 0;
    virtual void listarMesas() = 0;
    virtual void listarProductos() = 0;
    virtual void listarProductoTemporal() = 0;
    virtual void listarMesasConVentasEnCurso() = 0;
    virtual void listarTransportes() = 0;
    virtual void imprimirFacturaLocal(DtFacturaLocal) = 0;
    virtual void imprimirFacturaDomicilio(DtFacturaDomicilio) = 0;
    virtual void imprimirInforme(DtInforme) = 0;
};