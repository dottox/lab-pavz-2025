#pragma once

#include <iostream>
#include "DtProducto.h"

using namespace std;

class DtPlato : public DtProducto
{
public:
    DtPlato();
    DtPlato(char*, string, float);
    ~DtPlato();
    
};
