#include <iostream>
#include "../../clases/sistema.h"
#include "../../clases/entrenamiento.h"

using namespace std;

int main() {
    Sistema* sistema = new Sistema();

    // Test agregarSocio

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

    // Test agregarClase with DtSpinning and DtEntrenamiento

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
    DtFecha date = DtFecha(1, 1, 2021); // Example date
    DtFecha date2 = DtFecha(15, 3, 2022); // Example date
    DtFecha date3 = DtFecha(20, 4, 2023); // Example date
    DtFecha date4 = DtFecha(10, 5, 2024); // Example date
    
    try{
        sistema->agregarInscripcion("2", 1, date);
        sistema->agregarInscripcion("1", 1, date2);
        sistema->agregarInscripcion("3", 1, date3);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    
    try{
        sistema->agregarInscripcion("3", 2, date2);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    
    try{
        sistema->agregarInscripcion("4", 1, date);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    
    try{
        sistema->agregarInscripcion("1", 4, date2);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    
    try{
        sistema->agregarInscripcion("4", 2, date2);
    }catch(const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    
    delete sistema;
    
    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;
}