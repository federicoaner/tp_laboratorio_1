#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LinkedList.h"
#include "tarjeta.h"
#include "validacion.h"




int OrderByApellido(void* a, void* b)
{
    int retorno;
    Tarjeta* tr1;
    Tarjeta* tr2;

    if(a != NULL && b != NULL)
    {
        tr1 = (Tarjeta*) a;
        tr2 = (Tarjeta*) b;
        retorno=strcmp(tr1->apellido,tr2->apellido);
    }

    return retorno;
}



/** \brief Carga los datos de las tarjetas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListTarjeta)
{
    int todoOk=0;

    FILE* pFile;

//    f=fopen("data.csv","r");

    if(path != NULL &&pArrayListTarjeta!=NULL )
    {


        pFile=fopen(path,"r");

        if(pFile!=NULL)
        {

            if(parser_TarjetaFromText(pFile,pArrayListTarjeta))
            {
                todoOk=1;

            }

            fclose(pFile);
        }

    }

    return todoOk;
}

/** \brief Carga los datos de las tarjetas desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListTarjeta)
{
    int todoOk=0;

    FILE* pFile;


    if(path != NULL &&pArrayListTarjeta!=NULL )
    {
        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            if(parser_TarjetaFromBinary(pFile,pArrayListTarjeta))
            {
                todoOk=1;
            }

            fclose(pFile);
        }

    }

    return todoOk;

}

/** \brief Alta Tarjetas
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_addTarjeta(LinkedList* pArrayListTarjeta)
{
    int todoOk=0;
    int dni;
    int cuotas;
    int monto;
    char apellido[128];
      char tarjeta[128];



    Tarjeta* auxTarjeta = (Tarjeta*) tarjeta_new();


    printf("\n------ALTA DE TARJETAS----------\n");

    //printf("ingrese Id: \n");
    //scanf("%d",&dni);
    utn_getEntero(&dni,3,"ingrese dni: ","error rango ingrese rango valido entre 8 / 50 millones (solo nros)",8000000,50000000);



    if (tarjeta_SearchIdIndex(pArrayListTarjeta, dni)==-1)
    {
        tarjeta_setDni(auxTarjeta,dni);



        utn_getCadena(apellido,128,3,"Ingrese apellido: ","ERROR. apellido invalido\n");
        tarjeta_setApellido(auxTarjeta,apellido);

        utn_getCadena(tarjeta,128,3,"Ingrese marca de tarjeta: ","ERROR. Nombre invalido\n");
        tarjeta_setTarjeta(auxTarjeta,tarjeta);


        utn_getEntero(&cuotas,3,"ingrese cuotas: ","\nerror ingrese rango entre 1-12\n",1,12);
        tarjeta_setCuotas(auxTarjeta,cuotas);


       utn_getEntero(&monto,3,"ingrese monto: ","\nerror ingrese rango entre 1000-150000\n",1000,150000);
       tarjeta_setMonto(auxTarjeta,monto);

        ll_add(pArrayListTarjeta,auxTarjeta);
        todoOk=1;

       /* if (ll_add(pArrayListEmployee,auxTarjeta)==0 && auxTarjeta!=NULL)
        {
            todoOk=1;
        }*/

    }
    else
    {
        printf(" Error existe una Tarjeta asignada con ese Dni \n");

    }

       if(!todoOk){
			free(auxTarjeta);
		}


    return todoOk;
}

void menuModificar(int* option)
{


   printf("\n\nElija el campo q desea modificar?: ");
   printf("\n1. apellido\n");
   printf("2. Nro de cuotas\n");
   printf("3. Monto\n");
   printf("Eliga una opcion: ");
   fflush(stdin);
   scanf("%d",option);
}


