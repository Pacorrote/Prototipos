//
//  main.c
//  Lista Circular
//
//  Created by Francisco Árciga Nolasco on 7/11/18.
//  Copyright © 2018 Francisco Árciga Nolasco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define T 1
#define F 0
typedef struct LiC LiC;
struct LiC{
    int dato;
    struct LiC * siguiente;
};
LiC * CreadorDeNodos(int dato);
void InsertarInicio(LiC ** inicio, int dato);
void InsertarFinal(LiC ** inicio, int dato);
void imprimir(LiC ** inicio);
int BuscarNumero(LiC ** inicio, int num);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    LiC * inicio=NULL;
    InsertarFinal(&inicio, 1);
    InsertarFinal(&inicio, 2);
    InsertarFinal(&inicio, 3);
    imprimir(&inicio);
    printf("%d ", BuscarNumero(&inicio, 10));

    return 0;
}
LiC * CreadorDeNodos(int dato){
    LiC * nodo = malloc(sizeof(LiC));
    nodo->dato=dato;
    nodo->siguiente=NULL;
    return nodo;
}
void InsertarInicio(LiC ** inicio, int dato){
    LiC * Nodo = CreadorDeNodos(dato);
    LiC * aux;
    if(*inicio==NULL){
        *inicio=Nodo;
        (*inicio)->siguiente=(*inicio);
    }
    else{
        aux=(*inicio);
        while (aux->siguiente!=(*inicio)){
            aux=aux->siguiente;
        }
        aux->siguiente=Nodo;
        aux=Nodo;
        aux->siguiente=(*inicio);
    }
}
void InsertarFinal(LiC ** inicio, int dato){
    LiC * Nodo = CreadorDeNodos(dato);
    LiC * aux;
    if (*inicio==NULL){
        *inicio=Nodo;
        (*inicio)->siguiente=(*inicio);
    }
    else{
        aux=(*inicio);
        while(aux->siguiente!=(*inicio)){
            aux=aux->siguiente;
        }
        aux->siguiente=Nodo;
        aux=Nodo;
        aux->siguiente=(*inicio);
    }
}
void imprimir(LiC ** inicio){
    printf("%d ",(*inicio)->dato);
    LiC * corredor = (*inicio)->siguiente;
    while (corredor!=(*inicio)) {
        printf("%d ", corredor->dato);
        corredor=corredor->siguiente;
    }
}
int BuscarNumero (LiC ** inicio, int numero){
    if (*inicio==NULL){
        return F;
    }
    else{
        LiC * aux = *inicio;
        while(aux->siguiente!=(*inicio) && aux->dato!=numero){
            aux=aux->siguiente;
        }
        if (aux->dato==numero){
            return T;
        }
        else{
            return F;
        }
    }
}
