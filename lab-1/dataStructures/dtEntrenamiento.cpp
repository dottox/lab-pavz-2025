#include "dtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) 
  : DtClase(id, nom, turn) {
  this->enRambla = b;
}

bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

DtEntrenamiento::~DtEntrenamiento() {}
