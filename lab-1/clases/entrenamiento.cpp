
#include "entrenamiento.h"


/**
 * @brief Calculates the maximum capacity (cupo) for the training session.
 * 
 * This method determines the capacity based on whether the training session
 * is held at the "Rambla" location or not. If the session is at the Rambla,
 * the capacity is 20; otherwise, it is 10.
 * 
 * @return int The maximum capacity for the training session.
 */
int Entrenamiento::cupo(){
    if (this->getRambla()) {
        return 20;
    } else {
        return 10;
    }
};


/**
 * @brief Returns whether the training session is held at the Rambla.
 * 
 * @return bool True if the training session is at the Rambla, false otherwise.
 */
bool Entrenamiento::getRambla(){
    return this->enRambla;
};