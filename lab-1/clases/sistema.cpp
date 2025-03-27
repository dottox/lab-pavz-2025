#include "sistema.h"

Sistema::Sistema(){
    this->cantSocios = DEFAULT_SOCIOS;
    this->cantClases = DEFAULT_CLASES;
    this->socios = new Socio*[MAX_SOCIOS];
    this->clases = new Clase*[MAX_CLASES];
};

// void agregarSocio(string ci, string nombre)
// Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepción
// std::invalid_argument.
void Sistema::agregarSocio(string ci, string nombre){
    if(this->cantSocios >= MAX_SOCIOS){
      throw invalid_argument(ERROR_LIMITE_SOCIOS);
    }
    for(int i = 0; i < cantSocios; i++){
      if(socios[i]->getCI() == ci){
        throw invalid_argument(ERROR_MISMA_CI);
      }
    }
    DtSocio socioData = DtSocio(ci, nombre);
    this->socios[cantSocios] = new Socio(socioData);
    this->cantSocios++;
}

Socio* Sistema::getSocio(string ci){
    for(int i = 0; i < cantSocios; i++){
        if(socios[i]->getCI() == ci){
        return socios[i];
        }
    }
    throw invalid_argument(ERROR_NO_SOCIO_CI);
}

Clase* Sistema::getClase(int idClase){
  for(int i = 0; i < cantClases; i++){
    if(clases[i]->getId() == idClase){
    return clases[i];
    }
  }
  throw invalid_argument(ERROR_NO_CLASE_ID);
}

bool Sistema::buscarClase(int idClase){
  for(int i = 0; i < cantClases; i++){
    if(clases[i]->getId() == idClase){
      return true;
    }
  }
  return false;
}

void Sistema::agregarInscripcion(string ciSocio, int idClase, DtFecha fecha){
  Socio* socio = getSocio(ciSocio);
  Clase* clase = getClase(idClase);

  if(clase->cupo() == 0){throw invalid_argument(ERROR_CUPOS_CERO);}

  //Inscripcion existe
  Inscripcion** inscripcionesClase = clase->getInscripciones();

  for (int i=0; i < clase->getCantInscripciones(); i++){
    if (inscripcionesClase[i]->getSocio()->getCI() == ciSocio && inscripcionesClase[i]->getFecha() == fecha){
      throw invalid_argument(ERROR_INSCRIPCION_EXISTENTE);
    }
  }

  Inscripcion* inscripcion = new Inscripcion(fecha, socio);
  clase->agregarInscripcion(inscripcion);  
  DtFecha date = inscripcionesClase[0]->getFecha();
}

void Sistema::agregarClase(DtSpinning clase) {
  if (this->cantClases >= MAX_CLASES) {
    throw invalid_argument(ERROR_LIMITE_CLASES);
    
  }
  if (buscarClase(clase.getId())){
    throw invalid_argument(ERROR_CLASE_EXISTENTE_ID);
  }
  Spinning* spinning = new Spinning(clase);
  this->clases[cantClases] = spinning;
  this->cantClases++;
};

void Sistema::agregarClase(DtEntrenamiento clase) {
  if (this->cantClases >= MAX_CLASES) {
    throw invalid_argument(ERROR_LIMITE_CLASES);
  }
  if (buscarClase(clase.getId())){
    throw invalid_argument(ERROR_CLASE_EXISTENTE_ID);
  }
  Entrenamiento * entrenamiento = new Entrenamiento(clase);
  this->clases[cantClases] = entrenamiento;
  this->cantClases++;
};

void Sistema::listarClases(){
  cout << "-------- CLASES -----------" << endl;
  for(int i = 0; i < this->cantClases; i++){
    cout << this->clases[i]->getId() << " " << this->clases[i]->getNombre() << endl;
  }
  cout << "---------------------------" <<endl;
}

void Sistema::listarSocios(){
  cout << "-------- SOCIOS -----------" << endl;
  for(int i = 0; i < this->cantSocios; i++){
    cout << this->socios[i]->getCI() << " " << this->socios[i]->getNombre() << endl;
  }
  cout << "---------------------------" <<endl;
}


Sistema::~Sistema(){
    for(int i = 0; i < cantSocios; i++){
        delete socios[i];
    }
    delete[] socios;
    
    for(int i = 0; i < cantClases; i++){
        delete clases[i];
    }
    delete[] clases;
}