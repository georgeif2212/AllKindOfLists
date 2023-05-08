/*main de la lista simple main_listaD.c*/

// typedef int TipoDato;
#include "listaC.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  ListaSC *L;
  Nodo *aux1, *aux2;
  L = crear_ListaSC();

  insertar_cabeza(L, crear_Nodo(crear_Alumno(1, "areli", 25)));
  insertar_cabeza(L, crear_Nodo(crear_Alumno(2, "rojo", 25)));
  insertar_cabeza(L, crear_Nodo(crear_Alumno(3, "hndz", 25)));
  insertar_cola(L, crear_Nodo(crear_Alumno(4, "mario", 25)));
  insertar_enmedio(L, aux1, crear_Nodo(crear_Alumno(7, "torresSSSSS", 28)));
  printLista(L);

  quitar_cola(L);
  printLista(L);
  printLista(L);
  return (0);
}