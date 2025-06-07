#pragma once

#include <iostream>
#include "Producto.h"
#include "Plato.h"
#include "../../datatypes/Producto/DtMenu.h"
#include "MenuPlato.h"

#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/ICollection.h"

#include "../../ICollection/String.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/List.h"

using namespace std;

class Menu : public Producto
{
private:
    IDictionary *menuPlatos; // De tipo MenuPlato

public:
    Menu(DtMenu);
    Menu(DtMenu, IDictionary *);
    ICollection *getPlatos();
    void actualizarPrecio();
    bool esVacio();
    friend ostream &operator<<(ostream &, const Menu &);
    void anadirPlato(Plato *, int);



    ~Menu();
};