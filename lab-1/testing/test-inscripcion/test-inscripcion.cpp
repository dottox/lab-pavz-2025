#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/Inscripcion.h"
#
using namespace std;
/*
    private:
        DtFecha fecha;
    public:
        Inscripcion(DtFecha);
        DtFecha getFecha();
        ~Inscripcion();
    */

int main()
{
    cout << "Test Inscripcion" << endl;
    //---------------------------TEST FECHA BVA------------------------------------------

    // CASO FECHA INVaLIDA

    // Crear una fecha invalida
    //   - Si permite crear la fecha -> Tirar un throw para que no se siga ejecutandose el programa (Test fallado)
    //   - Si no permite crear la fecha -> Seguir con la ejecucion del programa (Test funcional)

    try
    { // TEST INVERSO (invalido)
        DtFecha fecha = DtFecha(0, 0, 0);

        // No deberia llegar aca si el programa funciona correctamente
        throw runtime_error("Error: Se permitio una fecha invalida (TC001)");
    }
    catch (invalid_argument &e)
    { // Camino invalid argument, la fecha no se creo (deseado)
        cout << "Test fecha invalida TC001 paso correctamente" << endl;
    }
    catch (runtime_error &e)
    { // Camino runtime error, la fecha se creo (no deseado)
        terminate();
    }

    // Caso fecha valida
    try
    {
        DtFecha fecha = DtFecha(1, 5, 1925);
        assert(fecha.getDia() == 1);
        cout << "TC002: Dia valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC002" << endl;
    }
    // Caso fecha valida
    try
    {
        DtFecha fecha = DtFecha(31, 1, 1900);
        assert(fecha.getDia() == 31);
        cout << "TC003: Dia valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC003" << endl;
    }
    // Caso fecha Invalida
    try
    {
        DtFecha fecha = DtFecha(32, 1, 1900);
        throw runtime_error("Error: Se permitio una fecha invalida (TC001)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC004 paso correctamente" << endl;
    }
    catch (...)
    {
        terminate();
    }

    // Caso fecha invaldia
    try
    {
        DtFecha fecha = DtFecha(1, 0, 1900);
        assert(fecha.getMes() == 0);
        throw runtime_error("Error: Se permitio una fecha invalida (TC005)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC005 paso correctamente" << endl;
    }
    catch (...)
    {
        terminate();
    }

    // Caso fecha valida
    try
    {
        DtFecha fecha = DtFecha(1, 1, 1900);
        assert(fecha.getMes() == 1);
        cout << "TC006: Mes valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC006" << endl;
    }

    // Caso fecha valida
    try
    {
        DtFecha fecha = DtFecha(1, 12, 1900);
        assert(fecha.getMes() == 12);
        cout << "TC007: Mes valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC007" << endl;
    }

    // Caso fecha invalida
    try
    {
        DtFecha fecha = DtFecha(1, 13, 1900);
        throw runtime_error("Error: Se permitio una fecha invalida (TC008)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC008 paso correctamente" << endl;
    }
    catch (...)
    {
        terminate();
    }

    try
    {
        DtFecha fecha = DtFecha(1, 1, 1899);

        throw runtime_error("Error: Se permitio una fecha invalida (TC009)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC004 paso correctamente" << endl;
    }
    catch (...)
    {
        terminate();
    }

    try
    {
        DtFecha fecha = DtFecha(1, 1, 1900);
        assert(fecha.getAnio() == 1900);
        cout << "TC010: Anio valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC010" << endl;
    }

    try
    {
        DtFecha fecha = DtFecha(1, 1, 1901);
        assert(fecha.getAnio() == 1901);
        cout << "TC011: Anio valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC011" << endl;
    }

    try
    {
        DtFecha fecha = DtFecha(1, 1, 2025);
        assert(fecha.getAnio() == 2025);
        cout << "TC012: Anio valido aprobado" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC012" << endl;
    }
    //---------------------------TEST INSCRIPCION------------------------------------------
    try
    {
        DtFecha fecha = DtFecha(5, 7, 2022);
        Inscripcion inscripcion = Inscripcion(fecha);
        assert(inscripcion.getFecha().getDia() == 5);
        assert(inscripcion.getFecha().getMes() == 7);
        assert(inscripcion.getFecha().getAnio() == 2022);

        assert(inscripcion.getFecha().getDia() != 3);
        assert(inscripcion.getFecha().getMes() != 8);
        assert(inscripcion.getFecha().getAnio() != 2023);
        cout << "TC013: Inscripcion creada correctamente" << endl;
    }
    catch (...)
    {
        cout << "Error inesperado en TC013" << endl;
    }
    

    return 0;
}