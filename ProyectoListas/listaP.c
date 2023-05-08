//Jorge Infante Fragoso - 2203025256
//Karina Alcantara Segura - 2203025452

#include "listaP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNCION CREAR ALIMENTO
Parametros: Tipo, nombre, precio, fecha de compra, fecha de caducidad, estatus
Retorna: Estructura de tipo Alimento
Descripcion: Inicializa los valores de una estructura alimento 
con los datos ingresados por el usuario.
*/ 
Alimento* crearAlimento(char tipo[20], char nombre[20], int precio, Fecha *fecha1, Fecha *fecha2, int estatus){
    Alimento *aux=(Alimento*)malloc(sizeof(Alimento));
    strcpy(aux->tipo, tipo);
    strcpy(aux->nombre, nombre);
    aux->fechaCompra=fecha1;
    aux->fechaCad=fecha2;
    aux->precio=precio;
    aux->estatus=estatus;
    return aux;
}

/* FUNCION CREAR NODOLISTA
Parametros: Estructura de tipo ListaDP
Retorna: Estructura de tipo NodoLista
Descripcion: Inicializa los valores de una estructura nodo 
con la estructura ListaDP ingresada por el usuario.
*/ 
NodoLista *crear_NodoLista(ListaDP *lista){
    NodoLista *aux=(NodoLista*)malloc(sizeof(NodoLista));
    aux->lista=lista;
    aux->sig=NULL;
    return aux;
}

/* FUNCION CREAR NODO
Parametros: Estructura de tipo Alimento
Retorna: Estructura de tipo Nodo
Descripcion: Inicializa los valores de una estructura nodo 
con la estructura Alimento ingresada por el usuario.
*/
Nodo *crear_Nodo(Alimento *alimento){
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
    aux->info=alimento;
    aux->sig=NULL;
    aux->ant=NULL;
    return aux;
}

/* FUNCION CREAR LISTA GENERAL
Parametros: -
Retorna: Estructura tipo Refrigerador
Descripcion: Inicializa los valores de una estructura Refrigerador 
por medio de apuntadores.
*/ 
Refrigerador *crearListaGeneral(){
    Refrigerador * aux=(Refrigerador*)malloc(sizeof(Refrigerador));
    aux->cabeza=NULL;
    return(aux);
}

/* FUNCION CREAR LISTA
Parametros: -
Retorna: Estructura tipo ListaDP
Descripcion: Inicializa los valores de una estructura ListaDP 
por medio de apuntadores.
*/
ListaDP *crearLista(){
    ListaDP *aux=(ListaDP*)malloc(sizeof(ListaDP));
    aux->cabeza=NULL;
    aux->cola=NULL;
    return(aux);
}

