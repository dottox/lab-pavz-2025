#include "clase.h"

Clase::Clase(DtClase claseData){
    this->id = claseData.getId();
    this->nombre = claseData.getNombre();
    this->turno = claseData.getTurno();
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

void Clase::agregarInscripcion(Inscripcion* inscripcion){
    this->inscripciones[this->cantInscripciones] = inscripcion;
    this->cantInscripciones++;
};

Inscripcion** Clase::getInscripciones(){
    return inscripciones;
};

int Clase::getCantInscripciones(){
    return this->cantInscripciones;
};

Clase::~Clase(){
    cout << "Clase: " << this->getId() << " destruida" << endl;
};