#include <iostream>
#include "../../clases/sistema.h"

using namespace std;
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