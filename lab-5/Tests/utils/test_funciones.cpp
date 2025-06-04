#include "../doctest.h"
#include "../../utils/funciones.h"

//C
TEST_CASE("Test de generarNumeroEmpleado")
{
    CHECK(generarNumeroEmpleado() == 1); // Primera llamada, debe devolver 1
    CHECK(generarNumeroEmpleado() == 2); // Segunda llamada, debe devolver 2
    CHECK(generarNumeroEmpleado() == 3); // Tercera llamada, debe devolver 3
}

TEST_CASE("Test de generarNumeroFactura")
{
    CHECK(generarNumeroFactura() == 1); // Primera llamada, debe devolver 1
    CHECK(generarNumeroFactura() == 2); // Segunda llamada, debe devolver 2
    CHECK(generarNumeroFactura() == 3); // Tercera llamada, debe devolver 3
}

TEST_CASE("Test de generarNumeroProducto")
{
    CHECK(generarNumeroProducto() == 1); // Primera llamada, debe devolver 1
    CHECK(generarNumeroProducto() == 2); // Segunda llamada, debe devolver 2
    CHECK(generarNumeroProducto() == 3); // Tercera llamada, debe devolver 3
}

TEST_CASE("Test de generarNumeroMesa")
{
    CHECK(generarNumeroMesa() == 1); // Primera llamada, debe devolver 1
    CHECK(generarNumeroMesa() == 2); // Segunda llamada, debe devolver 2
    CHECK(generarNumeroMesa() == 3); // Tercera llamada, debe devolver 3
}
