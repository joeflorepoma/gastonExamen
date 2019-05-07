#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "validacionesUTN.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"


#define CANT 3
#define ESC 27



int main()
{

    char opcion;


    eAutores aut[CANT];
    eLibros lib[CANT];
    eSocios socios[CANT];
    ePrestamo prestamo[CANT];


    autor_inicializar(aut,CANT);
    libros_inicializar(lib,CANT);
    socio_inicializar(socios, CANT);
    prestamo_inicializar(prestamo, CANT);


    do
    {
        printf("1-Menu Autores\n");
        printf("2-Menu Libros\n");
        printf("3-Menu Socios\n");
        printf("ESC- Salir\n");
        fflush(stdin);
        opcion = getch();

        switch (opcion)
        {
        case '1':
            autor_menu(aut,CANT);
            break;

        case '2':
            libros_menu(lib,CANT,aut);
            break;
        case '3':
            socio_menu(socios, CANT, lib, prestamo, aut);
            break;
        }

    }
    while(opcion != ESC);


    return 0;
}
