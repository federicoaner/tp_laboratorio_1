#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacion.h"




int OrderByName(void* a, void* b)
{
    int retorno;
    Employee* emp1;
    Employee* emp2;

    if(a != NULL && b != NULL)
    {
        emp1 =(Employee*) a;
        emp2 =(Employee*) b;

        retorno=strcmp(emp1->nombre,emp2->nombre);
    }

    return retorno;
}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* pFile;

    if(path != NULL &&pArrayListEmployee!=NULL )
    {
        pFile=fopen(path,"r");

        if(pFile!=NULL)
        {

            if(parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                todoOk=1;
            }

        fclose(pFile);
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* pFile;


    if(path != NULL &&pArrayListEmployee!=NULL )
    {
        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                todoOk=1;
            }

            fclose(pFile);
        }
    }

    return todoOk;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int id;
    int horas;
    int sueldo;
    char nombre[128];


    Employee* auxEmployee = (Employee*) employee_new();


    printf("\n------ALTA EMPLEADO----------\n");

    utn_getEntero(&id,3,"ingrese id: ","error ingrese solo nros",1,5000);



    if (employee_SearchIdIndex(pArrayListEmployee, id)==-1)
    {
        employee_setId(auxEmployee,id);


        utn_getCadena(nombre,128,3,"Ingrese nombre: ","ERROR. Nombre invalido\n");
        employee_setNombre(auxEmployee,nombre);


        utn_getEntero(&horas,3,"ingrese horas trabajadas: ","\nerror ingrese rango entre 1-500\n",1,500);
        employee_setHorasTrabajadas(auxEmployee,horas);


       utn_getEntero(&sueldo,3,"ingrese sueldo: ","\nerror ingrese rango entre 10000-150000\n",10000,150000);
       employee_setSueldo(auxEmployee,sueldo);

        ll_add(pArrayListEmployee,auxEmployee);
        todoOk=1;

       /* if (ll_add(pArrayListEmployee,auxEmployee)==0 && auxEmployee!=NULL)
        {
            todoOk=1;
        }*/

    }
    else
    {
        printf(" Error hay un empleado con ese Id\n");

    }

       if(!todoOk){
			free(auxEmployee);
		}


    return todoOk;
}

void menuModificar(int* option)
{


   printf("\n\nElija el campo q desea modificar?: ");
   printf("\n1. Nombre\n");
   printf("2. Horas trabajadas\n");
   printf("3. Sueldo\n");
   printf("Eliga una opcion: ");
   fflush(stdin);
   scanf("%d",option);
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
int todoOk = 1;
    int id;
    int index;
    int opcion;
    char nombre[128];
    int horasTrab;
    int sueldo;
    Employee* auxEmployee;
    char confirma='s';

    system("cls");
    utn_getEntero(&id,3,"Ingrese ID del empleado que desea modificar: ","ID invalido ingrese valor del 1 al 3000\n",1,3000);
    index = employee_SearchIdIndex(pArrayListEmployee,id);
    auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);

    printf("------------------------------------------\n");
    printf("  Id        Nombre  Hs Trabajadas  Sueldo\n");
    printf("------------------------------------------\n");


    listarEmpleado(pArrayListEmployee,index);

    if(index == -1)
    {
        printf("\nNo hay empleados ingresados con ese ID\n");
    }
    else
    {

        printf("\ndesea modificar el empleado? s/n  s para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {

        menuModificar(&opcion);
        switch(opcion)
        {

            case 1:
            fflush(stdin);
            utn_getCadena(nombre,128,3,"Ingrese nombre: ","ERROR. Nombre invalido\n");
            employee_setNombre(auxEmployee,nombre);
            break;

            case 2:
            utn_getEntero(&horasTrab,3,"ingrese hs trabajas: ","Error",1,600);
            employee_setHorasTrabajadas(auxEmployee,horasTrab);
            break;

            case 3:
            utn_getEntero(&sueldo,3,"\ningrese el sueldo a modificar: ","\nError ingrese valor entre 10000-200000 $",10000,200000);
            employee_setSueldo(auxEmployee,sueldo);
            break;

        }
      }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    listarEmpleados(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    ll_sort(pArrayListEmployee,OrderByName,1);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* f=fopen(path,"w");
    int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
    Employee* auxEmployee;



    if(f!=NULL && pArrayListEmployee != NULL)
    {
        fprintf(f,"id,nombre,horasTrabajadas trabajas,sueldo\n");

        for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
        {

            auxEmployee = ll_get(pArrayListEmployee,i);

            employee_getId(auxEmployee, &id);
            employee_getNombre(auxEmployee, nombre);
            employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
            employee_getSueldo(auxEmployee, &sueldo);


            fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo );
            todoOk=1;

        }

        printf("\nArchivo guardado con exito!!!\n");

    }

    else
    {
        printf("error al guardar");
    }

    fclose(f);


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* temp = (Employee*) employee_new();
    FILE* f = fopen(path, "wb");

    if (path != NULL && pArrayListEmployee != NULL && f != NULL && temp != NULL )
    {


        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            temp = ll_get(pArrayListEmployee, i);
            cant = fwrite(temp, sizeof(Employee), 1, f );


            if (cant<1)
            {
                printf("Error\n");
                return todoOk;
            }
        }

        todoOk = 1;
        printf("Archivo guardado con exito\n");
    }



    return todoOk;
}

int buscarId(LinkedList* lista, int id)
{

    int retorno=0;


    return retorno;

}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    int id;
    int index;
    Employee* auxEmployee = (Employee*) employee_new();
    char confirma ='s';


    printf("\n------BAJA EMPLEADO----------\n\n");


        utn_getEntero(&id,3,"ingrese id: ","error ingrese solo nros",1,5000);


    if (employee_SearchIdIndex(pArrayListEmployee, id)!=-1)
    {
        employee_setId(auxEmployee,id);

        index=employee_SearchIdIndex(pArrayListEmployee,id);

        printf("\n\n\nID        NOMBRE     HS/TRABAJADAS   SUELDO\n");
        printf("------------------------------------------------\n");
        listarEmpleado(pArrayListEmployee,index);

        printf("confirma baja? s/n  s para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            ll_remove(pArrayListEmployee, index);
            employee_delete(auxEmployee);
            todoOk=1;
            printf("\nBaja Realizada con exito!!!!\n");

        }

    }
    else

    {
        printf(" Error no hay un empleado con ese Id\n");

    }


    return todoOk;
}





