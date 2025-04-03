#include "dtEntrenamiento.h"

/*
  * @brief Constructor for the DtEntrenamiento class with parameters.
  * 
  * Initializes a DtEntrenamiento object with the specified ID, name, turn, and
  * whether it is in Rambla or not. The number of spots is set based on the
  * location (CUPOS_RAMBLA or CUPOS_NO_RAMBLA).
  * 
  * @param id The ID of the class.
  * @param nom The name of the class.
  * @param turn The turn of the class (morning, afternoon, or night).
  * @param b Indicates whether the class is in Rambla or not.
*/
DtEntrenamiento::DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn, b ? CUPOS_RAMBLA : CUPOS_NO_RAMBLA){
  // Validar el turno
  this->enRambla = b;
}

/*
  * @brief Returns whether the class is in Rambla or not.
  * 
  * @return true if the class is in Rambla, false otherwise.
*/
bool DtEntrenamiento::getRambla() {
  return this->enRambla;
}

/*
  * @brief Overloads the output operator for the DtEntrenamiento class.
  * 
  * @param os The output stream.
  * @param dt The DtEntrenamiento object to be printed.
  * @return The output stream with the formatted data.
*/
ostream& operator<<(ostream& os, const DtEntrenamiento& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: " << dt.turno << endl;
  return os;
}

/*
  * @brief Destructor for the DtEntrenamiento class.
  * 
  * Cleans up any resources used by the DtEntrenamiento object.
*/
DtEntrenamiento::~DtEntrenamiento() {}
