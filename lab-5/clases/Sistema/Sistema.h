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

    // ####### --------------- INICIO CASO DE USO INICIAR VENTA --------------- #######
    ICollection *mesasElegidas;
    

    // ####### --------------- Alta empleaado --------------- #######
    Transporte transporteSeleccionado;
    string nombreEmpleado;
    string tipoEmpleado;

public:
    // ###### --------------- Alta producto ---------------  #######
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
    ICollection *obtenerPlatos();

    /**
     * @brief Añade un plato a un menu.
     * @param codigo --> Codigo del plato a añadir.
     * @param cantidad --> Cantidad de platos a añadir al menu.
     * @note El sistema ya guarda en una variable el menu al que se le añadira el plato.
     */
    void anadirPlatoAMenu(char *, int);

    /**
     * @brief Crea el producto y lo guarda en el sistema.
     */
    void darAltaProducto();

    /**
     * @brief Cancela la creacion del producto.
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
     * @param codigo --> El codigo del producto a seleccionar
     */
    // void seleccionarProducto(int);

    /**
     * @brief Elimina el producto seleccionado del sistema.
     * @note Solo borrara al producto si todas las ventas que lo contienen estan facturadas.
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

    // ###### --------------- Alta Empleado ---------------  #######

    /**
     * @brief Agrega un empleado al sistema.
     * @param string --> Nombre del empleado.
     * @param string --> Tipo de empleado (Mozo o Repartidor).
     */
    void agregarEmpleado(string, string);

    /**
     * @brief Selecciona el transporte del repartidor.
     * @param Transporte --> Tipo de transporte (aPie, Moto, Bicicleta, Auto).
     */
    void seleccionarTransporte(Transporte);

    /**
     * @brief Crea un empleado y lo guarda en el sistema.
     * @return int --> Número del empleado creado.
     */
    int darDeAltaEmpleado();

    /**
     * @brief Cancela la creación del empleado.
     */
    void cancelarAltaEmpleado();

    // ####### --------------- INICIO CASO DE USO INICIAR VENTA --------------- #######
    /**
     * @brief El empleado inicia la venta.
     * @param identificador --> ID del empleado.
     */

    void iniciarVenta(string);
    void darAltaVenta();
    void cancelarAltaVenta();
    void addMesaElegida();
    ICollection *getMesasElegidas();
    void mostrarMesasElegidas(bool); //True para ver qué mesas están seleccionadas, false para ver solo números de dichas mesas.

    // ####### --------------- FIN CASO DE USO INICIAR VENTA --------------- #######
    // ###### --------------- Utils ---------------  #######
    /**
     * @brief Pobla todo el sistema
     * @return Sistema* --> El objeto unico de la clase Sistema.
     */
    void poblarSistema();

    /**
     * @brief Retorna el numero de productos del sistema.
     * @return int --> Cantidad de productos.
     */
    int getCantidadProductos();

    /**
     * @brief Retorna las facturaciones del sistema en una fecha dada.
     * @param DtFecha --> Fecha a consultar.
     */
    DtInforme consultarFacturacion(DtFecha);

    DtInfoProducto *obtenerProducto(string codigo);

    void listarEmpleados();
    void listarVentas();
    void listarMesasConVentasEnCurso();
    void listarMesas();
    void listarProductos();
    void imprimirFacturaLocal(DtFacturaLocal);
    void imprimirFacturaDomicilio(DtFacturaDomicilio);
    void imprimirInforme(DtInforme);
    void listarProductoTemporal();
    void listarTransportes();

    static Sistema *getInstance();
    ~Sistema();
};