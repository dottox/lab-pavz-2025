#include "../../doctest.h"
#include "../../../datatypes/Factura/DtFacturaLocal.h"
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

    DtFacturaLocal *facturaLocal = new DtFacturaLocal(
        1001, *fecha, *hora, productos, 20.50, 10, 30.00, 3.00, "Juan Perez");
    CHECK(facturaLocal->getCodigoVenta() == 1001);
    CHECK(facturaLocal->getFecha().getDia() == 1);
    CHECK(facturaLocal->getFecha().getMes() == 1);
    CHECK(facturaLocal->getFecha().getAnio() == 2023);
    CHECK(facturaLocal->getHora().getHora() == 12);
    CHECK(facturaLocal->getHora().getMinuto() == 30);
    CHECK(facturaLocal->getHora().getSegundo() == 0);
    CHECK(facturaLocal->getProductos()[0]->getDescripcion() == "Pizza");
    CHECK(facturaLocal->getProductos()[0]->getCantidad() == 2);
    CHECK(facturaLocal->getProductos()[0]->getPrecio() == 15.50);
    CHECK(facturaLocal->getProductos()[1]->getDescripcion() == "Bebida");
    CHECK(facturaLocal->getProductos()[1]->getCantidad() == 1);
    CHECK(facturaLocal->getProductos()[1]->getPrecio() == 5.00);
    CHECK(facturaLocal->getSubtotal() == 20.50);
    CHECK(facturaLocal->getDescuento() == 10);
    CHECK(facturaLocal->getMontoTotal() == 30.00);
    CHECK(facturaLocal->getIvaTotal() == 3.00);
    CHECK(facturaLocal->getNombreMozo() == "Juan Perez");
}
