#include "../../doctest.h"
#include "../../../clases/Producto/Producto.h"
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

TEST_CASE("Plato: Constructor y getters")
{
    DtPlato dtPlato(const_cast<char*>("P001"), "Ensalada César", 150.0f);
    Plato plato(dtPlato);

    CHECK(plato.getCodigo() == "P001");
    CHECK(plato.getDescripcion() == "Ensalada César");
    CHECK(plato.getPrecio() == doctest::Approx(150.0f));
    CHECK(plato.getTipo() == TipoProducto::TipoPlato);
}

TEST_CASE("Plato: Destructor")
{
    DtPlato dtPlato(const_cast<char*>("P003"), "Pizza Margherita", 200.0f);
    Plato* plato = new Plato(dtPlato);

    // Verificar que el destructor no cause fugas de memoria
    delete plato;
}

TEST_CASE("Plato: getInfo devuelve DtPlato correcto")
{
    DtPlato dtPlato(const_cast<char*>("P002"), "Sopa de Verduras", 100.0f);
    Plato plato(dtPlato);

    DtPlato* info = plato.getInfo();
    CHECK(info->getCodigo() == "P002");
    CHECK(info->getDescripcion() == "Sopa de Verduras");
    CHECK(info->getPrecio() == doctest::Approx(100.0f));
    CHECK(info->getTipo() == TipoProducto::TipoPlato);

    delete info; // Liberar memoria del DtPlato
}

TEST_CASE("Plato: Crear un plato con datos inválidos")
{
    // Intentar crear un plato con precio negativo
    CHECK_THROWS_AS(DtPlato dtPlato(const_cast<char*>("P004"), "Taco", -50.0f), std::invalid_argument);
    
    // Intentar crear un plato con código vacío
    CHECK_THROWS_AS(DtPlato dtPlato(const_cast<char*>(""), "Taco", 50.0f), std::invalid_argument);
    
    // Intentar crear un plato con descripción vacía
    CHECK_THROWS_AS(DtPlato dtPlato(const_cast<char*>("P005"), "", 50.0f), std::invalid_argument);
}
TEST_CASE("Plato: Invalid DtPlato")
{
    // Intentar crear un plato con un DtPlato inválido
    DtPlato dtPlatoInvalid(const_cast<char*>(""), "", -100.0f);
    CHECK_THROWS_AS(Plato plato(dtPlatoInvalid), std::invalid_argument);
}
TEST_CASE("Plato: Comparación de igualdad y desigualdad")
{
    DtPlato dtPlato1(const_cast<char*>("P010"), "Milanesa", 180.0f);
    DtPlato dtPlato2(const_cast<char*>("P011"), "Ravioles", 180.0f);
    Plato plato1(dtPlato1);
    Plato plato2(dtPlato2);

    CHECK(plato1.getCodigo() != plato2.getCodigo());
    CHECK(plato1.getDescripcion() != plato2.getDescripcion());
    CHECK(plato1.getPrecio() == doctest::Approx(plato2.getPrecio()));
}

TEST_CASE("Plato: Cambios en DtPlato original no afectan a Plato")
{
    DtPlato dtPlato(const_cast<char*>("P020"), "Hamburguesa", 120.0f);
    Plato plato(dtPlato);

    // Cambiar datos en dtPlato después de crear Plato
    // (asumiendo que DtPlato tiene setters, si no, omitir este test)
    // dtPlato.setDescripcion("Cambiado");
    // dtPlato.setPrecio(999.0f);

    CHECK(plato.getCodigo() == "P020");
    CHECK(plato.getDescripcion() == "Hamburguesa");
    CHECK(plato.getPrecio() == doctest::Approx(120.0f));
}

TEST_CASE("Plato: getTipo siempre retorna TipoPlato")
{
    DtPlato dtPlato(const_cast<char*>("P030"), "Tarta", 90.0f);
    Plato plato(dtPlato);

    CHECK(plato.getTipo() == TipoProducto::TipoPlato);
}

TEST_CASE("Plato: getInfo retorna copia independiente")
{
    DtPlato dtPlato(const_cast<char*>("P040"), "Paella", 250.0f);
    Plato plato(dtPlato);

    DtPlato* info1 = plato.getInfo();
    DtPlato* info2 = plato.getInfo();

    CHECK(info1 != info2);
    CHECK(info1->getCodigo() == info2->getCodigo());
    CHECK(info1->getDescripcion() == info2->getDescripcion());
    CHECK(info1->getPrecio() == doctest::Approx(info2->getPrecio()));

    delete info1;
    delete info2;
}

TEST_CASE("Plato: Manejo de memoria en getInfo")
{
    DtPlato dtPlato(const_cast<char*>("P050"), "Empanada", 60.0f);
    Plato plato(dtPlato);

    DtPlato* info = nullptr;
    CHECK_NOTHROW(info = plato.getInfo());
    CHECK(info != nullptr);

    delete info;
}
