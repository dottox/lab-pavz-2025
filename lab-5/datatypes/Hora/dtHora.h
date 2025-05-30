#pragma once

#include <iostream>
#include "../../utils/constant.h"

using namespace std;

class dtHora
{
private:
    int hora;
    int minuto;
    int segundo;

public:
    dtHora();
    dtHora(int, int, int);
    int getHora();
    int getMinuto();
    int getSegundo();
    bool operator==(const dtHora &other) const;
    friend ostream &operator<<(ostream &, const dtHora &);
    ~dtHora();
};