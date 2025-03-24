#include "./dtSpinning.h"
#include <stdexcept>
using namespace std;

DtSpinning::DtSpinning() {
  throw invalid_argument("Constructor vacio no permitido\n");
}

DtSpinning::DtSpinning(int id, string nom, Turno turn, int cantBicicletas) : DtClase(id, nom, turn) {
  if (cantBicicletas > 50 || cantBicicletas < 1) {
    throw invalid_argument("Cantidad de bicicletas invalida (1-50)\n");
  }
  this->cantBicicletas = cantBicicletas;
}

int DtSpinning::getCantBicicletas() {
  return this->cantBicicletas;
}

DtSpinning::~DtSpinning() {}
