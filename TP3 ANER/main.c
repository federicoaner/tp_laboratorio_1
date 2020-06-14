#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{

    char seguir='s';
    char confirma;
    //int flagCarga=0;


    //int option ;
    LinkedList* listaEmpleados = ll_newLinkedList();



    do
    {
        switch(menu())
        {
        case 1:

                if( controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("empleados cargados con exito\n");

                }
                else
                {
                    printf("Problema para cargar el archivo\n");
                }


            break;


        case 2:
            if( controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("empleados cargados con exito\n");
            }
            else
            {
                printf("Problema para cargar el archivo, Puede q no exista!!!\n");
            }
            break;

        case 3:

            if(controller_addEmployee(listaEmpleados))
            {
                printf("ALTA EXITOSA!!!!!\n");

            }
            else
            {
                printf("No se pudo realizar el alta");
            }

            break;

        case 4:

            controller_editEmployee(listaEmpleados);
            /*
            printf("cant: %d\n",ll_len(listaEmpleados)); // cantidad lista empleados
            Employee* p1=employee_newParametros("1234","juan","34","2000");
            ll_add(listaEmpleados,p1);
            controller_ListEmployee(listaEmpleados);
            printf("------------------");
            employee_delete(p1);
            ll_clear(listaEmpleados);
            controller_ListEmployee(listaEmpleados);
            printf("cant: %d\n",ll_len(listaEmpleados));
            */



            //Employee* p1=employee_newParametros("1234","juan","34","2000");

            /*listarEmpleado(listaEmpleados,1);
            if(ll_add(listaEmpleados,p1)==0){
             printf("alta exitosa\n\n");
            }*/


            break;

        case 5:

            controller_removeEmployee(listaEmpleados);

            break;


        case 6:

                controller_ListEmployee(listaEmpleados);
                break;
                system("pause");


        case 7:
            if(controller_sortEmployee(listaEmpleados))
            {
                printf("\nEmpleados ordenados exitosamente!\n");
            }
            else
            {
                printf("Error");
            }
            break;

        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;

        case 9:
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;


        case 10:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma =='s')
            {
                seguir='n';
            }

            break;
        }
        system("pause");

    }
    while(seguir=='s');



    //ll_deleteLinkedList(listaEmpleados);

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("-------------------------\n");
    printf("-----MENU DE OPCIONES----\n");
    printf("-------------------------\n");
    printf("1. Cargar archivo csv\n");
    printf("2. Cargar desde binario\n");
    printf("3. Alta empleado\n");
    printf("4. Modificar empleados\n");
    printf("5. Baja empleado-\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar por Nombre\n");
    printf("8. Guardar archivo csv\n");
    printf("9. Guardar archivo binario\n");
    printf("10. Salir\n");
    printf("-------------------------\n");
    printf("-------------------------\n\n\n");


    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}



