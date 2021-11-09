void capturaGrupo();
int buscarGrupo(int clave_grupo);
int getGrupoProfesor(int indice);
int getContadorGrupo();
extern struct grupo
{
    int numero_grupo_struct,
        semestre_grupo_struct,
        clave_grupo_struct,
        numero_profesor_grupo_struct;
    char nom_materia_struct[30];
    struct fecha f;
} g;
int getGrupoNumero(int indice);
struct grupo getGrupo(int indice);
struct fecha getGrupoFecha();