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

    CHECK(productoVenta.getProducto()->getCodigo() == "P001");
    CHECK(productoVenta.getProducto()->getDescripcion() == "Ensalada César");
    CHECK(productoVenta.getCantidad() == 2);
    

}

TEST_CASE("ProductoVenta: Setters") {
    DtPlato dtPlato(const_cast<char*>("P002"), "Sopa de Mariscos", 200.0f);
    Plato plato(dtPlato);
    ProductoVenta productoVenta("Sopa de Mariscos", 1, plato.getPrecio(), &plato);

    productoVenta.setCantidad(3);
    CHECK(productoVenta.getCantidad() == 3);
    
}

TEST_CASE("ProductoVenta: Destructor") {
    DtPlato dtPlato(const_cast<char*>("P003"), "Pizza Margherita", 200.0f);
    Plato plato(dtPlato);
    ProductoVenta *productoVenta = new ProductoVenta("Pizza Margherita", 1, plato.getPrecio(), &plato);
    CHECK(productoVenta->getProducto()->getCodigo() == "P003");
    CHECK(productoVenta->getProducto()->getDescripcion() == "Pizza Margherita");
    CHECK(productoVenta->getCantidad() == 1);

    
    // Verificar que el destructor no cause fugas de memoria
    delete productoVenta;
}

TEST_CASE("ProductoVenta: Invalid DtPlato") {
    // Intentar crear un ProductoVenta con un plato inválido
    DtPlato dtPlatoInvalido(const_cast<char*>(""), "Taco", -50.0f);
    Plato platoInvalido(dtPlatoInvalido);
    
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, platoInvalido.getPrecio(), &platoInvalido), std::invalid_argument);
    
    // Intentar crear un ProductoVenta con cantidad negativa
    DtPlato dtPlatoValido(const_cast<char*>("P004"), "Taco", 50.0f);
    Plato platoValido(dtPlatoValido);
    
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", -1, platoValido.getPrecio(), &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 0, platoValido.getPrecio(), &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, -50.0f, &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, 0.0f, &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("", 1, platoValido.getPrecio(), &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, platoValido.getPrecio(), nullptr), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("", 0, 0.0f, nullptr), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("", 0, 0.0f, &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, platoValido.getPrecio(), nullptr), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("", 1, platoValido.getPrecio(), nullptr), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("Taco", 1, platoValido.getPrecio(), &platoValido), std::invalid_argument);
    CHECK_THROWS_AS(ProductoVenta productoVenta("", 1, platoValido.getPrecio(), &platoValido), std::invalid_argument);
}

