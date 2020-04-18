
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int sumar(int a, int b)
{
    int rta;

    rta = a+b;

    return rta;
}

int restar (int a, int b)
{
    int rta;

    rta = a-b;

    return rta;
}

float dividir (int a, int b)
{
    float rta;

    rta =(float) a/b;

    if(b==0)
        {
        printf("error no se puede dividir por cero\n");
        }

    return rta;
}

int multiplicar (int a, int b)
{
 int rta;

    rta = a*b;

    return rta;
}

int factorizar(int a)
{
      int fact=1;
    //int i;
  for(int i =1; i<=a; i++)
        {
        fact=fact*i;
        }
    return fact;
}

int MenuOpciones()
{
    int opcion;
    system("cls");
    printf("****** BIENVENIDO******\n\n");
    printf("***Menu de opciones***\n\n");
    printf("1-Ingrese el primer operando\n");
    printf("2-Ingrese el segundo operando\n");
    printf("3-Calcular todas las operaciones\n");
    printf("4-Resultados\n");
    printf("5-Salir\n\n");


    printf("Indique opcion: ");
    scanf("%d",&opcion);

    return opcion;
}


