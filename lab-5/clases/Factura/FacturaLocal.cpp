#include "FacturaLocal.h"

FacturaLocal::FacturaLocal(dtFacturaLocal factura) : Factura(factura.getFactura()){
    this->nombreMozo = factura.getNombreMozo();
};

string FacturaLocal::getNombreMozo(){
    return this->nombreMozo;
};

FacturaLocal::~FacturaLocal(){
    
};