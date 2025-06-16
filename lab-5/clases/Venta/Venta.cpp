#include "Venta.h"


Venta::Venta()
{
    this->codigo = utils::generarNumeroVenta();
    this->descuento = 0;
    this->cantidadProductos = 0;
    this->subtotal = 0.0f;
    this->factura = nullptr;
    this->productosConsumidos = new OrderedDictionary();
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

ICollection * Venta::getProductos()
{
    ICollection *productos = new List();
    IIterator * it = this->productosConsumidos->getIterator();

    while(it->hasCurrent()){
        ProductoVenta *productoVenta = (ProductoVenta *)it->getCurrent();
        Producto* p = productoVenta->getProducto(); 
        Plato* plato = dynamic_cast<Plato *>(p);
        if(plato  != nullptr) {
            DtPlato* dtPlato = new DtPlato(p->getCodigo(), p->getDescripcion(), p->getPrecio());
            productos->add(dtPlato);
        } else {
            Menu* menu = dynamic_cast<Menu *>(p);
            if(menu != nullptr) {
                DtMenu* dtMenu = new DtMenu(p->getCodigo(), p->getDescripcion(), p->getPrecio());
                productos->add(dtMenu);
            }
        }
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
        producto->getDescripcion(),
        cantidad,
        producto->getPrecio(),
        producto);

    cout << "Producto agregado: " << productoVenta->getDescripcion()
         << ", Cantidad: " << productoVenta->getCantidad()
         << ", Precio: " << productoVenta->getPrecio() << endl;

    // Assuming productos is an OrderedDictionary
    IKey *key = new String(producto->getDescripcion().c_str());
    this->productosConsumidos->add(key, productoVenta);
    this->cantidadProductos += cantidad;
}

void Venta::quitarProducto(Producto *producto, int cantidad)
{
    if (cantidad <= 0)
    {
        throw invalid_argument("La cantidad debe ser mayor a 0.");
    }

    IKey *key = new String(producto->getDescripcion().c_str());
    ProductoVenta *productoVenta = (ProductoVenta *)this->productosConsumidos->find(key);
    if (productoVenta == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El producto no esta en la venta.");
    }
    else
    {
        if (productoVenta->getCantidad() < cantidad)
        {
            delete key; // Liberar memoria del key
            throw invalid_argument("La cantidad a quitar es mayor a la cantidad en la venta.");
        }
        else
        {
            productoVenta->setCantidad(productoVenta->getCantidad() - cantidad);
            this->cantidadProductos -= cantidad;
            if (productoVenta->getCantidad() == 0)
            {
                this->productosConsumidos->setNull(key); // quita el producto sin borrarlo la cantidad llega a 0
                cout << "Producto eliminado: " << productoVenta->getDescripcion() << endl;
            }

            cout << "Producto actualizado: " << productoVenta->getDescripcion()
                 << ", Nueva cantidad: " << productoVenta->getCantidad() << endl;

            delete key; // Liberar memoria del key
        }
    }
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

    return facturaLocal;
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