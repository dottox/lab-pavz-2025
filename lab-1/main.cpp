#include <iostream>
#include <cctype>
#include <limits>
#include "./clases/sistema.h"

void mostrarMenu(Sistema* s){
    system("cls");
    cout << "Cantidad de usuarios: " << s->getCantSocios() << endl;
    cout << "Cantidad de clases: " << s->getCantClases() << endl << endl;
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
    int opcion;
    string nombre, ci;
    
    while(salir){

        mostrarMenu(s);

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
                system("cls");
                cout << "[Agregando socio]" << endl;
                cout << "Cedula: ";
                cin >> ci;
                cout << endl << "Nombre: ";
                cin >> nombre;
                try{
                    s->agregarSocio(ci, nombre);
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    system("pause");
                    continue;
                }
                system("cls");
                cout << "El usuario\n\nNombre: " << nombre << "\nCi: " << ci << "\n\nHa sido creado correctamente." << endl;
                system("pause");
                break;
            case 2:
                // Llamar a agregar clase
                break;
            case 3:
                system("cls");
                s->listarClases();
                system("pause");
                break;
            case 4:
                system("cls");
                s->listarSocios();
                system("pause");
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