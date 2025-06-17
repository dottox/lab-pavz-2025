#include <iostream>
#include <cctype>
#include <limits>
#include <cstring> // Para strcpy
#include <string>  // para std::string
#include <set>     // para std::set
#include <cctype>
#include "clases/Factory/Factory.h"
#include "clases/Sistema/ISistema.h"

#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

void cleanScreen()
{
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
    cin.clear();
    cin.ignore();
    string dummy;
    cout << "Presiona cualquier tecla para continuar.";
    getline(cin, dummy);
}

bool soloLetras(const std::string &s)
{
    for (char c : s)
    {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
        {
            return false; // No es letra ni espacio
        }
    }
    return true;
}


bool soloNumeros(const std::string &s)
{
    if (s.empty())
        return false;

    size_t i = 0;

    // Permitir signo negativo al inicio
    if (s[0] == '-')
    {
        if (s.length() == 1)
            return false; // solo "-" no es un número
        i = 1;
    }

    for (; i < s.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
        {
            return false;
        }
    }

    return true;
}

bool esCalleValida(const std::string &s)
{
    if (s.empty())
        return false;

    for (char c : s)
    {
        if (!std::isalnum(static_cast<unsigned char>(c)) && c != ' ')
        {
            return false; // carácter inválido
        }
    }
    return true;
}

bool esTelefonoValido(const std::string &s)
{
    if (!soloNumeros(s))
        return false;
    if (s.length() != 9)
        return false;
    for (char c : s)
    {
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }
    return true;
}

void limpiarCin()
{
    cleanScreen();
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Has ingresado una opcion invalida." << endl
         << endl;
    pause();
}

void mostrarMenu(ISistema *s, ActorMenu a)
{
    switch (a)
    {
    case ActorMenu::noneMenu:
        cleanScreen();
        cout << "Bienvenido al sistema." << endl
             << endl;
        cout << "Ingrese el actor que desea probar: " << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Mozo" << endl;
        cout << "3. Repartidor" << endl;
        cout << "4. Cliente" << endl;
        cout << "5. Cargar datos de prueba" << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::AdministradorMenu:
        cleanScreen();
        cout << "Bienvenido al menu Administrativo." << endl
             << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Alta de producto" << endl;
        cout << "2. Alta de cliente" << endl;
        cout << "3. Alta de empleado" << endl;
        cout << "4. Asignar mesas a mozos" << endl;
        cout << "5. Venta a domicilio" << endl;
        cout << "6. Ventas de un mozo" << endl;
        cout << "7. Informacion de un producto" << endl;
        cout << "8. Resumen de facturacion de un dia" << endl;
        cout << "9. Baja de producto" << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::MozoMenu:
        cleanScreen();
        cout << "Bienvenido al menu Mozo." << endl
             << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Iniciar ventas en mesas" << endl;
        cout << "2. Agregar producto a una venta" << endl;
        cout << "3. Quitar producto de una venta" << endl;
        cout << "4. Facturacion de una venta" << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::RepartidorMenu:
        cleanScreen();
        cout << "Bienvenido Repartidor." << endl
             << endl;
        cout << "Lastimosamente aun no tenemos funcionalidades." << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::ClienteMenu:
        cleanScreen();
        cout << "Bienvenido Cliente." << endl
             << endl;
        cout << "Lastimosamente aun no tenemos funcionalidades." << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::PoblarMenu:
        cleanScreen();
        cout << "Bienvenido al almacen del sistema." << endl
             << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Poblar el sistema con datos de prueba" << endl;
        cout << "2. Ver TODOS los datos actualmente ingresados" << endl;
        cout << "0. Salir" << endl;
        break;
    default:
        cleanScreen();
        cout << "Bienvenido al Sistema." << endl;
        break;
    }
}

void mostrarPoblacion(ISistema *s)
{
    cleanScreen();
    s->listarEmpleados();
    s->listarMesas();
    s->listarVentas();
    s->listarProductos();
    s->listarProductoTemporal();
    s->mostrarMesasElegidas(true);
    pause();
}

