#include <iostream>
#include "socio.h"
#define MAX_SOCIOS 10

using namespace std;

class Sistema {
  private:
    int cantSocios;
    Socio** socios;

  public:
    Sistema();
    void agregarSocio(string, string);
    Socio* getSocio(string);
    ~Sistema();
};