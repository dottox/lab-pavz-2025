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

TEST_CASE("Mesa: Imprimir información") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    ostringstream oss;
    oss << mesa;

    string expectedOutput = "Mesa Numero: " + to_string(mesa.getNumero()) + "\n    Mozo: " + mozo->getNombre() + ", No hay venta en curso";
    CHECK(oss.str() == expectedOutput);

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

TEST_CASE("Mesa: Setters con valores inválidos") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa;

    // Intentar establecer un número de mesa negativo
    CHECK_THROWS_AS(mesa.setNumero(-1), std::invalid_argument);

    // Intentar establecer un mozo nulo
    CHECK_THROWS_AS(mesa.setMozo(nullptr), std::invalid_argument);

    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Set venta en curso con valor nulo") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    // Intentar establecer una venta en curso nula
    CHECK_NOTHROW(mesa.setVentaEnCurso(nullptr));

    CHECK(mesa.getVentaEnCurso() == nullptr); // Verifica que la venta en curso sea nula

    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Set venta en curso con venta existente") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    VentaLocal *venta1 = new VentaLocal();
    mesa.setVentaEnCurso(venta1);

    CHECK(mesa.getVentaEnCurso() == venta1);

    VentaLocal *venta2 = new VentaLocal();
    mesa.setVentaEnCurso(venta2);

    CHECK(mesa.getVentaEnCurso() == venta2); // Verifica que se haya actualizado la venta en curso

    delete venta1; // Liberar memoria de la primera venta
    delete venta2; // Liberar memoria de la segunda venta
    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Setters con venta en curso") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    VentaLocal *venta = new VentaLocal();
    mesa.setVentaEnCurso(venta);

    CHECK(mesa.getVentaEnCurso() == venta);

    // Verificar que se pueda cambiar el mozo mientras hay una venta en curso
    Mozo *nuevoMozo = new Mozo("Nuevo Mozo");
    mesa.setMozo(nuevoMozo);
    CHECK(mesa.getMozo() == nuevoMozo);
    delete nuevoMozo; // Liberar memoria del nuevo mozo
    delete venta; // Liberar memoria de la venta
    delete mozo; // Liberar memoria del mozo original
}

TEST_CASE("Mesa: Setters con venta en curso nula") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    // Intentar establecer una venta en curso nula
    CHECK_NOTHROW(mesa.setVentaEnCurso(nullptr));

    CHECK(mesa.getVentaEnCurso() == nullptr); // Verifica que la venta en curso sea nula

    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Setters con venta en curso y mozo nulo") {
    Mesa mesa;

    // Intentar establecer una venta en curso nula
    CHECK_NOTHROW(mesa.setVentaEnCurso(nullptr));

    CHECK(mesa.getVentaEnCurso() == nullptr); // Verifica que la venta en curso sea nula

    // Intentar establecer un mozo nulo
    CHECK_THROWS_AS(mesa.setMozo(nullptr), std::invalid_argument);
}

TEST_CASE("Mesa: Setters con venta en curso existente y mozo nulo") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    VentaLocal *venta = new VentaLocal();
    mesa.setVentaEnCurso(venta);

    CHECK(mesa.getVentaEnCurso() == venta);

    // Intentar establecer un mozo nulo
    CHECK_THROWS_AS(mesa.setMozo(nullptr), std::invalid_argument);

    delete venta; // Liberar memoria de la venta
    delete mozo; // Liberar memoria del mozo
}

TEST_CASE("Mesa: Setters con venta en curso existente y mozo existente") {
    Mozo *mozo = new Mozo("Mozo Juan");
    Mesa mesa(mozo);

    VentaLocal *venta = new VentaLocal();
    mesa.setVentaEnCurso(venta);

    CHECK(mesa.getVentaEnCurso() == venta);

    // Verificar que se pueda cambiar el mozo mientras hay una venta en curso
    Mozo *nuevoMozo = new Mozo("Nuevo Mozo");
    mesa.setMozo(nuevoMozo);
    CHECK(mesa.getMozo() == nuevoMozo);

    delete nuevoMozo; // Liberar memoria del nuevo mozo
    delete venta; // Liberar memoria de la venta
    delete mozo; // Liberar memoria del mozo original
}
