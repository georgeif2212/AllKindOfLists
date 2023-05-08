#include <stdio.h>

typedef struct Alumno
{
  char nombre[20];
  int edad;
  int matricula;
  char lic[20];
  char div[20];
} Alumno;

typedef struct Nodo
{
  Alumno alumno;
  struct Nodo *sig;
} Nodo;

typedef struct Lista
{
  Nodo *cabeza;
  int tam;
} Lista;

Nodo *CrearNodo(Alumno *alumno);
void Destruirnodo(Nodo *aux);
void InsertarPrincio(Lista *lista, Alumno *alumno);
void InsertarFinal(Lista *lista, Alumno *alumno);
void InsertarDespues(int n, Lista *lista, Alumno *alumno);
Alumno *Obtener(int n, Lista *lista);
void EliminarPrincipio(Lista *lista);
void EliminarFinal(Lista *lista);
void EliminarCualquiera(int n, Lista *lista);
void MostrarLista(Lista *lista);
int isEmpty(Lista *lista);