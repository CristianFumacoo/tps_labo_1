#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opc;

    system("cls");
    printf("Bienvenido a mi Empresa\n\n");
    printf("1.Ingresar un empleado.\n");
    printf("2.Modificar un empleado.\n");
    printf("3.Borrar un empleado.\n");
    printf("4.Mostrar empleados\n");
    printf("9.Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opc);

    return opc;

}

int menuModify()
{
    int opc;

    system("cls");
    printf("¿Que desea modificar?\n\n");
    printf("1.Nombre.\n");
    printf("2.Apellido.\n");
    printf("3.Salario.\n");
    printf("4.Sector\n");
    printf("9.Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opc);

    return opc;
}





