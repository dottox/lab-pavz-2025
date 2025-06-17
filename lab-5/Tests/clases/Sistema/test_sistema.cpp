#include "../../doctest.h"
#include "../../../clases/Sistema/Sistema.h"
#include <iostream>
using namespace std;
// /**
//  *  // ###### --------------- Alta producto ---------------  #######
//     /*
//      * @brief El sistema guarda temporalmente el tipo de producto a crear.
//      * @param tipoProducto --> TipoProducto (Plato o Menu).
//      */
//     void seleccionarTipoProducto(TipoProducto);

//     /**
//      * @brief Crea un menu y lo guarda temporalmente en una variable del sistema.
//      * @param DtMenu --> Datos del menu a crear.
//      */
//     void crearMenu(DtMenu);

//     /**
//      * @brief Crea un plato y lo guarda temporalmente en una variable del sistema.
//      * @param DtPlato --> Datos del plato a crear.
//      */
//     void crearPlato(DtPlato);

//     /**
//      * @brief Lista todos los platos del sistema
//      * @return ICollection* --> Set<DtPlato>.
//      */
//     ICollection *obtenerPlatos();

//     /**
//      * @brief Anade un plato a un menu.
//      * @param codigo --> Codigo del plato a anadir.
//      * @param cantidad --> Cantidad de platos a anadir al menu.
//      * @note El sistema ya guarda en una variable el menu al que se le anadira el plato.
//      */
//     void anadirPlatoAMenu(char *, int);

//     /**
//      * @brief Crea el producto y lo guarda en el sistema.
//      */
//     void darAltaProducto();

//     /**
//      * @brief Cancela la creacion del producto.
//      */
//     void cancelarAltaProducto();

//     // ####### --------------- Alta producto --------------- #######

// */

TEST_SUITE_BEGIN("Sistema Tests");
TEST_CASE("Alta Producto")
{

    ISistema *sistema = Sistema::getInstance();
    // Imprimir cada plato

    // Seleccionar tipo de producto
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Crear un plato
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);

    // Obtener platos
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Platos obtenidos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);

    // Crear 2 platos mas
    DtPlato plato2("Plato", "Pizza con queso", 12.0);
    DtPlato plato3("Plato", "Ensalada fresca", 8.0);

    platos->add(new DtPlato(plato2));
    platos->add(new DtPlato(plato3));

    CHECK(platos->getSize() == 7);

    // Recorrer cada plato y verificar su tipo
    IIterator *it = platos->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        CHECK(p->getTipo() == TipoProducto::TipoPlato);
        it->next();
    }

    // Ahora creamos un menu
    sistema->seleccionarTipoProducto(TipoProducto::TipoMenu);
    // Crear un menu
    sistema->crearMenu(DtMenu("Menu Especial", "Un menu especial con varios platos"));
    // Listar platos
    ICollection *platosMenu = sistema->obtenerPlatos();

    CHECK(platosMenu->getSize() == 5); // 3 platos +

    // Recorrer cada plato y, ponerlo en el menu

    it = platosMenu->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getTipo() == TipoProducto::TipoPlato)
        {
            // Anadir al menu
            sistema->anadirPlatoAMenu(p->getCodigo(), 1);
        }
        it->next();
    }
    delete it;

    // Verificar que el menu tiene los platos anadidos
    ICollection *platosDelMenu = sistema->obtenerPlatos();
    CHECK(platosDelMenu->getSize() == 5); // 3 platos
    // Recorrer cada plato del menu y verificar que estan en el menu
    it = platosDelMenu->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getTipo() == TipoProducto::TipoMenu)
        {
            // Verificar que el menu tiene los platos anadidos
            CHECK(p->getCodigo() == "Menu Especial");
        }
        it->next();
    }

    sistema->darAltaProducto(); // Dar de alta el producto

    // Verificar que el producto fue dado de alta
    ICollection *productos = sistema->obtenerPlatos();
    CHECK(productos->getSize() == 5); // 3 platos
    it = productos->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getTipo() == TipoProducto::TipoMenu)
        {
            // Verificar que el menu tiene los platos anadidos
            CHECK(p->getCodigo() == "Menu Especial");
        }
        if (p->getTipo() == TipoProducto::TipoPlato)
        {
            // Verificar que los platos fueron dados de alta
            CHECK(p->getDescripcion() != "");
        }
        // Imprimir cada plato
        it->next();
    }
    // Limpiar memoria
    delete it;
}

TEST_CASE("Cancelar Alta Producto")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Crear un plato
    cout << "Creando un plato..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);

    // Cancelar alta de producto
    cout << "Cancelando alta de producto..." << endl;
    sistema->cancelarAltaProducto();

    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras cancelar alta: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);
    CHECK_THROWS(sistema->darAltaProducto()); // Verificar que no se puede dar de alta un producto sin crear uno
}

