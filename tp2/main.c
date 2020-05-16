#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"



#include "validacion.h"
#define TAM 1000 //limite de empleados
#define TAMSEC 5




int main()
{

   // system("Color 1F");

    char seguir='s';
    char confirma;
    int flag = 1;

    int proximoId=100;

    eEmpleado lista[TAM];


    eSector sectores[]={{1,"Operaciones"}, {2,"RRHH"},{3,"Finanzas"},{4,"Compras"},{5,"Sistemas"} };

    inicializarEmpleados(lista,TAM);
    ordenarEmpleado(lista,TAM,sectores,TAMSEC);


     do
    {
        switch(menu())
        {

        case 1:
            if(altaEmpleado(proximoId, lista,TAM,sectores, TAMSEC))
            {
                proximoId++;
            }
            flag=0;
            break;


        case 2:

           if(flag == 0)
            {
            modificarEmpleado(lista,TAM,sectores,TAMSEC);
            }
            else{
            printf("Error primero debe dar de alta un empleado\n");
            }

            break;

        case 3:
           if(flag == 0)
            {
            bajaEmpleado(lista,TAM,sectores,TAMSEC);
            }
            else{
            printf("Error primero debe dar de alta un empleado\n");
            }

            break;

        case 4:

           if(flag == 0)
            {
            informar(lista,TAM,sectores,TAMSEC);
            }
            else
            {
            printf("Error primero debe dar de alta un empleado\n");
            }

            break;


        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma =='s')
            {
                seguir='n';
            }
        }
        system("pause");

    }
    while(seguir=='s');


return 0;

}



