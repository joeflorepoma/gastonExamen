#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define ESC 27

#include "cliente.h"
#include "validaciones.h"

void cliente_inicializar(eClientes client[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        client[i].estado = 0;
    }
}

int cliente_buscarEspacioLibre(eClientes client[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(client[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

int cliente_buscarPorCodigo(eClientes client[], int cantidad, int auxCodCliente)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(client[i].estado == 1 && client[i].CodigoCliente == auxCodCliente)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnCliente(eClientes client)
{
    printf("\n | %15d  | %15s | %15s | %15s | %15s |\n", client.CodigoCliente, client.Nombre, client.Apellido, client.Domicilio, client.telefono);
}

void cliente_mostrarTodos(eClientes client[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Clientes---\n\n");

    printf("\n | %s15  | %15s | %15s | %15s | %15s |\n", "Cod.Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");

    for(i=0; i < cantidad; i++)
    {
        if(client[i].estado != 0)
        {
            mostrarUnCliente(client[i]);
        }
    }

    system("pause");
}

void cliente_ingresoDatos(eClientes client[],int espacioLibre, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    client[espacioLibre].CodigoCliente = auxCodCliente;
    strcpy(client[espacioLibre].Nombre,auxNombre);
    strcpy(client[espacioLibre].Apellido,auxApellido);
    strcpy(client[espacioLibre].Domicilio,auxDomicilio);
    strcpy(client[espacioLibre].telefono,auxTelefono);
    client[espacioLibre].estado = 1;
}

void cliente_alta(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Clientes-----\t\n\n");


    espacioLibre = cliente_buscarEspacioLibre(client, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodCliente = getValidInt("\nIngresa codigo de cliente: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = cliente_buscarPorCodigo(client, cantidad, auxCodCliente);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %s15  | %15s | %15s | %15s | %15s |\n", "Cod.Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
            mostrarUnCliente(client[busqueda]);

        }
        else
        {
            getValidString("Ingrese nombre del cliente: \n", "\nIngrese solo caracteres.\n\n", auxNombre,2,51);
            getValidString("Ingrese el apellido del cliente: \n", "\nIngrese solo caracteres.\n\n", auxApellido,2,51);
            getValidAlfaNumerico("Ingrese el domicilio del cliente: \n", "\nsolo caracteres y numeros.\n\n", auxDomicilio);
            getString("Ingrese el telefono: \n", auxTelefono);

            cliente_ingresoDatos(client, espacioLibre, auxCodCliente, auxNombre, auxApellido, auxDomicilio, auxTelefono);
        }
    }
    system("pause");
}

void cliente_modificar(eClientes client[], int cantidad, int auxCodCliente, char auxNombre[], char auxApellido[], char auxDomicilio[], char auxTelefono[])
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Clientes-----\t\n\n");


    auxCodCliente = getValidInt("\nIngrese el codigo de cliente a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 1000);

    busqueda = cliente_buscarPorCodigo(client, cantidad, auxCodCliente);

    if(busqueda == -1)
    {
        printf("\nEl Codigo del cliente no se encuentra en la base de datos.\n");
    }
    else
    {
        printf("\n | %15s  | %15s | %15s | %15s | %15s |\n", "Cod.Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
        mostrarUnCliente(client[busqueda]);

        getValidString("Re-ingrese nombre del cliente: \n", "\nIngrese solo caracteres.\n\n", auxNombre,2,52);
        getValidString("Re-ingrese el apellido del cliente: \n", "\nIngrese solo caracteres.\n\n", auxApellido,2,52);
        getValidAlfaNumerico("Re-ingrese el domicilio del cliente: \n", "\nsolo caracteres y numeros.\n\n", auxDomicilio);
        getString("Re-ingrese el telefono: \n", auxTelefono);

        cliente_ingresoDatos(client, busqueda, auxCodCliente, auxNombre, auxApellido, auxDomicilio, auxTelefono);
    }

    system("pause");
}

void cliente_baja(eClientes client[], int cantidad, int auxCodCliente)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Cliente-----\t\n\n");

    auxCodCliente = getValidInt("\nIngrese codigo a dar de baja: \n", "Ingrese solo numeros.\n", 1, 10000);

    busqueda = cliente_buscarPorCodigo(client, cantidad, auxCodCliente);

    if(busqueda == -1)
    {
        printf("\n El Codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {
        printf("\n | %15s  | %16s | %16s | %16s | %15s |\n", "Cod. Cliente", "Nombre", "Apellido", "Domicilio", "Telefono");
        mostrarUnCliente(client[busqueda]);

        do
        {
            printf("\n\nConfirma baja? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            client[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void cliente_ordenarPorApellidoNombre(eClientes client[], int cantidad)
{
    int i, j;
    eClientes auxiliar;

    for(i=0; i<cantidad-1; i++)
    {
        if(client[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(client[i].estado == 0)
            {
                continue;
            }

            if(strcmp(client[i].Apellido, client[j].Apellido)>0)
            {
                auxiliar = client[i];
                client[i] = client[j];
                client[j] = auxiliar;
            }
            if(strcmp(client[i].Apellido, client[j].Apellido)==0)
            {
                if(strcmp(client[i].Nombre, client[j].Nombre)>0)
                {
                    auxiliar = client[i];
                    client[i] = client[j];
                    client[j] = auxiliar;
                }


            }

        }
    }
}

void cliente_admin(eClientes client[], int cantidad)
{

    int auxCodigoCliente = 0;
    char auxNombre[51];
    char auxApellido[51];
    char auxDireccion[51];
    char auxTelefono[21];

    char opcion;

    do
    {
        system("cls");
        printf("\n-------\tABM CLIENTES\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            cliente_alta(client, cantidad, auxCodigoCliente, auxNombre, auxApellido, auxDireccion, auxTelefono);

            break;
        case '2':

            cliente_modificar(client, cantidad, auxCodigoCliente, auxNombre, auxApellido, auxDireccion, auxTelefono);
            break;
        case '3':

            cliente_baja(client, cantidad, auxCodigoCliente);
            break;
        case '4':

            cliente_ordenarPorApellidoNombre(client, cantidad);
            cliente_mostrarTodos(client, cantidad);
            break;
        case ESC:
            system("cls");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }while(opcion != ESC);
}
