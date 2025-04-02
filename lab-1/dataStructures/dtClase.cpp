#include "./dtClase.h"
#include <stdexcept>
using namespace std;

DtClase::DtClase() {
  throw invalid_argument(ERROR_CONSTRUCTOR_VACIO);
}

DtClase::DtClase(int id, string nombre, Turno turn, int cantCupos) {
  if (turn < Manana || turn > Noche) {
    throw invalid_argument(ERROR_TURNO_INVALIDO);
  }

  if(id < 0) {
    throw invalid_argument(ERROR_ID_INVALIDO);
  }
  this->id = id;
  this->nombre = nombre;
  this->turno = turn;
  this->cantCupos = cantCupos;
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

int DtClase::getCupo() {
  return this->cantCupos;
}

ostream& operator<<(ostream& os, const DtClase& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: ";
  switch(dt.turno) {
    case Manana:
      os << "Manana";
      break;
    case Tarde:
      os << "Tarde";
      break;
    case Noche:
      os << "Noche";
      break;
  }
  os << endl;
  return os;
}

DtClase::~DtClase() {}
