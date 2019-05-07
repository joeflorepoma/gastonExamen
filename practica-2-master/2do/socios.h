typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codSocio;
    char apellido[31];
    char nombre[31];
    char sexo[5];
    char telefono[16];
    char eMail[31];
    eFecha fechaAsociado;
    int isEmpty;
}eSocios;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaPrestamo;

typedef struct
{
    int codPrestamo;
    int codLibro;
    int codSocio;
    eFechaPrestamo fechaPresta;
    int isEmpty;
}ePrestamo;

void socio_inicializar(eSocios socio[],int cantidad);
int socio_buscarLibre(eSocios socio[],int cantidad);
int socio_buscarPorId(eSocios socio[],int cantidad, int auxCodSocio);

void socio_alta(eSocios socio[], int cantidad);
void socio_modificar(eSocios socio[],int cantidad);
void socio_baja(eSocios socio[],int cantidad);

void socio_listar(eSocios socio[],int cantidad);
void socio_ordenarApeyNombre(eSocios socio[],int cantidad);

//prestamo
void prestamo_inicializar(ePrestamo prestamo[],int cantidad);
int prestamo_buscarLibre(ePrestamo prestamo[],int cantidad);
int prestamo_buscarPorId(ePrestamo prestamo[],int cantidad, int auxCodPrestamo);

void prestamo_alta(ePrestamo prestamo[], int cantidad,eSocios socio[], eLibros libro[]);

void socio_menu(eSocios socio[],int cantidad, eLibros libro[], ePrestamo prestamo[], eAutores autor[]);
