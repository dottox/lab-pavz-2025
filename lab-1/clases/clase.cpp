#include "clase.h"

Clase::Clase(DtClase * claseData){
    this->id = claseData->getId();
    this->nombre = claseData->getNombre();
    this->turno = claseData->getTurno();
};

int Clase::getId(){
    return this->id;
};

string Clase::getNombre(){
    return this->nombre;
};

Turno Clase::getTurno(){
    return this->turno;
};

Clase::~Clase(){
    cout << "Clase: " << this->getId() << " destruida" << endl;
};