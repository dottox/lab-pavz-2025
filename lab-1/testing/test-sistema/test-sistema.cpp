#include <iostream>
#include "../../clases/sistema.h"

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
// 4. Obtener información de socios por clase
//   - Obtener información de más socios de los que tiene la clase
//   - Obtener información de cantidad negativa de socios
//   - Obtener información de 0 socios
// 5. Obtener clase
//   - Obtener clase con ID válido
//   - Obtener clase con ID inválido



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
        cout << "TC-001 paso correctamente." << endl;
    } catch (const runtime_error& e) {
        terminate();
    }

    sistema->agregarSocio("12345670", "Juancho");


    // TC-002: Test de agregar socio sobre el máximo de socios
    try {
      sistema->agregarSocio("12312312", "Gonzalo");
      throw runtime_error("Error: Se permitio agregar un socio superando el limite máximo");
    } catch(const invalid_argument& e) {
        cout << "TC-002 paso correctamente." << endl;
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
        cout << "TC-003 paso correctamente" << endl;
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
        cout << "TC-004 paso correctamente." << endl;
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
        cout << "TC-005 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-006: Agregar una inscripción con una clase inválida
    try{
        sistema->agregarInscripcion("12345678", 1337, date);
        throw runtime_error("Error: Se permitio agregar una inscripcion con una clase invalida");
    } catch(const invalid_argument& e){
        cout << "TC-006 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-007: TODO: Añadir testeo de cupos en una clase

    // TC-008: Agregar una inscripción que ya existe
    try{
        sistema->agregarInscripcion("12345678", 1, date);
        throw runtime_error("Error: Se permitio agregar una inscripcion que ya existe");
    } catch(const invalid_argument& e){
        cout << "TC-008 paso correctamente." << endl;
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
        cout << "TC-009 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-010: Obtener información socios negativos
    try{
        int cantBelowZero = -999;
        DtSocio** tc_zero_ten = sistema->obtenerInfoSociosPorClase(1, cantBelowZero);
        throw runtime_error("Error: Se permitio saber la información de cantidad negativa de socios");
    } catch(const invalid_argument& e){
        cout << "TC-010 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-011: Obtener información de 0 socios
    try{
        int cantZero = 0;
        DtSocio** tc_zero_eleven = sistema->obtenerInfoSociosPorClase(1, cantZero);
        throw runtime_error("Error: Se permitio saber la información de 0 socios");
    } catch(const invalid_argument& e){
        cout << "TC-011 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }
        // --------------------- OBTENER CLASE -----------------------------
    
    // TC-012: Obtener clase con ID válido
    DtClase tc_zero_twelve = sistema->obtenerClase(1);
    cout << "TC-012 paso correctamente." << endl;
    
    // TC-013: Obtener clase con ID inválido
    try{
        DtClase tc_zero_thirteen = sistema->obtenerClase(1337);
        throw runtime_error("Error: Se obtuvo la clase con id Inválido");
    } catch(const invalid_argument& e){
        cout << "TC-013 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }
    // --------------------- BORRAR INSCRIPCION -----------------------------
    // TC-014: Borrar inscripción con ID inválido
    try{
        sistema->borrarInscripcion("00001111", 1);
        throw runtime_error("Error: Se permitio borrar una inscripcion con un socio invalido");
    } catch(const invalid_argument& e){
        cout << "TC-014 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-015: Borrar inscripción con clase inválida

    try{
        sistema->borrarInscripcion("12345678", 1337);
        throw runtime_error("Error: Se permitio borrar una inscripcion con una clase invalida");
    } catch(const invalid_argument& e){
        cout << "TC-015 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-016: Borrar inscripción que no existe

    try{
        
        sistema->borrarInscripcion("00000000", 1);
        throw runtime_error("Error: Se permitio borrar una inscripcion que no existe");
    } catch(const invalid_argument& e){
        cout << "TC-016 paso correctamente." << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    // TC-017: Borrar inscripción que existe

    try{
        sistema->borrarInscripcion("12345678", 1);
        cout << "TC-017 paso correctamente." << endl;
    } catch(const invalid_argument& e){
        cout << "Error: Se permitio borrar una inscripcion que existe" << endl;
    } catch (const runtime_error& e){
        terminate();
    }

    delete sistema;
    
    cout << "[/////////////////////////////- Tests Passed -/////////////////////////////////]" << endl;
}
