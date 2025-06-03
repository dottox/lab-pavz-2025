#include "Venta.h"

#include "../../utils/utils.h"

#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/interfaces/IKey.h"

Venta::Venta()
{
    this->codigo = utils::generarNumeroVenta();
    this->descuento = 0;
    this->cantidadProductos = 0;
    this->subtotal = 0.0f;
    this->factura = nullptr;
    this->productos = new OrderedDictionary(); 
}

int Venta::getCodigo()
{
    return this->codigo;
}

float Venta::getSubtotal()
{
    return this->subtotal;
}

int Venta::getDescuento()
{
    return this->descuento;
}

// Producto **Venta::getProductos()
// {
//     // return this->productos;
// }

int Venta::getCantidadProductos()
{
    return this->cantidadProductos;
}

bool Venta::estaFacturada()
{
    return this->factura != NULL;
}

void Venta::setSubtotal(float subtotal)
{
    this->subtotal = subtotal;
}

void Venta::setDescuento(int descuento)
{
    this->descuento = descuento;
}

void Venta::agregarProducto(Producto* producto, int cantidad)
{
    if (cantidad <= 0)
    {
        throw std::invalid_argument("La cantidad debe ser mayor a 0.");
    }

    // Assuming productos is an OrderedDictionary
    IKey* key = new String(producto->getCodigo());
    this->productos->add(key, producto);
    this->cantidadProductos += cantidad;
}

Venta::~Venta()
{
    delete productos; // Delete the array of Producto pointers
}

ostream &operator<<(ostream &os, const Venta &venta)
{
    os << "Codigo: " << venta.codigo 
       << ", Subtotal: " << venta.subtotal 
       << ", Descuento: " << venta.descuento 
       << ", Cantidad de Productos: " << venta.cantidadProductos;
    if (venta.factura != nullptr) {
        os << ", Facturada: Si";
    } else {
        os << ", Facturada: No";
    }
    return os;
}
