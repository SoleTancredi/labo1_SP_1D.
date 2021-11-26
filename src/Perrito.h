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
    float cantidadComidaRacion;
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
int perrito_laQueMapea(void* pElement);
int perrito_setCantidadComida(Perrito* this,float cantidadComida);
int perrito_getCantidadComida(Perrito* this,float* cantidadComida);
void perrito_posterListPunto3();
int perrito_showListPunto3(LinkedList* this);
void perrito_showUnitPunto3(Perrito* this);
int perrito_laQueFiltra(void* pElement);
Perrito* perrito_newParametros3(char* idStr,char* nombreStr,char* pesoStr , char* edadStr, char* razaStr, char* cantComidaStr);





#endif /* PERRITO_H_ */
