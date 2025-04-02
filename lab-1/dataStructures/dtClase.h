#pragma once

#include <iostream>
#include "turno.h"
#include "../globals/constants.h"
#include <string>

using namespace std;


class DtClase {
  protected:
    int id;
    string nombre;
    Turno turno;
    int cantCupos;

  public:
    DtClase();
    DtClase(int, string, Turno, int);
    int getId();
    string getNombre();
    Turno getTurno();
    int getCupo();
    friend ostream& operator<<(ostream&, const DtClase&);

    virtual ~DtClase();
};
