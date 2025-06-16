#include "../../doctest.h"
#include "../../../datatypes/Direccion/DtDireccionCasa.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtDireccionCasa - Constructor and Getters") 
{
    
    DtDireccionCasa * direccionCasa = new DtDireccionCasa("Calle Falsa", "123", "Entre A y B");

    CHECK(direccionCasa->getCalle() == "Calle Falsa");
    CHECK(direccionCasa->getNumero() == "123");
    CHECK(direccionCasa->getEntreCalles() == "Entre A y B");
    
    // Verificar que la impresion funcione correctamente
    if(cout << *direccionCasa << endl){
        CHECK(true); // Si la impresion no lanza una excepcion, el test pasa
    } else {
        CHECK(false); // Si la impresion falla, el test falla
    }
    delete direccionCasa; // Liberar memoria
 }