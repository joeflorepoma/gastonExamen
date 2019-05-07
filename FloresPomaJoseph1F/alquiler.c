#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define ESC 27

#include "cliente.h"
#include "juego.h"
#include "validaciones.h"
#include "alquiler.h"

void alquier_inicializar(eAlquileres rent[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        rent[i].estado = 0;
    }
}

int alquiler_buscarEspacioLibre(eAlquileres rent[], int cantidad)
{
    int i;
    int indice = -1;// devuelve -1 si no hay mas espaciop libre

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 0)
        {
            indice = i;// devolvera cualquier otro numero si encuentra un espacio libre
            break;
        }
    }
    return indice;
}

int alquier_buscarPorCodigo(eAlquileres rent[], int cantidad, int auxCodAlquiler)
{
    int i;
    int indice = -1;// el id no esta en la base de datos

    for(i=0; i<cantidad; i++)
    {
        if(rent[i].estado == 1 && rent[i].CodigoAlquiler == auxCodAlquiler)
        {
            indice = i;// se encontro el id en la base de datos
            break;
        }
    }
    return indice;
}

void mostrarUnAlquiler(eAlquileres rent)
{
    printf("\n | %13d  | %13d | %13d | %5d | %5d | %5d |\n", rent.CodigoAlquiler, rent.idCliente, rent.idJuego, rent.date.dia, rent.date.mes, rent.date.anio);
}

void alquier_mostrarTodos(eAlquileres rent[], int cantidad)
{
    int i;

    system("cls");
    printf("---Lista de Alquileres---\n\n");

    printf("\n | %13s  | %13s | %13s | %5s | %5s | %5s\n", "Cod.Alquiler", "Cod.Idcliente", "Cod.IdJuego", "Dia", "Mes", "anio");

    for(i=0; i < cantidad; i++)
    {
        if(rent[i].estado != 0)
        {
            mostrarUnAlquiler(rent[i]);
        }
    }

    system("pause");
}

void alquiler_ingresoDatos(eAlquileres rent[],int espacioLibre, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio)
{
    rent[espacioLibre].CodigoAlquiler = auxCodAlquiler;
    rent[espacioLibre].idCliente = auxIdCliente;
    rent[espacioLibre].idJuego = auxIdJuego;
    rent[espacioLibre].date.dia = auxDia;
    rent[espacioLibre].date.mes = auxMes;
    rent[espacioLibre].date.anio = auxAnio;
    rent[espacioLibre].estado = 1;
}

void alquiler_alta(eAlquileres rent[], int cantidad, eClientes clientes[], int cantClientes, eJuegos juego [], int cantJuego, int auxCodAlquiler, int auxIdCliente, int auxIdJuego, int auxDia, int auxMes, int auxAnio)
{
    int espacioLibre;
    int busqueda;
    int indice;
    int indiceJuego;

    system("cls");

    printf("\n\t-----Alta de Alquileres-----\t\n\n");


    espacioLibre = alquiler_buscarEspacioLibre(rent, cantidad);

    if(espacioLibre == -1)
    {
        printf("\nNo queda memoria libre...\n\n");
    }
    else
    {
        auxCodAlquiler = getValidInt("\nIngresa codigo de Alquiler: \n", "\nIngrese solo numeros\n\n", 1, 1000);

        busqueda = alquier_buscarPorCodigo(rent, cantidad, auxCodAlquiler);

        if(busqueda != -1)
        {
            printf("\nEl Codigo Ingresado ya existe.\n");
            printf("\n | %13s  | %13s | %13s | %5s | %5s | %5s \n", "Cod. alquiler", "Cod.Cliente", "Cod. juego", "Dia", "Mes", "anio");
            mostrarUnAlquiler(rent[busqueda]);

        }
        else
        {
            auxIdCliente = getValidInt("Ingrese el codigo de cliente: \n", "\nIngrese solo numeros.\n", 1, 10000);

            indice = cliente_buscarPorCodigo(clientes, cantClientes, auxIdCliente);

            if(indice == -1)
            {
                printf("Ingrese un codigo valido.\n");


            }
            else
            {
                auxIdJuego = getValidInt("Ingrese el codigo de juego; \n", "\nIngrese solo numeros.\n", 1, 10000);

                indiceJuego = juego_buscarPorCodigo(juego, cantJuego, auxIdJuego);
                if(indiceJuego == -1)
                {
                    printf("Ingrese un codigo valido.\n");

                }
                else
                {
                    auxDia = getValidInt("Ingrese el dia: \n", "\nIngrese solo numeros.\n", 1, 31);
                    auxMes = getValidInt("Ingrese el mes: \n", "\nIngrese solo numeros.\n", 1, 12);
                    auxAnio = getValidInt("Ingrese el anio: \n", "\nIngrese solo numeros.\n", 1, 9999);

                    alquiler_ingresoDatos(rent, espacioLibre, auxCodAlquiler, auxIdCliente, auxIdJuego, auxDia, auxMes, auxAnio);
                }


            }


        }
    }

    system("pause");
}

