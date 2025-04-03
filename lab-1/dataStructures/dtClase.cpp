#include "./dtClase.h"
#include <stdexcept>
using namespace std;

/*
  * @brief Constructor for the DtClase class with parameters.
  * 
  * Initializes a DtClase object with the specified ID, name, turn, and number of spots.
  * 
  * @param id The ID of the class.
  * @param nombre The name of the class.
  * @param turn The turn of the class (morning, afternoon, or night).
  * @param cantCupos The number of spots available in the class.
*/
DtClase::DtClase(int id, string nombre, Turno turn, int cantCupos) {
  if (turn < Manana || turn > Noche) {
    throw invalid_argument(ERROR_TURNO_INVALIDO);
  }

  if(id < 0) {
    throw invalid_argument(ERROR_ID_INVALIDO);
  }
  this->id = id;
  this->nombre = nombre;
  this->turno = turn;
  this->cantCupos = cantCupos;
}

int DtClase::getId() {
  return this->id;
}

string DtClase::getNombre() {
  return this->nombre;
}

Turno DtClase::getTurno() {
  return this->turno;
}

int DtClase::getCupo() {
  return this->cantCupos;
}

ostream& operator<<(ostream& os, const DtClase& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: " << dt.turno << endl;
  return os;
}

DtClase::~DtClase() {}
