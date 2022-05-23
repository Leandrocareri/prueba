#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "fecha.h"
#include "validaciones.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"


int buscarLugarLibre(eNotebook vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaNotebook(eNotebook vec[], int tam, int* pNumeroNote)
{
    int todoOk = 0;
    int indice;
    char auxCad[20];
    int auxNum;
    float auxFloat;
    eNotebook nuevaNotebook;

    if(vec != NULL && tam > 0 && pNumeroNote != NULL)
    {
        if( buscarLugarLibre(vec, tam, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema para cargar otra notebook\n");
            }
            else
            {
                printf("Ingrese el modelo de la notebook: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Modelo demasiado largo. Reingrese modelo: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaNotebook.modelo, auxCad);

                printf("Ingrese id de marca:\n 1000 Compaq\n 1001 Asus\n 1002 Acer\n 1003 HP\n");
                scanf("%d", &auxNum);
                if(isdigit(auxNum==0))
                {
                    printf("Error, no se ingreso un numero");
                }
             //   else{
            //
             //   }
               // if(validarNumero(&auxNum,1000,1999))
             //   {
              //      nuevaNotebook.idMarca=auxNum;
              //  }

                printf("Ingrese id de tipo:\n 5000 Gamer\n 5001 Disenio\n 5002 Ultrabook\n 5003 Normalita\n");
                scanf("%d", &auxNum);
                if(validarNumero(&auxNum,5000,5999))
                {
                    nuevaNotebook.idTipo=auxNum;
                }

                printf("Ingrese precio: ");
                scanf("%f", &auxFloat);
                if(validarPrecio(&auxFloat,0))
                {
                    nuevaNotebook.precio=auxFloat;
                }

                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id= *pNumeroNote;
                *pNumeroNote = *pNumeroNote + 1;
                vec[indice] = nuevaNotebook;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}



int mostrarNotebook(eNotebook notebooks, int tam)
{
    int todoOk=0;
    {
        printf("  %5d       %4d         %4d    %20s    %5.2f   \n",

               notebooks.id,
               notebooks.idMarca,
               notebooks.idTipo,
               notebooks.modelo,
               notebooks.precio
              );
        todoOk = 1;
    }
    return todoOk;
}


int listarNotebook(eNotebook vec[], int tam)
{
    int todoOk=0;
    int flag=0;
    if(vec != NULL && tam>0)
    {
        system("cls");
        printf("     ***  Listado de Notebooks   ***  \n\n");
        printf("---------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     precio\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebook(vec[i], tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int buscarNotebook(eNotebook lista[],int tam, int id, int* pIndex)
{
    int todoOk=0;
    if(lista!=NULL && tam>0 && pIndex!=NULL && id>=40000)
    {
        *pIndex=-1;
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0 && lista[i].id==id)
            {
                *pIndex=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}



int inicializarNotes(eNotebook lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;

}



int bajaNotebook(eNotebook lista[], int tam)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    if(lista!=NULL && tam>0)
    {
        listarNotebook(lista,tam);
        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);
        if(buscarNotebook(lista,tam,id,&indice))
        {
            if(indice==-1)
            {
                printf("No hay notebook con esa id\n");
            }
            else
            {
                mostrarNotebook(lista[indice],tam);
                printf("Confirma baja de notebook? \n");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma=toupper(confirma);
                if(confirma!='S')
                {
                    printf("Baja cancelada\n");
                }
                else
                {
                    lista[indice].isEmpty=1;
                    printf("Baja realizada con exito\n");
                }
                todoOk=1;

            }
            todoOk=1;
        }
        else
        {
            printf("Ocurrio un problema al buscar la notebook\n");
        }
        todoOk=1;

    }

    return todoOk;

}



int modificarNotebook(eNotebook lista[],int tam)
{
    int todoOk=0;
    int indice;
    int id;
    char salir='N';
    float auxFloat;
    int auxNum;

    if(lista!=NULL && tam>0)
    {
        listarNotebook(lista,tam);
        printf("Ingrese id de notebook a modificar: \n");
        scanf("%d",&id);
        if(buscarNotebook(lista,tam,id,&indice))
        {
            if(indice==-1)
            {
                printf("No hay notebook con esa id\n");
            }
            else
            {
                mostrarNotebook(lista[indice],tam);

                do
                {
                    switch(menuModificar())
                    {
                    case 1:
                        printf("Ingrese el nuevo precio: \n");
                        scanf("%f",&auxFloat);
                        validarPrecio(&auxFloat,0);
                        lista[indice].precio=auxFloat;
                        printf("Se ha modificado el precio con exito\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo id de tipo:\n 5000 Gamer\n 5001 Disenio\n 5002 Ultrabook\n 5003 Normalita\n");
                        scanf("%d",&auxNum);
                        validarNumero(&auxNum,5000,5999);
                        lista[indice].idTipo=auxNum;
                        printf("Se ha modificado el tipo con exito\n");
                        break;
                    case 3:
                        salir='S';
                        break;
                    }
               }
                while((salir=!'S'));
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar el id");
        }
        todoOk=1;
    }
    return todoOk;
}
