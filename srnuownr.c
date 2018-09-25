#include <stdio.h>
float recursiva1(int dato);
int g(int dato);
int main(int argc, const char * argv[]){
	int dato, veces, i; float resultado=0;
	scanf("%d", &veces);
	for (i=1; i<=veces; i++){
		scanf("%d", &dato);
		//resultado+=recursiva1(dato);
	}
	printf("%f", resultado);
	return 0;
}
int g(int dato){
	return (1+2*(dato-1))*(2*dato+1);
}
int Num(int dato){
	if(dato==0){
		return 0;
	}
	else{
		return g(dato)+Num(dato-1);
	}
}
int Den(int dato){
	if(dato==0){
		return g(0);
	}
	else{
		return g(dato)*Den(dato-1);
	}
}
