#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "tarjeta.h"

/** \brief Parsea los datos los datos de la tarjeta desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_TarjetaFromText(FILE* pFile , LinkedList* pArrayListTarjeta)
{
    int todoOk = 0;
    int cant;
    Tarjeta* auxiliar = (Tarjeta*) tarjeta_new();

    if (pFile == NULL || pArrayListTarjeta == NULL)
    {

        return todoOk;

    }

    char buffer[5][128];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3] ,buffer[4]);

        if (cant == 5)
        {
            auxiliar = tarjeta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

            if (auxiliar != NULL)
            {

                ll_add(pArrayListTarjeta, auxiliar);

            }
        }

    todoOk = 1;

    }

    return todoOk;
}

/** \brief Parsea los datos los datos de las tarjetas desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_TarjetaFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;

    if (pFile == NULL || pArrayListEmployee == NULL)
    {

        return todoOk;
    }

    while (!feof(pFile))
    {

        Tarjeta* aux = (Tarjeta*) tarjeta_new();

        if (aux != NULL)
        {
            cant = fread(aux, sizeof(Tarjeta), 1, pFile);

            if (cant == 1)
            {
                ll_add(pArrayListEmployee, aux);
                todoOk = 1;
            }

        }

    }

    return todoOk;

}
