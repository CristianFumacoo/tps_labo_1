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

void calcu(float numUno, float numDos)
{

    printf   (" _____________________ ");
    printf("\n|  _________________  | ");
    printf("\n| | %2.2f              | | ", numUno);
    printf("\n| | %2.2f              | | ", numDos);
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

float sumar(float numUno, float numDos)
{
    return (numUno + numDos);
}

float restar(float numUno, float numDos)
{
    return (numUno - numDos);
}

float multiplicar(float numUno, float numDos)
{
    return (numUno * numDos);
}

float dividir(float numUno, float numDos)
{
    return (numUno / numDos);
}

float factorizar(float num)
{
    float resultado = 1;

    for (int i = 1; i <= num; i++)
    {
        resultado = resultado * i;
    }

    return resultado;
}


















