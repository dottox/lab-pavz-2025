#include "dtFecha.h"
#include <stdexcept>
using namespace std;

DtFecha::DtFecha() {
  throw invalid_argument("Constructor vacio no permitido\n");
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
  return dia == other.dia && mes == other.mes && anio == other.anio;
}

DtFecha::~DtFecha() {}
