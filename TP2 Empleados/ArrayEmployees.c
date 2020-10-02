#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Gets.h"

int initEmployees(Employee list[], int length)
{
    int r = -1;

    if(list != NULL && length>0)
    {
        for(int i=0; i<length; i++)
        {
            list[i].isEmpty = 1;
            list[i].id = -1;
        }

        r = 0;
    }

    return r;
}

int findSpace(Employee list[], int length)
{
    int index = -1;

    if(list != NULL && length>0)
    {
        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

int createEmployee(Employee list[], int length, int id)
{
    Employee auxEmployee;
    int r = -1;
    int index = findSpace(list, length);

    if(list != NULL && length>0 && index != -1)
    {
        printf("               ***** CARGAR EMPLEADO *****\n\n");

        auxEmployee.id = id;
        getString(auxEmployee.name, 3, 50, "Ingrese nombre: ");
        getString(auxEmployee.lastName, 3, 50, "Ingrese apellido: ");
        auxEmployee.salary = getFloat(20000.00, 120000.00, "Ingrese salario (20000.00 - 120000.00): ");
        auxEmployee.sector = getInt(1, 4, "Ingrese sector (1-4): ");

        r = addEmployee(list, length, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

        if(r == 0)
        {
            list[index].isEmpty = 0;
        }
    }
    return r;
}

int addEmployee(Employee list[], int length, int id, char name[], char lastName[], float salary, int sector)
{
    int r = -1;
    int index = findSpace(list, length);

    if(list != NULL && length>0 && index != -1)
    {
        list[index].id = id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;

        r = 0;
    }

    return r;
}

int findEmployeeById(Employee list[], int length, int id)
{
    int r = -1;

    if(list != NULL && length>0)
    {
        for(int i=0; i<length; i++)
        {
            if(id == list[i].id && list[i].isEmpty == 0)
            {
                printf("\n  ID        Apellido           Nombre      Salario     Sector\n");
                printEmployee(list[i]);
                r = i;
                break;
            }
        }
    }

    return r;
}

void modifyEmployee(Employee list[], int length, int id)
{
    printf("\n               ***** MODIFICAR EMPLEADO *****\n\n");

    int index = findEmployeeById(list, length, id);

    if(list != NULL && length>0 &&  index != -1)
    {
        Employee auxEmployee = list[index];

        int option;
        int confirm = 'n';
        do
        {
            printf("\nQue desea modificar?\n");
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Salario\n");
            printf("4. Sector\n");
            printf("5. Volver al Menu\n\n");
            option = getInt(1, 5, "Ingrese una opcion: ");
            system("cls");

            switch(option)
            {
                case 1:
                    getString(auxEmployee.name, 3, 50, "Reingrese nombre: ");
                    break;
                case 2:
                    getString(auxEmployee.lastName, 3, 50, "Reingrese apellido: ");
                    break;
                case 3:
                    auxEmployee.salary = getFloat(20000.00, 120000.00, "Reingrese salario (20000.00 - 120000.00): ");
                    break;
                case 4:
                    auxEmployee.sector = getInt(1, 4, "Reingrese sector (1-4): ");
                    break;
                case 5:
                    confirm = getChar("Confirma los cambios realizados? (s/n): ");
                    if(confirm == 's')
                    {
                        list[index] = auxEmployee;
                    }
                    printf("Volviendo al Menu\n\n");
                    break;
            }
        }while(option != 5);
    }
    else
    {
        printf("No existe un empleado con el ID %d", id);
    }
}
int removeEmployee(Employee list[], int length, int id)
{
    printf("\n               ***** ELIMINAR EMPLEADO *****\n\n");

    int r = -1;
    int index = findEmployeeById(list, length, id);
    char confirm = 'n';

    if(list != NULL && length>0 &&  index != -1)
    {
        confirm = getChar("Confirma eliminar a este empleado? (s/n): ");

        if(confirm == 's')
        {
            list[index].isEmpty = 1;
            r = 0;
        }
        else
        {
            printf("Baja cancelada\n");
        }
    }
    else
    {
        printf("No existe un empleado con el ID %d", id);
    }

    return r;
}

int sortEmployees(Employee list[], int length, int order)
{
    int r = -1;
    Employee auxEmployee;

    if(list != NULL && length>0)
    {
        for(int i=0; i<length-1; i++)
        {
            for(int j=i+1; j<length; j++)
            {
                if(order == 1)
                {
                    if( (strcmp(list[i].lastName, list[j].lastName) > 0) || (list[i].sector > list[j].sector) )
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
                else
                {
                    if( (strcmp(list[i].lastName, list[j].lastName) < 0) || (list[i].sector < list[j].sector) )
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
        }

        r = 0;
    }

    return r;
}

void printEmployee(Employee anEmployee)
{
    printf("%4d %15s, %15s %12.2f %10d\n",  anEmployee.id,
                                            anEmployee.lastName,
                                            anEmployee.name,
                                            anEmployee.salary,
                                            anEmployee.sector);
}

int printEmployees(Employee list[], int length)
{
    system("cls");
    int acumEmployees = 0;
    int acumEmpSalary = 0;
    float acumSalary = 0;
    printf("               ***** LISTADO DE EMPLEADOS *****\n\n");
    printf("  ID        Apellido           Nombre      Salario     Sector\n");

    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printEmployee(list[i]);

            acumSalary = acumSalary + list[i].salary;
            acumEmployees++;
        }
    }

    float averageWages = (float)acumSalary/acumEmployees;

    for(int i=0; i<length; i++)
    {
        if(list[i].salary>averageWages)
        {
            acumEmpSalary++;
        }
    }

    printf("\nTotal salarios: $%.2f\n", acumSalary);
    printf("Promedio salarios: $%.2f\n", averageWages);
    printf("Cantidad de empleados que superan el salario promedio: %d\n\n", acumEmpSalary);

    return 0;
}
