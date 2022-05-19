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
#include <string.h>

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
#define CANTIDAD_LOCALIDADES 6

int main(void) {
	Censista censistas[CANTIDAD_CENSISTAS];
//	FechaNacimiento fechaNacimientos[CANTIDAD_CENSISTAS];
//	Direccion direcciones[CANTIDAD_CENSISTAS];
	Zona zonas[CANTIDAD_ZONAS];

	int id;
	char nombreCensista[51];
	char apellidoCensista[51];
	int dia;
	int mes;
	int anio;
	int edad;
	int cantidadVirtual;
	int cantidadAusente;
	char nombreCalle[51];
	int numeroCalle;


	char calles[4][51];
	int localidad;
	int codigoError;
	int opcionMenu;
//	char opcionMenuChar;
	int indice;
	int zonaAsignada;
//	int hayCargaForzada;

//	hayCargaForzada = FALSE;

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");
	inicializarCensistas(censistas, CANTIDAD_CENSISTAS);
	inicializarZonas(zonas, CANTIDAD_ZONAS);

	do {
		codigoError = utn_getInt(&opcionMenu, "\n0- Carga forzada. \n1- Cargar censista. \n2- Modificar censista. \n3- Eliminar censista. \n4- Cargar zona. \n5- Asignar zona a censar. \n6- Carga de datos. \n7- Mostrar censistas. \n8- Mostrar zonas. \n9- Salir. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 9, 0, 3);

		if (codigoError == 0) {
			switch (opcionMenu) {
				case 0:
					puts("\n=== CARGA FORZADA ===\n");

					if (hayCensistaCargado(censistas, CANTIDAD_CENSISTAS) || hayZonaCargada(zonas, CANTIDAD_ZONAS)) {

						puts("\nImposible hacer carga forzada si hay algo cargado.\n");

					} else {
						codigoError = hacerCargaForzadaCensista(censistas, CANTIDAD_CENSISTAS);
						if (codigoError == 0) {
							codigoError = hacerCargaForzadaZona(zonas, CANTIDAD_ZONAS);
							puts("\nCarga zona ok\n");
						}
						utn_imprimirMensajes(codigoError, "\nSe ha hecho la carga forzada satisfactoriamente.\n", "\nHa ocurrido un error al hacer la carga forzada.\n");

					}

				break;
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
					if (hayCensistaCargado(censistas, CANTIDAD_CENSISTAS)) {
						codigoError = utn_getInt(&id, "\nIngrese el ID del censista a modificar: ", "\nError. Sólo se permiten números del 150 al 999.\n", 999, 150, 3);
						if (codigoError == 0 && existeCensista(censistas, CANTIDAD_CENSISTAS, id)) {
							indice = buscarCensistaPorId(censistas, id, CANTIDAD_CENSISTAS);
							imprimirCabeceraCensista();
							imprimirCensista(censistas[indice]);
							//me quede aca tengo que hacer el modificar
							do {
								codigoError = utn_getInt(&opcionMenu, "\n1- Modificar nombre. \n2- Modificar apellido. \n3- Modificar fecha de nacimiento. \n4- Modificar estado del censista. \n5- Modificar dirección. \n6- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Solo se permite del 1 al 6.\n", 6, 1, 3);

								switch (opcionMenu) {
									case 1:
										puts("\n=== MODIFICAR NOMBRE ===\n");

										codigoError = utn_getString(censistas[indice].nombre, "\nIngrese el nuevo nombre: ", "\nError. Debe contener sólo letras y tener entre 4 y 50 caractéres.\n", 3, 4, 51);
										utn_imprimirMensajes(codigoError, "\nSe ha modificado el nombre satisfactoriamente.\n", "\nHa ocurrido un error al modificar el nombre.\n");
										break;
									case 2:
										puts("\n=== MODIFICAR APELLIDO ===\n");

										codigoError = utn_getString(censistas[indice].apellido, "\nIngrese el nuevo apellido: ", "\nError. Debe contener sólo letras y tener entre 4 y 50 caractéres.\n", 3, 4, 51);
										utn_imprimirMensajes(codigoError, "\nSe ha modificado el apellido satisfactoriamente.\n", "\nHa ocurrido un error al modificar el apellido.\n");
										break;
									case 3:
										puts("\n=== MODIFICAR FECHA DE NACIMIENTO ===\n");

										do {
											codigoError = utn_getInt(&opcionMenu, "\n1- Modificar día de nacimiento. \n2- Modificar mes de nacimiento. \n3- Modificar año de nacimiento. \n4- Atras. \n\nIngrese una opción: ", "\nOpción inválidad. Reintente.\n", 4, 1, 3);

											switch (opcionMenu) {
												case 1:
													codigoError = utn_getInt(&censistas[indice].fechaNacimiento.dia, "\nIngrese el nuevo día: ", "\nError. Debe contener un número del 1 al 31\n", 31, 1, 3);
													utn_imprimirMensajes(codigoError, "\nEl día de nacimiento fué modificado satisfactoriamente.\n", "\nHa ocurrido un error al modificar el día de nacimiento.\n");
													break;
												case 2:
													codigoError = utn_getInt(&censistas[indice].fechaNacimiento.mes, "\nIngrese el nuevo mes: ", "\nError. Debe contener un número del 1 al 12\n", 12, 1, 3);
													utn_imprimirMensajes(codigoError, "\nEl mes de nacimiento fué modificado satisfactoriamente.\n", "\nHa ocurrido un error al modificar el mes de nacimiento.\n");
													break;
												case 3:
													codigoError = utn_getInt(&censistas[indice].fechaNacimiento.anio, "\nIngrese el nuevo año: ", "\nError. Debe contener un número del 1950 al 2002\n", 2002, 1950, 3);
													//hacer funcion para cambiar anio
													censistas[indice].edad = 2022 - censistas[indice].fechaNacimiento.anio;
													utn_imprimirMensajes(codigoError, "\nEl año de nacimiento fué modificado satisfactoriamente.\n", "\nHa ocurrido un error al modificar el año de nacimiento.\n");
													break;
												default:
													break;
											}
										} while(opcionMenu != 4 && codigoError == 0);
										break;
									case 4:
										puts("\n=== MODIFICAR ESTADO DEL CENSISTA ===\n");

										codigoError = utn_getInt(&censistas[indice].estadoCensista, "\nIngrese un nuevo estado del censista 0 ACTIVO, 1 INACTIVO, 2 LIBERADO: ", "\nOpción inválida. Sólo se permite 0para ACTIVO, 1 para INACTIVO y 2 para LIBERADO.\n", 2, 0, 3);
										utn_imprimirMensajes(codigoError, "\nSe ha modificado el estado del censista satisfactoriamente.\n", "\nHa ocurrido un error al modificar el estado del censista.\n");
										break;
									case 5:
										puts("\n=== MODIFICAR DIRECCIÓN ===\n");

										do {
											codigoError = utn_getInt(&opcionMenu, "\n1- Modificar nombre de calle. \n2- Modificar número de domicilio. \n3- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 3, 1, 3);

											switch (opcionMenu) {
												case 1:
													codigoError = utn_getString(censistas[indice].direccion.calle, "\nIngrese la nueva calle: ", "\nError. Sólo debe contener solo letras y estar entre 4 y 50 caractéres.\n", 3, 4, 50);
													utn_imprimirMensajes(codigoError, "\nSe ha modificado el nombre de calle satisfactoriamente.\n", "\nHa ocurrido un error al modificar el nombre de calle.\n");
													break;
												case 2:
													codigoError = utn_getInt(&censistas[indice].direccion.numero, "\nIngrese el nuevo número de domicilio: ", "\nDebe contener sólo números y estar entre 1 y 3500\n", 3500, 1, 3);
													utn_imprimirMensajes(codigoError, "\nSe ha modificado el número de domicilio satisfactoriamente.\n", "\nHa ocurrido un error al modificar el número de domicilio.\n");
													break;
												default:
													break;
											}
										} while(opcionMenu != 3 && codigoError == 0);
										break;
									default:
										break;
								}
							} while(opcionMenu != 6 && codigoError == 0);

							utn_imprimirMensajes(codigoError, "\nSe ha modificado los datos correctamente.\n", "\nHa ocurrido un error al modificar los datos.\n");

						} else {
							puts("\nEl ID ingresado es inexistente.\n");
						}
					} else {
						puts("\nDebe haber al menos un censista cargado.\n");
					}
					break;
				case 3:
					puts("\n=== ELIMINAR CENSISTA ===\n");
					if (hayCensistaCargado(censistas, CANTIDAD_CENSISTAS)) {
						codigoError = utn_getInt(&id, "\nIngrese el ID del censista a eliminar: ", "\nError. Sólo se permiten números del 150 al 999.\n", 999, 150, 3);
						if (codigoError == 0 && existeCensista(censistas, CANTIDAD_CENSISTAS, id)) {
							indice = buscarCensistaPorId(censistas, id, CANTIDAD_CENSISTAS);
							imprimirCabeceraCensista();
							imprimirCensista(censistas[indice]);
							codigoError = eliminarCensista(censistas, id, CANTIDAD_CENSISTAS);

							utn_imprimirMensajes(codigoError, "\nSe ha eliminado al censista satisfactoriamente.\n", "\nHa ocurrido un error al eliminar al censista.\n");

						} else {
							puts("\nEl ID ingresado es inexistente.\n");
						}

					} else {
						puts("\nDebe haber al menos un censista cargado.\n");
					}
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

					if (hayZonaCargada(zonas, CANTIDAD_ZONAS) && hayCensistaCargado(censistas, CANTIDAD_CENSISTAS)) {

						codigoError = utn_getInt(&id, "\nIngrese el ID del censista para asignarle una zona: ", "\nError. Sólo se permiten números del 150 al 999.\n", 999, 150, 3);
						if (codigoError == 0 && existeCensista(censistas, CANTIDAD_CENSISTAS, id)) {
							indice = buscarCensistaPorId(censistas, id, CANTIDAD_CENSISTAS);
							imprimirCabeceraCensista();
							imprimirCensista(censistas[indice]);
							//cambiar por lapropiedad directa
							codigoError = utn_getInt(&zonaAsignada, "\n\nIngrese la zona a asignar [11,12,13,14,15,16]: ", "\nOpción inválida. Solo se permite del 11 al 16.\n", 16, 11, 3);

						} else {
							puts("\nEl ID ingresado es inexistente.\n");
						}
						if (codigoError == 0) {
							//refactoizar con asignarZona()
							censistas[indice].idZona = zonaAsignada;
							censistas[indice].estadoCensista = 0;
						}
						utn_imprimirMensajes(codigoError, "\nSe ha asignado una zona al censita satisfactoriamente.\n", "\nHa ocurrido un error al asignar zona al censista.\n");
					} else {
						puts("\nDebe haber al menos una zona y un censista cargados.\n");
					}
					break;
				case 6:
					puts("\n=== CARGA DE DATOS ===\n");
					//hay censistasAsignados HACER
					if (hayCensistaCargado(censistas, CANTIDAD_CENSISTAS) && hayZonaCargada(zonas, CANTIDAD_ZONAS)) {
						codigoError = utn_getInt(&id, "\nIngrese el ID del censista para la carga de datos: ", "\nError. Sólo debe haber números del 150 al 999.\n", 999, 150, 3);
						if (codigoError == 0 && existeCensista(censistas, CANTIDAD_CENSISTAS, id)) {
							indice = buscarCensistaPorId(censistas, id, CANTIDAD_CENSISTAS);
							imprimirCabeceraCensista();
							imprimirCensista(censistas[indice]);

							codigoError = utn_getInt(&cantidadVirtual, "\nIngrese cantidad de censados virtuales: ", "\nError. Sólo se permiten números del 0 al 999.\n", 999, 0, 3);
							if (codigoError == 0) {
								codigoError = utn_getInt(&cantidadAusente, "\nIngrese la cantidad de ausentes: ", "\nError. Sólo se permiten números.\n", 999, 0, 3);

								if (codigoError == 0) {
									int indiceZona = buscarZonaPorId(zonas, censistas[indice].idZona, CANTIDAD_ZONAS);
									int idZona = zonas[indiceZona].id;

									codigoError = cargarDatos(zonas, idZona, CANTIDAD_ZONAS, cantidadVirtual, cantidadAusente);

								}
							}

							utn_imprimirMensajes(codigoError, "\nSe han cargado los datos satisfactoriamente.\n", "\nHa sucedido un error al cargar los datos\n");
						}
					} else {
						puts("\nDebe haber al menos una zona y un censista cargado.\n");
					}
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
