#include "Sistema.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema(){
    cout << "Hola, se ha creado el sistema" << endl;
}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}

void Sistema::saludar() {
    cout << "Hola, bienvenido al sistema!" << endl;
}


Sistema::~Sistema() {

}
