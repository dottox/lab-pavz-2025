#include "../../doctest.h"
#include "../../../clases/Mesa/Mesa.h"
#include "../../../clases/Empleado/Mozo.h"
#include "../../../clases/Venta/VentaLocal.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Mesa: Constructor y getters") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    CHECK(mesa.getNumero() > 0); // Verifica que el número de mesa sea positivo
    CHECK(mesa.getMozo() == mozo);
    CHECK(mesa.getVentaEnCurso() == nullptr);

    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Setters") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa;

    mesa.setNumero(5);
    mesa.setMozo(mozo);

    CHECK(mesa.getNumero() == 5);
    CHECK(mesa.getMozo() == mozo);

    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Set venta en curso") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    VentaLocal *venta = new VentaLocal();
    mesa.setVentaEnCurso(venta);

    CHECK(mesa.getVentaEnCurso() == venta);

    delete venta; // Liberar memoria de la venta
    delete mozo; // Liberar memoria del mozo
}
TEST_CASE("Mesa: Destructor") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa *mesa = new Mesa(mozo);

    // Verificar que el destructor no cause fugas de memoria
    delete mesa; // Verifica que no haya fugas de memoria al eliminar la mesa

    // No hay forma directa de verificar fugas de memoria en este contexto, pero se asume que el destructor funciona correctamente
}

TEST_CASE("Mesa: Obtener instancia de Mesa") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    CHECK(mesa.getMesa() == &mesa); // Verifica que getMesa retorne la propia instancia

    delete mozo; // Liberar memoria del mozo
}
