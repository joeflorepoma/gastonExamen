typedef struct
{
    int idAutores; // Código de Autor (autoincremental arrancando en 1000)
    char name[31];
    char lastName[31];
    int isEmpty;
}eAutores;

void autor_inicializar(eAutores aut[],int cantidad);
int autor_buscarLibre(eAutores aut[],int cantidad);
int autor_buscarPorId(eAutores aut[],int cantidad, int aux);
void autor_alta(eAutores aut[], int cantidad);
void autor_listar(eAutores aut[],int cantidad);
void autor_imprimir(eAutores aut[],int indice);
void autor_baja(eAutores aut[],int cantidad);
void autor_modificar(eAutores aut[],int cantidad);
void autor_menu(eAutores aut[],int cantidad);
void autor_ordenar(eAutores aut[],int cantidad);

