#include "dtEntrenamiento.h"

DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn, b ? CUPOS_RAMBLA : CUPOS_NO_RAMBLA){
  // Validar el turno
  if (turn < Manana || turn > Noche) {
    throw invalid_argument(ERROR_TURNO_INVALIDO);
  }
  
  this->enRambla = b;
}

bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

int DtEntrenamiento::getCupo() {
  return this->cantCupos;
}

DtEntrenamiento::~DtEntrenamiento() {}
