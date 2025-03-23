#include "spinning.h"

Spinning::Spinning(DtSpinning claseData) : Clase(claseData) {
    this->cantBicicletas = claseData.getCantBicicletas();
};

int Spinning::cupo() {
    return this->getCantBicicletas();
};

void Spinning::setCantBicicletas(int cantBici) {
    this->cantBicicletas = cantBici;
};

int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
};

Spinning::~Spinning() {};
