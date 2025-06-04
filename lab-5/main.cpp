#include <iostream>
#include <cctype>
#include <limits>
#include <cstring>  // Para strcpy
#include "clases/Factory/Factory.h"
#include "clases/Sistema/ISistema.h"

#include <iostream>
#include <cctype>
#include <limits>
using namespace std;


void cleanScreen(){
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}

void pause(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string dummy;
    cout << "Presiona cualquier tecla para continuar.";
    getline(cin, dummy);
}

void limpiarCin(){
    cleanScreen();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Has ingresado una opcion invalida." << endl << endl;
    pause();
}


void mostrarMenu(ISistema* s) {
    cleanScreen();
    cout << "Ingrese una opcion: " << endl;
    cout << "0. Listar todo el sistema" << endl;
    cout << "1. Alta producto" << endl;
    cout << "9. Salir" << endl;
}

void altaProducto(ISistema* s) {
    cleanScreen();
    
    bool existenProductos = s->getCantidadProductos() > 0;

    cout << "Selecciona el tipo de producto a crear:" << endl;
    cout << "1. Plato" << endl;

    if (existenProductos) {
        cout << "2. Menu" << endl;
    }

    int opcion;
    cin >> opcion;

    cin.ignore();

    if (cin.fail() || (opcion != 1 && (opcion != 2 || !existenProductos))) {
        limpiarCin();
        return;
    }

    if (opcion == 1) {
        s->seleccionarTipoProducto(TipoProducto::TipoPlato);
    }
    else if (opcion == 2) {
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

    char* codigo = new char[code.size() + 1]; // Reservar memoria para el código, al finalizar el caso de uso se eliminará.
    strcpy(codigo, code.c_str());

    if (opcion == 1) {
        cleanScreen();
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        cin.ignore();
        if(cin.fail() || precio <= 0) {
            delete[] codigo; // Liberar memoria del código
            throw invalid_argument("El precio debe ser un número positivo.");
        }
        DtPlato dtPlato(codigo, descripcion, precio);
        s->crearPlato(dtPlato);
    }
    
    if (opcion == 2) {
        DtMenu dtMenu(codigo, descripcion);
        s->crearMenu(dtMenu);
        
        string code2; // Antes de agregar el plato al menu, creamos una copia del código en forma de char*
        int cantidad;
        bool salir = false;
        
        ICollection* platos = s->obtenerPlatos();
        
        while(salir != true){
            cleanScreen();

            IIterator* it = platos->getIterator();

            cout << "Platos disponibles para añadir al menu:" << endl;

            while (it->hasCurrent()) {
                DtPlato* plato = dynamic_cast<DtPlato*>(it->getCurrent());
                if (plato) {
                    cout << *plato << endl;
                }
                it->next();
            }
            delete it; // Liberar memoria del iterador

            cout << "Seleccione el plato a añadir al menu (ingrese el codigo)." << endl;
            cout << "Ingrese 'exit' para terminar de añadir platos: " << endl;
            cin >> code2;
            cin.ignore();

            if (code2 == "exit"){
                salir = true;
                continue;
            }

            cout << "Ingrese una cantidad de platos '"<< code2 <<"' a añadir: ";
            cin >> cantidad;
            cin.ignore();

            if (cin.fail() || cantidad <= 0) {
                cout << "La cantidad debe ser un número positivo." << endl;
                pause();
                continue;
            }

            char* codigoPlato = new char[code2.size() + 1]; // Reservar memoria para el código, al finalizar el caso de uso se eliminará.
            strcpy(codigoPlato, code2.c_str());

            try{
                s->añadirPlatoAMenu(codigoPlato, cantidad);
                cout << "Plato '"<< code2 <<"' añadido al menu temporal." << endl;
            }catch(const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            delete[] codigoPlato;
            pause();
        }
        
        delete platos; // Liberar memoria de la colección de platos
    }

    cleanScreen();

    s->listarProductoTemporal();

    cout << endl << "¿Confirmar alta del producto?: " << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> opcion;
    if (cin.fail() || (opcion != 1 && opcion != 2)) {
        limpiarCin();
        return;
    }
    if (opcion == 1) {
        s->darAltaProducto();
        cout << "Producto creado exitosamente." << endl;
    } else {
        s->cancelarAltaProducto();
        cout << "Creación de producto cancelada." << endl;
    }
    delete[] codigo;
    pause();
}


int main() {
    ISistema * s = Factory::getSistema();

    pause();

    bool mantener = true;
    int opcion;

    while(mantener){

        mostrarMenu(s);

        cin >> opcion;

        if(cin.fail()){
            limpiarCin();
            continue;
        }

        switch(opcion){
            case 1:
                try{
                    altaProducto(s);
                }catch(const invalid_argument& e) {
                    cleanScreen();
                    cout << "Error: " << e.what() << endl;
                    pause();
                }
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
                s->listarProductoTemporal();
                pause();
                break;
            default:
                limpiarCin();
                break;
        }
    
    }
    
    
    return 0;
}
    