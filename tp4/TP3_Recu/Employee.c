#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>

int employee_setId(Employee* this,int id)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->id = id;
            retorno = 1;
        }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(this->nombre,nombre);
            retorno = 1;
        }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horas)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->horasTrabajadas = horas;
            retorno = 1;
        }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->sueldo = sueldo;
            retorno = 1;
        }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;

        if(this != NULL)
        {
            *id = this->id;
            retorno = 1;
        }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(nombre,this->nombre);
            retorno = 1;
        }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

        if(this != NULL)
        {
            *sueldo = this->sueldo;
            retorno = 1;
        }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horas)
{
    int retorno = 0;

        if(this != NULL)
        {
            *horas = this->horasTrabajadas;
            retorno = 1;
        }
    return retorno;
}

Employee* employee_new()
{
    Employee* this;

    this = malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this = employee_new();


    if(employee_setId(this,atoi(idStr))&&
       employee_setNombre(this,nombreStr)&&
       employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
       employee_setSueldo(this,atoi(sueldo)))
    {
         return this;
    }

    return NULL;
}

int employee_CompareById(Employee* emp1,Employee* emp2)
{
    int retorno = 0;

    if(emp1->id > emp2->id)
    {
        retorno = 1;
    }
    if(emp1->id < emp2->id)
    {
        retorno = -1;
    }
    return retorno;
}

int employee_CompareByName(Employee* emp1, Employee* emp2)
{
    int retorno = 0;

    if(  strcmpi(emp1->nombre, emp2->nombre) > 0)
    {
        retorno = 1;
    }
    if(strcmpi(emp1->nombre,emp2->nombre) < 0)
    {
        retorno = -1;
    }

    return retorno;
}





