#include "DtMenu.h"

#include "../../enums/TipoProducto.h"

DtMenu::DtMenu(){}

DtMenu::DtMenu(char* codigo, string descripcion, float precio) : DtProducto(codigo, descripcion, TipoMenu, precio) {

}

DtMenu::~DtMenu() {}