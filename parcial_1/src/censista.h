/*
 * censista.h
 *
 *  Created on: 16 may 2022
 *      Author: Nicolás Caruso
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "fechaNacimiento.h"
#include "Direccion.h"
#define TRUE 1
#define FALSE 0

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	FechaNacimiento fechaNacimiento;
	int edad;
	int estadoCensista; //ACTIVO, INACTIVO, LIBERADO
	Direccion direccion;
	int idZona;
	int isEmpty;
}Censista;



/// @brief  Inicializa cada censista del array. Setea isEmpty en TRUE
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int inicializarCensistas(Censista arr[], int len);


/// @brief Busca el indice del primer censista encontrado que tenga la propiedad isEmpty en TRUE
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @return retorna el indice del asociado en caso de encontrarlo. Si no (-1)
int buscarEspacioLibreCensista(Censista arr[], int len);


/// @brief Busca el indice del censista mediante un id
///
/// @param arr -> array de censistas
/// @param id -> id del censista
/// @param len -> longitud del array
/// @return -> En caso de encontrarlo devuelve el indice, en caso de no encontrarlo (-1)
int buscarCensistaPorId(Censista arr[], int id, int len);


/// @brief Devuelve el indice del censista con la zona mas censada
///
/// @param arr -> array de censistas
/// @param idZona -> id de la zona mas censada
/// @param len -> longitud del array
int buscarCensistaConZonaMasCensada(Censista arr[], int idZona, int len);


/// @brief Carga un censista al array en el primer indice disponible
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @param id -> id autoincremental
/// @param nombre -> nombre del censista
/// @param apellido -> apellido del censista
/// @param dia -> dia de nacimineto del censista
/// @param mes -> mes del anio de nacimiento del censista 0 a 11
/// @param anio -> año de nacimiento del censista
/// @param edad -> edad del censista
/// @param nombreCalle -> nombre de la calle del censista
/// @param numeroCalle -> numero del domicilio del censista
/// @return En caso de exito (0), en caso de error (-1)
int agregarCensista(Censista arr[], int len, int id, char * nombre, char * apellido, int dia, int mes, int anio, int edad, char * nombreCalle, int numeroCalle);


/// @brief Elimina un censista del array
///
/// @param arr -> array de censistas
/// @param id -> id del censista a eliminar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int eliminarCensista(Censista arr[], int id, int len);


///// @brief Modifica nombre o apellido o precio o tipoPasajero o codigoVuelo del pasajero
/////
///// @param arr -> array de pasajeros
///// @param id ->id del pasajero a modificar
///// @param opcionMenu -> opcion a modificar
///// @param len -> longitud del array
///// @return En caso de exito (0), en caso de error (-1)
//int modificarPasajero(Pasajero arr[], int id, int opcionMenu, int len);


/// @brief Verifica si al menos hay 1 censista
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @return En caso de haber al menos un censista TRUE (1), sino FALSE (0)
int hayCensistaCargado(Censista arr[], int len);


/// @brief Verifica si hay al menos 1 censista con zona asignada
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @return En caso de haber al menos un censista con zona asignada TRUE (1), sino FALSE (0)
int hayCensistaAsignado(Censista arr[], int len);


/// @brief Verifica si existe o no el censista en base al id proporcionado
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @param id -> id del censista a verificar su existencia
/// @return En caso de existir devuelve TRUE (1), en caso contraro FALSE (0)
int existeCensista(Censista arr[], int len, int id);


/// @brief Incrementa el id por un, lo hace autoincremental
///
int incrementarCensistaId(void);


/// @brief Imprime los datos del censista dado
///
/// @param pasajero -> struct con los datos del censista
void imprimirCensista(Censista censista);


/// @brief Imprime todos los censistas
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
void imprimirCensistas(Censista arr[], int len);


///// @brief Imprime todos los pasajeros
/////
///// @param arr -> array de pasajeros
///// @param estado -> 0 ACTIVO, 1 DEMORADO, 2 CANCELADO
///// @param len -> longitud del array
//void imprimirPasajerosPorEstado(Pasajero arr[], int len, int estado);


/// @brief Ordena los censistas por apellido y nombre
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @param orden -> 1 ascendente, 2 descendente
/// @return En caso de exito (0), en caso de error (-1)
int ordenarCensistas(Censista arr[], int len, int orden);



///// @brief Ordenar los pasajeros por codigo de vuelo y estado ACTIVO
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
///// @param orden -> 1 ascendente, 2 descendente
///// @return En caso de exito (0), en caso de error (-1)
//int ordenarPasajerosPorCodigo(Pasajero arr[], int len, int orden);


/// @brief Carga 15 censistas
///
/// @param arr -> array de censistas
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int hacerCargaForzadaCensista(Censista arr[], int len);


/// @brief Imprime la cabecera de la tabla de censistas
void imprimirCabeceraCensista(void);


///// @brief Calcula el total de los precios de todos los pasajeros
/////
///// @param arr -> array de pasajeros
///// @param total -> puntero del resultado calculado en la funcion
///// @param len -> longitud del array
///// @return En caso de exito (0), en caso de error (-1)
//int calcularTotalDeTodosLosPasajes(Pasajero arr[], float * total, int len);


///// @brief Calcula el promedio de los precios de todos los pasajeros
/////
///// @param arr -> array de pasajeros
///// @param promedio -> puntero donde se guardara el resultado del promedio
///// @param total -> total de todos los precios
///// @param len -> longitud del array
///// @return En caso de exito (0), en caso de error (-1)
//int calcularPromedioDePasajes(Pasajero arr[], float * promedio, float total, int len);


///// @brief Calcula cuantos pasajeros superan el precio promedio
/////
///// @param arr -> array de pasajeros
///// @param promedio -> precio promedio
///// @param cantidadSuperanPromedio -> puntero a variable donde se guardara el resultado
///// @param len -> longitud del array
///// return En caso de exito (0), en caso de error (-1)
//int calcularCuantosSuperanPromedio(Pasajero arr[], float promedio, int * cantidadSuperanPromedio, int len);


///// @brief Imprime el total de precios, su promedio y la cantidad de pasajeros que superan el promedio
/////
///// @param totalPrecios -> total de precio de todos los pasajes
///// @param promedio -> promedio de precio de los pasajes vendidos
///// @param cantidadSuperanPromedio -> cantidad de pasajeros que superan el precio promedio
//void imprimirCalculosDePasajeros(float totalPrecios, float promedio, int cantidadSuperanPromedio);
//



#endif /* CENSISTA_H_ */
