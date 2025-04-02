#include <iostream>
#include <cassert>
#include <limits.h>
#include "../../clases/inscripcion.h"
#include "../../clases/socio.h"

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
    DtFecha fecha02 = DtFecha(31, 1, 1900);
    assert(fecha02.getDia() == 31);
    assert(fecha02.getMes() == 1);
    assert(fecha02.getAnio() == 1900);

    // Caso día Invalida
    try
    {
        DtFecha fecha03 = DtFecha(32, 1, 1900);
        throw runtime_error("Error: Se permitio una fecha invalida (TC003)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC003 paso correctamente" << endl;
    }
    catch (runtime_error &e)
    {
        terminate();
    }

    // Caso mes invaldia
    try
    {
        DtFecha fecha04 = DtFecha(1, 0, 1900);
        throw runtime_error("Error: Se permitio una fecha invalida (TC004)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC004 paso correctamente" << endl;
    }
    catch (runtime_error &e)
    {
        terminate();
    }

    // Caso año invalido
    try
    {
        DtFecha fecha05 = DtFecha(1, 1, 1899);
        throw runtime_error("Error: Se permitio una fecha invalida (TC005)");
    }
    catch (invalid_argument &e)
    {
        cout << "Test fecha invalida TC005 paso correctamente" << endl;
    }
    catch (runtime_error &e)
    {
        terminate();
    }

    DtFecha fecha06 = DtFecha(1, 1, 1900);
    assert(fecha06.getAnio() == 1900);
    cout << "TC010: Anio valido aprobado" << endl;


    DtFecha fecha07 = DtFecha(1, 1, 1901);
    assert(fecha07.getAnio() == 1901);
    cout << "TC011: Anio valido aprobadocs" << endl;

    DtFecha fecha08 = DtFecha(1, 1, 2025);
    assert(fecha08.getAnio() == 2025);
    cout << "TC012: Anio valido aprobado" << endl;
    //---------------------------TEST INSCRIPCION------------------------------------------

    DtFecha fechaValida = DtFecha(5, 7, 2022);
    Socio* socio = new Socio(DtSocio("12312323", "Juan"));
    Inscripcion inscripcion = Inscripcion(fechaValida, socio);
    assert(inscripcion.getFecha().getDia() == 5);
    assert(inscripcion.getFecha().getMes() == 7);
    assert(inscripcion.getFecha().getAnio() == 2022);

    assert(inscripcion.getFecha().getDia() != 3);
    assert(inscripcion.getFecha().getMes() != 8);
    assert(inscripcion.getFecha().getAnio() != 2023);

    delete socio;
    cout << "TC013: Inscripcion creada correctamente" << endl;
    

    return 0;
}