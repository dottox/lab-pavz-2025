#ifndef DTSOCIO_H
#define DTSOCIO_H


#include <string>
using namespace std;

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

#endif
