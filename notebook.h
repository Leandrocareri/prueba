#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty; //No pedido
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED


int listarNotebook(eNotebook vec[], int tam);
int buscarLugarLibre(eNotebook vec[], int tam, int* pIndex);
int altaNotebook(eNotebook vec[], int tam, int* pNumeroNote);
int mostrarNotebook(eNotebook notebooks, int tam);
int inicializarNotes(eNotebook lista[], int tam);
int bajaNotebook(eNotebook lista[], int tam);
int buscarNotebook(eNotebook lista[],int tam, int id, int* pIndex);
int modificarNotebook(eNotebook lista[],int tam);
