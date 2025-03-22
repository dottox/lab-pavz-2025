#include "spinning.h"

Spinning::Spinning(int id, string nom, Turno t, int cantBici) : Clase::Clase(id, nom, t) {
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
