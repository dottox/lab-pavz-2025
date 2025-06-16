#include "Sistema.h"

Sistema *Sistema::instance = NULL;

Sistema::Sistema()
{
    this->empleados = new OrderedDictionary();
    this->clientes = new OrderedDictionary();
    this->mesas = new OrderedDictionary();
    this->productos = new OrderedDictionary();
    this->ventas = new OrderedDictionary();
    this->productosSeleccionadosDomicilio = new OrderedDictionary();
    this->mesasElegidas = new List();

    this->mesaSeleccionada = NULL;
    this->ventaSeleccionada = NULL;
    this->mozoSeleccionado = NULL;
    this->productoCreado = NULL;
    this->clienteSeleccionado = NULL;
    this->repartidorSeleccionado = NULL;
    this->clienteTemporal = NULL;
    this->transporteSeleccionado = undefinedTransporte;
    this->tipoProductoSeleccionado = TipoProducto::undefinedTipo;

    this->cantidadProductosSeleccionadosDomicilio = 0;
    this->subtotalVentaDomicilio = 0.0f;

    // Poblar el sistema con datos de ejemplo
    this->poblarSistema();
}

Sistema *Sistema::getInstance()
{
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}

// ###### --------------- Alta producto ---------------  #######
void Sistema::seleccionarTipoProducto(TipoProducto tipoProducto)
{
    this->tipoProductoSeleccionado = tipoProducto;
}

void Sistema::crearMenu(DtMenu dtMenu)
{
    if (this->tipoProductoSeleccionado == TipoMenu)
    {
        this->productoCreado = new Menu(dtMenu);
    }
    else
    {
        throw invalid_argument("El tipo de producto seleccionado no es un Menu.");
    }
}

void Sistema::crearPlato(DtPlato dtPlato)
{
    if (this->tipoProductoSeleccionado == TipoPlato)
    {
        this->productoCreado = new Plato(dtPlato);
    }
    else
    {
        throw invalid_argument("El tipo de producto seleccionado no es un Plato.");
    }
}

