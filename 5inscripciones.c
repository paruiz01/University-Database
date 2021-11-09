#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "valida.h"
#include "1alumnos.h"
#include "4grupos.h"

int contadorInscripcion = 0;

struct inscripcion
{
    int numero_inscripcion, matricula_inscripcion;
    struct fecha f;
} in[100];

void capturaInscripcion()
{
    int valida_grupo = 0;
    int grupo = 0;
    int matricula = 0;
    int valida_matricula = 0;
    char opcion5[5];
    do
    {

        while (valida_grupo == 0)
        {
            printf("Ingrese la clave del grupo(A lo más 7): ");
            scanf("%d", &grupo);
            valida_grupo = buscarGrupo(grupo);
        }
        in[contadorInscripcion].numero_inscripcion = grupo;

        while (valida_matricula == 0)
        {
            printf("Ingrese la matricula del alumno: ");
            scanf("%d", &matricula);
            valida_matricula = buscarMatricula(matricula);
        }
        in[contadorInscripcion].matricula_inscripcion = matricula;

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        in[contadorInscripcion].f.dia = tm.tm_mday;
        in[contadorInscripcion].f.mes = tm.tm_mon + 1;
        in[contadorInscripcion].f.anio = tm.tm_year + 1900;
        printf("La fecha de hoy es: ");
        printFecha(in[contadorInscripcion].f);

        printf("¿Quiere otra inscripcion? R= ");
        scanf("%s", opcion5);

        contadorInscripcion++;

        valida_matricula = 0;
        valida_grupo = 0;

    } while (*opcion5 == 'S');
}

int getContadorInsc()
{
    return contadorInscripcion;
}

struct inscripcion getInsc(int indice)
{
    return in[indice];
}

struct fecha getInscFecha(int indice)
{
    return in[indice].f;
}