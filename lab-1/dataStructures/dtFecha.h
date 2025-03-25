#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;

class DtFecha {
  private:
    int dia;
    int mes;
    int anio;
  public:
    DtFecha();
    DtFecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const DtFecha& other) const;
    ~DtFecha();
};

#endif // DTFECHA_H
