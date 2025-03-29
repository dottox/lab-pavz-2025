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

    Inscripcion *inscripcion = clase->getInscripcion(ciSocio, fecha);

    // Check: inscripcion existe
    if (inscripcion == nullptr)
    {
        throw invalid_argument("No se encontró la inscripción.");
    }

    return inscripcion;
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

    clase->agregarInscripcion(socio,fecha);
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

void Sistema::agregarSocio(DtSocio socioData){
    if(this->cantSocios >= MAX_SOCIOS){
      throw invalid_argument(ERROR_LIMITE_SOCIOS);
    }
    if(getSocio(socioData.getCi()) != nullptr){
      throw invalid_argument(ERROR_SOCIO_EXISTENTE);
    }
    this->socios[cantSocios] = new Socio(socioData);
    this->cantSocios++;

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