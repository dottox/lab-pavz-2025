#include "../../doctest.h"
#include "../../../datatypes/Direccion/DtDireccion.h"
#include <iostream>
using namespace std;


TEST_CASE("Test DtDireccion - Constructor and Getters") 
{
    DtDireccion * direccion=new DtDireccion("Calle Direccion", 221, "Entre Pepe y Pepo");
    
    CHECK(direccion->getCalle() == "Calle Direccion");
    CHECK(direccion->getNumero() == 221);
    CHECK(direccion->getEntreCalles() == "Entre Pepe y Pepo");
    if(cout << *direccion << endl){
        CHECK(true); // Si la impresion no lanza una excepcion, el test pasa
    } else {
        CHECK(false); // Si la impresion falla, el test falla
    }
    delete direccion; // Liberar memoria
}

TEST_CASE("Test DtDireccion - Default Constructor") 
{
    DtDireccion * direccion = new DtDireccion();
    // CHECK(direccion->getCalle() == "");
    // CHECK(direccion->getNumero() == 0);
    // CHECK(direccion->getEntreCalles() == "");
    delete direccion; // Liberar memoria
}