
#include "clase.h"

Clase::Clase(DtClase claseData)
{
    this->id = claseData.getId();
    this->nombre = claseData.getNombre();
    this->turno = claseData.getTurno();
    this->cantCupo = claseData.getCupo();
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
    if(this->cupo() == 0) throw invalid_argument(ERROR_CUPOS_CERO);
    if(this->cantInscripciones >= MAX_INSCRIPCIONES) throw invalid_argument(ERROR_LIMITE_INSCRIPCIONES);

    this->inscripciones[this->cantInscripciones++] = inscripcion;
    this->cantCupo--;
};


/**
 * @brief Returns the inscriptions of the class.
 * 
 * @return An array of Inscripcion objects representing the inscriptions of the class.
 */
Inscripcion** Clase::getInscripciones(){
    return this->inscripciones;
};


Inscripcion* Clase::getInscripcion(string ci, DtFecha fecha){
    for (int i = 0; i < this->cantInscripciones; i++){
        if (this->inscripciones[i]->getSocio()->getCI() == ci && this->inscripciones[i]->getFecha() == fecha){
            return this->inscripciones[i];
        }
    }
    return nullptr;
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
 * @brief Sets the name of the class.
 * 
 * @param nombre The new name of the class.
 */
void Clase::setNombre(string nombre){
  this->nombre = nombre;
};

/**
 * @brief Sets the turn of the class.
 * 
 * @param turno The new turn of the class.
 */
void Clase::setTurno(Turno turno){
  // Validar el turno
  if (turno > Noche || turno < Manana) {
    throw invalid_argument(ERROR_TURNO_INVALIDO);
  }
  this->turno = turno;
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
