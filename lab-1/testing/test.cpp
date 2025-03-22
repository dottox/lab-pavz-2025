#include <iostream>
#include <cassert>

#include "../clases/socio.h"

using namespace std;

#define MAX_SOCIOS 10

void test_unit_socio() {
    Socio** listaSocios = new Socio*[MAX_SOCIOS];

    listaSocios[0] = new Socio("12345", "nombre1");
    listaSocios[1] = new Socio("23456", "nombre2");
    listaSocios[2] = new Socio("34567", "nombre3");
    listaSocios[3] = new Socio("34567", "nombre3");

    // Test of getCI
    assert(listaSocios[0]->getCI() == "12345");
    assert(listaSocios[3]->getCI() == "34567");

    // Test of getNombre
    assert(listaSocios[1]->getNombre() == "nombre2");
    assert(listaSocios[2]->getNombre() == "nombre3");

    // Test of setCI
    listaSocios[0]->setCI("12340");
    assert(listaSocios[0]->getCI() == "12340");

    // Test of setNombre
    listaSocios[1]->setNombre("nombre20");
    assert(listaSocios[1]->getNombre() == "nombre20");
}

int main() {
  

  return 0;
}