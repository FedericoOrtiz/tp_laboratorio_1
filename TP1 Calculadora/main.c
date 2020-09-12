/*******************************************************************
* Programa: Calculadora
* Objetivo:
Ingresar dos numeros.
Realizar operaciones de suma, resta, multiplicacion, division y factorial.
Mostrar los resultados
*
* Version: 1.0
* Autor: Federico Agustin Ortiz
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int option;
    int x;
    int y;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int addition;
    int substraction;
    float division;
    int multiplication;
    long long int fact1;
    long long int fact2;

    char exit = 'n';

    do
    {
        option = showMenu(x, y, flag1, flag2);

        switch(option)
        {
            case 1:
                x = getNumber("Ingrese un numero: ", "Error, ingrese un numero: ");
                flag1 = 1;
                break;
            case 2:
                y = getNumber("Ingrese un numero: ", "Error, ingrese un numero: ");
                flag2 = 1;
                break;
            case 3:
                if(flag1 == 0 || flag2 == 0)
                {
                    printf("Primero debe ingresar ambos numeros\n");
                }
                else
                {
                    printf("Realizando operaciones...\n");
                    addition = add(x,y);
                    substraction = substract(x,y);
                    division = divide(x,y);
                    multiplication = multiplicate(x,y);
                    fact1 = factorial(x);
                    fact2 = factorial(y);
                    flag3 = 1;
                }
                break;
            case 4:
                if(flag3 == 0)
                {
                    printf("Primero debe calcular los resultados\n");
                }
                else
                {
                    showResults(x, y, addition, substraction, multiplication, division, fact1, fact2);
                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                }
                break;
            case 5:
                printf("\nConfirma salida?(s/n) ");
                fflush(stdin);
                exit = getchar();
                exit = tolower(exit);
                break;
            default:
                break;
        }

        printf("\n");
        system("pause");
        system("cls");

    }while(exit != 's');

    return 0;
}
