#pragma once

#include <iostream>
#include "../Producto/Producto.h"
#include "../Factura/Factura.h"
#include "../Factura/FacturaLocal.h"
#include "../Factura/FacturaDomicilio.h"
#include "../ProductoVenta/ProductoVenta.h"

#include "../../datatypes/Factura/DtFactura.h"
#include "../../datatypes/Factura/DtFacturaLocal.h"
#include "../../datatypes/Factura/DtFacturaDomicilio.h"

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"

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
    int getCodigo();
    float getSubtotal();
    int getDescuento();
    // Producto **getProductos();
    int getCantidadProductos();
    bool estaFacturada();
    void setSubtotal(float);
    void agregarPorcentaje(int);
    void agregarProducto(Producto *, int);
    DtFacturaLocal generarFactura(string);
    DtFacturaLocal mostrarFacturaLocal();
    DtFacturaDomicilio mostrarFacturaDomicilio();
    bool contieneProducto(Producto *producto);
    Factura *getFactura();
    friend ostream &operator<<(ostream &os, const Venta &venta);
    virtual ~Venta();
};