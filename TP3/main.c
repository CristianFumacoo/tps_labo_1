#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opc;
    int valTex;
    int valBin;
    LinkedList* empleados = ll_newLinkedList();

    do
    {
        opc = menu();

        switch(opc)
        {
            case 1:
                if(controller_loadFromText("data.csv",empleados))
                {
                    printf("El archivo csv se leyo correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",empleados))
                {
                    printf("El archivo bin se leyo correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 3:
                if(controller_addEmployee(empleados))
                {
                    printf("El empleado se agrego correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 4:
                if(controller_editEmployee(empleados))
                {
                    printf("\nEmpleado modificado correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 5:
                if(controller_removeEmployee(empleados))
                {
                    printf("\nEmpleado borrado correctamente.\n");
                    system("pause");
                }
                system("cls");                break;
            case 6:
                if(controller_ListEmployee(empleados))
                {
                    printf("\nEmpleados listados correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 7:
                if(controller_sortEmployee(empleados))
                {
                    printf("\nEmpleados ordenados correctamente.\n");
                    system("pause");
                }
                system("cls");
                break;
            case 8:
                if(controller_saveAsText("data.csv",empleados))
                {
                    printf("Se guardo correctamente (csv).\n");
                    system("pause");
                }
                system("cls");
                break;
            case 9:
                if(controller_saveAsBinary("data.bin",empleados))
                {
                    printf("Se guardo correctamente (bin).\n");
                    system("pause");
                }
                system("cls");
                break;
        }
    }while(opc != 10);


    return 0;
}
