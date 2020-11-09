#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Gets.h"

/****************************************************
    * Programa: Linked List de ABM de Empleados

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

    * Version: 1.0
    * Autor: Federico Agustin Ortiz
*****************************************************/


int main()
{
    char exit = 'n';
    int loadFromText = 0;
    int loadFromBin = 0;

    LinkedList* listEmployees = ll_newLinkedList();
    do{

        switch(controller_showMenu())
        {
            case 1:
                if(!loadFromText)
                {
                    if(controller_loadFromText("data.csv", listEmployees))
                    {
                        printf("Empleados cargados con exito\n\n");
                        loadFromText = 1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo\n\n");
                    }
                }
                else
                {
                    printf("Los empleados ya han sido cargados al sistema\n\n");
                }
                break;
            case 2:
                if(!loadFromBin)
                {
                    if(controller_loadFromBinary("data.bin", listEmployees))
                    {
                        printf("Empleados cargados con exito\n\n");
                        loadFromBin = 1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo\n\n");
                    }
                }
                else
                {
                    printf("Los empleados ya han sido cargados al sistema\n\n");
                }
                break;
            case 3:
                controller_addEmployee(listEmployees);
                break;
            case 4:
                controller_editEmployee(listEmployees);
                break;
            case 5:
                controller_removeEmployee(listEmployees);
                break;
            case 6:
                if(!loadFromText && !loadFromBin)
                {
                    printf("Primero debe cargar el archivo a sistema\n\n");
                }
                else if(!controller_ListEmployees(listEmployees))
                {
                    printf("No hay empleados en sistema\n\n");
                }
                break;
            case 7:
                controller_sortEmployee(listEmployees);
                break;
            case 8:
                if(controller_saveAsText("data.csv", listEmployees))
                {
                    printf("Datos guardados\n\n");
                }
                else
                {
                    printf("No se han podido guardar los datos\n\n");
                }
                break;
            case 9:
                if(controller_saveAsBinary("data.bin", listEmployees))
                {
                    printf("Datos guardados\n\n");
                }
                else
                {
                    printf("No se han podido guardar los datos\n\n");
                }
                break;
            case 10:
                exit = getChar("Confirma salida? (s/n) ");
                break;
        }

        printf("\n");
        system("pause");
        system("cls");

    }while(exit != 's');

    ll_deleteLinkedList(listEmployees);
    return 0;
}
