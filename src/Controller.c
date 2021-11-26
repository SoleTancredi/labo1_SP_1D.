#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Perrito.h"
#include "parser.h"
#include "BibliotecaUtn2021.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_PerritoFromText(pFile, pArrayListPerrito) == 0)
		{
			retorno = 0;
		}
	}

    fclose(pFile);

    return retorno;
}



/** \brief Listar perritos
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPerritos(LinkedList* pArrayListPerritos)
{
	int retorno = -1;

	if(pArrayListPerritos != NULL)
	{
		if(perrito_showList(pArrayListPerritos) == 0)
		{
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortPerritos(LinkedList* pArrayListPerritos)
{
	int retorno = -1;

	if(pArrayListPerritos != NULL)
	{
		if(ll_sort(pArrayListPerritos, perrito_sortNames, 1) == 0)
		{

			retorno = 0;
		}
	}

    return retorno;
}
/** \brief Guarda los datos de los perritos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPerritos)
{
	int retorno = -1;
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];
	Perrito* pBuffer;

	if(path != NULL && pArrayListPerritos != NULL)
	{
		FILE* pFile;

		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			fprintf(pFile, " ID, NOMBRE, HORAS TRABAJADAS, SUELDO\n");
			for(int i = 0; i < ll_len(pArrayListPerritos); i++)
			{
				pBuffer = ll_get(pArrayListPerritos, i);
				perrito_getId(pBuffer, &id);
				perrito_getNombre(pBuffer, nombre);
				perrito_getPeso(pBuffer, &peso);
				perrito_getEdad(pBuffer, &edad);
				perrito_getRaza(pBuffer, raza);
				fprintf(pFile, "%d, %s, %.2f, %d, %s\n", id,nombre,peso, edad, raza);
				retorno =0;
			}

		}

		fclose(pFile);
	}

    return retorno;
}

/*
int controller_maxId(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = -1;
	int maxId = 0;
	int flag = 0;
	int idEmp;
	Employee* pEmpleado;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
	    {
			pEmpleado = ll_get(pArrayListEmployee, i);
		    employee_getId(pEmpleado, &idEmp);
		    if(flag == 0 ||idEmp > maxId)
		    {
		    	maxId = idEmp;
		    	flag = 1;
		    	retorno = 0;
		    }
		}
		*id = maxId;
	}

	return retorno;
}*/


