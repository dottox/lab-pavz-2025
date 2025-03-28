#include <iostream>
#include "../clases/inscripcion.h"
#include "../clases/entrenamiento.h"
#include "../clases/socio.h"
#include "../clases/spinning.h"
#include "../dataStructures/dtFecha.cpp"
#include "../dataStructures/dtEntrenamiento.cpp"
#include "../dataStructures/dtSocio.cpp"

#include <stdexcept>

using namespace std;

class Sistema
{
private:
    Clase **clases;
    int cantClases;

    Socio **socios;
    int cantSocios;

public:
    Sistema();
    Socio *getSocio(string ci);
    Clase *getClase(int id);
    Inscripcion *getInscripcion(string ciSocio, int idClase, DtFecha fecha);

    void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha);
    void agregarClase(DtEntrenamiento dtEntrenamiento);
    void agregarClase(DtSpinning dtSpinning);
    void agregarSocio(DtSocio dtSocio);

    ~Sistema();
};

Sistema::Sistema()
{
    clases = new Clase *[100];
    cantClases = 0;

    socios = new Socio *[100];
    cantSocios = 0;
}

Socio *Sistema::getSocio(string ci)
{
    for (int i = 0; i < cantSocios; i++)
    {
        if (socios[i]->getCI() == ci)
        {
            return socios[i];
        }
    }
    return nullptr;
}

Clase *Sistema::getClase(int id)
{
    for (int i = 0; i < this->cantClases; i++)
    {
        if (this->clases[i]->getId() == id)
        {
            return this->clases[i];
        }
    }
    return nullptr;
}

Inscripcion *Sistema::getInscripcion(string ciSocio, int idClase, DtFecha fecha)
{
    for (int i = 0; i < this->cantClases; i++)
    {
        if (this->clases[i]->getId() == idClase)
        { // Encuentra la clase con el idClase
            for (int j = 0; j < this->clases[i]->getCantInscripciones(); j++)
            { // Recorre las inscripciones de la clase
                Inscripcion *inscripcion = this->clases[i]->getInscripciones()[j];
                if (inscripcion->getSocio()->getCI() == ciSocio && inscripcion->getFecha() == fecha)
                { // Encuentra la inscripcion con el socio y la fecha
                    return inscripcion;
                }
            }
        }
    }
    return nullptr;
}

void Sistema::agregarInscripcion(string ciSocio, int idClase, DtFecha fecha)
{

    // Check: socio existe
    Socio *socio = getSocio(ciSocio);
    if (socio == nullptr)
    {
        throw invalid_argument("No se encontró el socio.");
    }

    // Check: clase existe
    Clase *clase = getClase(idClase);
    if (clase == nullptr)
    {
        throw invalid_argument("No se encontró la clase.");
    }

    // Check: clase tiene cupo
    if (clase->cupo() == 0)
    {
        throw invalid_argument("La clase ingresada no tiene cupo.");
    }

    // Check: inscripcion no existe
    if (this->getInscripcion(ciSocio, idClase, fecha) != nullptr)
    {
        throw invalid_argument("Ya existe una inscripción para el socio en la clase en la fecha ingresada.");
    }

    Inscripcion *inscripcion = new Inscripcion(fecha, socio);

    clase->agregarInscripcion(inscripcion);
}

void Sistema::agregarClase(DtEntrenamiento entrenamiento)
{
    Clase *clase = new Entrenamiento(entrenamiento);
    this->clases[cantClases] = clase;
    cantClases++;
}

void Sistema::agregarClase(DtSpinning spinning)
{
    Clase *clase = new Spinning(spinning);
    this->clases[cantClases] = clase;
    cantClases++;
}

Sistema::~Sistema()
{
    delete[] clases;
    delete[] socios;
}

int main()
{
    cout << "asd" << endl;
    Sistema *sistema = new Sistema();
    sistema->agregarSocio(DtSocio("123", "Juan"));
    sistema->agregarClase(DtEntrenamiento(1, "Entrenamiento 1", Manana, true));
    sistema->agregarInscripcion("123", 1, DtFecha(1, 1, 2021));

    return 0;
}