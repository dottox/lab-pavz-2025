#include "../../doctest.h"
#include "../../../clases/ProductoVenta/ProductoVenta.h"
#include "../../../clases/Producto/Menu.h"
#include "../../../clases/Producto/Plato.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../datatypes/Producto/DtMenu.h"
#include "../../../datatypes/Producto/DtPlato.h"
#include "../../../enums/TipoProducto.h"
#include "../../../ICollection/interfaces/ICollectible.h"
#include "../../../ICollection/collections/OrderedDictionary.h"
#include "../../../ICollection/interfaces/IKey.h"
#include <iostream>
using namespace std;

TEST_CASE("ProductoVenta: Constructor y getters") {
    DtPlato dtPlato(const_cast<char*>("P001"), "Ensalada César", 150.0f);
    Plato plato(dtPlato);
    ProductoVenta productoVenta("Ensalada César", 2, plato.getPrecio(), &plato);

    CHECK(std::string(productoVenta.getProducto()->getCodigo()) == "P001");
    CHECK(std::string(productoVenta.getProducto()->getDescripcion()) == "Ensalada César");
    CHECK(productoVenta.getCantidad() == 2);
    

}

TEST_CASE("ProductoVenta: Setters") {
    DtPlato dtPlato(const_cast<char*>("P002"), "Sopa de Mariscos", 200.0f);
    Plato plato(dtPlato);
    ProductoVenta productoVenta("Sopa de Mariscos", 1, plato.getPrecio(), &plato);

    productoVenta.setCantidad(3);
    CHECK(productoVenta.getCantidad() == 3);
    
}
