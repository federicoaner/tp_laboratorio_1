#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacion.h"

#include "validacion.h"
#include "empleados.h"
#define TAM 1000 //limite de empleados
#define TAMSEC 5




int menu()
{
	int opcion;



	system("cls");

	printf("** ABM Empleados ***\n\n");

	printf("1.Alta empleado.\n");
	printf("2.Modificar empleado.\n");
	printf("3.Baja a un empleado.\n");
	printf("4.Informar.\n");
	printf("5.Salir.\n\n");
	utn_getEntero(&opcion,3,"Ingrese opcion: ","\nerror ingrese opcion valida\n",1,5);

	return opcion;

}

void inicializarEmpleados(eEmpleado vec[],int tam)
{

    for(int i=0; i<tam; i++)
    {
     vec[i].isEmpty=1;
    }

}

void mostrarEmpleado(eEmpleado x,eSector sectores[],int tamSec)
{
    char nombreSector[20];
    cargarDescripcionSector(nombreSector, x.idSector, sectores,tamSec);

    printf("%d    %10s   %10s       %6.2f      %10s\n",x.id,x.nombre,x.apellido,x.sueldo,nombreSector);

}

void mostrarEmpleados(eEmpleado vec[],int tam, eSector sectores[],int tamSec)
{
    system("cls");
    int flag=0;

    printf("************LISTADO DE EMPLEADOS***************\n\n");
    printf("Id        Nombre      Apellido        Sueldo       Sector\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamSec);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("*****No hay empleados q listar******\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)  // busca si hay lugar libre //devuelve -1 si no hay lugar
{

    int indice=-1;


    for(int i=0; i<tam; i++)
    {

        if (vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


int buscarEmpleado(int id,eEmpleado vec[],int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {

        if (vec[i].id == id && vec[i].isEmpty == 0)  //ve si en esa lista de empleados el id q le mande esta ocupado
        {
            indice=i;
            break; //se frena una vez q lo encontramos
        }
    }

    return indice;

}


int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[],int tamSec)
{

    int todoOk=0;
    int indice = buscarLibre(vec, tam);

    eEmpleado auxEmpleado;

    system("cls");
    printf("*********ALTA EMPLEADO**************\n\n");

    if(indice == -1) //hay lugar?
    {
        printf("Sistema completo\n\n");
    }

    else  //si hay lugar vengo aca
    {


        auxEmpleado.id=idx;
        utn_getCadena(auxEmpleado.nombre,51,2,"ingrese el nombre del empleado: ","\nerror ingrese solo letras\n");
        utn_getCadena(auxEmpleado.apellido,51,2,"ingrese el apellido del empleado: ","\nerror ingrese solo letras\n");
        utn_getFlotante (&auxEmpleado.sueldo,2,"ingrese el salario: ","\nerror ingrese salario valido\n",0,2000000);


        mostrarSectores(sectores, tamSec);
        utn_getEntero(&auxEmpleado.idSector,3,"Ingrese sector : ","\nerror ingrese opcion valida\n",1,5);

        auxEmpleado.isEmpty=0;


            vec[indice] =auxEmpleado; //copio al vector el empleado nuevo
            todoOk=1;
       // } //else interior

        printf("\n*****************");
        printf("\nCARGA EXITOSA!!!\n");
        printf("******************\n\n");

    } //else exterior
    return todoOk;
} //fin funcion



void mostrarSectores( eSector sectores[], int tam)
{

    printf("\n\n************Sectores***************\n\n ");
    printf("Id   Descripcion    \n\n");

    for(int i=0; i<tam; i++)
    {
        printf("  %d    %10s\n",sectores[i].id,sectores[i].descripcion);
    }

}


int cargarDescripcionSector(char descripcion[],int id, eSector sectores[], int tam ){ // busca los ids y muestra la descripcion del sector

    int todoOk=0;

    for (int i=0;i<tam;i++){
        if(sectores[i].id==id){
           strcpy(descripcion, sectores[i].descripcion);
        todoOk=1;
        }
    }

    return todoOk;
}


void bajaEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec)
{

    int indice;
    int id;
    char confirma;

    system("cls");
    printf("*********BAJA EMPLEADO**************\n\n");

    utn_getEntero(&id,3,"Ingrese id : ","\nerror ingrese numeros\n",1,20000);

    indice=buscarEmpleado(id,vec,tam);


    if(indice==-1) // el id  ya esta?
    {
        printf("no hay registro de un empleado con ese id: %d\n",id);
    }
    else
    {
        mostrarEmpleado(vec[indice],sectores,tamSec);
        printf("confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("se ha cancelado la operacion\n\n");
        }
    }//else exterior
}


void modificarEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec)
{

    int indice;
    int id;
    char confirma;
    //float nuevoSueldo;
    //char nuevoNombre[51];

    system("cls");
    printf("*********MODIFICAR EMPLEADO**************\n\n");


    utn_getEntero(&id,3,"Ingrese id : ","\nerror ingrese numeros\n",1,20000);

    indice=buscarEmpleado(id,vec,tam);


    if(indice==-1) // el id  ya esta?
    {
        printf("no hay registro de un empleado con ese id: %d\n",id);
    }
    else
    {

        mostrarEmpleado(vec[indice], sectores,tamSec);


        printf("quiere modificar empleado? 's' para continuar: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            utn_getCadena(vec[indice].nombre,51,2,"ingrese el nuevo nombre: ","\nerror ingrese solo letras\n");
            utn_getCadena(vec[indice].apellido,51,2,"ingrese el nuevo apellido : ","\nerror ingrese solo letras\n");
            utn_getFlotante (&vec[indice].sueldo,2,"ingrese el salario: ","\nerror ingrese salario valido\n",0,2000000);
            utn_getEntero(&vec[indice].idSector,2,"Ingrese sector \n1-Operaciones \n2-RRHH \n3-Finanzas \n4-Compras \n5-Sistemas \nsector: ","\nerror ingrese sector valido\n",1,5);


            printf("se ha actualizado el empleado con exito\n\n");
        }
        else
        {
            printf("se ha cancelado la operacion\n\n");
        }
    }//else exterior

} //fin funcion

void informar(eEmpleado vec[],int tam, eSector sectores[],int tamSec){

    char seguir='s';
    char confirma;

do
    {
        switch(submenuInformar())
        {

        case 'a':
            ordenarEmpleado(vec,tam,sectores,tamSec);
            mostrarEmpleados(vec,tam,sectores,tamSec);
            break;


        case 'b':
          informarPromedios (vec,tam);
            break;



        case 'c':
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





}

 int submenuInformar()
{

    char opcion;
    system("cls");
    printf("*********MENU INFORMES***********\n\n");
    printf("a. ordenar empleados\n");
    printf("b. promedio \n");
    printf("c. Salir\n\n");

    utn_getCadena(&opcion,3,3,"Ingrese opcion: ","\nerror ingrese opcion valida\n");

    return opcion;
}

void ordenarEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec)
{

    eEmpleado auxEmpleado;
    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
             if(vec[i].idSector<vec[j].idSector)
                // if(vec[i].id>vec[j].id) //  ordenar por id
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
            else if(vec[i].idSector<vec[j].idSector && strcmp(vec[i].apellido,vec[j].apellido)>0) // ordenar x sector
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
        }
    }

}

void informarPromedios(eEmpleado vec[],int tam)
{


    float total=0;
    int  contadorEmpleados = 0;
    float promedio;
    int contadorMayorPromedio =0;


    system("cls");
    printf("************total sueldos***************\n\n ");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            total=total+vec[i].sueldo;
            contadorEmpleados++;
        }
    }

    	promedio= total/ (float) contadorEmpleados ;

    	for(int i = 0; i < tam; i++)
	{
		if(vec[i].isEmpty==0)
		{
			if(vec[i].sueldo > promedio)
			{
				contadorMayorPromedio++;
			}

		}
	}

        printf(" El total de los sueldos es: %.2f  pesos\n",total);
        printf(" El promedio es: %.2f  pesos\n",promedio);
        printf(" La cantidad de empleados que superan el salario promedio es: %d \n",contadorMayorPromedio);


}


