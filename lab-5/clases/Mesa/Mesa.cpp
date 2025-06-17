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

Mesa * Mesa::getMesa() {
    return this; // Retorna la propia instancia de Mesa
}

Mesa::~Mesa()
{
    cout << "Destruyendo Mesa Numero: " << this->numero << endl;
    this->mozo = nullptr; 
    delete mozo;
    this->ventaEnCurso = nullptr;
    delete ventaEnCurso;  
}