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
	int flagCarga = 0;
	Perrito* pbuffer;
	Perrito* pbuffer2;

	/*pbuffer = perrito_newParametros3("12", "pepe", "2", "15", "Galgo", "23");
	pbuffer2 = perrito_newParametros3("15", "sapo", "16", "12", "Galgo", "600.5");
	if(perrito_laQueFiltra(pbuffer) == 0)
	{

	}
	else
	{
		puts("\n ERROR");
	}
	if(perrito_laQueFiltra(pbuffer2) == 0)
	{
		puts("\n BIIENNNN");

	}
	else
	{
		puts("\n ERROR PERO ACA TENIA QUE ANDAR");
	}
    printf("\n esta es la comida %.2f", pbuffer->cantidadComidaRacion);*/


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
						flagCarga = 1;
						printf("\n »» CARGA DE DATOS EXITOSA ");
					}
					else
					{
						printf("\n X No se han cargado los datos.");
					}
					break;
				case 2:
                  if( flagCarga == 1)
				   {
                	  if(controller_sortPerritos(perritoList) == 0)
                	  {
                		  controller_ListPerritos(perritoList);
                	  }
                	  else
                	  {
                		  printf("\n X No se ha realizado el ordenamiento.");
                	  }

				   }
                  else
					{
						printf("\n X No hay elementos cargados.");
					}

					break;
				case 3:
                    if(flagCarga == 1)
                    {
                    	if(controller_llMap(perritoList) == 0)
                    	{
                    		printf("\n »» Mapeo correcto.");
                    	}
                    }
                    else
                    {
                    	printf("\n x No hay elementos cargados");
                    }
					break;
				case 4:
                    if(flagCarga == 1)
                    {
                    	if(controller_ListPerritosPunto3(perritoList) != 0)
                    	{
                    		puts("\n x Error");
                    	}
                    }
                    else
				  {
					printf("\n x No hay elementos cargados");
				  }
					break;
				case 5:
					if(flagCarga == 1)
					{
						if(controller_llFilter(perritoList) == 0)
						{
							puts("\n ANDA");
						}
					}
					else
					{
						puts("\n x No hay elementos cargados.");
					}

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
