#pragma once

#include <iostream>

#include "clase.h"
#include "../dataStructures/dtSpinning.h"

using namespace std;

/**
 * @class Spinning
 * @brief Represents a Spinning class, which is a type of fitness class.
 * 
 * The Spinning class inherits from the Clase class and includes additional
 * attributes and methods specific to spinning classes, such as the number
 * of bicycles available.
 */
class Spinning : public Clase {
  private:
    int cantBicicletas;
    int cantCupo;

  public:
    Spinning(DtSpinning);
    int cupo();
    void setCantBicicletas(int);
    int getCantBicicletas();
    ~Spinning();
};
