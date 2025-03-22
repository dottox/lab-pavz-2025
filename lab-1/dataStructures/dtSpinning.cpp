#ifndef DT_SPINNING
#define DT_SPINNING

#include <iostream>
using namespace std;

    class dtSpinning{
        private:
            int cantBicicletas;
        public:
            dtSpinning(){
                this->cantBicicletas = 0;
            };
            dtSpinning(int cantBicicletas){
                this->cantBicicletas = cantBicicletas;
            };
            int getCantBicicletas(){
                return this->cantBicicletas;
            };
            ~dtSpinning(){};
    };


#endif


/*
Existen dos tipos de clases en el gimnasio: Spinning y Entrenamiento. En el caso de Spinning se
conoce la cantidad de bicicletas con las que cuenta la clase, y en el caso de Entrenamiento se sabe si la
clase se realiza en la rambla o no. La cantidad de bicicletas de una clase de spinning debe ser a lo sumo
50.

*/