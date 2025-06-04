#include "../doctest.h"
#include "../../utils/utils.h"
#include <iostream>
using namespace std;

TEST_CASE("Test generarNumeroEmpleado") {

    CHECK(utils::generarNumeroEmpleado() == 1);
    CHECK(utils::generarNumeroEmpleado() == 2);
}

TEST_CASE("Test generarNumeroFactura") {
    CHECK(utils::generarNumeroFactura() == 1);
    CHECK(utils::generarNumeroFactura() == 2);
}

TEST_CASE("Test generarNumeroMesa") {
    CHECK(utils::generarNumeroMesa() == 1);
    CHECK(utils::generarNumeroMesa() == 2);
}

TEST_CASE("Test generarNumeroVenta") {
    CHECK(utils::generarNumeroVenta() == 2);
    CHECK(utils::generarNumeroVenta() == 3);
}
