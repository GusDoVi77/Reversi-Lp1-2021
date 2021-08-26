# Reversi-Lp1-2021#include <stdio.h>
#include <stdlib.h>
int main (){
	int A[10];//la variable A sera donde se guardaran los numeros ingresados por teclado
	int salida[10];
	int aux;
	int aux2;
	int i,j,k,m;
	int contador=0;
	for(i=0;i<10;i++){
		printf("ingrese los valores enteros: \n");
		scanf("%d",&aux);
		A[i]=aux;
	}

	for(j=0;j<10;j++){
		aux2=A[j];
		for(k=j+1;k<10;k++){
			if(abs(aux2)!=abs(A[k])){
				contador++;
				salida[j]=abs(aux2);
			}
		}
	}
	printf("\n la cantidad de valores absolutos distintos son de: %d",contador);
	printf("\n los valores distintos son :");
	for(m=0;m<contador;m++){
		printf("\n %d",salida[m]);
	}
}
