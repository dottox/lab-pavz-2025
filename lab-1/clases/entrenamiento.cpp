
#include "./entrenamiento.h"

/**
 * @brief Constructor for the Entrenamiento class.
 * 
 * Initializes an Entrenamiento object with the specified data.
 * 
 * @param claseData The data for the training session, represented as a DtClase object.
 * @param enRambla Indicates whether the training session is at the Rambla.
 */
Entrenamiento::Entrenamiento(DtEntrenamiento claseData) : Clase::Clase(claseData){
    this->enRambla = claseData.getRambla();
    this->cantCupo = claseData.getCupo();
};


/**
 * @brief Returns whether the training session is held at the Rambla.
 * 
 * @return bool True if the training session is at the Rambla, false otherwise.
 */
bool Entrenamiento::getRambla(){
    return this->enRambla;
};


/**
 * @brief Destructor for the Entrenamiento class.
 */
Entrenamiento::~Entrenamiento(){};