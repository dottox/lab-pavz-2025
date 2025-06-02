#include "DtAsignacion.h"

DtAsignacion::DtAsignacion(){}

DtAsignacion::DtAsignacion(int numeroMozo, int numeroMesa)
{
    this->numeroMozo = numeroMozo;
    this->numeroMesa = numeroMesa;
}

int DtAsignacion::getNumeroMozo()
{
    return this->numeroMozo;
}

int DtAsignacion::getNumeroMesa()
{
    return this->numeroMesa;
}

DtAsignacion::~DtAsignacion() {}