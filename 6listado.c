#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "0fecha.h"
#include "1alumnos.h"
#include "4grupos.h"
#include "5inscripciones.h"

void capturaListado()
{
    char opcion;
    struct alumno a;
    char car[30], carrera[30];
    int ctr = getContadorAlumno();
    struct grupo g;
    int clave;
    int ctrG = getContadorGrupo();
    struct fecha f;
    struct fecha fgrupo;
    int num;
    int ctrI = getContadorInsc();
    struct inscripcion in;
    struct fecha finsc;

    do
    {
        printf("\n----------------------------------\n");
        printf("a. Listado de alumnos por carrera\n");
        printf("b. Listado de materias que imparte un profesor\n");
        printf("c. Listado de grupos por fecha\n");
        printf("d. Listado de inscripciones por grupo\n");
        printf("e. Generar archivo de alumnos\n");
        printf("f. Generar archivo de profesores\n");
        printf("g. Mostrar archivo\n");
        printf("h. Salir de reportes\n");
        printf("\nIngrese la opcion deseada: ");
        scanf(" %c", &opcion);
        while (!isalpha(opcion))
        {
            printf("%c no es una letra. Solo se aceptan caracteres: ", opcion);
            scanf(" %c", &opcion);
        }

        switch (opcion)
        {
        case 'a':
            printf("Cual carrera quiere listar: ");
            scanf("%s", carrera);
            printf("MATRICULA      NOMBRE          CARRERA     SEM    FECHA DE NAC     CORREO            TELEFONO");
            for (int i = 0; i < ctr; i++)
            {
                if (strcmp(carrera, getAlumnoCarrera(i)) == 0)
                {
                    a = getAlumno(i);
                    f = getAlumnoFecha(i);
                    printf("\n%d         %s            %s       %d        ",
                           a.matricula_alumno_struct, a.nombre_alumno_struct, a.carrera_alumno_struct, a.semestre_alumno_struct);
                    printFecha(f);
                    printf("           %s        %s",
                           a.correo_alumno_struct, a.telefono_alumno_struct);
                }
            }
            break;

        case 'b':
            printf("Ingrese la clave del profesor: ");
            scanf("%d", &clave);
            printf("CLAVE     MATERIAS");
            for (int i = 0; i < ctrG; i++)
            {
                if (clave == getGrupoProfesor(i))
                {
                    g = getGrupo(i);
                    printf("\n%d         %s            ", g.clave_grupo_struct, g.nom_materia_struct);
                }
            }
            break;

        case 'c':
            printf("Ingrese la fecha a consultar... ");
            printf("Dia (DD):");
            scanf("%d", &f.dia);
            printf("Mes (MM)):");
            scanf("%d", &f.mes);
            printf("Año (AAAA):");
            scanf("%d", &f.anio);
            printf("FECHA     NUMERO        SEMESTRE     CLAVE      PROFESOR\n");
            for (int i = 0; i < ctrG; i++)
            {
                fgrupo = getGrupoFecha(i);
                if ((f.anio == fgrupo.anio) && (f.mes == fgrupo.mes) && (f.dia == fgrupo.dia))
                {
                    g = getGrupo(i);
                    printFecha(fgrupo);
                    printf("        %d      %d    %d         %d ", g.numero_grupo_struct, g.semestre_grupo_struct, g.clave_grupo_struct, g.numero_profesor_grupo_struct);
                }
                else if (f.anio < fgrupo.anio)
                {
                    g = getGrupo(i);
                    printFecha(fgrupo);
                    printf("        %d      %d    %d         %d ", g.numero_grupo_struct, g.semestre_grupo_struct, g.clave_grupo_struct, g.numero_profesor_grupo_struct);
                }
                else if (f.anio == fgrupo.anio)
                {
                    if (f.mes < fgrupo.mes)
                    {
                        g = getGrupo(i);
                        printFecha(fgrupo);
                        printf("        %d      %d    %d         %d ", g.numero_grupo_struct, g.semestre_grupo_struct, g.clave_grupo_struct, g.numero_profesor_grupo_struct);
                    }
                    else if (f.mes == fgrupo.mes)
                    {
                        if (f.dia < fgrupo.dia)
                        {
                            g = getGrupo(i);
                            printFecha(fgrupo);
                            printf("        %d      %d    %d         %d ", g.numero_grupo_struct, g.semestre_grupo_struct, g.clave_grupo_struct, g.numero_profesor_grupo_struct);
                        }
                        else
                        {
                            printf("No hay grupos creados en esa fecha o despues.");
                        }
                    }
                }
            }
            break;

        case 'd':
            printf("Ingrese el numero del grupo: ");
            scanf("%d", &num);
            printf("GRUPO     MATRICULA      FECHA DE INSC");
            printf("%d", ctrI);
            for (int i = 0; i < ctrG; i++)
            {
                if (num == getGrupoNumero(i))
                {
                    in = getInsc(i);
                    finsc = getInscFecha(i);
                    printf("\n%d        %d        ", in.numero_inscripcion, in.matricula_inscripcion);
                    printFecha(fgrupo);
                }
            }
            break;

        case 'e':

            break;
        case 'f':
            break;

        case 'g':
            break;

        case 'h':
            printf("Saliendo de los Reportes...");
            break;

        default:
            printf("Por favor escoga una de las opciones (a,b,c,d,e,f,g,h)");
            break;
        }
    } while (opcion != 'h');
}
