
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int CodigoAlquiler;
    int idJuego;
    int idCliente;
    eFecha date;
    int estado;
}eAlquileres;

void alquier_inicializar(eAlquileres rent[], int cantidad);
int alquiler_buscarEspacioLibre(eAlquileres rent[], int cantidad);
int alquier_buscarPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler);

void mostrarUnAlquiler(eAlquileres rent);
void alquier_mostrarTodos(eAlquileres rent[], int cantidad);
void alquiler_ingresoDatos(eAlquileres rent[],int espacioLibre, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio);

void alquiler_alta(eAlquileres rent[], int cantidad, eClientes clientes[], int cantClientes, eJuegos juego [], int cantJuego, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio);
void alquiler_admin(eAlquileres rent[], eClientes cliente[], eJuegos juego[], int cantJuego, int canCliente, int cantidad);

void totalYpromedio(eJuegos juego[], int cantJuegos, eAlquileres alquiler[], int cantAlquiler);
void menosvotado(eAlquileres alquileres[], int cantAlquileres, eJuegos juego[], int cantJuego);
void burbujeoMasEficiente(eJuegos juego[],int cantJuego);
void insertion(eClientes cliente[],int cantCliente);


