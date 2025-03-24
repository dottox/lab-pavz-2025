#include <iostream>
#include "../../clases/sistema.h"

using namespace std;
int main(){
    Sistema* sistema = new Sistema();

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

    try {
        sistema->agregarSocio("11", "Lol");
    } catch (const invalid_argument e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        sistema->agregarSocio("1", "Maria");
    } catch (const invalid_argument e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        sistema->getSocio("1387");
    } catch (const invalid_argument e) {
        cout << "Error: " << e.what() << endl;
    }

    delete sistema;

    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;
}