
#include "clase.h"

/**
 * @brief Constructor for the Clase class.
 * 
 * Initializes a Clase object using the data provided in a DtClase object.
 * 
 * @param claseData An object of type DtClase containing the initial data for the Clase.
 */
Clase::Clase(DtClase claseData){
    this->id = claseData.getId();
    this->nombre = claseData.getNombre();
    this->turno = claseData.getTurno();
    this->cantInscripciones = 0;
    this->inscripciones = new Inscripcion* [MAX_INSCRIPCIONES];
};


/**
 * @brief Returns the ID of the class.
 * 
 * @return The ID of the class.
 */
int Clase::getId(){
    return this->id;
};


/**
 * @brief Returns the name of the class.
 * 
 * @return The name of the class.
 */
string Clase::getNombre(){
    return this->nombre;
};


/**
 * @brief Returns the schedule of the class.
 * 
 * @return The schedule of the class.
 */
Turno Clase::getTurno(){
    return this->turno;
};


/**
 * @brief Adds an inscription to the class.
 * 
 * @param inscripcion The inscription to add to the class.
 */
void Clase::agregarInscripcion(Inscripcion* inscripcion){
    this->inscripciones[this->cantInscripciones] = inscripcion;
    this->cantInscripciones++;
};


/**
 * @brief Returns the inscriptions of the class.
 * 
 * @return An array of Inscripcion objects representing the inscriptions of the class.
 */
Inscripcion** Clase::getInscripciones(){
    return inscripciones;
};


/**
 * @brief Returns the number of inscriptions in the class.
 * 
 * @return The number of inscriptions in the class.
 */
int Clase::getCantInscripciones(){
    return this->cantInscripciones;
};


/**
 * @brief Destructor for the Clase class.
 */
Clase::~Clase(){
    cout << "Clase: " << this->getId() << " destruida" << endl;
};