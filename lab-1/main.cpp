#include <iostream>
#include "../clases/Inscripcion.h"
#include "../clases/Entrenamiento.h"
#include "../clases/Socio.h"
#include "../dataStructures/dtFecha.cpp"
#include "../dataStructures/dtEntrenamiento.cpp"
#include "../dataStructures/dtSocio.cpp"

using namespace std;

class Sistema {
  private:
    /*
    - Lista de clases
    - Lista de socios
    - 
    */

    Clase ** clases = new Clase*[100];
    int cantClases = 0;

    Socio ** socios = new Socio*[100];
    int cantSocios = 0;

    Inscripcion ** inscripciones = new Inscripcion*[100];
    int cantInscripciones = 0;

    

  public:
    Sistema() {
      cout << "Sistema creado" << endl;
    }

    ~Sistema() {
      cout << "Sistema destruído" << endl;
    }

    void agregarInscripcion(string ciSocio, int idClase, DtFecha fecha){

        //Socio existe

        Socio * socio;

        for (int i =0;i<cantSocios;i++){
            if (socios[i]->getCI() == ciSocio){
                socio = socios[i];
                break;
            }
        }

        if (socio == NULL) __throw_invalid_argument( "No se encontró el socio.");
        //Clase existe
        Clase * clase;

        for (int i =0;i<cantClases;i++){
            if (clases[i]->getId() == idClase){
                clase = clases[i];
                break;
            }
        }

        if (socio == NULL || clase == NULL) __throw_invalid_argument( "No se encontró la clase ingresada.");

        if(clase->cupo() == 0) __throw_invalid_argument( "No hay cupo en la clase");

        //Inscripcion existe

        Inscripcion ** inscripcionesClase = clase->getInscripciones();

        for (int i =0;i<clase->getCantInscripciones();i++){
            if (inscripcionesClase[i]->getSocio()->getCI() == ciSocio && inscripcionesClase[i]->getFecha() == fecha){
                __throw_invalid_argument( "Ya existe una inscripción para ese socio en esa fecha");
            }
        }

        delete inscripcionesClase;

        Inscripcion * inscripcion = new Inscripcion(fecha,socio);

        clase->agregarInscripcion(inscripcion);

        inscripciones[cantInscripciones] = inscripcion;
        cantInscripciones++;
        
    }

    void agregarClase(DtEntrenamiento dtEntrenamiento){
        
        Entrenamiento * entrenamiento = new Entrenamiento(dtEntrenamiento);
        clases[cantClases] = entrenamiento;
        cantClases++;
    }

    void agregarSocio(DtSocio dtSocio){
        Socio * socio = new Socio(dtSocio);
        socios[cantSocios] = socio;
        cantSocios++;
    }

};

int main() {
    cout << "asd" << endl;
    Sistema * sistema = new Sistema();
    sistema->agregarSocio(DtSocio(123, "Juan"));
    sistema->agregarClase(DtEntrenamiento(1, "Entrenamiento 1", Manana, true));
    sistema->agregarInscripcion("123", 1, DtFecha(1, 1, 2021));

  return 0;
}