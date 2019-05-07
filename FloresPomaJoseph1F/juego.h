typedef struct
{
    int CodigoJuego;
    char Descripcion[51];
    float importe;
    int estado;

}eJuegos;

void juego_inicializar( eJuegos games[], int cantidad);
int juego_buscarEspacioLibre(eJuegos games[], int cantidad);
int juego_buscarPorCodigo(eJuegos games[], int cantidad, int auxCodJuego);

void mostrarUnJuego(eJuegos games);
void juego_mostrarTodo(eJuegos games[], int cantidad);
void juego_ingresoDatos(eJuegos games[],int espacioLibre, int auxCodJuego,char auxDescripcion[], float auxImporte);

void juego_alta(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte);
void juego_modificar(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte);
void juego_baja(eJuegos games[], int cantidad, int auxCodJuego);

void juego_ordenarPorImporteYDescripcion(eJuegos games[], int cantidad);

void juego_admin(eJuegos games[], int cantidad);

