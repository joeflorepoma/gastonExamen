typedef struct
{
    int CodigoCliente;
    char Apellido[51];
    char Nombre[51];
    char Domicilio[51];
    char telefono[21];
    int estado;

}eClientes;

void cliente_inicializar(eClientes client[], int cantidad);
int cliente_buscarEspacioLibre(eClientes client[], int cantidad);
int cliente_buscarPorCodigo(eClientes client[], int cantidad, int auxCodCliente);

void mostrarUnCliente(eClientes client);
void cliente_mostrarTodos(eClientes client[], int cantidad);
void cliente_ingresoDatos(eClientes client[],int espacioLibre, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);

void cliente_alta(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);
void cliente_modificar(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[]);
void cliente_baja(eClientes client[], int cantidad, int auxCodCliente);

void cliente_ordenarPorApellidoNombre(eClientes client[], int cantidad);

void cliente_admin(eClientes client[], int cantidad);
