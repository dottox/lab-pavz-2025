#include "Sistema.h"

Sistema * Sistema::instance = NULL;

// ###### --------------- Alta producto ---------------  #######
void Sistema::seleccionarTipoProducto(TipoProducto tipoProducto) {
    this->tipoProductoSeleccionado = tipoProducto;
}

void Sistema::crearMenu(DtMenu dtMenu) {
    if (this->tipoProductoSeleccionado == TipoMenu) {
        this->productoCreado = new Menu(dtMenu);
    } else {
        throw invalid_argument("El tipo de producto seleccionado no es un Menu.");
    }
}

void Sistema::crearPlato(DtPlato dtPlato) {
    if (this->tipoProductoSeleccionado == TipoPlato) {
        this->productoCreado = new Plato(dtPlato);
    } else {
        throw invalid_argument("El tipo de producto seleccionado no es un Plato.");
    }
}

ICollection* Sistema::obtenerPlatos() {
    ICollection* platos = new List();
    IIterator* it = this->productos->getIterator();
    while (it->hasCurrent()) {
        Producto* producto = dynamic_cast<Producto*>(it->getCurrent());
        if (producto->getTipo() == TipoPlato) {
            DtPlato* dtPlato = dynamic_cast<Plato*>(producto)->getInfo();
            platos->add(dtPlato);
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return platos;
}

void Sistema::añadirPlatoAMenu(char* codigo, int cantidad) {
    if (this->productoCreado == NULL || this->tipoProductoSeleccionado != TipoMenu) {
        throw invalid_argument("No se ha creado un Menu o no se ha seleccionado un tipo de producto válido.");
    } else if (cantidad <= 0) {
        throw invalid_argument("La cantidad debe ser mayor a 0.");
    }
    
    IKey* key = new String(codigo);
    Plato* plato = dynamic_cast<Plato*>(this->productos->find(key));
    if (plato == nullptr) {
        delete key; // Liberar memoria del key
        throw invalid_argument("El plato con el código proporcionado no existe.");
    }

    Menu* menu = dynamic_cast<Menu*>(this->productoCreado);
    menu->añadirPlato(plato, cantidad);
    delete key; // Liberar memoria del key
}

void Sistema::darAltaProducto() {
    if (this->productoCreado == nullptr) {
        throw invalid_argument("No se ha creado un producto.");
    }
    
    IKey* key = new String(this->productoCreado->getCodigo());
    if (this->productos->member(key)) {
        delete key; // Liberar memoria del key
        this->cancelarAltaProducto(); // Limpiar el producto creado
        throw invalid_argument("El producto ya existe en el sistema.");
    }
    
    Menu* menu = dynamic_cast<Menu*>(this->productoCreado);
    if(menu != nullptr) {
        if(menu->esVacio()){
            delete key; // Liberar memoria del key
            cout << "El menú no contiene platos." << endl;
            this->cancelarAltaProducto(); // Limpiar el producto creado
            throw invalid_argument("El menú no contiene platos, no se puede dar de alta.");
        }
    }

    this->productos->add(key, this->productoCreado);
    this->productoCreado = nullptr; // Limpiar la variable temporal
}

void Sistema::cancelarAltaProducto() {
    if (this->productoCreado != nullptr) {
        cout << "Cancelando la creación del producto: " << this->productoCreado->getCodigo() << endl;
        delete this->productoCreado; // Liberar memoria del producto creado
        this->productoCreado = nullptr; // Limpiar la variable temporal
    }
    this->tipoProductoSeleccionado = TipoProducto::undefinedTipo; // Limpiar el tipo de producto seleccionado
}




// // ####### --------------- Utils --------------- #######

void Sistema::poblarSistema() {
    // Crear empleados
    Mozo* emp1 = new Mozo("Juan");
    Mozo* emp2 = new Mozo("Maria");
    Repartidor* emp3 = new Repartidor("Pedro", Bicicleta);

    // Agregar empleados al sistema
    this->empleados->add(new Integer(emp1->getNumero()), emp1);
    this->empleados->add(new Integer(emp2->getNumero()), emp2);
    this->empleados->add(new Integer(emp3->getNumero()), emp3);

    // Crear productos
    Plato* plato1 = new Plato(DtPlato((char*)"P001", "Ensalada Caesar", 150.0));
    Plato* plato2 = new Plato(DtPlato((char*)"P002", "Pizza Margherita", 200.0));
    Plato* plato3 = new Plato(DtPlato((char*)"P003", "Sopa de Tomate", 100.0));
    Menu* menu1 = new Menu(DtMenu((char*)"M001", "Menu del Dia"));
    menu1->añadirPlato(plato1, 1);
    menu1->añadirPlato(plato2, 2);

    // Agregar productos al sistema
    this->productos->add(new String(plato1->getCodigo()), plato1);
    this->productos->add(new String(plato2->getCodigo()), plato2);
    this->productos->add(new String(plato3->getCodigo()), plato3);
    this->productos->add(new String(menu1->getCodigo()), menu1);

    // Crear mesas
    Mesa* mesa1 = new Mesa(emp1);
    Mesa* mesa2 = new Mesa(emp2);
    Mesa* mesa3 = new Mesa(emp2);

    // Agregar mesas al sistema
    this->mesas->add(new Integer(mesa1->getNumero()), mesa1);
    this->mesas->add(new Integer(mesa2->getNumero()), mesa2);
    this->mesas->add(new Integer(mesa3->getNumero()), mesa3);


    // Crear cliente
    DtCliente* cliente1 = new DtCliente("Carlos", "123456789", DtDireccion("Calle Falsa", 123, "Pais"));

    // Crear ventas
    VentaLocal* venta1 = new VentaLocal();
    VentaDomicilio* venta2 = new VentaDomicilio(cliente1);
    venta1->agregarProducto(plato1, 2);
    venta1->agregarProducto(plato2, 1);
    venta2->agregarProducto(plato3, 1);

    // Agregar ventas al sistema
    this->ventas->add(new Integer(venta1->getCodigo()), venta1);
    this->ventas->add(new Integer(venta2->getCodigo()), venta2);

}

int Sistema::getCantidadProductos() {
    return this->productos->getSize();
}

void Sistema::listarEmpleados() {
    cout << "--- Empleados del Sistema ---" << endl;
    IIterator* it = this->empleados->getIterator();
    while (it->hasCurrent()) {
        Mozo* mozo = dynamic_cast<Mozo*>(it->getCurrent());
        if (mozo == nullptr) {
            Repartidor* repartidor = dynamic_cast<Repartidor*>(it->getCurrent());
            cout << *repartidor << endl;
        } else {
            cout << *mozo << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarVentas() {
    cout << endl << "--- Ventas del Sistema ---" << endl;
    IIterator* it = this->ventas->getIterator();
    while (it->hasCurrent()) {
        VentaLocal* ventaLocal = dynamic_cast<VentaLocal*>(it->getCurrent());
        if (ventaLocal != nullptr) {
            cout << *ventaLocal << endl;
        } else {
            VentaDomicilio* ventaDomicilio = dynamic_cast<VentaDomicilio*>(it->getCurrent());
            cout << *ventaDomicilio << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarMesas() {
    cout << endl << "--- Mesas del Sistema ---" << endl;
    IIterator* it = this->mesas->getIterator();
    while (it->hasCurrent()) {
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        cout << *mesa << endl;
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarProductos() {
    cout << endl << "--- Productos del Sistema ---" << endl;
    IIterator* it = this->productos->getIterator();
    while (it->hasCurrent()) {
        Plato* plato = dynamic_cast<Plato*>(it->getCurrent());
        if (plato != nullptr) {
            cout << *plato << endl;
        } else {
            Menu* menu = dynamic_cast<Menu*>(it->getCurrent());
            cout << *menu << endl;
        }

        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarProductoTemporal() {
    if (this->productoCreado == NULL) {
        cout << "No hay un producto temporal creado." << endl;
        return;
    }
    cout << "--- Producto Temporal ---" << endl;
    Plato* plato = dynamic_cast<Plato*>(this->productoCreado);
    if (plato != nullptr) {
        cout << *plato << endl;
    } else {
        Menu* menu = dynamic_cast<Menu*>(this->productoCreado);
        cout << *menu << endl;
    }
}

Sistema::Sistema(){
    this->empleados = new OrderedDictionary();
    this->mesas = new OrderedDictionary();
    this->productos = new OrderedDictionary();
    this->ventas = new OrderedDictionary();

    // Inicializar variables de alta de producto
    this->tipoProductoSeleccionado = TipoProducto::undefinedTipo;
    this->productoCreado = NULL;

    // Poblar el sistema con datos de ejemplo
    this->poblarSistema();
}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}

void Sistema::saludar() {
    cout << "Hola, bienvenido al sistema!" << endl;
}


Sistema::~Sistema() {
    delete empleados;
    delete ventas;
    delete mesas;
    delete productos;

    // Limpiar variables de alta de producto
    if (productoCreado != NULL) {
        delete productoCreado;
        productoCreado = NULL;
    }
    tipoProductoSeleccionado = TipoProducto::undefinedTipo;

    instance = NULL; // Limpiar la instancia única
}
