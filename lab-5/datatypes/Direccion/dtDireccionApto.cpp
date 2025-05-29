#include "dtDireccionApto.h"

dtDireccionApto::dtDireccionApto(string calle, int numero, string entreCalles, string nombre, int numeroApto) : dtDireccion(calle, numero, entreCalles), nombre(nombre), numeroApto(numeroApto)
{
    this->nombre = nombre;
    this->numeroApto = numeroApto;
};

string dtDireccionApto::getNombre()
{
    return nombre;
}

int dtDireccionApto::getNumeroApto()
{
    return numeroApto;
}

dtDireccionApto::~dtDireccionApto()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}