TEST_CASE("Alta Producto con Datos Nulos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Intentar crear un plato con datos nulos
    cout << "Intentando crear un plato con datos nulos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato(nullptr, "", 0.0)));

    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato nulo: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);
}

TEST_CASE("Alta Producto con Datos Inválidos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Intentar crear un plato con datos inválidos
    cout << "Intentando crear un plato con datos inválidos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato("Pasta", "", -10.0)));

    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato inválido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);
}

TEST_CASE("Alta Producto con Datos Válidos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Crear un plato con datos válidos
    cout << "Creando un plato con datos válidos..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);

    // Verificar que el plato fue creado correctamente
    cout << "Platos obtenidos tras crear un plato válido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    platos->add(new DtPlato(plato)); // Agregar el plato creado a la colección
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 6); // 3 platos + 1 nuevo

    IIterator *it = platos->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getCodigo() == "Pasta")
        {
            CHECK(p->getDescripcion() == "Deliciosa pasta con salsa de tomate");
            CHECK(p->getPrecio() == 10.0);
        }
        it->next();
    }

    delete it; // Liberar memoria del iterador
}

TEST_CASE("Alta Producto con Datos Repetidos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Crear un plato con datos válidos
    cout << "Creando un plato con datos válidos..." << endl;
    DtPlato plato("Pasta", "Deliciosa pasta con salsa de tomate", 10.0);
    sistema->crearPlato(plato);

    // Intentar crear el mismo plato nuevamente
    cout << "Intentando crear el mismo plato nuevamente..." << endl;
    CHECK_NOTHROW(sistema->crearPlato(plato)); // No debería lanzar excepción

    // Verificar que el plato no se haya duplicado
    cout << "Platos obtenidos tras intentar crear un plato repetido: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    platos->add(new DtPlato(plato)); // Agregar el plato creado a la colección
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 6); // 3 platos + 1 nuevo

    IIterator *it = platos->getIterator();
    while (it->hasCurrent())
    {
        DtPlato *p = (DtPlato *)it->getCurrent();
        if (p->getCodigo() == "Pasta")
        {
            CHECK(p->getDescripcion() == "Deliciosa pasta con salsa de tomate");
            CHECK(p->getPrecio() == 10.0);
        }
        it->next();
    }

    delete it; // Liberar memoria del iterador
}

TEST_CASE("Alta Producto con Datos Incompletos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Intentar crear un plato con datos incompletos
    cout << "Intentando crear un plato con datos incompletos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato("", "Descripción incompleta", 10.0)));

    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato incompleto: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);
}

