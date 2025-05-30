#pragma once

#include <iostream>

using namespace std;

class dtDireccion
{
protected:
    string calle;
    int numero;
    string entreCalles;

public:
    dtDireccion();
    dtDireccion(string, int, string);
    string getCalle();
    int getNumero();
    string getEntreCalles();
    virtual ~dtDireccion();
};