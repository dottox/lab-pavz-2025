#include "../../doctest.h"
#include "../../../clases/Cliente/Cliente.h"
#include "../../../datatypes/Cliente/DtCliente.h"
#include "../../../datatypes/Direccion/DtDireccion.h"
#include <iostream>
using namespace std;

TEST_CASE("Cliente: Constructor") {


    DtDireccion dir("Calle 123", 12345, "Ciudad");
    DtCliente dtCliente("Juan", "099123456", dir);
    Cliente cliente(dtCliente);

    CHECK(cliente.getNombre() == "Juan");
    CHECK(cliente.getTelefono() == "099123456");
    CHECK(cliente.getDireccion().getCalle() == "Calle 123");
    CHECK(cliente.getDireccion().getNumero() == 12345);
    CHECK(cliente.getDireccion().getEntreCalles() == "Ciudad");

}

TEST_CASE("Cliente: Constructor con datos inválidos") {
    // Dirección con datos vacíos o inválidos
    DtDireccion dirInvalida("", -1, "");
    DtCliente dtClienteInvalido("", "", dirInvalida);

    Cliente clienteInvalido(dtClienteInvalido);

    CHECK(clienteInvalido.getNombre() == "");
    CHECK(clienteInvalido.getTelefono() == "");
    CHECK(clienteInvalido.getDireccion().getCalle() == "");
    CHECK(clienteInvalido.getDireccion().getNumero() == -1);
    CHECK(clienteInvalido.getDireccion().getEntreCalles() == "");
}
TEST_CASE("Cliente: Setters y getters") {
    DtDireccion dir("Calle 456", 67890, "Otra Ciudad");
    DtCliente dtCliente("Maria", "099987654", dir);
    Cliente cliente(dtCliente);
    cliente.setNombre("Ana");
    cliente.setTelefono("099123456");
    DtDireccion nuevaDir("Calle 789", 54321, "Nueva Ciudad");
    cliente.setDireccion(nuevaDir);
    CHECK(cliente.getNombre() == "Ana");
    CHECK(cliente.getTelefono() == "099123456");
    CHECK(cliente.getDireccion().getCalle() == "Calle 789");
    CHECK(cliente.getDireccion().getNumero() == 54321);
    CHECK(cliente.getDireccion().getEntreCalles() == "Nueva Ciudad");
}
TEST_CASE("Cliente: Destructor") {
    DtDireccion dir("Calle 123", 12345, "Ciudad");
    DtCliente dtCliente("Juan", "099123456", dir);
    Cliente *cliente = new Cliente(dtCliente);
    
    // Verificar que el destructor no cause fugas de memoria
    delete cliente;
}
