#include "../../doctest.h"
#include "../../../datatypes/Direccion/DtDireccionApto.h"
#include <iostream>
using namespace std;

TEST_CASE("Test DtDireccionApto - Constructor and Getters")
{
    //calle, numero, entreCalles, nombre, numeroApto
    DtDireccionApto* direccionApto=new DtDireccionApto("Chetitos", "555", "Lagarca y Lloverga", "Se Largo a Lloverga", "101"); 
    CHECK(direccionApto->getCalle() == "Chetitos");
    CHECK(direccionApto->getNumero() == "555");
    CHECK(direccionApto->getEntreCalles() == "Lagarca y Lloverga");
    CHECK(direccionApto->getNombre() == "Se Largo a Lloverga");
    CHECK(direccionApto->getNumeroApto() == "101");
    if(cout << *direccionApto << endl){
        CHECK(true); // Si la impresion no lanza una excepcion, el test pasa
    } else {
        CHECK(false); // Si la impresion falla, el test falla
    }
    delete direccionApto; // Liberar memoria
}