TEST_CASE("Alta Producto con Datos Erróneos")
{
    ISistema *sistema = Sistema::getInstance();

    // Seleccionar tipo de producto
    cout << "Seleccionando tipo de producto..." << endl;
    sistema->seleccionarTipoProducto(TipoProducto::TipoPlato);

    // Intentar crear un plato con datos erróneos
    cout << "Intentando crear un plato con datos erróneos..." << endl;
    CHECK_THROWS(sistema->crearPlato(DtPlato("Pasta", "Descripción errónea", -10.0)));

    // Verificar que no hay productos en el sistema
    cout << "Platos obtenidos tras intentar crear un plato erróneo: " << endl;
    ICollection *platos = sistema->obtenerPlatos();
    cout << "Tamano de la colección de platos: " << platos->getSize() << endl;
    CHECK(platos->getSize() == 5);
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("Alta cliente");

TEST_CASE("Alta Cliente")
{
    ISistema *sistema = Sistema::getInstance();

    // Crear un cliente
    cout << "Dando de alta un cliente..." << endl;
    string nombre = "Juan Perez";
    string telefono = "559069389";
    DtDireccion *direccion = new DtDireccion("Calle Falsa 123", "Ciudad", "Pais");
    sistema->agregarCliente(nombre, telefono, direccion);
    cout << "Cliente dado de alta: " << nombre << endl;
    // Verificar que el cliente fue dado de alta
    sistema->mostrarClienteTemporal();
    sistema->darAltaCliente();

    bool existeCliente = sistema->existeCliente(telefono);
    CHECK(existeCliente == true); // Verificar que el cliente existe en el sistema
}

TEST_CASE("Cancelar Alta Cliente")
{
    ISistema *sistema = Sistema::getInstance();

    // Crear un cliente
    cout << "Dando de alta un cliente..." << endl;
    string nombre = "Maria Lopez";
    string telefono = "554876511";
    DtDireccion *direccion = new DtDireccion("Avenida Siempre Viva 456", "Ciudad", "Pais");
    sistema->agregarCliente(nombre, telefono, direccion);
    cout << "Cliente dado de alta: " << nombre << endl;

    // Cancelar alta de cliente
    cout << "Cancelando alta de cliente..." << endl;
    sistema->cancelarAltaCliente();

    // Verificar que no hay cliente temporal
    bool existeCliente = sistema->existeCliente(telefono);
    CHECK(existeCliente == false); // Verificar que el cliente no existe en el sistema
}

TEST_CASE("Alta Cliente con Datos Repetidos (mismo telefono)")
{
    ISistema *sistema = Sistema::getInstance();

    // Crear un cliente
    cout << "Dando de alta un cliente..." << endl;
    string nombre = "Carlos Ruiz";
    string telefono = "778854692";
    DtDireccion *direccion = new DtDireccion("Calle Luna 321", "Ciudad", "Pais");
    sistema->agregarCliente(nombre, telefono, direccion);
    cout << "Cliente dado de alta: " << nombre << endl;
    sistema->darAltaCliente();

    // Intentar dar de alta el mismo cliente nuevamente
    cout << "Intentando dar de alta el mismo cliente nuevamente..." << endl;
    // Este bloque puede lanzar (por duplicado)
    CHECK_THROWS({
        sistema->agregarCliente(nombre, telefono, direccion);
        sistema->darAltaCliente();
    });

    // Verificar que el cliente no se haya duplicado
    bool existeCliente = sistema->existeCliente(telefono);
    CHECK(existeCliente == true);
}

TEST_CASE("Alta Cliente con Datos Repetidos (diferente telefono)")
{
    ISistema *sistema = Sistema::getInstance();

    // Crear un cliente
    cout << "Dando de alta un cliente..." << endl;
    string nombre = "Laura Torres";
    string telefono = "654321987";
    DtDireccion *direccion = new DtDireccion("Calle Sol 654", "Ciudad", "Pais");
    sistema->agregarCliente(nombre, telefono, direccion);
    sistema->darAltaCliente();
    cout << "Cliente dado de alta: " << nombre << endl;

    // Intentar dar de alta el mismo cliente con un telefono diferente
    cout << "Intentando dar de alta el mismo cliente con un telefono diferente..." << endl;
    sistema->agregarCliente(nombre, "998855441", direccion); // No debería lanzar excepción
    sistema->darAltaCliente();
    // Verificar que el cliente fue dado de alta
    bool existeCliente = sistema->existeCliente("998855441");
    CHECK(existeCliente == true); // Verificar que el cliente existe en el sistema
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("Alta Empleado");
// ###### --------------- Alta Empleado ---------------  #######

/**
 * @brief Agrega un empleado al sistema.
 * @param string --> Nombre del empleado.
 * @param string --> Tipo de empleado (Mozo o Repartidor).
 */
void agregarEmpleado(string, string);

/**
 * @brief Selecciona el transporte del repartidor.
 * @param Transporte --> Tipo de transporte (aPie, Moto, Bicicleta, Auto).
 */
void seleccionarTransporte(Transporte);

/**
 * @brief Crea un empleado y lo guarda en el sistema.
 * @return int --> Número del empleado creado.
 */
int darDeAltaEmpleado();

/**
 * @brief Cancela la creación del empleado.
 */
void cancelarAltaEmpleado();

TEST_CASE("Alta Empleado")
{
    ISistema *sistema = Sistema::getInstance();
    // Agregar un empleado
    cout << "Dando de alta un empleado..." << endl;
    string nombre = "Pedro Gomez";
    string tipoEmpleado = "Mozo";
    CHECK_NOTHROW(sistema->agregarEmpleado(nombre, tipoEmpleado));
    CHECK_NOTHROW(sistema->darDeAltaEmpleado());
    cout << "Empleado dado de alta: " << nombre << endl;
}
TEST_CASE("Cancelar Alta Empleado")
{
    ISistema *sistema = Sistema::getInstance();
    // Agregar un empleado
    cout << "Dando de alta un empleado..." << endl;
    string nombre = "Ana Martinez";
    string tipoEmpleado = "Repartidor";
    // Seleccionar transporte para el repartidor
    cout << "Seleccionando transporte para el repartidor..." << endl;
    sistema->seleccionarTransporte(Transporte::Moto);
    // Agregar empleado
    cout << "Agregando empleado..." << endl;
    CHECK_NOTHROW(sistema->agregarEmpleado(nombre, tipoEmpleado));
    cout << "Empleado dado de alta: " << nombre << endl;

    // Cancelar alta de empleado
    cout << "Cancelando alta de empleado..." << endl;
    CHECK_NOTHROW(sistema->cancelarAltaEmpleado());
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("Asignar mesas a mozo");
// ####### --------------- INICIO CASO DE USO ASIGNAR MESAS MOZO --------------- #######

/**
 * @brief El sistema asigna mesas a un mozo.
 * @param int --> Numero del mozo.
 * @param int --> Numero de mesas a asignar.
 */
bool hayVentasEnCurso();
void asignarMesasMozos(int, int);

/// ####### --------------- FIN CASO DE USO ASIGNAR MESAS MOZO --------------- #######
TEST_CASE("Asignar Mesas a Mozo")
{
    ISistema *sistema = Sistema::getInstance();
    // Asignar mesas a un mozo
    cout << "Asignando mesas a un mozo..." << endl;
    int numeroMozo = 1;  // Supongamos que el mozo tiene el número 1
    int numeroMesas = 5; // Supongamos que queremos asignar 5 mesas
    CHECK_THROWS(sistema->asignarMesasMozos(numeroMozo, numeroMesas));
    cout << "Mesas asignadas al mozo: " << numeroMozo << endl;
}

TEST_CASE("Asignar Mesas a Mozo con Datos Inválidos")
{
    ISistema *sistema = Sistema::getInstance();
    // Asignar mesas a un mozo con datos inválidos
    cout << "Intentando asignar mesas a un mozo con datos inválidos..." << endl;
    CHECK_THROWS(sistema->asignarMesasMozos(-1, 5)); // Número de mozo inválido
    CHECK_THROWS(sistema->asignarMesasMozos(1, -5)); // Número de mesas inválido
    cout << "Datos inválidos para asignar mesas a un mozo." << endl;
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("INICIAR VENTA EN MESAS");
// ####### --------------- INICIO CASO DE USO INICIAR VENTA --------------- #######
/**
 * @brief El empleado inicia la venta.
 * @param identificador --> ID del empleado.
 */

void iniciarVenta(string);
void darAltaVenta();
void cancelarAltaVenta();
void addMesaElegida();
ICollection *getMesasElegidas();
void mostrarMesasElegidas(bool); // True para ver qué mesas están seleccionadas, false para ver solo números de dichas mesas.
// TEST_CASE("Iniciar Venta en Mesas")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Iniciar venta en mesas
//     cout << "Iniciando venta en mesas..." << endl;

    
//     int idEmpleado = 8; // Supongamos que el ID del empleado es 12345
//     //Selecciono empleado
//     //Imprimir todos los mozos
//     sistema->seleccionarMozo(idEmpleado);

//     CHECK_NOTHROW(sistema->iniciarVenta(std::to_string(idEmpleado)));
    
//     cout << "Venta iniciada por el empleado: " << idEmpleado << endl;

//     // Agregar mesas elegidas
//     cout << "Agregando mesas elegidas..." << endl;
//     sistema->addMesaElegida();
//     ICollection *mesasElegidas = sistema->getMesasElegidas();
//     CHECK(mesasElegidas->getSize() > 0); // Verificar que se hayan agregado mesas

//     cout << "Dando de alta la venta..." << endl;
//     CHECK_NOTHROW(sistema->darAltaVenta());
//     cout << "Venta dada de alta." << endl;
// }

TEST_CASE("Cancelar Alta Venta")
{
    ISistema *sistema = Sistema::getInstance();
    // Cancelar alta de venta
    cout << "Cancelando alta de venta..." << endl;
    CHECK_NOTHROW(sistema->cancelarAltaVenta());
    cout << "Alta de venta cancelada." << endl;

    // Verificar que no hay mesas elegidas
    ICollection *mesasElegidas = sistema->getMesasElegidas();
    CHECK(mesasElegidas->isEmpty() == true); // Verificar que no hay mesas elegidas
}

TEST_CASE("Iniciar Venta con Mesas No Disponibles")
{
    ISistema *sistema = Sistema::getInstance();
    // Iniciar venta con mesas no disponibles
    cout << "Intentando iniciar venta con mesas no disponibles..." << endl;
    CHECK_THROWS(sistema->addMesaElegida()); // No debería permitir agregar mesas si no hay disponibles
    cout << "No se pueden agregar mesas no disponibles." << endl;
}

// TEST_CASE("Iniciar Venta con Mesas Repetidas")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Iniciar venta con mesas repetidas
//     cout << "Intentando iniciar venta con mesas repetidas..." << endl;
//     CHECK_NOTHROW(sistema->addMesaElegida()); // Agregar una mesa
//     CHECK_THROWS(sistema->addMesaElegida());  // No debería permitir agregar la misma mesa nuevamente
//     cout << "No se pueden agregar mesas repetidas." << endl;
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("AGREGAR PRODUCTO A UNA VENTA");
// ####### --------------- Agregar producto a una venta --------------- #######
// ####### --------------- Agregar producto a una venta --------------- #######
// void seleccionarMozo(int);
// // void elegirMesa(int); Ya hecho
// // void listarProductos(); Ya hecho
// void seleccionarProducto(string);
// void agregarProductoAVenta();
// int getCantidadProductoSeleccionado();
// void setCantidadProductoSeleccionado(int);
// void cancelarAgregarProductoAVenta();

// TEST_CASE("Agregar Producto a una Venta")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Agregar producto a una venta
//     cout << "Agregando producto a una venta..." << endl;
//     int numeroMozo = 1; // Supongamos que el mozo tiene el número 1
//     sistema->seleccionarMozo(numeroMozo);
//     string codigoProducto = "Pasta"; // Supongamos que el código del producto es "Pasta"
//     sistema->seleccionarProducto(codigoProducto);
//     int cantidadProducto = 2; // Supongamos que queremos agregar 2 unidades del producto
//     sistema->setCantidadProductoSeleccionado(cantidadProducto);
//     CHECK_NOTHROW(sistema->agregarProductoAVenta());
//     cout << "Producto agregado a la venta: " << codigoProducto << endl;

//     // Verificar que el producto fue agregado correctamente
//     int cantidadSeleccionada = sistema->getCantidadProductoSeleccionado();
//     CHECK(cantidadSeleccionada == cantidadProducto); // Verificar que la cantidad seleccionada es correcta
// }
// TEST_CASE("Cancelar Agregar Producto a una Venta")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Cancelar agregar producto a una venta
//     cout << "Cancelando agregar producto a una venta..." << endl;
//     CHECK_NOTHROW(sistema->cancelarAgregarProductoAVenta());
//     cout << "Agregar producto a la venta cancelado." << endl;

//     // Verificar que no hay producto seleccionado
//     int cantidadSeleccionada = sistema->getCantidadProductoSeleccionado();
//     CHECK(cantidadSeleccionada == 0); // Verificar que no hay producto seleccionado
// }

TEST_CASE("Agregar Producto a una Venta con Producto No Existente")
{
    ISistema *sistema = Sistema::getInstance();
    // Agregar producto a una venta con producto no existente
    cout << "Intentando agregar producto a una venta con producto no existente..." << endl;
    CHECK_THROWS(sistema->seleccionarProducto("ProductoInexistente")); // Producto no existe
    cout << "No se puede agregar un producto que no existe." << endl;
}

// TEST_CASE("Agregar Producto a una Venta con Cantidad Cero")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Agregar producto a una venta con cantidad cero
//     cout << "Intentando agregar producto a una venta con cantidad cero..." << endl;
//     string codigoProducto = "Pasta"; // Supongamos que el código del producto es "Pasta"
//     sistema->seleccionarProducto(codigoProducto);
//     CHECK_THROWS(sistema->setCantidadProductoSeleccionado(0)); // Cantidad cero
//     cout << "No se puede agregar un producto con cantidad cero." << endl;
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("QUITAR PRODUCTO DE UNA VENTA");

// ####### --------------- Quitar producto de una venta --------------- #######
// void quitarProductoVenta(int);
// void cancelarQuitarProductoVenta();
// void verificarMesaSeleccionadaConVentaEnCurso();
// void listarProductosVentaSeleccionada();
// void seleccionarProductoDeVenta(string);

// TEST_CASE("Quitar Producto de una Venta")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Quitar producto de una venta
//     cout << "Quitando producto de una venta..." << endl;
//     int codigoProducto = 1; // Supongamos que el código del producto es 1
//     CHECK_NOTHROW(sistema->quitarProductoVenta(codigoProducto));
//     cout << "Producto con código " << codigoProducto << " quitado de la venta." << endl;
// }

TEST_CASE("Cancelar Quitar Producto de una Venta")
{
    ISistema *sistema = Sistema::getInstance();
    // Cancelar quitar producto de una venta
    cout << "Cancelando quitar producto de una venta..." << endl;
    CHECK_NOTHROW(sistema->cancelarQuitarProductoVenta());
    cout << "Quitar producto de la venta cancelado." << endl;
}

TEST_CASE("Quitar Producto de una Venta con Producto No Existente")
{
    ISistema *sistema = Sistema::getInstance();
    // Quitar producto de una venta con producto no existente
    cout << "Intentando quitar producto de una venta con producto no existente..." << endl;
    int codigoProducto = 999;                                   // Supongamos que el código del producto no existe
    CHECK_THROWS(sistema->quitarProductoVenta(codigoProducto)); // Producto no existe
    cout << "No se puede quitar un producto que no existe en la venta." << endl;
}

TEST_CASE("Quitar Producto de una Venta con Mesa No Seleccionada")
{
    ISistema *sistema = Sistema::getInstance();
    // Quitar producto de una venta con mesa no seleccionada
    cout << "Intentando quitar producto de una venta con mesa no seleccionada..." << endl;
    CHECK_THROWS(sistema->quitarProductoVenta(1)); // No se ha seleccionado una mesa
    cout << "No se puede quitar un producto sin seleccionar una mesa." << endl;
}

// TEST_CASE("Cancelar Baja Producto de una Venta")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Cancelar baja de producto de una venta
//     cout << "Cancelando baja de producto de una venta..." << endl;
//     CHECK_NOTHROW(sistema->cancelarQuitarProductoVenta());
//     cout << "Baja de producto de la venta cancelada." << endl;

//     // Verificar que no hay producto seleccionado para quitar
//     int codigoProductoSeleccionado = sistema->getCantidadProductoSeleccionado();
//     CHECK(codigoProductoSeleccionado == 0); // Verificar que no hay producto seleccionado para quitar
// }

// TEST_CASE("Quitar Producto de una Venta con Producto Repetido")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Quitar producto de una venta con producto repetido
//     cout << "Intentando quitar producto de una venta con producto repetido..." << endl;
//     int codigoProducto = 1;                                      // Supongamos que el código del producto es 1
//     CHECK_NOTHROW(sistema->quitarProductoVenta(codigoProducto)); // No debería lanzar excepción
//     cout << "Producto con código " << codigoProducto << " quitado de la venta." << endl;

//     // Verificar que el producto fue quitado correctamente
//     int cantidadSeleccionada = sistema->getCantidadProductoSeleccionado();
//     CHECK(cantidadSeleccionada == 0); // Verificar que no hay producto seleccionado para quitar
// }

// TEST_CASE("Quitar Producto de una Venta con Cantidad Cero")
// {
//     ISistema *sistema = Sistema::getInstance();
//     // Quitar producto de una venta con cantidad cero
//     cout << "Intentando quitar producto de una venta con cantidad cero..." << endl;
//     int codigoProducto = 1;                                     // Supongamos que el código del producto es 1
//     sistema->setCantidadProductoSeleccionado(0);                // Establecer cantidad a cero
//     CHECK_THROWS(sistema->quitarProductoVenta(codigoProducto)); // No debería permitir quitar producto con cantidad cero
//     cout << "No se puede quitar un producto con cantidad cero." << endl;
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("Facturacion de una Venta");

// TEST_CASE("Generar Factura")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Simular lógica de facturación de venta como en la función proporcionada
//     int idEmpleado = 1; // Supongamos que el mozo con ID 1 existe
//     int codigoMesa = 1; // Supongamos que la mesa 1 tiene una venta en curso
//     int descuento = 10; // Aplicar un 10% de descuento

//     // Listar mozos y seleccionar uno
//     sistema->listarMozos();
//     sistema->seleccionarMozo(idEmpleado);

//     // Listar mesas con ventas en curso y elegir una
//     sistema->listarMesasConVentasEnCurso();
//     sistema->elegirMesaDeMozoSeleccionado(codigoMesa);

//     // Agregar descuento
//     sistema->agregarPorcentaje(descuento);

//     // Facturar la venta
//     cout << "Facturando venta..." << endl;
//     Factura factura = sistema->generarFactura();
//     CHECK(factura.getDescuento() == descuento); // Verificar que el descuento se aplicó correctamente
//     CHECK(factura.getSubtotal() > 0);           // Verificar que el subtotal es mayor que cero
//     CHECK(factura.getMontoTotal() > 0);         // Verificar que el monto total es mayor que cero
//     CHECK(factura.getIvaTotal() > 0);           // Verificar que el IVA total es mayor que cero
//     cout << "Venta facturada correctamente." << endl;
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("Ventas a Domicilio");

// s

// TEST_CASE("Cancelar Venta a Domicilio")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Cancelar venta a domicilio
//     cout << "Cancelando venta a domicilio..." << endl;
//     CHECK_NOTHROW(sistema->cancelarVentaDomicilio());
//     cout << "Venta a domicilio cancelada." << endl;

//     // Verificar que no hay productos seleccionados para la venta a domicilio
//     int cantidadSeleccionada = sistema->getCantidadProductoSeleccionado();
//     CHECK(cantidadSeleccionada == 0); // Verificar que no hay productos seleccionados para la venta a domicilio
// }

// TEST_CASE("Venta a Domicilio con Cliente No Registrado")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Intentar realizar una venta a domicilio con un cliente no registrado
//     cout << "Intentando realizar una venta a domicilio con un cliente no registrado..." << endl;
//     string telefonoNoRegistrado = "123456789";
//     CHECK_THROWS(sistema->seleccionarCliente(telefonoNoRegistrado)); // Cliente no registrado
//     cout << "No se puede realizar una venta a domicilio sin un cliente registrado." << endl;
// }

TEST_CASE("Venta a Domicilio con Producto No Existente")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar realizar una venta a domicilio con un producto no existente
    cout << "Intentando realizar una venta a domicilio con un producto no existente..." << endl;
    string codigoProductoNoExistente = "ProductoInexistente";
    CHECK_THROWS(sistema->seleccionarProductoDomicilio(codigoProductoNoExistente, 1)); // Producto no existe
    cout << "No se puede realizar una venta a domicilio con un producto que no existe." << endl;
}

TEST_CASE("Venta a Domicilio con Repartidor No Registrado")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar realizar una venta a domicilio con un repartidor no registrado
    cout << "Intentando realizar una venta a domicilio con un repartidor no registrado..." << endl;
    int idRepartidorNoRegistrado = 999;                                     // Supongamos que el ID del repartidor no existe
    CHECK_THROWS(sistema->seleccionarRepartidor(idRepartidorNoRegistrado)); // Repartidor no registrado
    cout << "No se puede realizar una venta a domicilio sin un repartidor registrado." << endl;
}

// TEST_CASE("Venta a Domicilio con Cantidad Cero")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Intentar realizar una venta a domicilio con cantidad cero
//     cout << "Intentando realizar una venta a domicilio con cantidad cero..." << endl;
//     string codigoProducto = "Pasta";                                        // Supongamos que el código del producto es "Pasta"
//     sistema->seleccionarProductoDomicilio(codigoProducto, 0);               // Establecer cantidad a cero
//     CHECK_THROWS(sistema->seleccionarProductoDomicilio(codigoProducto, 0)); // No debería permitir cantidad cero
//     cout << "No se puede realizar una venta a domicilio con cantidad cero." << endl;
// }

// TEST_CASE("Venta a Domicilio con Producto Repetido")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Intentar realizar una venta a domicilio con un producto repetido
//     cout << "Intentando realizar una venta a domicilio con un producto repetido..." << endl;
//     string codigoProducto = "Pasta";                                                        // Supongamos que el código del producto es "Pasta"
//     int cantidadProducto = 2;                                                               // Supongamos que queremos agregar 2 unidades del producto
//     CHECK_NOTHROW(sistema->seleccionarProductoDomicilio(codigoProducto, cantidadProducto)); // No debería lanzar excepción
//     cout << "Producto con código " << codigoProducto << " agregado a la venta a domicilio." << endl;

//     // Verificar que el producto fue agregado correctamente
//     int cantidadSeleccionada = sistema->getCantidadProductoSeleccionado();
//     CHECK(cantidadSeleccionada == cantidadProducto); // Verificar que la cantidad seleccionada es correcta
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("Ventas de un mozo");
// TEST_CASE("Mostrar Ventas de un Mozo en un Rango de Fechas")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el mozo con ID 1 existe y tiene ventas en el sistema
//     int idMozo = 1;
//     DtFecha fechaInicio(2024, 6, 1);
//     DtFecha fechaFin(2024, 6, 30);

//     // Seleccionar mozo
//     sistema->seleccionarMozo(idMozo);

//     // Mostrar ventas del mozo en el rango de fechas
//     CHECK_NOTHROW(sistema->mostrarVentasMozo(fechaInicio, fechaFin));
// }

// TEST_CASE("Mostrar Ventas de un Mozo con Fechas Inválidas")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el mozo con ID 1 existe
//     int idMozo = 1;
//     DtFecha fechaInicio(2024, 6, 30);
//     DtFecha fechaFin(2024, 6, 1); // Fecha fin antes de la fecha inicio

//     // Seleccionar mozo
//     sistema->seleccionarMozo(idMozo);

//     // Intentar mostrar ventas del mozo con fechas inválidas
//     CHECK_THROWS(sistema->mostrarVentasMozo(fechaInicio, fechaFin));
// }

TEST_CASE("Mostrar Ventas de un Mozo con Mozo No Registrado")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar mostrar ventas de un mozo no registrado
    int idMozoNoRegistrado = 999; // Supongamos que el ID del mozo no existe

    // Intentar seleccionar mozo no registrado
    CHECK_THROWS(sistema->seleccionarMozo(idMozoNoRegistrado));
}

// TEST_CASE("Mostrar Ventas de un Mozo con No Ventas en el Rango de Fechas")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el mozo con ID 1 existe pero no tiene ventas en el rango de fechas
//     int idMozo = 1;
//     DtFecha fechaInicio(2024, 7, 1);
//     DtFecha fechaFin(2024, 7, 31);

//     // Seleccionar mozo
//     sistema->seleccionarMozo(idMozo);

//     // Mostrar ventas del mozo en el rango de fechas sin ventas
//     CHECK_NOTHROW(sistema->mostrarVentasMozo(fechaInicio, fechaFin));
// }

TEST_SUITE_END();

TEST_SUITE_BEGIN("Informacion de un Producto");

// TEST_CASE("Obtener Información de un Producto Existente")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el producto con código "Pasta" existe
//     string codigoProducto = "Pasta";

//     // Obtener información del producto
//     CHECK_NOTHROW({
//         DtInfoProducto *producto = sistema->obtenerProducto(codigoProducto);
//         CHECK(producto != nullptr);
//         if (producto)
//         {
//             CHECK(producto->getProducto()->getCodigo() == codigoProducto);
//             CHECK(producto->getProducto()->getDescripcion() == "Deliciosa pasta con salsa de tomate");
//             CHECK(producto->getProducto()->getPrecio() == 10.0);
//             CHECK(producto->getCantidadVentas() >= 0);
//             delete producto;
//         }
//     });
// }

TEST_CASE("Obtener Información de un Producto Inexistente")
{
    ISistema *sistema = Sistema::getInstance();

    // Supongamos que el producto con código "ProductoInexistente" no existe
    string codigoProducto = "ProductoInexistente";

    // Obtener información del producto inexistente debe lanzar excepción o retornar nullptr
    CHECK_THROWS_AS(sistema->obtenerProducto(codigoProducto), std::invalid_argument);
}

TEST_CASE("Obtener Información de un Producto con Código Vacío")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar obtener información de un producto con código vacío
    string codigoProducto = "";

    // Obtener información del producto con código vacío debe lanzar excepción
    CHECK_THROWS_AS(sistema->obtenerProducto(codigoProducto), std::invalid_argument);
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("Baja producto");

// TEST_CASE("Baja Producto Existente")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Listar productos antes de eliminar
//     cout << "Productos antes de eliminar:" << endl;
//     sistema->listarProductos();

//     // Seleccionar producto existente
//     string codigoProducto = "Pasta";
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));