void altaProducto(ISistema *s)
{
    cleanScreen();

    bool existenProductos = s->getCantidadProductos() > 0;

    cout << "Selecciona el tipo de producto a crear:" << endl;
    cout << "1. Plato" << endl;

    if (existenProductos)
    {
        cout << "2. Menu" << endl;
    }

    int opcion;
    cout << endl << "> ";
    cin >> opcion;

    cin.ignore();

    if (cin.fail() || (opcion != 1 && (opcion != 2 || !existenProductos)))
    {
        limpiarCin();
        return;
    }

    if (opcion == 1)
    {
        s->seleccionarTipoProducto(TipoProducto::TipoPlato);
    }
    else if (opcion == 2)
    {
        s->seleccionarTipoProducto(TipoProducto::TipoMenu);
    }

    string code;
    string descripcion;
    float precio;

    cleanScreen();
    cout << "Ingrese el codigo del producto (menu/plato): ";
    getline(cin, code);

    if (soloNumeros(code)) {
        if (stoi(code) <= 0) {
            throw invalid_argument("El codigo debe ser un numero positivo.");
        }
    }

    cout << endl << "Ingrese la descripcion del producto (menu/plato): ";
    getline(cin, descripcion);

    char *codigo = new char[code.size() + 1]; // Reservar memoria para el codigo, al finalizar el caso de uso se eliminara.
    strcpy(codigo, code.c_str());

    if (opcion == 1)
    {
        cout << endl << "Ingrese el precio del producto: ";
        cin >> precio;
        cin.ignore();
        if (cin.fail() || precio <= 0)
        {
            delete[] codigo; // Liberar memoria del codigo
            throw invalid_argument("El precio debe ser un numero positivo.");
        }
        DtPlato dtPlato(codigo, descripcion, precio);
        s->crearPlato(dtPlato);
    }

    if (opcion == 2)
    {
        DtMenu dtMenu(codigo, descripcion);
        s->crearMenu(dtMenu);

        string code2; // Antes de agregar el plato al menu, creamos una copia del codigo en forma de char*
        int cantidad;
        bool salir = false;

        ICollection *platos = s->obtenerPlatos();

        while (salir != true)
        {
            cleanScreen();

            IIterator *it = platos->getIterator();

            cout << "--- Platos disponibles para anadir al menu ---" << endl;

            while (it->hasCurrent())
            {
                DtPlato *plato = dynamic_cast<DtPlato *>(it->getCurrent());
                if (plato)
                {
                    cout << *plato << endl;
                }
                it->next();
            }
            delete it; // Liberar memoria del iterador

            cout << endl << "Seleccione el plato a anadir al menu (ingrese el codigo)." << endl;
            cout << "Ingrese 'exit' para terminar de anadir platos: " << endl;
            cout << endl << "> ";
            cin >> code2;
            cin.ignore();

            if (code2 == "exit")
            {
                salir = true;
                continue;
            }

            cout << endl << "Ingrese una cantidad de platos '" << code2 << "' a anadir: ";
            cin >> cantidad;
            cin.ignore();

            if (cin.fail() || cantidad <= 0)
            {
                cout << "La cantidad debe ser un numero positivo." << endl;
                pause();
                continue;
            }

            char *codigoPlato = new char[code2.size() + 1]; // Reservar memoria para el codigo, al finalizar el caso de uso se eliminara.
            strcpy(codigoPlato, code2.c_str());

            try
            {
                s->anadirPlatoAMenu(codigoPlato, cantidad);
                cout << "Plato '" << code2 << "' anadido al menu temporal." << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            delete[] codigoPlato;
            pause();
        }

        delete platos; // Liberar memoria de la coleccion de platos
    }

    cleanScreen();

    s->listarProductoTemporal();

    cout << endl
         << "¿Confirmar alta del producto?: " << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> opcion;
    if (cin.fail() || (opcion != 1 && opcion != 2))
    {
        limpiarCin();
        delete[] codigo;
        return;
    }
    if (opcion == 1)
    {
        s->darAltaProducto();
        cout << "Producto creado exitosamente." << endl;
    }
    else
    {
        s->cancelarAltaProducto();
        cout << "Creacion de producto cancelada." << endl;
    }
    delete[] codigo;
    pause();
}

void facturarVenta(ISistema *s)
{
    if(s->getCantidadMozos() == 0)
    {
        cout << "No hay mozos disponibles para facturar una venta." << endl;
        pause();
        return;
    }
    if(s->getCantidadMesas() == 0)
    {
        cout << "No hay mesas disponibles para facturar una venta." << endl;
        pause();
        return;
    }
    int idEmpleado;
    int codigoMesa, descuento;

    cleanScreen();

    s->listarMozos();
    cout << endl << "Ingrese el ID del empleado que quiere facturar una venta ('0' para salir): ";
    cin >> idEmpleado;
    cin.ignore();

    if (cin.fail() || idEmpleado < 0)
    {
        throw invalid_argument("El ID del empleado debe ser un numero positivo.");
        return;
    }

    if (idEmpleado == 0)
    {
        cout << "Cancelando operacion." << endl;
        s->cancelarFacturarVenta();
        return;
    }
    s->seleccionarMozo(idEmpleado);
    
    
    while (true) {
        cleanScreen();
        s->listarMesasConVentasEnCursoDeMozoSeleccionado();
    
        cout << endl << "Ingresa el codigo de la mesa a facturar ('0' para salir): ";
        cin >> codigoMesa;

        if (cin.fail() || codigoMesa < 0)
        {
            cout << "El codigo de la mesa debe ser un numero positivo." << endl;
            pause();
            continue; // Volver a solicitar el codigo de la mesa
        }

        if (codigoMesa == 0)
        {
            cout << "Cancelando operacion." << endl;
            s->cancelarFacturarVenta();
            return;
        }
    
        try {
            s->elegirMesaDeMozoSeleccionado(codigoMesa);
            s->verificarMesaSeleccionadaConVentaEnCurso();
            break;
        } catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;
            pause();
            continue; // Volver a solicitar el codigo de la mesa
        }   
    }


    if (!s->ventaMesaSeleccionadaTieneMenu()) {
        while (true)
        {
            cleanScreen();
            cout << "Ingrese el descuento a aplicar (0-100): ";
            cin >> descuento;
            cin.ignore();
    
            if (cin.fail() || descuento < 0 || descuento > 100)
            {
                cout << "Descuento invalido. Ingrese un descuento entre 0 y 100: ";
                pause();
            }
            else
                break;
        }
    } else {
        descuento = 0;
    }

    s->agregarPorcentaje(descuento);

    cleanScreen();
    s->imprimirFacturaLocal(s->generarFactura());
    pause();
}

