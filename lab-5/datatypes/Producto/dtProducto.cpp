#include "dtProducto.h"
#include "../../utils/utils.h"
dtProducto::dtProducto() {};

dtProducto::dtProducto(int id, string descripcion, string codigo)
{
    this->codigo = utils::generarNumeroProducto();
    this->id = id;
    this->descripcion = descripcion;
}

int dtProducto::getId()
{
    return this->id;
}

string dtProducto::getDescripcion()
{
    return this->descripcion;
}
string dtProducto::getCodigo()
{
    return this->codigo;
}
dtProducto dtProducto::getProducto()
{
    return *this; // Retorna una copia del objeto actual
}

dtProducto::~dtProducto()
{

}