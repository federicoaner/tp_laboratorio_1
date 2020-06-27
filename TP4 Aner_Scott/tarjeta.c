#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tarjeta.h"
#include "LinkedList.h"





Tarjeta* tarjeta_new()
{

    Tarjeta* newTarjeta = (Tarjeta*) malloc(sizeof(Tarjeta));

    if (newTarjeta != NULL)
    {
        newTarjeta->dni = 0;
        strcpy(newTarjeta->apellido," ");
        strcpy(newTarjeta->tarjeta," ");
        newTarjeta->cuotas = 0;
        newTarjeta->monto = 0;

    }

    return newTarjeta;

}

Tarjeta* tarjeta_newParametros(char* dniStr,char* apellidoStr,char* tarjetaStr,char* cuotasStr, char* montoStr)
{


    Tarjeta* nuevo = tarjeta_new();

    if (nuevo != NULL)
    {
        tarjeta_setDni(nuevo, atoi(dniStr));
        tarjeta_setApellido(nuevo, apellidoStr);
         tarjeta_setTarjeta(nuevo, tarjetaStr);
        tarjeta_setCuotas(nuevo, atoi(cuotasStr));
        tarjeta_setMonto(nuevo, atoi(montoStr));
    }

    return nuevo;
}

void tarjeta_delete(Tarjeta* unaTarjeta)
{

    if(unaTarjeta!=NULL)
    {

        free(unaTarjeta);
        unaTarjeta=NULL;
    }

}



void listarTarjetas(LinkedList* lista)
{

    printf("------------------------------------------\n");
    printf("  Dni          Apellido     Tarjeta        Nro de Cuotas    Monto\n");

    for (int i=0; i<ll_len(lista); i++)
    {
        listarTarjeta(lista, i);
    }

}


void listarTarjeta(LinkedList* lista, int index)
{
    Tarjeta* auxTarjeta = (Tarjeta*) tarjeta_new();
    int dni;
    char apellido[128];
    char tarjeta[128];
    int cuotas;
    int monto;


    if(lista != NULL && index >=0)
    {
    auxTarjeta = ll_get(lista, index);
    tarjeta_getDni(auxTarjeta,&dni);
    tarjeta_getApellido(auxTarjeta,apellido);
    tarjeta_getTarjeta(auxTarjeta,tarjeta);
    tarjeta_getCuotas(auxTarjeta,&cuotas);
    tarjeta_getMonto(auxTarjeta,&monto);
    printf("%4d   %12s     %-18s    %2d         %d \n", dni, apellido,tarjeta, cuotas, monto);

    }

}


int tarjeta_setDni(Tarjeta* this,int dni)
{
    int todoOk = 0;

    if (this != NULL)
    {
        this->dni = dni;
        todoOk = 1;
    }

    return todoOk;

}

int tarjeta_setApellido(Tarjeta* this,char* apellido)
{

    int todoOk = 0;

    if (this != NULL)
    {
        strcpy(this->apellido, apellido);
        todoOk = 1;
    }

    return todoOk;

}

int tarjeta_setTarjeta(Tarjeta* this,char* tarjeta)
{

    int todoOk = 0;

    if (this != NULL)
    {
        strcpy(this->tarjeta, tarjeta);
        todoOk = 1;
    }

    return todoOk;

}


int tarjeta_setCuotas(Tarjeta* this,int cuotas)
{

    int todoOk = 0;

    if (this != NULL)
    {
        this->cuotas = cuotas;
        todoOk = 1;
    }
    return todoOk;

}


int tarjeta_setMonto(Tarjeta* this,int monto)
{

    int todoOk = 0;

    if (this != NULL)
    {
        this->monto = monto;
        todoOk = 1;

    }

    return todoOk;

}



int tarjeta_SearchIdIndex (LinkedList* pArrayListTarjeta, int dni)
{
    int retorno = -1;
    Tarjeta* pTarjeta;
    int auxDni;


    for(int indice=0; indice <ll_len(pArrayListTarjeta); indice ++)
    {
        pTarjeta = ll_get(pArrayListTarjeta, indice );

        if(tarjeta_getDni(pTarjeta, &auxDni) == 1 && auxDni == dni)
        {
            retorno = indice;
            //printf("\nindice: %d\n",indice);
        }
    }
    return retorno;
}


int tarjeta_getDni(Tarjeta* this,int* dni)
{
    int todoOK = -1;

    if(this != NULL && dni != NULL)
    {
        *dni = this->dni;
        todoOK = 1;
    }
    return todoOK;
}


int tarjeta_getMonto(Tarjeta* this,int* monto) {

    int todoOk = 0;

    if (this != NULL && monto !=NULL)
    {
        *monto = this->monto;
        todoOk = 1;
    }

    return todoOk;

}

int tarjeta_getCuotas(Tarjeta* this,int* cuotas) {

    int todoOk = 0;

    if (this != NULL && cuotas !=NULL)
    {
        *cuotas = this->cuotas;
        todoOk = 1;
    }

    return todoOk;

}

int tarjeta_getApellido(Tarjeta* this,char* apellido) {

    int todoOk = 0;

    if (this != NULL && apellido !=NULL) {

        strcpy(apellido,this->apellido );
        todoOk = 1;
    }
    return todoOk;

}

int tarjeta_getTarjeta(Tarjeta* this,char* tarjeta) {

    int todoOk = 0;

    if (this != NULL && tarjeta !=NULL) {

        strcpy(tarjeta,this->tarjeta );
        todoOk = 1;
    }
    return todoOk;


}



