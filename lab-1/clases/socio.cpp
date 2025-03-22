#include "socio.h"


Socio::Socio(string ci, string nom){
    this->ci = ci;
    this->nombre = nom;
};

void Socio::setCI(string ci){
    this->ci = ci;
};

void Socio::setNombre(string ci){
    this->nombre = nombre;
};

string Socio::getCI(){
    return this->ci;
};

string Socio::getNombre(){
    return this->nombre;
};

Socio::~Socio(){
    cout << "Socio: " << this->getNombre() <<  "destruido" << endl; 
}