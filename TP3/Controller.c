#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno= 0;

    pArchivo=fopen(path,"r");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    }
    fclose(pArchivo);

    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 0;

    pArchivo = fopen(path,"rb");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    }
    fclose(pArchivo);

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int auxID = ll_len(pArrayListEmployee)+1;
    int retorno = 0;

    char auxNombre[51];
    int auxSueldo;
    int auxHoras;

    empleado = employee_new();

    if(ll_len(pArrayListEmployee) == 0)
    {
        printf("Primero cargue la lista.\n");
        system("pause");
        return retorno;
    }

    else
    {
        if(pArrayListEmployee != NULL)
        {

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxNombre);

            printf("\nIngrese sueldo: ");
            scanf("%d",&auxSueldo);

            printf("\nIngrese Horas de Trabajo: ");
            scanf("%d",&auxHoras);

            employee_setId(empleado,auxID);
            employee_setNombre(empleado,auxNombre);
            employee_setSueldo(empleado,auxSueldo);
            employee_setHorasTrabajadas(empleado,auxHoras);

            ll_add(pArrayListEmployee,empleado);

            auxID++;
            retorno = 1;
        }
    }

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    Employee* aux;
    int retorno = 0;
    int encontro = 0;
    int auxId;
    int idModify;
    int menu;

    char auxNombre[51];
    int auxSueldo;
    int auxHoras;

    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese id a Modificar: ");
    scanf("%d",&idModify);


    if(pArrayListEmployee != NULL)
    {

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&auxId);

            if(auxId == idModify)
            {
                encontro = i;
                break;
            }
        }

        if(encontro > 0)
        {
            menu = menuModify();

            switch(menu)
            {
            case 1:
                mostrar(empleado);

                printf("\nIngrese el nuevo nombre :");
                fflush(stdin);
                gets(auxNombre);

                employee_setNombre(empleado,auxNombre);
                break;
            case 2:
                mostrar(empleado);

                printf("\nIngrese nuevo sueldo: ");
                scanf("%d",&auxSueldo);

                employee_setSueldo(empleado,auxSueldo);
                break;
            case 3:
                mostrar(empleado);

                printf("\nIngrese nuevas horas: ");
                scanf("%d",&auxHoras);

                employee_setHorasTrabajadas(empleado,auxHoras);
                break;
            }
            retorno = 1;
        }
    }
    return retorno;
}

void mostrar(Employee* empleado)
{
    char nombre[50];
    int id;
    int sueldo;
    int horas;

    employee_getNombre(empleado,nombre);
    employee_getId(empleado,&id);
    employee_getSueldo(empleado,&sueldo);
    employee_getHorasTrabajadas(empleado,&horas);

    printf("%d%15s%15d%25d\n",id,nombre,sueldo,horas);
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno = 0;
    int auxId;
    int idPedido;
    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngresar id del empleado a borrar: ");
    scanf("%d",&idPedido);

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&auxId);

            if(auxId == idPedido)
            {
                ll_remove(pArrayListEmployee,i);
                retorno = 1;
            }
        }
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno = 0;
    char nombre[50];
    int id;
    int sueldo;
    int horas;

    if(pArrayListEmployee != NULL)
    {
        printf("%s%15s%15s%30s\n","ID","NOMBRE","SUELDO","HORAS DE TRABAJO");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            employee_getNombre(empleado,nombre);
            employee_getId(empleado,&id);
            employee_getSueldo(empleado,&sueldo);
            employee_getHorasTrabajadas(empleado,&horas);

            printf("%d%15s%15d%25d\n",id,nombre,sueldo,horas);
        }
        printf("\nCantidad de empleados : %d",ll_len(pArrayListEmployee));
        retorno = 1;
    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleados1;
    Employee* empleados2;
    int retorno = 0;
    int opc;

    if(pArrayListEmployee != NULL)
    {
        printf("1.Por id.\n");
        printf("2.Por nombre.\n");
        scanf("%d",&opc);

        switch(opc)
        {
            case 1:
                ll_sort(pArrayListEmployee,employee_CompareById,1);
                retorno = 1;
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_CompareByName,1);
                retorno = 1;
                break;
        }
    }
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee * empleado;
    int id;
    int sueldo;
    int horasTrabajadas;

    char auxId[101];
    char auxNombre[101];
    char auxHoras[101];
    char auxSueldo[101];

    FILE* pFile=fopen(path,"w");


    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
        for(int i= 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);

            employee_getId(empleado,&id);
            employee_getNombre(empleado,auxNombre);
            employee_getSueldo(empleado,&sueldo);
            employee_getHorasTrabajadas(empleado,&horasTrabajadas);

            sprintf(auxId, "%d", id);
            sprintf(auxSueldo,"%d",sueldo);
            sprintf(auxHoras,"%d",horasTrabajadas);
            fprintf(pFile,"%s,%s,%s,%s\n",auxId,auxNombre,auxHoras,auxSueldo);
            printf("%s,%s,%s,%s\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
        fclose(pFile);
        retorno = 1;
    }

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile=fopen(path,"wb");
    Employee* empleado;

    if (pFile!= NULL && pArrayListEmployee !=NULL)
    {
        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            empleado=ll_get(pArrayListEmployee,i);
            fwrite(empleado,140,1,pFile);
        }
        retorno = 1;
        fclose(pFile);
    }
    return retorno;
}

