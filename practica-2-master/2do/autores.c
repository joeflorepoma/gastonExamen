#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "validacionesUTN.h"
#include "autores.h"
#include "libros.h"
#define ESC 27

void autor_inicializar(eAutores aut[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        aut[i].isEmpty=0;
    }
}

int autor_buscarLibre(eAutores aut[],int cantidad)
{
    int i;
    int indice=-1;  //si devuelve -1 es que esta lleno, si devuelve el indice es porque el lugar esta libre
    for (i=0; i<cantidad; i++)
    {


        if (aut[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int autor_buscarPorId(eAutores aut[],int cantidad, int aux)
{
    int i;
    int indice =-1;

    for(i=0; i<cantidad; i++)
    {
        if(aut[i].isEmpty==1 && aut[i].idAutores == aux)
        {
            indice=i;
            break;
        }

    }

    return indice;
}

void autor_alta(eAutores aut[], int cantidad)
{

    char auxName[51];
    char auxLastName[51];

    int indiceEspacioLibre;

    system("cls");

    printf("---ALTA AUTORES---\n\n");

    indiceEspacioLibre = autor_buscarLibre(aut,cantidad);

    if(indiceEspacioLibre == -1 )
    {
        printf("No quedan mas espacios libres\n");
    }

    else
    {
        getValidString("Ingrese Nombre: \n","Ingrese solo letras",auxName,1,51);
        getValidString("Ingrese Apellido: \n","Ingrese solo letras",auxLastName,1,51); //getstring se usa distinto, esta guardando en auxname y lastname en este caso

        strcpy(aut[indiceEspacioLibre].name,auxName);
        strcpy(aut[indiceEspacioLibre].lastName,auxLastName);
        aut[indiceEspacioLibre].isEmpty=1;
    }


    system("pause");
    system("cls");

}

void autor_listar(eAutores aut[],int cantidad)
{
    int i;

    system("cls");

    printf("---LISTA AUTORESS---\n\n");

    for (i=0; i<cantidad; i++)
    {
        if(aut[i].isEmpty==1)
        {
            printf("%d\t%s\t%s\n",aut[i].idAutores,aut[i].name,aut[i].lastName);
        }
    }
    system("pause");
}

void autor_imprimir(eAutores aut[],int indice)
{

    printf("%d\t%s\t%s\n",aut[indice].idAutores,aut[indice].name,aut[indice].lastName);

}

void autor_baja(eAutores aut[],int cantidad)
{
    int auxId;
    int resultadoBuscarID;
    char opcion;

    system("cls");

    printf("---BAJA AUTORES---\n\n");

    auxId=getValidInt("\nIngrese un numero de ID:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=autor_buscarPorId(aut,cantidad,auxId);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {
        printf("\nDesea remover el Autor %d - %s %s?\n1.Si\n2.No\n",auxId,aut[resultadoBuscarID].name,aut[resultadoBuscarID].lastName);
        opcion=getch();

        switch (opcion)
        {
        case '1':
            aut[resultadoBuscarID].isEmpty=0;
            printf("\nAutor (%d) %s %s dado de baja exitosamente.\n",auxId,aut[resultadoBuscarID].name,aut[resultadoBuscarID].lastName);
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


void autor_modificar(eAutores aut[],int cantidad)
{
    int auxId;
    char auxNombre[51];
    char auxLastNombre[51];


    int resultadoBuscarID;


    system("cls");

    printf("---MODIFICAR AUTORES---\n\n");

    auxId=getValidInt("\nIngrese un numero de ID:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=autor_buscarPorId(aut,cantidad,auxId);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {

        getValidString("\nIngrese el nuevo nombre:","\nEl nombre debe contener solo letras",auxNombre,1,51);
        getValidString("\nIngrese el nuevo apellido:","\nEl apellido debe contener solo letras",auxLastNombre,1,51);

        strcpy(aut[resultadoBuscarID].name,auxNombre);
        strcpy(aut[resultadoBuscarID].lastName,auxLastNombre);

    }
}

void autor_ordenar(eAutores aut[],int cantidad)
{
    int i,j;
    eAutores auxAutor;

    for(i=0; i<cantidad-1; i++)
    {
        if(aut[i].isEmpty==0)
        {
            continue;
        }

        for(j=i+1; j<cantidad; j++)
        {
            if(aut[j].isEmpty==0)
            {
                continue;
            }
            if(strcmp(aut[i].lastName, aut[j].lastName)>0)
            {
                auxAutor = aut[i];
                aut[i] = aut[j];
                aut[j] = auxAutor;
            }
            if(strcmp(aut[i].lastName, aut[j].lastName)==0)
            {
                if(strcmp(aut[i].name, aut[j].name)>0)
                {
                    auxAutor = aut[i];
                    aut[i] = aut[j];
                    aut[j] = auxAutor;
                }
            }
        }
    }
    autor_listar(aut,cantidad);
}


void autor_menu(eAutores aut[],int cantidad)
{
    int indice=0;
    int id=1;
    char opcion;
    system("cls");
    printf("---MENU AUTORES---\n");

    do
    {
        printf("1-Alta\n");
        printf("2-Modificacion\n");
        printf("3-Baja\n");
        printf("4-Listar todos los autores ordenados por Apellido y Nombre, mostrando también su Código.\n");
        printf("ESC- Atras\n");
        fflush(stdin);
        opcion = getch();

        switch (opcion)
        {
        case '1':
            aut[indice].idAutores=id;
            indice++;
            id++;
            autor_alta(aut,cantidad);
            system("cls");

            break;

        case '2': //modificacion autores
            autor_modificar(aut,cantidad);
            system("pause");
            system("cls");
            break;
        case '3': //baja autores
            autor_baja(aut,cantidad);
            system("cls");
            break;

        case '4': //listar autores
            autor_ordenar(aut, cantidad);
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


/*void ordenamientoDoble(eAutores aut[],int cantidad)
{
    int i,j;
    eAutores auxaut;

    for(i=0;i<cantidad-1;i++)
    {
        if(aut[i].isEmpty==0)
        {
            continue;
        }

        for(j=i+1;j<cantidad;j++)
        {
            if(aut[j].isEmpty==0)
            {
                continue;
            }
            if((strcmp(aut[j].name,aut[i].name))!=0)
            {
                if(strcmp(aut[j].name,aut[i].name)<0)
                {
                    auxaut=aut[j];
                    aut[j]=aut[i];
                    aut[i]=auxaut;
                }
            }
            else
            {
                if(aut[j].sector>aut[i].sector)
                {
                    auxaut=aut[j];
                    aut[j]=aut[i];
                    aut[i]=auxaut;
                }
            }
        }
    }

    listarAutor(aut,cantidad);
}

void sumaYPromedio(eAutores aut[],int cantidad)
{
    int i;
    int suma=0;
    int contador=0;
    int contadorSobreSalario=0;
    float promedio=0;

    for(i=0;i<cantidad;i++)
    {
        if(aut[i].isEmpty==0)
        {
            continue;
        }


        suma= suma + aut[i].salary;
        contador++;


    }

    promedio=suma/contador;

    printf("\nTotal de los salarios:%d\nPromedio salario:%.2f\n",suma,promedio);

    for(i=0;i<cantidad;i++)
    {
        if(aut[i].isEmpty==0)
        {
            continue;
        }

        if(aut[i].salary>promedio)
        {
            contadorSobreSalario++;
        }
    }

    printf("\nLos Autors que superan el salario promedio son: %d\n",contadorSobreSalario);

    system("pause");
    system("cls");

}*/

