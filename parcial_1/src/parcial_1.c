/*
 ============================================================================
 Name        : parcial_1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "censista.h"
#include "fechaNacimiento.h"
#include "direccion.h"
#include "zona.h"
#include "localidad.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define CANTIDAD_CENSISTAS 200
#define CANTIDAD_ZONAS 6

int main(void) {
	Censista censistas[CANTIDAD_CENSISTAS];
//	FechaNacimiento fechaNacimientos[CANTIDAD_CENSISTAS];
//	Direccion direcciones[CANTIDAD_CENSISTAS];
	Zona zonas[CANTIDAD_ZONAS];
//	Localidad localidades[][51] = {"Lanús", "Avellaneda", "Gerli", "Remedios de Escalada", "Bandfield", "Lomas de Zamora", "Berazategui", "La Plata", "Glew", "Maximiliano Korn"};

	int id;
	char nombreCensista[51];
	char apellidoCensista[51];
	int dia;
	int mes;
	int anio;
	int edad;
//	int estadoCensista;
	char nombreCalle[51];
	int numeroCalle;
//	int idZona;


	char calles[4][51];
	int localidad;
	int codigoError;
	int opcionMenu;

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");
	inicializarCensistas(censistas, CANTIDAD_CENSISTAS);
	inicializarZonas(zonas, CANTIDAD_ZONAS);

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Cargar censista. \n2- Modificar censista. \n3- Eliminar censista. \n4- Cargar zona. \n5- Asignar zona a censar. \n6- Carga de datos. \n7- Mostrar censistas. \n8- Mostrar zonas. \n9- Salir. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 9, 1, 3);

		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("\n=== CARGA DEL CENSISTA ===\n");
					codigoError = utn_getString(nombreCensista, "\nIngrese el nombre del censista: ", "\nError. Debe contener sólo letras y tener entre 4 y 15 caractéres.\n", 3, 4, 15);
					if (codigoError == 0) {
						codigoError = utn_getString(apellidoCensista, "\nIngrese el apellido del censista: ", "\nError. Debe contener sólo letras y tener entre 4 y 15 caractéres.\n", 3, 4, 15);

						if (codigoError == 0) {
							codigoError = utn_getInt(&dia, "\nIngrese el día de nacimiento del censista [1 a 31]: ", "\nError. Debe contener sólo números del 1 al 31.\n", 31, 1, 3);

							if (codigoError == 0) {
								codigoError = utn_getInt(&mes, "\nIngrese el mes de nacimiento del censista [1 a 12]: ", "\nError. Debe contener sólo números del 1 al 12.\n", 12, 1, 3);

								if (codigoError == 0) {
									codigoError = utn_getInt(&anio, "\nIngrese el año de nacimiento del censista [1960 a 2022]: ", "\nError. Debe contener sólo números entre 1960 y 2022.\n", 2022, 1960, 3);

									if (codigoError == 0) {
										edad = 2022 - anio;

										if (codigoError == 0) {
											codigoError = utn_getString(nombreCalle, "\nIngrese la calle de domicilio del censista: ", "\nError. Debe contener sólo letras y tener entre 4 y 30 caractéres.\n", 3, 4, 30);

											if (codigoError == 0) {
												codigoError = utn_getInt(&numeroCalle, "\nIngrese el número de domicilio del censista: ", "\nError. Debe contener sólo números y estar entre 1 y 3500", 3500, 1, 3);
												id = incrementarCensistaId();

												if (codigoError == 0) {
													codigoError = agregarCensista(censistas, CANTIDAD_CENSISTAS, id, nombreCensista, apellidoCensista, dia, mes, anio, edad, nombreCalle, numeroCalle);

												}
											}
										}
									}
								}
							}
						}
					}

					utn_imprimirMensajes(codigoError, "\nSe han ingresado los datos satisfactoriamente.\n", "\nHa sucedido un error en la carga de datos.\n");
					break;
				case 2:
					puts("\n=== MODIFICAR CENSISTA ===\n");
					break;
				case 3:
					puts("\n=== ELIMINAR CENSISTA ===\n");
					break;
				case 4:
					puts("\n=== CARGAR ZONA ===\n");
					int i = 0;
					do {
						codigoError = utn_getString(calles[i], "\nIngrese el nombre de la calle en la zona: ", "\nError. Debe contener sólo letras y tener 6 a 20 caractéres.\n", 3, 6, 20);
						i++;
					} while(i < 4 && codigoError == 0);
					if (codigoError == 0) {
						codigoError = utn_getInt(&localidad, "\n0- Bandfield. \n1- Lanús. \n2- Escalada. \n3- Temperley. \n4- Gerli. \n5- Avellaneda. \n\nIngrese una localidad: ", "\nOpción inválidad. Reintente.\n", 5, 1, 3);

						if (codigoError == 0) {
							id = incrementarZonaId();
							agregarZona(zonas, CANTIDAD_ZONAS, id, calles, localidad);
						}
					}

					utn_imprimirMensajes(codigoError, "\nSe ha agregado una zona satisfactoriamente.\n", "\nHa ocurrido un error al agregar una zona.\n");
					break;
				case 5:
					puts("\n=== ASIGNAR ZONA A CENSAR ===\n");
					break;
				case 6:
					puts("\n=== CARGA DE DATOS ===\n");
					break;
				case 7:
					puts("\n=== MOSTRAR CENSISTAS ===\n");

					if (hayCensistaCargado(censistas, CANTIDAD_CENSISTAS)) {
						imprimirCabeceraCensista();
						imprimirCensistas(censistas, CANTIDAD_CENSISTAS);
					} else {
						puts("\nDebe haber al menos un censista cargado.\n");
					}
					break;
				case 8:
					puts("\n=== MOSTRAR ZONAS ===\n");

					if (hayZonaCargada(zonas, CANTIDAD_ZONAS)) {
						imprimirCabeceraZona();
						imprimirZonas(zonas, CANTIDAD_ZONAS);
					} else {
						puts("\nDebe haber al menos una zona cargada.\n");
					}
					break;
				default:
					break;
			}
		}
	} while(opcionMenu != 9 && codigoError == 0);

	puts("\nSaliendo...\n");
	puts("=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
