#pragma once

#include <iostream>
#include "DtProducto.h"


using namespace std;

class DtMenu : public DtProducto
{
public:
    DtMenu();
    DtMenu(char*, string);
    DtMenu(char*, string, float);
    friend ostream& operator<<(ostream&, const DtMenu&);
    DtProducto* clone() const; // Metodo que retorna una copia profunda del objeto
    ~DtMenu();
};
