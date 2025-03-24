#pragma once

#include <iostream>
#include "./dtClase.h"

class DtSpinning : public DtClase {
  private:
    int cantBicicletas;
  public:
    DtSpinning();
    DtSpinning(int id, std::string nom, Turno turn, int cantBicicletas);
    int getCantBicicletas();
    ~DtSpinning();
};


