#include "dtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn){
  this->enRambla = b; 
  this->cantCupo = b ? CUPOS_RAMBLA : CUPOS_NO_RAMBLA;
}

bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

int DtEntrenamiento::getCupo() {
  return this->cantCupo;
}

DtEntrenamiento::~DtEntrenamiento() {}
