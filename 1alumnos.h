void capturaAlumnos();
int buscarMatricula(int matricula_alumno);
extern struct alumno
{
    int matricula_alumno_struct, semestre_alumno_struct, dia_alumno_struct, mes_alumno_struct, anio_alumno_struct;
    char nombre_alumno_struct[30], carrera_alumno_struct[30], correo_alumno_struct[40], telefono_alumno_struct[20];
    struct fecha nacimiento;
} a;
int getContadorAlumno();
struct alumno getAlumno(int indice);
struct fecha getAlumnoFecha(int indice);
char *getAlumnoCarrera(int indice);
