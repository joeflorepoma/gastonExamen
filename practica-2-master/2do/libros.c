#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "validacionesUTN.h"
#include "autores.h"
#include "libros.h"

#define ESC 27

void libros_inicializar(eLibros lib[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lib[i].isEmpty=0;
    }
}

int libros_buscarLibre(eLibros lib[],int cantidad)
{
    int i;
    int indice=-1;  //si devuelve -1 es que esta lleno, si devuelve el indice es porque el lugar esta libre
    for (i=0; i<cantidad; i++)
    {


        if (lib[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int libros_buscarPorId(eLibros lib[],int cantidad, int aux)
{
    int i;
    int indice =-1;

    for(i=0; i<cantidad; i++)
    {
        if(lib[i].isEmpty==1 && lib[i].idLibros == aux)
        {
            indice=i;
            break;
        }

    }

    return indice;
}

void libros_alta(eLibros lib[], int cantidad,eAutores aut[])
{

    char auxtitulo[51];
    int auxIdAutor;

    int indiceEspacioLibre;

    int resultadoBusquedaPorIdAutores;


    system("cls");

    printf("---ALTA LIBROS---\n\n");

    indiceEspacioLibre = libros_buscarLibre(lib,cantidad);

    if(indiceEspacioLibre == -1 )
    {
        printf("No quedan mas espacios libres\n");
    }

    else
    {


        getValidString("Ingrese Titulo del libro: \n","Ingrese solo letras",auxtitulo,1,51);
        auxIdAutor=getValidInt("Ingrese ID de autor:","Solo numeros",1,100);
        resultadoBusquedaPorIdAutores=autor_buscarPorId(aut,cantidad,auxIdAutor);

        if(resultadoBusquedaPorIdAutores==-1)
        {
            printf("ESe autor no existe");
        }
        else
        {

            strcpy(lib[indiceEspacioLibre].titulo,auxtitulo);
            lib[indiceEspacioLibre].idAutor = auxIdAutor;
            lib[indiceEspacioLibre].isEmpty=1;
        }

    }

    system("pause");
    system("cls");

}


void libros_listar(eLibros lib[],int cantidad)
{
    int i;

    system("cls");

    printf("---LISTA LIBROS---\n\n");

    for (i=0; i<cantidad; i++)
    {
        if(lib[i].isEmpty==1)
        {
            printf("%d\t%s\t%d\n",lib[i].idLibros,lib[i].titulo, lib[i].idAutor);
        }

    }

    system("pause");

}


void libros_imprimir(eLibros lib[],int indice)
{

    printf("%d\t%s\n",lib[indice].idLibros,lib[indice].titulo);

}


void libros_baja(eLibros lib[],int cantidad)
{
    int auxId;
    int resultadoBuscarID;
    char opcion;

    system("cls");

    printf("---BAJA LIBROS---\n\n");

    auxId=getValidInt("\nIngrese un numero de ID:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=libros_buscarPorId(lib,cantidad,auxId);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {
        printf("\nDesea remover el Libro %d - %s ?\n1.Si\n2.No\n",auxId,lib[resultadoBuscarID].titulo);
        opcion=getch();

        switch (opcion)
        {
        case '1':
            lib[resultadoBuscarID].isEmpty=0;
            printf("\nLibro (%d) %s dado de baja exitosamente.\n",auxId,lib[resultadoBuscarID].titulo);
            system("pause");
            system("cls");

            break;

        case '2':
            printf("\nAccion cancelada por el usuario.\n");
            system("pause");
            system("cls");
            break;

        default:
            printf("\nIngrese una opción valida\n");
            system("pause");
            system("cls");
            break;

        }

    }
}


void libros_modificar(eLibros lib[],int cantidad)
{
    int auxCodLibro;
    int auxCodAutor;
    char auxTitulo[51];

    int resultadoBuscarID;

    system("cls");

    printf("---MODIFICAR LIBRO---\n\n");

    auxCodLibro=getValidInt("\nIngrese Cod. de Libro a modificar:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=libros_buscarPorId(lib,cantidad,auxCodLibro);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {

        getValidString("\nIngrese el nuevo Titulo:","\nEl titulo debe contener solo letras",auxTitulo,1,51);
        auxCodAutor = getValidInt("\nIngrese el nuevo cod. Autor:", "Ingrese solo numeros", 1, 10000);

        strcpy(lib[resultadoBuscarID].titulo,auxTitulo);
        lib[resultadoBuscarID].idAutor = auxCodAutor;
    }
}

void libros_menu(eLibros lib[],int cantidad,eAutores aut[])
{
    int indice=0;
    int id=1;
    char opcion;
    system("cls");
    printf("---MENU LIBROS---\n");

    do
    {
        printf("1-Alta\n");
        printf("2-Modificacion\n");
        printf("3-Baja\n");
        printf("4-Listar todos los libros ordenados por Título, mostrando tambien su Codigo y Codigo de Autor. \n");
        printf("ESC- Atras\n");
        fflush(stdin);
        opcion = getch();

        switch (opcion)
        {
        case '1':
            lib[indice].idLibros=id;
            indice++;
            id++;
            libros_alta(lib,cantidad,aut);
            system("cls");

            break;

        case '2': //modificacion Libroes

            libros_modificar(lib,cantidad);
            system("pause");
            system("cls");
            break;
        case '3': //baja Libroes

            libros_baja(lib,cantidad);
            system("cls");
            break;

        case '4': //listar Libroes
            libros_ordenar(lib,cantidad);
            system("cls");
            break;

        case ESC:
            system("cls");
            break;


        default:
            printf("\nIngrese una opción valida\n");
            system("pause");
            system("cls");
            break;

        }



    }
    while(opcion != ESC);
}


void libros_ordenar(eLibros lib[],int cantidad)
{
    int i,j;
    eLibros auxlib;

    for(i=0; i<cantidad-1; i++)
    {
        if(lib[i].isEmpty==0)
        {
            continue;
        }

        for(j=i+1; j<cantidad; j++)
        {
            if(lib[j].isEmpty==0)
            {
                continue;
            }
            if((strcmp(lib[j].titulo,lib[i].titulo))!=0)
            {
                if(strcmp(lib[j].titulo,lib[i].titulo)<0)
                {
                    auxlib=lib[j];
                    lib[j]=lib[i];
                    lib[i]=auxlib;
                }
            }



        }
    }
    libros_listar(lib,cantidad);
}
