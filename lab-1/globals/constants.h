#pragma once
//Errores de Socios
#define ERROR_LIMITE_SOCIOS "No se pueden agregar mas socios"
#define ERROR_MISMA_CI "Ya existe un socio con esa CI"
#define ERROR_NO_SOCIO_CI "No se encontro el socio con esa CI"
#define ERROR_CI_INVALIDA "CI invalida"
#define ERROR_NOMBRE_INVALIDO "Nombre invalido"
#define ERROR_SOCIO_EXISTENTE "Ya existe un socio con esa CI"
//Fin Errores de Socios

//Errores de clases
#define ERROR_NO_CLASE_ID "No se encontro la clase con ese ID"
#define ERROR_CUPOS_CERO "No hay cupo en la clase"
#define ERROR_INSCRIPCION_EXISTENTE "Ya existe una inscripcion para ese socio en esa fecha"
#define ERROR_LIMITE_INSCRIPCIONES "No se pueden agregar mas inscripciones"
#define ERROR_LIMITE_CLASES "No se pueden agregar mas clases"
#define ERROR_CLASE_EXISTENTE_ID "Ya existe una clase con ese ID"
//Fin Errores de clases

//Errores de inscripciones
#define ERROR_CONSTRUCTOR_VACIO "Constructor vacio no permitido"
#define ERROR_TURNO_INVALIDO "Turno invalido"
#define ERROR_FECHA_INVALIDA "Fecha invalida"
#define ERROR_CANT_BICICLETA_INVALIDA "Cantidad de bicicletas invalida (1-50)"
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
#define CUPOS_RAMBLA 20
#define CUPOS_NO_RAMBLA 10
#define MIN_BICICLETAS 1
#define MAX_BICICLETAS 50
//Fin constantes de clases

//Constantes de sistema
#define MAX_SOCIOS 3
#define MAX_CLASES 3
#define DEFAULT_SOCIOS 0
#define DEFAULT_CLASES 0
//Fin constantes de sistema

//Errores de sistema
#define ERROR_NO_INSCRIPCIONES "No hay socios inscriptos en esta clase"
#define ERROR_NO_SIOCIOS "No hay suficientes socios en la clase"
//Fin de errores de sistema