/*
 * zona.c
 *
 *  Created on: 16 may 2022
 *      Author: Nicolás Caruso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "zona.h"
#include "localidad.h"

#define TRUE 1
#define FALSE 0

char localidades[][51] = {"Bandfield", "Lanús", "Escalada", "Temperley", "Gerli", "Avellaneda"};
char estadoZonas[][51] = {"PENDIENTE", "FINALIZADO"};

int inicializarZonas(Zona arr[], int len) {
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



int buscarEspacioLibreZona(Zona arr[], int len) {
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



int buscarZonaPorId(Zona arr[], int id, int len) {
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



int agregarZona(Zona arr[], int len, int id, char calles[][51], int localidad) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && len > 0 && id > 0 && calles != NULL) {
		indice = buscarEspacioLibreZona(arr, len);
		if (indice != -1) {

			arr[indice].id = id;
			strncpy(arr[indice].calles[0], calles[0], strlen(calles[0]));
			strncpy(arr[indice].calles[1], calles[1], strlen(calles[1]));
			strncpy(arr[indice].calles[2], calles[2], strlen(calles[2]));
			strncpy(arr[indice].calles[3], calles[3], strlen(calles[3]));
			arr[indice].localidad = localidad;
			arr[indice].estadoZona = 0;
			arr[indice].isEmpty = FALSE;
			codigoError = 0;
		} else {
			puts("\n\nNo se pueden agregar más zonas.");
		}
	}


	return codigoError;
}


int cargarDatos(Zona arr[], int id, int len, int cantidadVirtual, int cantidadAusente) {
	int codigoError;
	int indice;

	codigoError = -1;

	if (arr != NULL && id > 0 && len > 0 && cantidadAusente >= 0 && cantidadAusente >= 0) {
		indice = buscarZonaPorId(arr, id, len);

		if (indice != -1) {

			arr[indice].cantidadAusente = cantidadAusente;
			arr[indice].cantidadVirtual = cantidadVirtual;
			codigoError = 0;
		}
	}

	return codigoError;
}





int eliminarZona(Zona arr[], int id, int len) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && id > 0 && len > 0) {
		indice = buscarZonaPorId(arr, id, len);
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
//					codigoError = utn_getString(arr[indice].nombre, "\nIngrese nuevo nombre: ", "\nNombre inválido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50);
//
//					break;
//				case 2:
//					codigoError = utn_getString(arr[indice].apellido, "\nIngrese nuevo apellido: ", "\nApellido inválido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50);
//
//					break;
//				case 3:
//					codigoError = utn_getFloat(&arr[indice].precio, "\nIngrese el nuevo precio: ", "\nPrecio inválido. Debe contener solo números.\n", 578800, 2500, 3);
//					break;
//				case 4:
//					codigoError = utn_getInt(&arr[indice].tipoPasajero, "\nIngrese el tipo de pasajero [PRIMERA_CLASE (0), EJECUTIVO (1), PREMIUM (2)]: ", "\nOpción inválida. Debe estar entre 0 y 2.\n", 2, 0, 3);
//					break;
//				case 5:
//					codigoError = utn_getString(arr[indice].codigoVuelo, "\nIngrese el nuevo código de vuelo: ", "\nCódigo de vuelo inválido. Debe tener 6 letras.\n", 3, 6, 6);
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


int hayZonaCargada(Zona arr[], int len) {
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


int existeZona(Zona arr[], int len, int id) {
	int existe;
	int indice;

	existe = FALSE;

	if (arr != NULL && len > 0 && id > 0) {
		indice = buscarZonaPorId(arr, id, len);
		if (indice != -1) {
			existe = TRUE;
		}
	}

	return existe;
}


int incrementarZonaId(void) {
	static int id = 10;
	id++;

	return id;
}



void imprimirZona(Zona zona) {
	if (zona.isEmpty == FALSE) {
		printf("|%6d", zona.id);
		printf("|%s %s %s %s", zona.calles[0], zona.calles[1], zona.calles[2], zona.calles[3]);
		printf("|%10s", estadoZonas[zona.estadoZona]);
		printf("|%10d", zona.cantidadAusente);
		printf("|%10d", zona.cantidadVirtual);
		printf("|%20s|\n", localidades[zona.localidad]);
	}
}


void imprimirCabeceraZona(void) {

		printf("|%6s", "ID");
		printf("|%35s", "CALLES");
		printf("|%10s", "ESTADO");
		printf("|%10s", "AUSENTE");
		printf("|%10s", "VIRTUAL");
		printf("|%20s|\n\n", "LOCALIDAD");
}



void imprimirZonas(Zona arr[], int len) {
	if (arr != NULL) {
		for(int i = 0; i < len; i++) {
			imprimirZona(arr[i]);
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



int hacerCargaForzadaZona(Zona arr[], int len) {
	int codigoError;
	int id;

	//zonas
	int localidades[] = {0, 1, 2, 3, 4, 5};
	char calles[][4][51] = {{"Pedernera", "SanLorenzo", "Alzaga", "Suipacha"}, {"Azcuenaga", "Pilar", "Centenario", "Aguapey"}, {"Alvear", "Almeyra", "Aguilar", "Calvo"}, {"Goezn", "Rioja", "Catamarca", "Gales"}, {"Pedernera", "SanLorenzo", "Alzaga", "Suipacha"}, {"Azcuenaga", "Pilar", "Centenario", "Aguapey"}, {"Alvear", "Almeyra", "Aguilar", "Calvo"}, {"Goezn", "Rioja", "Catamarca", "Gales"}, {"Pedernera", "SanLorenzo", "Alzaga", "Suipacha"}, {"Azcuenaga", "Pilar", "Centenario", "Aguapey"}, {"Alvear", "Almeyra", "Aguilar", "Calvo"}, {"Goezn", "Rioja", "Catamarca", "Gales"}, {"Pedernera", "SanLorenzo", "Alzaga", "Suipacha"}, {"Azcuenaga", "Pilar", "Centenario", "Aguapey"}, {"Alvear", "Almeyra", "Aguilar", "Calvo"}};
	int cantidadVirtual[] = {150, 170, 100, 56, 127, 78};
	int cantidadAusente[] = {15, 0, 35, 2, 7, 18};
	codigoError = -1;

	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			id = incrementarZonaId();
			codigoError = agregarZona(arr, len, id, calles[0][i], localidades[i]);
			if (codigoError == 0) {
				codigoError = cargarDatos(arr, id, len, cantidadVirtual[i], cantidadAusente[i]);
				arr[i].estadoZona = 1;
			}
			if (codigoError == -1) {
				codigoError = -1;
				break;
			}
			codigoError = 0;
		}

	}

	return codigoError;
}



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




