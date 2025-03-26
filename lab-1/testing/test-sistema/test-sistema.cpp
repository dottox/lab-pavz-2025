#include <iostream>
#include "../../clases/sistema.h"
#include "../../clases/entrenamiento.h"

using namespace std;

int main() {
    Sistema* sistema = new Sistema();

<<<<<<< HEAD
    // Test agregarSocio
    
=======
    sistema->agregarSocio("1", "Juan");
    sistema->agregarSocio("2", "Maria");
    sistema->agregarSocio("3", "Nacho");
    sistema->agregarSocio("4", "Pedro");
    sistema->agregarSocio("5", "Jose");
    sistema->agregarSocio("6", "Josefina");
    sistema->agregarSocio("7", "Julieta");
    sistema->agregarSocio("8", "Pepe");
    sistema->agregarSocio("9", "Eduardo");
    sistema->agregarSocio("10", "Wally");

    sistema->agregarClase(DtEntrenamiento(1, "Yoga", Manana,true));
    sistema->agregarClase(DtEntrenamiento(2, "Crossfit", Tarde,false));
    sistema->agregarClase(DtEntrenamiento(3, "Pilates", Noche,true));
    sistema->agregarClase(DtSpinning(4, "Spinning", Tarde, 10));
    sistema->agregarClase(DtSpinning(5, "Spinning", Noche, 10));


>>>>>>> 7ff3d03bdb934d8933b0b2d9a11c05d3ed84beaf
    try {
        sistema->agregarSocio("1", "Juan");
    } catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        sistema->agregarSocio("2", "Maria");
    } catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        sistema->agregarSocio("3", "Nacho");
    } catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        sistema->agregarSocio("4", "Gonzalo");
    } catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    // Test agregarClase with DtSpinning
    DtSpinning clase1 = DtSpinning(1, "Spinning", Manana, 10);
    DtEntrenamiento clase2 = DtEntrenamiento(2, "Entrenamiento", Tarde, true);
    DtEntrenamiento clase3 = DtEntrenamiento(1, "Entrenamiento", Tarde, true);
    DtEntrenamiento clase4 = DtEntrenamiento(3, "Entrenamiento", Tarde, true);
    DtSpinning clase5 = DtSpinning(4, "Spinning", Manana, 10);
    
    try{
        sistema->agregarClase(clase1);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }

    try{
        sistema->agregarClase(clase2);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }

    try{
        sistema->agregarClase(clase3);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }

    try{
        sistema->agregarClase(clase4);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }

    try{
        sistema->agregarClase(clase5);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }

    // Test agregarInscripcion

    try
    {
        sistema->agregarInscripcion("2", 1, DtFecha(1, 1, 2021));
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    try
    {
        sistema->agregarInscripcion("1", 1, DtFecha(1, 1, 2021));
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    
    
    sistema->listarClases();
    delete sistema;

    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;
}