#pragma once

#include <iostream>

using namespace std;

class DtDireccion
{
protected:
    string calle;
    string numero;
    string entreCalles;

public:
    DtDireccion();
    DtDireccion(string, string, string);
    string getCalle();
    string getNumero();
    string getEntreCalles();
    friend ostream& operator<<(ostream&, const DtDireccion&);
    virtual ~DtDireccion();
};