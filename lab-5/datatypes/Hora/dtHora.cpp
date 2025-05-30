#include "dtHora.h"
#include <stdexcept>
using namespace std;

dtHora::dtHora()
{
    this->hora = MIN_HORAS;
    this->minuto = MIN_MINUTOS;
    this->segundo = MIN_SEGUNDOS;
}

dtHora::dtHora(int hora, int minuto, int segundo)
{
    if (hora < MIN_HORAS || hora > MAX_HORAS || minuto < MIN_MINUTOS || minuto > MAX_MINUTOS || segundo < MIN_SEGUNDOS || segundo > MAX_SEGUNDOS)
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    {
        throw invalid_argument(ERROR_FECHA_INVALIDA);
    }
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
};

int dtHora::getHora()
{
    return this->hora;
};

int dtHora::getMinuto()
{
    return this->minuto;
};

int dtHora::getSegundo()
{
    return this->segundo;
}

bool dtHora::operator==(const dtHora &other) const
{
    return this->hora == other.hora && this->minuto == other.minuto && this->segundo == other.segundo;
}

ostream &operator<<(ostream &os, const dtHora &dt)
{
    os << dt.hora << "/" << dt.minuto << "/" << dt.segundo;
    return os;
}

dtHora::~dtHora() {}