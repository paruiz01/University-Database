#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "valida.h"
#include "1alumnos.h"
#include "2materias.h"
#include "3profesores.h"
#include "4grupos.h"
#include "5inscripciones.h"
#include "6listado.h"

void clearscr(void)
{
    #ifdef _WIN32
        system("cls");
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system("clear");
    #endif
}

int main()
{
    clearscr();

    int opcion;
 
    do
    {
        printf("\n----------------------------------\n");
        printf("1. Alumnos\n");
        printf("2. Materias\n");
        printf("3. Profesor \n");
        printf("4. Grupo\n");
        printf("5. Inscripcion\n");
        printf("6. Reportes\n");
        printf("7. Salir\n");
        printf("\nIngrese la opcion deseada: ");
        scanf("%d", &opcion);
        while (opcion < 1 || opcion > 7)
        {
            printf("%d no es una opcion valida. Ingrese por favor la opcion deseada: ", opcion);
            scanf("%d", &opcion);
        }

        switch (opcion)
        {
            case 1:
                capturaAlumnos();
                break;
            case 2:
                capturaMateria();
                break;
            case 3:
                capturaProfesor();
                break;
            case 4:
                capturaGrupo();
                break;
            case 5:
                capturaInscripcion();
                break;
            case 6:
                capturaListado();
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Por favor escoga una de las opciones");
                scanf("%d", &opcion);
        }
    } while (opcion != 7);
}


