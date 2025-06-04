#include "../../doctest.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../enums/TipoProducto.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtProducto - Constructor and Getters")
{
    // Create a DtProducto object
    DtProducto producto((char*)"P001", "Pizza grande", TipoProducto::TipoPlato, 15.50f);
    CHECK(string(producto.getCodigo()) == "P001");
    CHECK(producto.getDescripcion() == "Pizza grande");
    CHECK(producto.getTipo() == TipoProducto::TipoPlato);
    CHECK(producto.getPrecio() == 15.50f);

    DtProducto producto2((char*)"M001", "Menu del dia", TipoProducto::TipoMenu, 25.00f);
    CHECK(string(producto2.getCodigo()) == "M001");
    CHECK(producto2.getDescripcion() == "Menu del dia");
    CHECK(producto2.getTipo() == TipoProducto::TipoMenu);
    CHECK(producto2.getPrecio() == 25.00f);

    
}
