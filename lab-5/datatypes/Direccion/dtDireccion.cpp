#include "dtDireccion.h"

dtDireccion::dtDireccion() {}

dtDireccion::dtDireccion(string calle, int numero, string entreCalles)
{
    this->calle = calle;
    this->numero = numero;
    this->entreCalles = entreCalles;
}

string dtDireccion::getCalle()
{
    return this->calle;
}

int dtDireccion::getNumero()
{
    return this->numero;
}

string dtDireccion::getEntreCalles()
{
    return this->entreCalles;
}

dtDireccion::~dtDireccion()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is used, so nothing specific to clean up.
}