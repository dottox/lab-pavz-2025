#include "dtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn, b ? CUPOS_RAMBLA : CUPOS_NO_RAMBLA){
  // Validar el turno
  this->enRambla = b;
}

bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

int DtEntrenamiento::getCupo() {
  return this->cantCupos;
}

ostream& operator<<(ostream& os, const DtEntrenamiento& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: " << dt.turno << endl;
  return os;
}

DtEntrenamiento::~DtEntrenamiento() {}
