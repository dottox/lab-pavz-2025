#include "Repartidor.h"

Repartidor::Repartidor(string nombre, Transporte transporte) : Empleado(nombre)
{
    this->transporte = transporte;
};

Transporte Repartidor::getTransporte() const
{
    return this->transporte;
}

ostream &operator<<(ostream &os, const Repartidor &repartidor)
{
    string transporteStr;

    switch (repartidor.getTransporte())
    {
    case aPie:
        transporteStr = "A pie";
        break;
    case Moto:
        transporteStr = "Moto";
        break;
    case Bicicleta:

        transporteStr = "Bicicleta";
        break;
    case Auto:
        transporteStr = "Auto";
        break;
    default:
        transporteStr = "Transporte no definido";
        break;
    }

    os << "Repartidor: " << static_cast<const Empleado &>(repartidor); // Call base class operator<<
    os << ", Transporte: " << transporteStr;
    return os;
}

Repartidor::~Repartidor()
{
}