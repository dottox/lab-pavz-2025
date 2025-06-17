#pragma once

#include <iostream>
#include "../Producto/Producto.h"
#include "../Producto/Plato.h"
#include "../Producto/Menu.h"
#include "../Producto/Plato.h"
#include "../Producto/Menu.h"
#include "../Factura/Factura.h"
#include "../Factura/FacturaLocal.h"
#include "../Factura/FacturaDomicilio.h"
#include "../ProductoVenta/ProductoVenta.h"

#include "../../datatypes/Factura/DtFactura.h"
#include "../../datatypes/Factura/DtFacturaLocal.h"
#include "../../datatypes/Factura/DtFacturaDomicilio.h"

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"
#include "../../ICollection/interfaces/IKey.h"
#include "../../utils/utils.h"

using namespace std;

class Venta : public ICollectible
{
private:
    int codigo;
    int descuento;
    int cantidadProductos;
    float subtotal;
    Factura *factura;
    IDictionary *productosConsumidos;

public:
    Venta();
    Venta(int, float, IDictionary *);
    int getCodigo();
    float getSubtotal();
    int getDescuento();
    IDictionary *getProductos(); // retornar una coleccion con los productosConsumidos
    int getCantidadProductos();
    bool estaFacturada();
    void setSubtotal(float);
    void agregarPorcentaje(int);
    void agregarProducto(Producto *, int);
    void quitarProductoVenta(Producto *, int);
    void quitarProductoVenta(char *);
    void actualizarPrecioVenta();
    bool contieneMenu();
    DtFacturaLocal generarFactura(string);
    DtFacturaLocal mostrarFacturaLocal();
    DtFacturaDomicilio generarFacturaDomicilio(string, Transporte);
    DtFacturaDomicilio mostrarFacturaDomicilio();
    bool contieneProducto(Producto *producto);
    Factura *getFactura();
    friend ostream &operator<<(ostream &os, const Venta &venta);
    virtual ~Venta();
};