void facturacionDia(ISistema *s)
{
    cleanScreen();
    string fecha;
    cout << "Ingrese la fecha para la facturacion del dia (DD/MM/AAAA): ";
    cin >> fecha;
    cin.ignore();

    while (fecha.size() != 10 || fecha[2] != '/' || fecha[5] != '/')
    {
        cout << "Fecha invalida. Formato esperado: DD/MM/AAAA. Intente nuevamente: ";
        cin >> fecha;
    }
    DtFecha dtFecha = DtFecha(
        stoi(fecha.substr(0, 2)), // Dia
        stoi(fecha.substr(3, 2)), // Mes
        stoi(fecha.substr(6, 4))  // Anio
    );

    s->imprimirInforme(s->consultarFacturacion(dtFecha));
    pause();
}

void agregarProductoAVenta(ISistema *s)
{
    if(s->getCantidadProductos() == 0)
    {
        cout << "No hay productos disponibles para agregar a una venta." << endl;
        pause();
        return;
    }
    if(s->getCantidadMesas() == 0)
    {
        cout << "No hay mesas disponibles para agregar a una venta." << endl;
        pause();
        return;
    }
    if(s->getCantidadMozos() == 0)
    {
        cout << "No hay mozos disponibles para agregar a una venta." << endl;
        pause();
        return;
    }
    int idEmpleado;
    int codigoMesa, cantidad;
    string codigoProducto, confirmar;
    bool mantener = true;

    cleanScreen();
    s->listarMozos();
    cout << endl
         << "Ingrese el ID del empleado que quiere agregar un producto a una venta ('0' para salir): ";
    cin >> idEmpleado;
    cin.ignore();

    if (cin.fail() || idEmpleado < 0)
    {
        s->cancelarAgregarProductoAVenta();
        throw invalid_argument("El ID del empleado debe ser un numero positivo.");
        return;
    }

    if (idEmpleado == 0)
    {
        cout << "Cancelando operacion." << endl;
        s->cancelarAgregarProductoAVenta();
        return;
    }
    s->seleccionarMozo(idEmpleado);
    cleanScreen();

    // Loop para seleccionar la mesa.
    while (mantener)
    {
        cleanScreen();

        try
        {
            s->listarMesasConVentasEnCursoDeMozoSeleccionado();
        }
        catch (const invalid_argument &e)
        {
            s->cancelarAgregarProductoAVenta();
            throw e;
        }

        cout << endl
             << "Ingrese el numero de la mesa involucrada en la venta ('0' para salir): ";
        cin >> codigoMesa;
        cin.ignore();

        if (cin.fail() || codigoMesa < 0)
        {
            cout << endl
                 << "El codigo de la mesa debe ser un numero positivo." << endl;
            pause();
            continue;
        }

        if (codigoMesa == 0)
        {
            cout << endl
                 << "Cancelando Operacion." << endl;
            s->cancelarAgregarProductoAVenta();
            return;
        }

        try
        {
            s->elegirMesaDeMozoSeleccionado(codigoMesa);
            s->verificarMesaSeleccionadaConVentaEnCurso();
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Error: " << e.what() << endl;
            pause();
            continue;
        }
        mantener = false;
    }

    cleanScreen();
    mantener = true;
    // Loop para agregar los productos a la venta.
    while (mantener)
    {
        cleanScreen();
        try
        {
            s->listarProductos();
            cout << "-----------------------------------------" << endl;
            s->listarProductosVentaSeleccionada();
        }
        catch (const invalid_argument &e)
        {
            s->cancelarAgregarProductoAVenta();
            throw e;
        }

        cout << endl
             << "Ingrese el codigo del producto a agregar a la venta ('0' para salir): ";
        cin >> codigoProducto;
        cin.ignore();

        if (cin.fail() || codigoProducto.empty())
        {
            cout << endl
                 << "El codigo del producto no puede estar vacio." << endl;
            pause();
            continue;
        }

        if (codigoProducto == "0")
        {
            cout << endl
                 << "Terminando operacion." << endl;
            s->cancelarAgregarProductoAVenta();
            return;
        }

        try
        {
            s->seleccionarProducto(codigoProducto);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Error: " << e.what() << endl;
            pause();
            continue;
        }

        cout << endl
             << "Ingrese cuantas unidades desea agregar del producto: ";
        cin >> cantidad;
        cin.ignore();

        if (cin.fail() || cantidad <= 0)
        {
            cout << endl
                 << "La cantidad debe ser un numero positivo." << endl;
            pause();
            continue;
        }
        try
        {
            s->setCantidadProductoSeleccionado(cantidad);
        }
        catch (const invalid_argument &e)
        {
            cout << endl
                 << "Error: " << e.what() << endl;
            pause();
            continue;
        }

        cleanScreen();

        cout << endl
             << "¿Desea agregar el producto '" << codigoProducto << "' con cantidad " << cantidad << " a la venta? (y/n): ";
        cin >> confirmar;
        cin.ignore();
        if (confirmar != "y" && confirmar != "Y")
        {
            cout << endl
                 << "Operacion cancelada." << endl;
            pause();
            continue;
        }
        else
        {
            s->agregarProductoAVenta();
        }
    }
}

