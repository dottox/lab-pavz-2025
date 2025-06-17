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
    string telefono;
    DtDireccion* direccion;

public:
    Cliente(DtCliente);
    string getNombre();
    string getTelefono();
    DtCliente *getDatos();
    DtDireccion* getDireccion();
    void setNombre(string);
    void setTelefono(string);
    void setDireccion(DtDireccion*);
    friend ostream &operator<<(ostream &, const Cliente &);
    ~Cliente();
};