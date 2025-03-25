#ifndef DTSPINNING_H
#define DTSPINNING_H

#include <iostream>
#include <string>
#include "./dtClase.h"

class DtSpinning : public DtClase {
  private:
    int cantBicicletas;
  public:
    DtSpinning();
    DtSpinning(int id, string nom, Turno turn, int cantBicicletas);
    int getCantBicicletas();
    ~DtSpinning();
};


#endif