/*
 * censista.c
 *
 *  Created on: 16 may 2022
 *      Author: Nicolás Caruso
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



int buscarCensistaConZonaMasCensada(Censista arr[], int idZona, int len) {
	int indice;

	if (arr != NULL && idZona > 0 && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].idZona == idZona) {
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
			arr[indice].idZona = 0;
			arr[indice].isEmpty = FALSE;
			codigoError = 0;
		} else {
			puts("\n\nNo se pueden agregar más censistas");
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
			arr[indice].direccion.isEmpty = TRUE;
			arr[indice].fechaNacimiento.isEmpty = TRUE;
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


int hayCensistaAsignado(Censista arr[], int len) {
	int hayAlgo;

	hayAlgo = FALSE;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].idZona >= 11 && arr[i].idZona <= 16) {
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
		printf("|%4d", censista.id);
		printf("|%12s", censista.nombre);
		printf("|%12s", censista.apellido);
		printf("|%10d/%d/%d    ", censista.fechaNacimiento.dia, censista.fechaNacimiento.mes, censista.fechaNacimiento.anio);
		printf("|%6d", censista.edad);
		printf("|%10s", estadoCensista[censista.estadoCensista]);
		printf("|%12s %4d", censista.direccion.calle, censista.direccion.numero);
		if (censista.idZona == 0) {
			printf("|%15s|\n", "sin zona");
		} else {
			printf("|%15d|\n", censista.idZona);
		}
	}
}


void imprimirCabeceraCensista(void) {

		printf("|%4s", "ID");
		printf("|%12s", "NOMBRE");
		printf("|%12s", "APELLIDO");
		printf("|%21s", "FECHA NACIMIENTO");
		printf("|%6s", "EDAD");
		printf("|%10s", "ESTADO");
		printf("|%20s", "DIRECCIÓN");
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




int ordenarCensistas(Censista arr[], int len, int orden) {
	int codigoError;
	int estaOrdenado;

	Censista auxCensista;


	codigoError = -1;
	if (arr != NULL && len > 0 && (orden == 2 || orden == 1)) {
		do {
			estaOrdenado = TRUE;
			len--;
			switch (orden) {
				case 1:
					//ordeno de forma ascendente
					for (int i = 0; i < len; i++) {

						if (strcmp(arr[i].apellido, arr[i + 1].apellido) > 0) {
							if (arr[i].nombre > arr[i + 1].nombre) {
								auxCensista = arr[i];
								arr[i] = arr[i + 1];
								arr[i + 1] = auxCensista;
								estaOrdenado = FALSE;
							}

						}
					}
					break;
				case 2:
					//ordeno de forma descendente
					for (int i = 0; i < len; i++) {
						if (strcmp( arr[i + 1].apellido, arr[i].apellido) > 0) {
							if (arr[i].nombre < arr[i + 1].nombre) {
								auxCensista = arr[i];
								arr[i] = arr[i + 1];
								arr[i + 1] = auxCensista;
								estaOrdenado = FALSE;
							}

						}
					}
					break;
				default:
					break;
			}
		} while (estaOrdenado == FALSE);
		codigoError = 0;
	}

	return codigoError;
}



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



int hacerCargaForzadaCensista(Censista arr[], int len) {
	int codigoError;
	int id;
	int edad;
	char nombres[][51] = {"Malvina", "Martin", "Mariana", "Pedro", "Juan", "Nicolas"};
	char apellidos[][51] = {"Sainz", "Godirio", "Valenzuela", "Acosta", "Lopez","Caruso"};
	int dias[] = {25, 12, 5, 29, 7, 17};
	int meses[] = {2, 5, 1, 8, 7, 12};
	int anios[] = {2001, 1992, 1980, 1996, 1994, 2000};
	char nombresCalles[][51] = {"Azcuenaga", "Pedernera", "San Lorenzo", "Achaval", "Aguapey", "Aguilar"};
	int numerosCalles[] = {2553, 1500, 2768, 1200, 1250, 3214};
	int zonas[] = {11, 12, 13, 14, 15, 16};

	codigoError = -1;

	if (arr != NULL && len > 0) {
		for(int i = 0; i < 6; i++) {
			id = incrementarCensistaId();
			edad = 2022 - anios[i];
			codigoError = agregarCensista(arr, len, id, nombres[i], apellidos[i], dias[i], meses[i], anios[i], edad, nombresCalles[i], numerosCalles[i]);
			arr[i].idZona = zonas[i];
			arr[i].estadoCensista = 2;
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

