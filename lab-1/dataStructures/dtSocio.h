#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "../globals/constants.h"

using namespace std;

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

