#include "dtFecha.h"
#include <stdexcept>
using namespace std;

/*
  * @brief Constructor for the DtFecha class with default values.
  * 
  * Initializes a DtFecha object with default values for day, month, and year.
*/
DtFecha::DtFecha() {
  this->dia = MIN_DIAS;
  this->mes = MIN_MESES;
  this->anio = MIN_ANIO;
}

/*
  * @brief Constructor for the DtFecha class with specified values.
  * 
  * Initializes a DtFecha object with the specified day, month, and year.
  * Throws an exception if the date is invalid.
  * 
  * @param dia The day of the date.
  * @param mes The month of the date.
  * @param anio The year of the date.
*/
DtFecha::DtFecha(int dia, int mes, int anio) {
  if (dia < MIN_DIAS || dia > MAX_DIAS || mes < MIN_MESES || mes > MAX_MESES || anio < MIN_ANIO) {
    throw invalid_argument(ERROR_FECHA_INVALIDA);
  }
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

/*
  * @brief Returns the day of the date.
  * 
  * @return The day of the date as an integer.
*/
int DtFecha::getDia() {
  return this->dia;
}

/*
  * @brief Returns the month of the date.
  * 
  * @return The month of the date as an integer.
*/
int DtFecha::getMes() {
  return this->mes;
}

/*
  * @brief Returns the year of the date.
  * 
  * @return The year of the date as an integer.
*/
int DtFecha::getAnio() {
  return this->anio;
}

/*
  * @brief Compares two DtFecha objects for equality.
  * 
  * @param other The other DtFecha object to compare with.
  * @return true if the dates are equal, false otherwise.
*/
bool DtFecha::operator==(const DtFecha& other) const {
  return this->dia == other.dia && this->mes == other.mes && this->anio == other.anio;
}

/*
  * @brief Overloads the output operator for the DtFecha class.
  * 
  * @param os The output stream.
  * @param dt The DtFecha object to be printed.
  * @return The output stream with the formatted date.
*/
ostream& operator<<(ostream& os, const DtFecha& dt) {
  os << dt.dia << "/" << dt.mes << "/" << dt.anio;
  return os;
}

/*
  * @brief Destructor for the DtFecha class.
  * 
  * Cleans up any resources used by the DtFecha object.
*/
DtFecha::~DtFecha() {}
