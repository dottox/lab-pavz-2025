#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/socio.h"
using namespace std;

int main()
{

  Socio *dataSocio = new Socio(DtSocio("12345678", "Juan"));

  // Test for CI and Nombre
  assert(dataSocio->getCI() == "12345678");
  assert(dataSocio->getNombre() == "Juan");

  // Test for setCI and setNombre
  dataSocio->setCI("87654321");
  assert(dataSocio->getCI() == "87654321");

  dataSocio->setNombre("Jorge");
  assert(dataSocio->getNombre() == "Jorge");

  
  // TC-001: Validar setter CI inválido
  try {
    dataSocio->setCI("asdqwe");
    throw runtime_error("TC001 Error: Se permitió settear un CI inválido.");
  } catch (const invalid_argument &e) {
    cout << "TC001 funcionó correctamente" << endl;
  } catch (const runtime_error &e) {
    cout << e.what() << endl;
    terminate();
  }
  
  delete dataSocio;
  cout << "TC001 PASS" << endl;

  // TC002: Validar CI < 8 caracteres
  try
  {
    Socio *s=new Socio(DtSocio("1234567", "Juan"));
    throw runtime_error("TC002 Error: Se permitió un CI menor a 8 caracteres.");
  }
  catch (const invalid_argument &e)
  {
    cout << "TC002 funcionó correctamente" << endl;
  }
  catch (const runtime_error &e)
  {
    cout << e.what() << endl;
    terminate();
  }


  // TC003: Validar CI > 8 caracteres
  try
  {
    Socio *s=new Socio(DtSocio("123456789", "Juan"));
    throw runtime_error("TC003 Error: Se permitió un CI mayor a 8 caracteres.");
  }
  catch (const invalid_argument &e)
  {
    cout << "TC003 funcionó correctamente" << endl;
  }
  catch (const runtime_error &e)
  {
    cout << e.what() << endl;
    terminate();
  }

  // TC004: Validar CI invalida con letras
  try{
    Socio *s=new Socio(DtSocio("abcdefgh", "Juan"));
    throw runtime_error("TC004 Error: Se permitió un CI inválido con letras.");
  } catch (const invalid_argument &e)
  {
    cout << "TC004 funcionó correctamente" << endl;
  }
  catch (const runtime_error &e)
  {
    cout << e.what() << endl;
    terminate();
  }

  // TC005: Validar Nombre vacio
  try{
    Socio *s=new Socio(DtSocio("12345678", ""));
    throw runtime_error("TC005 Error: Se permitió un nombre vacío.");
  } catch (const invalid_argument &e)
  {
    cout << "TC005 funcionó correctamente" << endl;
  }
  catch (const runtime_error &e)
  {
    cout << e.what() << endl;
    terminate();
  }

  // TC006: Validar Nombre con 1 caracter
  try{
    Socio *s=new Socio(DtSocio("12345678", "A"));
    throw runtime_error("TC006 Error: Se permitió un nombre con 1 caracter.");
  } catch (const invalid_argument &e)
  {
    cout << "TC006 funcionó correctamente" << endl;
  }
  catch (const runtime_error &e)
  {
    cout << e.what() << endl;
    terminate();
  }

  cout << "[----------------------------/ Funciono pa' /----------------------------]" << endl;

  return 0;
}
