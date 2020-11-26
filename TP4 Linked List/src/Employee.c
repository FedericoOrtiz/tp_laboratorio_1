#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"

/** \brief Crea un empleado en memoria con los campos en 0
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* newEmployee = NULL;
    newEmployee = (Employee*) calloc(sizeof(Employee), 1);

    return newEmployee;
}

/** \brief Crea un empleado en memoria con los campos precargados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee = NULL;
    newEmployee = employee_new();

    if(newEmployee != NULL &&
       newEmployee != NULL &&
       idStr != NULL &&
       nombreStr != NULL &&
       horasTrabajadasStr != NULL)
    {
        employee_setId(newEmployee, atoi(idStr));
        employee_setNombre(newEmployee, nombreStr);
        employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(newEmployee, atoi(sueldoStr));
    }

    return newEmployee;
}

/** \brief Designa un ID al empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int ok = 0;
    if(this != NULL && id>0)
    {
        this->id = id;
        ok = 1;
    }

    return ok;
}

/** \brief Obtiene el ID del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int ok = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        ok = 1;
    }

    return ok;
}

/** \brief Designa el nombre al empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int ok = 0;
    if(this != NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre, nombre);
        ok = 1;
    }

    return ok;
}

/** \brief Obtiene el nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int ok = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        ok = 1;
    }

    return ok;
}

/** \brief Designa la cantidad de horas trabajadas al empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ok = 0;
    if(this != NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }

    return ok;
}

/** \brief Devuelve la cantidad de horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ok = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ok = 1;
    }

    return ok;
}

/** \brief Designa el sueldo al empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int ok = 0;
    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        ok = 1;
    }

    return ok;
}

/** \brief Devuelve el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ok = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        ok = 1;
    }

    return ok;
}

/** \brief Ordena dos empleados por ID
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int
 *
 */
int sortEmployeeById(void* employeeA, void* employeeB)
{
    int result = 0;
    int idA;
    int idB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employee_getId((Employee*)employeeA, &idA);
        employee_getId((Employee*)employeeB, &idB);

        result = idA - idB;
    }

    return result;
}

/** \brief Ordena dos empleados por Nombre
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int
 *
 */
int sortEmployeeByName(void* employeeA, void* employeeB)
{
    int result = 0;

    if(employeeA != NULL && employeeB != NULL)
    {
        char nombreA[128];
        char nombreB[128];

        employee_getNombre((Employee*)employeeA, nombreA);
        employee_getNombre((Employee*)employeeB, nombreB);

        result = strcmp(nombreA, nombreB);
    }

    return result;
}

/** \brief Ordena dos empleados por cantidad de Horas Trabajadas
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int
 *
 */
int sortEmployeeByWorkHours(void* employeeA, void* employeeB)
{
    int result = 0;
    int horasA;
    int horasB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employee_getHorasTrabajadas((Employee*)employeeA, &horasA);
        employee_getHorasTrabajadas((Employee*)employeeB, &horasB);

        result = horasA - horasB;
    }

    return result;
}

/** \brief Ordena dos empleados por Salario
 *
 * \param employeeA void*
 * \param employeeB void*
 * \return int
 *
 */
int sortEmployeeBySalary(void* employeeA, void* employeeB)
{
    int result = 0;
    int sueldoA;
    int sueldoB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employee_getSueldo((Employee*)employeeA, &sueldoA);
        employee_getSueldo((Employee*)employeeB, &sueldoB);

        result = sueldoA - sueldoB;
    }

    return result;
}

/** \brief Libera de memoria un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);

    this = NULL;
}

/** \brief Obtiene el proximo ID para un nuevo empleado
 *
 * \param listEmployees LinkedList*
 * \return int
 *
 */
int nextId(LinkedList* listEmployees)
{
    int tam = ll_len(listEmployees);
    Employee* auxEmployee;
    int auxId;
    int maxId;
    int flag = 0;

    for(int i=0; i<tam; i++)
    {
        auxEmployee = (Employee*) ll_get(listEmployees, i);
        employee_getId(auxEmployee, &auxId);

        if(auxId > maxId || flag == 0)
        {
            maxId = auxId;
            flag = 1;
        }
    }

    return maxId + 1;
}



/** \brief Obtiene un empleado por ID
 *
 * \param listEmployees LinkedList*
 * \param id int
 * \return int
 *
 */
int findEmployeeById(LinkedList* listEmployees, int id)
{
    int index = -1;
    int tam = ll_len(listEmployees);
    int idAux;
    Employee* auxEmployee;

    for(int i=0; i<tam; i++)
    {
        auxEmployee = (Employee*) ll_get(listEmployees, i);
        employee_getId(auxEmployee, &idAux);

        if(id == idAux)
        {
            index = i;
            break;
        }
    }

    return index;
}
