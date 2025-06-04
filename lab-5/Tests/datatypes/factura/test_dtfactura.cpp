#include "../../doctest.h"
#include "../../../datatypes/Factura/DtFactura.h"
#include "../../../datatypes/Consumido/DtConsumido.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include "../../../datatypes/Hora/DtHora.h"

#include <iostream>
using namespace std;

TEST_CASE("Test DtFactura - Constructor and Getters")
{
    DtConsumido * consumido = new DtConsumido("Pizza", 2, 15.50);
    DtConsumido  * consumido2 = new DtConsumido("Bebida", 1, 5.00);
    DtHora * hora = new DtHora(12, 30, 0);
    DtFecha * fecha = new DtFecha(1, 1, 2023);
    DtConsumido * productos[] = { consumido, consumido2, nullptr }; // Array de productos con un nullptr al final
    DtFactura * factura = new DtFactura(1, 1001, *fecha, *hora, productos, 20.50, 10, 30.00, 3.00);
    CHECK(factura->getCodigo() == 1);
    CHECK(factura->getCodigoVenta() == 1001);   
    CHECK(factura->getFecha().getDia() == 1);
    CHECK(factura->getFecha().getMes() == 1);
    CHECK(factura->getFecha().getAnio() == 2023);
    CHECK(factura->getHora().getHora() == 12);
    CHECK(factura->getHora().getMinuto() == 30);
    CHECK(factura->getHora().getSegundo() == 0);
    CHECK(factura->getProductos()[0]->getDescripcion() == "Pizza");
    CHECK(factura->getProductos()[0]->getCantidad() == 2);
    CHECK(factura->getProductos()[0]->getPrecio() == 15.50);
    CHECK(factura->getProductos()[1]->getDescripcion() == "Bebida");
    CHECK(factura->getProductos()[1]->getCantidad() == 1);
    CHECK(factura->getProductos()[1]->getPrecio() == 5.00);
    CHECK(factura->getSubtotal() == 20.50);
    CHECK(factura->getDescuento() == 10);
    CHECK(factura->getMontoTotal() == 30.00);
    CHECK(factura->getIvaTotal() == 3.00);

    
    
}