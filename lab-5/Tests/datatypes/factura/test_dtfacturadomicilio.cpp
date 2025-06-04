#include "../../doctest.h"
#include "../../../datatypes/Factura/DtFactura.h"
#include "../../../datatypes/Factura/DtFacturaDomicilio.h"
#include "../../../datatypes/Consumido/DtConsumido.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include "../../../datatypes/Hora/DtHora.h"
#include "../../../enums/Transporte.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtFactura - Constructor and Getters")
{
    DtConsumido *consumido = new DtConsumido("Pizza", 2, 15.50);
    DtConsumido *consumido2 = new DtConsumido("Bebida", 1, 5.00);
    DtHora *hora = new DtHora(12, 30, 0);
    DtFecha *fecha = new DtFecha(1, 1, 2023);
    DtConsumido *productos[] = {consumido, consumido2, nullptr}; // Array de productos con un nullptr al final
    DtFacturaDomicilio *facturaDomicilio = new DtFacturaDomicilio(1001, *fecha, *hora, productos, 20.50, 10, 30.00, 3.00, "Juan Perez", Transporte::Moto);
    CHECK(facturaDomicilio->getCodigoVenta() == 1001);
    CHECK(facturaDomicilio->getFecha().getDia() == 1);
    CHECK(facturaDomicilio->getFecha().getMes() == 1);
    CHECK(facturaDomicilio->getFecha().getAnio() == 2023);
    CHECK(facturaDomicilio->getHora().getHora() == 12);
    CHECK(facturaDomicilio->getHora().getMinuto() == 30);
    CHECK(facturaDomicilio->getHora().getSegundo() == 0);
    CHECK(facturaDomicilio->getProductos()[0]->getDescripcion() == "Pizza");
    CHECK(facturaDomicilio->getProductos()[0]->getCantidad() == 2);
    CHECK(facturaDomicilio->getProductos()[0]->getPrecio() == 15.50);
    CHECK(facturaDomicilio->getProductos()[1]->getDescripcion() == "Bebida");
    CHECK(facturaDomicilio->getProductos()[1]->getCantidad() == 1);
    CHECK(facturaDomicilio->getProductos()[1]->getPrecio() == 5.00);
    CHECK(facturaDomicilio->getSubtotal() == 20.50);
    CHECK(facturaDomicilio->getDescuento() == 10);
    CHECK(facturaDomicilio->getMontoTotal() == 30.00);
    CHECK(facturaDomicilio->getIvaTotal() == 3.00);
    CHECK(facturaDomicilio->getNombreRepartidor() == "Juan Perez");
    CHECK(facturaDomicilio->getTransporte() == Transporte::Moto);
    // Imprimir la factura para verificar la salida
    cout << "Factura Domicilio: " << endl;
    cout << "Codigo Venta: " << facturaDomicilio->getCodigoVenta() << endl;
    cout << "Fecha: " << facturaDomicilio->getFecha().getDia() << "/"
         << facturaDomicilio->getFecha().getMes() << "/"
         << facturaDomicilio->getFecha().getAnio() << endl;
    cout << "Hora: " << facturaDomicilio->getHora().getHora() << ":"
         << facturaDomicilio->getHora().getMinuto() << ":"
         << facturaDomicilio->getHora().getSegundo() << endl;
    cout << "Productos: " << endl;
    for (int i = 0; facturaDomicilio->getProductos()[i] != nullptr; i++)
    {
        cout << " - " << facturaDomicilio->getProductos()[i]->getDescripcion()
             << ", Cantidad: " << facturaDomicilio->getProductos()[i]->getCantidad()
             << ", Precio: " << facturaDomicilio->getProductos()[i]->getPrecio() << endl;
    }
    cout << "Subtotal: " << facturaDomicilio->getSubtotal() << endl;
    cout << "Descuento: " << facturaDomicilio->getDescuento() << "%" << endl;
    cout << "Monto Total: " << facturaDomicilio->getMontoTotal() << endl;
    cout << "IVA Total: " << facturaDomicilio->getIvaTotal() << endl;
    cout << "Nombre Repartidor: " << facturaDomicilio->getNombreRepartidor() << endl;
    cout << "Transporte: " << (facturaDomicilio->getTransporte() == Transporte::Moto ? "Moto" : "Otro") << endl;
}