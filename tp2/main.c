#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "menu.h"

#define TAM 1000


int main()
{
    eEmployee empleado[TAM];
    int opc;
    int opcSalir;
    char resp = 'n';
    int flag = 1;
    int id = 6;
    initEmployees(empleado,TAM);
    hardcoreEmployees(empleado,TAM);

    do
    {
        opc = menu();
        switch(opc)
        {
        case 1:
            if(addEmployee(empleado,TAM,id))
            {
                printf("El empleado se ingreso correctamente.\n");
                id++;
                flag = 1;
            }
            else
            {
                printf("Hubo un error, intente nuevamente.\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(flag != 0)
            {
                if(modifyEmployee(empleado,TAM))
                {
                    printf("Se modifico correctamente.\n");
                }
                else
                {
                    printf("Fallo. Intente nuevamente.\n");
                }
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tiene que ingresar un empleado primero.\n");
                system("pause");
            }
            break;
        case 3:
            if(flag != 0)
            {
                if(deleteEmployee(empleado,TAM))
                {
                    printf("Se modifico correctamente.\n");
                }
                else
                {
                    printf("Fallo. Intente nuevamente.\n");
                }
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tiene que ingresar un empleado primero.\n");
                system("pause");
            }
            break;
        case 4:
            if(flag != 0)
            {
                printEmployeesMain(empleado,TAM);
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tiene que ingresar un empleado primero.\n");
                system("pause");
            }
            break;
        case 9:
            printf("Seguro quiere salir? 1.Si 2.No");
            scanf("%d",&opcSalir);
            if(opcSalir == 1)
            {
                resp = 's';
            }
            break;
        }
    }
    while(resp != 's');

    return 0;
}
