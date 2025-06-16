#include "../../doctest.h"
#include "../../../clases/Empleado/Empleado.h"
#include <iostream>
using namespace std;

TEST_CASE("Empleado: Constructor") {
    Empleado empleado("Juan Perez");
    
    CHECK(empleado.getNombre() == "Juan Perez");
    CHECK(empleado.getNumero() == 1);
}

TEST_CASE("Empleado: Destructor") {
    Empleado *empleado = new Empleado("Pedro Martinez");
    
    // Verificar que el destructor no cause fugas de memoria
    delete empleado;
}