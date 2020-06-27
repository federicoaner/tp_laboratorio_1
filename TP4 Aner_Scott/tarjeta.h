#include "parser.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int dni;
    char apellido[128];
    char tarjeta[128];
    int cuotas;
    int monto;
}Tarjeta;



Tarjeta* tarjeta_new();
Tarjeta* tarjeta_newParametros(char* dniStr,char* apellidoStr,char* tarjetaStr,char* cuotasStr, char* montoStr);
void tarjeta_delete(Tarjeta* unEmpleado);

int tarjeta_setDni(Tarjeta* this,int dni);
int tarjeta_getDni(Tarjeta* this,int* dni);

int tarjeta_setApellido(Tarjeta* this,char* apellido);
int tarjeta_getApellido(Tarjeta* this,char* apellido);

int tarjeta_setTarjeta(Tarjeta* this,char* tarjeta);
int tarjeta_getTarjeta(Tarjeta* this,char* tarjeta);

int tarjeta_setCuotas(Tarjeta* this,int cuotas);
int tarjeta_getCuotas(Tarjeta* this,int* cuotas);

int tarjeta_setMonto(Tarjeta* this,int monto);
int tarjeta_getMonto(Tarjeta* this,int* monto);

void listarTarjeta(LinkedList* lista, int index);
void listarTarjetas(LinkedList* lista);

int tarjeta_SearchIdIndex (LinkedList* pArrayListTarjeta, int dni);






#endif // employee_H_INCLUDED
