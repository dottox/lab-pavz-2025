#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/socio.h"
using namespace std;

int main(){

  //Test for GetSocio
  Socio dataSocio = DtSocio("1", "Juan");

  //Test for CI and Nombre
  assert(dataSocio.getCI() == "1");
  assert(dataSocio.getNombre() == "Juan");  

  //Test for setCI and setNombre
  dataSocio.setCI("9");
  assert(dataSocio.getCI() == "9");
  dataSocio.setNombre("Jorge");
  assert(dataSocio.getNombre() == "Jorge");

  cout << "[----------------------------/ Funciono pa' /----------------------------]" << endl;

  delete dataSocio;

  return 0;
}


