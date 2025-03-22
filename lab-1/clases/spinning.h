
#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>

#include "clase.h"
#include "../dataStructures/turno.cpp"

using namespace std;

/**
 * @class Spinning
 * @brief Represents a Spinning class, which is a type of fitness class.
 * 
 * The Spinning class inherits from the Clase class and includes additional
 * attributes and methods specific to spinning classes, such as the number
 * of bicycles available.
 */
class Spinning : Clase {
  private:
    int cantBicicletas;

  public:
    Spinning(int, string, Turno, int);
    int cupo();
    void setCantBicicletas(int);
    int getCantBicicletas();
    ~Spinning();
};
#endif