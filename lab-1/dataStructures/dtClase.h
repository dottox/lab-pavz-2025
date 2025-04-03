#pragma once

#include <iostream>
#include "turno.h"
#include "../globals/constants.h"
#include <string>

using namespace std;

/*
  * @class DtClase
  * @brief Represents a data transfer object for a class.
  * 
  * The DtClase class encapsulates the details of a class, including its
  * ID, name, turn, and number of spots. It provides methods to retrieve
  * this information and to output it in a formatted manner.
*/
class DtClase {
  protected:
    int id;
    string nombre;
    Turno turno;
    int cantCupos;

  public:
    DtClase(int, string, Turno, int);
    int getId();
    string getNombre();
    Turno getTurno();
    int getCupo();
    friend ostream& operator<<(ostream&, const DtClase&);

    virtual ~DtClase();
};
