#include "DtPlato.h"

#include "../../enums/TipoProducto.h"

DtPlato::DtPlato(){}

DtPlato::DtPlato(char* codigo, string descripcion, float precio) : DtProducto(codigo, descripcion, TipoPlato, precio)
{
}

ostream& operator<<(ostream& os, const DtPlato& dtPlato)
{
    os << "Codigo: " << dtPlato.getCodigo() << ", Descripcion: " << dtPlato.getDescripcion()
       << ", Precio: $" << dtPlato.getPrecio();
    return os;
}

DtPlato::~DtPlato() {}