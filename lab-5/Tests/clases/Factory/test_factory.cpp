#include "../../doctest.h"
#include "../../../clases/Factory/Factory.h"
#include <iostream>

TEST_CASE("Factory: getSistema returns ISistema instance") {
    ISistema *sistema = Factory::getSistema();
    CHECK(sistema != nullptr);
    CHECK((Sistema*) sistema != nullptr);
}