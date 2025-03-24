#pragma once

#include <iostream>
using namespace std;

class DtFecha {
  private:
    int dia;
    int mes;
    int anio;
  public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const DtFecha& other) const;
    ~DtFecha();
};
