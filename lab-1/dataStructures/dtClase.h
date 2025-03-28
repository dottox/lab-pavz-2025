#pragma once

#include <iostream>
#include "turno.h"
#include <string>

using namespace std;


class DtClase {
  private:
    int id;
    string nombre;
    Turno turno;

  public:
    DtClase();
    DtClase(int, string, Turno);
    int getId();
    string getNombre();
    Turno getTurno();
    virtual ~DtClase();
};
