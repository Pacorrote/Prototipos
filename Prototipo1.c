#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cola cola;
struct cola{
	char caracter;
	struct cola * anterior;
	struct cola * siguiente;
};
void insertarCola(cola ** inicio, char caracter){
	cola * Nuevo = malloc(sizeof(cola));
	Nuevo->caracter=caracter;
	Nuevo->anterior=NULL;
	Nuevo->siguiente=NULL;
	cola * aux=NULL;
	cola * ant;
	if(*inicio!=NULL){
		if(*inicio->siguiente==NULL){
			Nuevo->anterior = *inicio;
			*inicio->siguiente = Nuevo;
		}
		else{
			aux = *inicio->siguiente;
			ant = *inicio;
			while(aux!=NULL){
				aux=aux->siguiente;
				ant=ant->siguiente;
			}
			ant->siguiente=Nuevo;
			aux=ant;
			ant=Nuevo;
			ant->anterior=aux;
		}
	}
	else{
		*inicio=Nuevo;
	}
}
int recorrersegundapalabra(cola ** inicio){
	
}
int comparaciones(cola ** cola1, cola ** cola2){
	
}
int main(int argc, char *argv[]) {
	char segundapalabra[10];
	char primerpalabra[20];
	int i;
	cola * p=NULL;
	cola * s=NULL;
	scanf("%s", &segundapalabra);
	scanf("%s", &primerpalabra);
	for(i=0; i<strlen(segundapalabra); i++){
		insertarCola(&s, segundapalabra[i]);
	}
	for(i=0; i<strlen(primerpalabra); i++){
		insertarCola(&p, primerpalabra[i]);
	}
	return 0;
}

