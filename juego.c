#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 0 = espacio vacio
// 1 = negro
// 2 = blanco
// crea un tablero de enteros cada numero representa un color
void CrearTablero(int *puntablero){
	int i;
	for(i=0;i<64;i++){
		*(puntablero+i)=0;
	}
	*(puntablero+27)=2;
	*(puntablero+28)=1;
	*(puntablero+35)=1;
	*(puntablero+36)=2;
}
//Agrega una ficha al tablero
void Agregarficha(int *puntablero,int fila,int columna, int color){
	*(puntablero+(fila*8)+columna)=color;
}
// conjunto de funciones
// que comprueban si la jugada es valida analizando una linea en especifico
// Total de 8 lineas por lo tanto 8 funciones
// Verifica la seguiente casilla desde la posicion fila columna yendo
// hacia el lado que especifica la funcion
// incluye inteligencia que pasa el valor de la mejor casilla
// La mejor casilla es la que cambia mas fichas hacia el valor requerido
// retorna 1 si es valido y 0 si no

int rectoizquierda(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	//Comprueba si la jugada es valida del lado izquierdo
	int i,cont=0;
	if(columna<2){
		return 0;
	}
	if(color==2){
		for(i=1;i<columna;i++){
			if ( *(puntablero+(fila*8)+columna-i)==1 ){
				if( *(puntablero+(fila*8)+columna-i-1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+(fila*8)+columna-i-1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+(fila*8)+columna-i)==0 ){
				break;
			}
			else if ( *(puntablero+(fila*8)+columna-i)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1;i<columna;i++){
			if ( *(puntablero+(fila*8)+columna-i)==2 ){
				if( *(puntablero+(fila*8)+columna-i-1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+(fila*8)+columna-i-1)==0){
					break;
				}
			}
			else if ( *(puntablero+(fila*8)+columna-i)==0 ){
				break;
			}
			else if ( *(puntablero+(fila*8)+columna-i)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida del lado derecho
int rectoderecha(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,cont=0;
	if(columna>5){
		return 0;
	}
	if(color==2){
		for(i=1;i<7-columna;i++){
			if ( *(puntablero+(fila*8)+columna+i)==1 ){
				if( *(puntablero+(fila*8)+columna+i+1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+(fila*8)+columna+i+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+(fila*8)+columna+i)==0 ){
				break;
			}
			else if ( *(puntablero+(fila*8)+columna+i)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1;i<7-columna;i++){
			if ( *(puntablero+(fila*8)+columna+i)==2 ){
				if( *(puntablero+(fila*8)+columna+i+1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+(fila*8)+columna+i+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+(fila*8)+columna+i)==0 ){
				break;
			}
			else if ( *(puntablero+(fila*8)+columna+i)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida hacia arriba
int rectoarriba(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,cont=0;
	if(fila<2 ){
		return 0;
	}
	if(color==2){
		for(i=1;i<fila;i++){
			if ( *(puntablero+((fila-i)*8)+columna)==1 ){
				if( *(puntablero+((fila-i-1)*8)+columna)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1;i<fila;i++){
			if ( *(puntablero+((fila-1)*8)+columna)==2 ){
				if( *(puntablero+((fila-i-1)*8)+columna)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna)==0){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida hacia abajo
int rectoabajo(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,cont=0;
	if(fila>5){
		return 0;
	}
	if(color==2){
		for(i=1;i<7-fila;i++){
			if ( *(puntablero+((fila+i)*8)+columna)==1 ){
				if( *(puntablero+((fila+i+1)*8)+columna)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1;i<7-fila;i++){
			if ( *(puntablero+((fila+i)*8)+columna)==2 ){
				if( *(puntablero+((fila+i+1)*8)+columna)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida en la diagonal arriba izquierda
int diagonalarribai(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,j,cont=0;
	if(fila<2 || columna<2){
		return 0;
	}
	if(color==2){
		for(i=1,j=1;i<fila && j<columna;i++,j++){
			if ( *(puntablero+((fila-i)*8)+columna-j)==1 ){
				if( *(puntablero+((fila-i-1)*8)+columna-j-1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna-j-1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna-j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna-j)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1,j=1;i<fila && j<columna;i++,j++){
			if ( *(puntablero+((fila-i)*8)+columna-j)==2 ){
				if( *(puntablero+((fila-i-1)*8)+columna-j-1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna-j-1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna-j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna-j)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida en la diagonal abajo izquierda
int diagonalabajoi(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,j,cont=0;
	if(fila>5 || columna<2){
		return 0;
	}
	if(color==2){
		for(i=1,j=1;i<7-fila && j<columna;i++,j++){
			if ( *(puntablero+((fila+i)*8)+columna-j)==1 ){
				if( *(puntablero+((fila+i+1)*8)+columna-j-1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna-j-1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna-j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna-j)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1,j=1;i<7-fila && j<columna;i++,j++){
			if ( *(puntablero+((fila+i)*8)+columna-j)==2 ){
				if( *(puntablero+((fila+i+1)*8)+columna-j-1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna-j-1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna-j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna-j)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida en la diagonal arriba derecha
int diagonalarribad(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,j,cont=0;
	if(fila<2 || columna>5){
		return 0;
	}
	if(color==2){
		for(i=1,j=1;i<fila && j<7-columna;i++,j++){
			if ( *(puntablero+((fila-i)*8)+columna+j)==1 ){
				if( *(puntablero+((fila-i-1)*8)+columna+j+1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna+j+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna+j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna+j)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1,j=1;i<fila && j<7-columna;i++,j++){
			if ( *(puntablero+((fila-i)*8)+columna+j)==2 ){
				if( *(puntablero+((fila-i-1)*8)+columna+j+1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila-i-1)*8)+columna+j+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila-i)*8)+columna+j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila-i)*8)+columna+j)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//Comprueba si la jugada es valida en la diagonal abajo derecha
int diagonalabajod(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	int i,j,cont=0;
	if(fila>5 || columna>5){
		return 0;
	}
	if(color==2){
		for(i=1,j=1;i<7-fila && j<7-columna;i++,j++){
			if ( *(puntablero+((fila+i)*8)+columna+j)==1 ){
				if( *(puntablero+((fila+i+1)*8)+columna+j+1)==2 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna+j+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna+j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna+j)==2 ){
				break;
			}
			cont++;
		}
	}
	if(color==1){
		for(i=1,j=1;i<7-fila && j<7-columna;i++,j++){
			if ( *(puntablero+((fila+i)*8)+columna+j)==2 ){
				if( *(puntablero+((fila+i+1)*8)+columna+j+1)==1 ){
					if(cont>*max){
						*max=cont;
						*casilla=(fila*8)+columna;
					}
					return 1;
				}
				else if( *(puntablero+((fila+i+1)*8)+columna+j+1)==0 ){
					break;
				}
			}
			else if ( *(puntablero+((fila+i)*8)+columna+j)==0 ){
				break;
			}
			else if ( *(puntablero+((fila+i)*8)+columna+j)==1 ){
				break;
			}
			cont++;
		}
	}
	return 0;
}
//funcion que convina todas las funciones anteriores
//ademas de cambiar el color de la ficha en las posiciones validas
//retorna 1 si es valida, 0 si no
int PermitidoCambio(int *puntablero, int fila,int columna,int color){
	int i,j,contador=0,max,casilla;
	if(*(puntablero+(fila*8)+columna)==0){
		if (rectoizquierda( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1;*(puntablero+(fila*8)+columna-i)!=color;i++){
				*(puntablero+(fila*8)+columna-i)=color;
			}
		}
		if (rectoderecha( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1;*(puntablero+(fila*8)+columna+i)!=color;i++){
				*(puntablero+(fila*8)+columna+i)=color;
			}
		}
		if (rectoarriba( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1;*(puntablero+((fila-i)*8)+columna)!=color;i++){
				*(puntablero+((fila-i)*8)+columna)=color;
			}
		}
		if (rectoabajo( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1;*(puntablero+((fila+i)*8)+columna)!=color;i++){
				*(puntablero+((fila+i)*8)+columna)=color;
			}
		}
		if (diagonalarribad( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1,j=1;*(puntablero+((fila-i)*8)+columna+j)!=color;i++,j++){
				*(puntablero+((fila-i)*8)+columna+j)=color;
			}
		}
		if (diagonalarribai( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1,j=1;*(puntablero+((fila-i)*8)+columna-j)!=color;i++,j++){
				*(puntablero+((fila-i)*8)+columna-j)=color;
			}
		}
		if (diagonalabajod( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1,j=1;*(puntablero+((fila+i)*8)+columna+j)!=color;i++,j++){
				*(puntablero+((fila+i)*8)+columna+j)=color;
			}
		}
		if (diagonalabajoi( puntablero, fila, columna, color,&max,&casilla)==1){
			contador++;
			for(i=1,j=1;*(puntablero+((fila+i)*8)+columna-j)!=color;i++,j++){
				*(puntablero+((fila+i)*8)+columna-j)=color;
			}
		}
		if(contador>0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
//Comprueba que una jugada sea valida, similar a PermitidoCambio pero
//sin agregar fichas al tablero
int PermitidoSin(int *puntablero, int fila,int columna,int color,int *max,int *casilla){
	if(*(puntablero+(fila*8)+columna)==0){
		if (rectoizquierda( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (rectoderecha( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (rectoarriba( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (rectoabajo( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (diagonalarribad( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (diagonalarribai( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (diagonalabajod( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
		if (diagonalabajoi( puntablero, fila, columna, color,max,casilla)==1){
			return 1;
		}
	}
	return 0;
}
//Funcion que analiza si hay alguna jugada valida
int JugadaValida(int *puntablero,int color){
	int i,j,max,casilla;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(PermitidoSin(puntablero,i,j,color,&max,&casilla)==1){
				return 1;
			}
		}
	}
	return 0;
}
//funcion del juego de la computadora
void JuegoComp(int *puntablero, int color){
	int i,j,max=-1,casilla;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if (PermitidoSin(puntablero,i,j,color,&max,&casilla)==1){

			}
		}
	}

	if(PermitidoCambio(puntablero,(casilla/8),(casilla%8),color)==1){
		Agregarficha(puntablero,(casilla/8),(casilla%8),color);
	}
}
//Gana blanca=2
//Gana negra=1
//Empate=0
int Ganador(int *puntablero){
	int ContBlanco=0,ContNegro=0,i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(*(puntablero+(i*8)+j)==1){
					ContNegro++;
			}
			if(*(puntablero+(i*8)+j)==2){
					ContBlanco++;
			}
		}
	}
	if(ContBlanco>ContNegro){
		return 2;
	}
	else if(ContBlanco<ContNegro){
		return 1;
	}
	else{
		return 0;
	}
}
