#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#include "juego.h"
#include "validaciones.h"
#include "cliente.h"
#include "alquiler.h"


#define ESC 27
#define CANTCLI 5
#define CANTJUE 6
#define CANTALQ 30

int main()
{
    eJuegos juegos[CANTJUE]= {{1,"wow",13.00,1},
        {2,"hos",15.00,1},
        {3,"farming",55.00,1},
        {4,"mechanic",123.00,1},
        {5,"bikers",45.00,1},
    };
    //juego_inicializar(juegos, CANTJUE);

    eClientes clientes[CANTCLI]= {{11,"flores","joseph","alberti","1122334455",1},
        {22,"rengifo","jhosy","florida","1123638755",1},
        {33,"alcides","erick","callao","112838858",1},
        {44,"tello","vale","nueva","1123435465",1},
    };
    //cliente_inicializar(clientes, CANTCLI);

    eAlquileres alquileres[CANTALQ];
    alquier_inicializar(alquileres, CANTALQ);
    //espacioLibre alquier cliente juego
    alquiler_ingresoDatos(alquileres, 0, 1, 11, 2, 11, 10, 1998);
    alquiler_ingresoDatos(alquileres, 1, 2, 11, 1, 11, 9, 1998);
    alquiler_ingresoDatos(alquileres, 2, 3, 22, 3, 2, 10, 1998);
    alquiler_ingresoDatos(alquileres, 3, 4, 33, 3, 11, 10, 1999);
    alquiler_ingresoDatos(alquileres, 4, 5, 33, 5, 11, 12, 1997);
    alquiler_ingresoDatos(alquileres, 5, 6, 33, 4, 10, 8, 1996);
    alquiler_ingresoDatos(alquileres, 6, 7, 33, 4, 8, 4, 1993);
    alquiler_ingresoDatos(alquileres, 7, 8, 22, 3, 21, 5, 1991);
    alquiler_ingresoDatos(alquileres, 8, 9, 44, 2, 11, 10, 1994);
    alquiler_ingresoDatos(alquileres, 9, 10, 44, 2, 11, 10, 1995);


    char opcion;

    do
    {
        system("cls");
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n1 - ABM JUEGOS \n2 - ABM CLIENTES \n3 - ABM ALQUILERES \n4 - RESULTADOS \n5- METODO DE BURBUJA EFICIENTE\n");
        printf("6 - METODO INSERCION:\n\n ESC para salir\n\n");
        opcion = getch();

        switch(opcion)
        {
        case '1':

            juego_admin(juegos, CANTJUE);
            break;
        case '2':
            cliente_admin(clientes, CANTCLI);

            break;
        case '3':
            alquiler_admin(alquileres, clientes,juegos, CANTJUE, CANTCLI, CANTALQ);

            break;
        case '4':
            printf("\n\nPROMEDIO Y TOTAL DE IMPORTE ALQUILERES Y CANTIDAD DE JUEGOS DEBAJO DEL PROMEDIO\n\n");
            totalYpromedio(juegos, CANTJUE, alquileres, CANTALQ);
            menosvotado(alquileres, CANTALQ, juegos, CANTJUE);

            break;
        case '5':
            printf("\nMETODO DE BURBUJERO MAS EFICIENTE\n");
            burbujeoMasEficiente(juegos, CANTJUE);
            juego_mostrarTodo(juegos, CANTJUE);
                break;
        case '6':
            printf("/nINSERCION POR APELLIDO/n/n");
            insertion(clientes, CANTCLI);
            cliente_mostrarTodos(clientes, CANTCLI);
            break;
        case ESC:
            system("cls");
            printf("\n\nPrograma finalizado.\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\n\nOpcion no encontrada, ingrese una opcion valida...\n");
            system("pause");
            break;
        }

    }
    while(opcion != ESC);

    return 0;
}
