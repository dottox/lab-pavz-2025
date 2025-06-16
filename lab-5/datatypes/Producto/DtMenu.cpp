#include "DtMenu.h"

#include "../../enums/TipoProducto.h"

DtMenu::DtMenu(){}

DtMenu::DtMenu(char* codigo, string descripcion) : DtProducto(codigo, descripcion, TipoMenu) {

}
DtMenu::DtMenu(char* codigo, string descripcion, float precio) : DtProducto(codigo, descripcion, TipoMenu, precio) {

}

ostream& operator<<(ostream& os, const DtMenu& menu)
{
    os << "Menu | Codigo: " << menu.getCodigo() 
       << ", Descripcion: " << menu.getDescripcion()
       << ", Precio: $" << menu.getPrecio();
    return os;
}

DtProducto* DtMenu::clone() const{
    return new DtMenu(*this);
}

DtMenu::~DtMenu() {}