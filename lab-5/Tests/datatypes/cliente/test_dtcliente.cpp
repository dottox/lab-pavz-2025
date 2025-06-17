#include "../../doctest.h"
#include "../../../datatypes/Cliente/DtCliente.h"
#include <sstream>
using namespace std;

TEST_CASE("Test DtCliente - Constructor and Getters") 
{
    DtDireccion* dir = new DtDireccion("Calle Falsa", "15", "Entre A y B");
    DtCliente* cliente = new DtCliente("Carlos", "123456789", *dir);

    CHECK(cliente->getNombre() == "Carlos");
    CHECK(cliente->getTelefono() == "123456789");
    CHECK(cliente->getDireccion().getCalle() == "Calle Falsa");
    CHECK(cliente->getDireccion().getNumero() == "15");
    CHECK(cliente->getDireccion().getEntreCalles() == "Entre A y B");

    delete cliente;
    delete dir;
}

TEST_CASE("Test DtCliente - Default Constructor") 
{
    DtCliente* cliente = new DtCliente();
    // CHECK(cliente->getNombre() == "");
    // CHECK(cliente->getTelefono() == "");
    // CHECK(cliente->getDireccion().getCalle() == "");
    // CHECK(cliente->getDireccion().getNumero() == 0);
    // CHECK(cliente->getDireccion().getEntreCalles() == "");
    delete cliente;
}

TEST_CASE("Test DtCliente - Output Operator") 
{
    DtDireccion* dir = new DtDireccion("Av. Siempre Viva", "742", "Cerca del parque");
    DtCliente* cliente = new DtCliente("Ana", "987654321", *dir);
    stringstream ss;
    ss << *cliente;
    string output = ss.str();
    CHECK(output.find("Nombre: Ana") != string::npos);
    CHECK(output.find("Telefono: 987654321") != string::npos);
    CHECK(output.find("Av. Siempre Viva") != string::npos);
    CHECK(output.find("742") != string::npos);
    CHECK(output.find("Cerca del parque") != string::npos);
    delete cliente;
    delete dir;
}

TEST_CASE("Test DtCliente - Copy Constructor") 
{
    DtDireccion* dir = new DtDireccion("Rambla", "10", "Frente al mar");
    DtCliente* original = new DtCliente("Luis", "5555555", *dir);
    DtCliente* copia = new DtCliente(*original);
    CHECK(copia->getNombre() == "Luis");
    CHECK(copia->getTelefono() == "5555555");
    CHECK(copia->getDireccion().getCalle() == "Rambla");
    CHECK(copia->getDireccion().getNumero() == "10");
    CHECK(copia->getDireccion().getEntreCalles() == "Frente al mar");
    delete original;
    delete copia;
    delete dir;
}

TEST_CASE("Test DtCliente - Assignment Operator") 
{
    DtDireccion* dir = new DtDireccion("Principal", "1", "Esq. Secundaria");
    DtCliente* cliente1 = new DtCliente("Maria", "111222333", *dir);
    DtCliente* cliente2 = new DtCliente();
    *cliente2 = *cliente1;
    CHECK(cliente2->getNombre() == "Maria");
    CHECK(cliente2->getTelefono() == "111222333");
    CHECK(cliente2->getDireccion().getCalle() == "Principal");
    CHECK(cliente2->getDireccion().getNumero() == "1");
    CHECK(cliente2->getDireccion().getEntreCalles() == "Esq. Secundaria");
    delete cliente1;
    delete cliente2;
    delete dir;
}