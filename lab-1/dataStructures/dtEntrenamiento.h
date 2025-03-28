#pragma once

#include <iostream>
using namespace std;

#include "dtClase.h"
#include "../globals/constants.h"




class DtEntrenamiento : public DtClase{
  private:
    bool enRambla;
  public:
    DtEntrenamiento(int id, string nom, Turno turn, bool b);
    bool getRambla();
    ~DtEntrenamiento();
};
