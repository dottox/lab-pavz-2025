#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/entrenamiento.h"

using namespace std;


int main()
{
  // ---------------------- TC-001 ----------------------
  // Test de constructor, getters y setters
  DtEntrenamiento dtTC001=DtEntrenamiento(1, "TC000", Manana, true);
  Entrenamiento * TC001 = new Entrenamiento(dtTC001);

  assert(TC001->getId() == 1);
  assert(TC001->getNombre() == "TC000");
  assert(TC001->getRambla() == true);
  assert(TC001->getTurno() == Manana);
  assert(TC001->cupo() == 20);
  cout << "TC-001 Constructor funciona correctamente" << endl;

  TC001->setTurno(Tarde);
  assert(TC001->getTurno() == Tarde);
  TC001->setNombre("TC001");
  assert(TC001->getNombre() == "TC001");
  cout << "TC-001 Setters funcionan correctamente" << endl;

  delete TC001;

    // ---------------------- TC-002 ----------------------

  // TC-002: Construir con un turno inválido
  try {
    DtEntrenamiento dtTC002=DtEntrenamiento(3, "TC002", static_cast<Turno>(999), 10); // agarro index 999 que no existe
    Entrenamiento* TC002 = new Entrenamiento(dtTC002);
    delete TC002;
    throw runtime_error("TC002 Error: Se permitió construir un turno inválido.");
  } catch (const invalid_argument& e) {
      cout << "TC-002 pasó correctamente: no se permitió construir un turno inválido" << endl;
  }


  // ---------------------- TC-004 ----------------------


  // TC-004: Settear un turno inválido
  try {
    DtEntrenamiento dtTC003=DtEntrenamiento(4, "TC002", Manana, 10); // agarro index 999 que no existe
    Entrenamiento* TC003 = new Entrenamiento(dtTC003);
    TC003->setTurno(static_cast<Turno>(999));
    delete TC003;
    throw runtime_error("TC003 Error: Se permitió settear un turno inválido.");
  } catch (const invalid_argument& e) {
    cout << "TC-003 pasó correctamente: no se permitió construir un turno inválido" << endl;
  }

  // ---------------------- TC-005 ----------------------

  // TC-005: Agregar una inscripción
  Socio* socio = new Socio(DtSocio("12345678", "Juan"));
  Inscripcion* inscripcion = new Inscripcion(DtFecha(1, 1, 2021), socio);
  DtEntrenamiento dtTC005 = DtEntrenamiento(6, "TC005", Manana, true);
  Entrenamiento* TC005 = new Entrenamiento(dtTC005);

  cout << "Cupo antes de agregar inscripcion: " << TC005->cupo() << endl;
  TC005->agregarInscripcion(inscripcion);
  cout << "Cupo después de agregar inscripcion: " << TC005->cupo() << endl;
  cout << "TC-005 Inscripcion agregada correctamente" << endl;

  // Verificar que el cupo se haya actualizado
  assert(TC005->cupo() == 19);
  cout << "TC-005 Cupo actualizado correctamente" << endl;

  // Verificar que la cantidad de inscripciones se haya actualizado
  assert(TC005->getCantInscripciones() == 1);
  cout << "TC-005 Cantidad de inscripciones actualizada correctamente" << endl;

  // Verificar que la inscripción se haya agregado correctamente
  Inscripcion* inscripcionObtenida = TC005->getInscripcion("12345678");
  if (inscripcionObtenida != nullptr) { cout << "TC-005 Inscripcion obtenida correctamente - getInscripción" << endl; }
  else { throw runtime_error("TC-005 Error: Inscripcion no encontrada mediante getInscripcion"); }

  // Verificar que la inscripción obtenida sea la misma que la agregada
  assert(inscripcionObtenida->getSocio()->getCI() == "12345678" && inscripcionObtenida->getFecha() == DtFecha(1, 1, 2021));
  cout << "TC-005 Inscripcion obtenida correctamente" << endl;

  // Verificar que la inscripción se haya agregado correctamente con getInscripciones
  Inscripcion** inscripciones = TC005->getInscripciones();
  bool inscripcionEncontrada = false;
  for (int i = 0; i < TC005->getCantInscripciones(); i++) {
    if (inscripciones[i]->getSocio()->getCI() == "12345678") {
      inscripcionEncontrada = true;
      break;
    }
  }
  if (inscripcionEncontrada) { cout << "TC-005 Inscripcion encontrada correctamente - getInscripciones" << endl; }
  else { throw runtime_error("TC-005 Error: Inscripcion no encontrada mediante getInscripciones"); }

  cout << "Todos los tests pasaron correctamente" << endl;
}