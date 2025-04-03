#include "./dtSpinning.h"
#include <stdexcept>
using namespace std;


/*
  * @brief Constructor for the DtSpinning class with parameters.
  * 
  * Initializes a DtSpinning object with the specified ID, name, turn, and number of bicycles.
  * Validates the number of bicycles and throws an exception if invalid.
  * 
  * @param id The ID of the spinning class.
  * @param nom The name of the spinning class.
  * @param turn The turn of the spinning class (morning, afternoon, or night).
  * @param cantBicicletas The number of bicycles available in the spinning class.
*/
DtSpinning::DtSpinning(int id, string nom, Turno turn, int cantBicicletas) : DtClase(id, nom, turn, cantBicicletas) {
  // Validar la cantidad de bicicletas
  if (cantBicicletas > MAX_BICICLETAS || cantBicicletas < MIN_BICICLETAS) {
    throw invalid_argument(ERROR_CANT_BICICLETA_INVALIDA);
  }
  this->cantBicicletas = cantBicicletas;
}

/*
  * @brief Sets the number of bicycles available in the spinning class.
  * 
  * @param cantBicicletas The new number of bicycles available in the spinning class.
  * @throws invalid_argument if the number of bicycles is invalid.
*/
int DtSpinning::getCantBicicletas() {
  return this->cantBicicletas;
}

/*
  * @brief Overloads the output operator for the DtSpinning class.
  * 
  * @param os The output stream.
  * @param dt The DtSpinning object to be printed.
  * @return The output stream with the formatted data.
*/
ostream& operator<<(ostream& os, const DtSpinning& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: " << dt.turno << endl;
  os << "Cantidad de bicicletas: " << dt.cantBicicletas << endl;
  return os;
}

/*
  * @brief Destructor for the DtSpinning class.
  * 
  * Cleans up any resources used by the DtSpinning object.
*/
DtSpinning::~DtSpinning() {}
