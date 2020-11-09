#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int cant;
    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];
    Employee* auxEmployee = NULL;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(cant == 4)
            {
                auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

                if(auxEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, auxEmployee);
                    ok = 1;
                }
            }
            else
            {
                break;
            }
        }

        fclose(pFile);
    }

    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int cant;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            cant = fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(cant == 1)
            {
                ll_add(pArrayListEmployee, auxEmployee);
            }

            ok = 1;
        }
    }
    return ok;
}
