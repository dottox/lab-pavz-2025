#include "Inscripcion.h"

Inscripcion::Inscripcion(DtFecha date){
    this->fecha = date;
};

DtFecha Inscripcion::getFecha(){
    return this->fecha;
};

Inscripcion::~Inscripcion(){};	