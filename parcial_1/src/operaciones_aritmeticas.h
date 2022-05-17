/*
 * operaciones_aritmeticas.h
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */

#ifndef OPERACIONES_ARITMETICAS_H_
#define OPERACIONES_ARITMETICAS_H_

/// @brief recibe dos numeros flotante y devuelve el resultado
///
/// @param num1 -> operando a sumar
/// @param num2 -> operando a sumar
/// @return suma de numero flotantes
float sumarNumeroFlotante(float num1, float num2);


/// @brief resta dos numeros flotantes, valida y verifica. Devuelve el resultado
///
/// @param num1 -> operando a restar
/// @param num2 -> operando a restar
/// @param pResultado -> puntero al resultado, alli se pondra el resultado
/// @return devuelve (0) en caso de exito y (-1) en caso de error
int restarNumeroFlotante(float num1, float num2, float * pResultado);


/// @brief Calcula el promedio de enteros basado en si son positivos, negativos o acepta ambos
///
/// @param arr -> Array de enteros
/// @param promedio -> puntero al resultado obtenido
/// @param len -> longitud del array
/// @param tipoPromedio -> (+) calcula promedio positivos, (-) calcula promedio negativo, (=) calcula promedio ambos
/// @return En caso de exito (0), en caso de error (-1)
int promedioDeEnteros(int arr[], int * promedio, int len, char tipoPromedio);
#endif /* OPERACIONES_ARITMETICAS_H_ */
