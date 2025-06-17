#include "DtDireccionCasa.h"

DtDireccionCasa::DtDireccionCasa(string calle, string numero, string entreCalles) : DtDireccion(calle, numero, entreCalles) {
    
};

ostream& operator<<(ostream& os, const DtDireccionCasa& dtDireccionCasa)
{
    os << static_cast<const DtDireccion&>(dtDireccionCasa) << endl;
    return os;
}

DtDireccionCasa::~DtDireccionCasa() {
    cout << "Destruyendo DtDireccionCasa" << endl;
};
