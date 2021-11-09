#include <stdio.h>
#include <string.h>
#include "valida.h"

struct profesor
{
    int clave_profesor_struct, coordinacion_profesor_struct;
    char nom_profesor_struct[30], mail_profesor_struct[40], celular_profesor_struct[20];
    struct fecha nacimiento;
} p[100];

int contadorProfesor = 0;

void capturaProfesor()
{
    int num_empleados, coordinacion_temp;
    char opcion3[5], nom_de_profesor[30], fechaNacimiento[11], email[40], celular[20];
    int validamail = 0;
    int valido = 0;
    int cadena = 0;
    int valida_nacimiento = 0;

    do
    {
        do
        {
            printf("Ingrese el numero del profesor(id): ");
            scanf("%d", &num_empleados);
        } while (mayorQueCero(num_empleados) == 0);
        p[contadorProfesor].clave_profesor_struct = num_empleados;

        while (cadena < 2)
        {
            printf("Ingrese el nombre del profesor: ");
            fgets(nom_de_profesor, 30, stdin);
            //scanf("%s", nom_de_profesor);
            cadena = longDeString(nom_de_profesor);
        }
        memcpy(&p[contadorProfesor].nom_profesor_struct, nom_de_profesor, sizeof p[contadorProfesor].nom_profesor_struct);

        do
        {
            printf("¿Cuál es la coordinación(Entre 1 y 6): ");
            scanf("%d", &coordinacion_temp);
        } while (entreUnoyDiez(coordinacion_temp) == 0);
        p[contadorProfesor].coordinacion_profesor_struct = coordinacion_temp;

        while (valida_nacimiento != 1)
        {
            printf("Ingrese su fecha de nacimiento... ");
            printf("Dia (DD):");
            scanf("%d", &p[contadorProfesor].nacimiento.dia);
            printf("Mes (MM)):");
            scanf("%d", &p[contadorProfesor].nacimiento.mes);
            printf("Año (AAAA):");
            scanf("%d", &p[contadorProfesor].nacimiento.anio);
            valida_nacimiento = validateBirthDate(p[contadorProfesor].nacimiento);
        }

        while (validamail != 1)
        {
            printf("Ingrese su correo: ");
            scanf("%s", email);
            validamail = findCharInString(email, '@');
        }
        p[contadorProfesor].mail_profesor_struct[39] = email[39];

        valido = 0;
        while (valido != 1)
        {
            printf("Ingrese su teléfono (10 digitos): ");
            scanf("%s", celular);
            valido = validate10DigitNumber(celular);
        }
        p[contadorProfesor].celular_profesor_struct[19] = celular[19];

        printf("¿Quiere agregar otro profesor? R= ");
        scanf("%s", opcion3);

        contadorProfesor++;

        validamail = 0;
        valido = 0;
        cadena = 0;
        valida_nacimiento = 0;
    } while (*opcion3 == 'S' || *opcion3 == 's');
}

int buscarProfesor(int clave_profesor)
{
    int i;
    for (i = 0; i < contadorProfesor; i++)
    {
        if (p[i].clave_profesor_struct == clave_profesor)
        {
            return 1;
        }
    }
    return 0;
}
