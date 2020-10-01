/*******************************************************************
* Programa: ABM de Empleados
* Objetivo: Realizar Altas, Bajas y Modificaciones en un sistema para administrar hasta 1000 empleados
*
* Version: 1.0
* Autor: Federico Agustin Ortiz
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Gets.h"
#define SIZE 1000

int main()
{
    int option;
    int order = -1;
    int nextId = 1000;
    int acumEmployees = 0;
    char exit = 'n';

    Employee listOfEmployees[SIZE];

    if(initEmployees(listOfEmployees, SIZE) == 0)
    {
        printf("Iniciacion exitosa\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");
    }

    system("pause");
    system("cls");

    do
    {
        printf("1. Dar de alta\n");
        printf("2. Modificar empleado\n");
        printf("3. Dar de baja\n");
        printf("4. Informar\n");
        printf("5. Salir\n");
        option = getInt(1, 5, "Ingrese una opcion: ");
        system("cls");

        switch(option)
        {
            case 1:
                if(createEmployee(listOfEmployees, SIZE, nextId) == 0)
                {
                    nextId++;
                    acumEmployees++;
                }
                else
                {
                    printf("Sistema completo\n");
                }
                break;

            case 2:
                if(acumEmployees>0)
                {
                    int id = getInt(1000, 9999, "Ingrese ID del empleado: ");
                    modifyEmployee(listOfEmployees, SIZE, id);
                }
                else
                {
                    printf("Primero debe realizar la carga de un empleado\n");
                }
                break;

            case 3:
                if(acumEmployees>0)
                {
                    int id = getInt(1000, 9999, "Ingrese ID del empleado: ");
                    if(removeEmployee(listOfEmployees, SIZE, id) == 0)
                    {
                        acumEmployees--;
                    }
                }
                else
                {
                    printf("Primero debe realizar la carga de un empleado\n");
                }
                break;

            case 4:
                if(acumEmployees>0)
                {
                    order = getInt(0, 1, "Desea listar los empleados de forma ascendente (1) o descendente (0)?: ");
                    sortEmployees(listOfEmployees, SIZE, order);
                    printEmployees(listOfEmployees, SIZE);
                }
                else
                {
                    printf("Primero debe realizar la carga de un empleado\n");
                }
                break;

            case 5:
                exit = getChar("Confirma salida (s/n): ");
                break;
        }

        printf("\n");
        system("pause");
        system("cls");

    }while(exit != 's');

    return 0;
}
