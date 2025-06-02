#include "FacturaLocal.h"

FacturaLocal::FacturaLocal(DtFacturaLocal factura) : Factura(factura.getFactura()){
    this->nombreMozo = factura.getNombreMozo();
};

string FacturaLocal::getNombreMozo(){
    return this->nombreMozo;
};

FacturaLocal::~FacturaLocal(){
    
};