#include "dtSocio.h"

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

string DtSocio::getCi() {
  return this->ci;
}

string DtSocio::getNombre() {
  return this->nombre;
}

ostream& operator<<(ostream& os, const DtSocio& dt) {
  os << "Nombre: " << dt.nombre << endl;
  os << "CI: " << dt.ci << endl;
  return os;
}

DtSocio::~DtSocio() {}
