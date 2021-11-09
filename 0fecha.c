#include <stdio.h>
#include <string.h>

struct fecha
{
    int dia, mes, anio;
} f;

void printFecha(struct fecha f)
{
    printf("%02d/%02d/%d", f.dia, f.mes, f.anio);
}