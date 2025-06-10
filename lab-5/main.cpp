#include <iostream>
#include <cctype>
#include <limits>
#include <cstring> // Para strcpy
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    cout << "Presiona cualquier tecla para continuar.";
    getline(cin, dummy);
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
        cout << "2. Alta de cliente (No implementado)" << endl;
        cout << "3. Alta de empleado" << endl;
        cout << "4. Asignar mesas a mozos (No implementado)" << endl;
        cout << "5. Venta a domicilio (No implementado)" << endl;
        cout << "6. Ventas de un mozo (No implementado)" << endl;
        cout << "7. Información de un producto (No implementado)" << endl;
        cout << "8. Resumen de facturacion de un dia" << endl;
        cout << "9. Baja de producto (No implementado)" << endl;
        cout << "0. Salir" << endl;
        break;
    case ActorMenu::MozoMenu:
        cleanScreen();
        cout << "Bienvenido al menu Mozo." << endl
             << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Iniciar ventas en mesas (No implementado)" << endl;
        cout << "2. Agregar producto a una venta (En proceso)" << endl;
        cout << "3. Quitar producto de una venta (No implementado)" << endl;
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
    cout << "Ingrese el código del producto (menu/plato): ";
    getline(cin, code);

    cleanScreen();
    cout << "Ingrese la descripcion del producto (menu/plato): ";
    getline(cin, descripcion);

    char *codigo = new char[code.size() + 1]; // Reservar memoria para el código, al finalizar el caso de uso se eliminará.
    strcpy(codigo, code.c_str());

    if (opcion == 1)
    {
        cleanScreen();
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        cin.ignore();
        if (cin.fail() || precio <= 0)
        {
            delete[] codigo; // Liberar memoria del código
            throw invalid_argument("El precio debe ser un número positivo.");
        }
        DtPlato dtPlato(codigo, descripcion, precio);
        s->crearPlato(dtPlato);
    }

    if (opcion == 2)
    {
        DtMenu dtMenu(codigo, descripcion);
        s->crearMenu(dtMenu);

        string code2; // Antes de agregar el plato al menu, creamos una copia del código en forma de char*
        int cantidad;
        bool salir = false;

        ICollection *platos = s->obtenerPlatos();

        while (salir != true)
        {
            cleanScreen();

            IIterator *it = platos->getIterator();

            cout << "Platos disponibles para añadir al menu:" << endl;

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

            cout << "Seleccione el plato a añadir al menu (ingrese el codigo)." << endl;
            cout << "Ingrese 'exit' para terminar de añadir platos: " << endl;
            cin >> code2;
            cin.ignore();

            if (code2 == "exit")
            {
                salir = true;
                continue;
            }

            cout << "Ingrese una cantidad de platos '" << code2 << "' a añadir: ";
            cin >> cantidad;
            cin.ignore();

            if (cin.fail() || cantidad <= 0)
            {
                cout << "La cantidad debe ser un número positivo." << endl;
                pause();
                continue;
            }

            char *codigoPlato = new char[code2.size() + 1]; // Reservar memoria para el código, al finalizar el caso de uso se eliminará.
            strcpy(codigoPlato, code2.c_str());

            try
            {
                s->anadirPlatoAMenu(codigoPlato, cantidad);
                cout << "Plato '" << code2 << "' añadido al menu temporal." << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            delete[] codigoPlato;
            pause();
        }

        delete platos; // Liberar memoria de la colección de platos
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
        cout << "Creación de producto cancelada." << endl;
    }
    delete[] codigo;
    pause();
}

void facturarVenta(ISistema *s)
{
    cleanScreen();
    s->listarMesasConVentasEnCurso();

    int codigoMesa, descuento;

    cout << "Ingrese el codigo de la mesa: " << endl;
    cin >> codigoMesa;

    cleanScreen();

    s->elegirMesa(codigoMesa);

    cout << "Ingrese el descuento a aplicar (0-100): ";
    cin >> descuento;

    while (cin.fail() || descuento < 0 || descuento > 100)
    {
        cout << "Descuento invalido. Ingrese un descuento entre 0 y 100: ";
        cin >> descuento;
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
    cout << "Sin implementar por el momento." << endl;
    pause();
}

void agregarEmpleado(ISistema *s)
{
    cleanScreen();
    string nombre, cargo, transporte;
    int opcion, opcion2;
    bool bandera = true;
    while (bandera)
    {
        cleanScreen();
        string nombre, cargo;
        int opcion, opcion2;

        cout << "Que desea hacer?" << endl;
        cout << "1. Agregar Mozo" << endl;
        cout << "2. Agregar Repartidor" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            bandera = false;
            break;
        case 1:
            cargo = "Mozo";
            break;
        case 2:
            cargo = "Repartidor";
            cout << "Seleccione el transporte del repartidor. ";
            s->listarTransportes();
            cout << "Ingrese el numero del transporte: ";
            cin >> opcion2;
            while (cin.fail() || opcion2 < 1 || opcion2 > 4)
            {
                limpiarCin();
                cout << "Opcion invalida. Ingrese un número entre 1 y 4: ";
                cin >> opcion2;
            }
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

        if (bandera == false)
            break;

        cout << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, nombre);

        bool nombreValido = true;
        for (char c : nombre)
        {
            if (!isalpha(c) && c != ' ')
            {
                nombreValido = false;
                break;
            }
        }

        if (!nombreValido || nombre.empty() || nombre.find_first_not_of(' ') == string::npos)
        {
            cout << "Nombre invalido. Intente nuevamente." << endl;
            pause();
            continue;
        }

        cout << "Desea agregar el empleado '" << nombre << "' con cargo '" << cargo << "'?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> opcion;

        if (cin.fail() || (opcion != 1 && opcion != 2))
        {
            limpiarCin();
            cout << "Opcion invalida." << endl;
            pause();
            continue;
        }

        if (opcion == 2)
        {
            cout << "Operacion cancelada." << endl;
            s->cancelarAltaEmpleado();
            pause();
            continue;
        }

        s->agregarEmpleado(nombre, cargo);
        int id = s->darDeAltaEmpleado();
        cout << "Empleado '" << nombre << "' con ID " << id << " creado exitosamente." << endl;
        pause();
    }
}

int main()
{
    ISistema *s = Factory::getSistema();

    bool mantener = true;
    int opcion;
    string err = "";

    while (mantener)
    {
        ActorMenu opcionMenu = ActorMenu::noneMenu;

        mostrarMenu(s, opcionMenu);

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
                        break;
                    case 3:
                        agregarEmpleado(s);
                        break;
                    case 4: // Asignar mesas a mozos
                        break;
                    case 5: // Venta a domicilio
                        break;
                    case 6: // Ventas de un mozo
                        break;
                    case 7: // Información de un producto
                        break;
                    case 8: // Resumen de facturación de un día
                        facturacionDia(s);
                        break;
                    case 9: // Baja de producto
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
                        break;
                    case 2: // Agregar producto a una venta
                        break;
                    case 3: // Quitar producto de una venta
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
                        cleanScreen();
                        s->poblarSistema();
                        mostrarPoblacion(s);
                        break;
                    case 2: // Ver TODOS los datos actualmente ingresados
                        cleanScreen();
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
    return 0;
}
