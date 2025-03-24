#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/entrenamiento.h"

using namespace std;


int main()
{
    //DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn){
    try{
        DtEntrenamiento dtTC001=DtEntrenamiento(1, "TC001", Manana, true);
        Entrenamiento * TC001 = new Entrenamiento(dtTC001);
        assert(TC001->getRambla() == true);
        assert(TC001->cupo() == 20);
        assert(TC001->getTurno() == Manana);
        assert(TC001->getNombre() == "TC001");
        assert(TC001->getId() == 1);

        delete TC001;
        cout << "Test Entrenamiento TC001 paso correctamente" << endl;
    }catch(...){
        cout << "Error inesperado en TC001" << endl;
    }
    try{
        DtEntrenamiento dtTC002=DtEntrenamiento(2, "TC002", Tarde, false);
        Entrenamiento * TC002 = new Entrenamiento(dtTC002);
        assert(TC002->getRambla() == false);
        assert(TC002->cupo() == 10);
        assert(TC002->getTurno() == Tarde);
        assert(TC002->getNombre() == "TC002");  
        assert(TC002->getId() == 2);

        delete TC002;
        cout << "Test Entrenamiento TC002 paso correctamente" << endl;
    }catch(...){
        cout << "Error inesperado en TC002" << endl;
    }
    try{
        DtEntrenamiento dtTC003=DtEntrenamiento(3, "TC003", Noche, true);
        Entrenamiento * TC003 = new Entrenamiento(dtTC003);
        assert(TC003->getRambla() == true);
        assert(TC003->cupo() == 20);
        assert(TC003->getTurno() == Noche);
        assert(TC003->getNombre() == "TC003");  
        assert(TC003->getId() == 3);

        delete TC003;
        cout << "Test Entrenamiento TC003 paso correctamente" << endl;
    }catch(...){
        cout << "Error inesperado en TC003" << endl;
    }

}