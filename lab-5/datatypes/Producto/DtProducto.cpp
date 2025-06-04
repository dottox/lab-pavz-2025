#include "DtProducto.h"
#include <cstring>

DtProducto::DtProducto(){}

DtProducto::DtProducto(const char* codigo, string descripcion, TipoProducto tipo){
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = 0.0f; // Inicializar precio a 0.0 por defecto
}

DtProducto::DtProducto(const char* codigo, string descripcion, TipoProducto tipo, float precio){
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
    this->descripcion = descripcion;
    this->tipo = tipo;
    this->precio = precio; 

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
