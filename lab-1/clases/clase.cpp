
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
void Clase::agregarInscripcion(Socio* socio, DtFecha fecha){
    if(this->cupo() == 0) throw invalid_argument(ERROR_CUPOS_CERO);
    if(this->cantInscripciones >= MAX_INSCRIPCIONES) throw invalid_argument(ERROR_LIMITE_INSCRIPCIONES);

     // Check: inscripcion no existe
     if (this->getInscripcion(socio->getCI(), fecha) != nullptr)
     {
         throw invalid_argument("Ya existe una inscripción para el socio en la clase en la fecha ingresada.");
     }

    Inscripcion *inscripcion = new Inscripcion(fecha, socio);

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

Inscripcion* Clase::getInscripcion(string ci){
    for (int i = 0; i < this->cantInscripciones; i++){
        if (this->inscripciones[i]->getSocio()->getCI() == ci){
            return this->inscripciones[i];
        }
    }
    return nullptr;
};

void Clase::borrarInscripcion(string ciSocio, int idClase){
    Inscripcion* inscripcion = this->getInscripcion(ciSocio);
    if (inscripcion == nullptr) throw invalid_argument(ERROR_NO_INSCRIPCION);

    for (int i = 0; i < this->cantInscripciones; i++){
        if (this->inscripciones[i] == inscripcion){
            delete this->inscripciones[i];
            this->inscripciones[i] = this->inscripciones[this->cantInscripciones - 1];
            this->cantInscripciones--;
            break;
        }
    }
}

void Clase::listarInscripciones(){
    cout << "-----------------------------" << endl;
    cout << "Inscripciones de la clase " << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < this->cantInscripciones; i++){
        cout << "Inscripcion: " << i + 1 << ": " << this->inscripciones[i]->getSocio()->getCI() << endl;
    }
    cout << "-----------------------------" << endl;
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