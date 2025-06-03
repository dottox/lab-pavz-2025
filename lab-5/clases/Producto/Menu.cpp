#include "Menu.h"

#include "../../ICollection/String.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/List.h"

Menu::Menu(DtMenu menu) : Producto(menu.getProducto())
{
    this->menuPlatos = new OrderedDictionary(); // Inicializar el diccionario de platos
}

Menu::Menu(DtMenu menu, IDictionary* menuPlatos) : Producto(menu.getProducto())
{
    this->menuPlatos = menuPlatos;
}

ICollection* Menu::getPlatos()
{
    ICollection* platos = new List();
    IIterator* it = this->menuPlatos->getIterator();
    while (it->hasCurrent()) {
        MenuPlato* menuPlato = dynamic_cast<MenuPlato*>(it->getCurrent());
        if (menuPlato) {
            Plato* plato = menuPlato->getPlato();
            platos->add(plato); // Agregar el plato al conjunto
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return platos; // Retornar el conjunto de platos
}

void Menu::añadirPlato(Plato* plato, int cantidad)
{
    IKey* key = new String(plato->getCodigo());
    if (this->menuPlatos->member(key)) {
        // Si el plato ya existe, no hacemos nada
        delete key; // Liberar memoria del key
        return;
    } else {
        // Si el plato no existe, lo agregamos
        MenuPlato* menuPlato = new MenuPlato(plato, cantidad);
        this->menuPlatos->add(key, menuPlato);
    }
}

ostream& operator<<(ostream& os, const Menu& menu)
{
    os << static_cast<const Producto&>(menu) << endl;
    os << "Platos en el menú:" << endl;
    IIterator* it = menu.menuPlatos->getIterator();
    while (it->hasCurrent()) {
        MenuPlato* menuPlato = dynamic_cast<MenuPlato*>(it->getCurrent());
        if (menuPlato) {
            os << "  - " << *(menuPlato->getPlato()) << " (Cantidad: " << menuPlato->getCantidad() << ")" << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return os;
}

Menu::~Menu()
{
    delete this->menuPlatos; // Liberar memoria del diccionario de platos
}