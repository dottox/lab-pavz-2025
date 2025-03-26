#pragma once

#include "turno.h"
#include "../globals/constants.h"
#include <string>
#include <stdexcept>


class DtClase {
  private:
    int id;
    std::string nombre;
    Turno turno;
  public:
    DtClase();
    DtClase(int id, std::string nombre, Turno turn);
    int getId();
    std::string getNombre();
    Turno getTurno();
    virtual ~DtClase();
};
