#include "Menu.h"

#include "../../ICollection/String.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/collections/List.h"

Menu::Menu(DtMenu menu) : Producto(menu.clone()){
    this->menuPlatos = new OrderedDictionary(); // Inicializar el diccionario de platos
}


Menu::Menu(DtMenu menu, IDictionary *menuPlatos) : Producto(menu.getProducto())
{
    this->menuPlatos = menuPlatos;
}

Menu::Menu(DtMenu menu, IDictionary* menuPlatos) : Producto(menu.clone()){
    this->menuPlatos = menuPlatos;
}

ICollection* Menu::getPlatos(){
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
    delete it;     // Liberar memoria del iterador
    return platos; // Retornar el conjunto de platos
}


void Menu::actualizarPrecio() {
    float precioTotal = 0.0f;
    float descuento = 0.1f; // 10% de descuento
    IIterator* it = this->menuPlatos->getIterator();
    while (it->hasCurrent()) {
        MenuPlato* menuPlato = dynamic_cast<MenuPlato*>(it->getCurrent());
        if (menuPlato) {
            Plato* plato = menuPlato->getPlato();
            precioTotal += plato->getPrecio() * menuPlato->getCantidad();
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    this->setPrecio(precioTotal - (precioTotal * descuento)); // Aplicar un 10% de descuento
}

bool Menu::esVacio() {
    return this->menuPlatos->isEmpty();
}

void Menu::anadirPlato(Plato* plato, int cantidad){
    IKey* key = new String(plato->getCodigo());
    if (this->menuPlatos->member(key)) { // Verificar si el plato ya existe en el menú
        delete key; // Liberar memoria del key
        throw invalid_argument("El plato ya existe en el menú, no se ha modificado nada.");
    } else {
        MenuPlato* menuPlato = new MenuPlato(plato, cantidad);
        this->menuPlatos->add(key, menuPlato);
        this->actualizarPrecio(); // Actualizar el precio del menú (con un 10% de descuento)
    }
}

ostream &operator<<(ostream &os, const Menu &menu)
{

    os << static_cast<const Producto &>(menu) << endl;
    os << "Platos en el menú:" << endl;
    IIterator *it = menu.menuPlatos->getIterator();
    while (it->hasCurrent())
    {
        MenuPlato *menuPlato = dynamic_cast<MenuPlato *>(it->getCurrent());
        if (menuPlato)
        {
            os << "  - " << *(menuPlato->getPlato()) << " (Cantidad: " << menuPlato->getCantidad() << ")" << endl;

    os << static_cast<const Producto&>(menu) << endl;
    if(menu.menuPlatos == nullptr || menu.menuPlatos->isEmpty()) {
        os << "El menú no contiene platos." << endl;
        return os;
    }
    os << "Cantidad de platos (distintos) en el menú: " << menu.menuPlatos->getSize() << endl;
    os << "Platos en el menú:" << endl;
    IIterator* it = menu.menuPlatos->getIterator();
    while (it->hasCurrent()) {
        MenuPlato* menuPlato = dynamic_cast<MenuPlato*>(it->getCurrent());
        if (menuPlato) {
            os << "  - " << *(menuPlato->getPlato()) << " (x" << menuPlato->getCantidad() << ")" << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return os;
}

Menu::~Menu(){
    delete this->menuPlatos; // Liberar memoria del diccionario de platos
}