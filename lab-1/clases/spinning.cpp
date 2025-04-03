#include "spinning.h"

/*
  * @brief Constructor for the Spinning class.
  * 
  * Initializes a Spinning object with the specified data.
  * 
  * @param claseData The data for the spinning class, represented as a DtSpinning object.
*/
Spinning::Spinning(DtSpinning claseData) : Clase(claseData) {
    this->cantBicicletas = claseData.getCantBicicletas();
};

/*
  * @brief Sets the number of bicycles for the spinning class.
  * 
  * @param cantBici The number of bicycles to set.
  * @throws invalid_argument if the number of bicycles is invalid.
*/
void Spinning::setCantBicicletas(int cantBici) {
  if (cantBici > MAX_BICICLETAS || cantBici < MIN_BICICLETAS) {
    throw invalid_argument(ERROR_CANT_BICICLETA_INVALIDA);
  }
  this->cantBicicletas = cantBici;
};

/*
  * @brief Returns the number of bicycles in the spinning class.
  * 
  * @return The number of bicycles in the spinning class.
*/
int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
};

/*
  * @brief Destructor for the Spinning class.
  * 
  * Cleans up the memory allocated for the Spinning object.
*/
Spinning::~Spinning(){};
