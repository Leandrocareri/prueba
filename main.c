#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "fecha.h"
#include "validaciones.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 20
#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMTBS 20


int main()
{
    char salir='n';
    int banderaAlta=0;
    int banderaTrabajo=0;
    int proxNote = 40000;
    int numeroTrabajo=1;
    eNotebook lista[TAM];
    eMarca marcas[TAMM];
    eTipo tipos[TAMT];
    eServicio servicios[TAMS];
    eTrabajo trabajos[TAMTBS];

    hardcodearMarcas(marcas,TAMM);
    hardcodearTipos(tipos,TAMT);
    hardcodearServicios(servicios,TAMS);
    inicializarNotes(lista,TAM);
    inicializarTrabajos(trabajos,TAMTBS);

    /*   if(validarFecha(fecha))
         {
             printf("La fecha es %d / %d / %d \n",fecha.dia,fecha.mes,fecha.anio);
             system("pause");
         }
    */

    do
    {
        switch(menu())
        {
        case 'A':
            if(altaNotebook(lista, TAM, &proxNote))
            {
                printf("Notebook agregada con exito!!!\n");
                banderaAlta=1;
                system("pause");
            }
            else
            {
                printf("Problema al dar de alta la notebook\n");
                system("pause");
            }
            break;

        case 'B':
            if(banderaAlta==0)
            {
                printf("No se puede modificar hasta no dar de alta una notebook\n");
                system("pause");
            }
            else
            {
                if(modificarNotebook(lista,TAM)==0)
                {
                    printf("Error al modificar los datos\n");
                }
                system("pause");
            }
            break;

        case 'C':
            if(banderaAlta==0)
            {
                printf("No se puede dar de baja hasta no dar de alta una notebook\n");
                system("pause");
            }
            else
            {
                if(bajaNotebook(lista,TAM))
                {
                    printf("Notebook dada de baja con exito\n");
                    system("pause");
                }
                else
                {
                    printf("Problema al dar de baja la notebook\n");
                    system("pause");
                }
            }
            break;

        case 'D':
            if(banderaAlta==0)
            {
                printf("No se puede modificar hasta no dar de alta una notebook\n");
                system("pause");
            }
            else
            {
                listarNotebook(lista, TAM);
                system("pause");
            }
            break;

        case 'E':
            listarMarcas(marcas,TAMM);
            break;

        case 'F':
            listartipos(tipos,TAMT);
            break;

        case 'G':
            listarServicios(servicios,TAMS);
            break;

        case 'H': // alta trabajo
            if(banderaAlta==0)
            {
                printf("No se puede ingresar trabajo hasta no dar de alta una notebook\n");
                system("pause");
            }
            else
            {
                if(altaTrabajo(trabajos,TAMTBS,&numeroTrabajo,lista,TAM))
                {
                    printf("Trabajo cargado con exito\n");
                    system("pause");
                    banderaTrabajo=1;
                }
                else
                {
                    printf("Error al cargar trabajo\n");
                    system("pause");
                }
                break;

            case 'I':
                if(banderaTrabajo==0)
                {
                    printf("No se puede mostrar trabajos hasta no dar de alta uno\n");
                    system("pause");
                }
                else
                {
                    listarTrabajos(trabajos,TAMTBS);
                }
                break;

            case 'Z':
                if(!confirmarSalida(&salir))
                {
                    printf("Ha ocurrido un error al salir\n");
                }
            }
            break;
        }

    }
    while(salir!='S');


    return 0;
}
