#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "../inc/LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);
int employee_add(LinkedList* listEmployees);
int findEmployeeById(LinkedList* listEmployees, int id);
int nextId(LinkedList* listEmployees);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int sortEmployeeById(void* employeeA, void* employeeB);
int sortEmployeeByName(void* employeeA, void* employeeB);
int sortEmployeeByWorkHours(void* employeeA, void* employeeB);
int sortEmployeeBySalary(void* employeeA, void* employeeB);


#endif // employee_H_INCLUDED
