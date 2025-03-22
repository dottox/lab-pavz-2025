#ifndef DT_ENTRENAMIENTO
#define DT_ENTRENAMIENTO

#include <iostream>
using namespace std;


class DtEntrenamiento{
    private:
        bool enRambla;
    public:
        DtEntrenamiento(){
            this->enRambla = false;
        };
        DtEntrenamiento(bool b){
            this->enRambla = b;
        };
        bool getRambla(){
            return this->enRambla;
        };
        ~DtEntrenamiento(){};
};

#endif