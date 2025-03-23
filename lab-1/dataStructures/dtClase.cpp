#ifndef DT_CLASE
#define DT_CLASE
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
            throw invalid_argument("Constructor vacio no permitido\n");
        }
        DtClase(int id, string nombre, Turno turn){
            if(turn < Manana || turn > Noche){
                throw invalid_argument("Turno invalido\n");
            }
            this->id = id;
            this->nombre = nombre;
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

        virtual ~DtClase(){};
};  


#endif