#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H

#include <iostream>
using namespace std;

#include "dtClase.h"

class DtEntrenamiento : public DtClase{
  private:
    bool enRambla;
  public:
    DtEntrenamiento(int id, string nom, Turno turn, bool b);
    bool getRambla();
    ~DtEntrenamiento();
};

#endif