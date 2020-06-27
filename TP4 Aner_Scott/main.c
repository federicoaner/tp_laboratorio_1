#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "tarjeta.h"


int menu();

int main()
{

    char seguir='s';
    char confirma;


    //int option ;
    LinkedList* listaTarjetas = ll_newLinkedList();
    LinkedList* lista2 = ll_newLinkedList();




    do
    {
        switch(menu())
        {
        case 1:
            if( controller_loadFromText("data.csv",listaTarjetas))
            {
                printf("tarjetas cargados con exito\n");
            }
            else
            {
                printf("Problema para cargar el archivo\n");
            }
            break;


        case 2:
            if( controller_loadFromBinary("data.bin",listaTarjetas))
            {
                printf("tarjetas cargados con exito\n");
            }
            else
            {
                printf("Problema para cargar el archivo, Puede q no exista!!!\n");
            }
            break;

        case 3:

            if(controller_addTarjeta(listaTarjetas))
            {
                printf(" Carga exitosa!!!!!\n");

            }
            else
            {
                printf("No se pudo realizar la carga");
            }

            break;

        case 4:

            controller_editTarjeta(listaTarjetas);
            /*
            printf("cant: %d\n",ll_len(listaTarjetas)); // cantidad lista tarjetas
            Employee* p1=employee_newParametros("1234","juan","34","2000");
            ll_add(listaTarjetas,p1);
            controller_ListEmployee(listaTarjetas);
            printf("------------------");
            employee_delete(p1);
            ll_clear(listaTarjetas);
            controller_ListEmployee(listaTarjetas);
            printf("cant: %d\n",ll_len(listaTarjetas));
            */



            //Employee* p1=employee_newParametros("1234","juan","34","2000");

            /*listarEmpleado(listaTarjetas,1);
            if(ll_add(listaTarjetas,p1)==0){
             printf("alta exitosa\n\n");
            }*/


            break;

        case 5:

            controller_removeTarjeta(listaTarjetas);

            break;


        case 6:

            if (ll_isEmpty(listaTarjetas)==0)
            {
                controller_ListTarjeta(listaTarjetas);
            }
            else
            {
                printf("no existe ninguna lista para mostrar\n");
            }
            break;



        case 7:
            if(controller_sortTarjeta(listaTarjetas))
            {
                printf("\nTarjetas ordenadas exitosamente!\n");
            }
            else
            {
                printf("Error");
            }
            break;


        case 8:
            controller_saveAsText("data.csv",listaTarjetas);
            break;

        case 9:
            controller_saveAsBinary("data.bin",listaTarjetas);
            break;


        case 10:
            if (ll_isEmpty(listaTarjetas)==0)
            {

                if (ll_clear(listaTarjetas)==0)
                {
                    printf("La lista se vacio correctamente\n");
                }

            }
            else
            {

                printf("No existe ninguna lista q vaciar\n");
            }
            break;


        case 11:
            if (ll_isEmpty(listaTarjetas)==0)
            {
                if ( (lista2 = ll_clone(listaTarjetas)) )
                {
                    printf("se realizo una copia de la lista\n");
                }

            }
            else
            {
                printf("No existe ninguna lista para copiar\n");
            }

            break;


        case 12:
            if (ll_isEmpty(lista2)==0)
            {
                controller_ListTarjeta(lista2);
            }

            else
            {
                printf("no existe ninguna copia de seguridad \n");
            }

            break;


        case 13:
            if (ll_isEmpty(lista2)==0)
            {
                controller_saveAsText("dataCopia.csv",lista2);
            }
            else
            {
                printf("no existe ninguna copia de seguridad \n");
            }

            break;


        case 14:
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



    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("------------------------------------------------\n");
    printf("--------SISTEMA ALTA DE PAGOS CON TARJETA-------\n");
    printf("1. Cargar archivo csv\n");
    printf("2. Cargar desde binario\n");
    printf("3. Cargar un pago\n");
    printf("4. Modificar un pago\n");
    printf("5.  Dar de Baja un pago-\n");
    printf("6. Listar Pagos\n");
    printf("7. Ordenar por Apellido Cliente\n");
    printf("8. Guardar archivo csv\n");
    printf("9. Guardar archivo binario\n");
    printf("10. Vaciar Lista\n");
    printf("11. Realizar copia de seguridad de la lista\n");
    printf("12. Listar copia de seguridad\n");
    printf("13. Guardar copia de seguridad como cvs\n");
    printf("14. Salir\n");
    printf("------------------------------------------------\n");
    printf("------------------------------------------------\n\n\n");


    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;

}



