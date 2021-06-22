#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();//Listo
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);//Listo
void employee_delete();

int employee_setId(Employee* this,int id);//Listo
int employee_getId(Employee* this,int* id);//Listo

int employee_setNombre(Employee* this,char* nombre);//Listo
int employee_getNombre(Employee* this,char* nombre);//Listo

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//Listo
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);//Listo

int employee_setSueldo(Employee* this,int sueldo);//Listo
int employee_getSueldo(Employee* this,int* sueldo);//Listo

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

void mostrar(Employee*);//Listo

#endif // employee_H_INCLUDED
