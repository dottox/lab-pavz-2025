#include "DtInforme.h"

DtInforme::DtInforme(float totalIngresos, IDictionary *ventas)
    : totalIngresos(totalIngresos), ventas(ventas)
{
    this->ventas = ventas;               // Asignar el diccionario de ventas
    this->totalIngresos = totalIngresos; // Asignar el total de ingresos
}

float DtInforme::getTotalIngresos()
{
    return this->totalIngresos; // Retornar el total de ingresos
}

IDictionary *DtInforme::getVentas()
{
    return this->ventas; // Retornar el diccionario de ventas
}

DtInforme::~DtInforme()
{
    ventas->clearDictionary();
    delete ventas;
}