#ifndef DT_SOCIO
#define DT_SOCIO
#include "turno.cpp"
#include <iostream>
using namespace std;

class DtSocio{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        DtSocio(){
            this->id = 0;
            this->nombre = "";
            this->turno = Manana;
        };
        DtSocio(int, string, Turno){
            this->id = id;
            this->nombre = nombre;
            this->turno = turno;
        };
        void setId(int){
            this->id = id;
        };
        void setNombre(string){
            this->nombre = nombre;
        };
        void  setTurno(Turno){
            this->turno = turno;
        };
        int getId(){
            return this->id;
        };
        string getNombre(){
            return this->nombre;
        };
        Turno getTurno(){
            return this->turno;
        };

        ~DtSocio(){};
};  


#endif