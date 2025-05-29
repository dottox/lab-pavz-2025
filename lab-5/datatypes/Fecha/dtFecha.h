#pragma once

#include <iostream>
#include "../../utils/constant.h"

using namespace std;

class dtFecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    dtFecha();
    dtFecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const dtFecha &other) const;
    friend ostream &operator<<(ostream &, const dtFecha &);
    ~dtFecha();
};