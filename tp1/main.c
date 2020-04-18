#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int num1;
    int num2;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorizacionDeNum1;
    int factorizacionDeNum2;
//char opcion;
   int salir;
    //int flag1=0;

    do
    {
        switch(MenuOpciones() )
        {
            case 1:
                printf("por favor ingrese el primer numero\n");
                scanf("%d",&num1);
                break;
            case 2:
                printf("por favor ingrese el segundo numero\n");
                scanf("%d",&num2);
                break;
            case 3:
                printf("las operaciones se han realizado exitosamente\n");
                suma=sumar(num1,num2);
                resta=restar(num1,num2);
                division=dividir(num1,num2);
                multiplicacion=multiplicar(num1,num2);
                factorizacionDeNum1=factorizar(num1);
                factorizacionDeNum2=factorizar(num2);

                system("pause");


                break;

            case 4:
                printf("el resultado de %d + %d es: %d \n",num1,num2,suma);
                printf("el resultado de %d - %d es: %d \n",num1,num2,resta);
                printf("el resultado de %d / %d es: %f \n",num1,num2,division);
                printf("el resultado de %d * %d es: %d \n",num1,num2,multiplicacion);
                printf("el factorial de %d es: %d \nel factorial de %d es: %d \n",num1,factorizacionDeNum1,num2,factorizacionDeNum2);
                system("pause");
                break;

            case 5:
                salir=5;
                break;

            default:
                printf("no es una opcion valida\n");
                system("pause");
                break;
        }

    //system("pause");

    }
    while(salir!=5);


    return 0;
}


