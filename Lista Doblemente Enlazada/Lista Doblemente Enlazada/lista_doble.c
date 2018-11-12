//
//  main.c
//  Lista Doblemente Enlazada
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
    struct Lista * anterior;
};
Lista * CreadorDeNodos(int dato);
void InsertarListaFinal(Lista ** inicio, int dato, Lista ** Final);
void InsertarListaInicio(Lista ** inicio, int dato, Lista ** Final);
void ImprimirListaDoble(Lista ** inicio);
void ImprimirListaDobleAlreves(Lista ** inicio);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    Lista * inicio1=NULL;
    Lista * final1=NULL;
    InsertarListaFinal(&inicio1, 5, &final1);
    InsertarListaFinal(&inicio1, 1, &final1);
    InsertarListaFinal(&inicio1, 3, &final1);
    ImprimirListaDoble(&inicio1);
    printf("\n\n");
    ImprimirListaDobleAlreves(&final1);
    printf("\n\n");
    Lista * inicio2=NULL;
    Lista * final2=NULL;
    InsertarListaInicio(&inicio2, 1, &final2);
    InsertarListaInicio(&inicio2, 5, &final2);
    InsertarListaInicio(&inicio2, 4, &final2);
    ImprimirListaDoble(&inicio2);
    printf("\n\n");
    ImprimirListaDobleAlreves(&final2);
    printf("\n\n");
    return 0;
}
Lista * CreadorDeNodos(int dato){
    Lista * Nuevo = malloc(sizeof(Lista));
    Nuevo->dato=dato;
    Nuevo->siguiente=NULL;
    Nuevo->anterior=NULL;
    return Nuevo;
}
void InsertarListaFinal(Lista ** inicio, int dato, Lista ** Final){
    Lista * nodo = CreadorDeNodos(dato);
    Lista * aux;
    if (*inicio==NULL){
        *inicio=nodo;
    }
    else{
        aux = *inicio;
        while (aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nodo;
        nodo->anterior=aux;
        *Final=nodo;
    }
}
void InsertarListaInicio(Lista ** inicio, int dato, Lista ** Final){
    Lista * nodo = CreadorDeNodos(dato);
    if (*inicio==NULL){
        *inicio=nodo;
        *Final = *inicio;
    }
    else{
        (*inicio)->anterior=nodo;
        nodo->siguiente=(*inicio);
        (*inicio)=nodo;
    }
}
void ImprimirListaDoble(Lista ** inicio){
    Lista * corredor = *inicio;
    while (corredor!=NULL){
        printf("%d ", corredor->dato);
        corredor=corredor->siguiente;
    }
}
void ImprimirListaDobleAlreves(Lista ** final){
    Lista * corredor = *final;
    while(corredor!=NULL){
        printf("%d ", corredor->dato);
        corredor=corredor->anterior;
    }
}

