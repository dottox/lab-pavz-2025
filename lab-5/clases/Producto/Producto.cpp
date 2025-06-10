#include "Producto.h"
#include "../../utils/utils.h"

Producto::Producto(const DtProducto* dtProducto)
{
    char* codigo = dtProducto->getCodigo();
    this->codigo = new char[strlen(codigo) + 1]; // Creamos una copia del codigo
    strcpy(this->codigo, codigo); 
    this->descripcion = dtProducto->getDescripcion();
    this->tipo = dtProducto->getTipo();
    this->precio = dtProducto->getPrecio();
}

char* Producto::getCodigo() const{
    return this->codigo;
}

string Producto::getDescripcion() const{
    return this->descripcion;
}

TipoProducto Producto::getTipo() const{
    return this->tipo;
}

float Producto::getPrecio() const{
    return this->precio;
}

void Producto::setPrecio(float precio){
    if (precio < 0) {
        throw invalid_argument("El precio no puede ser negativo.");
    }
    this->precio = precio;
}

ostream& operator<<(ostream& os, const Producto& producto){
    os << "Codigo: " << producto.codigo << ", Descripcion: " << producto.descripcion
       << ", Tipo: " << (producto.tipo == TipoPlato ? "Plato" : "Menu")
       << ", Precio: $" << producto.precio;
    return os;
}

Producto::~Producto() {
    cout << "Destruyendo Producto con codigo: " << this->codigo << endl;
    delete[] this->codigo; // Liberar memoria del codigo
}