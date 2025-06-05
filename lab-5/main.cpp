#include <iostream>
#include <cctype>
#include <limits>
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
    std::string dummy;
    std::cout << "Presiona cualquier tecla para continuar.";
    std::getline(std::cin, dummy);
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

void mostrarMenu(ISistema *s)
{
    cleanScreen();
    cout << "Ingrese una opcion: " << endl;
    cout << "0. Listar todo el sistema" << endl;
    cout << "1. Alta producto" << endl;
    cout << "2. Facturar venta" << endl;
    cout << "9. Salir" << endl;
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

    if (cin.fail() || (opcion != 1 && (opcion != 2 || !existenProductos)))
    {
        limpiarCin();
        return;
    }

    if (opcion == 1)
    {
        s->seleccionarTipoProducto(TipoProducto::TipoPlato);
        DtPlato prod;
    }
    else if (opcion == 2)
    {
        s->seleccionarTipoProducto(TipoProducto::TipoMenu);
        DtMenu prod;
    }

    string codigo;
    string descripcion;
    float precio;

    cleanScreen();
    cout << "Ingrese el codigo del producto: ";
    getline(cin, codigo);
    cleanScreen();
    cout << "Ingrese la descripcion del producto: ";
    getline(cin, descripcion);

    if (opcion == 1)
    {
        cleanScreen();
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        cin.ignore();
        DtPlato dtPlato((char *)codigo.c_str(), descripcion, precio);
        s->crearPlato(dtPlato);
    }

    if (opcion == 2)
    {
        DtMenu dtMenu((char *)codigo.c_str(), descripcion);
        s->crearMenu(dtMenu);

        char *codigoPlato;
        int cantidad;

        ICollection *platos = s->listarPlatos();
        IIterator *it = platos->getIterator();

        do
        {
            cleanScreen();
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
            cout << "Seleccione el plato a añadir al menu (ingrese el codigo).";
            cout << "-1 para terminar de añadir platos: " << endl;
            cin >> codigoPlato;
            cin.ignore();

            if (codigoPlato == "-1")
                break;

            cout << "Ingrese la cantidad de platos a añadir: ";
            cin >> cantidad;
            cin.ignore();
            if (cin.fail() || cantidad <= 0)
            {
                limpiarCin();
                continue;
            }

            s->anadirPlatoAMenu(codigoPlato, cantidad);
            cout << "Plato añadido al menu." << endl;
            pause();
        } while (codigoPlato != "-1");

        delete it;     // Liberar memoria del iterador
        delete platos; // Liberar memoria de la colección de platos
    }

    cleanScreen();
    cout << "¿Confirmar alta del producto?: " << endl;
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
    s->imprimirFactura(s->mostrarFacturaGenerada());
    pause();
};

int main()
{

    ISistema *s = Factory::getSistema();

    bool mantener = true;
    int opcion;

    while (mantener)
    {

        mostrarMenu(s);

        cin >> opcion;

        if (cin.fail())
        {
            limpiarCin();
            continue;
        }

        switch (opcion)
        {
        case 1:
            altaProducto(s);
            break;
        case 2:
            facturarVenta(s);
            break;
        case 9:
            mantener = false;
            cout << "Saliendo del sistema..." << endl;
            break;
        case 0:
            cleanScreen();
            s->listarEmpleados();
            s->listarMesas();
            s->listarVentas();
            s->listarProductos();
            pause();
            break;
        default:
            limpiarCin();
            break;
        }
    }

    return 0;
}
