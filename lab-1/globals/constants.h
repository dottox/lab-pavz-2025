#pragma once
//Errores de Socios
#define ERROR_LIMITE_SOCIOS "No se pueden agregar mas socios"
#define ERROR_MISMA_CI "Ya existe un socio con esa CI"
#define ERROR_NO_SOCIO_CI "No se encontro el socio con esa CI"
#define ERROR_CI_INVALIDA "CI invalida"
#define ERROR_NOMBRE_INVALIDO "Nombre invalido"
//Fin Errores de Socios

//Errores de clases
#define ERROR_NO_CLASE_ID "No se encontro la clase con ese ID"
#define ERROR_CUPOS_CERO "No hay cupo en la clase"
#define ERROR_INSCRIPCION_EXISTENTE "Ya existe una inscripcion para ese socio en esa fecha"
#define ERROR_LIMITE_CLASES "No se pueden agregar mas clases"
#define ERROR_CLASE_EXISTENTE_ID "Ya existe una clase con ese ID"
//Fin Errores de clases

//Errores de inscripciones
#define ERROR_CONSTRUCTOR_VACIO "Constructor vacio no permitido\n"
#define ERROR_TURNO_INVALIDO "Turno invalido\n"
#define ERROR_FECHA_INVALIDA "Fecha invalida\n"
#define ERROR_CANT_BICICLETA_INVALIDA "Cantidad de bicicletas invalida (1-50)\n"
//Fin Errores de inscripciones

//Constantes de fecha
#define MIN_DIAS 1
#define MAX_DIAS 31
#define MIN_MESES 1
#define MAX_MESES 12
#define MIN_ANIO 1900
//Fin constantes de fecha

//Constantes de clases
#define MAX_INSCRIPCIONES 100
#define DEFAULT_INSCRIPCIONES 0
//Fin constantes de clases

//Constantes de sistema
#define MAX_SOCIOS 3
#define MAX_CLASES 3
#define DEFAULT_SOCIOS 0
#define DEFAULT_CLASES 0
//Fin constantes de sistema