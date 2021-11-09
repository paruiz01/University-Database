void capturaProfesor();
int buscarProfesor(int clave_profesor);

extern struct profesor
{
    int clave_profesor_struct, coordinacion_profesor_struct;
    char nom_profesor_struct[30], mail_profesor_struct[40], celular_profesor_struct[20];
    struct fecha nacimiento;
} p;
