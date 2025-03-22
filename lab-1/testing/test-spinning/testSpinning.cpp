#include <iostream>
#include <cassert>
#include "../clases/spinning.h"

using namespace std;

int main() {
    // Test constructor por defecto
    Spinning s1;
    assert(s1.getCantBicicletas() == 0);

    // Test setter y getter
    s1.setCantBicicletas(20);
    assert(s1.getCantBicicletas() == 20);
    assert(s1.cupo() == 20);

    // Test constructor con argumento
    Spinning s2(15);
    assert(s2.getCantBicicletas() == 15);
    assert(s2.cupo() == 15);

    cout << "Todos los tests pasaron correctamente." << endl;
    return 0;
}
