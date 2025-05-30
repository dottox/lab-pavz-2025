#pragma once
#include <iostream>
#include "../Venta/VentaLocal.h" // Assuming VentaLocal is defined in this header

class Mozo; // Forward declaration to avoid circular dependency

using namespace std;

class Mesa{
private:
    int numero;
    Mozo* mozo;
    VentaLocal *ventaEnCurso; // Assuming VentaLocal is defined elsewhere

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