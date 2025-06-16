#include "DtHora.h"
#include <stdexcept>
using namespace std;

DtHora::DtHora()
{
    this->hora = MIN_HORAS;
    this->minuto = MIN_MINUTOS;
    this->segundo = MIN_SEGUNDOS;
}

DtHora::DtHora(int hora, int minuto, int segundo)
{
    if (hora < MIN_HORAS || hora > MAX_HORAS || minuto < MIN_MINUTOS || minuto > MAX_MINUTOS || segundo < MIN_SEGUNDOS || segundo > MAX_SEGUNDOS)
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
};

int DtHora::getHora()
{
    return this->hora;
};

int DtHora::getMinuto()
{
    return this->minuto;
};

int DtHora::getSegundo()
{
    return this->segundo;
}

bool DtHora::operator==(const DtHora &other) const
{
    return this->hora == other.hora && this->minuto == other.minuto && this->segundo == other.segundo;
}

ostream &operator<<(ostream &os, const DtHora &Dt)
{
    os << Dt.hora << "-" << Dt.minuto << "-" << Dt.segundo;
    return os;
}

DtHora::~DtHora() {}