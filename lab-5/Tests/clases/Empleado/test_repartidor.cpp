#include "../../doctest.h"
#include "../../../clases/Empleado/Mozo.h"
#include "../../../clases/Empleado/Repartidor.h"
#include "../../../clases/Mesa/Mesa.h"
#include "../../../clases/Venta/VentaLocal.h"
#include "../../../enums/Transporte.h"
#include <iostream>

TEST_CASE("Mozo constructor inicializa correctamente") {
    Mozo mozo("Juan Perez");
    CHECK(mozo.getCantidadMesasAsignadas() == 0);
    CHECK(mozo.getMesasAsignadas() != nullptr);
    CHECK(mozo.getMesasAsignadas()->getSize() == 0);
    CHECK(mozo.getMesasAsignadasSinVentaEnCurso()->getSize() == 0);
    CHECK(mozo.getNombre() == "Juan Perez");
    CHECK(mozo.getNumero() == 0); // Asumimos numero por defecto
}

TEST_CASE("setCantidadMesasAsignadas lanza excepcion con valor negativo") {
    Mozo mozo("Test");
    CHECK_THROWS_AS(mozo.setCantidadMesasAsignadas(-5), std::invalid_argument);
}

TEST_CASE("setMesaAsignada agrega mesa correctamente") {
    Mozo mozo("Carlos");
    Mesa* mesa = new Mesa();
    mozo.setMesaAsignada(mesa);
    CHECK(mozo.getCantidadMesasAsignadas() == 1);
    CHECK(mozo.getMesasAsignadas()->getSize() == 1);
    delete mesa;
}

TEST_CASE("setMesaAsignada lanza excepcion con nullptr") {
    Mozo mozo("Carlos");
    CHECK_THROWS_AS(mozo.setMesaAsignada(nullptr), std::invalid_argument);
}

TEST_CASE("setMesaAsignada lanza excepcion si ya esta asignada a otro mozo") {
    Mozo mozo1("Mozo1");
    Mozo mozo2("Mozo2");
    Mesa* mesa = new Mesa();
    mozo1.setMesaAsignada(mesa);
    CHECK_THROWS_AS(mozo2.setMesaAsignada(mesa), std::invalid_argument);
    delete mesa;
}

TEST_CASE("getMesasAsignadasSinVentaEnCurso solo devuelve las sin venta") {
    Mozo mozo("Mozo");
    Mesa* mesaSinVenta = new Mesa();
    Mesa* mesaConVenta = new Mesa();

    mesaConVenta->setVentaEnCurso(new VentaLocal());

    mozo.setMesaAsignada(mesaSinVenta);
    mozo.setMesaAsignada(mesaConVenta);

    ICollection* sinVenta = mozo.getMesasAsignadasSinVentaEnCurso();
    CHECK(sinVenta->getSize() == 1);

    delete mesaSinVenta;
    delete mesaConVenta;
    delete sinVenta;
}

TEST_CASE("Repartidor constructor y getTransporte") {
    Repartidor repartidor("Lucia", Transporte::Moto);
    CHECK(repartidor.getNombre() == "Lucia");
    CHECK(repartidor.getTransporte() == Transporte::Moto);
    CHECK(repartidor.getNumero() == 0); // Asume default del Empleado
}
