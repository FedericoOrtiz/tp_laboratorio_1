/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Gets.h"



int main(void)
{
    printf("                  ***** TESTEO DE FUNCIONES *****\n\n");
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort

    system("pause");
    system("cls");

    char exit = 'n';
    int loadFromText = 0;

    LinkedList* listEmployees = ll_newLinkedList();

    do
    {
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
                controller_addEmployee(listEmployees);
                break;
            case 3:
                controller_editEmployee(listEmployees);
                break;
            case 4:
                controller_removeEmployee(listEmployees);
                break;
            case 5:
                if(!loadFromText)
                {
                    printf("Primero debe cargar el archivo a sistema\n\n");
                }
                else if(!controller_ListEmployees(listEmployees))
                {
                    printf("No hay empleados en sistema\n\n");
                }
                break;
            case 6:
                controller_sortEmployee(listEmployees);
                break;
            case 7:
                if(controller_saveAsText("data.csv", listEmployees))
                {
                    printf("Datos guardados\n\n");
                }
                else
                {
                    printf("No se han podido guardar los datos\n\n");
                }
                break;
            case 8:
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

































