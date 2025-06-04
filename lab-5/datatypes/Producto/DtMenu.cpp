#include "DtMenu.h"

#include "../../enums/TipoProducto.h"

DtMenu::DtMenu(){}

DtMenu::DtMenu(char* codigo, string descripcion) : DtProducto(codigo, descripcion, TipoMenu) {

}

DtProducto* DtMenu::clone() const{
    return new DtMenu(*this);
}

DtMenu::~DtMenu() {}