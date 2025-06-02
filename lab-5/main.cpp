#include "clases/Factory/Factory.h"
#include "clases/Sistema/ISistema.h"

#include <iostream>
using namespace std;

int main(){
    ISistema * s = Factory::getSistema();
    return 0;
}
    