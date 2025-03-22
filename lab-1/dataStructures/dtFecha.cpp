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
            throw invalid_argument("Constructor vacio no permitido\n");
        };
        DtFecha(int dia, int mes, int anio){
            if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900){
                throw invalid_argument("Fecha invalida\n");
            }
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