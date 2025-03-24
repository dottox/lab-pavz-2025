
#include "socio.h"

/**
 * @brief Constructor for the Socio class.
 * 
 * This constructor initializes a Socio object with the provided
 * CI (identification number) and name.
 * 
 * @param ci The CI (identification number) of the socio.
 * @param nom The name of the socio.
 */
Socio::Socio(DtSocio socioData){
    this->ci = socioData.getCi();
    this->nombre = socioData.getNombre();
};


/**
 * @brief Sets the CI (identification number) of the socio.
 * 
 * @param ci The CI (identification number) of the socio.
 */
void Socio::setCI(string ci){
    this->ci = ci;
};


/**
 * @brief Sets the name of the socio.
 * 
 * @param nom The name of the socio.
 */
void Socio::setNombre(string nom){
    this->nombre = nom;
};


/**
 * @brief Returns the CI (identification number) of the socio.
 * 
 * @return The CI (identification number) of the socio.
 */
string Socio::getCI(){
    return this->ci;
};


/**
 * @brief Returns the name of the socio.
 * 
 * @return The name of the socio.
 */
string Socio::getNombre(){
    return this->nombre;
};


/**
 * @brief Destructor for the Socio class.
 */
Socio::~Socio(){
    cout << "Socio: " << this->getNombre() <<  " erradicado" << endl; 
}