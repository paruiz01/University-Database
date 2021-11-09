#include <stdio.h>
#include <string.h>
#include "valida.h"

struct alumno
{
    int matricula_alumno_struct, semestre_alumno_struct, dia_alumno_struct, mes_alumno_struct, anio_alumno_struct;
    char nombre_alumno_struct[30], carrera_alumno_struct[30], correo_alumno_struct[40], telefono_alumno_struct[20];
    struct fecha nacimiento;
} a[100];

int contadorAlumno = 0;

void capturaAlumnos()
{
    int matricula_temp, semestre_temp, valida_mail = 0, valido = 0;
    char opcion[5], nombre_temp[30], str[100], fechaNacimiento[10], email[20], numero[20];
    int cadena = 0;
    int valida_nacimiento = 0;
    int valida_telefono = 0;

    do
    {
        do
        {
            printf("Ingrese su matricula: ");
            scanf("%d", &matricula_temp);
        } while (mayorQueCero(matricula_temp) == 0);
        a[contadorAlumno].matricula_alumno_struct = matricula_temp;

        while (cadena < 2)
        {
            printf("Ingrese su nombre: ");
            fgets(nombre_temp, 30, stdin);
            //scanf("%s", nombre_temp);
            cadena = longDeString(nombre_temp);
        }
        memcpy(&a[contadorAlumno].nombre_alumno_struct, nombre_temp, sizeof a[contadorAlumno].nombre_alumno_struct);

        printf("Ingrese su carrera: ");
        scanf("%s", a[contadorAlumno].carrera_alumno_struct);

        do
        {
            printf("Ingrese su semestre (solo ##): ");
            scanf("%d", &semestre_temp);
        } while (entreUnoyDiez(semestre_temp) == 0);
        a[contadorAlumno].semestre_alumno_struct = semestre_temp;

        while (valida_nacimiento != 1)
        {
            printf("Ingrese su fecha de nacimiento... ");
            printf("Dia (DD):");
            scanf("%d", &a[contadorAlumno].nacimiento.dia);
            printf("Mes (MM)):");
            scanf("%d", &a[contadorAlumno].nacimiento.mes);
            printf("Año (AAAA):");
            scanf("%d", &a[contadorAlumno].nacimiento.anio);
            valida_nacimiento = validateBirthDate(a[contadorAlumno].nacimiento);
        }

        while (valida_mail != 1)
        {
            printf("Ingrese su correo: ");
            scanf("%s", email);
            valida_mail = findCharInString(email, '@');
        }
        printf("Email valido\n");
        memcpy(&a[contadorAlumno].correo_alumno_struct, email, sizeof a[contadorAlumno].correo_alumno_struct);

        while (valida_telefono != 1)
        {
            printf("Ingrese su teléfono (10 digitos): ");
            scanf("%s", numero);
            valida_telefono = validate10DigitNumber(numero);
        }
        memcpy(&a[contadorAlumno].telefono_alumno_struct, numero, sizeof a[contadorAlumno].telefono_alumno_struct);

        printf("¿Quiere agregar otro alumno? R= ");
        scanf("%s", opcion);

        contadorAlumno++;

        valida_mail = 0;
        valida_telefono = 0;
        valida_nacimiento = 0;
        cadena = 0;

    } while (*opcion == 'S' || *opcion == 's');
}

int buscarMatricula(int matricula_alumno)
{
    int i;
    for (i = 0; i < contadorAlumno; i++)
    {
        if (a[i].matricula_alumno_struct == matricula_alumno)
        {
            return 1;
        }
    }
    return 0;
}

int getContadorAlumno()
{
    return contadorAlumno;
}
struct alumno getAlumno(int indice)
{
    return a[indice];
}

struct fecha getAlumnoFecha(int indice)
{
    return a[indice].nacimiento;
}

char *getAlumnoCarrera(int indice)
{
    return a[indice].carrera_alumno_struct;
}