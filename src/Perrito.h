/*
 * Perrito.h
 *
 *  Created on: 26 nov. 2021
 *      Author: sole
 */

#ifndef PERRITO_H_
#define PERRITO_H_
#define TAM_CHAR 21
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[TAM_CHAR];
    float peso;
    int edad;
    char raza[TAM_CHAR];
}Perrito;

Perrito* perrito_new();
Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr);
void perrito_delete(Perrito* this);
int perrito_setId(Perrito* this,int id);
int perrito_getId(Perrito* this,int* id);
int perrito_setNombre(Perrito* this,char* nombre);
int perrito_getNombre(Perrito* this,char* nombre);
int perrito_setPeso(Perrito* this,float peso);
int perrito_getPeso(Perrito* this,float* peso);
int perrito_setEdad(Perrito* this,int edad);
int perrito_getEdad(Perrito* this,int* edad);
int perrito_setRaza(Perrito* this,char* raza);
int perrito_getRaza(Perrito* this,char* raza);
void perrito_showUnit(Perrito* this);
int perrito_showList(LinkedList* this);
void perrito_posterList();
int perrito_sortNames(void* thisOne, void* thisTwo);





#endif /* PERRITO_H_ */
