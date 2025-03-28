
#include "./inscripcion.h"

/**
 * @brief Constructor for the Inscripcion class.
 * 
 * Initializes an Inscripcion object with the specified date.
 * 
 * @param date The date of the inscription, represented as a DtFecha object.
 */
Inscripcion::Inscripcion(DtFecha date, Socio* socio){
    this->fecha = date;
    this->socio = socio;
};


/**
 * @brief Returns the date of the inscription.
 * 
 * @return The date of the inscription, represented as a DtFecha object.
 */
DtFecha Inscripcion::getFecha(){
    return this->fecha;
};

Socio* Inscripcion::getSocio(){
    return this->socio;
};


/**
 * @brief Destructor for the Inscripcion class.
 */
Inscripcion::~Inscripcion(){
    cout << "Inscripcion con fecha: " << this->fecha.getDia() << "/" << this->fecha.getMes() << "/" << this->fecha.getAnio() << " ha sido destruida." << endl;
};	