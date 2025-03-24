#include "dtSocio.h"

DtSocio::DtSocio(string ci, string nombre) {
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
