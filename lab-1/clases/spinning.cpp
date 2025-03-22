#include "spinning.h"

Spinning::Spinning(int id, string nom, Turno t, int cantBici) : Clase(id, nom, t) {
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

Spinning::~Spinning() {
    cout << "Spinning destruído" << endl;
};
