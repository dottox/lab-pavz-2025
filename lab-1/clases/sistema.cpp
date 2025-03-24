#include "sistema.h"

Sistema::Sistema(){
    this->cantSocios = 0;
    this->socios = new Socio*[MAX_SOCIOS];
};


// void agregarSocio(string ci, string nombre)
// Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepción
// std::invalid_argument.
void Sistema::agregarSocio(string ci, string nombre){
    if(this->cantSocios >= MAX_SOCIOS){
      throw invalid_argument("No se pueden agregar más socios");
    }
    for(int i = 0; i < cantSocios; i++){
      if(socios[i]->getCI() == ci){
        throw invalid_argument("Ya existe un socio con esa CI");
      }
    }
    DtSocio socioData = DtSocio(ci, nombre);
    this->socios[cantSocios] = new Socio(socioData);
    this->cantSocios++;
    delete &socioData;
}

Socio* Sistema::getSocio(string ci){
    for(int i = 0; i < cantSocios; i++){
        if(socios[i]->getCI() == ci){
        return socios[i];
        }
    }
    throw invalid_argument("No existe un socio con esa CI");
}

Sistema::~Sistema(){
    for(int i = 0; i < cantSocios; i++){
        delete socios[i];
    }
    delete[] socios;
}