#include "dtFecha.h"
#include <stdexcept>
using namespace std;

dtFecha::dtFecha()
{
    this->dia = MIN_DIAS;
    this->mes = MIN_MESES;
    this->anio = MIN_ANIO;
}

dtFecha::dtFecha(int d, int m, int a)
{
    if (d < MIN_DIAS || d > MAX_DIAS || m < MIN_MESES || m > MAX_MESES || a < MIN_ANIO)
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    this->dia = d;
    this->mes = m;
    this->anio = a;
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