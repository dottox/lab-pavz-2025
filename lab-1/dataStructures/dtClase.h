#pragma once

#include <iostream>
#include "turno.h"
#include "../globals/constants.h"
#include <string>

using namespace std;


class DtClase {
  private:
    int id;
    string nombre;
    Turno turno;
    int cantCupo;

  public:
    DtClase();
    DtClase(int, string, Turno, int);
    int getId();
    string getNombre();
    Turno getTurno();
    int getCupo();
    virtual ~DtClase();
};
