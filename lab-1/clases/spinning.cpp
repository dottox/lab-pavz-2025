#include "spinning.h"

int Spinning::cupo(int cantBicicletas){
    return cantBicicletas;
};
int Spinning::cupo(){
    return this->getCantBicicletas();
};

void Spinning::setCantBicicletas(int cantBicicletas){
    this->cantBicicletas=cantBicicletas;
};

int Spinning::getCantBicicletas(){
    return this->cantBicicletas;
};
