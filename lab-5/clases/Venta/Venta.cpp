#include "Venta.h"

#include "../../utils/utils.h"

Venta::Venta()
{
    this->codigo = utils::generarNumeroVenta();
    this->descuento = 0;
    this->cantidadProductos = 0;
    this->subtotal = 0.0f;
    this->factura = nullptr;
    this->productosConsumidos = new OrderedDictionary();
}

Venta::Venta(int cantidadProductos, float subtotal, IDictionary *productosConsumidos)
{
    this->codigo = utils::generarNumeroVenta();
    this->subtotal = subtotal;
    this->descuento = 0;
    this->cantidadProductos = cantidadProductos;
    this->factura = nullptr;
    this->productosConsumidos = productosConsumidos;

    if (this->productosConsumidos == nullptr)
    {
        this->productosConsumidos = new OrderedDictionary();
    }
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

ICollection *Venta::getProductos()
{
    ICollection *productos = new List();
    IIterator *it = this->productosConsumidos->getIterator();

    while (it->hasCurrent())
    {
        ProductoVenta *productoVenta = (ProductoVenta *)it->getCurrent();
        DtProducto *producto = productoVenta->getProducto();
        productos->add(producto);
        it->next();
    }

    delete it;
    return productos;
}

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

void Venta::agregarPorcentaje(int descuento)
{
    this->descuento = descuento;
}

void Venta::agregarProducto(Producto *producto, int cantidad)
{
    if (cantidad <= 0)
    {
        throw invalid_argument("La cantidad debe ser mayor a 0.");
    }

    ProductoVenta *productoVenta = new ProductoVenta(
        producto->getCodigo(),
        producto->getTipo(),
        producto->getDescripcion(),
        producto->getPrecio(),
        cantidad);

    cout << "Producto agregado: " << productoVenta->getDescripcion()
         << ", Cantidad: " << productoVenta->getCantidad()
         << ", Precio: " << productoVenta->getPrecio() << endl;

    // Assuming productos is an OrderedDictionary
    IKey *key = new String(producto->getCodigo());
    this->productosConsumidos->add(key, productoVenta);
    this->cantidadProductos += cantidad;
}

DtFacturaLocal Venta::generarFactura(string nombreMozo)
{
    IIterator *it = this->productosConsumidos->getIterator();
    IDictionary *productosConsumidos = new OrderedDictionary();

    while (it->hasCurrent())
    {
        ProductoVenta *productoConsumido = (ProductoVenta *)it->getCurrent();
        this->subtotal += productoConsumido->getPrecio() * productoConsumido->getCantidad();
        DtConsumido *consumido = new DtConsumido(
            productoConsumido->getDescripcion(),
            productoConsumido->getCantidad(),
            productoConsumido->getPrecio());
        IKey *key = new String(productoConsumido->getDescripcion().c_str());
        productosConsumidos->add(key, consumido);
        it->next();
    }

    delete it;

    DtFacturaLocal facturaLocal = DtFacturaLocal(
        DtFactura(
            this->codigo,
            utils::obtenerFechaActual(),
            utils::obtenerHoraActual(),
            productosConsumidos,
            this->subtotal,
            this->descuento,
            this->subtotal * (1 - descuento / 100.0f) * (1 + IVA / 100.0f),
            IVA),
        nombreMozo);

    FacturaLocal *factura = new FacturaLocal(facturaLocal);
    this->factura = factura;

    return factura->getDatos();
}

DtFacturaDomicilio Venta::generarFacturaDomicilio(string nombreRepartidor, Transporte transporte)
{
    IIterator *it = this->productosConsumidos->getIterator();
    IDictionary *productosConsumidos = new OrderedDictionary();

    while (it->hasCurrent())
    {
        ProductoVenta *productoConsumido = (ProductoVenta *)it->getCurrent();
        this->subtotal += productoConsumido->getPrecio() * productoConsumido->getCantidad();
        DtConsumido *consumido = new DtConsumido(
            productoConsumido->getDescripcion(),
            productoConsumido->getCantidad(),
            productoConsumido->getPrecio());
        IKey *key = new String(productoConsumido->getDescripcion().c_str());
        productosConsumidos->add(key, consumido);
        it->next();
    }

    delete it;

    DtFacturaDomicilio facturaDomicilio = DtFacturaDomicilio(
        DtFactura(
            this->codigo,
            utils::obtenerFechaActual(),
            utils::obtenerHoraActual(),
            productosConsumidos,
            this->subtotal,
            this->descuento,
            this->subtotal * (1 - descuento / 100.0f) * (1 + IVA / 100.0f),
            IVA),
        nombreRepartidor,
        transporte);

    FacturaDomicilio *factura = new FacturaDomicilio(facturaDomicilio);
    this->factura = factura;

    return factura->getDatos();
}

DtFacturaLocal Venta::mostrarFacturaLocal()
{
    FacturaLocal *facturaLocal = (FacturaLocal *)(this->factura);
    return facturaLocal->getDatos();
}

DtFacturaDomicilio Venta::mostrarFacturaDomicilio()
{
    FacturaDomicilio *facturaDomicilio = (FacturaDomicilio *)(this->factura);
    return facturaDomicilio->getDatos();
}

Factura *Venta::getFactura()
{
    return this->factura;
}

Venta::~Venta()
{
    delete productosConsumidos; // Delete the array of Producto pointers
}

ostream &operator<<(ostream &os, const Venta &venta)
{
    os << "Codigo: " << venta.codigo
       << ", Subtotal: " << venta.subtotal
       << ", Descuento: " << venta.descuento
       << ", Cantidad de Productos: " << venta.cantidadProductos;
    if (venta.factura != nullptr)
    {
        os << ", Facturada: Si";
    }
    else
    {
        os << ", Facturada: No";
    }
    return os;
}

bool Venta::contieneProducto(Producto *producto)
{
    IKey *key = new String(producto->getCodigo());
    bool contiene = this->productosConsumidos->member(key);
    delete key; // Liberar memoria del key
    return contiene;
}