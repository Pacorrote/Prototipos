//
//  main.c
//  Lista simple
//
//  Created by Francisco Árciga Nolasco on 7/11/18.
//  Copyright © 2018 Francisco Árciga Nolasco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Lista Lista;
struct Lista{
    int dato;
    struct Lista * siguiente;
};
void InsertarListaAlFinal(Lista ** inicio, int dato);
void InsertarListaAlinicio(Lista ** inicio, int dato);
Lista * CreadorDeNodos(int dato);
void ImprimirLista(Lista ** inicio);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    Lista * inicio=NULL;
    InsertarListaAlinicio(&inicio, 2);
    InsertarListaAlinicio(&inicio, 3);
    InsertarListaAlinicio(&inicio, 7);
    InsertarListaAlinicio(&inicio, 9);
    InsertarListaAlFinal(&inicio, 1);
    InsertarListaAlFinal(&inicio, 2);
    InsertarListaAlFinal(&inicio, 10);
    InsertarListaAlFinal(&inicio, 11);
    ImprimirLista(&inicio);
    return 0;
}

Lista * CreadorDeNodos(int dato){
    Lista * Nuevo = malloc(sizeof(Lista));
    Nuevo->dato=dato;
    Nuevo->siguiente=NULL;
    return Nuevo;
}
void InsertarListaAlFinal(Lista ** inicio, int dato){
    Lista * Nuevo=CreadorDeNodos(dato);
    Lista * aux;
    if (*inicio==NULL){
        *inicio=Nuevo;
    }
    else{
        aux=(*inicio);
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=Nuevo;
    }
}
void InsertarListaAlinicio(Lista ** inicio, int dato){
    Lista * Nuevo=CreadorDeNodos(dato);
    if (*inicio==NULL){
        *inicio=Nuevo;
    }
    else{
        Nuevo->siguiente=*inicio;
        *inicio=Nuevo;
    }
}
void ImprimirLista(Lista ** inicio){
    Lista * corredor = *inicio;
    while(corredor!=NULL){
        printf("%d ", corredor->dato);
        corredor=corredor->siguiente;
    }
}

