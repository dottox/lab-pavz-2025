#include <iostream>
#include <cctype>
#include <limits>
#include "./clases/sistema.h"
#define SOCIOS_MAX 15
#define CLASES_MAX 15

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
    std::string dummy;
    std::cout << "Presiona cualquier tecla para continuar.";
    std::getline(std::cin, dummy);
}

void mostrarMenu(Sistema* s){
    cleanScreen();
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
    cleanScreen();
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Has ingresado una opcion invalida." << endl << endl;
    pause();
}

int main(){
    Sistema* s = new Sistema(SOCIOS_MAX, CLASES_MAX);

    bool salir = true, r;
    int opcion, idClase, cantBicis, turno, rambla, dia, mes, anio, cantSocios;
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
                cleanScreen();
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
                    s->agregarInscripcion("87654325", 1, DtFecha(1, 8, 2043));
                    s->agregarInscripcion("87654326", 1, DtFecha(2, 8, 2043));
                    s->agregarInscripcion("87654327", 1, DtFecha(3, 8, 2043));
                    s->agregarInscripcion("87654328", 2, DtFecha(4, 8, 2043));
                    s->agregarInscripcion("87654329", 2, DtFecha(5, 8, 2043));
                    s->agregarInscripcion("87654321", 2, DtFecha(6, 8, 2043));
                    s->agregarInscripcion("12345679", 2, DtFecha(7, 8, 2043));
                    s->agregarInscripcion("87654322", 3, DtFecha(8, 8, 2043));
                    s->agregarInscripcion("87654323", 3, DtFecha(9, 8, 2043));
                    s->agregarInscripcion("87654324", 3, DtFecha(10, 8, 2043));
                    s->agregarInscripcion("87654325", 3, DtFecha(11, 8, 2043));
                    s->agregarInscripcion("87654326", 4, DtFecha(12, 8, 2043));
                    s->agregarInscripcion("87654327", 4, DtFecha(13, 8, 2043));
                    s->agregarInscripcion("87654328", 4, DtFecha(14, 8, 2043));
                    s->agregarInscripcion("87654329", 5, DtFecha(15, 8, 2043));
                    s->agregarInscripcion("87654321", 5, DtFecha(16, 8, 2043));
                    s->agregarInscripcion("12345679", 5, DtFecha(17, 8, 2043));
                    s->agregarInscripcion("87654322", 5, DtFecha(18, 8, 2043));
                    s->agregarInscripcion("87654323", 6, DtFecha(19, 8, 2043));
                    s->agregarInscripcion("87654324", 6, DtFecha(20, 8, 2043));
                    s->agregarInscripcion("87654325", 6, DtFecha(21, 8, 2043));
                    s->agregarInscripcion("87654326", 6, DtFecha(22, 8, 2043));
                    s->agregarInscripcion("87654327", 7, DtFecha(23, 8, 2043));
                    s->agregarInscripcion("87654328", 7, DtFecha(24, 8, 2043));
                    s->agregarInscripcion("87654329", 7, DtFecha(25, 8, 2043));
                    s->agregarInscripcion("87654321", 8, DtFecha(26, 8, 2043));
                    s->agregarInscripcion("12345679", 8, DtFecha(27, 8, 2043));
                    s->agregarInscripcion("87654322", 8, DtFecha(28, 8, 2043));
                    s->agregarInscripcion("87654323", 9, DtFecha(29, 8, 2043));
                    s->agregarInscripcion("87654324", 9, DtFecha(30, 8, 2043));
                    s->agregarInscripcion("87654325", 9, DtFecha(31, 8, 2043));
                    s->agregarInscripcion("87654326", 10, DtFecha(1, 9, 2043));
                    s->agregarInscripcion("87654327", 10, DtFecha(2, 9, 2043));
                    s->agregarInscripcion("87654328", 10, DtFecha(3, 9, 2043));
                    s->agregarInscripcion("87654329", 10, DtFecha(4, 9, 2043));
                    //eliminar las incripciones de la clase 10
                    s->borrarInscripcion("87654326", 10);
                    s->borrarInscripcion("87654327", 10);
                    s->borrarInscripcion("87654328", 10);
                    s->borrarInscripcion("87654329", 10);
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }
                cout << "Sistema poblado." << endl << endl;
                pause();
                break;
            case 1:
                cleanScreen();
                cout << "[Agregando socio]" << endl;
                cout << "Cedula: ";
                cin >> ci;
                cout << "Nombre: ";
                cin >> nombre;
                try{
                    s->agregarSocio(ci, nombre);
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }

                cleanScreen();
                cout << "El usuario\n\nNombre: " << nombre << "\nCi: " << ci << "\n\nHa sido creado correctamente." << endl;
                pause();
                break;
            case 2:
                cleanScreen();
                cout << "[Agregando clase]" << endl << endl;
                cout << "[Seleccione un tipo]\n\n1. Spinning\n2. Entrenamiento" << endl;
                cin >> opcion;
                if(cin.fail() || opcion < 1 || opcion > 2){
                    limpiarCin();
                    continue;
                }
                cleanScreen();
                cout << "ID: ";
                cin >> idClase;
                cout << "Nombre: ";
                cin >> nombre;
                cleanScreen();
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
                cleanScreen();
                switch(opcion){
                    case 1:
                        cout << "Cantidad de bicicletas: ";
                        cin >> cantBicis;
                        try{
                            s->agregarClase(DtSpinning(idClase, nombre, t, cantBicis));
                        }catch(invalid_argument &e){
                            cleanScreen();
                            cout << "Error: " << e.what() << endl;
                            pause();
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
                            cleanScreen();
                            cout << "Error: " << e.what() << endl;
                            pause();
                            continue;
                        }
                        break;
                }

                cleanScreen();
                cout << s->obtenerClase(idClase);
                pause();
                break;
            case 3:
                cleanScreen();
                cout << "[Agregando inscripcion]" << endl << endl;
                cout << "Cedula del socio: ";
                cin >> ci;
                cout << "ID de la clase: ";
                cin >> idClase;
                cout << "Fecha de Inscripcion (DD/MM/AAAA)\nDia:";
                cin >> dia; 
                cout << "Mes:";
                cin >> mes;
                cout << "Anio:";
                cin >> anio;
                if(cin.fail()){
                    limpiarCin();
                    continue;
                }
                try{
                    DtFecha fecha = DtFecha(dia, mes, anio);
                    s->agregarInscripcion(ci, idClase, fecha);
                }catch(invalid_argument &e){
                    cleanScreen();
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }
                cleanScreen();
                cout << "[Inscripcion creada correctamente]" << endl << endl;
                cout << "Socio: " << ci << endl;
                cout << "ID: " << idClase << endl;
                cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl << endl;
                pause();
                break;
            case 4:
                cleanScreen();
                s->listarClases();
                pause();
                break;
            case 5:
                cleanScreen();
                s->listarSocios();
                pause();
                break;
            case 6:
                cleanScreen();
                cout << "[Obteniendo info de socios por clase]" << endl << endl;
                cout << "ID de la clase: ";
                cin >> idClase;
                cleanScreen();
                try{
                    Clase* clase = s->getClase(idClase);
                    if(clase == NULL){
                        throw invalid_argument(ERROR_NO_CLASE_ID);
                    }
                    if(clase->getCantInscripciones() == 0){
                        throw invalid_argument(ERROR_NO_INSCRIPCIONES);
                    }
                    cout << "La clase tiene " << clase->getCantInscripciones() << " socios inscriptos." << endl;
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }
                cout << "Cant de socios: ";
                cin >> cantSocios;
                if(cin.fail()){
                    limpiarCin();
                    continue;
                }
                cleanScreen();
                try{
                    DtSocio** sociosPorClase = s->obtenerInfoSociosPorClase(idClase, cantSocios);
                    cout << "---------- [Socios] ----------" << endl;
                    cout << "------- [ CI | Nombre ] ------";
                    for(int i = 0; i < cantSocios; i++){
                        cout << endl << *sociosPorClase[i];
                    }
                }catch(invalid_argument &e){
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }
                cout << "-------[Fin de la lista]------" << endl << endl;
                pause();
                break;
            case 7:
                cleanScreen();
                cout << "[Obteniendo clase]" << endl;
                cout << "ID: ";
                cin >> idClase;
                if(cin.fail()){
                    limpiarCin();
                    continue;
                }
                cleanScreen();
                try{
                    cout << "[Info de la Clase]\n" << endl << endl;
                    cout << s->obtenerClase(idClase) << endl;
                }catch(invalid_argument &e){
                    cleanScreen();
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }
                pause();
                break;
            case 8:
                // Borrar inscripcion
                cleanScreen();
                cout << "[Borrando inscripcion]" << endl << endl;
                cout << "Cedula del socio: ";
                cin >> ci;
                cout << "ID de la clase: ";
                cin >> idClase;
                if(cin.fail()){
                    limpiarCin();
                    continue;
                }

                //Una vez todo validado, borrar inscripcion
                try{
                    cout << "[Inscripcion borrada correctamente]" << endl << endl;
                    cout << "Socio: " << ci << endl;
                    cout << "ID: " << idClase << endl;

                    s->borrarInscripcion(ci, idClase);
                    
                }catch(invalid_argument &e){
                    cleanScreen();
                    cout << "Error: " << e.what() << endl;
                    pause();
                    continue;
                }

                cleanScreen();
                break;
            case 9:
                cleanScreen();
                salir = false;
                break;
            default:
                cleanScreen();
                cout << "Has ingresado una opcion invalida." << endl << endl;
                pause();
                break;
        }
    }
    cleanScreen();
    cout << "Borrando el sistema" << endl;
    delete s;
    cout << "Sistema borrado" << endl << endl;
    pause();
    cleanScreen();
    return 0;
}

