#pragma once

#include <iostream>
#include <string>
#include "./dtClase.h"

class DtSpinning : public DtClase {
  private:
    int cantBicicletas;

  public:
    DtSpinning();
    DtSpinning(int id, string nom, Turno turn, int cantBicicletas);
    int getCupo();
    int getCantBicicletas();
    ~DtSpinning();
};
