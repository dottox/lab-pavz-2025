#include "spinning.h"


Spinning::Spinning(DtSpinning claseData) : Clase(claseData) {
    this->cantBicicletas = claseData.getCantBicicletas();
};

int Spinning::cupo() {
    return this->cantCupo;
};

void Spinning::setCantBicicletas(int cantBici) {
  if (cantBici > MAX_BICICLETAS || cantBici < MIN_BICICLETAS) {
    throw invalid_argument(ERROR_CANT_BICICLETA_INVALIDA);
  }
  this->cantBicicletas = cantBici;
};

int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
};

Spinning::~Spinning(){};
