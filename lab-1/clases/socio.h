#ifndef SOCIO_H
#define SOCIO_H
#include <iostream>

using namespace std;

class Socio {
    private:
        string ci;
        string nombre;
    public:
        Socio(string, string);
        void setCI(string);
        void setNombre(string);
        string getCI();
        string getNombre();
        ~Socio();
};

#endif