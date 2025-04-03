#pragma once

#include <iostream>
using namespace std;

#include "dtClase.h"

/*
  * @class DtEntrenamiento
  * @brief Represents a data transfer object for a training class.
  * 
  * The DtEntrenamiento class inherits from the DtClase class and includes additional
  * attributes and methods specific to training classes, such as whether the class
  * is held on a rambla.
*/
class DtEntrenamiento : public DtClase{
  private:
    bool enRambla;

  public:
    DtEntrenamiento(int id, string nom, Turno turn, bool b);
    bool getRambla();
    friend ostream& operator<<(ostream&, const DtEntrenamiento&);
    ~DtEntrenamiento();
};
