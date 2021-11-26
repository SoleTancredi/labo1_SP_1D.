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
	LinkedList* galgos = ll_newLinkedList();
	int option;
	int flagCarga = 0;
	Perrito* pbuffer;
	Perrito* pbuffer2;


	 do
	 {
		 printf("\n\t\t »»»»» MENU PRINCIPAL «««««\n");
		if( utn_getNumber(&option,""
				"\n[1] Cargar datos de perritos desde data.csv (modo texto)."
				"\n[2] Listar perritos ordenados de manera ascedente por nombre."
				"\n[3] Mapeo"
				"\n[4] Perritos con raciones de comida"
				"\n[5] Filter "
				"\n[6] Guardar en un nuevo archivo"
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
						if(controller_llFilter(perritoList,galgos) == 0)
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
					if(flagCarga == 1)
					{
						if(controller_saveAsText("galgosFlaquitos.csv", galgos) == 0)
						{
							printf("\n »» EL ARCHIVO SE GUARDO EXITOSAMENTE.");
						}
						else
						{
							printf("\n X No se pudo guardar el archivo en modo texto.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}

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
