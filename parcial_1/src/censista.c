/*
 * censista.c
 *
 *  Created on: 16 may 2022
 *      Author: Nicol�s Caruso
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "censista.h"
#include "utn.h"
#include "direccion.h"
#include "fechaNacimiento.h"

#define TRUE 1
#define FALSE 0

char estadoCensista[][10] = {"ACTIVO", "INACTIVO", "LIBERADO"};



int inicializarCensistas(Censista arr[], int len) {
	int codigoError;

	codigoError = -1;
	if(arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			arr[i].isEmpty = 1;
		}
		codigoError = 0;
	}

	return codigoError;
}



int buscarEspacioLibreCensista(Censista arr[], int len) {
	int indice;

	indice = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}



int buscarCensistaPorId(Censista arr[], int id, int len) {
	int indice;

	indice = -1;
	if (arr != NULL && id > 0 && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].id == id && arr[i].isEmpty == FALSE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}



int agregarCensista(Censista arr[], int len, int id, char * nombre, char * apellido, int dia, int mes, int anio, int edad, char * nombreCalle, int numeroCalle) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && len > 0 && id > 0 && nombre != NULL && apellido != NULL && dia > 0 && mes >= 0 && anio > 0 && edad > 17 && nombreCalle != NULL && numeroCalle > 0) {
		indice = buscarEspacioLibreCensista(arr, len);
		if (indice != -1) {

			arr[indice].id = id;
			strncpy(arr[indice].nombre, nombre, strlen(nombre));
			strncpy(arr[indice].apellido, apellido, strlen(apellido));
			//autoincrementar id de dia y isEmpty?
			arr[indice].fechaNacimiento.id = incrementarFechaNacimientoId();
			arr[indice].fechaNacimiento.dia = dia;
			arr[indice].fechaNacimiento.mes = mes;
			arr[indice].fechaNacimiento.anio = anio;
			arr[indice].fechaNacimiento.isEmpty = FALSE;
			arr[indice].edad = edad;
			arr[indice].estadoCensista = 1;
			//autoinrementar id de direccion y isEmpty ?
			arr[indice].direccion.id = incrementarDireccionId();
			strncpy(arr[indice].direccion.calle, nombreCalle, strlen(nombreCalle));
			arr[indice].direccion.numero = numeroCalle;
			arr[indice].direccion.isEmpty = FALSE;
			arr[indice].isEmpty = FALSE;
			codigoError = 0;
		} else {
			puts("\n\nNo se pueden agregar m�s censistas");
		}
	}


	return codigoError;
}




int eliminarCensista(Censista arr[], int id, int len) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && id > 0 && len > 0) {
		indice = buscarCensistaPorId(arr, id, len);
		if (indice != -1) {
			arr[indice].isEmpty = TRUE;
			codigoError = 0;
		}
	}

	return codigoError;
}



//int modificarPasajero(Pasajero arr[], int id, int opcionMenu, int len) {
//	int codigoError;
//	int indice;
//
//
//	codigoError = -1;
//	if (arr != NULL && id > 0 && opcionMenu > 0 && len > 0) {
//		indice = buscarPasajeroPorId(arr, id, len);
//		if (indice != -1) {
//			switch (opcionMenu) {
//				case 1:
//					codigoError = utn_getString(arr[indice].nombre, "\nIngrese nuevo nombre: ", "\nNombre inv�lido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50);
//
//					break;
//				case 2:
//					codigoError = utn_getString(arr[indice].apellido, "\nIngrese nuevo apellido: ", "\nApellido inv�lido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50);
//
//					break;
//				case 3:
//					codigoError = utn_getFloat(&arr[indice].precio, "\nIngrese el nuevo precio: ", "\nPrecio inv�lido. Debe contener solo n�meros.\n", 578800, 2500, 3);
//					break;
//				case 4:
//					codigoError = utn_getInt(&arr[indice].tipoPasajero, "\nIngrese el tipo de pasajero [PRIMERA_CLASE (0), EJECUTIVO (1), PREMIUM (2)]: ", "\nOpci�n inv�lida. Debe estar entre 0 y 2.\n", 2, 0, 3);
//					break;
//				case 5:
//					codigoError = utn_getString(arr[indice].codigoVuelo, "\nIngrese el nuevo c�digo de vuelo: ", "\nC�digo de vuelo inv�lido. Debe tener 6 letras.\n", 3, 6, 6);
//					break;
//				default:
//					break;
//			}
//		} else {
//			puts("\nID del pasajero inexistente\n");
//		}
//	}
//
//	return codigoError;
//}


int hayCensistaCargado(Censista arr[], int len) {
	int hayAlgo;

	hayAlgo = FALSE;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].isEmpty == FALSE) {
				hayAlgo = TRUE;
				break;
			}
		}
	}

	return hayAlgo;
}


int existeCensista(Censista arr[], int len, int id) {
	int existe;
	int indice;

	existe = FALSE;

	if (arr != NULL && len > 0 && id > 0) {
		indice = buscarCensistaPorId(arr, id, len);
		if (indice != -1) {
			existe = TRUE;
		}
	}

	return existe;
}


int incrementarCensistaId(void) {
	static int id = 150;
	id++;

	return id;
}



void imprimirCensista(Censista censista) {
	if (censista.isEmpty == FALSE) {
		printf("|%6d", censista.id);
		printf("|%20s", censista.nombre);
		printf("|%20s", censista.apellido);
		printf("|%3d/%3d/%3d  ", censista.fechaNacimiento.dia, censista.fechaNacimiento.mes, censista.fechaNacimiento.anio);
		printf("|%6d", censista.edad);
		printf("|%10s", estadoCensista[censista.estadoCensista]);
		printf("|%12s %8d", censista.direccion.calle, censista.direccion.numero);
		printf("|%15d|", censista.idZona);
	}
}


void imprimirCabeceraCensista(void) {

		printf("|%6s", "ID");
		printf("|%20s", "NOMBRE");
		printf("|%20s", "APELLIDO");
		printf("|%20s", "FECHA NACIMIENTO");
		printf("|%6s", "EDAD");
		printf("|%10s", "ESTADO");
		printf("|%20s", "DIRECCI�N");
		printf("|%15s|\n\n", "ZONA");

}



void imprimirCensistas(Censista arr[], int len) {
	if (arr != NULL) {
		for(int i = 0; i < len; i++) {
			imprimirCensista(arr[i]);
		}
	}
}



//void imprimirPasajerosPorEstado(Pasajero arr[], int len, int estado) {
//	if (arr != NULL && len > 0 && (estado >= 0 || estado <= 2) ) {
//		for(int i = 0; i < len; i++) {
//			if (arr[i].estadoVuelo == 0) {
//				imprimirPasajero(arr[i]);
//			}
//		}
//	}
//}




//int ordenarPasajeros(Pasajero arr[], int len, int orden) {
//	int codigoError;
//	int estaOrdenado;
//
//	Pasajero auxPasajero;
//
//
//	codigoError = -1;
//	if (arr != NULL && len > 0 && (orden == 2 || orden == 1)) {
//		do {
//			estaOrdenado = TRUE;
//			len--;
//			switch (orden) {
//				case 1:
//					//ordeno de forma ascendente
//					for (int i = 0; i < len; i++) {
//
//						if (strcmp(arr[i].apellido, arr[i + 1].apellido) > 0) {
//							if (arr[i].tipoPasajero > arr[i + 1].tipoPasajero) {
//								auxPasajero = arr[i];
//								arr[i] = arr[i + 1];
//								arr[i + 1] = auxPasajero;
//								estaOrdenado = FALSE;
//							}
//
//						}
//					}
//					break;
//				case 2:
//					//ordeno de forma descendente
//					for (int i = 0; i < len; i++) {
//						if (strcmp( arr[i + 1].apellido, arr[i].apellido) > 0) {
//							if (arr[i].tipoPasajero < arr[i + 1].tipoPasajero) {
//								auxPasajero = arr[i];
//								arr[i] = arr[i + 1];
//								arr[i + 1] = auxPasajero;
//								estaOrdenado = FALSE;
//							}
//
//						}
//					}
//					break;
//				default:
//					break;
//			}
//		} while (estaOrdenado == FALSE);
//		codigoError = 0;
//	}
//
//	return codigoError;
//}



//int ordenarPasajerosPorCodigo(Pasajero arr[], int len, int orden) {
//	int codigoError;
//	int estaOrdenado;
//
//	Pasajero auxPasajero;
//
//
//	codigoError = -1;
//	if (arr != NULL && len > 0 && (orden == 2 || orden == 1)) {
//		do {
//			estaOrdenado = TRUE;
//			len--;
//			switch (orden) {
//				case 1:
//					//ordeno de forma ascendente
//					for (int i = 0; i < len; i++) {
//
//						if (strcmp(arr[i].codigoVuelo, arr[i + 1].codigoVuelo) > 0) {
//								auxPasajero = arr[i];
//								arr[i] = arr[i + 1];
//								arr[i + 1] = auxPasajero;
//								estaOrdenado = FALSE;
//
//						}
//					}
//					break;
//				case 2:
//					//ordeno de forma descendente
//					for (int i = 0; i < len; i++) {
//						if (strcmp( arr[i + 1].codigoVuelo, arr[i].codigoVuelo) > 0) {
//								auxPasajero = arr[i];
//								arr[i] = arr[i + 1];
//								arr[i + 1] = auxPasajero;
//								estaOrdenado = FALSE;
//
//						}
//					}
//					break;
//				default:
//					break;
//			}
//		} while (estaOrdenado == FALSE);
//		codigoError = 0;
//	}
//
//	return codigoError;
//}



//int hacerCargaForzada(Pasajero arr[], int len) {
//	int codigoError;
//	int id;
//	char nombres[][51] = {"Malvina", "Martin", "Mariana", "Pedro", "Juan", "Nicolas", "Andrea", "Carlos", "Lucas", "Maximiliano", "Hector", "Jesica", "Gabriel", "Horacio", "Oscar"};
//	char apellidos[][51] = {"Sainz", "Godirio", "Valenzuela", "Acosta", "Lopez","Caruso", "Bollati", "Vitola", "Calvo", "Biglia", "Thomas", "Paulovies", "Marino", "Bollati", "Chananpa"};
//	float precios[] = {4500, 45000, 72345, 25000, 13200, 6500, 7200, 30255, 7900, 17456, 56789, 25400, 9800, 27890, 15600};
//	int tipoPasajeros[] = {1, 0, 1, 2 ,0, 1, 2, 0, 0, 1, 2, 0, 1, 1, 2};
//	char codigoVuelos[][10] = {"FGHQWE", "TYUQWE", "POILKJ", "FGHVBN", "YUIJKL","ARARAR", "QWEASD", "ASDQWE", "ZXCVBN", "QWERTY", "TYUGHJ", "TYUQWE", "ASDFGH", "UIOPJK", "QWEASD"};
//	int estadoVuelos[] = {1, 2, 2, 0, 1, 0, 2, 1, 1, 1, 2, 0, 0, 2, 1};
//	codigoError = -1;
//
//	if (arr != NULL) {
//		for(int i = 0; i < 15; i++) {
//			id = incrementarId();
//			codigoError = agregarPasajero(arr, len, id, nombres[i], apellidos[i], precios[i], tipoPasajeros[i], codigoVuelos[i], estadoVuelos[i]);
//			if (codigoError == -1) {
//				codigoError = -1;
//				break;
//			}
//			codigoError = 0;
//		}
//	}
//
//	return codigoError;
//}



//int calcularTotalDeTodosLosPasajes(Pasajero arr[], float * total, int len) {
//	int codigoError;
//	float resultado;
//
//	resultado = 0;
//	codigoError = -1;
//
//	if (arr != NULL && total != NULL && len > 0) {
//		for(int i = 0; i < len; i++) {
//			if (arr[i].isEmpty) {
//				codigoError = 0;
//				break;
//			}
//			resultado += arr[i].precio;
//		}
//		* total = resultado;
//		codigoError = 0;
//	}
//
//	return codigoError;
//}



//int calcularPromedioDePasajes(Pasajero arr[], float * promedio, float total, int len) {
//	int codigoError;
//	int contador;
//	float resultado;
//
//	contador = 0;
//	codigoError = -1;
//
//	if (arr != NULL && promedio != NULL && total > 0 && len > 0) {
//		for(int i = 0; i < len; i++) {
//			if (arr[i].isEmpty) {
//				codigoError = 0;
//				break;
//			}
//			contador++;
//		}
//		resultado = total / contador;
//		* promedio = resultado;
//		codigoError = 0;
//	}
//
//	return codigoError;
//}



//int calcularCuantosSuperanPromedio(Pasajero arr[], float promedio, int * cantidadSuperanPromedio, int len) {
//	int codigoError;
//	int contador;
//
//	contador = 0;
//	codigoError = -1;
//	if (arr != NULL && promedio > 0 && cantidadSuperanPromedio != NULL && len > 0) {
//		for(int i = 0; i < len; i++) {
//			if (arr[i].isEmpty) {
//				codigoError = 0;
//				break;
//			}
//
//			if (arr[i].precio > promedio) {
//				contador++;
//			}
//
//		}
//		* cantidadSuperanPromedio = contador;
//		codigoError = 0;
//	}
//
//
//	return codigoError;
//}



//void imprimirCalculosDePasajeros(float totalPrecios, float promedio, int cantidadSuperanPromedio) {
//	printf("\n\nEl total de todos los precios es: %.2f", totalPrecios);
//	printf("\nEl promedio de precios es: %.2f", promedio);
//	printf("\nCantidad de pasajeros que superan el promedio: %d\n\n", cantidadSuperanPromedio);
//}

