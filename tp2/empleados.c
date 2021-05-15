#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "menu.h"


void initEmployees(eEmployee empleados[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        empleados[i].salary = 0;
        empleados[i].sector = 0;
        strcpy(empleados[i].name, " ");
        strcpy(empleados[i].lastName, " ");
        empleados[i].isEmpty = 0;
    }
}

void hardcoreEmployees(eEmployee empleados[],int cant)
{
    float arraySalarios[3] = {15500,45000,78000};
    int arraySectores[3] = {12,21,45};
    char arrayNombres[3][51] = {"Cristian","Matias","Noelia"};
    char arrayApellidos[3][51] = {"Fumacoo","Gustavo","Anabel"};
    int arrayIsEmpty[3] = {1,1,1};
    int arrayId[3] = {1,2,3};

    for(int i=0; i<3; i++)
    {
        empleados[i].salary = arraySalarios[i];
        empleados[i].sector = arraySectores[i];
        empleados[i].isEmpty = arrayIsEmpty[i];
        empleados[i].id = arrayId[i];
        strcpy(empleados[i].name,arrayNombres[i]);
        strcpy(empleados[i].lastName,arrayApellidos[i]);
    }
}
int addEmployees(eEmployee empleado[],int tam)
{
    int retorno = 0;

    for(int i = 0; i<tam; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
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
            empleado[i].id = i+1;
            retorno = 1;
            break;
        }
    }


    return retorno;
}

int buscarEmpleado(eEmployee empleado[],int cant,int auxId)
{
    int retorno = -1;

    for(int i=0; i<cant; i++)
    {
        if(empleado[i].isEmpty != 0)
        {
            if(empleado[i].id == auxId)
            {
                retorno = i;
            }
        }

    }

    return retorno;
}

int borrarEmpleado(eEmployee empleado[],int cant)
{
    int retorno = 0;
    int auxId;
    char respuesta;
    int idABorrar;

    mostrarListaEmpleados(empleado,cant);

    printf("Ingrese el ID del empleado que quiere borrar: ");
    scanf("%d",&auxId);

    idABorrar = buscarEmpleado(empleado,cant,auxId);

    if(idABorrar != -1)
    {
        printf("¿Seguro que quiere borrar a?\n");
        mostrarEmpleado(empleado[idABorrar]);
        printf("Ingrese s para borrar o n para cancelar: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            empleado[idABorrar].isEmpty = 0;
            retorno = 1;
        }
    }
    else
    {
        printf("El id ingresado no existe.\n");
    }

    return retorno;
}

int modificarEmpleado(eEmployee empleado[],int cant)
{
    int retorno = 0;
    int auxId;
    char respuesta;
    int idAModificar;
    int opc;

    mostrarListaEmpleados(empleado,cant);

    printf("Ingrese el ID del empleado que quiere Modificar: ");
    scanf("%d",&auxId);

    idAModificar = buscarEmpleado(empleado,cant,auxId);

    if(idAModificar != -1)
    {
        printf("¿Seguro que quiere Modificar a?\n");
        mostrarEmpleado(empleado[idAModificar]);
        printf("Ingrese s para Modificar o n para cancelar: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            opc = menuModify();

            switch(opc)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s",&empleado[idAModificar].name);
                retorno = 1;
                break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                scanf("%s",&empleado[idAModificar].lastName);
                retorno = 1;
                break;
            case 3:
                printf("Ingrese nuevo salario: ");
                scanf("%f",&empleado[idAModificar].salary);
                retorno = 1;
                break;
            case 4:
                printf("Ingrese nuevo sector: ");
                scanf("%d",&empleado[idAModificar].sector);
                retorno = 1;
                break;
            default:
                printf("Opcion incorrecta.\n");
                break;
            }
        }
    }
    else
    {
        printf("El id ingresado no existe.\n");
    }

    return retorno;

}

void mostrarEmpleado(eEmployee empleado)
{
    if(empleado.isEmpty != 0)
    {
        printf("%d%15s%15s%15.1f%15d\n",empleado.id,empleado.name,empleado.lastName,empleado.salary,empleado.sector);
    }
}

void mostrarListaEmpleados(eEmployee empleados[],int cant)
{
    printf("%s%15s%15s%15s%15s\n\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(int i = 0; i<cant; i++)
    {
        if(empleados[i].isEmpty != 0)
        {
            mostrarEmpleado(empleados[i]);
        }
    }
}

void mostrarListaEmpleadosMain(eEmployee empleados[],int cant)
{
    printf("%s%15s%15s%15s%15s\n\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

    for(int i = 0; i<cant; i++)
    {
        if(empleados[i].isEmpty != 0)
        {
            mostrarEmpleado(empleados[i]);
        }
    }
    totalSalaries(empleados,cant);
}

void totalSalaries(eEmployee empleado[], int tam)
{
    float total = 0;
    int contador=0;
    int contador2=0;
    float promedio;

    printf("\n<<<<Total sueldo de los empleados<<<< \n");

    for(int i = 0; i < tam; i++)
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














