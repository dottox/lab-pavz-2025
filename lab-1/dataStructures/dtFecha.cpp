#include "dtFecha.h"
#include <stdexcept>
using namespace std;
DtFecha::DtFecha() {
  this->dia = MIN_DIAS;
  this->mes = MIN_MESES;
  this->anio = MIN_ANIO;
}

DtFecha::DtFecha(int dia, int mes, int anio) {
  if (dia < MIN_DIAS || dia > MAX_DIAS || mes < MIN_MESES || mes > MAX_MESES || anio < MIN_ANIO) {
    throw invalid_argument(ERROR_FECHA_INVALIDA);
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
