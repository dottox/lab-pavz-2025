#include "../../doctest.h"
#include "../../../datatypes/Asignacion/DtAsignacion.h"
#include <iostream>
using namespace std;
TEST_CASE("Test DtAsignacion") 
{
    DtAsignacion* asignacion = new DtAsignacion(5, 10);

    CHECK(asignacion->getNumeroMozo() == 5);
    CHECK(asignacion->getNumeroMesa() == 10);

    delete asignacion;
}

TEST_CASE("Test DtAsignacion - Default Constructor") 
{
    DtAsignacion* asignacion = new DtAsignacion();

    // CHECK(asignacion->getNumeroMozo() == 0);
    // CHECK(asignacion->getNumeroMesa() == 0);

    delete asignacion;
}