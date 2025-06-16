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


TEST_CASE("Plato: Destructor")
{
    DtPlato dtPlato(const_cast<char*>("P003"), "Pizza Margherita", 200.0f);
    Plato* plato = new Plato(dtPlato);

    // Verificar que el destructor no cause fugas de memoria
    delete plato;
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



TEST_CASE("Plato: getTipo siempre retorna TipoPlato")
{
    DtPlato dtPlato(const_cast<char*>("P030"), "Tarta", 90.0f);
    Plato plato(dtPlato);

    CHECK(plato.getTipo() == TipoProducto::TipoPlato);
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
