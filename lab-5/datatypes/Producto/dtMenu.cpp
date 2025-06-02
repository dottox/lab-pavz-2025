#include "dtMenu.h"

dtMenu::dtMenu(){}

dtMenu::dtMenu(int id, string codigo, string descripcion, float precio) : dtProducto(id, codigo, descripcion) {}

dtMenu::~dtMenu() {}