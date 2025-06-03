#pragma once

#include <iostream>
#include "Venta.h"

#include "../../ICollection/interfaces/ICollection.h"

using namespace std;

class VentaLocal : public Venta
{
public:
    VentaLocal();
    friend ostream & operator<<(ostream&, const VentaLocal&);
    ~VentaLocal();
};