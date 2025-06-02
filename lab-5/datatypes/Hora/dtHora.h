#pragma once

#include <iostream>
#include "../../utils/constant.h"

using namespace std;

class DtHora
{
private:
    int hora;
    int minuto;
    int segundo;

public:
    DtHora();
    DtHora(int, int, int);
    int getHora();
    int getMinuto();
    int getSegundo();
    bool operator==(const DtHora &other) const;
    friend ostream &operator<<(ostream &, const DtHora &);
    ~DtHora();
};