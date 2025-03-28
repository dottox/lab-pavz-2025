#pragma once

#include <string>
#include <stdexcept>
using namespace std;
#define CI_LENGTH 8
#define NOMBRE_MIN_LENGTH 1

class DtSocio {
private:
  string ci;
  string nombre;

public:
  DtSocio(string ci, string nombre);
  string getCi();
  string getNombre();
  ~DtSocio();
};

