#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/socio.h"
using namespace std;

#define MAX_SOCIOS 10

int main() {
  Socio** listaSocios = new Socio*[MAX_SOCIOS];

  listaSocios[0] = new Socio(DtSocio("1", "Juan"));

  //Test for CI and Nombre
  assert(listaSocios[0]->getCI() == "1");
  assert(listaSocios[0]->getNombre() == "Juan");  

  //Test for setCI and setNombre
  listaSocios[0]->setCI("9");
  assert(listaSocios[0]->getCI() == "9");
  listaSocios[0]->setNombre("Jorge");
  assert(listaSocios[0]->getNombre() == "Jorge");

  cout << "Funcionó pa" << endl;

  delete[] listaSocios;

  return 0;
}