/** \brief Modificar datos de la tarjeta
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_editTarjeta(LinkedList* pArrayListTarjeta)
{
int todoOk = 1;
    int dni;
    int index;
    int opcion;
    char apellido[128];
    int cuotas;
    int monto;
    Tarjeta* auxTarjeta;

    system("cls");
    listarTarjetas(pArrayListTarjeta); //ultimo
    utn_getEntero(&dni,3,"\n\nIngrese Dni del cliente que desea modificar: ","ERROR. Dni invalido ingrese rango entre 8 milones y 50 millones \n",8000000,500000000);
    index = tarjeta_SearchIdIndex(pArrayListTarjeta,dni);
    auxTarjeta = (Tarjeta*) ll_get(pArrayListTarjeta, index);

    printf("------------------------------------------\n");
    printf("  Dni        Apellido        Tarjeta              Cuotas     Monto\n");
    listarTarjeta(pArrayListTarjeta,index);

    if(index == -1)
    {
        printf("\nNo hay empleados ingresados con ese Dni\n");
    }
    else
    {
        menuModificar(&opcion);
        switch(opcion)
        {
        case 1:
            fflush(stdin);
            utn_getCadena(apellido,128,3,"Ingrese apellido: ","ERROR. apellido invalido\n");
            tarjeta_setApellido(auxTarjeta,apellido);
            break;
        case 2:
            do
            {
                printf("Ingrese  nro de cuotas : ");
                fflush(stdin);
                scanf("%d",&cuotas);
            }while(cuotas < 0);
            tarjeta_setCuotas(auxTarjeta,cuotas);
            break;
        case 3:
            do
            {
                printf("Ingrese el monto: ");
                fflush(stdin);
                scanf("%d",&monto);
            }while(monto < 0);
            tarjeta_setMonto(auxTarjeta,monto);
            break;
        }
    }
    return todoOk;
}

/** \brief Listar Tarjetas
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_ListTarjeta(LinkedList* pArrayListTarjeta)
{
    listarTarjetas(pArrayListTarjeta);
    return 1;
}

/** \brief Ordenar Targetas
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_sortTarjeta(LinkedList* pArrayListTarjeta)
{

    ll_sort(pArrayListTarjeta,OrderByApellido,1);

    return 1;
}

/** \brief Guarda los datos de las tarjetas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListTarjeta)
{
    int todoOk=-1;
    FILE* f=fopen(path,"w");
    Tarjeta* auxTarjeta;



    if(f!=NULL && pArrayListTarjeta != NULL)
    {
        fprintf(f,"dni,apellido,tarjeta,cuotas,monto\n");

        for (int i=0; i<ll_len(pArrayListTarjeta) ; i++ )
        {

            auxTarjeta = ll_get(pArrayListTarjeta,i);

            fprintf(f,"%d,%s,%s,%d,%d\n",auxTarjeta->dni,auxTarjeta->apellido,auxTarjeta->tarjeta,auxTarjeta->cuotas,auxTarjeta->monto );
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

/** \brief Guarda los datos de las tarjetas en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListTarjeta LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListTarjeta)
{
    int todoOk = 0;
    int cant;
    Tarjeta* temp = (Tarjeta*) tarjeta_new();
    FILE* f = fopen(path, "wb");

    if (path != NULL && pArrayListTarjeta != NULL && f != NULL && temp != NULL )
    {


        for (int i=0; i<ll_len(pArrayListTarjeta); i++)
        {
            temp = ll_get(pArrayListTarjeta, i);
            cant = fwrite(temp, sizeof(Tarjeta), 1, f );


            if (cant<1)
            {
                printf("OCURRIO UN ERROR GUARDANDO EL ARCHIVO\n");
                return todoOk;
            }
        }

        todoOk = 1;
        printf("ARCHIVO GUARDADO\n");
    }



    return todoOk;
}

int buscarId(LinkedList* lista, int dni)
{

    int retorno=0;
    /* if(lista!=NULL && dni>=0){

        for (int i=0;i>ll_len(lista);i++ ){

         lista[i]->dni==dni){

             retorno=i;

             break;
         }

     }


     }*/

    return retorno;

}


int controller_removeTarjeta(LinkedList* pArrayListTarjeta)
{

    int todoOk=0;
    int dni;
    int index;
    Tarjeta* auxTarjeta = (Tarjeta*) tarjeta_new();
    char confirma ='s';

    listarTarjetas(pArrayListTarjeta);
    printf("\n------BAJA TARJETA----------\n\n");

    printf("ingrese Dni: ");
    scanf("%d",&dni);

    if (tarjeta_SearchIdIndex(pArrayListTarjeta, dni)!=-1)
    {

        auxTarjeta->dni=dni;
        index=tarjeta_SearchIdIndex(pArrayListTarjeta,dni);

        printf("\n\n\nDNI             Apellido  Tarjeta             Cuotas         Monto\n");
        printf("----------------------------------------------------------------------------\n");
        listarTarjeta(pArrayListTarjeta,index);

        printf("confirma baja? s/n  s para confirmar\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            ll_remove(pArrayListTarjeta, index);
            tarjeta_delete(auxTarjeta);
            todoOk=1;
            printf("\nBaja Realizada con exito!!!!\n");

        }

    }
    else

    {
        printf(" Error no hay un cliente con ese dni\n");

    }


    return todoOk;
}





