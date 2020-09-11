#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Pide al usuario que ingrese una opcion del menu y la devuelve validada
 *
 * \param min primera opcion del meun
 * \param max ultima opcion del menu, ambas para validar
 * \param message Texto que solicita el ingreso del numero
 * \param messageError Texto que indica que ingresó una dato inválido
 * \return Opcion elegida por el usuario
 *
 */

int getOption(int min, int max, char message[], char messageError[])
{
    char string[] = {};
    int num;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", string);

    num = atoi(string);

    while(num == 0 || (num>max || num<min))
    {
        printf("%s", messageError);
        fflush(stdin);
        scanf("%s", string);

        num = atoi(string);
    }

    return num;
}

/** \brief Pide al usuario que ingrese un numero y lo devuelve
 *
 * \param message Texto que solicita el ingreso del mismo
 * \param messageError Texto que indica que ingresó un dato erróneo
 * \return Cifra ingresada
 *
 */

 int getNumber(char message[], char messageError[])
{
    char string[] = {};
    int num;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", string);

    num = atoi(string);

    while(num == 0)
    {
        printf("%s", messageError);
        fflush(stdin);
        scanf("%s", string);

        num = atoi(string);
    }

    return num;
}

/** \brief Muestra el menu de opciones y pide al usuario que ingrese una opcion
 *
 * \param x El valor del primer numero
 * \param y El valor del segundo numero
 * \param flag1 Indica si el primer operando fue ingresado
 * \param flag2 Indica si el segundo operando fue ingresado
 * \return La opcion ingresada por el usuario
 *
 */

int showMenu(int x, int y, int flag1, int flag2)
{
    if(flag1 == 1)
    {
        printf("1. Ingrese 1er operando (A=%d)\n", x);
    }
    else
    {
        printf("1. Ingrese 1er operando (A=X)\n");
    }

    if(flag2 == 1)
    {
        printf("2. Ingrese 2do operando (B=%d)\n", y);
    }
    else
    {
        printf("2. Ingrese 2do operando (B=Y)\n");
    }

    printf("3. Calcular todas las operaciones\n");
    printf("  a) Calcular la suma (A+B)\n");
    printf("  b) Calcular la resta (A-B)\n");
    printf("  c) Calcular la division (A/B)\n");
    printf("  d) Calcular la multiplicacion (A*B)\n");
    printf("  e) Calcular los factoriales (A!) (B!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");

    return getOption(1, 5, "Ingrese una opcion: ", "Error, reingrese una opcion: ");
}

/** \brief Calcula la suma entre dos numeros
 *
 * \param x Valor del primer operando
 * \param y Valor del segundo operando
 * \return El resultado de la operacion
 *
 */

int add(int x, int y)
{
    return x+y;
}

/** \brief Calcula la resta entre dos numeros
 *
 * \param x Valor del primer operando
 * \param y Valor del segundo operando
 * \return El resultado de la operación
 *
 */
int substract(int x, int y)
{
    return x-y;
}

/** \brief Calcula la multiplicacion entre dos numeros
 *
 * \param x Valor del primer operando
 * \param y Valor del segundo operando
 * \return El resultado de la operación
 *
 */
int multiplicate(int x, int y)
{
    return x*y;
}

/** \brief Calcula la division entre dos numeros
 *
 * \param x Valor del primer operando
 * \param y Valor del segundo operando
 * \return El resultado de la operación
 *
 */
float divide(int x, int y)
{
    return (float)x/y;
}

/** \brief Calcula el factorial de un numero
 *
 * \param x Valor del numero
 * \return El resultado de la operación
 *
 */
long long int factorial(int num)
{
    long long int result = 1;

    if(num>-1)
    {
        for(int i=num; i>1; i--)
        {
            result = result * i;
        }
    }
    else
    {
        result = 0;
    }

    return result;
}

/** \brief Muestra los resultados de las operaciones entre los numeros
 *
 * \param x Valor del primer operando
 * \param y Valor del segundo operando
 * \param addition Resultado de la suma entre ambos
 * \param substraction Resultado de la resta entre ambos
 * \param multiplication Resultado de la multiplicación entre ambos
 * \param division Resultado de la división entre ambos
 * \param fact1 Resultado del factorial del primer numero
 * \param fact2 Resultado del factorial del segundo numero
 *
 */

void showResults(int x, int y, int addition, int substraction, int multiplication, float division, long long int fact1, long long int fact2)
{
    printf("\nEl resultado de %d+%d = %d\n", x, y, addition);
    printf("El resultado de %d-%d = %d\n", x, y, substraction);

    if(y!=0)
    {
        printf("El resultado de %d/%d = %.2f\n", x, y, division);
    }
    else
    {
        printf("No es posible dividir por cero\n");
    }

    printf("El resultado de %d*%d = %d\n", x, y, multiplication);
    printf("El factorial de %d = %lld\n", x, fact1);
    printf("El factorial de %d = %lld\n", y, fact2);
}

