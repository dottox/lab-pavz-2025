#include "./dtSpinning.h"
#include <stdexcept>
using namespace std;


DtSpinning::DtSpinning(int id, string nom, Turno turn, int cantBicicletas) : DtClase(id, nom, turn, cantBicicletas) {
  // Validar la cantidad de bicicletas
  if (cantBicicletas > MAX_BICICLETAS || cantBicicletas < MIN_BICICLETAS) {
    throw invalid_argument(ERROR_CANT_BICICLETA_INVALIDA);
  }
  this->cantBicicletas = cantBicicletas;
}

int DtSpinning::getCupo() {
  return this->cantCupos;
}

int DtSpinning::getCantBicicletas() {
  return this->cantBicicletas;
}

ostream& operator<<(ostream& os, const DtSpinning& dt) {
  os << "ID: " << dt.id << endl;
  os << "Nombre: " << dt.nombre << endl;
  os << "Turno: " << dt.turno << endl;
  os << "Cantidad de bicicletas: " << dt.cantBicicletas << endl;
  return os;
}

DtSpinning::~DtSpinning() {}
