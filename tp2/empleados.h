typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

int searchEmployee(eEmployee[],int,int);

void initEmployees(eEmployee[],int);

void hardcoreEmployees(eEmployee[],int);

int addEmployee(eEmployee[],int,int);

int modifyEmployee(eEmployee[],int);

int deleteEmployee(eEmployee[],int);

int ordenEmployees(eEmployee[],int);

void printOneEmployee(eEmployee);

void printEmployees(eEmployee[],int);

void printEmployeesMain(eEmployee[],int);

void totalSueldoE(eEmployee[],int);



