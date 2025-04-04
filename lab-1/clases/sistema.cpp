#include "sistema.h"

/*
  * @brief Constructor for the Sistema class.
  * 
  * Initializes a Sistema object with default values for the maximum number of
  * socios and classes, and allocates memory for the arrays of socios and classes.
*/
Sistema::Sistema(){
  this->MAXSOCIOS = MAX_SOCIOS;
  this->cantSocios = DEFAULT_SOCIOS;
  this->MAXCLASES = MAX_CLASES;
  this->cantClases = DEFAULT_CLASES;
  this->socios = new Socio*[this->MAXSOCIOS];
  this->clases = new Clase*[this->MAXCLASES];
};

/*
  * @brief Constructor for the Sistema class with specified maximum number of socios and classes.
  * 
  * Initializes a Sistema object with the specified maximum number of socios and classes,
  * and allocates memory for the arrays of socios and classes.
  * 
  * @param socios The maximum number of socios.
  * @param clases The maximum number of classes.
*/
Sistema::Sistema(int socios, int clases){
  this->MAXSOCIOS = socios;
  this->cantSocios = DEFAULT_SOCIOS;
  this->MAXCLASES = clases;
  this->cantClases = DEFAULT_CLASES;
  this->socios = new Socio*[this->MAXSOCIOS];
  this->clases = new Clase*[this->MAXCLASES];
};

/*
  * @brief Destructor for the Sistema class.
  * 
  * Cleans up the memory allocated for the arrays of socios and classes.
*/
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

/*
  * @brief Returns a pointer to the Socio object with the specified CI.
  * 
  * @param ci The CI of the socio to be retrieved.
  * @return A pointer to the Socio object with the specified CI, or nullptr if not found.
*/
Socio* Sistema::getSocio(string ci){
    for(int i = 0; i < cantSocios; i++){
        if(socios[i]->getCI() == ci){
        return socios[i];
        }
    }
    return nullptr;
}

/*
  * @brief Returns a pointer to the Clase object with the specified ID.
  * 
  * @param idClase The ID of the class to be retrieved.
  * @return A pointer to the Clase object with the specified ID, or nullptr if not found.
*/
Clase* Sistema::getClase(int idClase){
  for(int i = 0; i < cantClases; i++){
    if(clases[i]->getId() == idClase){
      return clases[i];
    }
  }
  return nullptr;
}

/*
  * @brief Returns the number of socios in the system.
  * 
  * @return The number of socios in the system.
*/
int Sistema::getCantSocios(){
  return this->cantSocios;
}

/*
  * @brief Returns the number of classes in the system.
  * 
  * @return The number of classes in the system.
*/
int Sistema::getCantClases(){
  return this->cantClases;
}

/*
  * @brief Adds an inscription for a socio to a class.
  * 
  * @param ciSocio The CI of the socio to be inscribed.
  * @param idClase The ID of the class to which the socio is to be inscribed.
  * @param fecha The date of the inscription.
  * @throws invalid_argument if the socio or class is not found, or if the inscription already exists.
*/
void Sistema::agregarInscripcion(string ciSocio, int idClase, DtFecha fecha){
  Socio* socio = getSocio(ciSocio);
  Clase* clase = getClase(idClase);
  if(socio == nullptr) throw invalid_argument(ERROR_NO_SOCIO_CI);
  if(clase == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
  if(clase->getInscripcion(ciSocio) != nullptr) throw invalid_argument(ERROR_INSCRIPCION_EXISTENTE);;
  
  Inscripcion* inscripcion = new Inscripcion(fecha, socio);
  clase->agregarInscripcion(inscripcion);  
}

/*
  * @brief Adds a spinning class to the system.
  * 
  * @param clase The spinning class to be added.
  * @throws invalid_argument if the maximum number of classes is reached or if the class ID already exists.
*/
void Sistema::agregarClase(DtSpinning clase) {
  if (this->cantClases >= this->MAXCLASES) throw invalid_argument(ERROR_LIMITE_CLASES);
  if (getClase(clase.getId()) != nullptr) throw invalid_argument(ERROR_CLASE_EXISTENTE_ID);
  Spinning* spinning = new Spinning(clase);
  this->clases[cantClases] = spinning;
  this->cantClases++;
};

/*
  * @brief Adds a training class to the system.
  * 
  * @param clase The training class to be added.
  * @throws invalid_argument if the maximum number of classes is reached or if the class ID already exists.
*/
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

/*
  * @brief Deletes an inscription for a socio from a class.
  * 
  * @param ciSocio The CI of the socio whose inscription is to be deleted.
  * @param idClase The ID of the class from which the inscription is to be deleted.
  * @throws invalid_argument if the socio or class is not found.
*/
void Sistema::borrarInscripcion(string ciSocio, int idClase){
    Socio* socio = getSocio(ciSocio);
    Clase* clase = getClase(idClase);
    if(socio == nullptr) throw invalid_argument(ERROR_NO_SOCIO_CI);
    if(clase == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
    clase->borrarInscripcion(ciSocio);
}

/*
  * @brief Lists all classes in the system.
  * 
  * Displays the ID, name, and available spots for each class.
*/
void Sistema::listarClases(){
  cout << "---------- [CLASES] ----------" << endl;
  cout << "--- [ ID | Nombre | Cupo ] ---" << endl;
  for(int i = 0; i < this->cantClases; i++){
    cout << this->clases[i]->getId() << " " << this->clases[i]->getNombre() << " " << this->clases[i]->cupo() << endl;
  }
  cout << "-------[Fin de la lista]------" << endl;

}

/*
  * @brief Lists all socios in the system.
  * 
  * Displays the CI and name of each socio.
*/
void Sistema::listarSocios(){
  cout << "---------- [Socios] ----------" << endl;
  cout << "------- [ CI | Nombre ] ------" << endl;
  for(int i = 0; i < this->cantSocios; i++){
    cout << this->socios[i]->getCI() << " " << this->socios[i]->getNombre() << endl;
  }
  cout << "-------[Fin de la lista]------" << endl;
}

/*
  * @brief Returns an array of DtSocio objects representing the socios inscribed in a class.
  * 
  * @param idClase The ID of the class for which to retrieve the socios.
  * @param cantSocios The number of socios to retrieve.
  * @return An array of pointers to DtSocio objects representing the socios inscribed in the class.
  * @throws invalid_argument if the class ID is not found or if there are not enough socios.
*/
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

/*
  * @brief Returns a DtClase object representing the class with the specified ID.
  * 
  * @param idClase The ID of the class to be retrieved.
  * @return A DtClase object representing the class with the specified ID.
  * @throws invalid_argument if the class ID is not found.
*/
DtClase Sistema::obtenerClase(int idClase){
  if(getClase(idClase) == nullptr) throw invalid_argument(ERROR_NO_CLASE_ID);
  DtClase dtClase = DtClase(getClase(idClase)->getId(), getClase(idClase)->getNombre(), getClase(idClase)->getTurno(), getClase(idClase)->cupo());
  return dtClase;
}

/*
  * @brief Destructor for the Sistema class.
  * 
  * Cleans up the memory allocated for the arrays of socios and classes.
*/
Sistema::~Sistema(){
    delete[] socios;
    delete[] clases;
}