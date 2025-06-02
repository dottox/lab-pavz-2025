#include "dtAsignacion.h"

dtAsignacion::dtAsignacion(){}

dtAsignacion::dtAsignacion(int numeroMozo, int numeroMesa)
{
    this->numeroMozo = numeroMozo;
    this->numeroMesa = numeroMesa;
}

int dtAsignacion::getNumeroMozo()
{
    return this->numeroMozo;
}

int dtAsignacion::getNumeroMesa()
{
    return this->numeroMesa;
}

dtAsignacion::~dtAsignacion() {}