#include "DtFecha.h"
#include <stdexcept>
using namespace std;

DtFecha::DtFecha()
{
    this->dia = MIN_DIAS;
    this->mes = MIN_MESES;
    this->anio = MIN_ANIO;
}

DtFecha::DtFecha(int d, int m, int a)
{
    if (d < MIN_DIAS || d > MAX_DIAS || m < MIN_MESES || m > MAX_MESES || a < MIN_ANIO)
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    this->dia = d;
    this->mes = m;
    this->anio = a;
};

int DtFecha::getDia()
{
    return this->dia;
};

int DtFecha::getMes()
{
    return this->mes;
};

int DtFecha::getAnio()
{
    return this->anio;
}

bool DtFecha::operator==(const DtFecha &other) const
{
    return this->dia == other.dia && this->mes == other.mes && this->anio == other.anio;
}

bool DtFecha::operator>(const DtFecha &other) const
{
    if (this->anio > other.anio)
        return true;
    if (this->anio < other.anio)
        return false;
    if (this->mes > other.mes)
        return true;
    if (this->mes < other.mes)
        return false;
    return this->dia > other.dia;
}

bool DtFecha::operator>=(const DtFecha &other) const
{
    if (this->anio > other.anio)
        return true;
    if (this->anio < other.anio)
        return false;
    if (this->mes > other.mes)
        return true;
    if (this->mes < other.mes)
        return false;
    return this->dia >= other.dia;
}

bool DtFecha::operator<=(const DtFecha &other) const
{
    if (this->anio < other.anio)
        return true;
    if (this->anio > other.anio)
        return false;
    if (this->mes < other.mes)
        return true;
    if (this->mes > other.mes)
        return false;
    return this->dia <= other.dia;
}

ostream &operator<<(ostream &os, const DtFecha &Dt)
{
    os << Dt.dia << "/" << Dt.mes << "/" << Dt.anio;
    return os;
}

DtFecha::~DtFecha() {}