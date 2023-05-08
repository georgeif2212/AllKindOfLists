#include "listaE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Nodo *CrearNodo(Alumno *alumno)
{
  printf("Crear nodo");
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  strcpy(aux->alumno.nombre, alumno->nombre);
  aux->alumno.edad = alumno->edad;
  aux->alumno.matricula = alumno->matricula;
  strcpy(aux->alumno.lic, alumno->lic);
  strcpy(aux->alumno.div, alumno->div);
  aux->sig = NULL;
  return aux;
}

void Destruirnodo(Nodo *aux)
{
  free(aux);
}

void InsertarPrincio(Lista *lista, Alumno *alumno)
{
  printf("\nInsertar al inicio\n");
  Nodo *nodo = CrearNodo(alumno);
  nodo->sig = lista->cabeza;
  lista->cabeza = nodo;
  lista->tam++;
}

void InsertarFinal(Lista *lista, Alumno *alumno)
{
  printf("\nInsertar al final\n");
  Nodo *nodo = CrearNodo(alumno);
  if (isEmpty(lista) == 1)
  {
    lista->cabeza = nodo;
  }
  else
  {
    Nodo *puntero = lista->cabeza; //puntero recorre la lista desde la cabeza hasta que no tenga un nodo siguiente
    while (puntero->sig)
    {
      puntero = puntero->sig;
    }
    // cuando encuentra que el ultimo no tiene nada asignado, asigna el nodo a ese siguiente
    puntero->sig = nodo;
  }
  lista->tam++;
}

void InsertarDespues(int n, Lista *lista, Alumno *alumno)
{
  Nodo *nodo = CrearNodo(alumno);
  if (isEmpty(lista) == 1)
  {
    lista->cabeza = nodo;
  }
  else
  {
    Nodo *puntero = lista->cabeza;
    int posicion = 0;
    while (posicion < n && puntero->sig)
    {
      puntero = puntero->sig;
      posicion++;
    }
    nodo->sig = puntero->sig;
    puntero->sig = nodo;
  }
  lista->tam++;
}

Alumno *Obtener(int n, Lista *lista)
{
  if (isEmpty(lista) == 1)
  {
    return NULL;
  }
  else
  {
    Nodo *puntero = lista->cabeza;
    int posicion = 0;
    while (posicion < n && puntero->sig)
    {
      puntero = puntero->sig;
      posicion++;
    }
    if (posicion != n)
    {
      return NULL;
    }
    else
    {
      return &puntero->alumno;
    }
  }
}

void EliminarPrincipio(Lista *lista)
{
  if (lista->cabeza)
  {
    Nodo *aux = lista->cabeza;
    lista->cabeza = lista->cabeza->sig;
    Destruirnodo(aux);
    lista->tam--;
  }
}

void EliminarFinal(Lista *lista)
{
  if (lista->cabeza)
  {
    if (lista->cabeza->sig)
    {
      Nodo *puntero = lista->cabeza;
      while (puntero->sig->sig)
      {
        puntero = puntero->sig;
      }
      Nodo *aux = puntero->sig;
      puntero->sig = NULL;
      Destruirnodo(aux);
      lista->tam--;
    }
    else
    {
      Nodo *aux = lista->cabeza;
      lista->cabeza = NULL;
      Destruirnodo(aux);
      lista->tam--;
    }
  }
}

void EliminarCualquiera(int n, Lista *lista)
{

  if (lista->cabeza)
  {
    if (n == 0)
    {
      Nodo *aux = lista->cabeza;
      lista->cabeza = lista->cabeza->sig;
      Destruirnodo(aux);
    }
    else if (n < lista->tam)
    {
      Nodo *puntero = lista->cabeza;
      int pos = 0;
      while (pos < (n - 1))
      {
        puntero = puntero->sig;
        pos++;
      }
      Nodo *aux = puntero->sig;
      puntero->sig = aux->sig;
      Destruirnodo(aux);
    }
  }
}

void MostrarLista(Lista *lista)
{
  Nodo *aux = lista->cabeza;
  Alumno *alumno;
  if (isEmpty(lista) != 1)
  {
    while (aux != NULL)
    {
      printf("\n Nombre: %d\n", aux->alumno.nombre);
      printf("\n Edad: %d\n", aux->alumno.edad);
      printf("\n Matricula: %d\n", aux->alumno.matricula);
      printf("\n Licenciatura: %d\n", aux->alumno.lic);
      printf("\n Division: %d\n", aux->alumno.div);
      aux = aux->sig;
    }
  }
  else
  {
    printf("\n Lista vacia \n");
  }
}

int isEmpty(Lista *lista)
{
  if (lista->cabeza == NULL)
  {
    return (1);
  }
  else
  {
    return (0);
  }
}