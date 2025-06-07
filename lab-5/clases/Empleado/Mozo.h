#pragma once

#include <iostream>
#include "../Empleado/Empleado.h"
#include "../Mesa/Mesa.h"

#include "../../ICollection/Integer.h"
#include "../../ICollection/String.h"
#include "../../ICollection/interfaces/IKey.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/collections/OrderedDictionary.h"


using namespace std;

class Mesa;

class Mozo : public Empleado{
protected:
    IDictionary * mesasAsignadas;
    int cantidadMesasAsignadas;

public:
    Mozo(string);
    int getCantidadMesasAsignadas() const;
    void setCantidadMesasAsignadas(int cantidad);
    IDictionary * getMesasAsignadas();
    ICollection * getMesasAsignadasSinVentaEnCurso();
    void setMesaAsignada(Mesa *mesa);
    friend ostream & operator<<(ostream&, const Mozo&);
    ~Mozo();
};