#ifndef FACTORY_H
#define FACTORY_H

#include "../Sistema/ISistema.h"
#include "../Sistema/Sistema.h"

class Factory {
    public:
        static ISistema * getSistema();
};

#endif