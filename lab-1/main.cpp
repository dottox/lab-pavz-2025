#include <iostream>
#include <cctype>
#include <limits>
#include "./clases/sistema.h"

void mostrarMenu(){
    system("cls");
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Agregar socio" << endl;
    cout << "2. Agregar clase" << endl;
    cout << "3. Listar clases" << endl;
    cout << "4. Listar socios" << endl;
    cout << "5. Obtener info socios por clase" << endl;
    cout << "6. Obtener clase" << endl;
    cout << "7. Salir" << endl;
}

int main(){
    Sistema* s = new Sistema();
    
    bool salir = true;
    
    while(salir){
        int opcion;

        mostrarMenu();

        cin >> opcion;

        if(cin.fail()){
            system("cls");
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Has ingreasdo una opcion invalida." << endl << endl;
            system("pause");
            continue;
        }

        switch(opcion){
            case 1:
                // Llamar a agregar socio
                break;
            case 2:
                // Llamar a agregar clase
                break;
            case 3:
                s->listarClases();
                break;
            case 4:
                s->listarSocios();
                break;
            case 5:
                // Llamar a obtener info socios por clase
                break;
            case 6:
                // Llamar a obtener clase
                break;
            case 7:
                system("cls");
                salir = false;
                break;
            default:
                system("cls");
                cout << "Has ingresado una opcion invalida." << opcion << endl << endl;
                system("pause");
                break;
        }
    }
    cout << "Borrando el sistema" << endl;
    delete s;
    system("pause");
    system("cls");
    cout << "Sistema borrado" << endl << endl;
    return 0;
}