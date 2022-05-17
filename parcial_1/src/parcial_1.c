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

int main(void) {
	Censista censistas[CANTIDAD_CENSISTAS];
	FechaNacimiento fechaNacimientos[CANTIDAD_CENSISTAS];
	Direccion direcciones[CANTIDAD_CENSISTAS];
	Zona zonas[100];
	Localidad localidades[][51] = {"Lanús", "Avellaneda", "Gerli", "Remedios de Escalada", "Bandfield", "Lomas de Zamora", "Berazategui", "La Plata", "Glew", "Maximiliano Korn"};

	int codigoError;
	int opcionMenu;

	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Cargar censista. \n2- Modificar censista. \n3- Eliminar censista. \n4- Cargar zona. \n5- Asignar zona a censar. \n6- Carga de datos. \n7- Mostrar censistas. \n8- Mostrar zonas. \n9- Salir. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 9, 1, 3);

		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("\n=== CARGA DEL CENSISTA ===\n");
					break;
				case 2:
					puts("\n=== MODIFICAR CENSISTA ===\n");
					break;
				case 3:
					puts("\n=== ELIMINAR CENSISTA ===\n");
					break;
				case 4:
					puts("\n=== CARGAR ZONA ===\n");
					break;
				case 5:
					puts("\n=== ASIGNAR ZONA A CENSAR ===\n");
					break;
				case 6:
					puts("\n=== CARGA DE DATOS ===\n");
					break;
				case 7:
					puts("\n=== MOSTRAR CENSISTAS ===\n");
					break;
				case 8:
					puts("\n=== MOSTRAR ZONAS ===\n");
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
