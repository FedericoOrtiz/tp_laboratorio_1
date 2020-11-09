#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Employee.h"
#include "Gets.h"
#include <string.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                ok = 1;
            }
        }

        fclose(pFile);
    }

    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    FILE* pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee))
        {
            ok = 1;
        }
    }

    fclose(pFile);

    return ok;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxIdStr[128];
    char auxNombreStr[128];
    char auxHorasTrabajadasStr[128];
    char auxSueldoStr[128];

    Employee* newEmployee = employee_new();

    if(pArrayListEmployee != NULL)
    {
        auxId = nextId(pArrayListEmployee);
        itoa(auxId, auxIdStr, 10);

        getString(auxNombreStr, 3, 128, "Ingrese nombre: ");
        auxHorasTrabajadas = getInt(1, 5000, "Ingrese horas trabajadas (1-5000): ");
        itoa(auxHorasTrabajadas, auxHorasTrabajadasStr, 10);
        auxSueldo = getInt(25000, 150000, "Ingrese sueldo (25000-150000): ");
        itoa(auxSueldo, auxSueldoStr, 10);

        newEmployee = employee_newParametros(auxIdStr, auxNombreStr, auxHorasTrabajadasStr, auxSueldoStr);
        ll_add(pArrayListEmployee, newEmployee);
    }

    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 1;
    int index;
    int option;
    int auxId;
    Employee* auxEmployee;

    system("cls");

    controller_ListEmployees(pArrayListEmployee);
    auxId = getInt(1, 2000, "Ingrese ID del empleado: ");
    index = findEmployeeById(pArrayListEmployee, auxId);
    auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);

    if(index != -1)
    {
        char confirm = 'n';

        system("cls");
        printf("  ID          NOMBRE    HORAS     SUELDO\n");
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);
        controller_ListEmployee(auxEmployee);

        char auxNombre[128];
        int auxHorasTrabajadas;
        int auxSueldo;

        strcpy(auxNombre, auxEmployee->nombre);
        auxHorasTrabajadas = auxEmployee->horasTrabajadas;
        auxSueldo = auxEmployee->sueldo;

        do
        {
            switch(controller_menuEditEmployee())
            {
                case 1:
                    getString(auxNombre, 3, 128, "Reingrese nombre: ");
                    break;
                case 2:
                    auxHorasTrabajadas = getInt(1, 5000, "Reingrese horas trabajadas(1, 5000): ");
                    break;
                case 3:
                    auxSueldo = getInt(25000, 150000, "Reingrese sueldo(250000-150000): ");
                    break;
                case 4:
                    confirm = getChar("Confirma las modificaciones realizadas?(s/n): ");
                    if(confirm == 's');
                    {
                        employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
                        employee_setNombre(auxEmployee, auxNombre);
                        employee_setSueldo(auxEmployee, auxSueldo);
                    }
                    break;
            }

        }while(confirm != 's');
    }
    else
    {
        printf("No hay un empleado con el ID: %d\n", auxId);
    }

    return 1;
}

/** \brief Menu de opciones para editar empleado
 *
 * \return int
 *
 */
int controller_menuEditEmployee()
{
    printf("Que desea modificar?\n");
    printf("1. Nombre del empleado\n");
    printf("2. Horas trabajadas\n");
    printf("3. Sueldo\n");
    printf("4. Salir\n\n");

    return getInt(1, 4, "Ingrese una opcion: ");
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int auxId;
    int index;
    char confirm = 'n';
    Employee* auxEmployee;

    system("cls");
    controller_ListEmployees(pArrayListEmployee);
    auxId = getInt(1, 3000, "Ingrese el ID del empleado: ");
    index = findEmployeeById(pArrayListEmployee, auxId);

    if(index != 1)
    {
        printf("  ID          NOMBRE    HORAS     SUELDO\n");
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);
        controller_ListEmployee(auxEmployee);
        confirm = getChar("\nDesea eliminar a este empleado?: ");

        if(confirm == 's')
        {
            ll_remove(pArrayListEmployee, index);
            ok = 1;
        }
    }
    else
    {
        printf("No hay un empleado con el ID %d", auxId);
    }

    return ok;
}


/** \brief Muestra en pantalla un empleado
 *
 * \param myEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* myEmployee)
{
    int ok = 0;
    int auxId;
    char auxnombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(myEmployee != NULL)
    {
        employee_getId(myEmployee, &auxId);
        employee_getNombre(myEmployee, auxnombre);
        employee_getHorasTrabajadas(myEmployee, &auxHorasTrabajadas);
        employee_getSueldo(myEmployee, &auxSueldo);

        printf("%4d %15s     %4d     %6d\n", auxId, auxnombre, auxHorasTrabajadas, auxSueldo);
        ok = 1;
    }

    return ok;
}

/** \brief Muestra en pantalla un array de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    int ok = 0;

    int tam = ll_len(pArrayListEmployee);

    Employee* auxEmployee;
    system("cls");
    printf("  ID          NOMBRE    HORAS     SUELDO\n");

    for(int i=0; i<tam; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

        if(auxEmployee != NULL)
        {
            controller_ListEmployee(auxEmployee);
            ok = 1;
        }
    }

    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int option;

    do
    {
        system("cls");
        option = controller_menuSortEmployee();
        switch(option)
        {
            case 1:
                printf("Aguarde...\n\n");
                ll_sort(pArrayListEmployee, sortEmployeeById, 1);
                break;
            case 2:
                printf("Aguarde...\n\n");
                ll_sort(pArrayListEmployee, sortEmployeeByName, 1);
                break;
            case 3:
                printf("Aguarde...\n\n");
                ll_sort(pArrayListEmployee, sortEmployeeByWorkHours, 1);
                break;
            case 4:
                printf("Aguarde...\n\n");
                ll_sort(pArrayListEmployee, sortEmployeeBySalary, 1);
                break;
        }
    }while(option != 5);

    return 1;
}

/** \brief Menu de opciones para ordenar empleados
 *
 * \return int
 *
 */
int controller_menuSortEmployee()
{
    printf("Por cual criterio desea ordenar?\n");
    printf("1. ID\n");
    printf("2. Nombre\n");
    printf("3. Horas trabajadas\n");
    printf("4. Sueldo\n");
    printf("5. Salir\n");

    return getInt(1, 5, "Ingrese una opcion: ");
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int tam;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    FILE* pFile;

    Employee* auxEmployee;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        fprintf(pFile,"ID,NOMBRE,HORAS,SUELDO\n");
        tam = ll_len(pArrayListEmployee);

        for(int i=0; i< tam; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

            if(auxEmployee != NULL)
            {
                employee_getId(auxEmployee,&auxId);
                employee_getNombre(auxEmployee,auxNombre);
                employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
                employee_getSueldo(auxEmployee,&auxSueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            }
        }

        ok = 1;
    }

    employee_delete(auxEmployee);
    fclose(pFile);

    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int tam = ll_len(pArrayListEmployee);
    FILE* pFile = fopen(path, "wb");
    Employee* auxEmployee;

    for(int i=0; i<tam; i++)
    {
        auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

        if(auxEmployee != NULL)
        {
            fwrite(auxEmployee, sizeof(Employee), 1, pFile);
            ok = 1;
        }
    }

    fclose(pFile);

    return ok;
}

/** \brief Menu de opciones principal del programa
 *
 * \return int
 *
 */
int controller_showMenu()
{

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");

    return getInt(1, 10, "Ingrese una opcion: ");;
}
