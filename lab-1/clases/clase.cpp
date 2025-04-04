#include "clase.h"

/*
  * @brief Constructor for the Clase class.
  * 
  * Initializes a Clase object with the specified data.
  * 
  * @param claseData The data for the class, represented as a DtClase object.
*/
Clase::Clase(DtClase claseData)
{
    this->id = claseData.getId();
    this->nombre = claseData.getNombre();
    this->turno = claseData.getTurno();
    this->cantCupo = claseData.getCupo();
    this->cantInscripciones = DEFAULT_INSCRIPCIONES;
    this->inscripciones = new Inscripcion*[MAX_INSCRIPCIONES];
};

/**
 * @brief Returns the available spots (cupo) in the class.
 * 
 * @return The number of available spots in the class.
 */
int Clase::cupo()
{
    return this->cantCupo;
};

/**
 * @brief Returns the ID of the class.
 * 
 * @return The ID of the class as an integer.
 */
int Clase::getId()
{
    return this->id;
};

/**
 * @brief Returns the name of the class.
 * 
 * @return The name of the class as a string.
 */
string Clase::getNombre()
{
    return this->nombre;
};

/**
 * @brief Returns the turn of the class.
 * 
 * @return The turn of the class as a Turno enum value.
 */
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
    if(this->getInscripcion(inscripcion->getSocio()->getCI()) != nullptr) throw invalid_argument(ERROR_INSCRIPCION_EXISTENTE);

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


/**
 * @brief Returns the inscription of a specific socio.
 * 
 * @param ci The CI of the socio whose inscription is to be retrieved.
 * @return The Inscripcion object associated with the specified socio, or nullptr if not found.
 */
Inscripcion* Clase::getInscripcion(string ci){
    for (int i = 0; i < this->cantInscripciones; i++){
        if (this->inscripciones[i]->getSocio()->getCI() == ci){
            return this->inscripciones[i];
        }
    }
    return nullptr;
};

/**
 * @brief Deletes an inscription for a specific socio.
 * 
 * @param ciSocio The CI of the socio whose inscription is to be deleted.
 * @throws invalid_argument if the inscription is not found.
 */
void Clase::borrarInscripcion(string ciSocio){
    Inscripcion* inscripcion = this->getInscripcion(ciSocio);
    if (inscripcion == nullptr) throw invalid_argument(ERROR_NO_INSCRIPCION);

    for (int i = 0; i < this->cantInscripciones; i++){
        if (this->inscripciones[i] == inscripcion){
            delete this->inscripciones[i];
            this->inscripciones[i] = this->inscripciones[this->cantInscripciones - 1];
            this->cantInscripciones--;
            this->cantCupo++;
            this->inscripciones[this->cantInscripciones] = nullptr;
            break;
        }
    }
}

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