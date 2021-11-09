#include <stdio.h>
#include <string.h>
#include <time.h>
#include "valida.h"
#include "2materias.h"
#include "3profesores.h"

int contadorGrupo = 0;

struct grupo
{
    int numero_grupo_struct,
        semestre_grupo_struct,
        clave_grupo_struct,
        numero_profesor_grupo_struct;
    char nom_materia_struct[30];
    struct fecha f;
} g[100];

void capturaGrupo()
{
    int num_de_grupo = 0;
    int semestre_grupo = 0;
    int materia = 0;
    int profesor = 0;
    char opcion4[5];
    int valida_materia = 0;
    int valida_profesor = 0;
    int fecha_a = 0;

    do
    {
        do
        {
            printf("Ingrese el numero de grupo: ");
            scanf("%d", &num_de_grupo);
        } while (mayorQueCero(num_de_grupo) == 0);
        g[contadorGrupo].numero_grupo_struct = num_de_grupo;

        do
        {
            printf("Ingrese el semestre donde se encuentra el grupo: ");
            scanf("%d", &semestre_grupo);
        } while (entreUnoyDiez(semestre_grupo) == 0);
        g[contadorGrupo].semestre_grupo_struct = semestre_grupo;

        while (valida_materia == 0)
        {
            printf("Ingrese la clave de la materia(A lo más 7): ");
            scanf("%d", &materia);
            valida_materia = buscarMateria(materia);
        }
        g[contadorGrupo].clave_grupo_struct = materia;
        memcpy(&g[contadorGrupo].nom_materia_struct, getMateriaNom(materia), sizeof g[contadorGrupo].nom_materia_struct);

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        g[contadorGrupo].f.dia = tm.tm_mday;
        g[contadorGrupo].f.mes = tm.tm_mon + 1;
        g[contadorGrupo].f.anio = tm.tm_year + 1900;
        printf("La fecha de hoy es: ");
        printFecha(g[contadorGrupo].f);

        while (valida_profesor == 0)
        {
            printf("Ingrese el numero del profesor: ");
            scanf("%d", &profesor);
            valida_profesor = buscarProfesor(profesor);
        }
        g[contadorGrupo].numero_profesor_grupo_struct = profesor;

        printf("¿Quiere agregar otro grupo? R= ");
        scanf("%s", opcion4);

        contadorGrupo++;

        valida_materia = 0;
        valida_profesor = 0;

    } while (*opcion4 == 'S' || *opcion4 == 's');
}

int buscarGrupo(int clave_grupo)
{
    int i;
    for (i = 0; i < contadorGrupo; i++)
    {
        if (g[i].numero_grupo_struct == clave_grupo)
        {
            return 1;
        }
    }
    return 0;
}

int getContadorGrupo()
{
    return contadorGrupo;
}

struct grupo getGrupo(int indice)
{
    return g[indice];
}

int getGrupoProfesor(int indice)
{
    return g[indice].numero_profesor_grupo_struct;
}

int getGrupoNumero(int indice)
{
    return g[indice].numero_grupo_struct;
}

struct fecha getGrupoFecha(int indice)
{
    return g[indice].f;
}
