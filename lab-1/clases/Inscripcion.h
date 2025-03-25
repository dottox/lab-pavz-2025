#pragma once
#include <iostream>
using namespace std;

#include "../dataStructures/dtFecha.h"
#include "../clases/socio.h"

/**
 * @class Inscripcion
 * @brief Represents an inscription with an associated date.
 *
 * The Inscripcion class encapsulates the details of an inscription,
 * including the date of the inscription. It provides methods to
 * retrieve the date and manage the lifecycle of the object.
 */
class Inscripcion{
    private:
        DtFecha fecha;
        Socio* socio;
    public:
        Inscripcion(DtFecha, Socio*);
        DtFecha getFecha();
        Socio* getSocio();
        ~Inscripcion();
};