//     // Mostrar producto seleccionado
//     sistema->mostrarProductoSeleccionado();

//     // Eliminar producto
//     CHECK_NOTHROW(sistema->quitarProductoDelSistema(codigoProducto));
//     cout << "Producto eliminado exitosamente." << endl;

//     // Cancelar baja (debería limpiar selección temporal)
//     CHECK_NOTHROW(sistema->cancelarBajaProducto());

//     // Verificar que el producto ya no existe
//     CHECK_THROWS(sistema->seleccionarProducto(codigoProducto));
// }

// TEST_CASE("Cancelar Baja Producto")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Seleccionar producto existente
//     string codigoProducto = "Pasta";
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));

//     // Cancelar baja
//     CHECK_NOTHROW(sistema->cancelarBajaProducto());

//     // El producto debe seguir existiendo
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));
// }

TEST_CASE("Baja Producto Inexistente")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar eliminar producto que no existe
    string codigoProducto = "ProductoInexistente";
    CHECK_THROWS(sistema->seleccionarProducto(codigoProducto));
    CHECK_THROWS(sistema->quitarProductoDelSistema(codigoProducto));
}

TEST_CASE("Baja Producto con Código Vacío")
{
    ISistema *sistema = Sistema::getInstance();

    // Intentar eliminar producto con código vacío
    string codigoProducto = "";
    CHECK_THROWS(sistema->seleccionarProducto(codigoProducto));
    CHECK_THROWS(sistema->quitarProductoDelSistema(codigoProducto));
}

