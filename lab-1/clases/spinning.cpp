#include "spinning.h"


Spinning::Spinning(DtSpinning claseData) : Clase(claseData) {
    this->cantBicicletas = claseData.getCantBicicletas();
    this->cantCupo = claseData.getCupo();
};

int Spinning::cupo() {
    return this->cantCupo;
};

void Spinning::setCantBicicletas(int cantBici) {
    this->cantBicicletas = cantBici;
};

int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
};

Spinning::~Spinning(){};
