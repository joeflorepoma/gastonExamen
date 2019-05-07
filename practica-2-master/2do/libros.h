
typedef struct
{
    int idLibros;
    char titulo[51];
    int idAutor;
    int isEmpty;
}eLibros;

void libros_inicializar(eLibros lib[],int cantidad);
int libros_buscarLibre(eLibros lib[],int cantidad);
int libros_buscarPorId(eLibros lib[],int cantidad, int aux);
void libros_alta(eLibros lib[], int cantidad, eAutores aut[]);
void libros_listar(eLibros lib[],int cantidad);
void libros_imprimir(eLibros lib[],int indice);
void libros_baja(eLibros lib[],int cantidad);
void libros_modificar(eLibros lib[],int cantidad);
void libros_menu(eLibros lib[],int cantidad,eAutores aut[]);
void libros_ordenar(eLibros lib[],int cantidad);

