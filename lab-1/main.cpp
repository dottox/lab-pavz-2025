#include <iostream>

using namespace std;

class Sistema {
  private:
    /*
    - Lista de clases
    - Lista de socios
    - 
    */

  public:
    Sistema() {
      cout << "Sistema creado" << endl;
    }

    ~Sistema() {
      cout << "Sistema destruído" << endl;
    }
};

int main() {
  return 0;
}