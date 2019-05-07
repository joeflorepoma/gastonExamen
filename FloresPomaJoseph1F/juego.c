#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define ESC 27

#include "juego.h"
#include "validaciones.h"

void juego_inicializar( eJuegos games[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        games[i].estado = 0;
    }
}

int juego_buscarEspacioLibre(eJuegos games[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(games[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

int juego_buscarPorCodigo(eJuegos games[], int cantidad, int auxCodJuego)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(games[i].estado == 1 && games[i].CodigoJuego == auxCodJuego)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnJuego(eJuegos games)
{
    printf("\n | %6d  | %18s | %6.2f |\n", games.CodigoJuego, games.Descripcion, games.importe);
}

void juego_mostrarTodo(eJuegos games[], int cantidad)
{
    int i;


    printf("---Lista de Juegos---\n\n");

    printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");

    for(i=0; i < cantidad; i++)
    {
        if(games[i].estado != 0)
        {
            mostrarUnJuego(games[i]);
        }
    }
    system("pause");
}

void juego_ingresoDatos(eJuegos games[],int espacioLibre, int auxCodJuego,char auxDescripcion[], float auxImporte)
{
    games[espacioLibre].CodigoJuego = auxCodJuego;
    strcpy(games[espacioLibre].Descripcion,auxDescripcion);
    games[espacioLibre].importe = auxImporte;
    games[espacioLibre].estado = 1;
}

void juego_alta(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte)
{
    int espacioLibre;
    int busqueda;

    system("cls");

    printf("\n\t-----Alta de Juegos-----\t\n\n");


    espacioLibre = juego_buscarEspacioLibre(games, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodJuego = getValidInt("\nIngresa codigo de juego: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = juego_buscarPorCodigo(games, cantidad, auxCodJuego);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
            mostrarUnJuego(games[busqueda]);

        }
        else
        {
            getValidString("Ingrese descripcion del juego: \n", "\nIngrese solo caracteres.\n\n", auxDescripcion,2,51);
            auxImporte = getValidFloat("Ingrese el importe del juego: \n", "\nIngrese numeros reales.\n\n",1.0, 10000.0);
            juego_ingresoDatos(games, espacioLibre, auxCodJuego, auxDescripcion, auxImporte);

        }
    }
    system("pause");
}

void juego_modificar(eJuegos games[], int cantidad, int auxCodJuego, char auxDescripcion[], float auxImporte)
{
    int busqueda;

    system("cls");

    printf("\n\t-----Modificacion de Juegos-----\t\n\n");


    auxCodJuego = getValidInt("\nIngrese el codigo de juego a modificar: \n", "\nIngrese solo numeros.\n\n", 1, 1000);

    busqueda = juego_buscarPorCodigo(games, cantidad, auxCodJuego);

    if(busqueda == -1)
    {
        printf("\nEl Codigo del juego no se encuentra en la base de datos.\n");
    }
    else
    {
        printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
        mostrarUnJuego(games[busqueda]);

        getValidString("Re-ingrese descripcion del juego: \n", "\nIngrese solo caracteres.\n\n", auxDescripcion,2,51);
        auxImporte = getValidFloat("Re-ingrese el importe del juego: \n", "\nIngrese numeros reales.\n\n", 1.0, 10000.0);

        juego_ingresoDatos(games, busqueda, auxCodJuego, auxDescripcion, auxImporte);
    }

    system("pause");
}

void juego_baja(eJuegos games[], int cantidad, int auxCodJuego)
{
    int busqueda;
    char confirma;

    system("cls");

    printf("\n\t-----Baja de Juegos-----\t\n\n");

    auxCodJuego = getValidInt("\nIngrese codigo a dar de baja: \n", "Ingrese solo numeros.\n", 1, 10000);

    busqueda = juego_buscarPorCodigo(games, cantidad, auxCodJuego);

    if(busqueda == -1)
    {
        printf("\n El Codigo a dar de baja no se encuentra en la base de dato.\n\n");

    }
    else
    {
        printf("\n | %6s  | %18s | %6s |\n", "Cod. juego", "Descripcion", "Importe");
        mostrarUnJuego(games[busqueda]);

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
            games[busqueda].estado = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }

    system("pause");
}

void juego_ordenarPorImporteYDescripcion(eJuegos games[], int cantidad)
{
    int i, j;
    eJuegos auxiliar;

    for(i=0; i<cantidad-1; i++)
    {
        if(games[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j<cantidad; j++)
        {
            if(games[j].estado == 0)
            {
                continue;
            }

            if(games[i].importe > games[j].importe)
            {
                auxiliar = games[i];
                games[i] = games[j];
                games[j] = auxiliar;
            }
            if(games[i].importe == games[j].importe)
            {
                if( strcmp(games[i].Descripcion,games[j].Descripcion)==0)
                {
                    auxiliar = games[i];
                    games[i] = games[j];
                    games[j] = auxiliar;
                }


            }

        }
    }
}

void juego_admin(eJuegos games[], int cantidad)
{

    int auxCodigoJuego = 0;
    char auxDescripcion[51];
    float auxImporte = 0;

    char opcion;


    do
    {
        system("cls");
        printf("\n-------\tABM JUEGOS\t-------\n");
        printf("\n1.- Alta: \n2.- Modificacion : \n3.- Baja : \n4.- Listar: \nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            juego_alta(games, cantidad, auxCodigoJuego, auxDescripcion, auxImporte);

            break;
        case '2':

            juego_modificar(games, cantidad, auxCodigoJuego, auxDescripcion, auxImporte);
            break;
        case '3':

            juego_baja(games, cantidad, auxCodigoJuego);
            break;
        case '4':

            juego_ordenarPorImporteYDescripcion(games, cantidad);
            juego_mostrarTodo(games, cantidad);
            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }while(opcion != ESC);
}
