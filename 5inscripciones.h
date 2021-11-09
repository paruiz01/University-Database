void capturaInscripcion();
extern struct inscripcion
{
    int numero_inscripcion, matricula_inscripcion;
    struct fecha f;
} in;
int getContadorInsc();
struct inscripcion getInsc(int indice);
struct fecha getInscFecha(int indice);