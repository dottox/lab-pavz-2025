
#include "spinning.h"


/**
 * @brief Constructor for the Spinning class.
 * 
 * Initializes a Spinning object with the given parameters.
 * 
 * @param id The unique identifier for the spinning class.
 * @param nom The name of the spinning class.
 * @param t The time slot (Turno) for the spinning class.
 * @param cantBici The number of bicycles available for the spinning class.
 */
Spinning::Spinning(int id, string nom, Turno t, int cantBici) : Clase(id, nom, t) {
    this->cantBicicletas = cantBici;
};


/**
 * @brief Returns the cupo of the class, polymorphic from Clase::cupo().
 * 
 * @return The number of bicycles available for the spinning class.
 */
int Spinning::cupo() {
    return this->getCantBicicletas();
};


/**
 * @brief Sets the number of bicycles available for the spinning class.
 * 
 * @param cantBici The number of bicycles available for the spinning class.
 */
void Spinning::setCantBicicletas(int cantBici) {
    this->cantBicicletas = cantBici;
};


/**
 * @brief Returns the number of bicycles available for the spinning class.
 * 
 * @return The number of bicycles available for the spinning class.
 */
int Spinning::getCantBicicletas() {
    return this->cantBicicletas;
};


/**
 * @brief Destructor for the Spinning class.
 */
Spinning::~Spinning() {
    cout << "Spinning destruído" << endl;
};
