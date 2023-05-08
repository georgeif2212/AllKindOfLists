#include "listaC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funciones y/o procedimientos*/
Alumno *crear_Alumno(int ID, char NAME[20], int EDAD)
{
  Alumno *aux = (Alumno *)malloc(sizeof(Alumno));
  aux->id = ID;
  strcpy(aux->name, NAME);
  aux->edad = EDAD;
  return (aux);
}

Nodo *crear_Nodo(Alumno *alumno)
{
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->datos = alumno;
  aux->sig = NULL;
  return (aux);
}

ListaSC *crear_ListaSC()
{
  ListaSC *aux = (ListaSC *)malloc(sizeof(ListaSC));
  aux->cabeza = NULL;
  aux->cola = NULL;
  return (aux);
}

int isEmpty(ListaSC lista)
{
  if (lista.cabeza == NULL && lista.cola == NULL)
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

void insertar_cabeza(ListaSC *lista, Nodo *aux)
{
  if (isEmpty(*lista) == 1)
  {
    lista->cabeza = aux;
    lista->cola = aux;
    lista->cabeza->sig = aux;
  }
  else
  {
    aux->sig = lista->cabeza;
    lista->cabeza = aux;
    lista->cola->sig = lista->cabeza;
  }
}

void insertar_cola(ListaSC *lista, Nodo *elemento)
{
  if (isEmpty(*lista) == 1)
  {
    insertar_cabeza(lista, elemento);
  }
  else
  {

    lista->cola->sig = elemento;
    lista->cola = elemento;
    lista->cola->sig = lista->cabeza;
  }
}

void insertar_enmedio(ListaSC *lista, Nodo *next, Nodo *elemento)
{
  if (isEmpty(*lista) == 1)
  {
    insertar_cabeza(lista, elemento);
  }
  else
  {
    if (next == lista->cola)
    {
      insertar_cola(lista, elemento);
    }
    else
    {
      elemento->sig = next->sig;
      next->sig = elemento;
    }
  }
}

void quitar_cabeza(ListaSC *lista)
{
  Nodo *aux = NULL;
  if (!isEmpty(*lista))
  {
    if (lista->cabeza == lista->cola)
    {
      lista->cabeza = NULL;
      lista->cola = NULL;
    }
    else
    {
      aux = lista->cabeza;
      lista->cabeza = lista->cabeza->sig;
      lista->cola->sig = lista->cabeza;
      aux->sig = NULL;
    }
    free(aux);
  }
  else
  {
    printf("\n Empty list\n");
  }
}

void quitar_cola(ListaSC *lista)
{
  // Nodo *cola;
  Nodo *aux;
  if (isEmpty(*lista) == 1)
  {
    printf("\n Empty list\n");
  }
  else
  {
    if (lista->cabeza == lista->cola)
    {
      quitar_cabeza(lista);
    }
    else
    {
      aux = lista->cabeza;
      while (aux->sig != lista->cola)
      {
        aux = aux->sig;
      }
      lista->cola = aux;
      aux = aux->sig;
      aux->sig = NULL;
      lista->cola->sig = lista->cabeza;
      free(aux);
    }
  }
}

void quitar_enmedio(ListaSC *lista, Nodo *elemento)
{
  Nodo *aux;
  Nodo *borrar;
  if (isEmpty(*lista) == 1)
  {
    printf("\nEmpty list\n");
  }
  else
  {
    borrar = buscaElemento(lista, elemento);
    if (borrar == NULL)
    {
      printf("\n El elemento no se encuentra en la lista\n");
    }
    else
    {
      if (lista->cabeza == borrar)
      {
        quitar_cabeza(lista);
      }
      else
      {
        if (borrar == lista->cola)
        {
          quitar_cola(lista);
        }
        else
        {
          aux = lista->cabeza;
          while (aux->sig != borrar)
          {
            aux = aux->sig;
          }
          aux->sig = borrar->sig;
          borrar->sig = NULL;
          aux = borrar;
          aux->sig = NULL;
          borrar->sig = NULL;
          free(borrar);
        }
      }
    }
  }
}

Nodo *buscaElemento(ListaSC *lista, Nodo *elemento)
{
  Nodo *aux = lista->cabeza;
  Alumno *alu;
  if (!isEmpty(*lista))
  {
    while (aux->datos->id != elemento->datos->id)
    {
      if (aux->sig != NULL)
      {
        aux = aux->sig;
      }
      else
      {
        printf("\nEl elemento con ID = %d no se encuentra en la lista\n", elemento->datos->id);
        aux = NULL;
        return (aux);
        break;
      }
    }
    if (aux->datos->id == elemento->datos->id)
    {
      printf("\nEl elemento con ID = %d si esta en la lista\n", elemento->datos->id);
      return (aux);
    }
  }
  else
  {
    printf("\n EL ELEMENTO NO SE ENCUENTRA LA LISTA NO TIENE NADA \n");
    return (NULL);
  }
  return (aux);
}

void vaciarLista(ListaSC *lista)
{
  Nodo *aux = lista->cabeza;
  if (isEmpty(*lista) != 1)
  {
    while (aux != lista->cola)
    {
      aux = aux->sig;
      quitar_cabeza(lista);
    }
    quitar_cabeza(lista);
  }
  else
  {
    printf("\n Empty list\n");
  }
  free(aux);
}

void printLista(ListaSC *lista)
{
  Nodo *aux = lista->cabeza;
  Alumno *alu;
  if (isEmpty(*lista) != 1)
  {
    while (aux != lista->cola)
    {
      alu = aux->datos;
      printf("\n ID es: %d\n", alu->id);
      printf("\n Name es: %s", alu->name);
      printf("\n Edad es: %d \n", alu->edad);
      aux = aux->sig;
    }
    alu = lista->cola->datos;
    printf("\n ID es: %d\n", alu->id);
    printf("\n Name es: %s", alu->name);
    printf("\n Edad es: %d \n", alu->edad);
  }
  else
  {
    printf("\n Empty list \n");
  }
}