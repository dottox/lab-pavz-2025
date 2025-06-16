#include "../../doctest.h"
#include "../../../datatypes/Mesa/DtMesa.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtMesa - Constructor and Getters")
{
    // Crear un objeto Venta simulado
    Venta *venta = new Venta();
    venta->setSubtotal(100.0);
    
    // Crear un objeto DtMesa con la venta simulada
    DtMesa *dtMesa = new DtMesa(1, venta, true);
    
    // Verificar los valores de los atributos
    CHECK(dtMesa->getNumero() == 1);
    CHECK(dtMesa->getVentaActual()->getSubtotal() == 100.0);
    CHECK(dtMesa->getVentaActual()->getDescuento() == 10);
    CHECK(dtMesa->getVentaEnCurso() == true);

    
}