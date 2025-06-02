#pragma once

#include <iostream>
using namespace std;

class ISistema {
    public:
        virtual void saludar() = 0;
        ~ISistema();
};