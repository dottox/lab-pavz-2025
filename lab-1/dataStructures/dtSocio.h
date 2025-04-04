#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "../globals/constants.h"

using namespace std;

/*
  * @class DtSocio
  * @brief Represents a data transfer object for a socio.
  * 
  * The DtSocio class encapsulates the details of a socio, including its
  * CI and name. It provides methods to retrieve this information and to
  * output it in a formatted manner.
*/
class DtSocio {
private:
  string ci;
  string nombre;

public:
  DtSocio(string ci, string nombre);
  string getCi();
  string getNombre();
  friend ostream& operator<<(ostream&, const DtSocio&);
  ~DtSocio();
};

