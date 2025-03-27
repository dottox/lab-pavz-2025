
#include "clase.h"

Clase::Clase(DtClase claseData)
{
    this->id = claseData.getId();
    this->nombre = claseData.getNombre();
    this->turno = claseData.getTurno();
    this->cantInscripciones = DEFAULT_INSCRIPCIONES;
    this->inscripciones = new Inscripcion*[MAX_INSCRIPCIONES];
};

int Clase::getId()
{
    return this->id;
};

string Clase::getNombre()
{
    return this->nombre;
};

Turno Clase::getTurno()
{
    return this->turno;
};


/**
 * @brief Adds an inscription to the class.
 * 
 * @param inscripcion The inscription to add to the class.
 */
void Clase::agregarInscripcion(Inscripcion* inscripcion){
    this->inscripciones[this->cantInscripciones++] = inscripcion;
};


/**
 * @brief Returns the inscriptions of the class.
 * 
 * @return An array of Inscripcion objects representing the inscriptions of the class.
 */
Inscripcion** Clase::getInscripciones(){
    return this->inscripciones;
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
    for (int i = 0; i < this->cantInscripciones; i++){
        delete this->inscripciones[i];
    }
    delete[] this->inscripciones;
};