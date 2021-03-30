#ifndef JUEGO_H_
void CrearTablero(int *puntablero);
void Agregarficha(int *puntablero,int fila,int columna, int color);
int rectoizquierda(int *puntablero, int fila,int columna,int color);
int rectoderecha(int *puntablero, int fila,int columna,int color);
int rectoarriba(int *puntablero, int fila,int columna,int color);
int rectoabajo(int *puntablero, int fila,int columna,int color);
int diagonalarribai(int *puntablero, int fila,int columna,int color);
int diagonalabajoi(int *puntablero, int fila,int columna,int color);
int diagonalarribad(int *puntablero, int fila,int columna,int color);
int diagonalabajod(int *puntablero, int fila,int columna,int color);
int PermitidoCambio(int *puntablero, int fila,int columna,int color);
int PermitidoSin(int *puntablero, int fila,int columna,int color);
int JugadaValida(int *puntablero,int color);
void JuegoComp(int *puntablero, int color);
int Ganador(int *puntablero);

#endif