void alquiler_admin(eAlquileres rent[], eClientes cliente[], eJuegos juego[], int cantJuego, int canCliente, int cantidad)
{

    int auxCodigoAlquiler = 0;
    int auxIdJuego=0;
    int auxIdCliente=0;
    int auxDia=0;
    int auxMes=0;
    int auxAnio=0;

    char opcion;

    do
    {
        system("cls");
        printf("\n-------\tABM ALQUILERES\t-------\n");
        printf("\n1.- Alta: \n2.- listar\nESC.- Para salir...\n\n");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            alquiler_alta(rent, cantidad, cliente, canCliente,juego, cantJuego, auxCodigoAlquiler, auxIdCliente,auxIdJuego, auxDia, auxMes, auxAnio);

            break;
        case '2':

            alquier_mostrarTodos(rent, cantidad);
            break;
        case '3':


            break;
        case '4':

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

    }
    while(opcion != ESC);
}

void totalYpromedio(eJuegos juego[], int cantJuegos, eAlquileres alquiler[], int cantAlquiler)
{
    int i;
    int indice;
    float importe=0.0;
    int contador=0;
    int contJueProm=0;
    float promedio;

    for(i=0; i<cantAlquiler; i++)
    {
        if(alquiler[i].estado!=0)
        {
            indice = juego_buscarPorCodigo(juego, cantJuegos, alquiler[i].idJuego);

            if(indice != -1)
            {
                importe +=juego[indice].importe;
                contador++;
            }
        }
    }

    promedio = importe/(float)contador;

    printf("El importe total es: %.2f - y el promedio es: %.2f\n\n", importe, promedio);

    for(i=0; i<cantJuegos; i++)
    {
        if(juego[i].estado != 0)
        {
            if(juego[i].importe<promedio)
            {
                contJueProm++;
            }
        }
    }

    printf("Los cantidad de juegos por debajo del promedio son: %d\n", contJueProm);

    system("pause");
}

void menosvotado(eAlquileres alquileres[], int cantAlquileres, eJuegos juego[], int cantJuego)
{
    int respuesta; /* contador a través de las 40 respuestas */
    int rango;/* contador de rangos de 1 a 10 */
    int i;
    int contador=0;
    int contJuego=0;
    int frecuencia[40] = {0};
    int datos[20]= {0};



    printf("\n\n");
    for(i=0; i<cantAlquileres; i++)
    {

        if(alquileres[i].estado == 0)
        {
            continue;
        }

        datos[i] = alquileres[i].idJuego;


        contador++;

    }

    for(respuesta = 0; respuesta<contador; respuesta++)
    {
        printf("\n%d", datos[respuesta]);
        frecuencia[datos[respuesta]]++;
    }

    for(i=0; i<cantJuego; i++)
    {
        if(juego[i].estado==0)
        {
            continue;
        }



        contJuego++;
    }

    /*for(i = 0; i<cantAlquileres; i++)
    {
        if(frecuencia[i]!=0)
        printf("\n%d", frecuencia[i]);

    }*/

    for(rango = 1; rango<=contJuego; rango++)
    {
        printf(" \n%d--%d\n", rango,  frecuencia[rango]);
    }


    system("pause");
}

void burbujeoMasEficiente(eJuegos juego[],int cantJuego)
{
    int j;
    eJuegos aux;
    int flagNoEstaOrdenado = 1;
    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < cantJuego; j++)
        {
            if (juego[j].importe > juego[j- 1].importe)
            {
                aux = juego[j];
                juego[j] = juego[j - 1];
                juego[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }
}


void insertion(eClientes cliente[],int cantCliente)
{
    int i,j;
    eClientes aux;
    for(i=1; i<cantCliente; i++)
    {
        aux = cliente[i];
        j=i-1;
        while(j>=0 && strcmp(aux.Apellido, cliente[j].Apellido)<0) // temp<data[j] o temp>data[j]
        {
            cliente[j+1] = cliente[j];
            j--;
        }
        cliente[j+1]=aux; // inserción
    }

}

/*void clientesYJuegoDeterminado(eAlquiler alquier[], int cantALquier, eCliente cliente[], int cantCliente, eJuego juegos[], int cantJuegos)
{
    char auxDescrip[51];
    int indice = -1;
    char auxApellido[51];

    int i,j;
    int index=0;
    int indiceAlquier[index] ;

    getStringLetras("Ingrese el juego: \n",auxDescrip);

    for(i=0; i<cantJuegos; i++)
    {
        if(juegos[i].estado != 0)
        {
            if(strcmp(auxDescrip, juegos[i].descripcion)==0)
            {
                indice = i;
                break;
            }
        }
    }

    printf("%d---%s-----%.2f", juegos[indice].codigo, juegos[indice].descripcion, juegos[indice].importe);

    for(i=0; i<cantALquier; i++)
    {
        if(alquier[i].estado!=0)
        {
           indiceAlquier = buscarAlquilerPorCodigo(alquier, cantALquier,);

        }
        if(alquier[i].codJuego == juegos[indice].codigo)
        {
            indiceAlquier[index] = alquier[i].codCliente;
            index++;
            indiceAlquier = i;

            //printf("\n%d---%d---%d-\n", alquier[indiceAlquier].codAlquiler, alquier[indiceAlquier].codCliente, alquier[indiceAlquier].codJuego);
        }

    }

    for(j=0; j<cantCliente; j++)
            {
                if(cliente[i].estado!=0)
                {
                    printf("\n%s\n", cliente[indiceAlquier[index]].apellido);
                }


            }
}*/
