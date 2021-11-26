#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perrito.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito)
{
	int retorno = -1;
	char strId[21];
	char strNombre[21];
	char strPeso[21];
	char strEdad[21];
	char strRaza[21];
	int leidos;
	Perrito* pNewPerrito;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strPeso,strEdad, strRaza);

		do
		{
			leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strPeso,strEdad, strRaza);
			if(leidos == 5)
			{
				pNewPerrito = perrito_newParametros(strId, strNombre, strPeso, strEdad, strRaza);
				ll_add(pArrayListPerrito,pNewPerrito);
				retorno = 0;
			}
			else
			{
				printf("\n »» Error en la lectura.");
				retorno = -1;
				break;
			}

		}while(!feof(pFile));
	}
    return retorno;
}


