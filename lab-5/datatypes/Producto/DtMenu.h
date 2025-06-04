#pragma once

#include <iostream>
#include "DtProducto.h"


using namespace std;

class DtMenu : public DtProducto
{
public:
    DtMenu();
    DtMenu(char*, string);
    DtProducto* clone() const; // Método que retorna una copia profunda del objeto
    ~DtMenu();
};
