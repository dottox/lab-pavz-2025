#include "dtSocio.h"

/*
  * @brief Constructor for the DtSocio class with parameters.
  * 
  * Initializes a DtSocio object with the specified CI and name. Validates the
  * CI format and length, and throws an exception if invalid.
  * 
  * @param ci The CI of the socio.
  * @param nombre The name of the socio.
*/
DtSocio::DtSocio(string ci, string nombre) {
  try {
    stoi(ci);
  } catch (const invalid_argument&) {
    throw invalid_argument(ERROR_CI_INVALIDA);
  }

  if(ci.length() != CI_LENGTH || stoi(ci) < 0){
    throw invalid_argument(ERROR_CI_INVALIDA);
  }
  if(nombre.length() < NOMBRE_MIN_LENGTH) {
    throw invalid_argument(ERROR_NOMBRE_INVALIDO);
  }
  this->ci = ci;
  this->nombre = nombre;
}

/*
  * @brief Returns the CI of the socio.
  * 
  * @return The CI of the socio as a string.
*/
string DtSocio::getCi() {
  return this->ci;
}

/*
  * @brief Returns the name of the socio.
  * 
  * @return The name of the socio as a string.
*/
string DtSocio::getNombre() {
  return this->nombre;
}

/*
  * @brief Overloads the output operator for the DtSocio class.
  * 
  * @param os The output stream.
  * @param dt The DtSocio object to be printed.
  * @return The output stream with the formatted data.
*/
ostream& operator<<(ostream& os, const DtSocio& dt) {
  os << "Nombre: " << dt.nombre << endl;
  os << "CI: " << dt.ci << endl;
  return os;
}

/*
  * @brief Destructor for the DtSocio class.
  * 
  * Cleans up any resources used by the DtSocio object.
*/
DtSocio::~DtSocio() {}
