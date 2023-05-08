//Jorge Infante Fragoso - 2203025256
//Karina Alcantara Segura - 2203025452

#include <stdio.h>
#include <stdlib.h>
#include "listaP.h"

int main(){
    int menu, menu2;
    Nodo *producto;
    Fecha *fechaCompra, *fechaCad;
    char tipo[20], nombre[20];
    int precio, estatus, precioBuscar, dia, mes, año;
    ListaDP *bebidas=crearLista();
    ListaDP *embutidos=crearLista();
    ListaDP *lacteos=crearLista();
    ListaDP *frutas=crearLista();
    ListaDP *verduras=crearLista();
    ListaDP *proteinas=crearLista();
    Refrigerador *refrigerador=crearListaGeneral();
    do{
        //Menu 1
        printf("\n________________________________________________________________________");
        printf("\n\tBienvenido a las listas del contenido de tu refrigerador\n\n");
        printf("Estos son las categorias de los alimentos que podemos enlistar:\n\n");
        printf("\t\t1 - Bebidas\n");
        printf("\t\t2 - Embutidos\n");
        printf("\t\t3 - Frutas\n");
        printf("\t\t4 - Lacteos\n");
        printf("\t\t5 - Proteinas\n");
        printf("\t\t6 - Verduras\n");
        printf("\t\t7 - Mostrar la lista del refrigerador\n");
        printf("\t\t8 - Salir\n");
        printf("________________________________________________________________________\n");
        printf("Dime el numero de la categoria a la que quieres ingresar:");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                do{
                    //Menu 2 - Bebidas
                    printf("\n________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Bebidas\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar una bebida\n");
                    printf("\t\t2 - Quitar una bebida\n");
                    printf("\t\t3 - Mostrar la lista de bebidas\n");
                    printf("\t\t4 - Buscar una bebida\n");
                    printf("\t\t5 - Ordenar bebidas por precio\n");
                    printf("\t\t6 - Vaciar lista de bebidas\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\n|   Bebida:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);
                            producto=crear_Nodo(crearAlimento("Bebida", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(bebidas, producto);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(bebidas->cabeza==NULL){
                                printf("\nLista bebidas vacia");
                            }else{
                                printf("\nIngrese el precio de la bebida que desea eliminar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenara primero la lista.");
                                quickSort(bebidas->cabeza,bebidas->cola);
                                producto=buscayQuita_binaria(bebidas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(bebidas);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(bebidas->cabeza==NULL){
                                printf("\nLista bebidas vacia");
                            }else{
                                printf("\nIngrese el precio de la bebida que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                quickSort(bebidas->cabeza,bebidas->cola);
                                producto=busqueda_binaria(bebidas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(bebidas->cabeza==NULL){
                                printf("\nLista bebidas vacia");
                            }else{
                                quickSort(bebidas->cabeza, bebidas->cola);
                                printf("\nBebidas ordenadas por precio (quicksort)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(bebidas);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;

            case 2:
                do{
                    //Menu 2 - Embutidos
                    printf("________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Embutidos\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar un embutido\n");
                    printf("\t\t2 - Quitar un embutido\n");
                    printf("\t\t3 - Mostrar la lista de embutidos\n");
                    printf("\t\t4 - Buscar un embutido\n");
                    printf("\t\t5 - Ordenar embutidos por precio\n");
                    printf("\t\t6 - Vaciar lista de embutidos\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\n|   Embutido:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);
                            producto=crear_Nodo(crearAlimento("Embutido", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(embutidos, producto);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(embutidos->cabeza==NULL){
                                printf("\nLista embutidos vacia");
                            }else{
                                printf("\nIngrese el precio del embutido que desea eliminar:\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenará primero la lista.");
                                insercion(embutidos);
                                producto=buscayQuita_binaria(embutidos, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(embutidos);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(embutidos->cabeza==NULL){
                                printf("\nLista embutidos vacia");
                            }else{
                                printf("\nIngrese el precio del embutido que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                insercion(embutidos);
                                producto=busqueda_binaria(embutidos, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(embutidos->cabeza==NULL){
                                printf("\nLista embutidos vacia");
                            }else{
                                insercion(embutidos);
                                printf("\nEmbutidos ordenados por precio (insercion)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(embutidos);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;

            case 3:
                do{
                    //Menu 2 - Frutas
                    printf("________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Frutas\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar una fruta\n");
                    printf("\t\t2 - Quitar una fruta\n");
                    printf("\t\t3 - Mostrar la lista de frutas\n");
                    printf("\t\t4 - Buscar una fruta\n");
                    printf("\t\t5 - Ordenar frutas por precio\n");
                    printf("\t\t6 - Vaciar lista de frutas\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\n|   Fruta:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);
                            producto=crear_Nodo(crearAlimento("Fruta", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(frutas, producto);
                            system("pause");
                            system("cls");
                            break;

                        case 2:
                            if(frutas->cabeza==NULL){
                                printf("\nLista frutas vacia");
                            }else{
                                printf("\nIngrese el precio de la fruta que desea eliminar:\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenara primero la lista.");
                                quickSort(frutas->cabeza,frutas->cola);
                                producto=buscayQuita_binaria(frutas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(frutas);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(frutas->cabeza==NULL){
                                printf("\nLista frutas vacia");
                            }else{
                                printf("\nIngrese el precio de la fruta que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                quickSort(frutas->cabeza,frutas->cola);
                                producto=busqueda_binaria(frutas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(frutas->cabeza==NULL){
                                printf("\nLista frutas vacia");
                            }else{
                                quickSort(frutas->cabeza, frutas->cola);
                                printf("\nFrutas ordenadas por precio (quicksort)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(frutas);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;

            case 4:
                do{
                    //Menu 2 - Lacteos
                    printf("________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Lacteos\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar un lacteo\n");
                    printf("\t\t2 - Quitar un lacteo\n");
                    printf("\t\t3 - Mostrar la lista de lacteos\n");
                    printf("\t\t4 - Buscar un lacteo\n");
                    printf("\t\t5 - Ordenar lacteos por precio\n");
                    printf("\t\t6 - Vaciar lista de lacteos\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\n|   Lacteo:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);

                            producto=crear_Nodo(crearAlimento("Lacteo", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(lacteos, producto);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(lacteos->cabeza==NULL){
                                printf("\nLista lacteos vacia");
                            }else{
                                printf("\nIngrese el precio del lacteo que desea eliminar:\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenará primero la lista.");
                                insercion(lacteos);
                                producto=buscayQuita_binaria(lacteos, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(lacteos);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(lacteos->cabeza==NULL){
                                printf("\nLista lacteos vacia");
                            }else{
                                printf("\nIngrese el precio del lacteo que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                insercion(lacteos);
                                producto=busqueda_binaria(lacteos, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(lacteos->cabeza==NULL){
                                printf("\nLista lacteos vacia");
                            }else{
                                insercion(lacteos);
                                printf("\nLacteos ordenados por precio (insercion)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(lacteos);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;

            case 5:
                do{
                    //Menu 2 - Proteinas
                    printf("________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Proteinas\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar una proteina\n");
                    printf("\t\t2 - Quitar una proteina\n");
                    printf("\t\t3 - Mostrar la lista de proteinas\n");
                    printf("\t\t4 - Buscar una proteina\n");
                    printf("\t\t5 - Ordenar proteinas por precio\n");
                    printf("\t\t6 - Vaciar lista de proteinas\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\n|   Proteina:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);

                            producto=crear_Nodo(crearAlimento("Proteina", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(proteinas, producto);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(proteinas->cabeza==NULL){
                                printf("\nLista proteinas vacia");
                            }else{
                                printf("\nIngrese el precio de la que desea eliminar:\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenará primero la lista.");
                                quickSort(proteinas->cabeza,proteinas->cola);
                                producto=buscayQuita_binaria(proteinas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(proteinas);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(proteinas->cabeza==NULL){
                                printf("\nLista proteinas vacia");
                            }else{
                                printf("\nIngrese el precio de la proteina que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                quickSort(proteinas->cabeza,proteinas->cola);
                                producto=busqueda_binaria(proteinas, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(proteinas->cabeza==NULL){
                                printf("\nLista proteinas vacia");
                            }else{
                                quickSort(proteinas->cabeza, proteinas->cola);
                                printf("\nProteinas ordenadas por precio (quicksort)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(proteinas);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;

            case 6:
                do{
                    //Menu 2 - Verduras
                    printf("________________________________________________________________________");
                    printf("\n\tEstas en la seccion de Verduras\n\n");
                    printf("\t\tQue deseas hacer:\n\n");
                    printf("\t\t1 - Ingresar una verdura\n");
                    printf("\t\t2 - Quitar una verdura\n");
                    printf("\t\t3 - Mostrar la lista de verduras\n");
                    printf("\t\t4 - Buscar una verdura\n");
                    printf("\t\t5 - Ordenar verduras por precio\n");
                    printf("\t\t6 - Vaciar lista de verduras\n");
                    printf("\t\t7 - Salir\n");
                    printf("________________________________________________________________________\n");
                    printf("Dime el numero de lo que quieres hacer:");
                    scanf("%d", &menu2);
                    switch(menu2){
                        case 1:
                            printf("\n|   Verduras:  |\n");
                            printf("Nombre:");
                            scanf(" %[^\n]", &nombre);
                            printf("Precio:");
                            scanf("%d", &precio);
                            printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCompra=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCompra->dia, fechaCompra->mes, fechaCompra->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de compra (el formato de fecha es el siguiente, no omitas guiones ni digitos: 00-00-0000):");
                                scanf("%d-%d-%d", &fechaCompra->dia, &fechaCompra->mes, &fechaCompra->año);
                            }
                            printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                            printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                            scanf("%d-%d-%d", &dia, &mes, &año);
                            fechaCad=crearFecha(dia, mes, año);
                            while(validar_fecha(fechaCad->dia, fechaCad->mes, fechaCad->año)==0){
                                printf("Fecha incorrecta, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            while(verificaCaducidad(fechaCompra,fechaCad)==0){
                                printf("La fecha de caducidad debe ser mayor que la de compra, intentelo de nuevo\n\n");
                                printf("Fecha de caducidad (el formato de fecha es el siguiente, no omitas guiones, ni digitos: 00-00-0000):\n");
                                printf("\nEn caso de desconocer esta fecha, coloque ceros en el formato indicado\n");
                                scanf("%d-%d-%d", &fechaCad->dia, &fechaCad->mes, &fechaCad->año);
                            }
                            printf("Estatus (ingrese 1 si hay disponibilidad y 0 si no):");
                            scanf("%d", &estatus);

                            producto=crear_Nodo(crearAlimento("Verdura", nombre, precio, fechaCompra, fechaCad, estatus));
                            insertar_cola(verduras, producto);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            if(verduras->cabeza==NULL){
                                printf("\nLista verduras vacia");
                            }else{
                                printf("\nIngrese el precio de la verdura que desea eliminar:\n");
                                scanf("%d", &precioBuscar);
                                printf("Se ordenará primero la lista.");
                                insercion(verduras);
                                producto=buscayQuita_binaria(verduras, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printLista(verduras);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(verduras->cabeza==NULL){
                                printf("\nLista verduras vacia");
                            }else{
                                printf("\nIngrese el precio de la verdura que desea buscar: (Busqueda binaria)\n");
                                scanf("%d", &precioBuscar);
                                printf("\n\tSe ordenara primero la lista.\n");
                                insercion(verduras);
                                producto=busqueda_binaria(verduras, precioBuscar);
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(verduras->cabeza==NULL){
                                printf("\nLista verduras vacia");
                            }else{
                                insercion(verduras);
                                printf("\nVerduras ordenadas por precio (insercion)\n\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            vaciarLista(verduras);
                            system("pause");
                            system("cls");
                            break;
                        case 7:
                            break;
                        default: 
                            printf("Opcion incorrecta");
                            system("cls");
                            break;
                    }
                }while(menu2!=7);
                break;
            case 7:
                //Ingresa productos a lista refrigerador
                if(bebidas->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(bebidas));
                }
                if(embutidos->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(embutidos));
                }
                if(frutas->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(frutas));
                }
                if(lacteos->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(lacteos));
                }
                if(proteinas->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(proteinas));
                }
                if(verduras->cabeza!=NULL){
                    InsertarRefrigerador(refrigerador,crear_NodoLista(verduras));
                }
                printRefrigerador(refrigerador);
                vaciarRefrigerador(refrigerador);
                break;
            case 8:
                free(refrigerador);
                printf("\nRefrigerador cerrado\n");
                break;
            default:
                printf("\nOpcion incorrecta");
                break;
        }
    }while(menu!=8);
}