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
    Spinning * TC001 = new Spinning(1, "TC001", Manana, 0);
    assert(TC001->getCantBicicletas() == 0);
    Spinning * TC002 = new Spinning(2, "TC002", Tarde, 1); 
    assert(TC002->getCantBicicletas() == 1);
    Spinning * TC003 = new Spinning(3, "TC003", Noche, 49);
    assert(TC003->getCantBicicletas() == 49);
    Spinning * TC004 = new Spinning(4, "TC004", Manana, 50);
    assert(TC004->getCantBicicletas() == 50);
    Spinning * TC005 = new Spinning(5, "TC005", Tarde, 51);
    assert(TC005->getCantBicicletas() == 51);
    //-----------------------------------------------------

    // Float inválidos
    try{
        Spinning * TC006 = new Spinning(0.1, "TC006", Manana, 30);
        delete TC006;
    }catch(...){
        cout << "Error esperado" << endl;
    }

    try{
        Spinning * TC007 = new Spinning(6, "TC006", Tarde, 0.5);
        delete TC007;
    }catch(...){
        cout << "Resultado esperado" << endl;
    }
    
    try{
        Spinning * TC008 = new Spinning(7.5, "TC006", Noche, 5.1);
        delete TC008;
    }catch(...){
        cout << "Resultado esperado" << endl;
    }
    //-----------------------------------------------------
    cout << "Todos los tests pasaron correctamente." << endl;

    delete TC001;
    delete TC002;
    delete TC003;
    delete TC004;
    delete TC005;

    return 0;
}
