#include "dtFecha.h"
#include <stdexcept>
using namespace std;

DtFecha::DtFecha() {
  this->dia = 1;
  this->mes = 1;
  this->anio = 1900;
  cout << "Se hizo una fecha por defecto" << endl;
}

DtFecha::DtFecha(int dia, int mes, int anio) {
  if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900) {
    throw invalid_argument("Fecha invalida\n");
  }
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

int DtFecha::getDia() {
  return this->dia;
}

int DtFecha::getMes() {
  return this->mes;
}

int DtFecha::getAnio() {
  return this->anio;
}

bool DtFecha::operator==(const DtFecha& other) const {
  return this->dia == other.dia && this->mes == other.mes && this->anio == other.anio;
}


DtFecha::~DtFecha() {}
