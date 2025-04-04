#pragma once

#include <iostream>
#include <string>
#include "./dtClase.h"

/*
  * @class DtSpinning
  * @brief Represents a data transfer object for a spinning class.
  * 
  * The DtSpinning class encapsulates the details of a spinning class,
  * including its ID, name, turn, and number of bicycles. It provides
  * methods to retrieve this information and to output it in a formatted manner.
*/
class DtSpinning : public DtClase {
  private:
    int cantBicicletas;

  public:
    DtSpinning(int id, string nom, Turno turn, int cantBicicletas);
    int getCantBicicletas();
    friend ostream& operator<<(ostream&, const DtSpinning&);
    ~DtSpinning();
};
