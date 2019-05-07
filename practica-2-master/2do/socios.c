#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "validacionesUTN.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"

#define ESC 27

void socio_inicializar(eSocios socio[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        socio[i].isEmpty=0;
    }
}

int socio_buscarLibre(eSocios socio[],int cantidad)
{
    int i;
    int indice=-1;  //si devuelve -1 es que esta lleno, si devuelve el indice es porque el lugar esta libre
    for (i=0; i<cantidad; i++)
    {


        if (socio[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int socio_buscarPorId(eSocios socio[],int cantidad, int auxCodSocio)
{
    int i;
    int indice =-1;

    for(i=0; i<cantidad; i++)
    {
        if(socio[i].isEmpty==1 && socio[i].codSocio == auxCodSocio)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void socio_alta(eSocios socio[], int cantidad)
{

    char auxNombreSocio[51];
    char auxApellidoSocio[51];
    char auxSexo[12];
    char auxTelefono[16];
    char auxMail[31];
    int auxDia;
    int auxMes;
    int auxAnio;

    int indiceEspacioLibre;

    system("cls");

    printf("---ALTA SOCIOS---\n\n");

    indiceEspacioLibre = socio_buscarLibre(socio,cantidad);

    if(indiceEspacioLibre == -1 )
    {
        printf("No quedan mas espacios libres\n");
    }

    else
    {
        getValidString("Ingrese Nombre Socio: \n","Ingrese solo letras",auxNombreSocio,1,51);
        getValidString("Ingrese Apellido Socio: \n","Ingrese solo letras",auxApellidoSocio,1,51); //getstring se usa distinto, esta guardando en auxname y lastname en este caso
        getValidString("Ingrese el sexo del socio (F/M): \n", "Ingrese solo letras", auxSexo, 1, 1);
        if(getStringNumeros("Ingrese Nro. telefonico: \n", auxTelefono) == 0)
        {
            printf("Ingrese solo numeros\n");

        }
        else
        {
            getValidString("Ingrese eMail del asociado: \n", "Ingrese solo letras", auxMail, 1, 31);
            auxDia = getValidInt("Ingrese el dia: \n", "Ingrese solo numeros.\n", 1, 31);
            auxMes = getValidInt("Ingrese el mes: \n", "Ingrese solo numeros.\n", 1, 12);
            auxAnio = getValidInt("Ingrese el anio: \n", "Ingrese solo numeros.\n", 1, 9999);

            strcpy(socio[indiceEspacioLibre].nombre, auxNombreSocio);
            strcpy(socio[indiceEspacioLibre].apellido, auxApellidoSocio);
            strcpy(socio[indiceEspacioLibre].sexo, auxSexo);
            strcpy(socio[indiceEspacioLibre].telefono, auxTelefono);
            strcpy(socio[indiceEspacioLibre].eMail, auxMail);
            socio[indiceEspacioLibre].fechaAsociado.dia = auxDia;
            socio[indiceEspacioLibre].fechaAsociado.mes = auxMes;
            socio[indiceEspacioLibre].fechaAsociado.anio = auxAnio;
            socio[indiceEspacioLibre].isEmpty = 1;
        }


    }

    system("pause");
    system("cls");

}

void socio_modificar(eSocios socio[],int cantidad)
{
    int auxCodSocio;
    char auxNombreSocio[51];
    char auxApellidoSocio[51];
    char auxSexo[12];
    char auxTelefono[16];
    char auxMail[31];

    int resultadoBuscarID;


    system("cls");

    printf("---MODIFICAR SOCIO---\n\n");

    auxCodSocio=getValidInt("\nIngrese un Cod. socio:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=socio_buscarPorId(socio,cantidad,auxCodSocio);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {

        getValidString("Re-ingrese Nombre Socio: \n","Ingrese solo letras",auxNombreSocio,1,51);
        getValidString("Re-ingrese Apellido Socio: \n","Ingrese solo letras",auxApellidoSocio,1,51); //getstring se usa distinto, esta guardando en auxname y lastname en este caso
        getValidString("Re-ingrese el sexo del socio (F/M): \n", "Ingrese solo letras", auxSexo, 1, 1);
        if(getStringNumeros("Re-ingrese Nro. telefonico: \n", auxTelefono) == 0)
        {
            printf("Ingrese solo numeros\n");

        }
        else
        {
            getValidString("Ingrese eMail del asociado: \n", "Ingrese solo letras", auxMail, 1, 31);

            strcpy(socio[resultadoBuscarID].nombre, auxNombreSocio);
            strcpy(socio[resultadoBuscarID].apellido, auxApellidoSocio);
            strcpy(socio[resultadoBuscarID].sexo, auxSexo);
            strcpy(socio[resultadoBuscarID].telefono, auxTelefono);
            strcpy(socio[resultadoBuscarID].eMail, auxMail);

        }
    }
}

void socio_baja(eSocios socio[],int cantidad)
{
    int auxCodSocio;
    int resultadoBuscarID;
    char opcion;

    system("cls");

    printf("---BAJA SOCIOS---\n\n");

    auxCodSocio=getValidInt("\nIngrese un cod. Socio:","\nSolo puede ser numeros",1,1000);

    resultadoBuscarID=socio_buscarPorId(socio,cantidad,auxCodSocio);

    if (resultadoBuscarID==-1)
    {
        printf("\nEse ID no existe");
    }

    else
    {
        printf("\nDesea remover el Socio %d - %s %s?\n1.Si\n2.No\n",socio[resultadoBuscarID].codSocio,socio[resultadoBuscarID].nombre,socio[resultadoBuscarID].apellido);
        opcion=getch();

        switch (opcion)
        {
        case '1':
            socio[resultadoBuscarID].isEmpty=0;
            printf("\nSocio se hadado de baja exitosamente.\n");
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

void socio_listar(eSocios socio[],int cantidad)
{
    int i;

    system("cls");

    printf("---LISTA SOCIOS---\n\n");

    for (i=0; i<cantidad; i++)
    {
        if(socio[i].isEmpty==1)
        {
            printf("%d--%s--%s--%s--%s--%s\n",socio[i].codSocio,socio[i].nombre,socio[i].apellido, socio[i].sexo, socio[i].telefono, socio[i].eMail);
        }
    }
    system("pause");
}

void socio_ordenarApeyNombre(eSocios socio[],int cantidad)
{
    int i,j;
    eSocios auxSocio;

    for(i=0; i<cantidad-1; i++)
    {
        if(socio[i].isEmpty==0)
        {
            continue;
        }

        for(j=i+1; j<cantidad; j++)
        {
            if(socio[j].isEmpty==0)
            {
                continue;
            }
            if(strcmp(socio[i].apellido, socio[j].apellido)>0)
            {
                auxSocio = socio[i];
                socio[i] = socio[j];
                socio[j] = auxSocio;
            }
            if(strcmp(socio[i].apellido, socio[j].apellido)==0)
            {
                if(strcmp(socio[i].nombre, socio[j].nombre)>0)
                {
                    auxSocio = socio[i];
                    socio[i] = socio[j];
                    socio[j] = auxSocio;
                }
            }
        }
    }
    socio_listar(socio,cantidad);

}

void prestamo_inicializar(ePrestamo prestamo[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        prestamo[i].isEmpty=0;
    }
}

int prestamo_buscarLibre(ePrestamo prestamo[],int cantidad)
{
    int i;
    int indice=-1;  //si devuelve -1 es que esta lleno, si devuelve el indice es porque el lugar esta libre
    for (i=0; i<cantidad; i++)
    {


        if (prestamo[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int prestamo_buscarPorId(ePrestamo prestamo[],int cantidad, int auxCodPrestamo)
{
    int i;
    int indice =-1;

    for(i=0; i<cantidad; i++)
    {
        if(prestamo[i].isEmpty==1 && prestamo[i].codPrestamo == auxCodPrestamo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


void prestamo_alta(ePrestamo prestamo[], int cantidad,eSocios socio[], eLibros libro[])
{
    int auxCodSocio;
    int auxCodLibro;
    int auxDia;
    int auxMes;
    int auxAnio;

    int indiceEspacioLibre;

    int busquedaLibro;
    int busquedaSocio;


    system("cls");

    printf("---ALTA PRESTAMO---\n\n");

    indiceEspacioLibre = prestamo_buscarLibre(prestamo,cantidad);

    if(indiceEspacioLibre == -1 )
    {
        printf("No quedan mas espacios libres\n");
    }

    else
    {
        auxCodLibro = getValidInt("Ingrese Cod. Libro: \n", "Ingrese solo numeros:\n", 1, 10000);
        busquedaLibro = libros_buscarPorId(libro, cantidad, auxCodLibro);
        if(busquedaLibro == -1)
        {
            printf("Ese codigo de libro no existe.\n");
        }else
        {
            auxCodSocio = getValidInt("Ingrese cod. Socio: \n", "Ingrese solo numeros.\n", 1, 10000);
            busquedaSocio = socio_buscarPorId(socio, cantidad, auxCodSocio);
            if(busquedaSocio == -1)
            {
                printf("Ese codigo de socio no existe.\n");
            }else
            {
                auxDia = getValidInt("Ingrese el dia de prestamo:\n", "solo numeros.\n", 1, 31);
                auxMes = getValidInt("Ingrese el dia de prestamo:\n", "solo numeros.\n", 1 , 12);
                auxAnio = getValidInt("Ingrese el anio de prestamo: \n", "solo numeros.\n", 1, 9999);

                prestamo[indiceEspacioLibre].codLibro = auxCodLibro;
                prestamo[indiceEspacioLibre].codSocio = auxCodSocio;
                prestamo[indiceEspacioLibre].fechaPresta.dia = auxDia;
                prestamo[indiceEspacioLibre].fechaPresta.mes = auxMes;
                prestamo[indiceEspacioLibre].fechaPresta.anio = auxAnio;
                prestamo[indiceEspacioLibre].isEmpty = 1;

            }
        }
    }

    system("pause");
    system("cls");

}


void socio_menu(eSocios socio[],int cantidad, eLibros libro[], ePrestamo prestamo[], eAutores autor[])
{
    int indice=0;
    int id=1;
    int indicePres=0;
    int idPres= 0;
    char opcion;
    system("cls");
    printf("---MENU SOCIO---\n");

    do
    {
        printf("1-Alta\n");
        printf("2-Modificacion\n");
        printf("3-Baja\n");
        printf("4-Listar todos los socios ordenados por apellido y nombre, mostrando sus demas campos. \n");
        printf("5-listar libros. \n");
        printf("6-listar autores.\n");
        printf("7-Alta prestamo:\n");
        printf("ESC- Atras\n");
        fflush(stdin);
        opcion = getch();

        switch (opcion)
        {
        case '1':
            socio[indice].codSocio=id;
            indice++;
            id++;
            socio_alta(socio,cantidad);
            system("cls");

            break;

        case '2': //modificacion Libroes

            socio_modificar(socio,cantidad);
            system("pause");
            system("cls");
            break;
        case '3': //baja Libroes

            socio_baja(socio,cantidad);
            system("cls");
            break;

        case '4': //listar Libroes
            socio_ordenarApeyNombre(socio,cantidad);
            system("cls");
            break;
        case '5':
            libros_ordenar(libro, cantidad);
            break;
        case '6':
            autor_ordenar(autor, cantidad);
            break;
        case '7':
            prestamo[indicePres].codPrestamo=idPres;
            indicePres++;
            idPres++;
            prestamo_alta(prestamo, cantidad, socio, libro);
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


