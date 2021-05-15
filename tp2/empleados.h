/*
initEmployees
addEmployees
findEmployeeById
removeEmployee
sortEmployeeByName
printEmployees..
*/
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int addEmployees(eEmployee[],int);

int borrarEmpleado(eEmployee[],int);

int modificarEmpleado(eEmployee[],int);

int buscarEmpleado(eEmployee[],int,int);

void mostrarListaEmpleados(eEmployee[],int);

void mostrarEmpleado(eEmployee);

void initEmployees(eEmployee[],int);

void hardcoreEmployees(eEmployee[],int);

void totalSalaries(eEmployee[],int);





