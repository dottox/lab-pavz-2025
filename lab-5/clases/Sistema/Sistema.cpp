#include "Sistema.h"

#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../ICollection/interfaces/IKey.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../datatypes/Cliente/DtCliente.h"

Sistema *Sistema::instance = NULL;

Sistema::Sistema()
{
    this->empleados = new OrderedDictionary();
    this->mesas = new OrderedDictionary();
    this->productos = new OrderedDictionary();
    this->ventas = new OrderedDictionary();
    this->mesasElegidas = new List();

    // Inicializar variables de alta de producto
    this->tipoProductoSeleccionado = TipoProducto::undefinedTipo;
    this->productoCreado = NULL;

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
        throw invalid_argument("El plato con el código proporcionado no existe.");
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
            cout << "El menú no contiene platos." << endl;
            this->cancelarAltaProducto(); // Limpiar el producto creado
            throw invalid_argument("El menú no contiene platos, no se puede dar de alta.");
        }
    }

    this->productos->add(key, this->productoCreado);
    this->productoCreado = nullptr; // Limpiar la variable temporal
}

void Sistema::cancelarAltaProducto()
{
    if (this->productoCreado != nullptr)
    {
        cout << "Cancelando la creación del producto: " << this->productoCreado->getCodigo() << endl;
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

void Sistema::seleccionarProducto(char *codigo)
{
    IKey *key = new String(codigo);
    this->prodctoSeleccionado = dynamic_cast<Producto *>(this->productos->find(key));
    if (this->prodctoSeleccionado == nullptr)
    {
        delete key; // Liberar memoria del key
        throw invalid_argument("El producto seleccionado no existe.");
    }
    delete key; // Liberar memoria del key
}

void Sistema::agregarProductoAVenta()
{
    if (this->mozoSeleccionado == nullptr || this->mesaSeleccionada == nullptr ||
        this->prodctoSeleccionado == nullptr || this->cantidadProductoSeleccionado <= 0)
    {
        throw invalid_argument("Debe seleccionar un mozo, una mesa, un producto y una cantidad valida.");
    }

    VentaLocal *ventaEnCurso = this->mesaSeleccionada->getVentaEnCurso();

    if (ventaEnCurso == nullptr)
    {
        throw invalid_argument("La mesa seleccionada no tiene una venta en curso.");
    }

    ventaEnCurso->agregarProducto(this->prodctoSeleccionado, this->cantidadProductoSeleccionado);
}

void Sistema::cancelarAgregarProductoAVenta()
{
    // Limpiar las selecciones temporales
    this->mozoSeleccionado = nullptr;
    this->mesaSeleccionada = nullptr;
    this->prodctoSeleccionado = nullptr;
    this->cantidadProductoSeleccionado = 0;
}

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

// // ####### --------------- Utils --------------- #######

void Sistema::poblarSistema()
{
    // Crear empleados
    cout << "CRear empledaos: ";
    Mozo *emp1 = new Mozo("Juan");
    Mozo *emp2 = new Mozo("Maria");
    Repartidor *emp3 = new Repartidor("Pedro", Bicicleta);

    // Agregar empleados al sistema
    cout << "ADD empledaos: ";
    this->empleados->add(new Integer(emp1->getNumero()), emp1);
    this->empleados->add(new Integer(emp2->getNumero()), emp2);
    this->empleados->add(new Integer(emp3->getNumero()), emp3);

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
    cout << "Crear cliente: ";
    DtCliente *cliente1 = new DtCliente("Carlos", "123456789", DtDireccion("Calle Falsa", 123, "Pais"));

    // Crear ventas
    cout << "Crear VCentas: ";
    VentaLocal *venta1 = new VentaLocal();
    VentaDomicilio *venta2 = new VentaDomicilio(cliente1);
    VentaLocal *venta3 = new VentaLocal();
    cout << "Crear Asignar productos: ";
    venta1->agregarProducto(plato1, 2);
    venta1->agregarProducto(plato2, 1);
    venta2->agregarProducto(plato3, 1);
    venta3->agregarProducto(plato3, 3);
    // Crear mesas
    cout << "Crear Mesas: ";
    Mesa *mesa1 = new Mesa();
    Mesa *mesa2 = new Mesa();
    Mesa *mesa3 = new Mesa();
    Mesa *mesa4 = new Mesa();
    Mesa *mesa5 = new Mesa();
    Mesa *mesa6 = new Mesa();

    emp1->setMesaAsignada(mesa1);
    emp2->setMesaAsignada(mesa2);
    emp1->setMesaAsignada(mesa3);
    emp2->setMesaAsignada(mesa4);
    emp1->setMesaAsignada(mesa5);
    emp2->setMesaAsignada(mesa6);

    cout << "Crear VentasEncuroso: ";
    mesa1->setVentaEnCurso(venta1);
    mesa2->setVentaEnCurso(venta3);
    cout << "Asignar mozos a mesas: ";

    // Agregar mesas al sistema
    this->mesas->add(new Integer(mesa1->getNumero()), mesa1);
    this->mesas->add(new Integer(mesa2->getNumero()), mesa2);
    this->mesas->add(new Integer(mesa3->getNumero()), mesa3);
    this->mesas->add(new Integer(mesa4->getNumero()), mesa4);
    this->mesas->add(new Integer(mesa5->getNumero()), mesa5);
    this->mesas->add(new Integer(mesa6->getNumero()), mesa6);

    // Agregar ventas al sistema
    this->ventas->add(new Integer(venta1->getCodigo()), venta1);
    this->ventas->add(new Integer(venta2->getCodigo()), venta2);
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
    cout << endl
         << "--- Mesas del Sistema ---" << endl;
    IIterator *it = this->mesas->getIterator();
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
    cout << endl
         << "-------------------------" << endl;
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
    cout << "-------------------------" << endl;
}

void Sistema::imprimirFacturaDomicilio(DtFacturaDomicilio factura)
{
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
    cout << "Transporte: " << factura.getTransporte() << endl;
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
        return mozo->getNumero();
    }
    else
    {
        Repartidor *repartidor = new Repartidor(this->nombreEmpleado, this->transporteSeleccionado);
        this->empleados->add(new Integer(repartidor->getNumero()), repartidor);
    }
    this->nombreEmpleado = "";
    this->tipoEmpleado = "";
    this->transporteSeleccionado = Transporte::undefinedTransporte;
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

void Sistema::iniciarVenta(string codigo)
{
    if(this->mozoSeleccionado == nullptr)
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
        this->mesaSeleccionada->getVentaEnCurso() != nullptr
    )
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
    delete it;                     // Liberar memoria del iterador
    this->mesasElegidas->clearCollection(); // Limpiar las mesas elegidas
    this->mesaSeleccionada = nullptr; // Limpiar la mesa seleccionada
    this->mozoSeleccionado = nullptr; // Limpiar el mozo seleccionado

    cout << "Todas las mesas elegidas han sido procesadas y se ha iniciado una venta en curso para cada una." << endl;
}

void Sistema::cancelarAltaVenta()
{
    cout << "Cancelando la alta de venta." << endl;
    this->mesasElegidas->clearCollection();    // Limpiar la coleccion temporal
    this->mesaSeleccionada = nullptr; // Limpiar la mesa seleccionada
    this->mozoSeleccionado = nullptr; // Limpiar el mozo seleccionado
    cout << "No hay mesas elegidas para cancelar." << endl;
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

    instance = NULL; // Limpiar la instancia única
}