/* FUNCION IS EMPTY
Parametros: Estructura tipo ListaDP
Retorna: Entero
Descripcion: Verifica si una lista esta vacia,
en caso verdadero retorna 1 y en falso retorna 0
*/
int isEmpty(ListaDP lista){
    if(lista.cabeza==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

/* FUNCION INSERTAR REFRIGERADOR
Parametros: Estructura tipo Refrigerador y estructura de tipo NodoLista
Retorna: -
Descripcion: Verifica si la lista esta vacia, en caso de que si asigna
el nodo a la cabeza, si no, se asigna al nodo siguiente
*/
void InsertarRefrigerador(Refrigerador* listaGeneral, NodoLista* listaProducto){
    if(listaGeneral->cabeza==NULL){
        listaGeneral->cabeza=listaProducto; 
    }else{
        NodoLista* puntero = listaGeneral->cabeza;
        while (puntero->sig!=NULL){
            puntero=puntero->sig;
        }
        puntero->sig=listaProducto;
    }   
}

/* FUNCION INSERTAR CABEZA
Parametros: Estructura tipo ListaDP y estructura de tipo Nodo
Retorna: -
Descripcion: Verifica si la lista esta vacia, en caso de que si asigna
el nodo a la cabeza, si no, se asigna al nodo siguiente
*/
void insertar_cabeza(ListaDP *lista, Nodo *aux){
    if(isEmpty(*lista)==1){
        lista->cabeza=aux;
    }
    else{
        lista->cabeza->ant=aux;
        aux->sig=lista->cabeza;
        lista->cabeza=aux;
    }
}

/* FUNCION INSERTAR COLA
Parametros: Estructura tipo ListaDP y estructura de tipo Nodo
Retorna: -
Descripcion: Verifica si la lista esta vacia, en caso de que si asigna
el nodo a la cabeza llamando a la funcion insertar_cabeza, si no, se 
signa al nodo siguiente
*/
void insertar_cola(ListaDP *lista, Nodo *aux){
    Nodo *cola;
    if(isEmpty(*lista)==1){
        insertar_cabeza(lista,aux);
    }
    else{
        cola = lista->cabeza;
        while(cola->sig != NULL){
            cola=cola->sig;
        }
        cola->sig=aux;
        aux->ant=cola;
        cola=aux;
        lista->cola=aux;
    }
}

/* FUNCION QUITAR COLA
Parametros: Estructura tipo ListaDP
Retorna: -
Descripcion: Verifica si una lista esta vacia,
y elimina la cola de la lista.
*/
void quitar_cola(ListaDP *lista){
    Nodo *cola;
    Nodo * aux;
    if(isEmpty(*lista)==1){
        printf("\n La lista esta vacia\n");    
    }
    else
    {
        if(lista->cabeza->sig == NULL)
        {
            cola=lista->cabeza;
            lista->cabeza=NULL;
            free(cola);
            printf("\n  \n");
        }
        else
        {
            cola=lista->cabeza;
            while(cola->sig != NULL)
            {
                cola = cola->sig;
            }
            aux=cola;
            cola=aux->ant;
            cola->sig=NULL;
            aux->ant=NULL;
            free(aux);
        }
    }
}

/* FUNCION PRINT REFRIGERADOR
Parametros: Estructura tipo Refrigerador
Retorna: -
Descripcion: Verifica si una lista esta vacia e
imprime los valores en ella
*/
void printRefrigerador(Refrigerador *refrigerador){
    NodoLista *aux =refrigerador->cabeza;
    if(refrigerador->cabeza!=NULL){
        printf("\n\t\t\tREFRIGERADOR\n");
        while (aux!=NULL){
            printf("\n________________________________________________________________________\n");
            printf("\t\t\t%ss\n",aux->lista->cabeza->info->tipo);
            printLista(aux->lista);
            aux=aux->sig;
            printf("\n________________________________________________________________________\n");
        }
    }
}

/* FUNCION PRINT LISTA
Parametros: Estructura tipo ListaDP
Retorna: -
Descripcion: Verifica si una lista esta vacia e
imprime los valores en ella
*/
void printLista(ListaDP *lista){
    Nodo *aux = lista->cabeza;
    Alimento *ali;
    int cont=1;
    if(lista->cabeza==NULL) {
        printf("\n Lista vacia\n");
    }else{
        while(aux!=NULL){
            ali = aux->info;
            printf("\n\n\t\tProducto %d: ", cont);
            printf("\n Tipo: %s", ali->tipo);
            printf("\n Nombre: %s", ali->nombre);
            printf("\n Precio: $%d", ali->precio);
            printf("\n Fecha de compra: %d-%d-%d", ali->fechaCompra->dia, ali->fechaCompra->mes, ali->fechaCompra->año);
            printf("\n Fecha de caducidad: %d-%d-%d", ali->fechaCad->dia, ali->fechaCad->mes, ali->fechaCad->año);
            printf("\n Estatus de disponibilidad: %d\n", ali->estatus);
            aux=aux->sig;
            cont++;
        }
    }
}

/* FUNCION VACIAR LISTA
Parametros: Estructura tipo ListaDP
Retorna: -
Descripcion: Verifica si una lista esta vacia en caso
de que no procede a vaciarla
*/
void vaciarLista(ListaDP *lista){
    Nodo *aux = lista->cabeza;
    if(isEmpty(*lista)!=1) {
        while(aux!=NULL){
            aux=aux->sig;
            quitar_cabeza(lista);
        }
    }
    else{
        printf("\nLa lista ya esta vacia\n");
    }
}

/* FUNCION VACIAR REFRIGERADOR
Parametros: Estructura tipo Refrigerador
Retorna: -
Descripcion: Verifica si una lista esta vacia en caso
de que no procede a vaciarla
*/
void vaciarRefrigerador(Refrigerador * refri){
    NodoLista *aux =refri->cabeza;
    if(refri->cabeza!=NULL){
        while (aux!=NULL){
            aux=aux->sig;
            quitar_cabezaR(refri);
        }
    }
}

/* FUNCION QUITAR ENMEDIO
Parametros: Estructura tipo ListaDP y estructura tipo Nodo
Retorna: -
Descripcion: Verifica si una lista esta vacia, en caso de que 
la cabeza sea el elemento a borrar hace uso de la funcion 
quitar_cabeza, en caso de que no elimina el nodo por medio de 
la reasignacion con apuntadores con la funcion quitar_cola
*/
void quitar_enmedio(ListaDP *lista, Nodo *elemento){
    Nodo *aux;
    if(isEmpty(*lista)==1){
        printf("\n La lista esta vacia\n");    
    }
    else{
        if(lista->cabeza == elemento){
            printf("%s", elemento->info->nombre);
            quitar_cabeza(lista);

        }else if(lista->cola == elemento){
            quitar_cola(lista);
        }
        else{
            aux=elemento->ant;
            aux->sig=elemento->sig;
            aux=elemento->sig;
            aux->ant=elemento->ant;
            elemento->ant=NULL;
            elemento->sig=NULL;
            free(elemento);
        }
    }
}

/* FUNCION QUITAR CABEZAR
Parametros: Estructura tipo Refrigerador
Retorna: -
Descripcion: Verifica si una lista esta vacia,
y elimina la cabeza de la lista.
*/
void quitar_cabezaR(Refrigerador *refri){
    NodoLista *aux = NULL;
    if(refri->cabeza!=NULL){
        aux=refri->cabeza;
        refri->cabeza=refri->cabeza->sig;
        free(aux);
    }
}

/* FUNCION QUITAR CABEZA
Parametros: Estructura tipo ListaDP
Retorna: -
Descripcion: Verifica si una lista esta vacia,
y elimina la cabeza de la lista.
*/
void quitar_cabeza(ListaDP *lista){
    Nodo *aux = NULL;
    if(!isEmpty(*lista))
    {
        if(lista->cabeza->sig==NULL){
            aux=lista->cabeza;
            lista->cabeza=NULL;
            free(aux);
        }
        else{
            aux=lista->cabeza;
            lista->cabeza=lista->cabeza->sig;
            lista->cabeza->ant=NULL;
            aux->sig=NULL;
            free(aux);
        }
    }
    else{
        printf("\n La lista esta vacia\n");
    }
}

/* FUNCION PIVOTE
Parametros: 2 estructuras de tipo Nodo
Retorna: Estructura tipo Nodo
Descripcion: Particiona la lista y regresa el valor el
valor para posteriormente usar quicksort
*/
Nodo * pivote(Nodo *cabeza, Nodo *cola){
	Nodo * aux1 = cabeza;
	Nodo * aux2 = cabeza->ant;
	Alimento *ali;
	while (aux1 != NULL && aux1 != cola)	{
		if ((aux1->info->precio <= cola->info->precio)){
			if ((aux2 == NULL)){
				aux2 = cabeza;
			}else{
				aux2 = aux2->sig;
			}

			ali = aux1->info;
			aux1->info = aux2->info;
			aux2->info = ali;
		}

		aux1 = aux1->sig;
	}
	if ((aux2 == NULL)){
		aux2 = cabeza;
	}else{
		aux2 = aux2->sig;
	}
	ali = cola->info;
	cola->info = aux2->info;
	aux2->info = ali;
	return aux2;
}

/* FUNCION QUICKSORT
Parametros: 2 estructuras de tipo Nodo
Retorna: -
Descripcion: Recorre la lista y ordena de menor a 
mayor por metodo de quicksort
*/
void quickSort(Nodo *cabeza, Nodo *cola){

	if ((cabeza != cola && cabeza != NULL && cola != NULL && cola->sig != cabeza)){
		Nodo * node = pivote(cabeza, cola);
		if ((node != NULL)){
			quickSort(node->sig, cola);
			quickSort(cabeza, node->ant);
		}
	}
}

/* FUNCION INTERCAMBIO
Parametros: 2 estructuras de tipo Nodo
Retorna: -
Descripcion: Intercambia el primer nodo por el segundo
y el segundo al primero
*/
void intercambio(Nodo *cabeza, Nodo *sig){
	Alimento *aux;
    aux = cabeza->info;
	cabeza->info = sig->info;
	sig->info = aux;
}

/* FUNCION INSERCION
Parametros: Estructura tipo ListaDP
Retorna: -
Descripcion: Recorre la lista y va comparando valores juntos
en caso de que el segundo sea menor utiliza la funcion
intercambio para acomodarlos
*/
void insercion(ListaDP * lista){
	Nodo *aux1 = lista->cabeza;
	Nodo *aux2 = NULL;
	while (aux1 != NULL){
		aux2 = aux1->sig;
		while (aux2 != NULL && aux2->ant != NULL && aux2->info->precio < aux2->ant->info->precio){
			intercambio(aux2, aux2->ant);
			aux2 = aux2->ant;
		}
		aux1 = aux1->sig;
	}
}

/* FUNCION CENTRO LISTA
Parametros: 2 estructuras de tipo Nodo
Retorna: Estructura Nodo
Descripcion: Recorre la lista y busca el valor central
de la lista
*/
Nodo* centro_lista(Nodo* cabeza, Nodo* aux2){
    if (cabeza==NULL){
        return NULL;
    }
    Nodo* aux = cabeza;
    Nodo* aux1 = cabeza->sig;
 
    while (aux1!=aux2){
        aux1 = aux1->sig;
        if (aux1!=aux2){
            aux = aux->sig;
            aux1 = aux1->sig;
        }
    }
    return aux;
}

/* FUNCION BUSQUEDA BINARIA
Parametros: Estructura tipo ListaDP y un entero
Retorna: Estructura Nodo
Descripcion: Recorre la lista y muestra en pantalla el producto
con el valor precio que ingresa el usuario
*/
Nodo* busqueda_binaria(ListaDP *lista, int precio){
    Nodo* aux = NULL;
    Nodo* Cabeza_aux = lista->cabeza;
    do{
        Nodo* centro = centro_lista(Cabeza_aux, aux);
        if (centro == NULL){
            return NULL;
        }

        if (centro->info->precio == precio){
            printf("\n\n\t\tProducto encontrado: ");
            printf("\n Tipo: %s", centro->info->tipo);
            printf("\n Nombre: %s", centro->info->nombre);
            printf("\n Precio: $%d", centro->info->precio);
            printf("\n Fecha de compra: %d-%d-%d", centro->info->fechaCompra->dia, centro->info->fechaCompra->mes, centro->info->fechaCompra->año);
            printf("\n Fecha de caducidad: %d-%d-%d", centro->info->fechaCad->dia, centro->info->fechaCad->mes, centro->info->fechaCad->año);
            printf("\n Estatus de disponibilidad: %d\n", centro->info->estatus);
            return centro;
        }else if (centro->info->precio < precio){
            Cabeza_aux= centro->sig;
        }else{
            aux = centro;
        }
    } while (aux == NULL || aux != Cabeza_aux);
    printf("\n\n\t\tProducto no encontrado\n");
    return NULL;
}

/* FUNCION BUSCA Y QUITA BINARIA
Parametros: Estructura tipo ListaDP y un entero
Retorna: Estructura Nodo
Descripcion: Recorre la lista y elimina de la lista el producto
con el valor precio que ingresa el usuario
*/
Nodo* buscayQuita_binaria(ListaDP *lista, int precio){ 
    Nodo* aux = NULL;
    Nodo* Cabeza_aux = lista->cabeza;
    do
    {
        Nodo* centro = centro_lista(Cabeza_aux, aux);
        if (centro == NULL){
            return NULL;
        }
        if (centro->info->precio == precio){
            printf("\n\n\t\tProducto: ");
            printf("\n Tipo: %s", centro->info->tipo);
            printf("\n Nombre: %s", centro->info->nombre);
            printf("\n Precio: $%d", centro->info->precio);
            printf("\n Fecha de compra: %d-%d-%d", centro->info->fechaCompra->dia, centro->info->fechaCompra->mes, centro->info->fechaCompra->año);
            printf("\n Fecha de caducidad: %d-%d-%d", centro->info->fechaCad->dia, centro->info->fechaCad->mes, centro->info->fechaCad->año);
            printf("\n Estatus de disponibilidad: %d\n", centro->info->estatus);
            printf("\n\nProducto %s eliminado \n",centro->info->tipo);
            quitar_enmedio(lista, centro);
            return centro;
        }else if (centro->info->precio < precio){
            Cabeza_aux = centro->sig;

        }else{
            aux = centro;
        }
    } while (aux == NULL || aux != Cabeza_aux);
    printf("\n\n\t\tProducto no encontrado\n");
    return NULL;
}

/* FUNCION VERIFICA CADUCIDAD
Parametros: 2 estructuras de tipo Fecha
Retorna: entero
Descripcion: Verifica si la fecha de caducidad es posterior
a la fecha de compra, retorna 1 en caso verdadero
*/
int verificaCaducidad(Fecha *fechaCompra, Fecha *fechaCad) {
    if(fechaCompra->año<fechaCad->año){
        return 1;
    }

    if(fechaCompra->año==fechaCad->año){
        if(fechaCompra->mes<fechaCad->mes){
            return 1;
        }
    }

    if(fechaCompra->año==fechaCad->año){
        if(fechaCompra->mes==fechaCad->mes){
            if(fechaCompra->dia<fechaCad->dia){
                return 1;
            }
        }
    }
    if((fechaCad->año==0) && (fechaCad->mes==0) && (fechaCad->dia==0)){
        printf("Fecha de caducidad desconocida\n");
        return 1;
    }
    return 0;
}

/* FUNCION CREAR FECHA
Parametros: Dia, mes, año
Retorna: Estructura de tipo Fecha
Descripcion: Inicializa los valores de una estructura fecha 
con los datos ingresados por el usuario.
*/
Fecha* crearFecha(int dia, int mes, int año){
    Fecha *aux=(Fecha*)malloc(sizeof(Fecha));
    aux->dia=dia;
    aux->mes=mes;
    aux->año=año;
    return aux;
}

/* FUNCION VALIDAR FECHA
Parametros: Dia, mes, año
Retorna: entero
Descripcion: Verifica si la fecha introducida es correcta, retorna 
1 en caso verdadero
*/
int validar_fecha(int dia, int mes, int año){
    int b=0;
    if((año==0) && (mes==0) && (dia==0)){
        return 1;
    }
    if(mes>=1 && mes<=12){
        switch(mes){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(dia>=1 && dia<=31){
                    b=1;
                }
                break;

            case 4: case 6: case 9: case 11:
                if(dia>=1 && dia<=30){
                    b=1;
                }
                break; 
            case 2:
                if((año%4 == 0) && (año%100 != 0) || (año%400 == 0)){
                    if( dia >= 1 && dia <= 29 ){
                        b=1;
                    }
                }else{
                    if(dia>=1 && dia<=28){
                    b=1;
                    } 
                }
                break;
        }
    }
    return b;
}
