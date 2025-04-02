#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/spinning.h"
using namespace std;
int main()
{
  // ---------------------- TC-001 ----------------------
  // Test de constructor, getters y setters
  DtSpinning dtTC001=DtSpinning(1, "TC000", Manana, 1);
  Spinning * TC001 = new Spinning(dtTC001);
  cout << "TC-001 Creando clase spinning con id: " << TC001->getId() << endl;

  assert(TC001->getId() == 1);
  assert(TC001->getNombre() == "TC000");
  assert(TC001->getCantBicicletas() == 1);
  assert(TC001->getTurno() == Manana);
  assert(TC001->cupo() == 1);
  cout << "TC-001 Constructor funciona correctamente" << endl;

  TC001->setCantBicicletas(2);
  assert(TC001->getCantBicicletas() == 2);
  TC001->setTurno(Tarde);
  assert(TC001->getTurno() == Tarde);
  TC001->setNombre("TC001");
  assert(TC001->getNombre() == "TC001");
  cout << "TC-001 Setters funcionan correctamente" << endl;

  // TC-001: Settear una cantidad de bicicletas mayor a lo válido
  try {
    TC001->setCantBicicletas(51);
    throw runtime_error("TC001 Error: Se permitió una cantidad de bicicletas inválida.");
  } catch (const invalid_argument& e) {
    cout << "TC-001 pasó correctamente: no se permitió agregar una cantidad de bicicletas mayor a lo esperado" << e.what() << endl;
  } catch (runtime_error& e) {
    terminate();
  }


  // ---------------------- TC-002 ----------------------

  // TC-002: Settear una cantidad de bicicletas menor a lo válido
  try {
    TC001->setCantBicicletas(-2);
    throw runtime_error("TC002 Error: Se permitió una cantidad de bicicletas inválida.");
  } catch (const invalid_argument& e) {
    cout << "TC-002 pasó correctamente: no se permitió agregar una cantidad de bicicletas menor a lo esperado" << e.what() << endl;
  } catch (runtime_error& e) {
    terminate();
  }

  delete TC001;


  // ---------------------- TC-003 ----------------------

  // TC-003: Construir con un turno inválido
  try {
    DtSpinning dtTC003=DtSpinning(3, "TC003", static_cast<Turno>(999), 10); // agarro index 999 que no existe
    Spinning* TC003 = new Spinning(dtTC003);
    delete TC003;
    throw runtime_error("TC003 Error: Se permitió construir un turno inválido.");
  } catch (const invalid_argument& e) {
      cout << "TC-003 pasó correctamente: no se permitió construir un turno inválido" << endl;
  }


  // ---------------------- TC-004 ----------------------


  // TC-004: Settear un turno inválido
  try {
    DtSpinning dtTC004=DtSpinning(4, "TC003", Manana, 10); // agarro index 999 que no existe
    Spinning* TC004 = new Spinning(dtTC004);
    TC004->setTurno(static_cast<Turno>(999));
    delete TC004;
    throw runtime_error("TC004 Error: Se permitió settear un turno inválido.");
  } catch (const invalid_argument& e) {
    cout << "TC-003 pasó correctamente: no se permitió construir un turno inválido" << endl;
  }


  // ---------------------- TC-005 ----------------------


  // TC-005: Constructor vacío
  try{
    DtSpinning dtTC005 = DtSpinning();
    Spinning * TC005 = new Spinning(dtTC005);
    delete TC005;
    throw runtime_error("TC005 Error: Se permitió construir un spinning vacío.");
  } catch (const invalid_argument& e) {
      cout << "TC-005 pasó correctamente: no se permitió construir un spinning vacío" << endl;
  } catch (runtime_error& e) {
      terminate();
  }

  // TC-006: Agregar una inscripción
  Socio* socio = new Socio(DtSocio("12345678", "Juan"));
  Inscripcion* inscripcion = new Inscripcion(DtFecha(1, 1, 2021), socio);
  DtSpinning dtTC006 = DtSpinning(6, "TC006", Manana, 10);
  Spinning* TC006 = new Spinning(dtTC006);

  cout << "Cupo antes de agregar inscripcion: " << TC006->cupo() << endl;
  TC006->agregarInscripcion(inscripcion);
  cout << "TC-006 Inscripcion agregada correctamente" << endl;

  // Verificar que cupo se haya actualizado correctamente
  assert(TC006->cupo() == 9);
  cout << "TC-006 Cupo actualizado correctamente" << endl;

  // Verificar que la cantidad de inscripciones se haya actualizado correctamente
  assert(TC006->getCantInscripciones() == 1);
  cout << "TC-006 Cantidad de inscripciones actualizada correctamente" << endl;

  // Verificar que la inscripción se haya agregado correctamente con getInscripcion
  Inscripcion* inscripcionEncontrada = TC006->getInscripcion(socio->getCI(), DtFecha(1, 1, 2021));
  if (inscripcionEncontrada != nullptr) { cout << "TC-006 Inscripcion encontrada correctamente" << endl; } 
  else { throw runtime_error("TC006 Error: Inscripcion no encontrada en la clase spinning"); }

  // Verificar que la inscripción se haya agregado correctamente con getInscripciones
  Inscripcion** inscripciones = TC006->getInscripciones();
  bool found = false;
  for (int i = 0; i < TC006->getCantInscripciones(); i++) {
      if (inscripciones[i]->getSocio()->getCI() == socio->getCI() && inscripciones[i]->getFecha() == DtFecha(1, 1, 2021)) {
        found = true;
        break;
      }
  }
  if (found) { cout << "TC-006 Inscripcion encontrada correctamente" << endl; }
  else { throw runtime_error("TC006 Error: Inscripcion no agregada correctamente en la clase spinning"); }


  cout << "Todos los tests pasaron correctamente." << endl;

  return 0;
}