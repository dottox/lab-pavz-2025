#include "../../doctest.h"
#include "../../../datatypes/Producto/DtPlato.h"
#include "../../../datatypes/Producto/DtProducto.h"
#include "../../../enums/TipoProducto.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtPlato - Constructor and Getters")
{

    DtPlato * plato = new DtPlato((char*)"P001", "Ensalada fresca", 10.00f);
    CHECK(string(plato->getCodigo()) == "P001");
    CHECK(plato->getDescripcion() == "Ensalada fresca");
    CHECK(plato->getTipo() == TipoProducto::TipoPlato);
    CHECK(plato->getPrecio() == 10.00f);

    


}