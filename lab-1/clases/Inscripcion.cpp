
#include "Inscripcion.h"

/**
 * @brief Constructor for the Inscripcion class.
 * 
 * Initializes an Inscripcion object with the specified date.
 * 
 * @param date The date of the inscription, represented as a DtFecha object.
 */
Inscripcion::Inscripcion(DtFecha date){
    this->fecha = date;
};


/**
 * @brief Returns the date of the inscription.
 * 
 * @return The date of the inscription, represented as a DtFecha object.
 */
DtFecha Inscripcion::getFecha(){
    return this->fecha;
};


/**
 * @brief Destructor for the Inscripcion class.
 */
Inscripcion::~Inscripcion(){};	