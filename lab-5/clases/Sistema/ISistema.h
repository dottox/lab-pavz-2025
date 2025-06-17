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

#include "../Cliente/Cliente.h"

#include "../../datatypes/Factura/DtFacturaLocal.h"
#include "../../datatypes/Producto/DtPlato.h"
#include "../../datatypes/Producto/DtMenu.h"
#include "../../datatypes/Informe/DtInforme.h"
#include "../../datatypes/InfoProducto/DtInfoProducto.h"
#include "../../datatypes/Asignacion/DtAsignacion.h"
#include "../../datatypes/Fecha/DtFecha.h"
#include "../../datatypes/Direccion/DtDireccion.h"
#include "../../datatypes/Direccion/DtDireccionCasa.h"
#include "../../datatypes/Direccion/DtDireccionApto.h"

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
     * @brief Anade un plato a un menu.
     * @param codigo --> Codigo del plato a anadir.
     * @param cantidad --> Cantidad de platos a anadir al menu.
     * @note El sistema ya guarda en una variable el menu al que se le anadira el plato.
     */
    virtual void anadirPlatoAMenu(char *, int) = 0;

    /**
     * @brief Crea el producto y lo guarda en el sistema.
     */
    virtual void darAltaProducto() = 0;

    /**
     * @brief Cancela la creacion del producto.
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
     * @param codigo --> El codigo del producto a seleccionar
     */
    // virtual void seleccionarProducto(int) = 0;

    /**
     * @brief Elimina el producto seleccionado del sistema.
     * @note Solo borrara al producto si todas las ventas que lo contienen estan facturadas.
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
    virtual void seleccionarProducto(string) = 0;
    virtual void agregarProductoAVenta() = 0;
    virtual int getCantidadProductoSeleccionado() = 0;
    virtual void setCantidadProductoSeleccionado(int) = 0;
    virtual void cancelarAgregarProductoAVenta() = 0;

    // ####### --------------- Quitar productos de venta --------------- #######

    virtual void quitarProductoVenta(int) = 0;
    virtual void cancelarQuitarProductoVenta() = 0;
    virtual void verificarMesaSeleccionadaConVentaEnCurso() = 0;
    virtual void listarProductosVentaSeleccionada() = 0;
    virtual void seleccionarProductoDeVenta(string) = 0;
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

    // ####### --------------- INICIO CASO DE USO INICIAR VENTA  --------------- #######
    /**
     * @brief El empleado inicia la venta.
     * @param identificador --> ID del empleado.
     */
    virtual void iniciarVenta(std::string) = 0;
    virtual void darAltaVenta() = 0;
    virtual void cancelarAltaVenta() = 0;
    // ###### --------------- FIN CASO DE USO INICIO VENTA  --------------- #######
    // ####### --------------- INICIO CASO DE USO BUSCAR INFO PRODUCTO --------------- #######
    /**
     * @brief Retorna un producto del sistema.
     * @param codigo --> Codigo del producto a buscar.
     * @return DtInfoProducto* --> Datos del producto buscado.
     */
    virtual DtInfoProducto *obtenerProducto(string) = 0;
    // ####### --------------- FIN CASO DE USO BUSCAR INFO PRODUCTO --------------- #######
    // ###### --------------- Utils ---------------  #######
    /**
     * @brief Pobla todo el sistema
     * @return Sistema* --> El objeto unico de la clase Sistema.
     */
    virtual void poblarSistema() = 0;

    /**
     * @brief Retorna el numero de productos del sistema.
     * @return int --> Cantidad de productos.
     */
    virtual int getCantidadProductos() = 0;

    /**
     * @brief Retorna las facturaciones del sistema en una fecha dada.
     * @param DtFecha --> Fecha a consultar.
     */
    virtual DtInforme consultarFacturacion(DtFecha) = 0;

    // ####### --------------- INICIO CASO DE USO VENTAS MOZO --------------- #######

    /**
     * @brief Muestra las ventas de un mozo en un rango de fechas.
     * @param DtFecha --> Fecha de inicio.
     * @param DtFecha --> Fecha de fin.
     */
    virtual void mostrarVentasMozo(DtFecha, DtFecha) = 0;

    // ####### --------------- INICIO CASO DE USO VENTAS MOZO --------------- #######

    // ####### --------------- INICIO CASO DE USO ASIGNAR MESAS MOZO --------------- #######

    /**
     * @brief El sistema asigna mesas a un mozo.
     * @param int --> Numero del mozo.
     * @param int --> Numero de mesas a asignar.
     */
    virtual bool hayVentasEnCurso() = 0;
    virtual void asignarMesasMozos(int, int) = 0;

    /// ####### --------------- FIN CASO DE USO ASIGNAR MESAS MOZO --------------- #######

    // ####### --------------- INICIO CASO DE USO VENTA DOMICILIO --------------- #######

    virtual bool existeCliente(string) = 0;

    virtual void seleccionarCliente(string) = 0;

    virtual void ventaDomicilio() = 0;

    virtual void seleccionarProductoDomicilio(string, int) = 0;

    virtual void seleccionarRepartidor(int) = 0;

    virtual DtFacturaDomicilio generarFacturaDomicilio() = 0;

    virtual void cancelarVentaDomicilio() = 0;

    /// ####### --------------- FIN CASO DE USO ASIGNAR VENTA DOMICILIO --------------- #######

    virtual void addMesaElegida() = 0;
    virtual ICollection *getMesasElegidas() = 0;
    virtual void mostrarMesasElegidas(bool) = 0;
    virtual void listarEmpleados() = 0;
    virtual void listarMozos() = 0;
    virtual void listarRepartidores() = 0;
    virtual void listarVentas() = 0;
    virtual void listarMesas() = 0;
    virtual void listarProductos() = 0;
    virtual void listarProductoTemporal() = 0;
    virtual void listarMesasConVentasEnCurso() = 0;
    virtual void listarTransportes() = 0;
    virtual void imprimirFacturaLocal(DtFacturaLocal) = 0;
    virtual void imprimirFacturaDomicilio(DtFacturaDomicilio) = 0;
    virtual void imprimirInforme(DtInforme) = 0;
    virtual bool validarFecha(string) = 0;
    virtual void agregarCliente(string, string, DtDireccion) = 0;
    virtual void mostrarClienteTemporal() = 0;
    virtual void darAltaCliente() = 0;
    virtual void cancelarAltaCliente() = 0;
    virtual void quitarProductoDelSistema(string) = 0;
    virtual void mostrarProductoSeleccionado() = 0;
    virtual void cancelarBajaProducto() = 0;
    virtual void resetInstance() = 0;
};