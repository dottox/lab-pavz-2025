#pragma once

#include "ISistema.h"

using namespace std;

class Sistema : public ISistema
{
private:
    Sistema();
    static Sistema *instance;

    IDictionary *empleados;
    IDictionary *ventas;
    IDictionary *mesas;
    IDictionary *productos;

    // ###### --------------- Alta producto ---------------  #######
    TipoProducto tipoProductoSeleccionado;
    Producto *productoCreado;

    // ####### --------------- Agregar producto a una venta --------------- #######
    Mozo *mozoSeleccionado;
    Producto *prodctoSeleccionado;
    int cantidadProductoSeleccionado;

    // ###### --------------- Facturar venta ---------------  #######
    Mesa *mesaSeleccionada;
    Venta *ventaSeleccionada;

public:
    // ###### --------------- Alta producto ---------------  #######
    /**
     * @brief El sistema guarda temporalmente el tipo de producto a crear.
     * @param tipoProducto --> TipoProducto (Plato o Menu).
     */
    void seleccionarTipoProducto(TipoProducto);

    /**
     * @brief El empleado inicia la venta.
     * @param identificador --> ID del empleado.
     */
    ICollection *iniciarVenta(string);

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
    ICollection *obtenerPlatos();

    /**
     * @brief Añade un plato a un menu.
     * @param codigo --> Codigo del plato a añadir.
     * @param cantidad --> Cantidad de platos a añadir al menu.
     * @note El sistema ya guarda en una variable el menu al que se le añadirá el plato.
     */
    void anadirPlatoAMenu(char *, int);

    /**
     * @brief Crea el producto y lo guarda en el sistema.
     */
    void darAltaProducto();

    /**
     * @brief Cancela la creación del producto.
     */
    void cancelarAltaProducto();

    // ####### --------------- Alta producto --------------- #######

    // ###### --------------- Facturar venta ---------------  #######

    /**
     * @brief El sistema guarda temporalmente la mesa elegida.
     * @param int --> Codigo de mesa.
     */

    void elegirMesa(int);

    /**
     * @brief El sistema agrega el descuento a la venta.
     * @param int --> Porcentaje de descuento a aplicar.
     */

    void agregarPorcentaje(int);

    /**
     * @brief El sistema muestra la factura generada.
     * @return DtFacturaLocal --> Datos de la factura generada.
     */

    DtFacturaLocal generarFactura();

    // ###### --------------- Facturar venta ---------------  #######

    /**
     * @brief Retorna todos los productos del sistema.
     * @return ICollection* --> Set<DtProducto>.
     */
    // ICollection* mostrarProductos();

    /**
     * @brief El sistema guarda temporalmente el producto seleccionado.
     * @param codigo --> El código del producto a seleccionar
     */
    // void seleccionarProducto(int);

    /**
     * @brief Elimina el producto seleccionado del sistema.
     * @note Solo borrará al producto si todas las ventas que lo contienen están facturadas.
     */
    // void quitarProducto();

    /**
     * @brief Cancela la baja del producto.
     */
    // void cancelarProducto();

    // ####### --------------- Agregar producto a una venta --------------- #######
    void seleccionarMozo(int);
    // void elegirMesa(int); Ya hecho
    // void listarProductos(); Ya hecho
    void seleccionarProducto(char *);
    void agregarProductoAVenta();
    void cancelarAgregarProductoAVenta();

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

    /**
     * @brief Retorna las facturaciones del sistema en una fecha dada.
     * @param DtFecha --> Fecha a consultar.
     */
    DtInforme consultarFacturacion(DtFecha);

    void listarEmpleados();
    void listarVentas();
    void listarMesasConVentasEnCurso();
    void listarMesas();
    void listarProductos();
    void imprimirFacturaLocal(DtFacturaLocal);
    void imprimirFacturaDomicilio(DtFacturaDomicilio);
    void imprimirInforme(DtInforme);
    void listarProductoTemporal();

    static Sistema *getInstance();
    ~Sistema();
};