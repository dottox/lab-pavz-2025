#include "DtPlato.h"

#include "../../enums/TipoProducto.h"

DtPlato::DtPlato(){}

DtPlato::DtPlato(char* codigo, string descripcion, float precio) : DtProducto(codigo, descripcion, TipoPlato, precio)
{
}

DtPlato::~DtPlato() {}