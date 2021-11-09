#include <stdio.h>
#include <string.h>
#include "valida.h"

struct materia
{
    int clave_materia_struct, semestre_materia_struct;
    char nom_materia_struct[30];
} m[100];

int contadorMateria = 0;

void capturaMateria()
{
    int clave_temp, cadena = 0, semestre_materia;
    char opcion2[5], nom_materia[20];
    do
    {
        do
        {
            printf("Ingrese la clave de la materia: ");
            scanf("%d", &clave_temp);
        } while (mayorQueCero(clave_temp) == 0);
        m[contadorMateria].clave_materia_struct = clave_temp;

        while (cadena < 2)
        {
            printf("Ingrese el nombre de la materia:");
            fgets(nom_materia, 30, stdin);
            //scanf("%s", nom_materia);
            cadena = longDeString(nom_materia);
        }
        memcpy(&m[contadorMateria].nom_materia_struct, nom_materia, sizeof m[contadorMateria].nom_materia_struct);

        do
        {
            printf("Ingrese su semestre: ");
            scanf(" %d", &semestre_materia);
        } while (entreUnoyDiez(semestre_materia) == 0);
        m[contadorMateria].semestre_materia_struct = semestre_materia;

        printf("¿Quiere agregar otra materia? R= ");
        scanf("%s", opcion2);

        contadorMateria++;

        cadena = 0;

    } while (*opcion2 == 'S' || *opcion2 == 's');
}

int buscarMateria(int clave_materia)
{
    int i;
    for (i = 0; i < contadorMateria; i++)
    {
        if (m[i].clave_materia_struct == clave_materia)
        {
            return 1;
        }
    }
    return 0;
}

char *getMateriaNom(int clave)
{
    for (int i = 0; i < contadorMateria; i++)
    {
        if (m[i].clave_materia_struct == clave)
        {
            return m[i].nom_materia_struct;
        }
    }
    return "N/A";
}