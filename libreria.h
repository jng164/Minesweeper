#define MAX 36
//Estado de las casillas en define
#define TAPADO 0
#define DESTAPADO 1
#define BANDERA 2
#define INTERROGACION 3
//Estado de la partida
#define WIN 1
#define LOSE 0
#define INGAME 2
#define BOMBA -1
typedef struct 
{
	int estado_casilla;
	int valor_casilla;
}tcasilla;

typedef struct 
{
tcasilla casilla [MAX][MAX];
int filas;
int columnas;
int nbombas;
int tiempo;
int levantadas;
int game;
}ttablero;



void  menu  (ttablero *tablero);
void poner_cero(ttablero *tablero);
void poner_alrededor(ttablero *tablero,int x,int y);
void poner_bomba(ttablero *tablero);
void clearscreen();
void coordenada (int x);
void tiempo(ttablero *tablero);
void mostrar(ttablero tablero);
void cambiar_blanco(ttablero *tablero,int fil,int col);
void cambiar_estado(ttablero *tablero);
void comprobacion(ttablero *tablero);
void case_lose(ttablero *tablero);
void case_win (ttablero *tablero);
