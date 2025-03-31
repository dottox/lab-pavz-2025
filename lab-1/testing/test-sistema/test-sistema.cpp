#include <iostream>
#include "../../clases/sistema.h"
#include "../../clases/entrenamiento.h"

using namespace std;

// DOCUMENTACIÓN DEL TESTEO
// SE TESTEAN LOS SIGUIENTES REQUERIMIENTOS:
// 1. Agregar socio
//   - Agregar socio con CI de otro socio
//   - Agregar socio sobre el máximo de socios
// 2. Agregar clase
//   - Agregar clase que ya existe
//   - Agregar clase superando el máximo de clases
// 3. Agregar inscripción
//   - Agregar inscripción con un socio inválido
//   - Agregar inscripción con una clase inválida
//   # TODO: Agregar inscripcion sin más cupos en la clase
//   - Agregar inscripción que ya existe


int main() {
    Sistema* sistema = new Sistema();

    // --------------------- SOCIOS -----------------------------

    // Agregar socios bases
      sistema->agregarSocio("12345678", "Juan");
      sistema->agregarSocio("12345679", "Maria");

    // TC-001: Test de agregar socio con CI de otro socio
    try {
        sistema->agregarSocio("12345678", "Gonzalo");
        throw runtime_error("Error: Se permitio agregar un socio con la misma CI que otro");
    } catch(const invalid_argument& e) {
        cout << "TC-001 pasó correctamente." << endl;
    } catch (const runtime_error& e) {
        terminate();
    }

    sistema->agregarSocio("12345670", "Juancho");


    // TC-002: Test de agregar socio sobre el máximo de socios
    try {
      sistema->agregarSocio("12312312", "Gonzalo");
      throw runtime_error("Error: Se permitio agregar un socio superando el limite máximo");
    } catch(const invalid_argument& e) {
        cout << "TC-002 pasó correctamente." << endl;
    } catch (const runtime_error& e) {
        terminate();
    }



    // --------------------- CLASES -----------------------------


    // Crear clases bases
    DtSpinning clase1 = DtSpinning(1, "Spinning", Manana, 10);
    DtEntrenamiento clase2 = DtEntrenamiento(2, "Entrenamiento", Tarde, true);
    DtSpinning clase3 = DtSpinning(3, "Spinning", Noche, 10);
    
    // Agregar clases bases
    sistema->agregarClase(clase1);
    sistema->agregarClase(clase2);
  
    // TC-003: Test de agregar una clase que ya existe
    try{
        sistema->agregarClase(clase2);
        throw runtime_error("Error: Se permitio agregar una clase ya existente");
    } catch(const invalid_argument& e) {
        cout << "TC-003 pasó correctamente" << endl;
    } catch (const runtime_error& e) {
        terminate();
    }

    sistema->agregarClase(clase3);

    // TC-004: Test de agregar una clase superando el máximo de clases
    try{
        DtSpinning clase4 = DtSpinning(4, "Spinning", Manana, 10);
        sistema->agregarClase(clase4);
        throw runtime_error("Error: Se permitio agregar una clase superando el limite maximo");
    } catch(const invalid_argument& e) {
        cout << "TC-004 pasó correctamente." << endl;
    } catch (const runtime_error& e) {
        terminate();
    }
    

    // --------------------- INSCRIPCIONES -----------------------------

    
    // Test agregarInscripcion
    DtFecha date = DtFecha(1, 1, 2021); // Example date
    DtFecha date2 = DtFecha(15, 3, 2022); // Example date
    DtFecha date3 = DtFecha(20, 4, 2023); // Example date
    DtFecha date4 = DtFecha(10, 5, 2024); // Example date
    
    // Agregar inscripciones bases.
    sistema->agregarInscripcion("12345678", 1, date);
    sistema->agregarInscripcion("12345679", 1, date2);
    sistema->agregarInscripcion("12345670", 1, date3);

    // TC-005: Agregar una inscripción con un socio inválido
    try{
        sistema->agregarInscripcion("00001111", 1, date4);
        throw runtime_error("Error: Se permitio agregar una inscripcion con un socio invalido");
    } catch(const invalid_argument& e){
        cout << "TC-005 pasó correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-006: Agregar una inscripción con una clase inválida
    try{
        sistema->agregarInscripcion("12345678", 1337, date);
        throw runtime_error("Error: Se permitio agregar una inscripcion con una clase invalida");
    } catch(const invalid_argument& e){
        cout << "TC-006 pasó correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-007: TODO: Añadir testeo de cupos en una clase

    // TC-008: Agregar una inscripción que ya existe
    try{
        sistema->agregarInscripcion("12345678", 1, date);
        throw runtime_error("Error: Se permitio agregar una inscripcion que ya existe");
    } catch(const invalid_argument& e){
        cout << "TC-008 pasó correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }
    
    // --------------------- OBTENER INFO SOCIOS POR CLASE -----------------------------

    
    int cantidad = 2;
    DtSocio** oISPC_test = sistema->obtenerInfoSociosPorClase(1, cantidad);
    delete[] oISPC_test;
    
    
    // TC-009: Obtener información de más socios de los que tiene la clase
    try{
        int cantOverMax = 999;
        DtSocio** tc_zero_zero_nine = sistema->obtenerInfoSociosPorClase(1, cantOverMax);
        throw runtime_error("Error: Se permitio saber la información de más socios de los que tiene la clase");
    } catch(const invalid_argument& e){
        cout << "TC-009 pasó correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }
        // --------------------- OBTENER CLASE -----------------------------
    try
    {
        sistema->obtenerClase(1);
    }
    catch(invalid_argument e)
    {
        cout << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    delete sistema;
    
    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;
}
