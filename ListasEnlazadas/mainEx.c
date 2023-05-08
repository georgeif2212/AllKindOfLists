#include "listaE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int menu = 1, aux = 0, cont = 0, num;
  Alumno *alumno;
  Lista *lista;
  do
  {
    printf("\nBienvenido, elige una opcion:\n");
    printf("\n1- Agregar un alumno\n");
    printf("4- Imprimir la lista\n");
    printf("5- Salir o Terminar\n\n");
    printf("Opcion:\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
      printf("\n|   Alumno %d:  |\n", cont + 1);
      printf("Nombre:");
      scanf("%s", &alumno->nombre);
      printf("Edad:");
      scanf("%d", &alumno->edad);
      printf("Matricula:");
      scanf("%d", &alumno->matricula);
      printf("Licenciatura::");
      scanf("%s", &alumno->lic);
      printf("Division:");
      scanf("%s", &alumno->div);
      printf("hola");
      if (cont = 0)
      {
        InsertarPrincio(lista, alumno);
      }
      else
      {
        InsertarFinal(lista, alumno);
      }
      cont++;

      break;
    case 4:
      MostrarLista(lista);
      break;
    case 5:
      printf("Vuelve pronto\n");
      break;
    default:
      printf("Opcion incorrecta");
      break;
    }
  } while (menu != 5);

  return (0);
}