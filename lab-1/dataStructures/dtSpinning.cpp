#include "./dtSpinning.h"
#include <stdexcept>
using namespace std;

DtSpinning::DtSpinning() {
  throw invalid_argument(ERROR_CONSTRUCTOR_VACIO);
}

DtSpinning::DtSpinning(int id, string nom, Turno turn, int cantBicicletas) : DtClase(id, nom, turn) {
  if (cantBicicletas > MAX_BICICLETAS || cantBicicletas < MIN_BICICLETAS) {
    throw invalid_argument(ERROR_CANT_BICICLETA_INVALIDA);
  }
  this->cantBicicletas = cantBicicletas;
}

int DtSpinning::getCantBicicletas() {
  return this->cantBicicletas;
}

DtSpinning::~DtSpinning() {}
