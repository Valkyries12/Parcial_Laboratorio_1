/*
 * zona.h
 *
 *  Created on: 16 may 2022
 *      Author: Nicolás Caruso
 */

#ifndef ZONA_H_
#define ZONA_H_

typedef struct {
	int id;
	char calles[4][51];
	int estadoZona;
	int idLocalidad;
	int isEmpty;
}Zona;



/// @brief  Inicializa cada zona del array. Setea isEmpty en TRUE
///
/// @param arr -> array de zonas
/// @param len -> longitud del array
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int inicializarZonas(Zona arr[], int len);



/// @brief Busca el indice de la primera zona encontrado que tenga la propiedad isEmpty en TRUE
///
/// @param arr -> array de zonas
/// @param len -> longitud del array
/// @return retorna el indice del asociado en caso de encontrarlo. Si no (-1)
int buscarEspacioLibreZona(Zona arr[], int len);



/// @brief Busca el indice de la zona mediante un id
///
/// @param arr -> array de zonas
/// @param id -> id de la zona
/// @param len -> longitud del array
/// @return -> En caso de encontrarlo devuelve el indice, en caso de no encontrarlo (-1)
int buscarZonaPorId(Zona arr[], int id, int len);


///// @brief Carga un pasajero al array en el primer indice disponible
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
///// @param id -> id autoincremental
///// @param nombre -> nombre del pasajero
///// @param apellido -> apellido del pasajero
///// @param precio -> precio del vuelo
///// @param tipoPasajero -> PRIMERA_CLASE (0), EJECUTIVO (1), PREMIUM (2)
///// @param codigoVuelo -> valor alfanumerico
///// @param estadoVuelo -> ACTIVO (0), DEMORADO (1), CANCELADO (2)
///// @return En caso de exito (0), en caso de error (-1)
//int agregarPasajero(Pasajero arr[], int len, int id, char * nombre, char * apellido, float precio, int tipoPasajero, char * codigoVuelo, int estadoVuelo );


/// @brief Elimina una zona del array
///
/// @param arr -> array de zonas
/// @param id -> id de la zona a eliminar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int eliminarZona(Zona arr[], int id, int len);


///// @brief Modifica nombre o apellido o precio o tipoPasajero o codigoVuelo del pasajero
/////
///// @param arr -> array de pasajeros
///// @param id ->id del pasajero a modificar
///// @param opcionMenu -> opcion a modificar
///// @param len -> longitud del array
///// @return En caso de exito (0), en caso de error (-1)
//int modificarPasajero(Pasajero arr[], int id, int opcionMenu, int len);


/// @brief Verifica si al menos hay 1 zona
///
/// @param arr -> array de zonas
/// @param len -> longitud del array
/// @return En caso de haber al menos un asociado TRUE (1), sino FALSE (0)
int hayZonaCargada(Zona arr[], int len);


/// @brief Verifica si existe o no la zona en base al id proporcionado
///
/// @param arr -> array de zonas
/// @param len -> longitud del array
/// @param id -> id de la zona a verificar su existencia
/// @return En caso de existir devuelve TRUE (1), en caso contraro FALSE (0)
int existeZona(Zona arr[], int len, int id);


/// @brief Incrementa el id por uno, lo hace autoincremental
///
int incrementarZonaId(void);

//
///// @brief Imprime los datos del pasajero dado
/////
///// @param pasajero -> struct con los datos del pasajero
//void imprimirPasajero(Pasajero pasajero);


///// @brief Imprime todos los pasajeros
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
//void imprimirPasajeros(Pasajero arr[], int len);


///// @brief Imprime todos los pasajeros
/////
///// @param arr -> array de pasajeros
///// @param estado -> 0 ACTIVO, 1 DEMORADO, 2 CANCELADO
///// @param len -> longitud del array
//void imprimirPasajerosPorEstado(Pasajero arr[], int len, int estado);


///// @brief Ordena los pasajeros por apellido y tipo de pasajero
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
///// @param orden -> 1 ascendente, 2 descendente
///// @return En caso de exito (0), en caso de error (-1)
//int ordenarPasajeros(Pasajero arr[], int len, int orden);


///// @brief Ordenar los pasajeros por codigo de vuelo y estado ACTIVO
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
///// @param orden -> 1 ascendente, 2 descendente
///// @return En caso de exito (0), en caso de error (-1)
//int ordenarPasajerosPorCodigo(Pasajero arr[], int len, int orden);


///// @brief Carga 10 usuarios
/////
///// @param arr -> array de pasajeros
///// @param len -> longitud del array
///// @return En caso de exito (0), en caso de error (-1)
//int hacerCargaForzada(Pasajero arr[], int len);


///// @brief Imprime la cabecera de la tabla de pasajeros
//void imprimirCabecera(void);


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


#endif /* ZONA_H_ */
