#ifndef DT_ENTRENAMIENTO
#define DT_ENTRENAMIENTO

#include <iostream>
using namespace std;

#include "dtClase.cpp"

class DtEntrenamiento : public DtClase{
    private:
        bool enRambla;
    public:
        DtEntrenamiento(int id, string nom, Turno turn, bool b) : DtClase(id, nom, turn){
            this->enRambla = b;
        };
        bool getRambla(){
            return this->enRambla;
        };
        ~DtEntrenamiento(){};
};

#endif