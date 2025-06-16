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
TEST_CASE("Test secuencia de generarNumeroEmpleado") {
    int val1 = utils::generarNumeroEmpleado();
    int val2 = utils::generarNumeroEmpleado();
    int val3 = utils::generarNumeroEmpleado();
    CHECK(val2 == val1 + 1);
    CHECK(val3 == val2 + 1);
}

TEST_CASE("Test secuencia de generarNumeroFactura") {
    int val1 = utils::generarNumeroFactura();
    int val2 = utils::generarNumeroFactura();
    int val3 = utils::generarNumeroFactura();
    CHECK(val2 == val1 + 1);
    CHECK(val3 == val2 + 1);
}

TEST_CASE("Test secuencia de generarNumeroMesa") {
    int val1 = utils::generarNumeroMesa();
    int val2 = utils::generarNumeroMesa();
    int val3 = utils::generarNumeroMesa();
    CHECK(val2 == val1 + 1);
    CHECK(val3 == val2 + 1);
}

TEST_CASE("Test secuencia de generarNumeroVenta") {
    int val1 = utils::generarNumeroVenta();
    int val2 = utils::generarNumeroVenta();
    int val3 = utils::generarNumeroVenta();
    CHECK(val2 == val1 + 1);
    CHECK(val3 == val2 + 1);
}

TEST_CASE("Test obtenerFechaActual devuelve fecha razonable") {
    DtFecha fecha = utils::obtenerFechaActual();
    CHECK(fecha.getAnio() >= 2024); // Ajusta según el año actual
    CHECK(fecha.getMes() >= 1);
    CHECK(fecha.getMes() <= 12);
    CHECK(fecha.getDia() >= 1);
    CHECK(fecha.getDia() <= 31);
}

TEST_CASE("Test obtenerHoraActual devuelve hora razonable") {
    DtHora hora = utils::obtenerHoraActual();
    CHECK(hora.getHora() >= 0);
    CHECK(hora.getHora() <= 23);
    CHECK(hora.getMinuto() >= 0);
    CHECK(hora.getMinuto() <= 59);
    CHECK(hora.getSegundo() >= 0);
    CHECK(hora.getSegundo() <= 59);
}
