#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calcu.h"

int menu()
{
    int opc;

    printf("1.Ingresar primer numero.\n");
    printf("2.Ingresar segundo numero.\n");
    printf("3.Realizar operaciones.\n");
    printf("4.Mostrar operaciones.\n");
    printf("5.Salir.\n");
    printf("Ingresar opcion: ");
    scanf("%d",&opc);

    return opc;
}

void calcu(int numUno, int numDos)
{

    printf   (" _____________________ ");
    printf("\n|  _________________  | ");
    printf("\n| | %2d              | | ", numUno);
    printf("\n| | %2d              | | ", numDos);
    printf("\n|  ___ ___ ___   ___  | ");
    printf("\n| | 7 | 8 | 9 | | + | | ");
    printf("\n| |___|___|___| |___| | ");
    printf("\n| | 4 | 5 | 6 | | - | | ");
    printf("\n| |___|___|___| |___| | ");
    printf("\n| | 1 | 2 | 3 | | x | | ");
    printf("\n| |___|___|___| |___| | ");
    printf("\n| | . | 0 | = | | / | | ");
    printf("\n| |___|___|___| |___| | ");
    printf("\n|_____________________| \n");
}

float sumar(int numUno, int numDos)
{
    return (float) (numUno + numDos);
}

float restar(int numUno, int numDos)
{
    return (float) (numUno - numDos);
}

float multiplicar(int numUno, int numDos)
{
    return (float) (numUno * numDos);
}

float dividir(int numUno, int numDos)
{
    return (float) (numUno / numDos);
}

float factorizar(int num)
{
    float resultado = 1;

    for (int i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }

    return (float) resultado;
}

int pedirNumero()
{
    int retorno;
    char num[10];

    printf("Ingrese un numero: ");
    scanf("%s",&num);

    for (int i = 0; i < strlen(num); i++)
    {
        while(!isdigit(num[i]) )
        {
            printf("Error. Ingrese un numero: ");
            scanf("%s",&num);
        }
        break;
    }

    retorno = atoi(num);

    return retorno;
}


















