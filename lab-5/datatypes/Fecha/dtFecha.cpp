#include "dtFecha.h"
#include <stdexcept>
using namespace std;

dtFecha::dtFecha()
{
    this->dia = MIN_DIAS;
    this->mes = MIN_MESES;
    this->anio = MIN_ANIO;
}

dtFecha::dtFecha(int horas, int mes, int anio)
{
    if (dia < MIN_HORAS || dia > MAX_DIAS || mes < MIN_MESES || mes > MAX_MESES || anio < MIN_ANIO)
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
};

int dtFecha::getDia()
{
    return this->dia;
};

int dtFecha::getMes()
{
    return this->mes;
};

int dtFecha::getAnio()
{
    return this->anio;
}

bool dtFecha::operator==(const dtFecha &other) const
{
    return this->dia == other.dia && this->mes == other.mes && this->anio == other.anio;
}

ostream &operator<<(ostream &os, const dtFecha &dt)
{
    os << dt.dia << "/" << dt.mes << "/" << dt.anio;
    return os;
}

dtFecha::~dtFecha() {}