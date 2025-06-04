#include "../../doctest.h"
#include "../../../datatypes/Fecha/DtFecha.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtFecha - Constructor and Getters")
{
    DtFecha *fecha = new DtFecha(5, 10, 2025);

    CHECK(fecha->getMes() == 10);
    CHECK(fecha->getDia() == 5);
    CHECK(fecha->getAnio() == 2025);

    if (cout << *fecha << endl)
    {
        CHECK(true); // Si la impresión no lanza una excepción, el test pasa
    }
    else
    {
        CHECK(false); // Si la impresión falla, el test falla
    }
    DtFecha *fecha2 = new DtFecha(5, 10, 2025);
    CHECK(*fecha == *fecha2); // Verifica que la comparación funcione correctamente
    DtFecha *fecha3 = new DtFecha(5, 10, 2024);
    CHECK_FALSE(*fecha == *fecha3); // Verifica que la comparación funcione correctamente
}