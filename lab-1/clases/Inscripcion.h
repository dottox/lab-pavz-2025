#include "Inscripcion.h"

Inscripcion::Inscripcion(DtFecha fecha){
    this->fecha = fecha;
};

DtFecha Inscripcion::getFecha(){
    return this->fecha;
};

Inscripcion::~Inscripcion(){
    cout << "Inscripcion del día: " << this->getFecha() << "destruida" << endl;
};	