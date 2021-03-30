#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "juego.h"
//Imprime el tablero (B = Ficha blanca; N = Ficha Negra)
void ImprimirTablero(int *puntablero){
	int i,j;
	printf("    A   B   C   D   E   F   G   H\n");
	printf("  +---+---+---+---+---+---+---+---+\n");
	for(i=0;i<8;i++){
		printf("%d |",i+1);
		for(j=0;j<8;j++){
			if(*(puntablero+(i*8)+j)==0){
				printf("   |");
			}
			if(*(puntablero+(i*8)+j)==1){
				printf(" N |");
			}
			if(*(puntablero+(i*8)+j)==2){
				printf(" B |");
			}
		}
		printf("\n  +---+---+---+---+---+---+---+---+\n");
	}
}
void Comganador(int *puntablero){
	if(Ganador(puntablero)==2){
		printf("\nBlancas ganan\n");
	}
	if(Ganador(puntablero)==1){
		printf("\nNegras ganan\n");
	}
	if(Ganador(puntablero)==2){
		printf("\nEs un empate\n");
	}
}
// funcion para agregar una ficha manualmente
// 1=negro
// 2=blanco
void JugarJugador(int *puntablero,int color){
	int fila,numcolumna,valido=0;
	char columna;
	while(valido==0){
		printf("Ingrese fila(numero)\n");
		scanf("%d",&fila);
		while(getchar()!='\n');
		while(fila<1 || fila >8){
			printf("\nLo ingresado es incorrecto\nVuelva a ingresar");
			scanf("%d",&fila);
			while(getchar()!='\n');
		}
		printf("Ingrese columna (Mayuscula)\n");
		scanf("%c",&columna);
		while(getchar()!='\n');
		numcolumna=columna-65;
		while(numcolumna<0 || numcolumna>8){
			printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
			scanf("%c",&columna);
			while(getchar()!='\n');
			numcolumna=columna-65;
		}
		if(PermitidoCambio(puntablero,fila-1,numcolumna,color)){
			Agregarficha(puntablero,fila-1,numcolumna,color);
			valido=1;
		}
		else{
			printf("\nJugada no valida\n");
		}
	}
}
void JvC(int *puntablero){
	int empieza;
	int colorju,colorcom;
	printf("\nIngresa quien empieza \n1-Humano \n2-Computadora\n");
	printf("3-Aleatorio");
	scanf("%d",&empieza);
	while(getchar()!='\n');
	while(empieza<1 || empieza > 3){
		printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
		scanf("%d",&empieza);
		while(getchar()!='\n');
	}
	if(empieza==3){
		empieza= rand()%2+1;
	}
	printf("\nIngresa el color que quieres ser \n1-Blanco \n2-Negro\n");
	printf("3-Aleatorio");
	scanf("%d",&colorju);
	while(getchar()!='\n');
	while(colorju<1 || colorju > 3){
		printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
		scanf("%d",&colorju);
		while(getchar()!='\n');
	}
	if(colorju==3){
		colorju= rand()%2+1;
	}
	if(colorju==2){
		printf("Usted jugara con blancas\n");
		colorcom=1;
	}
	if(colorju==1){
		printf("Usted jugara con negras\n");
		colorcom=2;
	}
	if(empieza==2){
		printf("Comienza la computadora\n");
		ImprimirTablero(puntablero);
	}
	if(empieza==1){
		printf("Comienza usted Don\n");
		ImprimirTablero(puntablero);
		JugarJugador(puntablero,colorju);
		ImprimirTablero(puntablero);
	}
	while(JugadaValida(puntablero,colorcom)==1){
		printf("\nJuega la computadora\n");
		JuegoComp(puntablero,colorcom);
		ImprimirTablero(puntablero);
		if(JugadaValida(puntablero,colorju)==0){
			break;
		}
		printf("\nJuega usted\n");
		JugarJugador(puntablero,1);
		ImprimirTablero(puntablero);
	}
	Comganador(puntablero);
}
void JvJ(int *puntablero){
	int empieza;
	printf("\nIngresa quien empieza \n1-Negras\n 2-Blancas\n ");
	printf("3-Aleatorio");
	scanf("%d",&empieza);
	while(getchar()!='\n');
	while(empieza<1 || empieza > 3){
		printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
		scanf("%d",&empieza);
		while(getchar()!='\n');
	}
	if(empieza==3){
		empieza= rand()%2+1;
	}
	if(empieza==1){
		printf("Juegan negras");
		JugarJugador(puntablero,1);
		ImprimirTablero(puntablero);
	}
	ImprimirTablero(puntablero);
	while(JugadaValida(puntablero,2)==1){
		printf("\nJuegan blancas\n");
		JugarJugador(puntablero,2);
		ImprimirTablero(puntablero);
		if(JugadaValida(puntablero,1)==0){
			break;
		}
		printf("\nJuegan negras\n");
		JugarJugador(puntablero,1);
		ImprimirTablero(puntablero);
	}
	Comganador(puntablero);
}
void CvC(int *puntablero){
	int empieza;
	printf("\nIngresa quien empieza \n1-Negras\n2-Blancas  \n");
	printf("3-Aleatorio");
	scanf("%d",&empieza);
	while(getchar()!='\n');
	while(empieza<1 || empieza > 3){
		printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
		scanf("%d",&empieza);
		while(getchar()!='\n');
	}
	if(empieza==3){
		empieza= rand()%2+1;
	}
	if(empieza==1){
		printf("\nJuegan negras\n");
		JuegoComp(puntablero,1);
		ImprimirTablero(puntablero);
		printf("Presione cualquier tecla para continuar");
		getchar();
		while(getchar()!='\n');
	}
	while(JugadaValida(puntablero,2)==1){
		printf("\nJuegan blancas\n");
		JuegoComp(puntablero,2);
		ImprimirTablero(puntablero);
		printf("Presione cualquier tecla para continuar");
		getchar();
		while(getchar()!='\n');
		if(JugadaValida(puntablero,1)==0){
			break;
		}
		printf("\nJuegan negras\n");
		JuegoComp(puntablero,1);
		ImprimirTablero(puntablero);
		printf("Presione cualquier tecla para continuar");
		getchar();
		while(getchar()!='\n');
	}
	Comganador(puntablero);
}
int main(void) {
	int tablero[8][8],tipo=-1;
	srand(time(NULL));
	while(1){
		CrearTablero(&tablero[0][0]);
		printf("\nBienvenido a reversi\n");
		printf("Ingrese la modalidad (numero)\n1-Humano vs Computadora\n");
		printf("2-Humano vs Humano\n3-Computadora vs Computadora\n");
		printf("4-Cerrar programa\n");
		scanf("%d",&tipo);
		while(getchar()!='\n');
		while(tipo<1 || tipo>4){
			printf("\nLo ingresado es incorrecto\nVuelva a ingresar\n");
			scanf("%d",&tipo);
			while(getchar()!='\n');
		}
		if(tipo==4){
			break;
		}
		if (tipo==1){
			JvC(&tablero[0][0]);
		}
		if (tipo==2){
			JvJ(&tablero[0][0]);
		}
		if (tipo==3){
			CvC(&tablero[0][0]);
		}
	}
	printf("\nGracias por jugar\n");
}
