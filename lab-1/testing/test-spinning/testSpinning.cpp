#include <iostream>
#include <cassert>
#include "../../clases/spinning.h"
#include "../../dataStructures/turno.cpp"
using namespace std;

int main()
{
    //TC = TEST CASE
    // ID, nombre, turno, cantBicicletas

    // BVA = Boundary Value Analysis
    Spinning TC001 = Spinning(1, "TC001", Manana, 0);
    assert(TC001.getCantBicicletas() == 0);
    Spinning TC002 = Spinning(2, "TC002", Tarde, 1); 
    assert(TC002.getCantBicicletas() == 1);
    Spinning TC003 = Spinning(3, "TC003", Noche, 49);
    assert(TC003.getCantBicicletas() == 49);
    Spinning TC004 = Spinning(4, "TC004", Manana, 50);
    assert(TC004.getCantBicicletas() == 50);
    Spinning TC005 = Spinning(5, "TC005", Tarde, 51);
    assert(TC005.getCantBicicletas() == 51);
    //-----------------------------------------------------

    // Float inválidos
    try{
        Spinning TC000 = Spinning(0.1, "TC006", Manana, 30);
    }catch(...){
        cout << "Error esperado" << endl;
    }

    try{
        Spinning TC007 = Spinning(6, "TC006", Tarde, 0.5);
    }catch(...){
        cout << "Resultado esperado" << endl;
    }
    
    try{
        Spinning TC008 = Spinning(7.5, "TC006", Noche, 5.1);
    }catch(...){
        cout << "Resultado esperado" << endl;
    }
    //-----------------------------------------------------
    cout << "Todos los tests pasaron correctamente." << endl;
    return 0;
}
