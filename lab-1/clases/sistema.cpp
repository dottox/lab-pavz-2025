#include "sistema.h"

Sistema::Sistema(){
  this->MAXSOCIOS = MAX_SOCIOS;
  this->cantSocios = DEFAULT_SOCIOS;
  this->MAXCLASES = MAX_CLASES;
  this->cantClases = DEFAULT_CLASES;
  this->socios = new Socio*[this->MAXSOCIOS];
  this->clases = new Clase*[this->MAXCLASES];
};

Sistema::Sistema(int socios, int clases){
  this->MAXSOCIOS = socios;
  this->cantSocios = DEFAULT_SOCIOS;
  this->MAXCLASES = clases;
  this->cantClases = DEFAULT_CLASES;
  this->socios = new Socio*[this->MAXSOCIOS];
  this->clases = new Clase*[this->MAXCLASES];
};

void Sistema::agregarSocio(string ci, string nombre){
    if(this->cantSocios >= this->MAXSOCIOS){
      throw invalid_argument(ERROR_LIMITE_SOCIOS);
    }
    if(getSocio(ci) != nullptr){
      throw invalid_argument(ERROR_SOCIO_EXISTENTE);
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
    return nullptr;
}

Clase* Sistema::getClase(int idClase){
  for(int i = 0; i < cantClases; i++){
    if(clases[i]->getId() == idClase){
      return clases[i];
    }
  }
  return nullptr;
}

int Sistema::getCantSocios(){
  return this->cantSocios;
}

int Sistema::getCantClases(){
  return this->cantClases;
}

void Sistema::agregarInscripcion(string ciSocio, int idClase, DtFecha fecha){
  Socio* socio = getSocio(ciSocio);
  Clase* clase = getClase(idClase);
  if(socio == nullptr) throw invalid_argument(ERROR_NO_SOCIO_CI);
  if(clase == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
  if(clase->getInscripcion(ciSocio) != nullptr) throw invalid_argument(ERROR_INSCRIPCION_EXISTENTE);;
  
  Inscripcion* inscripcion = new Inscripcion(fecha, socio);
  clase->agregarInscripcion(inscripcion);  
}

void Sistema::agregarClase(DtSpinning clase) {
  if (this->cantClases >= this->MAXCLASES) throw invalid_argument(ERROR_LIMITE_CLASES);
  if (getClase(clase.getId()) != nullptr) throw invalid_argument(ERROR_CLASE_EXISTENTE_ID);
  Spinning* spinning = new Spinning(clase);
  this->clases[cantClases] = spinning;
  this->cantClases++;
};

void Sistema::agregarClase(DtEntrenamiento clase) {
  if (this->cantClases >= this->MAXCLASES) {
    throw invalid_argument(ERROR_LIMITE_CLASES);
  }
  if (getClase(clase.getId()) != nullptr){
    throw invalid_argument(ERROR_CLASE_EXISTENTE_ID);
  }
  Entrenamiento * entrenamiento = new Entrenamiento(clase);
  this->clases[cantClases] = entrenamiento;
  this->cantClases++;
};

void Sistema::borrarInscripcion(string ciSocio, int idClase){
    Socio* socio = getSocio(ciSocio);
    Clase* clase = getClase(idClase);
    if(socio == nullptr) throw invalid_argument(ERROR_NO_SOCIO_CI);
    if(clase == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
    clase->borrarInscripcion(ciSocio,idClase);
}

void Sistema::listarClases(){
  cout << "---------- [CLASES] ----------" << endl;
  cout << "--- [ ID | Nombre | Cupo ] ---" << endl;
  for(int i = 0; i < this->cantClases; i++){
    cout << this->clases[i]->getId() << " " << this->clases[i]->getNombre() << " " << this->clases[i]->cupo() << endl;
  }
  cout << "-------[Fin de la lista]------" << endl;

}

void Sistema::listarSocios(){
  cout << "---------- [Socios] ----------" << endl;
  cout << "------- [ CI | Nombre ] ------" << endl;
  for(int i = 0; i < this->cantSocios; i++){
    cout << this->socios[i]->getCI() << " " << this->socios[i]->getNombre() << endl;
  }
  cout << "-------[Fin de la lista]------" << endl;
}

DtSocio** Sistema::obtenerInfoSociosPorClase(int idClase,int & cantSocios){
  if(getClase(idClase) == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
  if(getClase(idClase)->getCantInscripciones() < cantSocios || cantSocios <= 0) throw invalid_argument(ERROR_NO_SOCIOS);
  Inscripcion** inscripciones = getClase(idClase)->getInscripciones();
  DtSocio** dtSocios = new DtSocio*[cantSocios];
  for(int i = 0; i < cantSocios; i++){
    dtSocios[i] = new DtSocio(inscripciones[i]->getSocio()->getCI(), inscripciones[i]->getSocio()->getNombre());
  }
  return dtSocios;
}

DtClase Sistema::obtenerClase(int idClase){
  if(getClase(idClase) == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
  DtClase dtClase = DtClase(getClase(idClase)->getId(), getClase(idClase)->getNombre(), getClase(idClase)->getTurno(), getClase(idClase)->cupo());
  return dtClase;
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