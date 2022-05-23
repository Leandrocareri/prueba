#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "validaciones.h"

char menu()
{

    char opcion;
    system("cls");
    printf("     *** SERVICE DE NOTEBOOKS ***\n\n");
    printf("A- Alta notebook\n");
    printf("B- Modificar notebook\n");
    printf("C- Baja notebook\n");
    printf("D- Listar notebooks\n");
    printf("E- Listar marcas\n");
    printf("F- Listar tipos\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
   printf("Z- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);
    if(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D' && opcion!='E' && opcion!='F' && opcion!='G'
       && opcion!='H' && opcion!='I' && opcion!='Z')
    {
        printf("Opcion incorrecta, elija una opcion valida\n");
        system("pause");
    }
    return opcion;

}


int menuModificar()
{
    int opcion;
    printf(" \n   ***  Campos a modificar  ***\n\n");
    printf("1_ Precio\n");
    printf("2_ Id tipo\n");
    printf("3_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,3);
    return opcion;
}
