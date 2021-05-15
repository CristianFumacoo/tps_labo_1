#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "menu.h"
#define TAM 100



int main()
{
    eEmployee employee[TAM];
    int opc;
    int flag = 0;
    char respuesta = 's';
    initEmployees(employee,TAM);
    hardcoreEmployees(employee,TAM);

    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            if(addEmployees(employee,TAM))
            {
                printf("Se agrego empleado correctamente.\n");
                system("pause");
                flag++;
            }
            break;
        case 2:
            if(flag != 0)
            {
                if(modificarEmpleado(employee,TAM))
                {
                    printf("Se modifico correctamente.\n");
                    system("pause");
                }
                else
                {
                    printf("La operacion se cancelo o no se pudo completar.\n");
                    system("pause");
                }
            }
            else
            {
                printf("Primero debe ingresar un empleado.\n");
                system("pause");
            }
            break;
        case 3:
            if(flag != 0)
            {
                if(borrarEmpleado(employee,TAM))
                {
                    printf("Se borro correctamente.\n");
                    system("pause");
                }
                else
                {
                    printf("La operacion se cancelo o no se pudo completar.\n");
                    system("pause");
                }
            }
            else
            {
                printf("Primero debe ingresar un empleado.\n");
                system("pause");
            }
            break;
        case 4:
            if(flag != 0)
            {
                mostrarListaEmpleadosMain(employee,TAM);
                system("pause");
            }
            else
            {
                printf("Primero debe ingresar un empleado.\n");
                system("pause");
            }
            break;
        case 9:
            respuesta = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;


        }

    }
    while(respuesta == 's');

}
