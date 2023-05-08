//Jorge Infante Fragoso - 2203025256
//Karina Alcantara Segura - 2203025452

#include <stdio.h>
#include <stdlib.h>

//Estructura para crear fecha por alimento
typedef struct Fecha{
    int dia;
    int mes;
    int año;
}Fecha;

//Estructura para crear alimento (contiene la informacion por producto)
typedef struct Alimento {
    char tipo[20];
    char nombre[20];
    int precio;
    Fecha *fechaCompra;
    Fecha *fechaCad;
    int estatus;
}Alimento;

//Estructura para crear nodo de cada una de las listas por producto (contiene el alimento)
typedef struct Nodo{
    Alimento *info;
    struct Nodo *sig;
    struct Nodo *ant;
}Nodo;

//Estructura para crear la lista doblemente enlazada por producto
typedef struct ListaDP{
    struct Nodo *cabeza;
    struct Nodo *cola;
}ListaDP;

//Estructura para crear nodo de la lista refrigerador (contiene las listas doblemente enlazadas)
typedef struct NodoLista{
    ListaDP *lista;
    struct NodoLista *sig;
}NodoLista;

//Estructura para crear la lista Refrigerador (lista simple de listas doblemente enlazadas)
typedef struct Refrigerador{
    NodoLista *cabeza;
    NodoLista *cola;
}Refrigerador;

//Cabeceras de funciones
Alimento *crearAlimento(char tipo[20], char nombre[20], int precio, Fecha *fecha1, Fecha *fecha2, int estatus);
Nodo *crear_Nodo(Alimento *alimento);
ListaDP *crearLista();
int isEmpty(ListaDP lista);
void insertar_cabeza(ListaDP *lista, Nodo *aux);
void insertar_cola(ListaDP *lista, Nodo *aux);
void quitar_cabeza(ListaDP *lista);
void quitar_cola(ListaDP *lista);
void quitar_enmedio(ListaDP *lista, Nodo *elemento);
void printLista(ListaDP *lista);
Nodo *pivote(Nodo *cabeza, Nodo *cola);
void quickSort(Nodo *cabeza, Nodo *cola);
void vaciarLista(ListaDP *lista);
void intercambio(Nodo *cabeza, Nodo *sig);
void insercion(ListaDP * lista);
Nodo *centro_lista(Nodo* aux1, Nodo* aux2);
Nodo *busqueda_binaria(ListaDP *lista, int value);
Nodo *buscayQuita_binaria(ListaDP *lista, int value);
void InsertarRefrigerador(Refrigerador* listaGeneral, NodoLista* listaProducto);
Refrigerador *crearListaGeneral();
NodoLista *crear_NodoLista(ListaDP *lista);
void printRefrigerador(Refrigerador *refrigerador);
void vaciarRefrigerador(Refrigerador * refri);
void quitar_cabezaR(Refrigerador *refri);
int verificaCaducidad(Fecha *fecha1, Fecha *fecha2);
Fecha *crearFecha(int dia, int mes, int año);
int validar_fecha(int dia, int mes, int año);
void RefriPreciosIguales(Refrigerador *refrigerador,int precio);
