
#ifndef SOCIO_H
#define SOCIO_H
#include <iostream>

using namespace std;

/**
 * @class Socio
 * @brief Represents a member with a unique identification and name.
 * 
 * The Socio class provides methods to set and retrieve the member's 
 * identification (CI) and name. It is designed to encapsulate the 
 * member's data and ensure proper management of these attributes.
 */
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