    #include <iostream>
    #include <cassert>
    #include <limits.h>
    #include "../../clases/entrenamiento.h"

    using namespace std;


    int main()
    {
        //DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn){
        try{
            DtEntrenamiento dtTC001=DtEntrenamiento(1, "TC001", Tarde, true);
            Entrenamiento * TC001 = new Entrenamiento(dtTC001);
            assert(TC001->getRambla() == true);
            assert(TC001->cupo() == 20);
            assert(TC001->getTurno() == Tarde);
            assert(TC001->getNombre() == "TC001");
            assert(TC001->getId() == 1);

            delete TC001;
            cout << "Test Entrenamiento TC001 paso correctamente" << endl;
        }catch(...){
            cout << "Error inesperado en TC001" << endl;
        }
        try{
            DtEntrenamiento dtTC002=DtEntrenamiento(1, "TC002", Manana, true);
            Entrenamiento * TC002 = new Entrenamiento(dtTC002);
            assert(TC002->getRambla() == true);
            assert(TC002->cupo() == 20);
            assert(TC002->getTurno() == Manana);
            assert(TC002->getNombre() == "TC002");
            assert(TC002->getId() == 1);

            delete TC002;
            cout << "Test Entrenamiento TC002 paso correctamente" << endl;
        }catch(...){
            cout << "Error inesperado en TC002" << endl;
        }
        try{
            DtEntrenamiento dtTC003=DtEntrenamiento(2, "TC003", Tarde, false);
            Entrenamiento * TC003 = new Entrenamiento(dtTC003);
            assert(TC003->getRambla() == false);
            assert(TC003->cupo() == 10);
            assert(TC003->getTurno() == Tarde);
            assert(TC003->getNombre() == "TC003");  
            assert(TC003->getId() == 2);

            delete TC003;
            cout << "Test Entrenamiento TC003 paso correctamente" << endl;
        }catch(...){
            cout << "Error inesperado en TC003" << endl;
        }
        try{
            DtEntrenamiento dtTC004=DtEntrenamiento(3, "TC004", Noche, true);
            Entrenamiento * TC004 = new Entrenamiento(dtTC004);
            assert(TC004->getRambla() == true);
            assert(TC004->cupo() == 20);
            assert(TC004->getTurno() == Noche);
            assert(TC004->getNombre() == "TC004");  
            assert(TC004->getId() == 3);

            delete TC004;
            cout << "Test Entrenamiento TC004 paso correctamente" << endl;
        }catch(...){
            cout << "Error inesperado en TC004" << endl;
        }

    }