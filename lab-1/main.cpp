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
    cout << "3. Agregar inscripcion" << endl;
    cout << "4. Listar clases" << endl;
    cout << "5. Listar socios" << endl;
    cout << "6. Obtener info socios por clase" << endl;
    cout << "7. Obtener clase" << endl;
    cout << "8. Borrar inscripcion" << endl;
    cout << "9. Salir" << endl;
}

void limpiarCin(){
    system("cls");
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Has ingresado una opcion invalida." << endl << endl;
    system("pause");
}

int main(){
    Sistema* s = new Sistema(SOCIOS_MAX, CLASES_MAX);
    
    bool salir = true, r;
    int opcion, idClase, cantBicis, turno, rambla;
    string nombre, ci;
    Turno t;
    
    while(salir){

        mostrarMenu(s);

        cin >> opcion;

        if(cin.fail()){
            limpiarCin();
            continue;
        }

        switch(opcion){
            case 0:
                system("cls");
                try{

                    s->agregarSocio("87654321", "Jose_Jerbacio");
                    s->agregarSocio("12345679", "Nahuel_(nachota)");
                    s->agregarSocio("87654322", "Maria_Gonzalez");
                    s->agregarSocio("87654323", "Carlos_Perez");
                    s->agregarSocio("87654324", "Ana_Martinez");
                    s->agregarSocio("87654325", "Luis_Rodriguez");
                    s->agregarSocio("87654326", "Sofia_Lopez");
                    s->agregarSocio("87654327", "Miguel_Torres");
                    s->agregarSocio("87654328", "Laura_Ramirez");
                    s->agregarSocio("87654329", "Jorge_Fernandez");
                    s->agregarClase(DtSpinning(1, "Clase_2B", Manana, 33));
                    s->agregarClase(DtEntrenamiento(2, "Clase_Gym_Pederadasta", Tarde, true));
                    s->agregarClase(DtSpinning(3, "Clase_3C", Noche, 25));
                    s->agregarClase(DtEntrenamiento(4, "Clase_Gym_Avanzado", Manana, false));
                    s->agregarClase(DtSpinning(5, "Clase_5D", Tarde, 20));
                    s->agregarClase(DtEntrenamiento(6, "Clase_Gym_Intermedio", Noche, true));
                    s->agregarClase(DtSpinning(7, "Clase_7E", Manana, 30));
                    s->agregarClase(DtEntrenamiento(8, "Clase_Gym_Principiantes", Tarde, false));
                    s->agregarClase(DtSpinning(9, "Clase_9F", Noche, 28));
                    s->agregarClase(DtEntrenamiento(10, "Clase_Gym_Cardio", Manana, true));
                    s->agregarInscripcion("87654321", 1, DtFecha(1, 8, 2043));
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    system("pause");
                    continue;
                }
                cout << "Sistema poblado." << endl;
                system("pause");
                break;
            case 1:
                system("cls");
                cout << "[Agregando socio]" << endl;
                cout << "Cedula: ";
                cin >> ci;
                cout << "Nombre: ";
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
                system("cls");
                cout << "[Agregando clase]" << endl << endl;
                cout << "[Seleccione un tipo]\n\n1. Spinning\n2. Entrenamiento" << endl;
                cin >> opcion;
                if(cin.fail() || opcion < 1 || opcion > 2){
                    limpiarCin();
                    continue;
                }
                system("cls");
                cout << "ID: ";
                cin >> idClase;
                cout << "Nombre: ";
                cin >> nombre;
                system("cls");
                cout << "[Seleccione un Turno]\n\n1. Manana\n2. Tarde\n3. Noche" << endl;
                cin >> turno;
                if(cin.fail() || turno < 1 || turno > 3){
                    limpiarCin();
                    continue;
                }
                if(turno == 1){
                    t = Manana;
                }else if(turno == 2){
                    t = Tarde;
                }else if(turno == 3){
                    t = Noche;
                }
                system("cls");
                switch(opcion){
                    case 1:
                        cout << "Cantidad de bicicletas: ";
                        cin >> cantBicis;
                        try{
                            s->agregarClase(DtSpinning(idClase, nombre, t, cantBicis));
                        }catch(invalid_argument &e){
                            system("cls");
                            cout << "Error: " << e.what() << endl;
                            system("pause");
                            continue;
                        }
                        break;
                    case 2:
                        cout << "[Rambla]: \n\n1. Si\n2. No" << endl;
                        cin >> rambla;
                        if(cin.fail() || rambla < 1 || rambla > 2){
                            limpiarCin();
                            continue;
                        }
                        if(rambla == 1){
                            r = true;
                        }else if(rambla == 2){
                            r = false;
                        }
                        try{
                            s->agregarClase(DtEntrenamiento(idClase, nombre, t, r));
                        }catch(invalid_argument &e){
                            system("cls");
                            cout << "Error: " << e.what() << endl;
                            system("pause");
                            continue;
                        }
                        break;
                }
                system("cls");
                cout << s->obtenerClase(idClase);
                system("pause");
                break;
            case 3:
                // Llamar a agregar inscripcion
            case 4:
                system("cls");
                s->listarClases();
                system("pause");
                break;
            case 5:
                system("cls");
                s->listarSocios();
                system("pause");
                break;
            case 6:
                // Obtener info socios por clase
                break;
            case 7:
                system("cls");
                cout << "[Obteniendo clase]" << endl;
                cout << "ID: ";
                cin >> idClase;
                if(cin.fail()){
                    limpiarCin();
                    continue;
                }
                system("cls");
                try{
                    cout << "[Info de la Clase]\n" << endl;
                    cout << s->obtenerClase(idClase);
                }catch(invalid_argument &e){
                    system("cls");
                    cout << "Error: " << e.what() << endl;
                    system("pause");
                    continue;
                }
                system("pause");
                break;
            case 8:
                // Borrar inscripcion
                break;
            case 9:
                system("cls");
                salir = false;
                break;
            default:
                system("cls");
                cout << "Has ingresado una opcion invalida." << endl << endl;
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