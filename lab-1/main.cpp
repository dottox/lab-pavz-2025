#include <iostream>
#include <cctype>
#include <limits>
#include "./clases/sistema.h"
#define SOCIOS_MAX 15
#define CLASES_MAX 15


void mostrarMenu(Sistema* s){
    system("cls");
    cout << "Cantidad de usuarios: " << s->getCantSocios() << "/" << SOCIOS_MAX << endl;
    cout << "Cantidad de clases: " << s->getCantClases() << "/" << CLASES_MAX << endl << endl;
    cout << "Ingrese una opcion: " << endl;
    cout << "0. Poblacion del sistema" << endl;
    cout << "1. Agregar socio" << endl;
    cout << "2. Agregar clase" << endl;
    cout << "3. Listar clases" << endl;
    cout << "4. Listar socios" << endl;
    cout << "5. Obtener info socios por clase" << endl;
    cout << "6. Obtener clase" << endl;
    cout << "7. Salir" << endl;
}

int main(){
    Sistema* s = new Sistema(SOCIOS_MAX, CLASES_MAX);
    
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
            case 0:
                system("cls");
                cout << "Poblando el sistema..." << endl << endl;
                s->agregarSocio("87654321", "Jose Jerbacio");
                s->agregarSocio("12345679", "Nahuel (nachota)");
                s->agregarSocio("87654322", "Maria Gonzalez");
                s->agregarSocio("87654323", "Carlos Perez");
                s->agregarSocio("87654324", "Ana Martinez");
                s->agregarSocio("87654325", "Luis Rodriguez");
                s->agregarSocio("87654326", "Sofia Lopez");
                s->agregarSocio("87654327", "Miguel Torres");
                s->agregarSocio("87654328", "Laura Ramirez");
                s->agregarSocio("87654329", "Jorge Fernandez");
                s->agregarClase(DtSpinning(1, "Clase 2B", Manana, 33));
                s->agregarClase(DtEntrenamiento(2, "Clase Gym Pederadasta", Tarde, true));
                s->agregarClase(DtSpinning(3, "Clase 3C", Noche, 25));
                s->agregarClase(DtEntrenamiento(4, "Clase Gym Avanzado", Manana, false));
                s->agregarClase(DtSpinning(5, "Clase 5D", Tarde, 20));
                s->agregarClase(DtEntrenamiento(6, "Clase Gym Intermedio", Noche, true));
                s->agregarClase(DtSpinning(7, "Clase 7E", Manana, 30));
                s->agregarClase(DtEntrenamiento(8, "Clase Gym Principiantes", Tarde, false));
                s->agregarClase(DtSpinning(9, "Clase 9F", Noche, 28));
                s->agregarClase(DtEntrenamiento(10, "Clase Gym Cardio", Manana, true));
                s->agregarInscripcion("87654321", 1, DtFecha(1, 8, 2043));
                cout << "Sistema poblado." << endl;
                system("pause");
                break;
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