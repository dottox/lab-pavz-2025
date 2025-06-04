#include "../../doctest.h"
#include "../../../datatypes/InfoProducto/DtInfoProducto.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../enums/TipoProducto.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtInfoProducto - Constructor and Getters")
{
    // Crear un objeto DtProducto simulado
    DtProducto producto((char *)"P001", "Pizza grande", TipoProducto::TipoPlato, 15.50f);
    // Crear un objeto DtInfoProducto con el producto simulado y cantidad de ventas
    DtInfoProducto *dtInfoProducto = new DtInfoProducto(producto, 10);

    // Verificar los valores de los atributos
    CHECK(string(producto.getCodigo()) == "P001");
    CHECK(producto.getDescripcion() == "Pizza grande");
    CHECK(producto.getTipo() == TipoProducto::TipoPlato);
    CHECK(producto.getPrecio() == 15.50f);
    CHECK(dtInfoProducto->getCantidadVentas() == 10);
    CHECK(dtInfoProducto->getProducto().getCodigo() == producto.getCodigo());
    CHECK(dtInfoProducto->getProducto().getDescripcion() == producto.getDescripcion());
    CHECK(dtInfoProducto->getProducto().getTipo() == producto.getTipo());
    CHECK(dtInfoProducto->getProducto().getPrecio() == producto.getPrecio());
    
}