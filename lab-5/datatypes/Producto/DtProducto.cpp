#include "DtProducto.h"
#include <cstring>

DtProducto::DtProducto(){}

DtProducto::DtProducto(const char* codigo, string descripcion, TipoProducto tipo){
    if(codigo == nullptr || strlen(codigo) == 0) {
        throw invalid_argument("El codigo no puede ser nulo o vacio.");
    }
    if(descripcion.empty()) {
        throw invalid_argument("La descripcion no puede estar vacia.");
    }
    if(tipo != TipoPlato && tipo != TipoMenu) {
        throw invalid_argument("Tipo de producto invalido.");
    }
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = 0.0f; // Inicializar precio a 0.0 por defecto
    this->cantidad = 1; // Inicializar cantidad a 1 por defecto
}

DtProducto::DtProducto(const char* codigo, string descripcion, TipoProducto tipo, float precio) 
    : DtProducto(codigo, descripcion, tipo) {
    if(precio <= 0) {
        throw invalid_argument("El precio no puede ser negativo o 0.");
    }
    this->precio = precio; 
    this->cantidad = 1; // Inicializar cantidad a 1 por defecto
}

DtProducto::DtProducto(const char* codigo, string descripcion, TipoProducto tipo, float precio, int cantidad) 
    : DtProducto(codigo, descripcion, tipo, precio) {
    if(cantidad < 0) {
        throw invalid_argument("La cantidad no puede ser negativa.");
    }
    this->cantidad = cantidad; // Inicializar cantidad
}

DtProducto::DtProducto(const DtProducto& other){
    this->codigo = new char[strlen(other.codigo) + 1];
    strcpy(this->codigo, other.codigo);
    this->descripcion = other.descripcion;
    this->tipo = other.tipo;
    this->precio = other.precio;
}

DtProducto& DtProducto::operator=(const DtProducto& other) {
    if (this != &other) {
        delete[] this->codigo;
        this->codigo = new char[strlen(other.codigo) + 1];
        strcpy(this->codigo, other.codigo);
        this->descripcion = other.descripcion;
        this->tipo = other.tipo;
        this->precio = other.precio;
    }
    return *this;
}

DtProducto::~DtProducto() {
    delete[] this->codigo;
}

char* DtProducto::getCodigo() const {
    return this->codigo;
}

string DtProducto::getDescripcion() const {
    return this->descripcion;
}

TipoProducto DtProducto::getTipo() const {
    return this->tipo;
}

float DtProducto::getPrecio() const {
    return this->precio;
}

int DtProducto::getCantidad() const {
    return this->cantidad;
}