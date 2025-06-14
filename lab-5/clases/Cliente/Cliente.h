#pragma once
#include <iostream>

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/Cliente/DtCliente.h"
#include "../../datatypes/Direccion/DtDireccion.h"
#include "../../datatypes/Direccion/DtDireccionCasa.h"
#include "../../datatypes/Direccion/DtDireccionApto.h"

using namespace std;

class Cliente : public ICollectible
{
private:
    string nombre;
    int telefono;
    DtDireccion direccion;

public:
    Cliente(DtCliente);
    string getNombre();
    int getTelefono();
    DtCliente* getDatos();
    DtDireccion getDireccion();
    void setNombre(string);
    void setTelefono(int);
    void setDireccion(DtDireccion);
    friend ostream & operator<<(ostream&, const Cliente&);
    ~Cliente();
};