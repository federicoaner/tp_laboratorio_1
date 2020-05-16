#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct{

int id; //PK
char descripcion[20];

}eSector;

#endif // EMPLEADOS_H_INCLUDED


int menu();



/** \brief  recorre el vector de empleados y asigna 1 a isEmpty a cada indice
 *
 * \param vector de empleados
 * \param tamanio del vector
 */

void inicializarEmpleados(eEmpleado vec[],int tam);




/** \brief Funcion que muestra descripcion nombre apellido salario sector
 *
 * \param vector de empleados
 * \param vector sectores
 * \param tamanio sector

 */

void mostrarEmpleado(eEmpleado x,eSector sectores[],int tamSec);



/** \brief funcion que muestra empleados encolumnados
 *
 * \param vector de empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 */

void mostrarEmpleados(eEmpleado vec[],int tam, eSector sectores[],int tamSec);


/** \brief busca los indices del vector de empleados donde isempty=1
 *
 * \param vector de empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 */

int buscarLibre(eEmpleado vec[], int tam);




/** \brief busca si hay empleados libres, en el vector de empleados indicado por id donde isempty=0
 *
 * \param campo id
 * \param vector empleados
 * \param tamanio del vec empleados
 * \return
 */


int buscarEmpleado(int id,eEmpleado vec[],int tam);





/** \brief agrega nuevo empleado con id autoincremental
 *
 * \param campo id
 * \param vector empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 * \return isok
 */

int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[],int tamSec);



/** \brief muestra encabezado para imprimir los sectores
 *
 * \param vector sectores
 * \param   tamanio sector

 */


void mostrarSectores( eSector sectores[], int tam);




/** \brief  muestra sectores encolumnados
 *
 * \param descripcion del sector(hardcodeada)
 * \param id sector
 * \param vector sector
 * \param tamanio sector

 * \return todook
 */


int cargarDescripcionSector(char descripcion[],int id, eSector sectores[], int tam );




/** \brief da de baja un empleado llamando a la funcion buscarempleado
 *
 * \param vector de empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 */

void bajaEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec);






/** \brief modifica los parametros (a partir de un id),nombre apellido sueldo y sector llamando a buscarempleado
 *
 * \param vector de empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 */

void modificarEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec);



/** \brief submenu informar

 */

void informar(eEmpleado vec[],int tam, eSector sectores[],int tamSec);


 int submenuInformar();



/** \brief ordena con metodo de buebujeo a partir de 2 parametros elegidos
 *
 * \param vector de empleados
 * \param tamanio del vec empleados
 * \param vector sectores
 * \param tamanio sector
 */

void ordenarEmpleado(eEmpleado vec[],int tam, eSector sectores[],int tamSec);





/** \brief informa sueldo total promedio de sueldos y empleados con sueldos mayor al promedio
 *
 * \param vector empleados
 * \param tamanio del vector
 * \return
 */

void informarPromedios(eEmpleado vec[],int tam);
