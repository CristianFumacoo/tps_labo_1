#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "menu.h"

void initEmployees(eEmployee empleados[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        empleados[i].isEmpty = 0;
    }
}

void hardcoreEmployees(eEmployee empleados[],int cant)
{
    int arrayCuil[5] = {2670148952,4503971542,4501230785,6503500489,1035071823};
    char arrayNombres[5][51] = {"Cristian","Matias","Noelia","Alicia","Jorge"};
    char arrayApellidos[5][51] = {"Fumacoo","Fumacoo","Anabel","Peres","Fumacoo"};
    int arrayIsEmpty[5] = {1,1,1,1,1};
    int arrayId[5] = {1000,1001,1002,1003,1004};

    for(int i=0; i<5; i++)
    {
        empleados[i].id = arrayId[i];
        strcpy(empleados[i].name,arrayNombres[i]);
        strcpy(empleados[i].lastName,arrayApellidos[i]);
        empleados[i].sector = arrayCuil[i];
        empleados[i].isEmpty = arrayIsEmpty[i];
    }
}

int searchEmployee(eEmployee empleado[],int cant,int id)
{
    int retorno = -1;
    for(int i = 0; i < cant; i++)
    {
        if(empleado[i].isEmpty == 1 && empleado[i].id == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int addEmployee(eEmployee empleado[],int cant,int id)
{
    int retorno = 0;

    for(int i = 0; i < cant; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            printf("ID: %d\n",id);

            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", &empleado[i].name);

            printf("Ingrese el apellido del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", &empleado[i].lastName);

            printf("Ingrese el salario del empleado: ");
            scanf("%f", &empleado[i].salary);

            printf("Ingrese el sector del empleado: ");
            scanf("%d", &empleado[i].sector);

            empleado[i].isEmpty = 1;
            empleado[i].id = id;
            retorno = 1;
            break;
        }
    }

    return retorno;
}

int modifyEmployee(eEmployee empleado[],int cant)
{
    int retorno = 0;
    int opc;
    int idModify;
    int indiceModify;
    int siOno;

    printEmployees(empleado,cant);

    printf("\nIngrese el ID del empleado a modificar: ");
    scanf("%d",&idModify);

    indiceModify = searchEmployee(empleado,cant,idModify);

    if(indiceModify == -1)
    {
        printf("El empleado que ingreso no corresponde.\n");
    }
    else
    {
        printf("¿Seguro quiere modificar a?\n");
        printOneEmployee(empleado[indiceModify]);

        printf("1.Si 2.No :");
        scanf("%d",&siOno);

        if(siOno == 1)
        {
            opc = menuModify();

            switch(opc)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%[^\n]", &empleado[indiceModify].name);
                retorno = 1;
                break;

            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                scanf("%[^\n]", &empleado[indiceModify].lastName);
                retorno = 1;
                break;

            case 3:
                printf("Ingrese nuevo salario: ");
                scanf("%d",&empleado[indiceModify].salary);
                retorno = 1;
                break;

            case 4:
                printf("Ingrese nuevo sector: ");
                scanf("%d",&empleado[indiceModify].sector);
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

int deleteEmployee(eEmployee empleado[],int cant)
{
    int retorno = 0;
    int opc;
    int idModify;
    int indiceDelete;
    int siOno;

    printEmployees(empleado,cant);

    printf("\nIngrese el ID del empleado a modificar: ");
    scanf("%d",&idModify);

    indiceDelete = searchEmployee(empleado,cant,idModify);

    if(indiceDelete == -1)
    {
        printf("El empleado que ingreso no corresponde.\n");
    }
    else
    {
        printf("¿Seguro quiere eliminar a?\n");
        printOneEmployee(empleado[indiceDelete]);

        printf("1.Si 2.No :");
        scanf("%d",&siOno);

        if(siOno == 1)
        {
            empleado[indiceDelete].isEmpty = 0;
            retorno = 1;
        }
        else
        {
            printf("La operacion se cancelo.\n");
        }

    }

    return retorno;
}

void orderEmployees(eEmployee empleado[],int cant)
{
    eEmployee employee;

    for (int i = 0; i < cant-1; i++)
    {
        for (int j = i; j < cant; j++)
        {
            if(empleado[i].isEmpty == 1 && empleado[j].isEmpty == 1)
            {
                if (strcmp(empleado[i].lastName, empleado[j].lastName) == 0)
                {
                    if(empleado[i].sector > empleado[j].sector)
                    {
                        employee = empleado[j];
                        empleado[j] = empleado[i];
                        empleado[i] = employee;
                    }
                }
                else if(strcmp(empleado[i].lastName, empleado[j].lastName) > 0)
                {
                    employee = empleado[j];
                    empleado[j] = empleado[i];
                    empleado[i] = employee;
                }
            }
        }
    }
}


void printOneEmployee(eEmployee empleado)
{
    if(empleado.isEmpty == 1)
    {
        printf("%d%15s%15s%20.2f%15d\n",empleado.id,
               empleado.name,
               empleado.lastName,
               empleado.salary,
               empleado.sector);
    }
}

void printEmployees(eEmployee empleados[],int cant)
{
    printf("%s%15s%15s%15s%20s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(int i = 0; i < cant; i++)
    {
        printOneEmployee(empleados[i]);
    }

}

void printEmployeesMain(eEmployee empleados[],int cant)
{
    orderEmployees(empleados,cant);
    printf("%s%15s%15s%15s%20s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(int i = 0; i < cant; i++)
    {
        printOneEmployee(empleados[i]);
    }

    totalSueldoE(empleados,cant);

}

void totalSueldoE(eEmployee empleado[], int tam)
{
    float total = 0;
    int contador=0;
    int contador2=0;
    float promedio;

    printf("\n<<<<Total sueldo de los empleados<<<< \n");

    for(int i = 0; i < tam;i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            contador++;
            total += empleado[i].salary;
        }
    }
    promedio = total / contador;

    for(int i = 0; i < tam; i++)
    {
        if(empleado[i].isEmpty == 1 && empleado[i].salary > promedio)
        {
            contador2++;
        }
    }


    printf("El total de salarios es: %.2f\n",total);
    printf("El salario promedio es: %.2f\n",promedio);
    printf("Los empleados que superan el salario promedio son: %d\n",contador2);
}




