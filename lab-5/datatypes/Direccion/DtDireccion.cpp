#include "DtDireccion.h"

DtDireccion::DtDireccion() {}

DtDireccion::DtDireccion(string calle, int numero, string entreCalles)
{
    this->calle = calle;
    this->numero = numero;
    this->entreCalles = entreCalles;
}

string DtDireccion::getCalle()
{
    return this->calle;
}

int DtDireccion::getNumero()
{
    return this->numero;
}

string DtDireccion::getEntreCalles()
{
    return this->entreCalles;
}

ostream& operator<<(ostream& os, const DtDireccion& dtDireccion)
{
    os << "Calle: " << dtDireccion.calle << ", Numero: " << dtDireccion.numero
       << ", Entre Calles: " << dtDireccion.entreCalles;
    return os;
}

DtDireccion::~DtDireccion()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is used, so nothing specific to clean up.
}