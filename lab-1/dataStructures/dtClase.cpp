#ifndef DT_SOCIO
#define DT_SOCIO
#include "turno.cpp"
#include <iostream>
using namespace std;

class DtClase{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        DtClase(){
            this->id = 0;
            this->nombre = "";
            this->turno = Manana;
        };
        DtClase(int, string, Turno){
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
        void setTurno(Turno){
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

        ~DtClase(){};
};  


#endif