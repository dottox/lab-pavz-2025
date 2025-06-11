#include "Mozo.h"
Mozo::Mozo(string nombre) : Empleado(nombre){
    this->mesasAsignadas= new  OrderedDictionary();
    this->cantidadMesasAsignadas = 0;
}

int Mozo::getCantidadMesasAsignadas() const {
    return this->cantidadMesasAsignadas;
}
void Mozo::setCantidadMesasAsignadas(int cantidad) {
    if (cantidad < 0) {
        throw invalid_argument("La cantidad de mesas asignadas no puede ser negativa.");
    }
    this->cantidadMesasAsignadas = cantidad;
    return;
}

//Precondicion: Mesa existe en sistema
void Mozo::setMesaAsignada(Mesa *mesa) {    
    if (mesa == nullptr) {
        throw invalid_argument("La mesa no puede ser nula.");
    }
    if (mesa->getMozo() != nullptr && mesa->getMozo() != this) {
        throw invalid_argument("La mesa ya esta asignada a otro mozo.");
    }

    IKey *key = new Integer(mesa->getNumero());
    if (!this->mesasAsignadas->member(key)) {
        this->mesasAsignadas->add(key,mesa);
        this->setCantidadMesasAsignadas(this->getCantidadMesasAsignadas() + 1);
        mesa->setMozo(this); // Asignar el mozo a la mesa
    } else {
        delete key; // Liberar memoria del key
        throw invalid_argument("La mesa ya esta asignada a este mozo.");
    }
    cout << "Asignando mesa " << mesa->getNumero() << " al mozo " << this->getNombre() << endl;
    // if (!this->mesasAsignadas->member(mesa)) {
    //     cout << "Entre al if";
    //     this->mesasAsignadas->add(mesa);
    //     this->setCantidadMesasAsignadas(this->getCantidadMesasAsignadas() + 1);
    // } else {
    //     throw invalid_argument("La mesa ya esta asignada a este mozo.");
    // }
    return;
}


IDictionary * Mozo::getMesasAsignadas() {
    return this->mesasAsignadas;
}
ostream & operator<<(ostream &os, const Mozo &mozo) {
    os << "Mozo: " << static_cast<const Empleado&>(mozo); // Call base class operator<<
    os << ", Cantidad de Mesas Asignadas: " << mozo.getCantidadMesasAsignadas();
    return os;
}

ICollection * Mozo::getMesasAsignadasSinVentaEnCurso() {
    ICollection *mesasSinVenta = new List();
    IIterator *it = this->mesasAsignadas->getIterator();
    while (it->hasCurrent()) {
        Mesa *mesa = (Mesa*)(it->getCurrent());
        if (mesa && mesa->getVentaEnCurso() != nullptr) {
            it->next();
            continue;
        }
        mesasSinVenta->add(mesa->getMesa());
        it->next();
    }
    delete it; // Liberar memoria del iterador
    return mesasSinVenta;
}


Mozo::~Mozo(){
    // Destructor implementation
}

