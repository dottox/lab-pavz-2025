
#include "utils.h"

int utils::generarNumeroEmpleado()
{
    static int contadorEmpleado = 0; // Variable estatica para mantener el estado entre llamadas
    contadorEmpleado++;
    return contadorEmpleado;
}

int utils::generarNumeroFactura()
{
    static int contadorFactura = 0; // Variable estatica para mantener el estado entre llamadas
    contadorFactura++;
    return contadorFactura;
}

int utils::generarNumeroMesa()
{
    static int contadorMesa = 0; // Variable estatica para mantener el estado entre llamadas
    contadorMesa++;
    return contadorMesa;
}

int utils::generarNumeroVenta()
{
    static int contadorVenta = 0; // Variable estatica para mantener el estado entre llamadas
    contadorVenta++;
    return contadorVenta;
}

DtFecha utils::obtenerFechaActual()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm *time_info = localtime(&now_time);

    // Extraer valores por separado
    int anio = time_info->tm_year + 1900; // tm_year: años desde 1900
    int mes = time_info->tm_mon + 1;      // tm_mon: meses desde enero (0-11)
    int dia = time_info->tm_mday;

    return DtFecha(dia, mes, anio);
}

DtHora utils::obtenerHoraActual()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm *time_info = localtime(&now_time);

    // Extraer valores por separado
    int hora = time_info->tm_hour;
    int minutos = time_info->tm_min;
    int segundos = time_info->tm_sec;

    return DtHora(hora, minutos, segundos);
}
