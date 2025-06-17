#include "../../doctest.h"
#include "../../../datatypes/Consumido/DtConsumido.h"

TEST_CASE("Test DtConsumido - Constructor and Getters")
{
    DtConsumido *consumido = new DtConsumido((char*)"001", "Pizza", 2, 15.50);

    CHECK(consumido->getDescripcion() == "Pizza");
    CHECK(consumido->getCantidad() == 2);
    CHECK(consumido->getPrecio() == 15.50);
    delete consumido; // Liberar memoria
}
TEST_CASE("Test DtConsumido - Default Constructor")
{
    DtConsumido *consumido = new DtConsumido();
    // CHECK(consumido->getDescripcion() == "");
    // CHECK(consumido->getCantidad() == 0);
    // CHECK(consumido->getPrecio() == 0.0f);
    delete consumido; // Liberar memoria
}
