#pragma once

#include <iostream>

using namespace std;

class DtDireccion
{
protected:
    string calle;
    int numero;
    string entreCalles;

public:
    DtDireccion();
    DtDireccion(string, int, string);
    string getCalle();
    int getNumero();
    string getEntreCalles();
    friend ostream& operator<<(ostream&, const DtDireccion&);
    virtual ~DtDireccion();
};