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
    cout << e.what() << endl;
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
    cout << e.what() << endl;
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

  DtSpinning dtTC004=DtSpinning(4, "TC003", Manana, 10); // agarro index 999 que no existe
  Spinning* TC004 = new Spinning(dtTC004);

  // TC-004: Settear un turno inválido
  try {
    TC004->setTurno(static_cast<Turno>(999));
    throw runtime_error("TC004 Error: Se permitió settear un turno inválido.");
  } catch (const invalid_argument& e) {
    cout << "TC-003 pasó correctamente: no se permitió construir un turno inválido" << endl;
  }
  
  delete TC004;

  // ---------------------- TC-005 ----------------------


  // TC-005: Agregar una inscripción
  Socio* socio = new Socio(DtSocio("12345678", "Juan"));
  Inscripcion* inscripcion = new Inscripcion(DtFecha(1, 1, 2021), socio);
  DtSpinning dtTC005 = DtSpinning(6, "TC005", Manana, 10);
  Spinning* TC005 = new Spinning(dtTC005);

  cout << "TC-005 Cupo antes de agregar inscripcion: " << TC005->cupo() << endl;
  TC005->agregarInscripcion(inscripcion);
  cout << "TC-005 Cupo despues de agregar inscripcion: " << TC005->cupo() << endl;
  cout << "TC-005 Inscripcion agregada correctamente" << endl;

  // Verificar que cupo se haya actualizado correctamente
  assert(TC005->cupo() == 9);
  cout << "TC-005 Cupo actualizado correctamente" << endl;

  // Verificar que la cantidad de inscripciones se haya actualizado correctamente
  assert(TC005->getCantInscripciones() == 1);
  cout << "TC-005 Cantidad de inscripciones actualizada correctamente" << endl;

  // Verificar que la inscripción se haya agregado correctamente con getInscripcion
  Inscripcion* inscripcionEncontrada = TC005->getInscripcion(socio->getCI());
  if (inscripcionEncontrada != nullptr) { cout << "TC-005 Inscripcion encontrada correctamente - getInscripción" << endl; } 
  else { throw runtime_error("TC005 Error: Inscripcion no encontrada mediante getInscripción"); }

  // Verificar que la inscripción obtenida sea la misma que la agregada
  assert(inscripcionEncontrada->getSocio()->getCI() == "12345678" && inscripcionEncontrada->getFecha() == DtFecha(1, 1, 2021));
  cout << "TC-005 Inscripcion obtenida correctamente" << endl;


  // Verificar que la inscripción se haya agregado correctamente con getInscripciones
  Inscripcion** inscripciones = TC005->getInscripciones();
  bool found = false;
  for (int i = 0; i < TC005->getCantInscripciones(); i++) {
      if (inscripciones[i]->getSocio()->getCI() == socio->getCI()) {
        found = true;
        break;
      }
  }
  if (found) { cout << "TC-005 Inscripcion encontrada correctamente - getInscripciones" << endl; }
  else { throw runtime_error("TC005 Error: Inscripcion no encontrada mediante getInscripciones"); }

  // TC-006: Agregar una inscripción ya existente
  DtFecha fechaInscripcion = DtFecha(1, 2, 2021);
  Inscripcion* inscripcionDuplicada = new Inscripcion(fechaInscripcion, socio);

  try {
    TC005->agregarInscripcion(inscripcionDuplicada);
    throw runtime_error("TC006 Error: Se permitió agregar una inscripción duplicada.");
  } catch (const invalid_argument& e) {  
    cout << "TC-006 pasó correctamente: no se permitió agregar una inscripción duplicada" << endl;
  } catch (runtime_error& e) {
    cout << e.what() << endl;
    terminate();
  }
  
  delete inscripcionDuplicada;

  // TC-007: Borrar una inscripción
  cout << "Cupo antes de borrar inscripcion: " << TC005->cupo() << endl;
  TC005->borrarInscripcion(socio->getCI());
  cout << "Cupo despues de borrar inscripcion: " << TC005->cupo() << endl;
  cout << "Inscripcion borrada correctamente" << endl;

  // Verificar que la cantidad de inscripciones se haya actualizado correctamente
  assert(TC005->getCantInscripciones() == 0);

  // Verificar que el cupo se haya actualizado correctamente
  assert(TC005->cupo() == 10);
  cout << "TC-007 Cantidad de inscripciones y cupo actualizados correctamente" << endl;

  // Verificar que la inscripción se haya borrado correctamente
  Inscripcion* inscripcionBorrada = TC005->getInscripcion(socio->getCI());
  if (inscripcionBorrada == nullptr) { cout << "TC-007 Inscripcion borrada correctamente - getInscripcion" << endl; } 
  else { throw runtime_error("TC007 Error: Inscripcion no borrada mediante getInscripcion"); }

  // Verificar que la inscripción se haya borrado correctamente con getInscripciones
  inscripciones = TC005->getInscripciones();
  found = false;
  for (int i = 0; i < TC005->getCantInscripciones(); i++) {
      if (inscripciones[i]->getSocio()->getCI() == socio->getCI()) {
        found = true;
        break;
      }
  }
  if (!found) { cout << "TC-007 Pasó correctamente, no se encontró - getInscripciones" << endl; }
  else { throw runtime_error("TC007 Error: Inscripcion encontrada mediante getInscripciones"); }

  delete socio;
  delete TC005;

  cout << "Todos los tests pasaron correctamente." << endl;
}