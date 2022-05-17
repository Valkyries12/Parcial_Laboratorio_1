/*
 * operaciones_aritmeticas.c
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */

#include <stdlib.h>
#include <stdio.h>
#include "operaciones_aritmeticas.h"

#define TRUE 1
#define FALSE 0


float sumarNumeroFlotante(float num1, float num2) {
	float resultado;
	resultado = num1 + num2;

	return resultado;
}


int restarNumeroFlotante(float num1, float num2, float * pResultado) {
	int codigoError;
	float auxResultado;
	float resultado;

	if (pResultado != NULL && num1 > 0 && num2 > 0) {
		if (num1 > num2) {
			resultado = num1 - num2;
			auxResultado = resultado;
		} else {
			resultado = num2 - num1;
			auxResultado = resultado;
		}

		* pResultado = auxResultado;
		codigoError = 0;
	}

	codigoError =-1;


	return codigoError;
}


int promedioDeEnteros(int arr[], int * promedio, int len, char tipoPromedio) {
	int codigoError;
	int resultado;
	int contador;

	resultado = 0;
	contador = 0;

	codigoError = -1;
	if (arr != NULL && len > 0 && promedio != NULL ) {
		for(int i = 0; i < len; i++) {
			switch (tipoPromedio) {
				case '+':
					if (arr[i] > 0) {
						contador++;
						resultado += arr[i];
					}
					break;
				case '-':
					if (arr[i] < 0) {
						contador++;
						resultado += arr[i];
					}
					break;
				case '=':
					contador++;
					resultado += arr[i];
					break;
				default:
					puts("\nTipo operador inválido, solo + - =");
					break;
			}


		}
		if (contador > 0) {
			resultado = resultado / contador;
			* promedio = resultado;
			codigoError = 0;
		}
	}


	return codigoError;
}






