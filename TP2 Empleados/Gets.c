#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gets.h"

int validateInt(char string[])
{
    int i = 0;
    int r = 0;

    while(string[i]!='\0')
    {
        if((string[0]=='\n' || string[i]==' ') && (string[i]<'0' || string[i]>'9'))
        {
            r = -1;
        }
        i++;
    }
    return r;
}

int validateFloat(char string[])
{
    int i = 0;
    int r = 0;

    while(string[i] != '\0')
    {
        if((string[0]=='\n' || string[i]==' ') && (string[i]<'0' || string[i]>'9' || string[i] != '.'))
        {
            r = -1;
        }
        i++;
    }

    return r;
}

int validateString(char string[])
{
    int i = 0;
    int r = 0;
    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
        {
            r = -1;
        }
        i++;
    }
    return r;
}

int getInt(int min, int max, char message[])
{
    int num;
    char string[11];

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(string);

        while(validateInt(string)!= 0 || string[0] == '\0')
        {
            printf("Ingrese una dato valido: ");
            fflush(stdin);
            gets(string);
        }

        num = atoi(string);
    }while(num>max || num<min);

    return num;
}

float getFloat(float min, float max, char message[])
{
    float num;
    char string[11];

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(string);

        while(validateFloat(string)!= 0 || string[0] == '\0')
        {
            printf("Ingrese una dato valido: ");
            fflush(stdin);
            gets(string);
        }

        num = atof(string);
    }while(num>max || num<min);

    return num;
}

char getChar(char message[])
{
    char letter;

    printf("%s", message);
    fflush(stdin);
    letter = getchar();
    letter = tolower(letter);

    while((letter == '\0' || letter == ' ') && (letter<'a' || letter>'z'))
    {
        printf("Ingrese un dato valido: ");
        fflush(stdin);
        letter = getchar();
        letter = tolower(letter);
    }

    return letter;
}

void getString(char string[], int min, int max, char message[])
{
    printf("%s",message);
    fflush(stdin);
    gets(string);

    while(validateString(string)!= 0 || string[0] == '\0' || string[0] == ' ' || (strlen(string)<min || strlen(string)>max))
    {
        printf("Ingrese un dato valido: ");
        fflush(stdin);
        gets(string);
    }

    strlwr(string);
    string[0] = toupper(string[0]);

    for(int i=1; i<max; i++)
    {
        if(string[i] == ' ')
        {
            string[i+1] = toupper(string[i+1]);
        }
    }
}
