#include "./dtClase.h"
#include <stdexcept>
using namespace std;

DtClase::DtClase() {
  throw invalid_argument("Constructor vacio no permitido\n");
}

DtClase::DtClase(int id, string nombre, Turno turn) {
  if (turn < Manana || turn > Noche) {
    throw invalid_argument("Turno invalido\n");
  }
  this->id = id;
  this->nombre = nombre;
  this->turno = turn;
}

int DtClase::getId() {
  return this->id;
}

string DtClase::getNombre() {
  return this->nombre;
}

Turno DtClase::getTurno() {
  return this->turno;
}

DtClase::~DtClase() {}
