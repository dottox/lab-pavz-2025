#include "spinning.h"

Spinning::Spinning(DtClase claseData, int cantBici) : Clase(claseData) {
    this->cantBicicletas = cantBici;
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
