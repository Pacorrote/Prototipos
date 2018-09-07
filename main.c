//
//  main.c
//  prueba
//
//  Created by Usuario on 12/08/18.
//  Copyright © 2018 Usuario. All rights reserved.
//

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define T 1
#define F 0
int numerosPrimos[25]={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void NumeroPrimo(long long a, int *b);
int main(int argc, const char * argv[]) {
    int entradas, P=0, j;
    long long i;
    scanf("%d", &entradas);
    for(j=1; j<=entradas; j++){
        scanf("%lld", &i);
        NumeroPrimo(i, &P);
        if (P==T)
            printf("UltraPrimo\n");
        else if (P==F)
            printf("No UltraPrimo\n");
    }
    return 0;
}
void NumeroPrimo(long long a, int *b){
    long long acumulador=0;
    if (a>1 && a<=97){
        for (int i=0; i<25; i++){
            if (a==numerosPrimos[i])
                acumulador++;
        }
        if (acumulador==1)
            *b=T;
        else
            *b=F;
    }
    else{
        for (int i=0; i<25; i++){
            if (a%numerosPrimos[i]==0)
                acumulador+=1;
        }
        if (acumulador==0)
            *b=T;
        else
            *b=F;
    }
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    char frase[100];
    int i, a, b;
    scanf("%d", &a); scanf("%d", &b);
    fflush(stdin);
    scanf(" %[^\n]", frase);
    for (i = b; i>=a;i--) {
        printf("%c", frase[i]);
    }
    for (i=b+1; i<=strlen(frase); i++){
        printf("%c", frase[i]);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    int datos, i, i1, j;
    scanf("%d", &datos);
    int vector[datos];
    int auxiliar[1];
    int auxiliar2[1];
    for (i=0; i<datos; i++){
        scanf("%d", &vector[i]);
        if (i==0)
            auxiliar[1]=vector[i];
    }
    for (i=0; i<datos; i++){
        for (j=i+1; j<datos; j++){
            if (vector[i]>vector[j]){
                auxiliar2[1]=vector[j];
                vector[j]=vector[i];
                vector[i]=auxiliar2[1];
            }
        }
        if (vector[i]==auxiliar[1])
            i1=i;
    }
    printf("%d", i1);
return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Numero Numero;
struct Numero{
    int digito;
    struct Numero * siguiente;
    struct Numero * anterior;
};
Numero *inicio1=NULL;
Numero *ultimo1=NULL;
Numero *inicio2=NULL;
Numero *ultimo2=NULL;
Numero *inicios=NULL;
Numero *ultimos=NULL;
void creareinsertar1(int dato);
void creareinsertar2(int dato);
Numero *creareinsertarresultado(Numero *l, int dato);
void imprimirresultado1();
void imprimirresultado2();
void imprimirresultado3();
void suma();
int main(int argc, const char * argv[]){
    long numero1, numero2;
    int digito, filas=0, columnas=0;
    printf("Inserte numero 1: ");
    scanf("%ld", &numero1);
    printf("Inserte numero 2: ");
    scanf("%ld", &numero2);
    while(numero1>=1){
        digito=numero1%10;
        numero1/=10;
        creareinsertar1(digito);
        columnas++;
        //printf("%i", digito);
    }
    printf(" \n");
    while(numero2>=1){
        digito=numero2%10;
        numero2/=10;
        creareinsertar2(digito);
        filas++;
       // printf("%i ", digito);
    }
    Numero *nodo1=creareinsertarresultado(ultimos, 9);
    Numero *nodo2=creareinsertarresultado(ultimos, 7);
    Numero *nodo3=creareinsertarresultado(ultimos, 5);
    inicios=nodo1;
    while (inicios!=NULL) {
        printf("%d", inicios->digito);
        inicios=inicios->siguiente;
    }
    //suma();
    //imprimirresultado1();
    
return 0;
}
void creareinsertar1(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    Numero *at;
    if (inicio1==NULL){
        inicio1=Nuevodigito;
        ultimo1=Nuevodigito;
        aux=inicio1;
    }
    else{
        aux=inicio1;
        at=aux->anterior;
        at=Nuevodigito;
        Nuevodigito->siguiente=aux;
        inicio1=Nuevodigito;
        aux=Nuevodigito;
    }
}
void creareinsertar2(int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    Numero *at;
    if (inicio2==NULL){
        inicio2=Nuevodigito;
        ultimo2=Nuevodigito;
        aux=inicio2;
    }
    else{
        aux=inicio2;
        at=aux->anterior;
        at=Nuevodigito;
        Nuevodigito->siguiente=aux;
        inicio2=Nuevodigito;
        aux=Nuevodigito;
    }
}
void imprimirresultado2(){
    /*
    Numero *aux=inicio2;
    while (aux!=NULL) {
        printf("%d", aux->digito);
        aux=aux->siguiente;
    }
     */
}
Numero *creareinsertarresultado(Numero *l, int dato){
    Numero *Nuevodigito = malloc(sizeof(Numero));
    Nuevodigito->digito = dato;
    Nuevodigito->anterior=NULL;
    Nuevodigito->siguiente=NULL;
    Numero *aux;
    Numero *at;
    Numero *dt;
    if (l==NULL){
        l=Nuevodigito;
        aux=l;
        dt=l;
    }
    else{
        aux=l;
        at=aux->anterior;
        at=Nuevodigito;
        Nuevodigito->siguiente=aux;
        dt=aux;
        aux=Nuevodigito;
    }
}
void suma(){
    Numero * aux1=ultimo1;
    Numero * aux2=ultimo2;
    Numero *sumalist;
    if(aux1==NULL || aux2==NULL){
        printf("Una de las dos listas estan vacias\n");
    }
    else{
        int sumadigito, acarreo=0, sumadigito1;
        while(aux1!=NULL || aux2!=NULL){
            sumadigito=(aux1->digito)+(aux2->digito)+acarreo;
            sumadigito1=sumadigito%10;
            acarreo/=10;
            //sumalist=creareinsertarresultado(inicios, ultimos,sumadigito1);
            //printf("%d", sumalist->digito);
            aux1=aux1->anterior;
            aux2=aux2->anterior;
        }
    }
}
void imprimirresultado1(){
    
    /*Numero *aux=inicios;
    while (aux!=NULL) {
        printf("%d", aux->digito);
        aux=aux->siguiente;
    }
    */
}
//SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
/*
 if(head==NULL){
 head=Nuevonodo;
 }
 else{
 SinglyLinkedListNode *auxiliar=head;
 SinglyLinkedListNode *anterior;
 int posicion=1;
 while(auxiliar->next!=NULL && posicion<=position){
 anterior=auxiliar;
 auxiliar=auxiliar->next;
 posicion++;
 }
 auxiliar=auxiliar->next;
 anterior->next=Nuevonodo;
 anterior=Nuevonodo;
 anterior->next=auxiliar;
 }
 */
/*while (node) {
    SinglyLinkedListNode* temp = node;
    node = node->next;
    
    free(temp);
}*/

 /*#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 int main(int argc, const char * argv[]) {
     char *frase=malloc(100*sizeof(char));
     int i, a, b;
     scanf("%d %d", &a , &b);
     fflush(stdin);
     scanf(" %[^\n]", frase);
     for (i = b; i>=a;i--) {
         printf("%c", frase[i]);
     }
     for (i=b+1; i<=strlen(frase); i++){
         printf("%c", frase[i]);
     }
 return 0;
 }
*/
