#include "dtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn, b ? CUPOS_RAMBLA : CUPOS_NO_RAMBLA){
  this->enRambla = b;
}

bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

int DtEntrenamiento::getCupo() {
  return this->cantCupo;
}

DtEntrenamiento::~DtEntrenamiento() {}