void agregarEmpleado(ISistema *s)
{
    cleanScreen();
    while (true)
    {
        cleanScreen();
        string nombre, cargo, transporte, opcion3;
        int opcion, opcion2;
        cout << "Ingrese una opcion:" << endl;
        cout << "1. Agregar Mozo" << endl;
        cout << "2. Agregar Repartidor" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << endl << "> ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 0:
            return; // Salir del bucle y volver al menu anterior
        case 1:
            cargo = "Mozo";
            break;
        case 2:
            cleanScreen();
            cargo = "Repartidor";
            cout << "Seleccione el transporte del repartidor. ";
            s->listarTransportes();
            do
            {
                cout << endl << "Ingrese el numero del transporte ('0' para salir): ";
                cin >> opcion2;
                cin.ignore();
                if (opcion2 == 0) {
                    cout << "Cancelando alta de empleado." << endl;
                    s->cancelarAltaEmpleado();
                    return; // Salir del bucle y cancelar la alta
                }
            } while (cin.fail() || opcion2 < 1 || opcion2 > 4);

            s->seleccionarTransporte(opcion2 == 1   ? aPie
                                     : opcion2 == 2 ? Moto
                                     : opcion2 == 3 ? Bicicleta
                                                    : Auto);
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            pause();
            continue;
        }

        cleanScreen();

        do
        {
            cout << "Ingrese el nombre del empleado ('0' para salir): ";
            getline(cin, nombre);
            if (nombre == "0") {
                cout << "Cancelando alta de empleado." << endl;
                s->cancelarAltaEmpleado();
                return;
            }
        } while (cin.fail() || nombre.empty() || nombre.find_first_not_of(' ') == string::npos || !soloLetras(nombre));

        do
        {
            cleanScreen();
            cout << "Desea agregar el empleado '" << nombre << "' con cargo '" << cargo << "'?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << endl << "> ";
            getline(cin, opcion3);
        } while (cin.fail() || (opcion3 != "1" && opcion3 != "2"));

        if (opcion3 == "2")
        {
            cout << "Operacion cancelada." << endl;
            s->cancelarAltaEmpleado();
            pause();
            continue;
        }

        s->agregarEmpleado(nombre, cargo);
        int id = s->darDeAltaEmpleado();
        cleanScreen();
        cout << "Empleado '" << nombre << "' con ID " << id << " creado exitosamente." << endl;
        pause();
    }
}

void iniciarVenta(ISistema *s)
{
    if(s->getCantidadMozos() == 0)
    {
        cout << "No hay mozos disponibles para iniciar una venta." << endl;
        pause();
        return;
    }
    cleanScreen();

    int idEmpleado;
    bool flag = true;
    int mesaElegida, confirmar;

    s->listarMozos();

    cout << "Ingrese el ID del empleado que inicia la venta ('0' para salir): ";
    cin >> idEmpleado;
    cin.ignore();

    if (cin.fail() || idEmpleado < 0)
    {
        cout << "El ID del empleado debe ser un numero positivo." << endl;
        pause();
        return;
    }

    if (idEmpleado == 0)
    {
        cout << "Cancelando operacion." << endl;
        s->cancelarAltaVenta();
        return;
    }

    s->seleccionarMozo(idEmpleado);

    while (flag)
    {
        cleanScreen();
        try
        {
            s->mostrarMesasElegidas(false);
            s->iniciarVenta(to_string(idEmpleado));
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            flag = false;
            s->cancelarAltaVenta();
            pause();
            return;
        }

        cout << endl << "Ingrese el numero de la mesa para iniciar la venta." << endl
             << "('0' para continuar, '-1' para salir): " << endl;
        cin >> mesaElegida;
        cin.ignore();

        if (cin.fail() || mesaElegida < -1)
        {
            cout << "Numero de mesa invalido. Debe ser un numero positivo." << endl;
            pause();
            continue;
        }
        
        if (mesaElegida == 0)
        {
            if (s->getMesasElegidas()->isEmpty()) {
                cout << "Debes elegir una mesa." << endl;
                pause();
                continue;
            } else {
                flag = false; // Salimos del bucle si se elige continuar sin seleccionar una mesa
                continue;
            }
        }

        if (mesaElegida == -1) {
            cout << "Saliendo de la operacion." << endl;
            s->cancelarAltaVenta();
            return;
        }


        try
        {
            // Elegir la mesa
            s->elegirMesaDeMozoSeleccionado(mesaElegida);
            s->addMesaElegida(); // Agregar la mesa elegida al sistema
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            pause();
            continue;
        }
    }

    cleanScreen();
    s->mostrarMesasElegidas(true);

    cout << "¿Desea confirmar la venta? (1. Si, 0. No): ";
    cin >> confirmar;
    cin.ignore();

    cleanScreen();
    if (confirmar == 1 && !cin.fail())
    {
        s->darAltaVenta();
        cout << "Venta iniciada exitosamente." << endl;
    }
    else
    {
        s->cancelarAltaVenta();
        cout << "Venta cancelada." << endl;
    }
    pause();
}

