#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/socio.h"
using namespace std;

int main()
{

  /*
    private:
        string ci;
        string nombre;
    public:
        Socio(DtSocio);
        void setCI(string);
        void setNombre(string);
        string getCI();
        string getNombre();
        ~Socio();
        */
  // Test for GetSocio

  //
  try
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
    delete dataSocio;
    cout << "TC001 PASS" << endl;
  }
  catch (...)
  {
    cout << "Error inesperado en TC001" << endl;
  }

  // TC001: Validar CI < 8 caracteres
  try
  {
    Socio *s=new Socio(DtSocio("1234567", "Juan"));
    assert(false); // No debería llegar aquí
  }
  catch (...)
  {
    cout << "TC002 PASS" << endl;
  }

  // TC003: Validar CI == 8 caracteres
  try
  {
    Socio *s=new Socio(DtSocio("12345678", "Juan"));
    assert(s->getCI() == "12345678");
    cout << "TC003 PASS" << endl;
  }
  catch (...)
  {
    assert(false);
  }

  // TC004: Validar CI > 8 caracteres
  try
  {
    Socio *s=new Socio(DtSocio("123456789", "Juan"));
    assert(false); // No debería llegar aquí
  }
  catch (...)
  {
    cout << "TC004 PASS" << endl;
  }
  // TC005: Validar CI invalida con letras
  try{
    Socio *s=new Socio(DtSocio("abcdefgh", "Juan"));
    assert(false);
  }catch(...){
    cout << "TC005 PASS" << endl;
  }
  // TC006: Validar Nombre vacio
  try{
    Socio *s=new Socio(DtSocio("12345678", ""));
    assert(false);
  }catch(...){
    cout << "TC006 PASS" << endl;
  }
  // TC007: Validar Nombre con 1 caracter
  try{
    Socio *s=new Socio(DtSocio("12345678", "Gerardo"));
    assert(s->getNombre() == "Gerardo");
    delete s;
    cout << "TC007 PASS" << endl;

  }catch(...){
    assert(false);
  }

  cout << "[----------------------------/ Funciono pa' /----------------------------]" << endl;

  return 0;
}
