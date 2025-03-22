#ifndef DT_SOCIO
#define DT_SOCIO

#include <iostream>
using namespace std;

class DtSocio{
    private:
        int ci;
        string nombre;
    public:
        DtSocio(){
            throw invalid_argument("Constructor vacio no permitido\n");
        };
        DtSocio(int ci, string nombre){
            this->ci = ci;
            this->nombre = nombre;
        };
        int getCi(){
            return this->ci;
        }
        string getNombre(){
            return this->nombre;
        }

        ~DtSocio(){}
};

#endif