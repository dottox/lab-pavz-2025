#pragma once
#include <iostream>
#include "./clase.h"
using namespace std;

#include "../dataStructures/dtEntrenamiento.h"

/**
 * @class Entrenamiento
 * @brief Represents a training session, inheriting from the Clase class.
 * 
 * This class extends the functionality of the Clase class by adding a specific
 * attribute to indicate whether the training session takes place at the Rambla.
 */
class Entrenamiento : public Clase{
  private: 
    bool enRambla;
  public:
    Entrenamiento(DtEntrenamiento);
    int cupo();
    bool getRambla();
    ~Entrenamiento();
};
