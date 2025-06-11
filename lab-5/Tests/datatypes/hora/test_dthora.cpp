#include "../../doctest.h"
#include "../../../datatypes/Hora/DtHora.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtHora - Constructor and Getters")
{
    DtHora *hora = new DtHora(14, 30, 45);

    CHECK(hora->getHora() == 14);
    CHECK(hora->getMinuto() == 30);
    CHECK(hora->getSegundo() == 45);

    if (cout << *hora << endl)
    {
        CHECK(true); // Si la impresion no lanza una excepcion, el test pasa
    }
    else
    {
        CHECK(false); // Si la impresion falla, el test falla
    }

    DtHora *hora2 = new DtHora(14, 30, 45);
    CHECK(*hora == *hora2); // Verifica que la comparacion funcione correctamente

    DtHora *hora3 = new DtHora(15, 30, 45);
    CHECK_FALSE(*hora == *hora3); // Verifica que la comparacion funcione correctamente
}