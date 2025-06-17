#pragma once
#include <iostream>
#include "../Venta/VentaLocal.h" 
#include "../Empleado/Mozo.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/Mesa/DtMesa.h"
using namespace std;

class Mozo;

class Mesa : public ICollectible {
private:
    int numero;
    Mozo* mozo;
    VentaLocal *ventaEnCurso; 

public:
    Mesa();
    Mesa(Mozo*);
    int getNumero();
    Mozo *getMozo();
    VentaLocal *getVentaEnCurso() const;
    void setNumero(int);
    void setMozo(Mozo*);
    void setVentaEnCurso(VentaLocal*);
    Mesa * getMesa();
    DtMesa getDtMesa() const; // ni está hecho XD
    friend ostream & operator<<(ostream&, const Mesa&);
    ~Mesa();
};