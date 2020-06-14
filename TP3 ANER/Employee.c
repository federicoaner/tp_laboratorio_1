#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"





Employee* employee_new()
{

    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;

    }

    return newEmployee;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevo = employee_new();

    if (nuevo != NULL)
    {
        employee_setId(nuevo, atoi(idStr));
        employee_setNombre(nuevo, nombreStr);
        employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevo, atoi(sueldoStr));
    }

    return nuevo;
}

void employee_delete(Employee* unEmpleado)
{

    if(unEmpleado!=NULL)
    {

        free(unEmpleado);
        unEmpleado=NULL;
    }

}



void listarEmpleados(LinkedList* lista)
{

    printf("------------------------------------------\n");
    printf("  Id        Nombre  Hs Trabajadas  Sueldo\n");

    for (int i=0; i<ll_len(lista); i++)
    {
        listarEmpleado(lista, i);
    }

}


void listarEmpleado(LinkedList* lista, int index)
{
    Employee* auxEmployee = (Employee*) employee_new();
    int id;
    char nombre[128];
    int sueldo;
    int horasTrabajadas;


    if(lista != NULL && index >=0)
    {
    auxEmployee = ll_get(lista, index);
    employee_getId(auxEmployee,&id);
    employee_getNombre(auxEmployee,nombre);
    employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
    employee_getSueldo(auxEmployee,&sueldo);
    printf("%4d  %12s  %8d          %d \n", id, nombre, horasTrabajadas, sueldo);

    }

}


int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if (this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }


    return todoOk;

}

int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if (this != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if (this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}


int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if (this != NULL)
    {
        this->sueldo = sueldo;
        todoOk = 1;

    }

    return todoOk;

}



int employee_SearchIdIndex (LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    Employee* pEmployee;
    int auxID;

    for(int indice=0; indice <ll_len(pArrayListEmployee); indice ++)
    {
        pEmployee = ll_get(pArrayListEmployee, indice );

        if(employee_getId(pEmployee, &auxID) == 1 && auxID == id)
        {
            retorno = indice;
            //printf("\nindice: %d\n",indice);
        }
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int todoOK = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOK = 1;
    }
    return todoOK;
}


int employee_getSueldo(Employee* this,int* sueldo) {

    int todoOk = 0;

    if (this != NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }

    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horas) {

    int todoOk = 0;

    if (this != NULL && horas !=NULL)
    {
        *horas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre) {

    int todoOk = 0;

    if (this != NULL && nombre !=NULL) {

        strcpy(nombre,this->nombre );
        todoOk = 1;
    }
    return todoOk;

}


