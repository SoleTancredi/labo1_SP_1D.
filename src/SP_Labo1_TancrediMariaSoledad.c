/*
 ============================================================================
 Name        : SP_Labo1_TancrediMariaSoledad.c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Perrito.h"
#include "BibliotecaUtn2021.h"

int main(void)
{
	LinkedList* perritoList  = ll_newLinkedList();
	int option;
	Perrito* pbuffer;

	pbuffer = perrito_newParametros("12", "yicon", "45.2", "3", "galgo");
	perrito_showUnit(pbuffer);

	//controller_loadFromText("perritos.csv", perritoList);

	 do
	 {
		 printf("\n\t\t »»»»» MENU PRINCIPAL «««««\n");
		if( utn_getNumber(&option,""
				"\n[1] Cargar datos de perritos desde data.csv (modo texto)."
				"\n[2] Listar perritos ordenados de manera ascedente por nombre."
				"\n[3] Agregar empleado "
				"\n[4] Modificar datos de empleado"
				"\n[5] Eliminar empleado "
				"\n[6] Listar todos los empleados"
				"\n[7] Salir. "
				"\n »» INGRESE UNA OPCION:  ", "\n × ERROR. ", 1, 7, 1) == 0)
		{
			switch(option)
			{
				case 1:
					if(controller_loadFromText("perritos.csv", perritoList) == 0)
					{
						printf("\n »» CARGA DE DATOS EXITOSA ");
					}
					else
					{
						printf("\n X No se han cargado los datos.");
					}

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				case 7:
					printf("\n »»» FIN DEL PROGRAMA ««« ");
					ll_deleteLinkedList(perritoList);
					break;
			}
		}
	 }while(option != 7);





	return EXIT_SUCCESS;
}