#include "spinning.h"

Spinning::Spinning() : Clase(){
    throw invalid_argument("No se puede crear un Spinning sin datos");
};

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
