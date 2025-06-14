#include "DtDireccionApto.h"

DtDireccionApto::DtDireccionApto(string calle, string numero, string entreCalles, string nombre, string numeroApto) : DtDireccion(calle, numero, entreCalles), nombre(nombre), numeroApto(numeroApto)
{
    this->nombre = nombre;
    this->numeroApto = numeroApto;
};

string DtDireccionApto::getNombre()
{
    return nombre;
}

string DtDireccionApto::getNumeroApto()
{
    return numeroApto;
}

ostream& operator<<(ostream& os, const DtDireccionApto& dtDireccionApto)
{
    os << static_cast<const DtDireccion&>(dtDireccionApto) << endl 
       << "Edificio: " << dtDireccionApto.nombre << endl 
       << "Numero Apto: " << dtDireccionApto.numeroApto << endl;
    return os;
}

DtDireccionApto::~DtDireccionApto()
{
    // Destructor implementation (if needed)
    // Currently, no dynamic memory allocation is done, so nothing specific to clean up.
}