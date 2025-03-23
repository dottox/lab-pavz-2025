#include <iostream>
#include "../../clases/socio.h"
#define MAX_SOCIOS 10

using namespace std;

class Sistema {
  private:
    int cantSocios = 0;
    Socio** socios = new Socio*[MAX_SOCIOS];

  public:
    Sistema() {
      cout << "Sistema creado" << endl;
    }

    // void agregarSocio(string ci, string nombre)
    // Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepción
    // std::invalid_argument.
    void agregarSocio(string ci, string nombre){
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
    };

    Socio* getSocio(string ci){
      for(int i = 0; i < cantSocios; i++){
        if(socios[i]->getCI() == ci){
          return socios[i];
        }
      }
      throw invalid_argument("No existe un socio con esa CI");
    }

    ~Sistema() {
      cout << "Sistema destruido" << endl;
    }
};

int main(){
    Sistema* sistema = new Sistema();

    // This should be in main.cpp
    sistema->agregarSocio("1", "Juan");
    sistema->agregarSocio("2", "Maria");
    sistema->agregarSocio("3", "Nacho");
    sistema->agregarSocio("4", "Pedro");
    sistema->agregarSocio("5", "Jose");
    sistema->agregarSocio("6", "Josefina");
    sistema->agregarSocio("7", "Julieta");
    sistema->agregarSocio("8", "Pepe");
    sistema->agregarSocio("9", "Eduardo");
    sistema->agregarSocio("10", "Wally");

    try{
        sistema->agregarSocio("11", "Lol");
    }catch(...){
        cout << "Error: No se pueden agregar mas socios" << endl;
    }

    try{
        sistema->agregarSocio("1", "Maria");
    }catch(...){
        cout << "Error: Socio con CI repetida" << endl;
    }

    try{
        sistema->getSocio("1387");
    }catch(...){
        cout << "Error: Socio no encontrado" << endl;
    }

    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;

    delete sistema;
}