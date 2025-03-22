#ifndef DT_FECHA
#define DT_FECHA

#include <iostream>
using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        DtFecha(){
            this->dia = 0;
            this->mes = 0;
            this->anio = 0;
        };
        DtFecha(int, int, int){
            this->dia = dia;
            this->mes = mes;
            this->anio = anio;
        };
        int getDia(){
            return this->dia;
        };
        int getMes(){
            return this->mes;
        };
        int getAnio(){
            return this->anio;
        };
        ~DtFecha(){};
};


#endif