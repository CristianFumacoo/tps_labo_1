#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int menu()
{
    int retorno;

    printf("Bienvenido a mi empresa\n\n");
    printf("¿Que desea hacer?\n");
    printf("1.Ingresar empleado.\n");
    printf("2.Modificar empleado\n");
    printf("3.Borrar empleado.\n");
    printf("4.Mostrar empleado.\n");
    printf("9.Salir.\n");
    printf("Ingrese opcion: ");
    scanf("%d",&retorno);

    return retorno;
}

int menuModify()
{
    int retorno;

    printf("\nBienvenido al modificar\n");
    printf("¿Que quiere modificar?.\n");
    printf("1.Nombre.\n");
    printf("2.Apellido.\n");
    printf("3.Salario.\n");
    printf("4.Sector.\n");

    printf("Ingrese opcion: ");
    scanf("%d",&retorno);

    return retorno;
}
