#include "Mesa.h"
#include "../../utils/utils.h"

Mesa::Mesa()
{
    this->numero = utils::generarNumeroMesa();
    this->mozo = nullptr;
    this->ventaEnCurso = nullptr;
}

Mesa::Mesa(Mozo *mozo)
{
    this->numero = utils::generarNumeroMesa();
    this->mozo = mozo;
    this->ventaEnCurso = nullptr;
}

int Mesa::getNumero()
{
    return this->numero;
}

Mozo *Mesa::getMozo()
{
    return this->mozo;
}

VentaLocal *Mesa::getVentaEnCurso() const
{
    return this->ventaEnCurso;
}

void Mesa::setNumero(int numero)
{
    this->numero = numero;
}
void Mesa::setMozo(Mozo *mozo)
{
    this->mozo = mozo;
}
void Mesa::setVentaEnCurso(VentaLocal *venta)
{
    if(this->getVentaEnCurso() != nullptr)
    {
        throw invalid_argument("La mesa ya tiene una venta en curso.");
    }
    if(venta == nullptr || venta->getFactura() != nullptr){
        throw invalid_argument("La venta ya esta facturada o no existe.");
    }
    if(this->mozo == nullptr){
        throw invalid_argument("La mesa no tiene un mozo asignado.");
    }
    this->ventaEnCurso = venta;
}

ostream &operator<<(ostream &os, const Mesa &mesa)
{
    os << "Mesa Numero: " << mesa.numero << endl;
    if(mesa.mozo == nullptr){
        os << "    No tiene mozo asignado";
    }else{
        os << "    " << *(mesa.mozo);
    }
    if (mesa.getVentaEnCurso() != nullptr)
    {
        os << ", Hay venta en curso";
    }
    else
    {
        os << ", No hay venta en curso";
    }
    return os;
}
Mesa *Mesa::getMesa()
{
    return this; // Retorna la propia instancia de Mesa
}

Mesa::~Mesa()
{
    // Destructor logic if needed, currently does nothing
}