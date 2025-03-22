#include "clase.h"

Clase::Clase(int id, string nom, Turno t){
    this->id = id;
    this->nombre = nom;
    this->turno = t;
};

int Clase::getId(){
    return this->id;
};

Clase::~Clase(){
    cout << "Clase: " << this->getId() << "destruida" << endl;
};