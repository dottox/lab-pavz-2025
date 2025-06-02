#pragma once
#include <iostream>
#include "../Venta/VentaLocal.h" 
#include "../Empleado/Mozo.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class Mozo;

class Mesa : ICollectible {
private:
    int numero;
    Mozo* mozo;
    VentaLocal *ventaEnCurso; 

public:
    Mesa(Mozo*);
    int getNumero();
    Mozo *getMozo();
    VentaLocal *getVentaEnCurso();
    void setNumero(int);
    void setMozo(Mozo*);
    void setVentaEnCurso(VentaLocal*);
    ~Mesa();
};