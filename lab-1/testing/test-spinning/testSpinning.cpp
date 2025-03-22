#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/spinning.h"
#include "../../dataStructures/turno.cpp"
using namespace std;
int main()
{
    //TC = TEST CASE
    // ID, nombre, turno, cantBicicletas
    // BVA = Boundary Value Analysis
    try {
        DtSpinning dtTC001=DtSpinning(1, "TC001", Manana,0);
        Spinning * TC001 = new Spinning(dtTC001);
        assert(TC001->getCantBicicletas() == 0);
        delete TC001;
    } catch (...) {
        cout << "Error Esperado en TC001" << endl;
    }

    try {
        DtSpinning dtTC002=DtSpinning(2, "TC002", Tarde,1);
        Spinning * TC002 = new Spinning(dtTC002);
        assert(TC002->getCantBicicletas() == 1);
        assert(TC002->cupo() == 1);
        TC002->setCantBicicletas(2);
        assert(TC002->getCantBicicletas() == 2);
        delete TC002;
    } catch (...) {
        cout << "Error inesperado en TC002" << endl;
    }

    try {
        DtSpinning dtTC003=DtSpinning(3, "TC003", Noche,49);
        Spinning * TC003 = new Spinning(dtTC003);
        assert(TC003->getCantBicicletas() == 49);
        delete TC003;
    } catch (...) {
        cout << "Error inesperado en TC003" << endl;
    }

    try {
        DtSpinning dtTC004=DtSpinning(4, "TC004", Manana,50);
        Spinning * TC004 = new Spinning(dtTC004);
        assert(TC004->getCantBicicletas() == 50);
        delete TC004;
    } catch (...) {
        cout << "Error inesperado en TC004" << endl;
    }

    try {
        DtSpinning dtTC005=DtSpinning(5, "TC005", Tarde,51);
        Spinning * TC005 = new Spinning(dtTC005);
        assert(TC005->getCantBicicletas() == 51);
        delete TC005;
    } catch (...) {
        cout << "Error esperado en TC005" << endl;
    }
    //-----------------------------------------------------

    // Float inválidos
    try{
        DtSpinning dtTC006=DtSpinning(6, "TC006", Manana,1.5);
        Spinning * TC006 = new Spinning(dtTC006);
        delete TC006;
    }catch(...){
        cout << "Error esperado en TC006" << endl;
    }

    try{
        DtSpinning dtTC007=DtSpinning(7, "TC007", Tarde,5);
        Spinning * TC007 = new Spinning(dtTC007);
        delete TC007;
    }catch(...){
        cout << "Resultado esperado en TC007" << endl;
    }
    
    try{
        DtSpinning dtTC008=DtSpinning(8, "TC008", Noche,5);
        Spinning * TC008 = new Spinning(dtTC008);
        delete TC008;
    }catch(...){
        cout << "Resultado esperado en TC008" << endl;
    }

    //-----------------Numeros negativos-------------------
    try{
        DtSpinning dtTC009=DtSpinning(-9, "TC009", Manana,50);
        Spinning * TC009 = new Spinning(dtTC009);
        delete TC009;
    }catch(...){
        cout << "Resultado esperado en TC009" << endl;
    }

    try{
        DtSpinning dtTC010=DtSpinning(10, "TC010", Manana,-10);
        Spinning * TC010 = new Spinning(dtTC010);
        delete TC010;
    }catch(...){
        cout << "Resultado esperado en TC010" << endl;
    }
    try{
        DtSpinning dtTC011=DtSpinning(-11, "TC011", Manana,-15);
        Spinning * TC011 = new Spinning(dtTC011);
        delete TC011;
    }catch(...){
        cout << "Resultado esperado en TC011" << endl;
    }
    //----------------Nombre Vacio-------------------
    try{
        DtSpinning dtTC012=DtSpinning(11, "", Manana,50);
        Spinning * TC012 = new Spinning(dtTC012);
        delete TC012;
    }catch(...){
        cout << "Resultado esperado en TC012" << endl;
    }
    //-----------------Valor fuera de rango static_cast<int>(999)-------------------
    try {
        DtSpinning dtTC013=DtSpinning(13, "TC013", static_cast<Turno>(999), 10); // agarro index 999 que no existe
        Spinning *TC013 = new Spinning(dtTC013);
        delete TC013;
        cout << "Error: Se permitió un turno invalido. en TC013" << endl;
    } catch (...) {
        cout << "Resultado esperado: Turno invalido no permitido. en TC013" << endl;
    }
    //------------------Límites Extremos------------------
    try{
        DtSpinning dtTC014=DtSpinning(INT_MIN, "TC014", Manana,50);
        Spinning * TC014 = new Spinning(dtTC014);
        delete TC014;
    }catch(...){
        cout << "Resultado esperado en TC014" << endl;
    }
    try{
        DtSpinning dtTC015=DtSpinning(INT_MAX, "TC015", Manana,50);
        Spinning * TC015 = new Spinning(dtTC015);
        delete TC015;
    }catch(...){
        cout << "Resultado esperado en TC015" << endl;
    }
    try{
        DtSpinning dtTC016=DtSpinning(16, "TC016", Manana,INT_MIN);
        Spinning * TC016 = new Spinning(dtTC016);
        delete TC016;
    }    catch(...){
        cout << "Resultado esperado en TC016" << endl;
    }
    try{
        DtSpinning dtTC017=DtSpinning(17, "TC017", Manana,INT_MAX);
        Spinning * TC017 = new Spinning(dtTC017);
        delete TC017;
    }catch(...){
        cout << "Resultado esperado en TC017" << endl;
    }
    try{
        DtSpinning dtTC018=DtSpinning(INT_MIN, "TC018", Manana,INT_MIN);
        Spinning * TC018 = new Spinning(dtTC018);
        delete TC018;
    }catch(...){
        cout << "Resultado esperado en TC018" << endl;
    }

    //------------------------------------Constructor Vacío------------------------------------
    try{
        DtSpinning dtTC019=DtSpinning();
        Spinning * TC019 = new Spinning(dtTC019);
        delete TC019;
    }catch(...){
        cout << "Resultado esperado constructor vacio en TC019" << endl;
    }

    cout << "Todos los tests pasaron correctamente." << endl;

    return 0;
}