// TEST_CASE("Baja Producto con Ventas Asociadas")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el producto "Pasta" tiene ventas asociadas
//     string codigoProducto = "Pasta";

//     // Intentar eliminar producto con ventas asociadas
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));
//     CHECK_THROWS(sistema->quitarProductoDelSistema(codigoProducto)); // No debería permitir eliminar si hay ventas asociadas
// }

// TEST_CASE("Baja Producto con Ventas en Curso")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el producto "Pasta" tiene ventas en curso
//     string codigoProducto = "Pasta";

//     // Intentar eliminar producto con ventas en curso
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));
//     CHECK_THROWS(sistema->quitarProductoDelSistema(codigoProducto)); // No debería permitir eliminar si hay ventas en curso
// }

// TEST_CASE("Baja Producto con Producto Repetido")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el producto "Pasta" tiene un código repetido
//     string codigoProducto = "Pasta";

//     // Intentar eliminar producto con código repetido
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));
//     CHECK_THROWS(sistema->quitarProductoDelSistema(codigoProducto)); // No debería permitir eliminar si hay un código repetido
// }

// TEST_CASE("Baja Producto con Producto Seleccionado")
// {
//     ISistema *sistema = Sistema::getInstance();

//     // Supongamos que el producto "Pasta" está seleccionado
//     string codigoProducto = "Pasta";

//     // Intentar eliminar producto seleccionado
//     CHECK_NOTHROW(sistema->seleccionarProducto(codigoProducto));
//     CHECK_NOTHROW(sistema->quitarProductoDelSistema(codigoProducto)); // Debería permitir eliminar si está seleccionado

//     // Verificar que el producto ya no existe
//     CHECK_THROWS(sistema->seleccionarProducto(codigoProducto));
// }
TEST_SUITE_END();