#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "0fecha.h"

int mayorQueCero(int number)
{
  if (number > 0)
    return 1;
  else
    return 0;
}

int longDeString(const char *arr)
{
  int size = 0;

  while (*arr)
  {
    size += 1;
    arr += 1;
  }

  return size;
}

int entreUnoyDiez(int num)
{
  return (num >= 1 && num <= 10);
}

int entreUnoySeis(int num2)
{
  return (num2 >= 1 && num2 <= 6);
}

int validateBirthDate(struct fecha f)
{
  int dia, mes, anio;
  dia = f.dia;
  mes = f.mes;
  anio = f.anio;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  // La siguiente linea despliega la fecha de hoy
  //printf("La fecha de hoy es: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

  //sscanf(birthDate, "%d/%d/%d", &dia, &mes, &anio);

  // Los ticks se utilizan para calcular que la fecha de nacimiento sea
  // menor que la fecha de hoy
  int ticks_hoy = tm.tm_mday + tm.tm_mon + 1 + tm.tm_year + 1900;
  int ticks_nacimiento = dia + mes + anio;

  if (ticks_hoy <= ticks_nacimiento)
  {
    return 0;
  }
  if (dia < 1 || dia > 31)
  {
    return 0;
  }
  if (mes < 1 || mes > 12)
  {
    return 0;
  }
  if (anio < 1900 || anio > tm.tm_year + 1900)
  {
    return 0;
  }

  return 1;
}

int findCharInString(char *string, char character)
{
  int i;
  for (i = 0; i < strlen(string); i++)
  {
    if (string[i] == character)
    {
      return 1;
    }
  }
  return 0;
}

int validate10DigitNumber(char *number)
{
  int i;
  int count = 0;
  for (i = 0; i < 20; i++)
  {
    if (number[i] >= '0' && number[i] <= '9')
    {
      count++;
    }
  }

  if (count > 10)
  {
    return 0;
  }

  if (count == 10)
  {
    return 1;
  }

  return 0;
}