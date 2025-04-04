#pragma once

#include <iostream>
#include "../globals/constants.h"

using namespace std;

/*
  * @class DtFecha
  * @brief Represents a date with day, month, and year.
  * 
  * The DtFecha class encapsulates the details of a date, including its
  * day, month, and year. It provides methods to retrieve this information
  * and to compare dates.
*/
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
    friend ostream& operator<<(ostream&, const DtFecha&);
    ~DtFecha();
};