void informacionProducto(ISistema *s)
{
    string codigo;
    while (true)
    {
        cleanScreen();
        s->listarProductos();

        cout << endl << "Ingrese el codigo del producto a consultar (o '0' para salir): ";
        cin >> codigo;
        cin.ignore();
        // Si el codigo es "0", salimos del bucle
        if (cin.fail())
        {
            limpiarCin();
            continue;
        }

        if (codigo == "0")
            break;

        if (codigo.empty())
        {
            cout << "El codigo del producto no puede estar vacio." << endl;
            pause();
            continue;
        }

        try
        {
            DtInfoProducto *producto = s->obtenerProducto(codigo);
            if (producto)
            {
                cout << "Informacion del producto: " << endl;
                cout << "-----------------------------------------------------------------------:" << endl;
                cout << "Codigo: " << producto->getProducto()->getCodigo() << endl;
                cout << "Descripcion: " << producto->getProducto()->getDescripcion() << endl;
                cout << "Tipo: " << (producto->getProducto()->getTipo() == TipoPlato ? "Plato" : "Menu") << endl;
                cout << "Precio: $" << producto->getProducto()->getPrecio() << endl;
                cout << "Cantidad de ventas: " << producto->getCantidadVentas() << endl;
                cout << "-----------------------------------------------------------------------:" << endl;
                delete producto; // Liberar memoria del DtInfoProducto
            }
            else
            {
                cout << "Producto no encontrado." << endl;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
        pause();
    }
}

void ventasMozo(ISistema *s)
{
    if(s->getCantidadMozos() == 0) {
        cout << "No hay mozos disponibles para consultar ventas." << endl;
        pause();
        return;
    }
    cleanScreen();
    try
    {
        s->listarMozos();
        string idMozo, fechaInicio, fechaFin;
        cout << "Ingrese el ID del mozo: ";
        cin >> idMozo;
        cin.ignore();

        s->seleccionarMozo(stoi(idMozo));

        cout << "Ingrese la fecha de inicio de la consulta (DD/MM/AAAA): ";
        cin >> fechaInicio;
        cin.ignore();

        while (s->validarFecha(fechaInicio) == false)
        {
            cout << "Fecha invalida. Formato esperado: DD/MM/AAAA. Intente nuevamente." << endl;
            cout << "Ingrese la fecha de inicio de la consulta (DD/MM/AAAA): ";
            cin >> fechaInicio;
            cin.ignore();
        }

        DtFecha dtFechaInicio = DtFecha(stoi(fechaInicio.substr(0, 2)), stoi(fechaInicio.substr(3, 2)), stoi(fechaInicio.substr(6, 4)));

        cout << "Ingrese la fecha de fin de la consulta (DD/MM/AAAA): ";
        cin >> fechaFin;
        cin.ignore();

        while (s->validarFecha(fechaFin) == false)
        {
            cout << "Fecha invalida. Formato esperado: DD/MM/AAAA. Intente nuevamente." << endl;
            cout << "Ingrese la fecha de fin de la consulta (DD/MM/AAAA): ";
            cin >> fechaFin;
            cin.ignore();
        }

        DtFecha dtFechaFin = DtFecha(stoi(fechaFin.substr(0, 2)), stoi(fechaFin.substr(3, 2)), stoi(fechaFin.substr(6, 4)));

        if (dtFechaInicio > dtFechaFin)
        {
            cout << "La fecha de inicio no puede ser posterior a la fecha de fin." << endl;
            pause();
            return;
        }

        s->mostrarVentasMozo(dtFechaInicio, dtFechaFin);
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    pause();
}

void asignarMesasMozos(ISistema *s)
{
    if(s->getCantidadMozos() == 0 || s->getCantidadMesas() == 0) {
        cout << "No hay mozos o mesas disponibles para asignar." << endl;
        pause();
        return;
    }
    cleanScreen();

    int cantMozos, cantMesas;
    cout << "Ingrese la cantidad de mozos a asignar: ";
    cin >> cantMozos;
    cin.ignore();

    while (cin.fail() || cantMozos <= 0 || cantMozos > s->getCantidadMozos())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Cantidad invalida. Ingrese un numero positivo o la cantidad seleccionada es mayor a la disponible: " << endl;
        cin >> cantMozos;
        cin.ignore();
    }

    cout << endl << "Ingrese la cantidad de mesas a asignar: ";
    cin >> cantMesas;
    cin.ignore();

    while (cin.fail() || cantMesas <= 0 || cantMesas > s->getCantidadMesas())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Cantidad invalida. Ingrese un numero positivo o la cantidad seleccionada es mayor a la disponible: " << endl;
        cin >> cantMesas;
        cin.ignore();
    }

    try
    {
        s->asignarMesasMozos(cantMozos, cantMesas);
        pause();
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
        pause();
        return;
    }
}

void altaCliente(ISistema *s)
{
    cleanScreen();

    string nombre, telefono, calle, numero, entreCalles, nombreEdificio, numeroApto, esCasa;

    while (true)
    {

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        do
        {
            cleanScreen();
            cout << "Ingrese el nombre del cliente ('0' para salir): ";
            getline(cin, nombre);
            if(nombre.empty() || cin.fail() || nombre.find_first_not_of(' ') == string::npos || !soloLetras(nombre)) {
                cout << "El nombre no puede estar vacio o contener solo espacios." << endl;
                continue; // Volver a solicitar el nombre
            }
            if (nombre == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (!soloLetras(nombre) || cin.fail() || nombre[0] == ' ' || nombre.empty());


        do
        {
            cout << endl << "Ingrese el telefono del cliente (9 digitos) ('0' para salir): ";
            getline(cin, telefono);
            if (telefono == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (!esTelefonoValido(telefono));


        do
        {
            cout << endl << "Ingrese la calle del cliente ('0' para salir): ";
            getline(cin, calle);
            if (calle == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (cin.fail() || !esCalleValida(calle) || calle[0] == ' ');

        
        do
        {
            cout << endl << "Ingrese el numero de calle del cliente ('0' para salir): ";
            getline(cin, numero);
            if (numero == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (cin.fail() || !soloNumeros(numero) || numero[0] == ' ');

        
        do
        {
            cout << endl << "(Opcional) Ingrese la entre calle del cliente ('0' para salir, '-1' para omitir): ";
            getline(cin, entreCalles);
            if (entreCalles == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (cin.fail() || (!esCalleValida(entreCalles) && entreCalles != "-1") || entreCalles[0] == ' ');

        if (entreCalles == "-1")
        {
            entreCalles = ""; // Si el usuario ingresa '-1', se omite este campo
        }

        
        do
        {
            cleanScreen();
            cout << "Vive en edificio o en casa? (0. Salir | 1. Casa | 2. Edificio): ";
            getline(cin, esCasa);
            if (esCasa == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
        } while (cin.fail() || (esCasa != "1" && esCasa != "2"));

        if (esCasa == "2")
        {
            do
            {
                cout << endl << "Nombre del edificio ('0' para cancelar): ";
                getline(cin, nombreEdificio);
                if (nombreEdificio == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
            } while (cin.fail() || !soloLetras(nombreEdificio) || nombreEdificio[0] == ' ');

            do
            {
                cout << endl << "Numero de apartamento ('0' para cancelar): ";
                getline(cin, numeroApto);
                if (numeroApto == "0") {
                cout << "Cancelando alta de cliente." << endl;
                s->cancelarAltaCliente();
                return; // Salir del bucle y cancelar la alta
            }
            } while (cin.fail() || numeroApto[0] == ' ');
        }

        DtDireccion* direccion; // Declarar antes del if

        if (esCasa == "1")
        {
            direccion = new DtDireccionCasa(calle, numero, entreCalles);
        }
        else
        {
            direccion = new DtDireccionApto(calle, numero, entreCalles, nombreEdificio, numeroApto);
        }

        try
        {
            s->agregarCliente(nombre, telefono, direccion);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl
                 << "Cancelando alta de cliente." << endl;
            s->cancelarAltaCliente();
            pause();
            return;
        }

        string confirmar; //  Confirmacion de alta del cliente

        while (true)
        {
            do
            {
                cleanScreen();
                s->mostrarClienteTemporal();
                cout << "Dar de alta? (1. Si, 2. No): ";
                getline(cin, confirmar);
            } while (cin.fail() || (confirmar != "1" && confirmar != "2"));

            break;
        }

        cleanScreen();

        if (confirmar == "2")
        {
            s->cancelarAltaCliente();
            cout << "Alta de cliente cancelada." << endl;
            pause();
            return;
        }

        try
        {
            s->darAltaCliente();
            cout << "Cliente creado exitosamente." << endl;
            pause();
            return;
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}



void ventaADomicilio(ISistema *s)
{
    //Preguntar si existen productos Y repartidores
    if(s->getCantidadProductos() == 0)
    {
        cout << "No hay productos disponibles para la venta a domicilio." << endl;
        pause();
        return;
    }
    if(s->getCantidadRepartidores() == 0)
    {
        cout << "No hay repartidores disponibles para la venta a domicilio." << endl;
        pause();
        return;
    }
    cleanScreen();
    string telefono;
    cout << "Ingrese el telefono del cliente: ";
    cin >> telefono;
    cin.ignore();

    while (cin.fail() || !esTelefonoValido(telefono))
    {
        cout << "El telefono debe ser un numero y debe contener 9 digitos." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ingrese el telefono del cliente: ";
        cin >> telefono;
        cin.ignore();
    }

    try
    {
        if (!s->existeCliente(telefono))
        {
            cout << "El cliente no esta registrado. Desea registrarlo?" << endl;
            cout << "1. Si" << endl;
            cout << "0. No" << endl;
            int opcion;
            cin >> opcion;
            cin.ignore();

            if (opcion == 1)
            {
                altaCliente(s);
            }
            else
            {
                cout << "Venta a domicilio cancelada." << endl;
                pause();
                return;
            }
        }
        cleanScreen();
        s->seleccionarCliente(telefono);
        while (true)
        {
            cleanScreen();
            s->listarProductos();
            cout << "Ingrese el codigo del producto a agregar a la venta (o '0' para finalizar): ";
            string codigoProducto;
            cin >> codigoProducto;
            cin.ignore();

            if (codigoProducto == "0")
            {
                break; // Salir del bucle si el usuario ingresa '0'
            }
            if(cin.fail() || codigoProducto.empty())
            {
                cout << "El codigo del producto no puede estar vacio." << endl;
                pause();
                continue; // Volver a solicitar el codigo del producto
            }
            if(!s->existeProducto(codigoProducto))
            {
                cout << "El producto no existe." << endl;
                pause();
                continue; // Volver a solicitar el codigo del producto
            }

            cout << "Ingrese la cantidad de productos a agregar: ";
            int cantidad;
            cin >> cantidad;
            cin.ignore();

            if(cin.fail() || cantidad <= 0)
            {
                cout << "La cantidad debe ser un numero positivo." << endl;
                pause();
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue; // Volver a solicitar el codigo y la cantidad
            }

            s->seleccionarProductoDomicilio(codigoProducto, cantidad);
        }
        cleanScreen();
        
        s->listarRepartidores();

        int idRepartidor;
        while (true)
        {
            cout << endl << "Ingrese el ID del repartidor: ";
            cin >> idRepartidor;
            cin.ignore();

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Intente nuevamente." << endl;
                pause();
                continue;
            }

            try
            {
                s->seleccionarRepartidor(idRepartidor);
                break; 
            }
            catch (const invalid_argument &e)
            {
                cleanScreen();
                cout << "Error: " << e.what() << endl;
            }
        }
        
        cleanScreen();
        int confirmar;
        cout << "Desea confirmar la venta a domicilio? (1. Si, 0. No): ";
        cin >> confirmar;
        if (cin.fail() || (confirmar != 0 && confirmar != 1))
        {
            cout << "Opcion invalida. Debe ingresar 1 o 0." << endl;
            s->cancelarVentaDomicilio();
            return;
        }
        cin.ignore();

        cleanScreen();
        if (confirmar == 1 && !cin.fail())
        {
            cout << "Venta a domicilio iniciada exitosamente." << endl;
            s->imprimirFacturaDomicilio(s->generarFacturaDomicilio());
            pause();
        }
        else
        {
            s->cancelarVentaDomicilio();
            cout << "Venta a domicilio cancelada." << endl;
            pause();
        }
    }

    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
        pause();
        return;
    }
}

void quitarProductoVenta(ISistema *s)
{
    int codigoMesa, cantidad, idEmpleado;
    string codigoProducto;
    bool mantener = true;

    cleanScreen();
    s->listarMozos();
    cout << endl
         << "Ingrese el ID del empleado que quiere quitar un producto a una venta ('0' para salir): ";
    cin >> idEmpleado;
    cin.ignore();

    if (cin.fail() || idEmpleado < 0)
    {
        s->cancelarQuitarProductoVenta();
        throw invalid_argument("El ID del empleado debe ser un numero positivo.");
        return;
    }

    if (idEmpleado == 0)
    {
        cout << "Cancelando operacion." << endl;
        s->cancelarQuitarProductoVenta();
        return;
    }   
    s->seleccionarMozo(idEmpleado);
    cleanScreen();


    while (mantener)
    {
        cleanScreen();

        s->listarMesasConVentasEnCursoDeMozoSeleccionado();

        cout << endl << "Ingrese el numero de la mesa involucrada en la venta ('0' para salir): ";
        cin >> codigoMesa;
        cin.ignore();

        if (cin.fail() || codigoMesa < 0)
        {
            cout << "El codigo de la mesa debe ser un numero positivo." << endl;
            pause();
            continue;
        }

        if (codigoMesa == 0)
        {
            cout << "Cancelando Operacion." << endl;
            return;
        }

        try
        {
            s->elegirMesaDeMozoSeleccionado(codigoMesa);
            s->verificarMesaSeleccionadaConVentaEnCurso();
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            cout << "Cancelando operacion" << endl;
            s->cancelarQuitarProductoVenta();
            pause();
            return;
        }
        mantener = false;
    }

    mantener = true;

    while (mantener)
    {
        cleanScreen();
        s->listarProductosVentaSeleccionada();

        cout << endl << "Ingrese el codigo del producto a quitar de la venta ('0' para salir): ";
        cin >> codigoProducto;
        cin.ignore();

        if (cin.fail() || codigoProducto.empty())
        {
            cout << "El codigo del producto no puede estar vacio." << endl;
            pause();
            continue;
        }

        if (codigoProducto == "0")
        {
            cout << "Cancelando operacion." << endl;
            s->cancelarQuitarProductoVenta();
            pause();
            return;
        }

        try
        {
            s->seleccionarProductoDeVenta(codigoProducto);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            pause();
            continue;
        }

        cout << endl << "Ingrese cuantas unidades desea quitar del producto: ";
        cin >> cantidad;
        cin.ignore();

        if (cin.fail() || cantidad <= 0)
        {
            cout << "La cantidad debe ser un numero positivo." << endl;
            pause();
            continue;
        }

        try
        {
            s->quitarProductoVenta(cantidad);
            cout << "Producto quitado de la venta exitosamente." << endl;
            pause();
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
            pause();
            continue;
        }
    }
}

void bajaProducto(ISistema *s)
{
    cleanScreen();
    s->listarProductos();

    string codigoProducto;
    int opcion;
    cout << "Ingrese el codigo del producto a eliminar (0 para cancelar): ";
    cin >> codigoProducto;
    cin.ignore();

    if (cin.fail() || codigoProducto.empty())
    {
        cout << "El codigo del producto no puede estar vacio." << endl;
        pause();
        return;
    }

    if (codigoProducto == "0")
    {
        cout << "Cancelando operacion." << endl;
        return;
    }

    
    s->seleccionarProducto(codigoProducto);

    cleanScreen();

    s->mostrarProductoSeleccionado();

    cout << "¿Desea eliminar el producto seleccionado? (1. Si, 2. No): ";
    cin >> opcion;
    cin.ignore();

    if (cin.fail() || opcion == 2)
    {
        cout << "Opcion invalida. Operacion cancelada." << endl;
        s->cancelarBajaProducto();
        pause();
        return;
    }
    else
    {
        s->quitarProductoDelSistema(codigoProducto);
        cout << "Producto eliminado exitosamente." << endl;
        s->cancelarBajaProducto();
        pause();
    }
}

void borrarSistema(ISistema *s)
{
    cleanScreen();
    delete s; // Liberar memoria del sistema
    cout << "Sistema borrado exitosamente." << endl;
    pause();
}

int main()
{
    // pause(); // Uncomment this line if you want to pause the program at the start

    ISistema *s = Factory::getSistema();

    // pause(); // Uncomment this line if you want to pause the program after getting the system

    bool mantener = true;
    int opcion;
    string err = "";

    while (mantener)
    {
        ActorMenu opcionMenu = ActorMenu::noneMenu;

        mostrarMenu(s, opcionMenu);

        cout << endl << "> ";
        cin >> opcion;

        if (cin.fail())
        {
            limpiarCin();
            continue;
        }

        switch (opcion)
        {
        case 0:
            mantener = false;
            break;
        case 1:
            opcionMenu = AdministradorMenu;
            break;
        case 2:
            opcionMenu = MozoMenu;
            break;
        case 3:
            opcionMenu = RepartidorMenu;
            break;
        case 4:
            opcionMenu = ClienteMenu;
            break;
        case 5:
            opcionMenu = PoblarMenu;
            break;
        default:
            break;
        }

        while (opcionMenu != noneMenu)
        {
            mostrarMenu(s, opcionMenu);

            cout << endl << "> ";
            cin >> opcion;

            if (cin.fail())
            {
                limpiarCin();
                continue;
            }

            try
            {
                if (opcionMenu == AdministradorMenu)
                {
                    switch (opcion)
                    {
                    case 0:
                        opcionMenu = noneMenu;
                        break;
                    case 1: // Alta Producto
                        altaProducto(s);
                        break;
                    case 2: // Alta Cliente
                        altaCliente(s);
                        break;
                    case 3: // AltaEmpleado
                        agregarEmpleado(s);
                        break;
                    case 4: // Asignar mesas a mozos
                        asignarMesasMozos(s);
                        break;
                    case 5: // Venta a domicilio
                        ventaADomicilio(s);
                        break;
                    case 6:
                        ventasMozo(s);
                        break;
                    case 7: // Informacion de un producto
                        informacionProducto(s);
                        break;
                    case 8: // Resumen de facturacion de un dia
                        facturacionDia(s);
                        break;
                    case 9: // Baja de producto
                        bajaProducto(s);
                        break;
                    default:
                        break;
                    }
                }

                if (opcionMenu == MozoMenu)
                {
                    switch (opcion)
                    {
                    case 0:
                        opcionMenu = noneMenu;
                        break;
                    case 1: // Iniciar ventas en mesas
                        iniciarVenta(s);
                        break;
                    case 2: // Agregar producto a una venta
                        agregarProductoAVenta(s);
                        break;
                    case 3: // Quitar producto de una venta
                        quitarProductoVenta(s);
                        break;
                    case 4: // Facturacion de una venta
                        facturarVenta(s);
                        break;
                    default:
                        break;
                    }
                }

                if (opcionMenu == RepartidorMenu)
                {
                    switch (opcion)
                    {
                    case 0:
                        opcionMenu = noneMenu;
                        break;
                    case 1:
                        break;
                    default:
                        break;
                    }
                }

                if (opcionMenu == ClienteMenu)
                {
                    switch (opcion)
                    {
                    case 0:
                        opcionMenu = noneMenu;
                        break;
                    case 1:
                        break;
                    default:
                        break;
                    }
                }

                if (opcionMenu == PoblarMenu)
                {
                    switch (opcion)
                    {
                    case 0:
                        opcionMenu = noneMenu;
                        break;
                    case 1: // Poblar el sistema con datos de prueba
                        s->poblarSistema();
                        mostrarPoblacion(s);
                        break;
                    case 2: // Ver TODOS los datos actualmente ingresados
                        mostrarPoblacion(s);
                        break;
                    default:
                        break;
                    }
                }
            }
            catch (const invalid_argument &e)
            { // Este catch maneja TODOS los errores de los casos de uso.
                cleanScreen();
                cout << "Error: " << e.what() << endl;
                pause();
            }
        }
    }
    borrarSistema(s); // Liberar memoria del sistema
    return 0;
}
