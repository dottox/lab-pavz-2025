#include "dtSocio.h"

DtSocio::DtSocio(string ci, string nombre) {
  stoi(ci);
  if(ci.length() != CI_LENGTH) {
    throw invalid_argument(ERROR_CI_INVALIDA);
  }
  if(nombre.length() < NOMBRE_MIN_LENGTH) {
    throw invalid_argument(ERROR_NOMBRE_INVALIDO);
  }
  this->ci = ci;
  this->nombre = nombre;
}

string DtSocio::getCi() {
  return this->ci;
}

string DtSocio::getNombre() {
  return this->nombre;
}

DtSocio::~DtSocio() {}
