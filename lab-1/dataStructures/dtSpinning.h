#pragma once

#include <iostream>
#include <string>
#include "./dtClase.h"

class DtSpinning : public DtClase {
  private:
    int cantBicicletas;

  public:
    DtSpinning(int id, string nom, Turno turn, int cantBicicletas);
    int getCupo();
    int getCantBicicletas();
    friend ostream& operator<<(ostream&, const DtSpinning&);
    ~DtSpinning();
};
