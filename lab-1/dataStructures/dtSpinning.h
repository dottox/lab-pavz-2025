#pragma once

#include <iostream>
#include "./dtClase.h"
#include "../globals/constants.h"
#define MIN_BICICLETAS 1
#define MAX_BICICLETAS 50

class DtSpinning : public DtClase {
  private:
    int cantBicicletas;
  public:
    DtSpinning();
    DtSpinning(int id, std::string nom, Turno turn, int cantBicicletas);
    int getCantBicicletas();
    ~DtSpinning();
};