ICollection *Sistema::obtenerPlatos()
{
    ICollection *platos = new List();
    IIterator *it = this->productos->getIterator();
    while (it->hasCurrent())
    {
        Producto *producto = dynamic_cast<Producto *>(it->getCurrent());
        if (producto->getTipo() == TipoPlato)
        {
            DtPlato *dtPlato = dynamic_cast<Plato *>(producto)->getInfo();
            platos->add(dtPlato);
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return platos;
}

void Sistema::anadirPlatoAMenu(char *codigo, int cantidad)
{
    if (this->productoCreado == NULL || this->tipoProductoSeleccionado != TipoMenu)
    {
        throw invalid_argument("No se ha creado un Menu o no se ha seleccionado un tipo de producto valido.");
    }
    else if (cantidad <= 0)
    {
        throw invalid_argument("La cantidad debe ser mayor a 0.");
    }

    IKey *key = new String(codigo);
    Plato *plato = dynamic_cast<Plato *>(this->productos->find(key));
    if (plato == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El plato con el codigo proporcionado no existe.");
    }

    Menu *menu = dynamic_cast<Menu *>(this->productoCreado);
    menu->anadirPlato(plato, cantidad);
    delete key; // Liberar memoria del key
}

void Sistema::darAltaProducto()
{
    if (this->productoCreado == nullptr)
    {
        throw invalid_argument("No se ha creado un producto.");
    }

    IKey *key = new String(this->productoCreado->getCodigo());
    if (this->productos->member(key))
    {
        delete key;                   // Liberar memoria del key
        this->cancelarAltaProducto(); // Limpiar el producto creado
        throw invalid_argument("El producto ya existe en el sistema.");
    }

    Menu *menu = dynamic_cast<Menu *>(this->productoCreado);
    if (menu != nullptr)
    {
        if (menu->esVacio())
        {
            delete key; // Liberar memoria del key
            cout << "El menu no contiene platos." << endl;
            this->cancelarAltaProducto(); // Limpiar el producto creado
            throw invalid_argument("El menu no contiene platos, no se puede dar de alta.");
        }
    }

    this->productos->add(key, this->productoCreado);
    this->productoCreado = nullptr; // Limpiar la variable temporal
}

void Sistema::cancelarAltaProducto()
{
    if (this->productoCreado != nullptr)
    {
        cout << "Cancelando la creacion del producto: " << this->productoCreado->getCodigo() << endl;
        delete this->productoCreado;    // Liberar memoria del producto creado
        this->productoCreado = nullptr; // Limpiar la variable temporal
    }
    this->tipoProductoSeleccionado = TipoProducto::undefinedTipo; // Limpiar el tipo de producto seleccionado
}

// ###### --------------- Facturar venta ---------------  #######

void Sistema::elegirMesa(int codigoMesa)
{
    IKey *key = new Integer(codigoMesa);
    Mesa *mesa = (Mesa *)this->mesas->find(key);
    if (mesa == nullptr)
    {
        delete key;
        throw invalid_argument("La mesa con el codigo proporcionado no existe.");
    }
    this->mesaSeleccionada = mesa;
    delete key;
    return;
}

void Sistema::agregarPorcentaje(int descuento)
{
    VentaLocal *venta = this->mesaSeleccionada->getVentaEnCurso();
    if (venta == nullptr)
    {
        throw invalid_argument("No hay una venta en curso para la mesa seleccionada.");
    }

    venta->agregarPorcentaje(descuento);
    this->ventaSeleccionada = venta;
}

DtFacturaLocal Sistema::generarFactura()
{
    string nombreMozo = this->mesaSeleccionada->getMozo()->getNombre();
    DtFacturaLocal factura = this->ventaSeleccionada->generarFactura(nombreMozo);
    this->mesaSeleccionada->getMozo()->borrarMesaAsignada(this->mesaSeleccionada); // Eliminar la mesa de las mesas asignadas del mozo
    this->mesaSeleccionada->setVentaEnCurso(nullptr);
    this->mesaSeleccionada = NULL;
    this->ventaSeleccionada = NULL;
    return factura;
}

// ####### --------------- Agregar producto a una venta --------------- #######
void Sistema::seleccionarMozo(int numeroMozo)
{
    IKey *key = new Integer(numeroMozo);
    this->mozoSeleccionado = dynamic_cast<Mozo *>(this->empleados->find(key));
    if (this->mozoSeleccionado == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El mozo seleccionado no existe.");
    }
    delete key; // Liberar memoria del key
}

void Sistema::seleccionarProducto(string codigo)
{
    IKey *key = new String(codigo.c_str());
    this->productoSeleccionado = dynamic_cast<Producto *>(this->productos->find(key));
    if (this->productoSeleccionado == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El producto seleccionado no existe.");
    }
    delete key; // Liberar memoria del key
}

void Sistema::agregarProductoAVenta()
{
    if (this->mozoSeleccionado == nullptr || this->mesaSeleccionada == nullptr ||
        this->productoSeleccionado == nullptr || this->cantidadProductoSeleccionado <= 0)
    {
        throw invalid_argument("Debe seleccionar un mozo, una mesa, un producto y una cantidad valida.");
    }

    IKey* key = new Integer(this->mesaSeleccionada->getNumero());
    if (this->mozoSeleccionado->getMesasAsignadas()->member(key) == false)
    {
        delete key;
        throw invalid_argument("El mozo seleccionado no tiene asignada la mesa seleccionada.");
    }
    delete key;

    VentaLocal *ventaEnCurso = this->mesaSeleccionada->getVentaEnCurso();
    if (ventaEnCurso == nullptr)
    {
        throw invalid_argument("La mesa seleccionada no tiene una venta en curso.");
    }

    ventaEnCurso->agregarProducto(this->productoSeleccionado, this->cantidadProductoSeleccionado);
}

int Sistema::getCantidadProductoSeleccionado()
{
    return this->cantidadProductoSeleccionado;
}

void Sistema::setCantidadProductoSeleccionado(int cantidad)
{
    if (cantidad <= 0)
    {
        throw invalid_argument("La cantidad debe ser mayor a 0.");
    }
    this->cantidadProductoSeleccionado = cantidad;
}

void Sistema::cancelarAgregarProductoAVenta()
{
    // Limpiar las selecciones temporales
    this->mozoSeleccionado = nullptr;
    this->mesaSeleccionada = nullptr;
    this->ventaSeleccionada = nullptr;
    this->productoSeleccionado = nullptr;
}

// ####### --------------- Quitar producto de una venta --------------- #######
void Sistema::verificarMesaSeleccionadaConVentaEnCurso()
{
    if (this->mesaSeleccionada->getVentaEnCurso() == nullptr)
    {
        throw invalid_argument("La mesa seleccionada no tiene una venta en curso.");
    }

    this->ventaSeleccionada = this->mesaSeleccionada->getVentaEnCurso();
    cout << "Venta seleccionada: " << this->ventaSeleccionada->getCodigo() << endl;
}

void Sistema::listarProductosVentaSeleccionada()
{
    VentaLocal *venta = (VentaLocal *)this->ventaSeleccionada;

    if (venta->getCantidadProductos() == 0)
    {
        throw invalid_argument("La venta no tiene productos o se ha quedado sin ellos.");
    }

    cout << "Productos de la venta: " << endl;
    IDictionary *consumidosVenta = venta->getProductos();
    IIterator *it = consumidosVenta->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *plato = (DtPlato *)it->getCurrent();
        if (plato != nullptr)
        {
            cout << *plato << endl;
        }
        else
        {
            DtMenu *menu = (DtMenu *)it->getCurrent();
            cout << *menu << endl;
        }
        it->next();
    }
    delete it;
    consumidosVenta->clearDictionary();
    delete consumidosVenta;
}

void Sistema::seleccionarProductoDeVenta(string codigoProducto)
{
    char *codigo = new char[codigoProducto.size() + 1];
    strcpy(codigo, codigoProducto.c_str());

    IKey *key = new String(codigo);

    this->productoSeleccionado = dynamic_cast<Producto *>(this->productos->find(key));

    if (this->productoSeleccionado == nullptr)
    {
        delete key;
        delete[] codigo; // Liberar memoria del codigo
        throw invalid_argument("El producto seleccionado no existe.");
    }

    IDictionary *productosVenta = this->ventaSeleccionada->getProductos();

    if (!productosVenta->member(key))
    {
        delete key;
        delete[] codigo;
        productosVenta->clearDictionary(); // Limpiar la coleccion de productos
        delete productosVenta;             // Liberar memoria de la coleccion
        throw invalid_argument("El producto seleccionado no pertenece a la venta.");
    }

    delete key;
    productosVenta->clearDictionary(); // Setear a null el producto seleccionado en la coleccion
    delete productosVenta;             // Liberar memoria de la coleccion
    delete[] codigo;
}

void Sistema::quitarProductoVenta(int cantidad)
{
    if (this->productoSeleccionado == nullptr || cantidad <= 0)
    {
        throw invalid_argument("Producto no seleccionado o cantidad invalida.");
    }

    if (this->ventaSeleccionada == nullptr)
    {
        throw invalid_argument("No hay una venta seleccionada.");
    }

    this->ventaSeleccionada->quitarProductoVenta(this->productoSeleccionado, cantidad);
}

void Sistema::cancelarQuitarProductoVenta()
{
    this->productoSeleccionado = nullptr; // Limpiar la variable temporal
    this->mesaSeleccionada = nullptr;     // Limpiar la mesa seleccionada
    this->ventaSeleccionada = nullptr;    // Limpiar la venta seleccionada
};

// ####### --------------- Facturacion de un dia --------------- #######
DtInforme Sistema::consultarFacturacion(DtFecha fecha)
{
    if (this->ventas->isEmpty())
    {
        throw invalid_argument("No hay ventas registradas en el sistema.");
    }

    IIterator *it = this->ventas->getIterator();
    int contador = 0;
    float totalIngresos = 0;
    IDictionary *ventasFacturadas = new OrderedDictionary();

    while (it->hasCurrent())
    {
        Venta *venta = (Venta *)it->getCurrent();

        if (venta->estaFacturada())
        {
            if (venta->getFactura()->getFecha() == fecha)
            {
                contador++;
                ventasFacturadas->add(new Integer(venta->getCodigo()), venta);
                totalIngresos += venta->getFactura()->getMontoTotal();
            }
        }
        it->next();
    }

    if (contador == 0)
        throw invalid_argument("No se encontraron ventas facturadas para la fecha proporcionada.");

    delete it; // Liberar memoria del iterador

    return DtInforme(totalIngresos, ventasFacturadas);
};

/*************  ✨ Windsurf Command ⭐  *************/
/*******  a9df266d-0516-4d10-9217-e269e4c02af0  *******/
void Sistema::imprimirInforme(DtInforme informe)
{
    cout << "Total Ingresos: " << informe.getTotalIngresos() << endl;
    cout << "Ventas Facturadas:" << endl;

    IIterator *it = informe.getVentas()->getIterator();
    while (it->hasCurrent())
    {
        Venta *venta = (Venta *)it->getCurrent();
        if ((VentaLocal *)venta != nullptr)
        {
            this->imprimirFacturaLocal(venta->mostrarFacturaLocal());
        }
        else
        {
            this->imprimirFacturaDomicilio(venta->mostrarFacturaDomicilio());
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::mostrarVentasMozo(DtFecha fechaInicio, DtFecha fechaFin)
{
    bool ventasEncontradas = false;

    IIterator *it = this->ventas->getIterator();
    while (it->hasCurrent())
    {
        VentaLocal *venta = dynamic_cast<VentaLocal *>(it->getCurrent());
        if (venta != nullptr)
        {
            if (venta->estaFacturada())
            {
                FacturaLocal *factura = dynamic_cast<FacturaLocal *>(venta->getFactura());
                if (factura->getFecha() >= fechaInicio && factura->getFecha() <= fechaFin && factura->getNombreMozo() == this->mozoSeleccionado->getNombre())
                {
                    ventasEncontradas = true;
                    this->imprimirFacturaLocal(venta->mostrarFacturaLocal());
                }
            }
        }
        it->next();
    }

    if (!ventasEncontradas)
    {
        cout << "No se encontraron ventas facturadas para el mozo en el rango de fechas proporcionado." << endl;
    }
}

// // ####### --------------- Utils --------------- #######

void Sistema::poblarSistema()
{
    // Crear empleados
    cout << "Crear empledaos: ";
    Mozo *emp1 = new Mozo("Juan");
    Mozo *emp2 = new Mozo("Maria");
    Mozo *emp3 = new Mozo("Luis");
    Mozo *emp4 = new Mozo("Ana");
    Mozo *emp5 = new Mozo("Sofia");
    Mozo *emp6 = new Mozo("Carlos");
    Mozo *emp7 = new Mozo("Lucia");
    Mozo *emp8 = new Mozo("Miguel");
    Mozo *emp9 = new Mozo("Elena");
    Repartidor *emp10 = new Repartidor("Pedro", Bicicleta);

    // Agregar empleados al sistema
    cout << "ADD empledaos: ";
    this->empleados->add(new Integer(emp1->getNumero()), emp1);
    this->empleados->add(new Integer(emp2->getNumero()), emp2);
    this->empleados->add(new Integer(emp3->getNumero()), emp3);
    this->empleados->add(new Integer(emp4->getNumero()), emp4);
    this->empleados->add(new Integer(emp5->getNumero()), emp5);
    this->empleados->add(new Integer(emp6->getNumero()), emp6);
    this->empleados->add(new Integer(emp7->getNumero()), emp7);
    this->empleados->add(new Integer(emp8->getNumero()), emp8);
    this->empleados->add(new Integer(emp9->getNumero()), emp9);
    this->empleados->add(new Integer(emp10->getNumero()), emp10);

    // Crear productos
    cout << "Crear platos: ";
    Plato *plato1 = new Plato(DtPlato((char *)"P001", "Ensalada Caesar", 150.0));
    Plato *plato2 = new Plato(DtPlato((char *)"P002", "Pizza Margherita", 200.0));
    Plato *plato3 = new Plato(DtPlato((char *)"P003", "Sopa de Tomate", 100.0));
    Menu *menu1 = new Menu(DtMenu((char *)"M001", "Menu del Dia"));
    cout << "ADD Platos: ";
    menu1->anadirPlato(plato1, 1);
    menu1->anadirPlato(plato2, 2);

    // Agregar productos al sistema
    cout << "ADD productos: ";
    this->productos->add(new String(plato1->getCodigo()), plato1);
    this->productos->add(new String(plato2->getCodigo()), plato2);
    this->productos->add(new String(plato3->getCodigo()), plato3);
    this->productos->add(new String(menu1->getCodigo()), menu1);

    // Crear cliente
    cout << "Creando clientes con casa" << endl;
    Cliente *cliente1 = new Cliente(DtCliente("Carlos", "123456789", DtDireccionCasa("Av. Libertador", "1234", "Entre Calles 1 y 2")));
    Cliente *cliente2 = new Cliente(DtCliente("Ana", "987654321", DtDireccionCasa("Calle 8", "5678", "Entre Calles 3 y 4")));
    Cliente *cliente3 = new Cliente(DtCliente("Luis", "555123456", DtDireccionCasa("Boulevard Artigas", "4321", "Esq. Rivera")));
    Cliente *cliente4 = new Cliente(DtCliente("Sofia", "222333444", DtDireccionCasa("Camino Maldonado", "1010", "Entre Calles 5 y 6")));
    Cliente *cliente5 = new Cliente(DtCliente("Miguel", "888777666", DtDireccionCasa("Av. Italia", "2020", "Esq. Propios")));
    Cliente *cliente6 = new Cliente(DtCliente("Lucia", "444555666", DtDireccionCasa("Calle 25 de Mayo", "3030", "Entre Calles 7 y 8")));
    this->clientes->add(new String(cliente1->getTelefono().c_str()), cliente1);
    this->clientes->add(new String(cliente2->getTelefono().c_str()), cliente2);
    this->clientes->add(new String(cliente3->getTelefono().c_str()), cliente3);
    this->clientes->add(new String(cliente4->getTelefono().c_str()), cliente4);
    this->clientes->add(new String(cliente5->getTelefono().c_str()), cliente5);
    this->clientes->add(new String(cliente6->getTelefono().c_str()), cliente6);

    cout << "Creando clientes con dpto" << endl;
    Cliente *cliente7 = new Cliente(DtCliente("Fernando", "111222333", DtDireccionApto("Av. Brasil", "1500", "", "Apto 101", "Edificio Sol")));
    Cliente *cliente8 = new Cliente(DtCliente("Valeria", "444333222", DtDireccionApto("Calle 18 de Julio", "", "2500", "Apto 202", "Edificio Luna")));
    Cliente *cliente9 = new Cliente(DtCliente("Martina", "777888999", DtDireccionApto("Rambla Francia", "", "3500", "Apto 303", "Edificio Mar")));
    Cliente *cliente10 = new Cliente(DtCliente("Diego", "666555444", DtDireccionApto("Camino Carrasco", "", "4500", "Apto 404", "Edificio Río")));
    Cliente *cliente11 = new Cliente(DtCliente("Paula", "999000111", DtDireccionApto("Av. Rivera", "5500", "", "Apto 505", "Edificio Parque")));
    Cliente *cliente12 = new Cliente(DtCliente("Santiago", "333444555", DtDireccionApto("Calle Colonia", "Esto es un cruce jaj", "6500", "Apto 606", "Edificio Centro")));
    this->clientes->add(new String(cliente7->getTelefono().c_str()), cliente7);
    this->clientes->add(new String(cliente8->getTelefono().c_str()), cliente8);
    this->clientes->add(new String(cliente9->getTelefono().c_str()), cliente9);
    this->clientes->add(new String(cliente10->getTelefono().c_str()), cliente10);
    this->clientes->add(new String(cliente11->getTelefono().c_str()), cliente11);
    this->clientes->add(new String(cliente12->getTelefono().c_str()), cliente12);

    // Crear ventas
    cout << "Crear Ventas: ";
    VentaLocal *venta1 = new VentaLocal();
    // VentaDomicilio *venta2 = new VentaDomicilio(cliente1->getDatos());
    VentaLocal *venta3 = new VentaLocal();
    cout << "Crear Asignar productos: ";
    venta1->agregarProducto(plato1, 2);
    venta1->agregarProducto(plato2, 1);
    // venta2->agregarProducto(plato3, 1);
    venta3->agregarProducto(plato3, 3);
    // Crear mesas
    cout << "Crear Mesas: ";
    Mesa *mesa1 = new Mesa();
    Mesa *mesa2 = new Mesa();
    Mesa *mesa3 = new Mesa();
    Mesa *mesa4 = new Mesa();
    Mesa *mesa5 = new Mesa();
    Mesa *mesa6 = new Mesa();
    Mesa *mesa7 = new Mesa();
    Mesa *mesa8 = new Mesa();
    Mesa *mesa9 = new Mesa();
    Mesa *mesa10 = new Mesa();
    Mesa *mesa11 = new Mesa();
    Mesa *mesa12 = new Mesa();
    Mesa *mesa13 = new Mesa();
    Mesa *mesa14 = new Mesa();
    Mesa *mesa15 = new Mesa();
    Mesa *mesa16 = new Mesa();
    Mesa *mesa17 = new Mesa();
    Mesa *mesa18 = new Mesa();
    Mesa *mesa19 = new Mesa();
    Mesa *mesa20 = new Mesa();

    // Agregar mesas al sistema
    this->mesas->add(new Integer(mesa1->getNumero()), mesa1);
    this->mesas->add(new Integer(mesa2->getNumero()), mesa2);
    this->mesas->add(new Integer(mesa3->getNumero()), mesa3);
    this->mesas->add(new Integer(mesa4->getNumero()), mesa4);
    this->mesas->add(new Integer(mesa5->getNumero()), mesa5);
    this->mesas->add(new Integer(mesa6->getNumero()), mesa6);
    this->mesas->add(new Integer(mesa7->getNumero()), mesa7);
    this->mesas->add(new Integer(mesa8->getNumero()), mesa8);
    this->mesas->add(new Integer(mesa9->getNumero()), mesa9);
    this->mesas->add(new Integer(mesa10->getNumero()), mesa10);
    this->mesas->add(new Integer(mesa11->getNumero()), mesa11);
    this->mesas->add(new Integer(mesa12->getNumero()), mesa12);
    this->mesas->add(new Integer(mesa13->getNumero()), mesa13);
    this->mesas->add(new Integer(mesa14->getNumero()), mesa14);
    this->mesas->add(new Integer(mesa15->getNumero()), mesa15);
    this->mesas->add(new Integer(mesa16->getNumero()), mesa16);
    this->mesas->add(new Integer(mesa17->getNumero()), mesa17);
    this->mesas->add(new Integer(mesa18->getNumero()), mesa18);
    this->mesas->add(new Integer(mesa19->getNumero()), mesa19);
    this->mesas->add(new Integer(mesa20->getNumero()), mesa20);

    asignarMesasMozos(cantMozosAsignados, cantMesasAsignadas); // Asignar 2 mesas (20, 9) para usar el "SetVentaEnCurso"

    mesa20->setVentaEnCurso(venta1);
    mesa19->setVentaEnCurso(venta3);

    // Agregar ventas al sistema
    this->ventas->add(new Integer(venta1->getCodigo()), venta1);
    // this->ventas->add(new Integer(venta2->getCodigo()), venta2);
    this->ventas->add(new Integer(venta3->getCodigo()), venta3);
}

int Sistema::getCantidadProductos()
{
    return this->productos->getSize();
}

void Sistema::listarEmpleados()
{
    cout << "--- Empleados del Sistema ---" << endl;
    IIterator *it = this->empleados->getIterator();
    while (it->hasCurrent())
    {
        Mozo *mozo = dynamic_cast<Mozo *>(it->getCurrent());
        if (mozo == nullptr)
        {
            Repartidor *repartidor = dynamic_cast<Repartidor *>(it->getCurrent());
            cout << *repartidor << endl;
        }
        else
        {
            cout << *mozo << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarVentas()
{
    cout << endl
         << "--- Ventas del Sistema ---" << endl;
    IIterator *it = this->ventas->getIterator();
    while (it->hasCurrent())
    {
        VentaLocal *ventaLocal = dynamic_cast<VentaLocal *>(it->getCurrent());
        if (ventaLocal != nullptr)
        {
            cout << *ventaLocal << endl;
        }
        else
        {
            VentaDomicilio *ventaDomicilio = dynamic_cast<VentaDomicilio *>(it->getCurrent());
            cout << *ventaDomicilio << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarMesas()
{
    cout << endl
         << "--- Mesas del Sistema ---" << endl;
    IIterator *it = this->mesas->getIterator();
    while (it->hasCurrent())
    {
        Mesa *mesa = dynamic_cast<Mesa *>(it->getCurrent());
        cout << *mesa << endl;
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::listarMesasConVentasEnCurso()
{
    if (this->mozoSeleccionado == nullptr)
    {
        throw invalid_argument("Debe seleccionar un mozo antes de listar las mesas con ventas en curso.");
        return;
    }

    cout << "--- Mesas del Sistema ---" << endl;
    IIterator *it = this->mozoSeleccionado->getMesasAsignadas()->getIterator();
    while (it->hasCurrent())
    {
        Mesa *mesa = (Mesa *)it->getCurrent();
        if (mesa->getVentaEnCurso() != nullptr)
        {
            cout << *mesa << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    cout << endl << "-------------------------" << endl;
}

void Sistema::listarProductos()
{
    cout << endl
         << "--- Productos del Sistema ---" << endl;
    IIterator *it = this->productos->getIterator();
    while (it->hasCurrent())
    {
        Plato *plato = dynamic_cast<Plato *>(it->getCurrent());
        if (plato != nullptr)
        {
            cout << *plato << endl;
        }
        else
        {
            Menu *menu = dynamic_cast<Menu *>(it->getCurrent());
            cout << *menu << endl;
        }

        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::imprimirFacturaLocal(DtFacturaLocal factura)
{
    cout << endl
         << "-------------------------" << endl;
    cout << "Factura Local:" << endl;
    cout << "Codigo: " << factura.getCodigo() << endl;
    cout << "Fecha: " << factura.getFecha() << endl;
    cout << "Hora: " << factura.getHora() << endl;
    cout << "Subtotal: " << factura.getSubtotal() << endl;
    cout << "Descuento: " << factura.getDescuento() << "%" << endl;
    cout << "Monto Total: " << factura.getMontoTotal() << endl;
    cout << "IVA Total: " << factura.getIvaTotal() << endl;
    cout << "Nombre Mozo: " << factura.getNombreMozo() << endl;
}

void Sistema::imprimirFacturaDomicilio(DtFacturaDomicilio factura)
{
    string transporteStr;
    switch (factura.getTransporte())
    {
    case aPie:
        transporteStr = "A pie";
        break;
    case Moto:
        transporteStr = "Moto";
        break;
    case Bicicleta:
        transporteStr = "Bicicleta";
        break;
    case Auto:
        transporteStr = "Auto";
        break;
    }

    cout << endl
         << "-------------------------" << endl;
    cout << "Factura Domicilio:" << endl;
    cout << "Codigo: " << factura.getCodigo() << endl;
    cout << "Fecha: " << factura.getFecha() << endl;
    cout << "Hora: " << factura.getHora() << endl;
    cout << "Subtotal: " << factura.getSubtotal() << endl;
    cout << "Descuento: " << factura.getDescuento() << "%" << endl;
    cout << "Monto Total: " << factura.getMontoTotal() << endl;
    cout << "IVA Total: " << factura.getIvaTotal() << endl;
    cout << "Nombre Repartidor: " << factura.getNombreRepartidor() << endl;
    cout << "Transporte: " << transporteStr << endl;
    cout << "-------------------------" << endl;
}

void Sistema::seleccionarTransporte(Transporte transporte)
{
    this->transporteSeleccionado = transporte;
}

void Sistema::agregarEmpleado(string nombre, string tipoEmpleado)
{
    this->nombreEmpleado = nombre;
    this->tipoEmpleado = tipoEmpleado;
}

int Sistema::darDeAltaEmpleado()
{
    if (this->tipoEmpleado == "Mozo")
    {
        Mozo *mozo = new Mozo(this->nombreEmpleado);
        this->empleados->add(new Integer(mozo->getNumero()), mozo);
        this->cancelarAltaEmpleado(); // Limpiar los datos del empleado temporal
        return mozo->getNumero();
    }
    else
    {
        Repartidor *repartidor = new Repartidor(this->nombreEmpleado, this->transporteSeleccionado);
        this->empleados->add(new Integer(repartidor->getNumero()), repartidor);
        this->cancelarAltaEmpleado(); // Limpiar los datos del empleado temporal
        return repartidor->getNumero();
    }
}

void Sistema::cancelarAltaEmpleado()
{
    this->nombreEmpleado = "";
    this->tipoEmpleado = "";
    this->transporteSeleccionado = Transporte::undefinedTransporte;
}

void Sistema::listarProductoTemporal()
{
    if (this->productoCreado == nullptr)
    {
        cout << "No hay un producto temporal creado." << endl;
        return;
    }
    cout << "--- Producto Temporal ---" << endl;
    Plato *plato = dynamic_cast<Plato *>(this->productoCreado);
    if (plato != nullptr)
    {
        cout << *plato << endl;
    }
    else
    {
        Menu *menu = dynamic_cast<Menu *>(this->productoCreado);
        cout << *menu << endl;
    }
}

void Sistema::listarTransportes()
{
    string transportes[] = {"A pie", "Moto", "Bicicleta", "Auto"};
    cout << "Transportes disponibles:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << transportes[i] << endl;
    }
}

void Sistema::listarMozos()
{
    cout << "--- Mozos del Sistema ---" << endl;
    IIterator *it = this->empleados->getIterator();
    while (it->hasCurrent())
    {
        Mozo *mozo = dynamic_cast<Mozo *>(it->getCurrent());
        if (mozo != nullptr)
        {
            cout << *mozo << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

bool Sistema::validarFecha(string fecha)
{
    if (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/')
    {
        return false; // Formato incorrecto
    }

    return true; // Formato correcto
}

void Sistema::iniciarVenta(string codigo)
{
    if (this->mozoSeleccionado == nullptr)
    {
        throw invalid_argument("Debe seleccionar un mozo antes de iniciar una venta.");
    }

    ICollection *mesasAsignadas = this->mozoSeleccionado->getMesasAsignadasSinVentaEnCurso();
    if (mesasAsignadas == 0)
    {
        throw invalid_argument("El mozo no tiene mesas asignadas.");
    }
    cout << "Mesas asignadas al mozo " << this->mozoSeleccionado->getNombre() << ":" << endl;
    IIterator *it = mesasAsignadas->getIterator();
    while (it->hasCurrent())
    {
        Mesa *mesa = (Mesa *)it->getCurrent();
        cout << "Mesa numero:" << mesa->getNumero() << endl;
        it->next();
    }
    delete it;             // Liberar memoria del iterador
    delete mesasAsignadas; // Liberar memoria de las mesas asignadas
    return;
}

void Sistema::addMesaElegida()
{
    if (
        this->mesaSeleccionada == nullptr ||
        this->mesaSeleccionada->getMozo() != this->mozoSeleccionado ||
        this->mesaSeleccionada->getVentaEnCurso() != nullptr)
    {
        this->mesaSeleccionada = nullptr;
        throw invalid_argument("La mesa seleccionada no pertenece al mozo seleccionado o tiene una venta en curso.");
    }
    this->mesasElegidas->add(this->mesaSeleccionada);
    this->mesaSeleccionada = nullptr;
}
ICollection *Sistema::getMesasElegidas()
{
    return this->mesasElegidas;
}

void Sistema::mostrarMesasElegidas(bool verDatos = false)
{
    cout << "Mesas elegidas:" << endl;
    if (this->mesasElegidas == nullptr || this->mesasElegidas->isEmpty())
    {
        cout << "No hay mesas elegidas." << endl;
        return;
    }
    IIterator *it = this->mesasElegidas->getIterator();
    if (!verDatos)
    {
        while (it->hasCurrent())
        {
            Mesa *mesa = (Mesa *)it->getCurrent();
            cout << mesa->getNumero() << ", ";
            it->next();
        }
    }
    else
    {
        while (it->hasCurrent())
        {
            Mesa *mesa = (Mesa *)it->getCurrent();
            cout << "Mesa numero: " << mesa->getNumero();
            cout << " | Mozo: " << mesa->getMozo()->getNombre();
            cout << " | Venta en curso: " << (mesa->getVentaEnCurso() != nullptr ? "Error. Reporten a soporte" : "No");

            cout << endl;
            it->next();
        }
    }

    cout << endl;
    delete it; // Liberar memoria del iterador
}

void Sistema::darAltaVenta()
{
    // Se crea la venta local
    // Se pone en venta en curso en true
    // Se agrega a venta
    if (this->mesasElegidas->isEmpty())
    {
        throw invalid_argument("No hay mesas elegidas para iniciar una venta.");
    }
    IIterator *it = this->mesasElegidas->getIterator();
    while (it->hasCurrent())
    {
        Mesa *mesa = (Mesa *)it->getCurrent();
        if (mesa->getVentaEnCurso() != nullptr)
        {
            throw invalid_argument("La mesa " + to_string(mesa->getNumero()) + " ya tiene una venta en curso.");
        }
        VentaLocal *ventaLocal = new VentaLocal();
        mesa->setVentaEnCurso(ventaLocal);
        this->ventas->add(new Integer(ventaLocal->getCodigo()), ventaLocal);
        cout << "Venta iniciada para la mesa " << mesa->getNumero() << endl;
        it->next();
    }
    delete it;                              // Liberar memoria del iterador
    this->mesasElegidas->clearCollection(); // Limpiar las mesas elegidas
    this->mesaSeleccionada = nullptr;       // Limpiar la mesa seleccionada
    this->mozoSeleccionado = nullptr;       // Limpiar el mozo seleccionado

    cout << "Todas las mesas elegidas han sido procesadas y se ha iniciado una venta en curso para cada una." << endl;
}

void Sistema::cancelarAltaVenta()
{
    cout << "Cancelando la alta de venta." << endl;
    this->mesasElegidas->clearCollection(); // Limpiar la coleccion temporal
    this->mesaSeleccionada = nullptr;       // Limpiar la mesa seleccionada
    this->mozoSeleccionado = nullptr;       // Limpiar el mozo seleccionado
    cout << "No hay mesas elegidas para cancelar." << endl;
}

DtInfoProducto *Sistema::obtenerProducto(string codigo)
{
    IKey *key = new String(codigo.c_str());
    Producto *producto = (Producto *)this->productos->find(key);
    delete key; // Liberar memoria del key

    if (producto == nullptr)
    {
        throw invalid_argument("El producto con el codigo proporcionado no existe.");
    }

    int cantidadVentas = 0;
    IIterator *it = this->ventas->getIterator();
    while (it->hasCurrent())
    {
        Venta *venta = (Venta *)it->getCurrent();
        if (venta->contieneProducto(producto))
        {
            cantidadVentas++;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
    cout << "Cantidad de ventas del producto " << codigo << ": " << cantidadVentas << endl;
    return new DtInfoProducto((DtProducto *)producto, cantidadVentas);
}

// ####### --------------- ASIGNAR MESAS MOZO --------------- #######

bool Sistema::hayVentasEnCurso()
{
    IIterator *it = this->ventas->getIterator();
    while (it->hasCurrent())
    {
        Venta *venta = (Venta *)it->getCurrent();
        if (!venta->estaFacturada())
        {
            delete it;   // Liberar memoria del iterador
            return true; // Hay al menos una venta en curso
        }
        it->next();
    }
    delete it;
    return false; // No hay ventas en curso
}

void Sistema::asignarMesasMozos(int cantMozos, int cantMesas)
{

    if (cantMozos > cantMesas)
    {
        throw invalid_argument("No se pueden asignar mas mozos que mesas.");
    }

    if (cantMesas > this->mesas->getSize())
    {
        throw invalid_argument("No hay suficientes mesas para asignar a los mozos.");
    }

    if (hayVentasEnCurso())
    {
        throw invalid_argument("No se pueden asignar mesas a mozos mientras haya ventas en curso.");
    }

    IIterator *itMesas = this->mesas->getIterator();
    IDictionary *mesasDisponibles = new OrderedDictionary();

    // Verificar que haya suficientes mesas
    while (itMesas->hasCurrent() && mesasDisponibles->getSize() < cantMesas)
    {
        Mesa *mesa = dynamic_cast<Mesa *>(itMesas->getCurrent());
        if (mesa != nullptr)
        {
            if (mesa->getMozo() == nullptr) // Solo agregar mesas sin mozo asignado
            {
                mesasDisponibles->add(new Integer(mesa->getNumero()), mesa);
            }
        }
        itMesas->next();
    }

    int contadorMesas = mesasDisponibles->getSize();

    delete itMesas; // Liberar memoria del iterador

    IIterator *itEmpleados = this->empleados->getIterator();
    IDictionary *mozosDisponibles = new OrderedDictionary();

    // Verificar que haya suficientes mozos
    while (itEmpleados->hasCurrent() && mozosDisponibles->getSize() < cantMozos)
    {
        Mozo *mozo = dynamic_cast<Mozo *>(itEmpleados->getCurrent());
        if (mozo != nullptr)
        {
            IKey *key = new Integer(mozo->getNumero());
            mozosDisponibles->add(key, mozo);
        }
        itEmpleados->next();
    }
    delete itEmpleados; // Liberar memoria del iterador

    int contadorMozos = mozosDisponibles->getSize();

    if (contadorMozos < cantMozos)
    {
        mozosDisponibles->clearDictionary();
        delete mozosDisponibles; // Liberar memoria del diccionario de mozos
        mesasDisponibles->clearDictionary();
        delete mesasDisponibles; // Liberar memoria del diccionario de mesas
        throw invalid_argument("No hay suficientes mozos para asignar a las mesas.");
    }

    if (contadorMesas < cantMesas)
    {
        mozosDisponibles->clearDictionary();
        delete mozosDisponibles; // Liberar memoria del diccionario de mozos
        mesasDisponibles->clearDictionary();
        delete mesasDisponibles; // Liberar memoria del diccionario de mesas
        throw invalid_argument("No hay suficientes mesas para asignar a los mozos.");
    }

    int mesasXMozo = cantMesas / cantMozos;
    int restoMesas = cantMesas % cantMozos;
    int mesasSinResto = mesasXMozo * cantMozos;

    ICollection *asignaciones = new List();
    IIterator *itMesasDisponibles = mesasDisponibles->getIterator();
    IIterator *itMozosDisponibles = mozosDisponibles->getIterator();

    while (itMesasDisponibles->hasCurrent())
    {
        Mesa *mesa = dynamic_cast<Mesa *>(itMesasDisponibles->getCurrent());

        if (!itMozosDisponibles->hasCurrent())
        {
            delete itMozosDisponibles;                            // Liberar memoria del iterador de mozos
            itMozosDisponibles = mozosDisponibles->getIterator(); // Reiniciar el iterador de mozos
            if (mesasSinResto == 0)
            {
                break;
            }
        }
        Mozo *mozo = dynamic_cast<Mozo *>(itMozosDisponibles->getCurrent());

        if (mozo->getCantidadMesasAsignadas() < mesasXMozo)
        {
            mozo->setMesaAsignada(mesa);
            DtAsignacion *asignacion = new DtAsignacion(mozo->getNumero(), mesa->getNumero());
            asignaciones->add(asignacion);
            mesasSinResto--;
        }
        else
        {
            itMozosDisponibles->next();
        }

        if (mesa->getMozo() != nullptr)
        {
            itMesasDisponibles->next();
            continue;
        }
    }

    if (itMesasDisponibles->hasCurrent())
    {
        while (itMesasDisponibles->hasCurrent())
        {
            Mozo *mozo = dynamic_cast<Mozo *>(itMozosDisponibles->getCurrent());
            Mesa *mesa = dynamic_cast<Mesa *>(itMesasDisponibles->getCurrent());
            mozo->setMesaAsignada(mesa);
            DtAsignacion *asignacion = new DtAsignacion(mozo->getNumero(), mesa->getNumero());
            asignaciones->add(asignacion);

            itMozosDisponibles->next();
            itMesasDisponibles->next();
        }
    }

    delete itMozosDisponibles;
    delete itMesasDisponibles;
    mozosDisponibles->clearDictionary();
    delete mozosDisponibles;
    mesasDisponibles->clearDictionary();
    delete mesasDisponibles;

    IIterator *itAsignaciones = asignaciones->getIterator();
    cout << "---------- Asignaciones ----------" << endl;
    while (itAsignaciones->hasCurrent())
    {
        DtAsignacion *asignacion = dynamic_cast<DtAsignacion *>(itAsignaciones->getCurrent());
        if (asignacion != nullptr)
        {
            cout << "Mozo: " << asignacion->getNumeroMozo() << " | Mesa: " << asignacion->getNumeroMesa() << endl;
        }
        itAsignaciones->next();
    }
    delete itAsignaciones;

    asignaciones->clearCollection(); // Primero vaciamos la coleccion y luego la limpiamos para no eliminar mozos ni mesas
    delete asignaciones;
}

void Sistema::agregarCliente(string nombre, string telefono, DtDireccion direccion)
{
    DtCliente clienteDatos = DtCliente(nombre, telefono, direccion);

    if (this->clienteTemporal != nullptr)
    {
        delete this->clienteTemporal; // Liberar memoria del cliente temporal anterior
        this->clienteTemporal = nullptr;
    }

    // Verificar si el cliente ya existe
    IKey *key = new String(clienteDatos.getTelefono().c_str());
    if (this->clientes->member(key))
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El cliente ya existe en el sistema.");
    }
    delete key;

    Cliente *cliente = new Cliente(clienteDatos);

    this->clienteTemporal = cliente;
}

void Sistema::mostrarClienteTemporal()
{
    if (this->clienteTemporal == nullptr)
    {
        return;
    }
    cout << "--- Cliente Temporal ---" << endl;
    cout << *this->clienteTemporal << endl;
}

void Sistema::darAltaCliente()
{
    if (this->clienteTemporal == nullptr)
    {
        throw invalid_argument("No hay cliente temporal para dar de alta.");
    }
    IKey *key = new String(this->clienteTemporal->getTelefono().c_str());
    if (this->clientes->member(key))
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El cliente ya existe en el sistema.");
    }
    this->clientes->add(key, this->clienteTemporal);
    this->clienteTemporal = nullptr; // Limpiar el cliente temporal
}

void Sistema::cancelarAltaCliente()
{
    if (this->clienteTemporal != nullptr)
    {
        delete this->clienteTemporal; // Liberar memoria del cliente temporal
        this->clienteTemporal = nullptr;
    }
}

// ####### --------------- INICIO CASO DE USO VENTA DOMICILIO --------------- #######

bool Sistema::existeCliente(string telefono)
{
    IKey *key = new String(telefono.c_str());
    bool registrado = this->clientes->member(key);
    delete key; // Liberar memoria del key
    return registrado;
}

void Sistema::seleccionarCliente(string telefono)
{
    IKey *key = new String(telefono.c_str());
    this->clienteSeleccionado = (Cliente *)this->clientes->find(key);
    delete key; // Liberar memoria del key
}

void Sistema::ventaDomicilio()
{

    while (true)
    {
        this->listarProductos();
        cout << "Ingrese el codigo del producto a agregar a la venta (o '0' para finalizar): ";
        string codigoProducto;
        cin >> codigoProducto;
    }
}

void Sistema::seleccionarProductoDomicilio(string codigo, int cantidad)
{
    IKey *key = new String(codigo.c_str());

    Producto *producto = (Producto *)this->productos->find(key);
    if (producto == nullptr)
    {
        delete key;
        throw invalid_argument("El producto con el codigo proporcionado no existe.");
    }

    delete key; // Liberar memoria del key

    IKey *keyProducto = new String(producto->getCodigo());
    ProductoVenta *productoVentaExistente = (ProductoVenta *)this->productosSeleccionadosDomicilio->find(keyProducto);

    if (productoVentaExistente != nullptr)
    {
        productoVentaExistente->setCantidad(productoVentaExistente->getCantidad() + cantidad);
    }
    else
    {
        IKey *keyProductoNuevo = new String(producto->getCodigo());
        ProductoVenta *productoVenta = new ProductoVenta(producto->getCodigo(), producto->getTipo(), producto->getDescripcion(), producto->getPrecio(), cantidad);
        this->productosSeleccionadosDomicilio->add(keyProductoNuevo, productoVenta);
    }

    this->subtotalVentaDomicilio += producto->getPrecio() * cantidad; // Actualizar el subtotal de la venta a domicilio
    this->cantidadProductosSeleccionadosDomicilio++;
    delete keyProducto; // Liberar memoria del key del producto
}

void Sistema::listarRepartidores()
{
    cout << "--- Repartidores del Sistema ---" << endl;
    IIterator *it = this->empleados->getIterator();
    while (it->hasCurrent())
    {
        Repartidor *repartidor = dynamic_cast<Repartidor *>(it->getCurrent());
        if (repartidor != nullptr)
        {
            cout << *repartidor << endl;
        }
        it->next();
    }
    delete it; // Liberar memoria del iterador
}

void Sistema::seleccionarRepartidor(int numeroRepartidor)
{
    IKey *key = new Integer(numeroRepartidor);
    this->repartidorSeleccionado = (Repartidor *)this->empleados->find(key);
    if (this->repartidorSeleccionado == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El repartidor con el numero proporcionado no existe.");
    }
    delete key; // Liberar memoria del key
}

void Sistema::cancelarVentaDomicilio()
{
    if (this->productosSeleccionadosDomicilio != nullptr)
    {
        this->productosSeleccionadosDomicilio->clearDictionary(); // Limpiar los productos seleccionados
    }
    this->repartidorSeleccionado = nullptr;            // Limpiar el repartidor seleccionado
    this->clienteSeleccionado = nullptr;               // Limpiar el cliente seleccionado
    this->cantidadProductosSeleccionadosDomicilio = 0; // Reiniciar la cantidad de productos seleccionados
    this->subtotalVentaDomicilio = 0.0;                // Reiniciar el subtotal de la venta a domicilio
}

DtFacturaDomicilio Sistema::generarFacturaDomicilio()
{
    string nombreRepartidor = this->repartidorSeleccionado->getNombre();
    Transporte transporte = this->repartidorSeleccionado->getTransporte();
    VentaDomicilio *ventaDomicilio = new VentaDomicilio(this->clienteSeleccionado->getDatos(), this->cantidadProductosSeleccionadosDomicilio, this->subtotalVentaDomicilio, this->productosSeleccionadosDomicilio);
    DtFacturaDomicilio facturaDomicilio = ventaDomicilio->generarFacturaDomicilio(nombreRepartidor, transporte);
    return facturaDomicilio;
}

/// ####### --------------- FIN CASO DE USO ASIGNAR VENTA DOMICILIO --------------- #######

// ####### --------------- BAJA PRODUCTO --------------- #######

void Sistema::mostrarProductoSeleccionado(){
    if (this->productoSeleccionado == nullptr){
        throw invalid_argument("No hay producto seleccionado.");
    }
    
    cout << "--- Producto Seleccionado ---" << endl;
    Plato *plato = dynamic_cast<Plato *>(this->productoSeleccionado);
    if (plato != nullptr){
        cout << *plato << endl;
    } else {
        Menu *menu = dynamic_cast<Menu *>(this->productoSeleccionado);
        if (menu != nullptr){
            cout << *menu << endl;
        } else {
            throw invalid_argument("El producto seleccionado no es un plato ni un menu.");
        }
    }
}

void Sistema::cancelarBajaProducto(){
    this->productoSeleccionado = nullptr; 
    this->ventaSeleccionada = nullptr;
}

void Sistema::quitarProductoDelSistema(char* codigo){

    Producto* productoEliminar = (Producto*)this->productos->find(new String(codigo));
    if(productoEliminar == nullptr){
        throw invalid_argument("El producto no existe.");
    }

    try{
        seleccionarProducto(codigo);
    }catch(const invalid_argument& e){
        throw invalid_argument("El producto no existe.");
    }

    IIterator* it = this->ventas->getIterator();
    IDictionary* ventasSinFacturaConProducto = new OrderedDictionary();

    while(it->hasCurrent()){
        Venta* venta = (Venta*)it->getCurrent();
        IDictionary* productos = venta->getProductos();

        if(productos->member(new String(this->productoSeleccionado->getCodigo())) && !venta->estaFacturada()){
            ventasSinFacturaConProducto->add(new Integer(venta->getCodigo()), venta);
        }        

        it->next();
    }
    delete it;
    
    if(!ventasSinFacturaConProducto->isEmpty()){
        throw invalid_argument("Hay ventas en curso con el producto seleccionado.");
    }

    ventasSinFacturaConProducto->clearDictionary();
    delete ventasSinFacturaConProducto;

    IIterator * borrarVenta = this->ventas->getIterator();

    while(borrarVenta->hasCurrent()){
        Venta* venta = (Venta*)borrarVenta->getCurrent();
        IDictionary* productos = venta->getProductos();
        IKey* key = new String(this->productoSeleccionado->getCodigo());

        if(productos->member(key) && venta->estaFacturada()){
            venta->quitarProductoVenta(this->productoSeleccionado->getCodigo());
        }

        borrarVenta->next();
    }
    delete borrarVenta;

    Plato* plato = dynamic_cast<Plato*>(this->productoSeleccionado);
    if (plato != nullptr)
    {
        IIterator* borrarPlato = this->productos->getIterator();
        while(borrarPlato->hasCurrent())
        {
            Menu* menu = dynamic_cast<Menu*>(borrarPlato->getCurrent());
            if(menu != nullptr)
            {
                menu->quitarPlato(plato);
                if(menu->getPlatos()->isEmpty())
                {
                    quitarProductoDelSistema(menu->getCodigo());
                }
            }
            borrarPlato->next();
        }
        delete borrarPlato;

        this->productos->remove(new String(plato->getCodigo()));
    }else{
        Menu* menu = dynamic_cast<Menu*>(this->productoSeleccionado);
        this->productos->remove(new String(menu->getCodigo()));
    }

}

Sistema::~Sistema()
{
    delete empleados;
    delete ventas;
    delete mesas;
    delete productos;

    // Limpiar variables de alta de producto
    if (productoCreado != NULL)
    {
        delete productoCreado;
        productoCreado = NULL;
    }
    tipoProductoSeleccionado = TipoProducto::undefinedTipo;

    instance = NULL; // Limpiar la instancia unica
}
